package application;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

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
public class XmlManager implements ICodeManager {

    // object for XML documents parsing
    private DocumentBuilder documentBuilder;
    // container with main XML document
    private XmlContainer mainContainer;
    // folder with another documents
    private String directoryPath;
    // object for transforming DOM to XML code
    private Transformer transformer;

    /**
     * The class {@code XmlContainer} serves as a container that binds XML
     * document object with the corresponding XML data file.
     *
     * @author Petr Kozler
     */
    private class XmlContainer {

        /**
         * XML file
         */
        public final File FILE;
        /**
         * Document object
         */
        public final Document DOCUMENT;

        /**
         * Creates a new container.
         *
         * @param file XML file
         * @param document Document object
         */
        public XmlContainer(File file, Document document) {
            FILE = file;
            DOCUMENT = document;
        }

    }

    /**
     * Loads the main document and tests if the directory exists.
     *
     * @param mainDataFileDest main XML data file
     * @param dataFilesFolderDest folder with XML data files
     * @throws application.CodeManagementException error
     */
    public void setPaths(String mainDataFileDest, String dataFilesFolderDest) throws CodeManagementException {
        try {
            // testing the main file
            File mainFile = new File(mainDataFileDest);

            if (!mainFile.exists()) {
                // TODO vyhodit výjimku
            }

            // testing the directory
            File directory = new File(dataFilesFolderDest);

            if (!directory.isDirectory()) {
                // TODO vyhodit výjimku
            }

            directoryPath = dataFilesFolderDest;

            // initializing document builder and transformer
            DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
            documentBuilder = dbf.newDocumentBuilder();
            TransformerFactory tf = TransformerFactory.newInstance();
            transformer = tf.newTransformer();

            // parsing the main XML file
            Document mainDocument = documentBuilder.parse(mainFile);
            mainDocument.getDocumentElement().normalize();
            mainContainer = new XmlContainer(mainFile, mainDocument);
        } catch (SAXException | IOException | ParserConfigurationException | TransformerConfigurationException ex) {
            throw new CodeManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.ICodeManager#loadClassList()
     */
    @Override
    public ArrayList<String> loadClassList() throws CodeManagementException {
        ArrayList<String> list = new ArrayList<>();
        NodeList nodes = mainContainer.DOCUMENT.getElementsByTagName("class");

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
     @see application.ICodeManager#loadLangList()
     */
    @Override
    public ArrayList<String> loadLangList() throws CodeManagementException {
        ArrayList<String> list = new ArrayList<>();
        NodeList nodes = mainContainer.DOCUMENT.getElementsByTagName("language");

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
     @see application.ICodeManager#addClass()
     */
    @Override
    public void addClass(String clazz) throws CodeManagementException {
        try {
            // creating a new XML class file
            createDocument(clazz);
            Element classList = getClassList();
            // adding a class item to the main XML file list
            addClassItem(classList, clazz);
        } catch (TransformerException ex) {
            throw new CodeManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.ICodeManager#editClass()
     */
    @Override
    public void editClass(String oldClass, String newClass) throws CodeManagementException {
        try {
            // renaming the XML class file
            renameDocument(oldClass, newClass);
            Element classList = getClassList();
            // editing the class item in the main XML file list
            editClassItem(classList, oldClass, newClass);
        } catch (TransformerException ex) {
            throw new CodeManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.ICodeManager#removeClass()
     */
    @Override
    public void removeClass(String clazz) throws CodeManagementException {
        try {
            // deleting the XML class file
            deleteDocument(clazz);
            Element classList = getClassList();
            // removing the class item from the main XML file list
            removeClassItem(classList, clazz);
        } catch (TransformerException ex) {
            throw new CodeManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.ICodeManager#addLang()
     */
    @Override
    public void addLang(String lang) throws CodeManagementException {
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
        } catch (SAXException | IOException | TransformerException ex) {
            throw new CodeManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.ICodeManager#editLang()
     */
    @Override
    public void editLang(String oldLang, String newLang) throws CodeManagementException {
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
        } catch (SAXException | IOException | TransformerException ex) {
            throw new CodeManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.ICodeManager#removeLang()
     */
    @Override
    public void removeLang(String lang) throws CodeManagementException {
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
        } catch (SAXException | IOException | TransformerException ex) {
            throw new CodeManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.ICodeManager#loadCode()
     */
    @Override
    public String loadCode(String clazz, String lang) throws CodeManagementException {
        try {
            // opening the XML class file
            Document document = openDocument(clazz);
            // retrieving the code element
            Element codeElement = getCodeItem(new XmlContainer(getFileFromClass(clazz), document), lang);

            if (codeElement != null) {
                // reading the code element content
                return codeElement.getTextContent();
            }

            return "";
        } catch (SAXException | IOException ex) {
            throw new CodeManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     (non-Javadoc)
     @see application.ICodeManager#saveCode()
     */
    @Override
    public void saveCode(String clazz, String lang, String code) throws CodeManagementException {
        try {
            // opening the XML class file
            Document document = openDocument(clazz);
            // retrieving the code element
            Element codeElement = getCodeItem(new XmlContainer(getFileFromClass(clazz), document), lang);

            if (codeElement == null) {
                // TODO výjimka
            }

            // rewriting the code element content
            codeElement.setTextContent(code);
            updateFileCode(new XmlContainer(getFileFromClass(clazz), document));
        } catch (SAXException | IOException | TransformerException ex) {
            throw new CodeManagementException(ex.getLocalizedMessage());
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
    private Document openDocument(String clazz)
            throws SAXException, IOException {
        documentBuilder.reset();
        // parsing and normalizing the specified document
        Document document = documentBuilder.parse(getFileFromClass(clazz));
        document.getDocumentElement().normalize();

        return document;
    }

    /*
     Creates a new XML data file with the 
     specified name from a document object.
     */
    private void createDocument(String newClass) throws TransformerException {
        File file = getFileFromClass(newClass);

        if (file.exists()) {
            // TODO výjimka
        }

        // creating a new XML document with root element
        Document document = documentBuilder.newDocument();
        Element root = document.createElement("codes");
        document.appendChild(root);
        updateFileCode(new XmlContainer(getFileFromClass(newClass), document));
    }

    /*
     Renames an XML data file represented by the specified name
     with a specified new name.
     */
    private void renameDocument(String oldClass, String newClass) {
        File oldFile = getFileFromClass(oldClass);

        if (!oldFile.exists()) {
            // TODO výjimka
        }

        File newFile = getFileFromClass(newClass);

        if (newFile.exists()) {
            // TODO výjimka
        }

        boolean renamed = oldFile.renameTo(newFile);

        if (!renamed) {
            // TODO výjimka
        }
    }

    /*
     Deletes an XML data file represented by the specified name.
     */
    private void deleteDocument(String oldClass) {
        File file = getFileFromClass(oldClass);

        if (!file.exists()) {
            // TODO výjimka
        }

        file.delete();
    }

    /*
     Returns an XML element representing the list of all created classes.
     */
    private Element getClassList() {
        NodeList items = mainContainer.DOCUMENT.getElementsByTagName("classes");

        if (items.getLength() != 1) {
            // TODO výjimka
        }

        Node itemsNode = items.item(0);

        if (itemsNode.getNodeType() != Node.ELEMENT_NODE) {
            // TODO výjimka
        }

        return (Element) itemsNode;
    }

    /*
     Returns an XML element representing the list of all created languages.
     */
    private Element getLangList() {
        NodeList items = mainContainer.DOCUMENT.getElementsByTagName("languages");

        if (items.getLength() != 1) {
            // TODO výjimka
        }

        Node itemsNode = items.item(0);

        if (itemsNode.getNodeType() != Node.ELEMENT_NODE) {
            // TODO výjimka
        }

        return (Element) itemsNode;
    }

    /*
     Returns an XML element wrapping the source code elements
     in a specified document.
     */
    private Element getCodeList(Document clazz) {
        NodeList items = clazz.getElementsByTagName("codes");

        if (items.getLength() != 1) {
            // TODO výjimka
        }

        Node itemsNode = items.item(0);

        if (itemsNode.getNodeType() != Node.ELEMENT_NODE) {
            // TODO výjimka
        }

        return (Element) itemsNode;
    }

    /*
     Returns an XML element representing the item in the list
     of classes in the main XML document.
     */
    private Element getClassItem(Element classList, String clazz) {
        NodeList classes = classList.getElementsByTagName("class");

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
     Returns an XML element representing the item in the list
     of languages in the main XML document.
     */
    private Element getLangItem(Element langList, String lang) {
        NodeList languages = langList.getElementsByTagName("language");

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
     Returns an XML element containing the source code in the specified
     XML document.
     */
    private Element getCodeItem(XmlContainer container, String lang) {
        NodeList codeNodes = container.DOCUMENT.getElementsByTagName("code");

        for (int i = 0; i < codeNodes.getLength(); i++) {
            Node codeNode = codeNodes.item(i);

            if (codeNode.getNodeType() == Node.ELEMENT_NODE) {
                Element codeElement = (Element) codeNode;

                // finding the specified code element
                if (lang.equals(codeElement.getAttribute("lang"))) {
                    return codeElement;
                }
            }
        }

        return null;
    }

    /*
     Creates an XML element representing the item in the list
     of classes in the main XML document.
     */
    private void addClassItem(Element classList, String newClass) throws TransformerException {
        Element newClassElement = getClassItem(classList, newClass);

        if (newClassElement != null) {
            // TODO výjimka
        }

        newClassElement = mainContainer.DOCUMENT.createElement("class");
        newClassElement.setTextContent(newClass);
        classList.appendChild(newClassElement);
        updateMainFile();
    }

    /*
     Creates an XML element representing the item in the list
     of languages in the main XML document.
     */
    private void addLangItem(Element langList, String newLang) throws TransformerException {
        Element newLangElement = getLangItem(langList, newLang);

        if (newLangElement != null) {
            // TODO výjimka
        }

        newLangElement = mainContainer.DOCUMENT.createElement("language");
        newLangElement.setTextContent(newLang);
        langList.appendChild(newLangElement);
        updateMainFile();
    }

    /*
     Creates an XML element containing the source code in the specified
     XML document.
     */
    private void addCodeItem(XmlContainer container, String newLang) throws TransformerException {
        Element newCodeElement = getCodeItem(container, newLang);

        if (newCodeElement != null) {
            // TODO výjimka
        }

        newCodeElement = container.DOCUMENT.createElement("code");
        newCodeElement.setAttribute("lang", newLang);
        getCodeList(container.DOCUMENT).appendChild(newCodeElement);
        updateFileCode(container);
    }

    /*
     Updates an XML element representing the item in the list
     of classes in the main XML document.
     */
    private void editClassItem(Element classList, String oldClass, String newClass) throws TransformerException {
        Element oldClassElement = getClassItem(classList, oldClass);

        if (oldClassElement == null) {
            // TODO výjimka
        }

        Element newClassElement = getClassItem(classList, newClass);

        if (newClassElement != null) {
            // TODO výjimka
        }

        oldClassElement.setTextContent(newClass);
        updateMainFile();
    }

    /*
     Updates an XML element representing the item in the list
     of languages in the main XML document.
     */
    private void editLangItem(Element langList, String oldLang, String newLang) throws TransformerException {
        Element oldLangElement = getLangItem(langList, oldLang);

        if (oldLangElement == null) {
            // TODO výjimka
        }

        Element newLangElement = getLangItem(langList, newLang);

        if (newLangElement != null) {
            // TODO výjimka
        }

        oldLangElement.setTextContent(newLang);
        updateMainFile();
    }

    /*
     Updates an XML element containing the source code in the specified
     XML document.
     */
    private void editCodeItem(XmlContainer container, String oldLang, String newLang) throws TransformerException {
        Element oldCodeElement = getCodeItem(container, oldLang);

        if (oldCodeElement == null) {
            // TODO výjimka
        }

        Element newCodeElement = getCodeItem(container, newLang);

        if (newCodeElement != null) {
            // TODO výjimka
        }

        oldCodeElement.setAttribute("lang", newLang);
        updateFileCode(container);
    }

    /*
     Deletes an XML element representing the item in the list
     of classes in the main XML document.
     */
    private void removeClassItem(Element classList, String oldClass) throws TransformerException {
        Element oldClassElement = getClassItem(classList, oldClass);

        if (oldClassElement == null) {
            // TODO výjimka
        }

        classList.removeChild(oldClassElement);
        updateMainFile();
    }

    /*
     Deletes an XML element representing the item in the list
     of languages in the main XML document.
     */
    private void removeLangItem(Element langList, String oldLang) throws TransformerException {
        Element oldLangElement = getLangItem(langList, oldLang);

        if (oldLangElement == null) {
            // TODO výjimka
        }

        langList.removeChild(oldLangElement);
        updateMainFile();
    }

    /*
     Deletes an XML element containing the source code in the specified
     XML document.
     */
    private void removeCodeItem(XmlContainer container, String oldLang) throws TransformerException {
        Element oldCodeElement = getCodeItem(container, oldLang);

        if (oldCodeElement == null) {
            // TODO výjimka
        }

        getCodeList(container.DOCUMENT).removeChild(oldCodeElement);
        updateFileCode(container);
    }

}
