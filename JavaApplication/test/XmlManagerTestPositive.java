
import application.core.ADataManagementException;
import application.core.xml.XmlManager;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.ResourceBundle;
import java.util.Scanner;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.TransformerException;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

/**
 * The {@code XmlManagerTestPositive} class performs automatic unit testing of
 * the {@code XmlManager} class with correct inputs.
 *
 * @author Petr Kozler
 */
public class XmlManagerTestPositive {

    // tested XML manager
    private XmlManager xmlManager;
    // testData for tested XML manager
    private XmlManagerTestData testData;

    /**
     * Creates a clean test test data directory structure and creates the XML
     * manager before each test is run.
     *
     * @throws ParserConfigurationException parser error
     * @throws TransformerException transformer error
     * @throws IOException IO error
     */
    @Before
    public void setUp() throws ParserConfigurationException, TransformerException, IOException {
        xmlManager = new XmlManager();
        testData = new XmlManagerTestData();
    }

    /**
     * Tests the setPaths method.
     *
     * @throws application.core.ADataManagementException an error
     * @throws java.io.IOException IO error
     */
    @Test
    public void setPathsTest() throws ADataManagementException, IOException {
        // reading the content before XML manager initialization
        String mainFileContentBefore = new Scanner(testData.getMainDataFile()).useDelimiter("\\Z").next();
        String filesFolderContentBefore = Arrays.toString(testData.getDataFilesFolder().listFiles());

        testData.initXmlManager(xmlManager);

        // reading the content after XML manager initialization
        String mainFileContentAfter = new Scanner(testData.getMainDataFile()).useDelimiter("\\Z").next();
        String filesFolderContentAfter = Arrays.toString(testData.getDataFilesFolder().listFiles());

        // comparing the contents before and after the initialization
        assertEquals(mainFileContentBefore, mainFileContentAfter);
        assertEquals(filesFolderContentBefore, filesFolderContentAfter);
    }

    /**
     * Tests the loadClassList method.
     *
     * @throws application.core.ADataManagementException an error
     */
    @Test
    public void loadClassListTest() throws ADataManagementException {
        testData.initXmlManager(xmlManager);
        ArrayList<String> classList = xmlManager.loadClassList();
        assertEquals(0, classList.size());
    }

    /**
     * Tests the loadLangList method.
     *
     * @throws application.core.ADataManagementException an error
     */
    @Test
    public void loadLangListTest() throws ADataManagementException {
        testData.initXmlManager(xmlManager);
        ArrayList<String> langList = xmlManager.loadLangList();
        assertEquals(0, langList.size());
    }

    /**
     * Tests the addClass method.
     *
     * @throws application.core.ADataManagementException an error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     */
    @Test
    public void addClassTest() throws ADataManagementException, SAXException, IOException, ParserConfigurationException {
        testData.initXmlManager(xmlManager);
        ArrayList<String> classList;
        String className1 = "ClassA";
        String className2 = "ClassB";
        String className3 = "ClassC";
        xmlManager.addClass(className1);
        classList = xmlManager.loadClassList();
        assertEquals(className1, classList.get(0));
        assertTrue(validClassFileExists(className1));
        assertTrue(directoryHasFileCount(1));
        
        xmlManager.addClass(className2);
        classList = xmlManager.loadClassList();
        assertEquals(className1, classList.get(0));
        assertEquals(className2, classList.get(1));
        assertTrue(validClassFileExists(className1));
        assertTrue(validClassFileExists(className2));
        assertTrue(directoryHasFileCount(2));

        xmlManager.addClass(className3);
        classList = xmlManager.loadClassList();
        assertEquals(className1, classList.get(0));
        assertEquals(className2, classList.get(1));
        assertEquals(className3, classList.get(2));
        assertTrue(validClassFileExists(className1));
        assertTrue(validClassFileExists(className2));
        assertTrue(validClassFileExists(className3));
        assertTrue(directoryHasFileCount(3));
    }

    /**
     * Tests the editClass method.
     *
     * @throws application.core.ADataManagementException an error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     */
    @Test
    public void editClassTest() throws ADataManagementException, SAXException, IOException, ParserConfigurationException {
        testData.initXmlManager(xmlManager);
        ArrayList<String> classList;
        String className1 = "ClassA";
        String className2 = "ClassB";
        String className3 = "ClassC";
        String className4 = "ClassD";
        String className5 = "ClassE";
        String className6 = "ClassF";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        xmlManager.addClass(className3);

        xmlManager.editClass(className1, className4);
        classList = xmlManager.loadClassList();
        assertEquals(className4, classList.get(0));
        assertEquals(className2, classList.get(1));
        assertEquals(className3, classList.get(2));
        assertTrue(validClassFileExists(className4));
        assertTrue(validClassFileExists(className2));
        assertTrue(validClassFileExists(className3));
        assertTrue(directoryHasFileCount(3));

        xmlManager.editClass(className2, className5);
        classList = xmlManager.loadClassList();
        assertEquals(className4, classList.get(0));
        assertEquals(className5, classList.get(1));
        assertEquals(className3, classList.get(2));
        assertTrue(validClassFileExists(className4));
        assertTrue(validClassFileExists(className5));
        assertTrue(validClassFileExists(className3));
        assertTrue(directoryHasFileCount(3));

        xmlManager.editClass(className3, className6);
        classList = xmlManager.loadClassList();
        assertEquals(className4, classList.get(0));
        assertEquals(className5, classList.get(1));
        assertEquals(className6, classList.get(2));
        assertTrue(validClassFileExists(className4));
        assertTrue(validClassFileExists(className5));
        assertTrue(validClassFileExists(className6));
        assertTrue(directoryHasFileCount(3));
    }

    /**
     * Tests the removeClass method.
     *
     * @throws application.core.ADataManagementException an error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     */
    @Test
    public void removeClassTest() throws ADataManagementException, SAXException, IOException, ParserConfigurationException {
        testData.initXmlManager(xmlManager);
        ArrayList<String> classList;
        String className1 = "ClassA";
        String className2 = "ClassB";
        String className3 = "ClassC";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        xmlManager.addClass(className3);

        xmlManager.removeClass(className1);
        classList = xmlManager.loadClassList();
        assertEquals(className2, classList.get(0));
        assertEquals(className3, classList.get(1));
        assertTrue(validClassFileExists(className2));
        assertTrue(validClassFileExists(className3));
        assertTrue(directoryHasFileCount(2));

        xmlManager.removeClass(className2);
        classList = xmlManager.loadClassList();
        assertEquals(className3, classList.get(0));
        assertTrue(validClassFileExists(className3));
        assertTrue(directoryHasFileCount(1));

        xmlManager.removeClass(className3);
        classList = xmlManager.loadClassList();
        assertEquals(0, classList.size());
        assertTrue(directoryHasFileCount(0));
    }

    /**
     * Tests the addLang method.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addLangTest() throws ADataManagementException, ParserConfigurationException, SAXException, IOException {
        testData.initXmlManager(xmlManager);
        ArrayList<String> langList;
        String className1 = "ClassA";
        String className2 = "ClassB";
        String className3 = "ClassC";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        xmlManager.addClass(className3);

        String langName1 = "LangA";
        String langName2 = "LangB";
        String langName3 = "LangC";

        xmlManager.addLang(langName1);
        langList = xmlManager.loadLangList();
        assertEquals(langName1, langList.get(0));
        assertTrue(allFilesHaveCodeInLang(langName1));
        assertTrue(allFilesHaveCodeCount(1));

        xmlManager.addLang(langName2);
        langList = xmlManager.loadLangList();
        assertEquals(langName1, langList.get(0));
        assertEquals(langName2, langList.get(1));
        assertTrue(allFilesHaveCodeInLang(langName1));
        assertTrue(allFilesHaveCodeInLang(langName2));
        assertTrue(allFilesHaveCodeCount(2));

        xmlManager.addLang(langName3);
        langList = xmlManager.loadLangList();
        assertEquals(langName1, langList.get(0));
        assertEquals(langName2, langList.get(1));
        assertEquals(langName3, langList.get(2));
        assertTrue(allFilesHaveCodeInLang(langName1));
        assertTrue(allFilesHaveCodeInLang(langName2));
        assertTrue(allFilesHaveCodeInLang(langName3));
        assertTrue(allFilesHaveCodeCount(3));
    }

    /**
     * Tests the editLang method.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editLangTest() throws ADataManagementException, ParserConfigurationException, SAXException, IOException {
        testData.initXmlManager(xmlManager);
        ArrayList<String> langList;
        String className1 = "ClassA";
        String className2 = "ClassB";
        String className3 = "ClassC";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        xmlManager.addClass(className3);

        String langName1 = "LangA";
        String langName2 = "LangB";
        String langName3 = "LangC";
        String langName4 = "LangD";
        String langName5 = "LangE";
        String langName6 = "LangF";
        xmlManager.addLang(langName1);
        xmlManager.addLang(langName2);
        xmlManager.addLang(langName3);

        xmlManager.editLang(langName1, langName4);
        langList = xmlManager.loadLangList();
        assertEquals(langName4, langList.get(0));
        assertEquals(langName2, langList.get(1));
        assertEquals(langName3, langList.get(2));
        assertTrue(allFilesHaveCodeInLang(langName4));
        assertTrue(allFilesHaveCodeInLang(langName2));
        assertTrue(allFilesHaveCodeInLang(langName3));
        assertTrue(allFilesHaveCodeCount(3));

        xmlManager.editLang(langName2, langName5);
        langList = xmlManager.loadLangList();
        assertEquals(langName4, langList.get(0));
        assertEquals(langName5, langList.get(1));
        assertEquals(langName3, langList.get(2));
        assertTrue(allFilesHaveCodeInLang(langName4));
        assertTrue(allFilesHaveCodeInLang(langName5));
        assertTrue(allFilesHaveCodeInLang(langName3));
        assertTrue(allFilesHaveCodeCount(3));

        xmlManager.editLang(langName3, langName6);
        langList = xmlManager.loadLangList();
        assertEquals(langName4, langList.get(0));
        assertEquals(langName5, langList.get(1));
        assertEquals(langName6, langList.get(2));
        assertTrue(allFilesHaveCodeInLang(langName4));
        assertTrue(allFilesHaveCodeInLang(langName5));
        assertTrue(allFilesHaveCodeInLang(langName6));
        assertTrue(allFilesHaveCodeCount(3));
    }

    /**
     * Tests the removeLang method.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeLangTest() throws ADataManagementException, ParserConfigurationException, SAXException, IOException {
        testData.initXmlManager(xmlManager);
        ArrayList<String> langList;
        String className1 = "ClassA";
        String className2 = "ClassB";
        String className3 = "ClassC";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        xmlManager.addClass(className3);

        String langName1 = "LangA";
        String langName2 = "LangB";
        String langName3 = "LangC";
        xmlManager.addLang(langName1);
        xmlManager.addLang(langName2);
        xmlManager.addLang(langName3);

        xmlManager.removeLang(langName1);
        langList = xmlManager.loadLangList();
        assertEquals(langName2, langList.get(0));
        assertEquals(langName3, langList.get(1));
        assertTrue(allFilesHaveCodeInLang(langName2));
        assertTrue(allFilesHaveCodeInLang(langName3));
        assertTrue(allFilesHaveCodeCount(2));

        xmlManager.removeLang(langName2);
        langList = xmlManager.loadLangList();
        assertEquals(langName3, langList.get(0));
        assertTrue(allFilesHaveCodeInLang(langName3));
        assertTrue(allFilesHaveCodeCount(1));

        xmlManager.removeLang(langName3);
        langList = xmlManager.loadLangList();
        assertEquals(0, langList.size());
        assertTrue(allFilesHaveCodeCount(0));
    }

    /**
     * Tests the saveCode method.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void saveCodeTest() throws ADataManagementException, ParserConfigurationException, SAXException, IOException {
        testData.initXmlManager(xmlManager);
        String className1 = "ClassA";
        String className2 = "ClassB";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        String langName1 = "LangA";
        String langName2 = "LangB";
        xmlManager.addLang(langName1);
        xmlManager.addLang(langName2);

        String formatStr = "Source code example for class <%s>\nwritten in <%s> programming language";
        String codeAA = String.format(formatStr, className1, langName1);
        String codeAB = String.format(formatStr, className1, langName2);
        String codeBA = String.format(formatStr, className2, langName1);
        String codeBB = String.format(formatStr, className2, langName2);
        xmlManager.saveCode(className1, langName1, codeAA);
        xmlManager.saveCode(className1, langName2, codeAB);
        xmlManager.saveCode(className2, langName1, codeBA);
        xmlManager.saveCode(className2, langName2, codeBB);
        assertEquals(codeAA, readCodeFromFile(className1, langName1));
        assertEquals(codeAB, readCodeFromFile(className1, langName2));
        assertEquals(codeBA, readCodeFromFile(className2, langName1));
        assertEquals(codeBB, readCodeFromFile(className2, langName2));

        formatStr = "NEW VERSION of <%s> in <%s>";
        codeAA = String.format(formatStr, className1, langName1);
        codeAB = String.format(formatStr, className1, langName2);
        codeBA = String.format(formatStr, className2, langName1);
        codeBB = String.format(formatStr, className2, langName2);
        xmlManager.saveCode(className1, langName1, codeAA);
        xmlManager.saveCode(className1, langName2, codeAB);
        xmlManager.saveCode(className2, langName1, codeBA);
        xmlManager.saveCode(className2, langName2, codeBB);
        assertEquals(codeAA, readCodeFromFile(className1, langName1));
        assertEquals(codeAB, readCodeFromFile(className1, langName2));
        assertEquals(codeBA, readCodeFromFile(className2, langName1));
        assertEquals(codeBB, readCodeFromFile(className2, langName2));
    }

    /**
     * Tests the loadCode method.
     *
     * @throws application.core.ADataManagementException an error
     */
    @Test
    public void loadCodeTest() throws ADataManagementException {
        testData.initXmlManager(xmlManager);
        String className1 = "ClassA";
        String className2 = "ClassB";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        String langName1 = "LangA";
        String langName2 = "LangB";
        xmlManager.addLang(langName1);
        xmlManager.addLang(langName2);

        String formatStr = "Source code example for class <%s>\nwritten in <%s> programming language";
        String codeAA = String.format(formatStr, className1, langName1);
        String codeAB = String.format(formatStr, className1, langName2);
        String codeBA = String.format(formatStr, className2, langName1);
        String codeBB = String.format(formatStr, className2, langName2);
        xmlManager.saveCode(className1, langName1, codeAA);
        xmlManager.saveCode(className1, langName2, codeAB);
        xmlManager.saveCode(className2, langName1, codeBA);
        xmlManager.saveCode(className2, langName2, codeBB);
        assertEquals(codeAA, xmlManager.loadCode(className1, langName1));
        assertEquals(codeAB, xmlManager.loadCode(className1, langName2));
        assertEquals(codeBA, xmlManager.loadCode(className2, langName1));
        assertEquals(codeBB, xmlManager.loadCode(className2, langName2));

        formatStr = "NEW VERSION of <%s> in <%s>";
        codeAA = String.format(formatStr, className1, langName1);
        codeAB = String.format(formatStr, className1, langName2);
        codeBA = String.format(formatStr, className2, langName1);
        codeBB = String.format(formatStr, className2, langName2);
        xmlManager.saveCode(className1, langName1, codeAA);
        xmlManager.saveCode(className1, langName2, codeAB);
        xmlManager.saveCode(className2, langName1, codeBA);
        xmlManager.saveCode(className2, langName2, codeBB);
        assertEquals(codeAA, xmlManager.loadCode(className1, langName1));
        assertEquals(codeAB, xmlManager.loadCode(className1, langName2));
        assertEquals(codeBA, xmlManager.loadCode(className2, langName1));
        assertEquals(codeBB, xmlManager.loadCode(className2, langName2));
    }

    /*
     Checks if a valid XML file for the specified class exists in the current test testData directory
     */
    private boolean validClassFileExists(String className) throws SAXException, IOException, ParserConfigurationException {
        // building a path from the class name
        File file = testData.getFileFromClass(className);

        // creating a document and searching for a required element representing the code list
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document document = db.parse(file);
        NodeList codeNodes = document.getElementsByTagName("codes");

        // checking if there is a valid number of required elements
        return codeNodes.getLength() == 1;
    }

    /*
     Checks if the current test testData directory has the specified number of files.
     */
    private boolean directoryHasFileCount(int count) {
        return testData.getDataFilesFolder().listFiles().length == count;
    }

    /*
     Checks if all of the XML class files in the current test testData directory
     have the code element with the specified lang attribute.
     */
    private boolean allFilesHaveCodeInLang(String lang) throws ParserConfigurationException, SAXException, IOException {
        File[] files = testData.getDataFilesFolder().listFiles();
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();

        // iterating through the files
        for (File file : files) {
            // parsing XML and searching for elements with source code
            db.reset();
            Document document = db.parse(file);
            NodeList codeNodes = document.getElementsByTagName("code");

            // assumption of missing required code element
            boolean containsLang = false;

            // iterating through the code elements in the current file
            for (int i = 0; i < codeNodes.getLength(); i++) {
                Node codeNode = codeNodes.item(i);

                if (codeNode.getNodeType() == Node.ELEMENT_NODE
                        && ((Element) codeNode).getAttribute("lang").equals(lang)) {
                    // jumping to another file if the element was found
                    containsLang = true;
                    break;
                }
            }

            // returning FALSE if the file without the required element was found
            if (!containsLang) {
                return false;
            }
        }

        // returning TRUE if there is the required element in all files
        return true;
    }

    /*
     Checks if all of the XML class files in the current test testData directory
     have the specified number of the code elements.
     */
    private boolean allFilesHaveCodeCount(int count) throws SAXException, IOException, ParserConfigurationException {
        File[] files = testData.getDataFilesFolder().listFiles();
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();

        // iterating through the files
        for (File file : files) {
            // parsing XML and searching for elements with source code
            db.reset();
            Document document = db.parse(file);
            NodeList codeNodes = document.getElementsByTagName("code");

            // returning FALSE if the file with wrong number of elements was found
            if (codeNodes.getLength() != count) {
                return false;
            }
        }

        // returning TRUE if there is the right number of elements in all files
        return true;
    }

    /*
     Reads the source code representing a specified class written in a specified language,
     saved as the text content of the corresponding XML element in the corresponding XML testData file.
     */
    private String readCodeFromFile(String clazz, String lang) throws ParserConfigurationException, SAXException, IOException {
        // building a path from the class name
        File file = testData.getFileFromClass(clazz);

        // creating a document and searching for the element containing the requested source code
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document document = db.parse(file);
        NodeList codeNodes = document.getElementsByTagName("code");

        // iterating through the code elements
        for (int i = 0; i < codeNodes.getLength(); i++) {
            Node codeNode = codeNodes.item(i);

            if (codeNode.getNodeType() == Node.ELEMENT_NODE) {
                Element codeElement = (Element) codeNode;

                // returning the escaped text content of the corresponding element
                if (codeElement.getAttribute("lang").equals(lang)) {
                    return codeElement.getTextContent();
                }
            }
        }

        return null;
    }

}
