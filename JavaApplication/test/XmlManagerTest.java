import application.CodeManagementException;
import application.XmlManager;
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
import org.apache.commons.io.FileUtils;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

/**
 * The {@code XmlManagerTest} class performs automatic unit testing of the
 * {@code XmlManager} class.
 *
 * @author Petr Kozler
 */
public class XmlManagerTest {

    // path to the folder with test data directories (relative to the project root folder)
    private static final String TEST_DATA_FOLDER = "temp/";
    // name of the main test XML data file with the lists of available Java classes and programming languages
    private static final String MAIN_DATA_FILE = "classes.xml";
    // name of the folder with test XML data files with translations of each class to each language
    private static final String DATA_FILES_FOLDER = "classes/";
    // a counter of test runs for building the real path to the current test data directory
    private static int testCounter = 0;

    // the real path to the current test data directory consisting of the root folder and the test number
    private String testDataFolderDest;
    // the real path to the main test XML data file for current test
    private String mainDataFileDest;
    // the real path to the folder with test XML data files for current test
    private String dataFilesFolderDest;
    // tested XML manager
    private XmlManager xmlManager;

    /*
     Creates a new folder for test XML data files associated with current test.
     */
    private void createTestDataDirectory() throws IOException {
        File directory = new File(dataFilesFolderDest);

        // creating the directory for current test
        if (!directory.mkdirs()) {
            throw new IOException("Unable to create the test data directory.");
        }
    }

    /*
     Creates a new main test XML data file associated with current test.
     */
    private void createTestDataMainFile() throws ParserConfigurationException, TransformerException {
        File file = new File(mainDataFileDest);

        // creating the stream for a new main file
        StreamResult result = new StreamResult(file);
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder documentBuilder = dbf.newDocumentBuilder();

        // creating basic document elements
        Document document = documentBuilder.newDocument();
        Element root = document.createElement("lists");
        Element langList = document.createElement("languages");
        Element classList = document.createElement("classes");
        root.appendChild(langList);
        root.appendChild(classList);
        document.appendChild(root);
        document.normalize();

        // creating a new DOM source
        DOMSource source = new DOMSource(document);
        TransformerFactory factory = TransformerFactory.newInstance();
        Transformer transformer = factory.newTransformer();

        // writing the DOM to the stream
        transformer.transform(source, result);
    }

    /*
     Checks if a valid XML file for the specified class exists in the current test data directory
     */
    private boolean validClassFileExists(String className) throws SAXException, IOException, ParserConfigurationException {
        // building a path from the class name
        File file = new File(dataFilesFolderDest + className.toLowerCase() + ".xml");

        // creating a document and searching for a required element representing the code list
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DocumentBuilder db = dbf.newDocumentBuilder();
        Document document = db.parse(file);
        NodeList codeNodes = document.getElementsByTagName("codes");

        // checking if there is a valid number of required elements
        return codeNodes.getLength() == 1;
    }

    /*
     Checks if the current test data directory has the specified number of files.
     */
    private boolean directoryHasFileCount(int count) {
        return new File(dataFilesFolderDest).listFiles().length == count;
    }

    /*
     Checks if all of the XML class files in the current test data directory
     have the code element with the specified lang attribute.
     */
    private boolean allFilesHaveCodeInLang(String lang) throws ParserConfigurationException, SAXException, IOException {
        File[] files = new File(dataFilesFolderDest).listFiles();
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
     Checks if all of the XML class files in the current test data directory
     have the specified number of the code elements.
     */
    private boolean allFilesHaveCodeCount(int count) throws SAXException, IOException, ParserConfigurationException {
        File[] files = new File(dataFilesFolderDest).listFiles();
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
     saved as the text content of the corresponding XML element in the corresponding XML data file.
     */
    private String readCodeFromFile(String clazz, String lang) throws ParserConfigurationException, SAXException, IOException {
        // building a path from the class name
        File file = new File(dataFilesFolderDest + clazz.toLowerCase() + ".xml");

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

    /**
     * Creates a clean test data directory structure and initializes the XML
     * manager before each test is run.
     *
     * @throws ParserConfigurationException parser error
     * @throws TransformerException transformer error
     * @throws IOException IO error
     * @throws application.CodeManagementException error when setting the paths
     * for XML manager
     */
    @Before
    public void setUp() throws ParserConfigurationException, TransformerException, IOException, CodeManagementException {
        testCounter++;

        // building the real paths for the current test
        testDataFolderDest = TEST_DATA_FOLDER + testCounter + "/";
        mainDataFileDest = testDataFolderDest + MAIN_DATA_FILE;
        dataFilesFolderDest = testDataFolderDest + DATA_FILES_FOLDER;

        // creating the files and directories for the current test
        createTestDataDirectory();
        createTestDataMainFile();

        // initializing the XML manager
        xmlManager = new XmlManager();
        xmlManager.setPaths(mainDataFileDest, dataFilesFolderDest);
    }

    /**
     * Tests the loadClassList method.
     *
     * @throws application.CodeManagementException an error
     */
    @Test
    public void loadClassListTest() throws CodeManagementException {
        ArrayList<String> classList = xmlManager.loadClassList();
        assertEquals(0, classList.size());
    }

    /**
     * Tests the loadLangList method.
     *
     * @throws application.CodeManagementException an error
     */
    @Test
    public void loadLangListTest() throws CodeManagementException {
        ArrayList<String> langList = xmlManager.loadLangList();
        assertEquals(0, langList.size());
    }

    /**
     * Tests the addClass method.
     *
     * @throws application.CodeManagementException an error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     */
    @Test
    public void addClassTest() throws CodeManagementException, SAXException, IOException, ParserConfigurationException {
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
     * @throws application.CodeManagementException an error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     */
    @Test
    public void editClassTest() throws CodeManagementException, SAXException, IOException, ParserConfigurationException {
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
     * @throws application.CodeManagementException an error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     */
    @Test
    public void removeClassTest() throws CodeManagementException, SAXException, IOException, ParserConfigurationException {
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
     * @throws application.CodeManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addLangTest() throws CodeManagementException, ParserConfigurationException, SAXException, IOException {
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
     * @throws application.CodeManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editLangTest() throws CodeManagementException, ParserConfigurationException, SAXException, IOException {
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
     * @throws application.CodeManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeLangTest() throws CodeManagementException, ParserConfigurationException, SAXException, IOException {
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
     * @throws application.CodeManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void saveCodeTest() throws CodeManagementException, ParserConfigurationException, SAXException, IOException {
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
     * @throws application.CodeManagementException an error
     */
    @Test
    public void loadCodeTest() throws CodeManagementException {
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

    /**
     * Deletes the test data directory structure after each test is run.
     *
     * @throws IOException IO error
     */
    @After
    public void tearDown() throws IOException {
        // deleting temporary test data directory from current test
        FileUtils.deleteDirectory(new File(testDataFolderDest));
    }

}
