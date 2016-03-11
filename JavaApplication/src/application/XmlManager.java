package application;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.apache.commons.lang3.StringEscapeUtils;

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
    
    // path to the main XML data file with the lists of available Java classes and programming languages
    private static final String MAIN_DATA_FILE_DEST = "data/classes.xml";
    // path to the folder with XML data files with translations of each class to each language
    private static final String DATA_FILES_FOLDER_DEST = "data/classes/";
    // object for XML documents parsing
    private DocumentBuilder documentBuilder;
    // main XML document
    private Document mainDocument;
    // folder with another documents
    private String directoryPath;

    /**
     * Loads the main document and tests if the directory exists.
     *
     * @throws application.CodeManagementException error
     */
    public void setPaths() throws CodeManagementException {
        try {
            // testing the main file
            File mainFile = new File(MAIN_DATA_FILE_DEST);

            if (!mainFile.exists()) {
                // TODO vyhodit výjimku
            }

            // testing the directory
            File directory = new File(DATA_FILES_FOLDER_DEST);

            if (!directory.isDirectory()) {
                // TODO vyhodit výjimku
            }

            // parsing the main XML file
            DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
            documentBuilder = dbf.newDocumentBuilder();
            mainDocument = documentBuilder.parse(mainFile);
            mainDocument.getDocumentElement().normalize();
            directoryPath = DATA_FILES_FOLDER_DEST;
        } catch (SAXException | IOException | ParserConfigurationException ex) {
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
        NodeList nodes = mainDocument.getElementsByTagName("class");

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
        NodeList nodes = mainDocument.getElementsByTagName("language");

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
        // renaming the XML class file
        renameDocument(oldClass, newClass);
        Element classList = getClassList();
        // editing the class item in the main XML file list
        editClassItem(classList, oldClass, newClass);
    }

    /*
     (non-Javadoc)
     @see application.ICodeManager#removeClass()
     */
    @Override
    public void removeClass(String clazz) throws CodeManagementException {
        // deleting the XML class file
        deleteDocument(clazz);
        Element classList = getClassList();
        // removing the class item from the main XML file list
        removeClassItem(classList, clazz);
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
                    Document document = openDocument(directoryPath
                            + classElement.getTextContent().toLowerCase() + ".xml");
                    addCodeItem(document, lang);
                }
            }

            Element langList = getLangList();
            addLangItem(langList, lang);
        } catch (SAXException | IOException ex) {
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

                // editig the code element to the XML class file
                if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element classElement = (Element) classNode;
                    Document document = openDocument(directoryPath
                            + classElement.getTextContent().toLowerCase() + ".xml");
                    editCodeItem(document, oldLang, newLang);
                }
            }

            Element langList = getLangList();
            editLangItem(langList, oldLang, newLang);
        } catch (SAXException | IOException ex) {
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
                    Document document = openDocument(directoryPath
                            + classElement.getTextContent().toLowerCase() + ".xml");
                    removeCodeItem(document, lang);
                }
            }

            Element langList = getLangList();
            removeLangItem(langList, lang);
        } catch (SAXException | IOException ex) {
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
            Element codeElement = getCodeItem(document, lang);

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
            String escapedCode = StringEscapeUtils.escapeXml10(code);
            // opening the XML class file
            Document document = openDocument(clazz);
            // retrieving the code element
            Element codeElement = getCodeItem(document, lang);

            if (codeElement != null) {
                // rewriting the code element content
                codeElement.setTextContent(escapedCode);
            } else {
                // TODO výjimka
            }
        } catch (SAXException | IOException ex) {
            throw new CodeManagementException(ex.getLocalizedMessage());
        }
    }

    /*
     Opens the XML data file with the specified name, 
     parses the XML code and creates a document object from it.
     */
    private Document openDocument(String clazz)
            throws SAXException, IOException {
        // parsing and normalizing the specified document
        Document document = documentBuilder.parse(new File(directoryPath
                + clazz.toLowerCase() + ".xml"));
        document.getDocumentElement().normalize();

        return document;
    }

    /*
     Creates a new XML data file with the 
     specified name from a document object.
     */
    private void createDocument(String newClass) throws TransformerException {
        File file = new File(directoryPath + newClass.toLowerCase() + ".xml");

        if (file.exists()) {
            // TODO výjimka
        }

        // creating the stream for a new file
        StreamResult result = new StreamResult(file);
        Document document = documentBuilder.newDocument();
        Element root = document.createElement("codes");
        document.appendChild(root);
        // creating a new DOM source
        DOMSource source = new DOMSource(document);
        TransformerFactory factory = TransformerFactory.newInstance();
        Transformer transformer = factory.newTransformer();
        // writing the DOM to the stream
        transformer.transform(source, result);
    }

    /*
     Renames an XML data file represented by the specified name
     with a specified new name.
     */
    private void renameDocument(String oldClass, String newClass) {
        File oldFile = new File(directoryPath + oldClass.toLowerCase() + ".xml");

        if (!oldFile.exists()) {
            // TODO výjimka
        }

        File newFile = new File(directoryPath + newClass.toLowerCase() + ".xml");

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
        File file = new File(directoryPath + oldClass.toLowerCase() + ".xml");

        if (!file.exists()) {
            // TODO výjimka
        }

        file.delete();
    }

    /*
     Returns an XML element representing the list of all created classes.
     */
    private Element getClassList() {
        NodeList items = mainDocument.getElementsByTagName("classes");

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
        NodeList items = mainDocument.getElementsByTagName("languages");

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
    private Element getCodeItem(Document clazz, String lang) {
        NodeList codeNodes = clazz.getElementsByTagName("code");

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
    private void addClassItem(Element classList, String newClass) {
        Element newClassElement = getClassItem(classList, newClass);

        if (newClassElement != null) {
            // TODO výjimka
        }

        newClassElement = mainDocument.createElement("class");
        newClassElement.setTextContent(newClass);
        classList.appendChild(newClassElement);
    }

    /*
     Creates an XML element representing the item in the list
     of languages in the main XML document.
     */
    private void addLangItem(Element langList, String newLang) {
        Element newLangElement = getLangItem(langList, newLang);

        if (newLangElement != null) {
            // TODO výjimka
        }

        newLangElement = mainDocument.createElement("language");
        newLangElement.setTextContent(newLang);
        langList.appendChild(newLangElement);
    }

    /*
     Creates an XML element containing the source code in the specified
     XML document.
     */
    private void addCodeItem(Document clazz, String newLang) {
        Element newCodeElement = getCodeItem(clazz, newLang);

        if (newCodeElement != null) {
            // TODO výjimka
        }

        newCodeElement = clazz.createElement("code");
        newCodeElement.setAttribute("lang", newLang);
        getCodeList(clazz).appendChild(newCodeElement);
    }

    /*
     Updates an XML element representing the item in the list
     of classes in the main XML document.
     */
    private void editClassItem(Element classList, String oldClass, String newClass) {
        Element oldClassElement = getClassItem(classList, oldClass);

        if (oldClassElement == null) {
            // TODO výjimka
        }

        Element newClassElement = getClassItem(classList, newClass);

        if (newClassElement != null) {
            // TODO výjimka
        }

        oldClassElement.setTextContent(newClass);
    }

    /*
     Updates an XML element representing the item in the list
     of languages in the main XML document.
     */
    private void editLangItem(Element langList, String oldLang, String newLang) {
        Element oldLangElement = getClassItem(langList, oldLang);

        if (oldLangElement == null) {
            // TODO výjimka
        }

        Element newLangElement = getClassItem(langList, newLang);

        if (newLangElement != null) {
            // TODO výjimka
        }

        oldLangElement.setTextContent(newLang);
    }

    /*
     Updates an XML element containing the source code in the specified
     XML document.
     */
    private void editCodeItem(Document clazz, String oldLang, String newLang) {
        Element oldCodeElement = getCodeItem(clazz, oldLang);

        if (oldCodeElement == null) {
            // TODO výjimka
        }

        Element newCodeElement = getCodeItem(clazz, newLang);

        if (newCodeElement != null) {
            // TODO výjimka
        }

        oldCodeElement.setAttribute("lang", newLang);
    }

    /*
     Deletes an XML element representing the item in the list
     of classes in the main XML document.
     */
    private void removeClassItem(Element classList, String oldClass) {
        Element oldClassElement = getClassItem(classList, oldClass);

        if (oldClassElement == null) {
            // TODO výjimka
        }

        classList.removeChild(oldClassElement);
    }

    /*
     Deletes an XML element representing the item in the list
     of languages in the main XML document.
     */
    private void removeLangItem(Element langList, String oldLang) {
        Element oldLangElement = getClassItem(langList, oldLang);

        if (oldLangElement == null) {
            // TODO výjimka
        }

        langList.removeChild(oldLangElement);
    }

    /*
     Deletes an XML element containing the source code in the specified
     XML document.
     */
    private void removeCodeItem(Document clazz, String oldLang) {
        Element oldCodeElement = getCodeItem(clazz, oldLang);

        if (oldCodeElement == null) {
            // TODO výjimka
        }

        getCodeList(clazz).removeChild(oldCodeElement);
    }

    /*
     (non-Javadoc)
     @see java.lang.Object#finalize()
     */
    @Override
    protected void finalize() throws Throwable {
        // TODO zavřít soubory
        super.finalize();
    }

}
