package application.core.xml;

import application.core.ADataManagementException;
import application.core.IDataManager;
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
     * regular expression representing the set of allowed Java class names
     */
    private static final String CLASS_NAME_PATTERN = "[a-zA-Z_][0-9a-zA-Z_]*";
    /**
     * regular expression representing the set of allowed programming language
     * names
     */
    private static final String LANGUAGE_NAME_PATTERN = " +( +| )* *";
    // resource bundle for XML-specific strings
    private ResourceBundle xmlBundle;
    // object for XML documents parsing
    private DocumentBuilder documentBuilder;
    // object for transforming DOM to XML code
    private Transformer transformer;
    // main XML data file
    private File mainFile;
    // folder with XML data files
    private File directory;

    /**
     * Loads the main document and tests if the directory exists.
     *
     * @param mainDataFile main XML data file
     * @param dataFilesFolder folder with XML data files
     * @param xmlBundle resource bundle for XML-specific strings
     * @throws application.core.ADataManagementException error
     */
    public synchronized void setPaths(File mainDataFile, File dataFilesFolder, ResourceBundle xmlBundle)
            throws ADataManagementException {
        try {
            this.xmlBundle = xmlBundle;
            mainFile = mainDataFile;
            directory = dataFilesFolder;

            // testing the main file
            if (!mainDataFile.isFile()) {
                throw new XmlManagementException(xmlBundle.getString(
                        "notAMainFile"), mainDataFile.getName());
            }

            // testing the directory
            if (!dataFilesFolder.isDirectory()) {
                throw new XmlManagementException(xmlBundle.getString(
                        "notADirectory"), dataFilesFolder.getName());
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
            Document mainDocument = readDocumentFromFile(mainFile);

            ArrayList<String> list = new ArrayList<>();
            Element classList = getClassList(mainDocument);
            NodeList nodes = classList.getElementsByTagName(XmlKeyword.CLASS_ELEMENT.getName());

            // iterating through the class elements in the main XML file
            for (int i = 0; i < nodes.getLength(); i++) {
                Node language = nodes.item(i);

                // adding the class elements contents to array list
                if (language.getNodeType() == Node.ELEMENT_NODE) {
                    Element languageElement = (Element) language;
                    list.add(languageElement.getTextContent());
                }
            }

            return list;
        } catch (XmlManagementException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#loadLangList()
     */
    @Override
    public synchronized ArrayList<String> loadLangList()
            throws ADataManagementException {
        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            ArrayList<String> list = new ArrayList<>();
            Element langList = getLangList(mainDocument);
            NodeList nodes = langList.getElementsByTagName(XmlKeyword.LANGUAGE_ELEMENT.getName());

            // iterating through the language elements in the main XML file
            for (int i = 0; i < nodes.getLength(); i++) {
                Node language = nodes.item(i);

                // adding the language element content to array list
                if (language.getNodeType() == Node.ELEMENT_NODE) {
                    Element languageElement = (Element) language;
                    list.add(languageElement.getTextContent());
                }
            }

            return list;
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
        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            // creating a new XML class file
            createDocument(mainDocument, clazz);

            // adding a class item to the main XML file list
            Element classList = getClassList(mainDocument);
            addClassItem(mainDocument, classList, clazz);

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
        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            // renaming the XML class file
            renameDocument(oldClass, newClass);

            // editing the class item in the main XML file list
            Element classList = getClassList(mainDocument);
            editClassItem(classList, oldClass, newClass);

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
            deleteDocument(clazz);

            // removing the class item from the main XML file list
            Element classList = getClassList(mainDocument);
            removeClassItem(classList, clazz);

            writeDocumentToFile(mainFile, mainDocument);
        } catch (TransformerException | XmlManagementException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#addLang(java.lang.String)
     */
    @Override
    public synchronized void addLang(String lang)
            throws ADataManagementException {
        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            Element classList = getClassList(mainDocument);
            NodeList classes = classList.getChildNodes();

            // iterating through the XML class files
            for (int i = 0; i < classes.getLength(); i++) {
                Node classNode = classes.item(i);

                // adding a new code element to the XML class file
                if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element classElement = (Element) classNode;

                    File file = getFileFromClass(classElement.getTextContent());
                    Document document = readDocumentFromFile(file);
                    addCodeItem(document, lang);
                    writeDocumentToFile(file, document);
                }
            }

            // adding a language item to the main XML file list
            Element langList = getLangList(mainDocument);
            addLangItem(mainDocument, langList, lang);

            writeDocumentToFile(mainFile, mainDocument);
        } catch (TransformerException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#editLang(java.lang.String, java.lang.String)
     */
    @Override
    public synchronized void editLang(String oldLang, String newLang)
            throws ADataManagementException {
        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            Element classList = getClassList(mainDocument);
            NodeList classes = classList.getChildNodes();

            // iterating through the XML class files
            for (int i = 0; i < classes.getLength(); i++) {
                Node classNode = classes.item(i);

                // editing the code element to the XML class file
                if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element classElement = (Element) classNode;

                    File file = getFileFromClass(classElement.getTextContent());
                    Document document = readDocumentFromFile(file);
                    editCodeItem(document, oldLang, newLang);
                    writeDocumentToFile(file, document);
                }
            }

            // editing a language item in the main XML file list
            Element langList = getLangList(mainDocument);
            editLangItem(langList, oldLang, newLang);

            writeDocumentToFile(mainFile, mainDocument);
        } catch (TransformerException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.core.xml.XmlManager#removeLang(java.lang.String)
     */
    @Override
    public synchronized void removeLang(String lang)
            throws ADataManagementException {
        try {
            Document mainDocument = readDocumentFromFile(mainFile);

            Element classList = getClassList(mainDocument);
            NodeList classes = classList.getChildNodes();

            // iterating through the XML class files
            for (int i = 0; i < classes.getLength(); i++) {
                Node classNode = classes.item(i);

                // removing the code element to the XML class file
                if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element classElement = (Element) classNode;

                    File file = getFileFromClass(classElement.getTextContent());
                    Document document = readDocumentFromFile(file);
                    removeCodeItem(document, lang);
                    writeDocumentToFile(file, document);
                }
            }

            // removing a language item from the main XML file list
            Element langList = getLangList(mainDocument);
            removeLangItem(langList, lang);

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
            Element codeElement = getCodeItem(document, lang);

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
            Element codeElement = getCodeItem(document, lang);

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
                (String o1, String o2) -> getFileFromClass(o1).getName()
                .compareToIgnoreCase(getFileFromClass(o2).getName())) < 0;
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

        ArrayList langList = loadLangList();
        return Collections.binarySearch(langList, lang,
                (String o1, String o2) -> o1.compareToIgnoreCase(o2)) < 0;
    }

    /*
     Creates a new XML data file with the 
     specified name from a document object.
     */
    private void createDocument(Document mainDocument, String newClass)
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

        // creating a new XML document with root element
        Document document = documentBuilder.newDocument();
        Element root = document.createElement(XmlKeyword.CODE_ROOT_ELEMENT.getName());

        Element langList = getLangList(mainDocument);
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
        writeDocumentToFile(file, document);
    }

    /*
     Renames an XML data file represented by the specified name
     with a specified new name.
     */
    private void renameDocument(String oldClass, String newClass)
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
    private void deleteDocument(String oldClass)
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
     Returns an XML element representing the list of all created classes.
     */
    private Element getClassList(Document mainDocument)
            throws XmlManagementException, SAXException, IOException {
        String elementName = XmlKeyword.CLASS_LIST_ELEMENT.getName();
        NodeList items = mainDocument.getElementsByTagName(elementName);

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
     of classes in the main XML document.
     */
    private Element getClassItem(Element classList, String clazz) {
        String elementName = XmlKeyword.CLASS_ELEMENT.getName();
        NodeList classes = classList.getElementsByTagName(elementName);

        for (int i = 0; i < classes.getLength(); i++) {
            Node classNode = classes.item(i);

            if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                Element classElement = (Element) classNode;

                // finding the specified class element
                if (classElement.getTextContent().equals(clazz)) {
                    return classElement;
                }
            }
        }

        return null;
    }

    /*
     Creates an XML element representing the item in the list
     of classes in the main XML document.
     */
    private void addClassItem(Document mainDocument, Element classList, String newClass)
            throws XmlManagementException, TransformerException, SAXException, IOException {
        String elementName = XmlKeyword.CLASS_ELEMENT.getName();
        Element newClassElement = getClassItem(classList, newClass);

        if (newClassElement != null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueExists"), elementName, newClass);
        }

        newClassElement = mainDocument.createElement(elementName);
        newClassElement.setTextContent(newClass);
        classList.appendChild(newClassElement);
    }

    /*
     Updates an XML element representing the item in the list
     of classes in the main XML document.
     */
    private void editClassItem(Element classList, String oldClass, String newClass)
            throws XmlManagementException, TransformerException, SAXException, IOException {
        String elementName = XmlKeyword.CLASS_ELEMENT.getName();
        Element oldClassElement = getClassItem(classList, oldClass);

        if (oldClassElement == null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueNotFound"), elementName, oldClass);
        }

        Element newClassElement = getClassItem(classList, newClass);

        if (newClassElement != null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueExists"), elementName, newClass);
        }

        oldClassElement.setTextContent(newClass);
    }

    /*
     Deletes an XML element representing the item in the list
     of classes in the main XML document.
     */
    private void removeClassItem(Element classList, String oldClass)
            throws XmlManagementException, TransformerException, SAXException, IOException {
        String elementName = XmlKeyword.CLASS_ELEMENT.getName();
        Element oldClassElement = getClassItem(classList, oldClass);

        if (oldClassElement == null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueNotFound"), elementName, oldClass);
        }

        classList.removeChild(oldClassElement);
    }

    /*
     Returns an XML element representing the list of all created languages.
     */
    private Element getLangList(Document mainDocument)
            throws XmlManagementException, SAXException, IOException {
        String elementName = XmlKeyword.LANGUAG_LIST_ELEMENT.getName();
        NodeList items = mainDocument.getElementsByTagName(elementName);

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
     of languages in the main XML document.
     */
    private Element getLangItem(Element langList, String lang) {
        String elementName = XmlKeyword.LANGUAGE_ELEMENT.getName();
        NodeList languages = langList.getElementsByTagName(elementName);

        for (int i = 0; i < languages.getLength(); i++) {
            Node langNode = languages.item(i);

            if (langNode.getNodeType() == Node.ELEMENT_NODE) {
                Element langElement = (Element) langNode;

                // finding the specified language element
                if (langElement.getTextContent().equals(lang)) {
                    return langElement;
                }
            }
        }

        return null;
    }

    /*
     Creates an XML element representing the item in the list
     of languages in the main XML document.
     */
    private void addLangItem(Document mainDocument, Element langList, String newLang)
            throws XmlManagementException, TransformerException, SAXException, IOException {
        String elementName = XmlKeyword.LANGUAGE_ELEMENT.getName();
        Element newLangElement = getLangItem(langList, newLang);

        if (newLangElement != null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueExists"), elementName, newLang);
        }

        newLangElement = mainDocument.createElement(elementName);
        newLangElement.setTextContent(newLang);
        langList.appendChild(newLangElement);
    }

    /*
     Updates an XML element representing the item in the list
     of languages in the main XML document.
     */
    private void editLangItem(Element langList, String oldLang, String newLang)
            throws XmlManagementException, TransformerException, SAXException, IOException {
        String elementName = XmlKeyword.LANGUAGE_ELEMENT.getName();
        Element oldLangElement = getLangItem(langList, oldLang);

        if (oldLangElement == null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueNotFound"), elementName, oldLang);
        }

        Element newLangElement = getLangItem(langList, newLang);

        if (newLangElement != null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueExists"), elementName, newLang);
        }

        oldLangElement.setTextContent(newLang);
    }

    /*
     Deletes an XML element representing the item in the list
     of languages in the main XML document.
     */
    private void removeLangItem(Element langList, String oldLang)
            throws XmlManagementException, TransformerException, SAXException, IOException {
        String elementName = XmlKeyword.LANGUAGE_ELEMENT.getName();
        Element oldLangElement = getLangItem(langList, oldLang);

        if (oldLangElement == null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithValueNotFound"), elementName, oldLang);
        }

        langList.removeChild(oldLangElement);
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
    private Element getCodeItem(Document document, String lang) {
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
    private void addCodeItem(Document document, String newLang)
            throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();
        Element newCodeElement = getCodeItem(document, newLang);

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
    private void editCodeItem(Document document, String oldLang, String newLang)
            throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();
        Element oldCodeElement = getCodeItem(document, oldLang);

        if (oldCodeElement == null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithAttributeNotFound"), elementName, attributeName, oldLang);
        }

        Element newCodeElement = getCodeItem(document, newLang);

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
    private void removeCodeItem(Document document, String oldLang)
            throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();
        Element oldCodeElement = getCodeItem(document, oldLang);

        if (oldCodeElement == null) {
            throw new XmlManagementException(xmlBundle.getString(
                    "elementWithAttributeNotFound"), elementName, attributeName, oldLang);
        }

        getCodeList(document).removeChild(oldCodeElement);
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
        // creating the stream for a new file
        StreamResult result = new StreamResult(file);
        // creating a new DOM source
        DOMSource source = new DOMSource(document);
        // writing the DOM to the stream
        transformer.transform(source, result);
    }

    /*
     Returns the XML data file object corresponding to the specified class name.
     */
    private File getFileFromClass(String clazz) {
        return new File(directory.getPath() + "/" + clazz.toLowerCase() + ".xml");
    }

}
