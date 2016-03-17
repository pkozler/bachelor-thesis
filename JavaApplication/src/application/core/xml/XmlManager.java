package application.core.xml;

import application.core.ADataManagementException;
import application.core.IDataManager;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
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

    // resource bundle for XML-specific strings
    private ResourceBundle xmlBundle;
    // object for XML documents parsing
    private DocumentBuilder documentBuilder;
    // object for transforming DOM to XML code
    private Transformer transformer;
    // container with main XML document
    private XmlContainer mainContainer;
    // path to folder with XML data files
    private String directoryPath;

    /**
     * Loads the main document and tests if the directory exists.
     *
     * @param mainDataFile main XML data file
     * @param dataFilesFolder folder with XML data files
     * @param xmlBundle resource bundle for XML-specific strings
     * @throws application.core.ADataManagementException error
     */
    public void setPaths(File mainDataFile, File dataFilesFolder, ResourceBundle xmlBundle) throws ADataManagementException {
        try {
            this.xmlBundle = xmlBundle;

            // testing the main file
            if (!mainDataFile.isFile()) {
                throw new XmlManagementException(xmlBundle.getString("notAMainFile"), mainDataFile.getName());
            }

            // testing the directory
            if (!dataFilesFolder.isDirectory()) {
                throw new XmlManagementException(xmlBundle.getString("notADirectory"), dataFilesFolder.getName());
            }

            directoryPath = dataFilesFolder.getPath() + "/";

            // initializing document builder and transformer
            DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
            documentBuilder = dbf.newDocumentBuilder();
            TransformerFactory tf = TransformerFactory.newInstance();
            transformer = tf.newTransformer();

            // parsing the main XML file
            Document mainDocument = documentBuilder.parse(mainDataFile);
            mainDocument.getDocumentElement().normalize();
            mainContainer = new XmlContainer(mainDataFile, mainDocument);
        } catch (ParserConfigurationException | TransformerConfigurationException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.IDataManager#loadClassList()
     */
    @Override
    public ArrayList<String> loadClassList() throws ADataManagementException {
        ArrayList<String> list = new ArrayList<>();
        Element classList = getClassList();
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
    }

    /*
     (non-Javadoc)
     @see application.IDataManager#loadLangList()
     */
    @Override
    public ArrayList<String> loadLangList() throws ADataManagementException {
        ArrayList<String> list = new ArrayList<>();
        Element langList = getLangList();
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
    }

    /*
     (non-Javadoc)
     @see application.IDataManager#addClass(java.lang.String)
     */
    @Override
    public void addClass(String clazz) throws ADataManagementException {
        try {
            // creating a new XML class file
            createDocument(clazz);
            Element classList = getClassList();
            // adding a class item to the main XML file list
            addClassItem(classList, clazz);
        } catch (TransformerException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.IDataManager#editClass(java.lang.String, java.lang.String)
     */
    @Override
    public void editClass(String oldClass, String newClass) throws ADataManagementException {
        try {
            // renaming the XML class file
            renameDocument(oldClass, newClass);
            Element classList = getClassList();
            // editing the class item in the main XML file list
            editClassItem(classList, oldClass, newClass);
        } catch (TransformerException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.IDataManager#removeClass(java.lang.String)
     */
    @Override
    public void removeClass(String clazz) throws ADataManagementException {
        try {
            // deleting the XML class file
            deleteDocument(clazz);
            Element classList = getClassList();
            // removing the class item from the main XML file list
            removeClassItem(classList, clazz);
        } catch (TransformerException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.IDataManager#addLang(java.lang.String)
     */
    @Override
    public void addLang(String lang) throws ADataManagementException {
        try {
            Element classList = getClassList();
            NodeList classes = classList.getChildNodes();

            // iterating through the XML class files
            for (int i = 0; i < classes.getLength(); i++) {
                Node classNode = classes.item(i);

                // adding a new code element to the XML class file
                if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element classElement = (Element) classNode;
                    Document document = openDocument(classElement.getTextContent());
                    addCodeItem(new XmlContainer(getFileFromClass(classElement.getTextContent()), document), lang);
                }
            }

            Element langList = getLangList();
            addLangItem(langList, lang);
        } catch (TransformerException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.IDataManager#editLang(java.lang.String, java.lang.String)
     */
    @Override
    public void editLang(String oldLang, String newLang) throws ADataManagementException {
        try {
            Element classList = getClassList();
            NodeList classes = classList.getChildNodes();

            // iterating through the XML class files
            for (int i = 0; i < classes.getLength(); i++) {
                Node classNode = classes.item(i);

                // editing the code element to the XML class file
                if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element classElement = (Element) classNode;
                    Document document = openDocument(classElement.getTextContent());
                    editCodeItem(new XmlContainer(getFileFromClass(classElement.getTextContent()), document), oldLang, newLang);
                }
            }

            Element langList = getLangList();
            editLangItem(langList, oldLang, newLang);
        } catch (TransformerException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.IDataManager#removeLang(java.lang.String)
     */
    @Override
    public void removeLang(String lang) throws ADataManagementException {
        try {
            Element classList = getClassList();
            NodeList classes = classList.getChildNodes();

            // iterating through the XML class files
            for (int i = 0; i < classes.getLength(); i++) {
                Node classNode = classes.item(i);

                // removing the code element to the XML class file
                if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element classElement = (Element) classNode;
                    Document document = openDocument(classElement.getTextContent());
                    removeCodeItem(new XmlContainer(getFileFromClass(classElement.getTextContent()), document), lang);
                }
            }

            Element langList = getLangList();
            removeLangItem(langList, lang);
        } catch (TransformerException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.IDataManager#loadCode(java.lang.String, java.lang.String)
     */
    @Override
    public String loadCode(String clazz, String lang) throws ADataManagementException {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();

        try {
            // opening the XML class file
            Document document = openDocument(clazz);
            // retrieving the code element
            Element codeElement = getCodeItem(new XmlContainer(getFileFromClass(clazz), document), lang);

            if (codeElement == null) {
                throw new XmlManagementException(xmlBundle.getString("elementWithAttributeNotFound"), elementName, attributeName, lang);
            }

            // reading the code element content
            return codeElement.getTextContent();
        } catch (XmlManagementException | SAXException | IOException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.IDataManager#saveCode(java.lang.String, java.lang.String, java.lang.String)
     */
    @Override
    public void saveCode(String clazz, String lang, String code) throws ADataManagementException {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();

        try {
            File file = getFileFromClass(clazz);
            // opening the XML class file
            Document document = openDocument(clazz);
            // retrieving the code element
            Element codeElement = getCodeItem(new XmlContainer(file, document), lang);

            if (codeElement == null) {
                throw new XmlManagementException(xmlBundle.getString("elementWithAttributeNotFound"), elementName, attributeName, lang);
            }

            // rewriting the code element content
            codeElement.setTextContent(code);
            updateFileCode(new XmlContainer(file, document));
        } catch (XmlManagementException | SAXException | IOException | TransformerException ex) {
            throw new XmlManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     Returns the XML data file object corresponding to the specified class name.
     */
    private File getFileFromClass(String clazz) {
        return new File(directoryPath + clazz.toLowerCase() + ".xml");
    }

    /*
     Writes changes to the main XML file.
     */
    private void updateMainFile() throws TransformerException {
        transformer.reset();
        // creating the stream for a new file
        StreamResult result = new StreamResult(mainContainer.FILE);
        // creating a new DOM source
        DOMSource source = new DOMSource(mainContainer.DOCUMENT);
        // writing the DOM to the stream
        transformer.transform(source, result);
    }

    /*
     Writes the specified XML document object to the corresponding XML file of the specified class.
     */
    private void updateFileCode(XmlContainer container) throws TransformerConfigurationException, TransformerException {
        transformer.reset();
        // creating the stream for a new file
        StreamResult result = new StreamResult(container.FILE);
        // creating a new DOM source
        DOMSource source = new DOMSource(container.DOCUMENT);
        // writing the DOM to the stream
        transformer.transform(source, result);
    }

    /*
     Opens the XML data file with the specified name, 
     parses the XML code and creates a document object from it.
     */
    private Document openDocument(String clazz) throws XmlManagementException, SAXException, IOException {
        File file = getFileFromClass(clazz);

        if (!file.isFile()) {
            throw new XmlManagementException(xmlBundle.getString("notAFile"), file.getName());
        }

        documentBuilder.reset();
        // parsing and normalizing the specified document
        Document document = documentBuilder.parse(file);
        document.getDocumentElement().normalize();

        return document;
    }

    /*
     Creates a new XML data file with the 
     specified name from a document object.
     */
    private void createDocument(String newClass) throws XmlManagementException, TransformerException {
        File file = getFileFromClass(newClass);

        if (file.exists()) {
            throw new XmlManagementException(xmlBundle.getString("fileExists"), file.getName());
        }

        // creating a new XML document with root element
        Document document = documentBuilder.newDocument();
        Element root = document.createElement(XmlKeyword.CODES_ELEMENT.getName());
        document.appendChild(root);
        updateFileCode(new XmlContainer(file, document));
    }

    /*
     Renames an XML data file represented by the specified name
     with a specified new name.
     */
    private void renameDocument(String oldClass, String newClass) throws XmlManagementException {
        File oldFile = getFileFromClass(oldClass);

        if (!oldFile.isFile()) {
            throw new XmlManagementException(xmlBundle.getString("notAFile"), oldFile.getName());
        }

        File newFile = getFileFromClass(newClass);

        if (newFile.exists()) {
            throw new XmlManagementException(xmlBundle.getString("fileExists"), newFile.getName());
        }

        boolean renamed = oldFile.renameTo(newFile);

        if (!renamed) {
            throw new XmlManagementException(xmlBundle.getString("notRenamed"), oldFile.getName());
        }
    }

    /*
     Deletes an XML data file represented by the specified name.
     */
    private void deleteDocument(String oldClass) throws XmlManagementException {
        File file = getFileFromClass(oldClass);

        if (!file.exists()) {
            throw new XmlManagementException(xmlBundle.getString("notAFile"), file.getName());
        }

        boolean deleted = file.delete();

        if (!deleted) {
            throw new XmlManagementException(xmlBundle.getString("notDeleted"), file.getName());
        }
    }

    /*
     Returns an XML element representing the list of all created classes.
     */
    private Element getClassList() throws XmlManagementException {
        String elementName = XmlKeyword.CLASSES_ELEMENT.getName();
        NodeList items = mainContainer.DOCUMENT.getElementsByTagName(elementName);

        if (items.getLength() != 1) {
            throw new XmlManagementException(xmlBundle.getString("duplicateElements"), elementName);
        }

        Node itemsNode = items.item(0);

        if (itemsNode.getNodeType() != Node.ELEMENT_NODE) {
            throw new XmlManagementException(xmlBundle.getString("elementNotFound"), elementName);
        }

        return (Element) itemsNode;
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
    private void addClassItem(Element classList, String newClass) throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CLASS_ELEMENT.getName();
        Element newClassElement = getClassItem(classList, newClass);

        if (newClassElement != null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithValueExists"), elementName, newClass);
        }

        newClassElement = mainContainer.DOCUMENT.createElement(elementName);
        newClassElement.setTextContent(newClass);
        classList.appendChild(newClassElement);
        updateMainFile();
    }

    /*
     Updates an XML element representing the item in the list
     of classes in the main XML document.
     */
    private void editClassItem(Element classList, String oldClass, String newClass) throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CLASS_ELEMENT.getName();
        Element oldClassElement = getClassItem(classList, oldClass);

        if (oldClassElement == null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithValueNotFound"), elementName, oldClass);
        }

        Element newClassElement = getClassItem(classList, newClass);

        if (newClassElement != null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithValueExists"), elementName, newClass);
        }

        oldClassElement.setTextContent(newClass);
        updateMainFile();
    }

    /*
     Deletes an XML element representing the item in the list
     of classes in the main XML document.
     */
    private void removeClassItem(Element classList, String oldClass) throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CLASS_ELEMENT.getName();
        Element oldClassElement = getClassItem(classList, oldClass);

        if (oldClassElement == null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithValueNotFound"), elementName, oldClass);
        }

        classList.removeChild(oldClassElement);
        updateMainFile();
    }

    /*
     Returns an XML element representing the list of all created languages.
     */
    private Element getLangList() throws XmlManagementException {
        String elementName = XmlKeyword.LANGUAGES_ELEMENT.getName();
        NodeList items = mainContainer.DOCUMENT.getElementsByTagName(elementName);

        if (items.getLength() != 1) {
            throw new XmlManagementException(xmlBundle.getString("duplicateElements"), elementName);
        }

        Node itemsNode = items.item(0);

        if (itemsNode.getNodeType() != Node.ELEMENT_NODE) {
            throw new XmlManagementException(xmlBundle.getString("elementNotFound"), elementName);
        }

        return (Element) itemsNode;
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
    private void addLangItem(Element langList, String newLang) throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.LANGUAGE_ELEMENT.getName();
        Element newLangElement = getLangItem(langList, newLang);

        if (newLangElement != null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithValueExists"), elementName, newLang);
        }

        newLangElement = mainContainer.DOCUMENT.createElement(elementName);
        newLangElement.setTextContent(newLang);
        langList.appendChild(newLangElement);
        updateMainFile();
    }

    /*
     Updates an XML element representing the item in the list
     of languages in the main XML document.
     */
    private void editLangItem(Element langList, String oldLang, String newLang) throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.LANGUAGE_ELEMENT.getName();
        Element oldLangElement = getLangItem(langList, oldLang);

        if (oldLangElement == null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithValueNotFound"), elementName, oldLang);
        }

        Element newLangElement = getLangItem(langList, newLang);

        if (newLangElement != null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithValueExists"), elementName, newLang);
        }

        oldLangElement.setTextContent(newLang);
        updateMainFile();
    }

    /*
     Deletes an XML element representing the item in the list
     of languages in the main XML document.
     */
    private void removeLangItem(Element langList, String oldLang) throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.LANGUAGE_ELEMENT.getName();
        Element oldLangElement = getLangItem(langList, oldLang);

        if (oldLangElement == null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithValueNotFound"), elementName, oldLang);
        }

        langList.removeChild(oldLangElement);
        updateMainFile();
    }

    /*
     Returns an XML element wrapping the source code elements
     in a specified document.
     */
    private Element getCodeList(Document clazz) throws XmlManagementException {
        String elementName = XmlKeyword.CODES_ELEMENT.getName();
        NodeList items = clazz.getElementsByTagName(elementName);

        if (items.getLength() != 1) {
            throw new XmlManagementException(xmlBundle.getString("duplicateElements"), elementName);
        }

        Node itemsNode = items.item(0);

        if (itemsNode.getNodeType() != Node.ELEMENT_NODE) {
            throw new XmlManagementException(xmlBundle.getString("elementNotFound"), elementName);
        }

        return (Element) itemsNode;
    }

    /*
     Returns an XML element containing the source code in the specified
     XML document.
     */
    private Element getCodeItem(XmlContainer container, String lang) {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();
        NodeList codeNodes = container.DOCUMENT.getElementsByTagName(elementName);

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
    private void addCodeItem(XmlContainer container, String newLang) throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();
        Element newCodeElement = getCodeItem(container, newLang);

        if (newCodeElement != null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithAttributeExists"), elementName, attributeName, newLang);
        }

        newCodeElement = container.DOCUMENT.createElement(elementName);
        newCodeElement.setAttribute(attributeName, newLang);
        getCodeList(container.DOCUMENT).appendChild(newCodeElement);
        updateFileCode(container);
    }

    /*
     Updates an XML element containing the source code in the specified
     XML document.
     */
    private void editCodeItem(XmlContainer container, String oldLang, String newLang) throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();
        Element oldCodeElement = getCodeItem(container, oldLang);

        if (oldCodeElement == null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithAttributeNotFound"), elementName, attributeName, oldLang);
        }

        Element newCodeElement = getCodeItem(container, newLang);

        if (newCodeElement != null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithAttributeExists"), elementName, attributeName, newLang);
        }

        oldCodeElement.setAttribute(attributeName, newLang);
        updateFileCode(container);
    }

    /*
     Deletes an XML element containing the source code in the specified
     XML document.
     */
    private void removeCodeItem(XmlContainer container, String oldLang) throws XmlManagementException, TransformerException {
        String elementName = XmlKeyword.CODE_ELEMENT.getName();
        String attributeName = XmlKeyword.LANGUAGE_ATTRIBUTE.getName();
        Element oldCodeElement = getCodeItem(container, oldLang);

        if (oldCodeElement == null) {
            throw new XmlManagementException(xmlBundle.getString("elementWithAttributeNotFound"), elementName, attributeName, oldLang);
        }

        getCodeList(container.DOCUMENT).removeChild(oldCodeElement);
        updateFileCode(container);
    }

}
