package main.app.xml;

import main.app.ADataManagementException;
import main.app.IDataManager;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.ResourceBundle;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.OutputKeys;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

/**
 * The class {@code XmlManager} provides methods for reading, creating, updating
 * and deleting XML files with source codes and lists and therefore serves as an
 * application data management class.
 *
 * @author Petr Kozler
 */
public class XmlManager implements IDataManager {

    /**
     * XML document file extension for created code files
     */
    private static final String XML_FILE_EXTENSION = ".xml";
    /**
     * regular expression representing the set of allowed Java class names
     */
    private static final String CLASS_NAME_PATTERN = "\\s*[a-zA-Z_][0-9a-zA-Z_]*\\s*";
    /**
     * regular expression representing the set of allowed programming item names
     */
    private static final String LANGUAGE_NAME_PATTERN = ".*[^\\s]+.*";
    // resource bundle for XML-specific strings
    private ResourceBundle xmlBundle;
    // object for XML documents parsing
    private DocumentBuilder documentBuilder;
    // object for transforming DOM to XML code
    private Transformer transformer;
    // main XML data file
    private File mainFile;
    // subfolder with XML data files
    private File subfolder;

    /**
     * Sets the path to the main file and the source code files subfolder.
     *
     * @param mainFilePath path to the main XML data file
     * @param subfolderPath path to the subfolder with XML data files
     * @param xmlBundle resource bundle for XML-specific strings
     * @throws main.app.ADataManagementException error
     */
    public synchronized void initialize(String mainFilePath, String subfolderPath, ResourceBundle xmlBundle)
            throws ADataManagementException {
        try {
            this.xmlBundle = xmlBundle;
            mainFile = new File(mainFilePath.replace('/', File.separatorChar));
            subfolder = new File(subfolderPath.replace('/', File.separatorChar));

            // testing the main file
            if (!mainFile.isFile()) {
                throw new XmlManagementException(xmlBundle.getString(
                        "notAMainFile"), mainFile.getName());
            }

            // testing the subfolder
            if (!subfolder.isDirectory()) {
                throw new XmlManagementException(xmlBundle.getString(
                        "notADirectory"), subfolder.getName());
            }

            // initializing document builder and transformer
            DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
            documentBuilder = dbf.newDocumentBuilder();
            TransformerFactory tf = TransformerFactory.newInstance();
            transformer = tf.newTransformer();
        } catch (ParserConfigurationException | TransformerConfigurationException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#loadClassList()
     */
    @Override
    public synchronized ArrayList<String> loadClassList()
            throws ADataManagementException {
        try {
            return loadList(XmlKeyword.CLASS_LIST_ELEMENT.getName(), XmlKeyword.CLASS_ELEMENT.getName());
        } catch (XmlManagementException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#loadLanguageList()
     */
    @Override
    public synchronized ArrayList<String> loadLanguageList()
            throws ADataManagementException {
        try {
            return loadList(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName(), XmlKeyword.LANGUAGE_ELEMENT.getName());
        } catch (XmlManagementException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#addClass(java.lang.String)
     */
    @Override
    public synchronized void addClass(String clazz)
            throws ADataManagementException {
        String purifiedClass = purifyClassName(clazz);

        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            // creating a new XML class file
            File file = createFile(purifiedClass);
            Element langList = getItemList(mainDocument, XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
            Document document = createDocument(langList);
            writeDocumentToFile(file, document);

            // adding a class item to the main XML file list
            Element classList = getItemList(mainDocument, XmlKeyword.CLASS_LIST_ELEMENT.getName());
            addItem(mainDocument, classList, purifiedClass, XmlKeyword.CLASS_ELEMENT.getName());

            writeDocumentToFile(mainFile, mainDocument);
        } catch (TransformerException | XmlManagementException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#editClass(java.lang.String, java.lang.String)
     */
    @Override
    public synchronized void editClass(String oldClass, String newClass)
            throws ADataManagementException {
        String purifiedClass = purifyClassName(newClass);

        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            // renaming the XML class file
            renameFile(oldClass, purifiedClass);

            // editing the class item in the main XML file list
            Element classList = getItemList(mainDocument, XmlKeyword.CLASS_LIST_ELEMENT.getName());
            editItem(classList, oldClass, purifiedClass, XmlKeyword.CLASS_ELEMENT.getName());

            writeDocumentToFile(mainFile, mainDocument);
        } catch (TransformerException | XmlManagementException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#removeClass(java.lang.String)
     */
    @Override
    public synchronized void removeClass(String clazz)
            throws ADataManagementException {
        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            // deleting the XML class file
            deleteFile(clazz);

            // removing the class item from the main XML file list
            Element classList = getItemList(mainDocument, XmlKeyword.CLASS_LIST_ELEMENT.getName());
            removeItem(classList, clazz, XmlKeyword.CLASS_ELEMENT.getName());

            writeDocumentToFile(mainFile, mainDocument);
        } catch (TransformerException | XmlManagementException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#addLanguage(java.lang.String)
     */
    @Override
    public synchronized void addLanguage(String lang)
            throws ADataManagementException {
        String purifiedLang = purifyLanguageName(lang);

        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            Element classList = getItemList(mainDocument, XmlKeyword.CLASS_LIST_ELEMENT.getName());
            NodeList classes = classList.getChildNodes();

            // iterating through the XML class files
            for (int i = 0; i < classes.getLength(); i++) {
                Node classNode = classes.item(i);

                // adding a new code element to the XML class file
                if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element classElement = (Element) classNode;

                    File file = getFileFromClass(classElement.getTextContent());
                    Document document = readDocumentFromFile(file);
                    addCode(document, purifiedLang);
                    writeDocumentToFile(file, document);
                }
            }

            // adding a item item to the main XML file list
            Element langList = getItemList(mainDocument, XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
            addItem(mainDocument, langList, purifiedLang, XmlKeyword.LANGUAGE_ELEMENT.getName());

            writeDocumentToFile(mainFile, mainDocument);
        } catch (TransformerException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#editLanguage(java.lang.String, java.lang.String)
     */
    @Override
    public synchronized void editLanguage(String oldLang, String newLang)
            throws ADataManagementException {
        String purifiedLang = purifyLanguageName(newLang);

        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            Element classList = getItemList(mainDocument, XmlKeyword.CLASS_LIST_ELEMENT.getName());
            NodeList classes = classList.getChildNodes();

            // iterating through the XML class files
            for (int i = 0; i < classes.getLength(); i++) {
                Node classNode = classes.item(i);

                // editing the code element to the XML class file
                if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element classElement = (Element) classNode;

                    File file = getFileFromClass(classElement.getTextContent());
                    Document document = readDocumentFromFile(file);
                    editCode(document, oldLang, purifiedLang);
                    writeDocumentToFile(file, document);
                }
            }

            // editing a item item in the main XML file list
            Element langList = getItemList(mainDocument, XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
            editItem(langList, oldLang, purifiedLang, XmlKeyword.LANGUAGE_ELEMENT.getName());

            writeDocumentToFile(mainFile, mainDocument);
        } catch (TransformerException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#removeLanguage(java.lang.String)
     */
    @Override
    public synchronized void removeLanguage(String lang)
            throws ADataManagementException {
        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            Element classList = getItemList(mainDocument, XmlKeyword.CLASS_LIST_ELEMENT.getName());
            NodeList classes = classList.getChildNodes();

            // iterating through the XML class files
            for (int i = 0; i < classes.getLength(); i++) {
                Node classNode = classes.item(i);

                // removing the code element to the XML class file
                if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element classElement = (Element) classNode;

                    File file = getFileFromClass(classElement.getTextContent());
                    Document document = readDocumentFromFile(file);
                    removeCode(document, lang);
                    writeDocumentToFile(file, document);
                }
            }

            // removing a item item from the main XML file list
            Element langList = getItemList(mainDocument, XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
            removeItem(langList, lang, XmlKeyword.LANGUAGE_ELEMENT.getName());

            writeDocumentToFile(mainFile, mainDocument);
        } catch (TransformerException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#loadCode(java.lang.String, java.lang.String)
     */
    @Override
    public synchronized String loadCode(String clazz, String lang)
            throws ADataManagementException {
        try {
            String elementName = XmlKeyword.CODE_ELEMENT.getName();
            String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();

            // opening the XML class file
            Document document = readDocumentFromFile(getFileFromClass(clazz));
            // retrieving the code element
            Element codeElement = getCode(document, lang);

            if (codeElement == null) {
                throw new XmlManagementException(xmlBundle.getString(
                        "elementWithAttributeNotFound"), elementName, attributeName, lang);
            }

            // reading the code element content
            return codeElement.getTextContent();
        } catch (XmlManagementException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#saveCode(java.lang.String, java.lang.String, java.lang.String)
     */
    @Override
    public synchronized void saveCode(String clazz, String lang, String code)
            throws ADataManagementException {
        try {
            String elementName = XmlKeyword.CODE_ELEMENT.getName();
            String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();

            File file = getFileFromClass(clazz);
            // opening the XML class file
            Document document = readDocumentFromFile(file);
            // retrieving the code element
            Element codeElement = getCode(document, lang);

            if (codeElement == null) {
                throw new XmlManagementException(xmlBundle.getString(
                        "elementWithAttributeNotFound"), elementName, attributeName, lang);
            }

            // rewriting the code element content
            codeElement.setTextContent(code);
            // save changes to file
            writeDocumentToFile(file, document);
        } catch (XmlManagementException | SAXException | IOException | TransformerException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#validateClass(java.lang.String)
     */
    @Override
    public synchronized boolean validateClass(String clazz)
            throws ADataManagementException {
        if (!clazz.matches(CLASS_NAME_PATTERN)) {
            return false;
        }

        ArrayList classList = loadClassList();
        return Collections.binarySearch(classList, clazz,
                (String o1, String o2) -> purifyClassName(o1).compareToIgnoreCase(purifyClassName(o2))) < 0;
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#validateLanguage(java.lang.String)
     */
    @Override
    public synchronized boolean validateLanguage(String lang)
            throws ADataManagementException {
        if (!lang.matches(LANGUAGE_NAME_PATTERN)) {
            return false;
        }

        ArrayList langList = loadLanguageList();
        return Collections.binarySearch(langList, lang,
                (String o1, String o2) -> purifyLanguageName(o1).compareToIgnoreCase(purifyLanguageName(o2))) < 0;
    }

    /*
     Loads the class or language list from main XML file into array list of strings.
     */
    private ArrayList<String> loadList(String listElementName, String elementName)
            throws XmlManagementException, SAXException, IOException {
        Document mainDocument = readDocumentFromFile(mainFile);

        ArrayList<String> list = new ArrayList<>();
        Element itemList = getItemList(mainDocument, listElementName);
        NodeList nodes = itemList.getElementsByTagName(elementName);

        // iterating through the class elements in the main XML file
        for (int i = 0; i < nodes.getLength(); i++) {
            Node item = nodes.item(i);

            // adding the class elements contents to array list
            if (item.getNodeType() == Node.ELEMENT_NODE) {
                Element itemElement = (Element) item;
                list.add(itemElement.getTextContent());
            }
        }

        return list;
    }

    /*
     Returns an XML element representing the list of all created classes or languages.
     */
    private Element getItemList(Document mainDocument, String elementName)
            throws XmlManagementException, SAXException, IOException {
        NodeList items = mainDocument.getElementsByTagName(elementName); // TODO list

        if (items.getLength() > 1) {
            throw new XmlManagementException(xmlBundle.getString(
                    "duplicateElements"), elementName);
        }

        if (items.getLength() < 1 || items.item(0).getNodeType() != Node.ELEMENT_NODE) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementNotFound"), elementName);
        }

        return (Element) items.item(0);
    }

    /*
     Returns an XML element representing the item in the list
     of classe or languagess in the main XML document.
     */
    private Element getItem(Element itemList, String clazz, String elementName) {
        NodeList items = itemList.getElementsByTagName(elementName);

        for (int i = 0; i < items.getLength(); i++) {
            Node itemNode = items.item(i);

            if (itemNode.getNodeType() == Node.ELEMENT_NODE) {
                Element itemElement = (Element) itemNode;

                // finding the specified item element
                if (itemElement.getTextContent().equals(clazz)) {
                    return itemElement;
                }
            }
        }

        return null;
    }

    /*
     Creates an XML element representing the item in the list
     of classes or languages in the main XML document.
     */
    private void addItem(Document mainDocument, Element itemList, String newItem, String elementName)
            throws XmlManagementException, TransformerException, SAXException, IOException {
        Element newItemElement = getItem(itemList, newItem, elementName);

        if (newItemElement != null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueExists"), elementName, newItem);
        }

        newItemElement = mainDocument.createElement(elementName);
        newItemElement.setTextContent(newItem);
        itemList.appendChild(newItemElement);
    }

    /*
     Updates an XML element representing the item in the list
     of classes or languages in the main XML document.
     */
    private void editItem(Element itemList, String oldItem, String newItem, String elementName)
            throws XmlManagementException, TransformerException, SAXException, IOException {
        Element oldItemElement = getItem(itemList, oldItem, elementName);

        if (oldItemElement == null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueNotFound"), elementName, oldItem);
        }

        Element newItemElement = getItem(itemList, newItem, elementName);

        if (newItemElement != null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueExists"), elementName, newItem);
        }

        oldItemElement.setTextContent(newItem);
    }

    /*
     Deletes an XML element representing the item in the list
     of classes or languages in the main XML document.
     */
    private void removeItem(Element itemList, String oldItem, String elementName)
            throws XmlManagementException, TransformerException, SAXException, IOException {
        Element oldItemElement = getItem(itemList, oldItem, elementName);

        if (oldItemElement == null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueNotFound"), elementName, oldItem);
        }

        itemList.removeChild(oldItemElement);
    }

    /*
     Returns an XML element wrapping the source code elements
     in a specified document.
     */
    private Element getCodeList(Document document)
            throws XmlManagementException {
        String elementName = XmlKeyword.CODE_ROOT_ELEMENT.getName();
        NodeList items = document.getElementsByTagName(elementName);

        if (items.getLength() > 1) {
            throw new XmlManagementException(xmlBundle.getString(
                    "duplicateElements"), elementName);
        }

        if (items.getLength() < 1 || items.item(0).getNodeType() != Node.ELEMENT_NODE) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementNotFound"), elementName);
        }

        return (Element) items.item(0);
    }

    /*
     Returns an XML element containing the source code in the specified
     XML document.
     */
    private Element getCode(Document document, String lang) {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();
        NodeList codeNodes = document.getElementsByTagName(elementName);

        for (int i = 0; i < codeNodes.getLength(); i++) {
            Node codeNode = codeNodes.item(i);

            if (codeNode.getNodeType() == Node.ELEMENT_NODE) {
                Element codeElement = (Element) codeNode;

                // finding the specified code element
                if (lang.equals(codeElement.getAttribute(attributeName))) {
                    return codeElement;
                }
            }
        }

        return null;
    }

    /*
     Creates an XML element containing the source code in the specified
     XML document.
     */
    private void addCode(Document document, String newLang)
            throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();
        Element newCodeElement = getCode(document, newLang);

        if (newCodeElement != null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithAttributeExists"), elementName, attributeName, newLang);
        }

        newCodeElement = document.createElement(elementName);
        newCodeElement.setAttribute(attributeName, newLang);
        getCodeList(document).appendChild(newCodeElement);
    }

    /*
     Updates an XML element containing the source code in the specified
     XML document.
     */
    private void editCode(Document document, String oldLang, String newLang)
            throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();
        Element oldCodeElement = getCode(document, oldLang);

        if (oldCodeElement == null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithAttributeNotFound"), elementName, attributeName, oldLang);
        }

        Element newCodeElement = getCode(document, newLang);

        if (newCodeElement != null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithAttributeExists"), elementName, attributeName, newLang);
        }

        oldCodeElement.setAttribute(attributeName, newLang);
    }

    /*
     Deletes an XML element containing the source code in the specified
     XML document.
     */
    private void removeCode(Document document, String oldLang)
            throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();
        Element oldCodeElement = getCode(document, oldLang);

        if (oldCodeElement == null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithAttributeNotFound"), elementName, attributeName, oldLang);
        }

        getCodeList(document).removeChild(oldCodeElement);
    }
    
    /*
    Creates a new XML document and adds code elements with all available languages into it.
    */
    private Document createDocument(Element langList) throws XmlManagementException, SAXException, IOException {
        // creating a new XML document with root element
        Document document = documentBuilder.newDocument();
        Element root = document.createElement(XmlKeyword.CODE_ROOT_ELEMENT.getName());
        NodeList languages = langList.getChildNodes();

        // iterating through the languages
        for (int i = 0; i < languages.getLength(); i++) {
            Node langNode = languages.item(i);

            // adding a new code element with lang attribute to the new XML class file
            if (langNode.getNodeType() == Node.ELEMENT_NODE) {
                Element langElement = (Element) langNode;
                Element codeElement = document.createElement(XmlKeyword.CODE_ELEMENT.getName());
                codeElement.setAttribute(XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langElement.getTextContent());
                root.appendChild(codeElement);
            }
        }

        document.appendChild(root);
        
        return document;
    }
    
    /*
     Creates a new XML data file with the 
     specified name from a document object.
     */
    private File createFile(String newClass)
            throws XmlManagementException, TransformerException, IOException, SAXException {
        File file = getFileFromClass(newClass);

        if (file.exists()) {
            throw new XmlManagementException(xmlBundle.getString(
                    "fileExists"), file.getName());
        }

        boolean created = file.createNewFile();

        if (!created) {
            throw new XmlManagementException(xmlBundle.getString(
                    "notCreated"), file.getName());
        }
        
        return file;
    }

    /*
     Renames an XML data file represented by the specified name
     with a specified new name.
     */
    private void renameFile(String oldClass, String newClass)
            throws XmlManagementException {
        File oldFile = getFileFromClass(oldClass);

        if (!oldFile.isFile()) {
            throw new XmlManagementException(xmlBundle.getString(
                    "notAFile"), oldFile.getName());
        }

        File newFile = getFileFromClass(newClass);

        if (newFile.exists()) {
            throw new XmlManagementException(xmlBundle.getString(
                    "fileExists"), newFile.getName());
        }

        boolean renamed = oldFile.renameTo(newFile);

        if (!renamed) {
            throw new XmlManagementException(xmlBundle.getString(
                    "notRenamed"), oldFile.getName());
        }
    }

    /*
     Deletes an XML data file represented by the specified name.
     */
    private void deleteFile(String oldClass)
            throws XmlManagementException {
        File file = getFileFromClass(oldClass);

        if (!file.exists()) {
            throw new XmlManagementException(xmlBundle.getString(
                    "notAFile"), file.getName());
        }

        boolean deleted = file.delete();

        if (!deleted) {
            throw new XmlManagementException(xmlBundle.getString(
                    "notDeleted"), file.getName());
        }
    }

    /*
     Reads the XML document object from the specified XML file.
     */
    private Document readDocumentFromFile(File file)
            throws SAXException, IOException {
        documentBuilder.reset();
        // creating a document
        Document document = documentBuilder.parse(file);
        // normalizing a document
        document.getDocumentElement().normalize();
        // returning document
        return document;
    }

    /*
     Writes the specified XML document object to the corresponding XML file.
     */
    private void writeDocumentToFile(File file, Document document)
            throws TransformerConfigurationException, TransformerException {
        transformer.reset();
        transformer.setOutputProperty(OutputKeys.INDENT, "yes");
        // creating the stream for a new file
        StreamResult result = new StreamResult(file);
        // creating a new DOM source
        DOMSource source = new DOMSource(document);
        // writing the DOM to the stream
        transformer.transform(source, result);
    }

    /*
     Purifies the class name before adding into list.
     */
    private String purifyClassName(String clazz) {
        return clazz.trim().replaceAll("\\s+", "_");
    }

    /*
     Purifies the item name before adding into list.
     */
    private String purifyLanguageName(String lang) {
        return lang.trim().replaceAll("\\s+", " ");
    }

    /*
     Returns the XML data file object corresponding to the specified class name.
     */
    private File getFileFromClass(String clazz) {
        return new File(subfolder.getPath() + File.separator + clazz.toLowerCase() + XML_FILE_EXTENSION);
    }

}
