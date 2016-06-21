
import main.app.ADataManagementException;
import main.app.xml.XmlKeyword;
import main.app.xml.XmlManager;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.TransformerException;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;
import org.junit.Rule;
import org.junit.rules.TestName;
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

    /**
     * rule for accessing the test method names
     */
    @Rule
    public TestName testName = new TestName();

    // tested XML manager
    private XmlManager xmlManager;
    // testUtils for tested XML manager
    private XmlManagerTestUtils testUtils;

    /**
     * Creates the XML manager and prepares the test data directory before each
     * test is run.
     *
     * @throws ParserConfigurationException parser error
     * @throws TransformerException transformer error
     * @throws IOException IO error
     */
    @Before
    public void setUp()
            throws ParserConfigurationException, TransformerException, IOException {
        xmlManager = new XmlManager();
        testUtils = new XmlManagerTestUtils(XmlManagerTestUtils.POSITIVE_TEST);
    }

    /**
     * Tests the initialize method.
     *
     * @throws main.app.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws java.io.IOException IO error
     */
    @Test
    public void initializeTest()
            throws ADataManagementException, IOException, ParserConfigurationException, TransformerException {
        // initializing test directory
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName(), false);

        // reading the content before XML manager initialization
        String mainFileContentBefore = new Scanner(testUtils.getMainFile()).useDelimiter("\\Z").next();
        String filesFolderContentBefore = Arrays.toString(testUtils.getSubfolder().listFiles());

        // setting paths to XML manager
        testUtils.initializeXmlManager(xmlManager);

        // reading the content after XML manager initialization
        String mainFileContentAfter = new Scanner(testUtils.getMainFile()).useDelimiter("\\Z").next();
        String filesFolderContentAfter = Arrays.toString(testUtils.getSubfolder().listFiles());

        // comparing the contents before and after the initialization
        assertEquals(mainFileContentBefore, mainFileContentAfter);
        assertEquals(filesFolderContentBefore, filesFolderContentAfter);
    }

    /**
     * Tests the loadClassList method.
     *
     * @throws main.app.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws java.io.IOException IO error
     */
    @Test
    public void loadClassListTest()
            throws ADataManagementException, IOException, ParserConfigurationException, TransformerException {
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        ArrayList<String> classList = xmlManager.loadClassList();
        assertEquals(0, classList.size());
    }

    /**
     * Tests the loadLanguageList method.
     *
     * @throws main.app.ADataManagementException an error
     * @throws java.io.IOException
     * @throws javax.xml.parsers.ParserConfigurationException
     * @throws javax.xml.transform.TransformerException
     */
    @Test
    public void loadLanguageListTest()
            throws ADataManagementException, IOException, ParserConfigurationException, TransformerException {
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        ArrayList<String> langList = xmlManager.loadLanguageList();
        assertEquals(0, langList.size());
    }

    /**
     * Tests the addClass method.
     *
     * @throws main.app.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addClassTest()
            throws ADataManagementException, SAXException, IOException, ParserConfigurationException, TransformerException {
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        ArrayList<String> classList;
        String className1 = "System";
        String className2 = "Scanner";
        String className3 = "String";
        xmlManager.addClass(className1);
        classList = xmlManager.loadClassList();
        assertEquals(className1, classList.get(0));
        assertTrue(directoryContainsValidClassFile(className1));
        assertTrue(directoryHasFileCount(1));

        xmlManager.addClass(className2);
        classList = xmlManager.loadClassList();
        assertEquals(className1, classList.get(0));
        assertEquals(className2, classList.get(1));
        assertTrue(directoryContainsValidClassFile(className1));
        assertTrue(directoryContainsValidClassFile(className2));
        assertTrue(directoryHasFileCount(2));

        xmlManager.addClass(className3);
        classList = xmlManager.loadClassList();
        assertEquals(className1, classList.get(0));
        assertEquals(className2, classList.get(1));
        assertEquals(className3, classList.get(2));
        assertTrue(directoryContainsValidClassFile(className1));
        assertTrue(directoryContainsValidClassFile(className2));
        assertTrue(directoryContainsValidClassFile(className3));
        assertTrue(directoryHasFileCount(3));
    }

    /**
     * Tests the editClass method.
     *
     * @throws main.app.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editClassTest()
            throws ADataManagementException, SAXException, IOException, ParserConfigurationException, TransformerException {
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        ArrayList<String> classList;
        String className1 = "System";
        String className2 = "Scanner";
        String className3 = "String";
        String className4 = "ArrayList";
        String className5 = "Arrays";
        String className6 = "Math";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        xmlManager.addClass(className3);

        xmlManager.editClass(className1, className4);
        classList = xmlManager.loadClassList();
        assertEquals(className4, classList.get(0));
        assertEquals(className2, classList.get(1));
        assertEquals(className3, classList.get(2));
        assertTrue(directoryContainsValidClassFile(className4));
        assertTrue(directoryContainsValidClassFile(className2));
        assertTrue(directoryContainsValidClassFile(className3));
        assertTrue(directoryHasFileCount(3));

        xmlManager.editClass(className2, className5);
        classList = xmlManager.loadClassList();
        assertEquals(className4, classList.get(0));
        assertEquals(className5, classList.get(1));
        assertEquals(className3, classList.get(2));
        assertTrue(directoryContainsValidClassFile(className4));
        assertTrue(directoryContainsValidClassFile(className5));
        assertTrue(directoryContainsValidClassFile(className3));
        assertTrue(directoryHasFileCount(3));

        xmlManager.editClass(className3, className6);
        classList = xmlManager.loadClassList();
        assertEquals(className4, classList.get(0));
        assertEquals(className5, classList.get(1));
        assertEquals(className6, classList.get(2));
        assertTrue(directoryContainsValidClassFile(className4));
        assertTrue(directoryContainsValidClassFile(className5));
        assertTrue(directoryContainsValidClassFile(className6));
        assertTrue(directoryHasFileCount(3));
    }

    /**
     * Tests the removeClass method.
     *
     * @throws main.app.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeClassTest()
            throws ADataManagementException, SAXException, IOException, ParserConfigurationException, TransformerException {
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        ArrayList<String> classList;
        String className1 = "System";
        String className2 = "Scanner";
        String className3 = "String";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        xmlManager.addClass(className3);

        xmlManager.removeClass(className1);
        classList = xmlManager.loadClassList();
        assertEquals(className2, classList.get(0));
        assertEquals(className3, classList.get(1));
        assertTrue(directoryContainsValidClassFile(className2));
        assertTrue(directoryContainsValidClassFile(className3));
        assertTrue(directoryHasFileCount(2));

        xmlManager.removeClass(className2);
        classList = xmlManager.loadClassList();
        assertEquals(className3, classList.get(0));
        assertTrue(directoryContainsValidClassFile(className3));
        assertTrue(directoryHasFileCount(1));

        xmlManager.removeClass(className3);
        classList = xmlManager.loadClassList();
        assertEquals(0, classList.size());
        assertTrue(directoryHasFileCount(0));
    }

    /**
     * Tests the addLanguage method.
     *
     * @throws main.app.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addLanguageTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        ArrayList<String> langList;
        String className1 = "System";
        String className2 = "Scanner";
        String className3 = "String";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        xmlManager.addClass(className3);

        String langName1 = "Pascal";
        String langName2 = "C#";
        String langName3 = "C++";

        xmlManager.addLanguage(langName1);
        langList = xmlManager.loadLanguageList();
        assertEquals(langName1, langList.get(0));
        assertTrue(allFilesContainCodeInLang(langName1));
        assertTrue(allFilesHaveCodeCount(1));

        xmlManager.addLanguage(langName2);
        langList = xmlManager.loadLanguageList();
        assertEquals(langName1, langList.get(0));
        assertEquals(langName2, langList.get(1));
        assertTrue(allFilesContainCodeInLang(langName1));
        assertTrue(allFilesContainCodeInLang(langName2));
        assertTrue(allFilesHaveCodeCount(2));

        xmlManager.addLanguage(langName3);
        langList = xmlManager.loadLanguageList();
        assertEquals(langName1, langList.get(0));
        assertEquals(langName2, langList.get(1));
        assertEquals(langName3, langList.get(2));
        assertTrue(allFilesContainCodeInLang(langName1));
        assertTrue(allFilesContainCodeInLang(langName2));
        assertTrue(allFilesContainCodeInLang(langName3));
        assertTrue(allFilesHaveCodeCount(3));
    }

    /**
     * Tests the editLanguage method.
     *
     * @throws main.app.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editLanguageTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        ArrayList<String> langList;
        String className1 = "System";
        String className2 = "Scanner";
        String className3 = "String";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        xmlManager.addClass(className3);

        String langName1 = "Pascal";
        String langName2 = "C#";
        String langName3 = "C++";
        String langName4 = "Python";
        String langName5 = "JavaScript";
        String langName6 = "PHP";
        xmlManager.addLanguage(langName1);
        xmlManager.addLanguage(langName2);
        xmlManager.addLanguage(langName3);

        xmlManager.editLanguage(langName1, langName4);
        langList = xmlManager.loadLanguageList();
        assertEquals(langName4, langList.get(0));
        assertEquals(langName2, langList.get(1));
        assertEquals(langName3, langList.get(2));
        assertTrue(allFilesContainCodeInLang(langName4));
        assertTrue(allFilesContainCodeInLang(langName2));
        assertTrue(allFilesContainCodeInLang(langName3));
        assertTrue(allFilesHaveCodeCount(3));

        xmlManager.editLanguage(langName2, langName5);
        langList = xmlManager.loadLanguageList();
        assertEquals(langName4, langList.get(0));
        assertEquals(langName5, langList.get(1));
        assertEquals(langName3, langList.get(2));
        assertTrue(allFilesContainCodeInLang(langName4));
        assertTrue(allFilesContainCodeInLang(langName5));
        assertTrue(allFilesContainCodeInLang(langName3));
        assertTrue(allFilesHaveCodeCount(3));

        xmlManager.editLanguage(langName3, langName6);
        langList = xmlManager.loadLanguageList();
        assertEquals(langName4, langList.get(0));
        assertEquals(langName5, langList.get(1));
        assertEquals(langName6, langList.get(2));
        assertTrue(allFilesContainCodeInLang(langName4));
        assertTrue(allFilesContainCodeInLang(langName5));
        assertTrue(allFilesContainCodeInLang(langName6));
        assertTrue(allFilesHaveCodeCount(3));
    }

    /**
     * Tests the removeLanguage method.
     *
     * @throws main.app.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeLanguageTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        ArrayList<String> langList;
        String className1 = "System";
        String className2 = "Scanner";
        String className3 = "String";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        xmlManager.addClass(className3);

        String langName1 = "Pascal";
        String langName2 = "C#";
        String langName3 = "C++";
        xmlManager.addLanguage(langName1);
        xmlManager.addLanguage(langName2);
        xmlManager.addLanguage(langName3);

        xmlManager.removeLanguage(langName1);
        langList = xmlManager.loadLanguageList();
        assertEquals(langName2, langList.get(0));
        assertEquals(langName3, langList.get(1));
        assertTrue(allFilesContainCodeInLang(langName2));
        assertTrue(allFilesContainCodeInLang(langName3));
        assertTrue(allFilesHaveCodeCount(2));

        xmlManager.removeLanguage(langName2);
        langList = xmlManager.loadLanguageList();
        assertEquals(langName3, langList.get(0));
        assertTrue(allFilesContainCodeInLang(langName3));
        assertTrue(allFilesHaveCodeCount(1));

        xmlManager.removeLanguage(langName3);
        langList = xmlManager.loadLanguageList();
        assertEquals(0, langList.size());
        assertTrue(allFilesHaveCodeCount(0));
    }

    /**
     * Tests the saveCode method.
     *
     * @throws main.app.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void saveCodeTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        String className1 = "System";
        String className2 = "Scanner";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        String langName1 = "Pascal";
        String langName2 = "C#";
        xmlManager.addLanguage(langName1);
        xmlManager.addLanguage(langName2);

        int version = 1;
        String codeAA = getCode(className1, langName1, version);
        String codeAB = getCode(className1, langName2, version);
        String codeBA = getCode(className2, langName1, version);
        String codeBB = getCode(className2, langName2, version);
        xmlManager.saveCode(className1, langName1, codeAA);
        xmlManager.saveCode(className1, langName2, codeAB);
        xmlManager.saveCode(className2, langName1, codeBA);
        xmlManager.saveCode(className2, langName2, codeBB);
        assertEquals(codeAA, readCodeFromFile(className1, langName1));
        assertEquals(codeAB, readCodeFromFile(className1, langName2));
        assertEquals(codeBA, readCodeFromFile(className2, langName1));
        assertEquals(codeBB, readCodeFromFile(className2, langName2));

        version++;
        codeAA = getCode(className1, langName1, version);
        codeAB = getCode(className1, langName2, version);
        codeBA = getCode(className2, langName1, version);
        codeBB = getCode(className2, langName2, version);
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
     * @throws main.app.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws java.io.IOException IO error
     */
    @Test
    public void loadCodeTest()
            throws ADataManagementException, IOException, ParserConfigurationException, TransformerException {
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        String className1 = "System";
        String className2 = "Scanner";
        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        String langName1 = "Pascal";
        String langName2 = "C#";
        xmlManager.addLanguage(langName1);
        xmlManager.addLanguage(langName2);

        int version = 1;
        String codeAA = getCode(className1, langName1, version);
        String codeAB = getCode(className1, langName2, version);
        String codeBA = getCode(className2, langName1, version);
        String codeBB = getCode(className2, langName2, version);
        xmlManager.saveCode(className1, langName1, codeAA);
        xmlManager.saveCode(className1, langName2, codeAB);
        xmlManager.saveCode(className2, langName1, codeBA);
        xmlManager.saveCode(className2, langName2, codeBB);
        assertEquals(codeAA, xmlManager.loadCode(className1, langName1));
        assertEquals(codeAB, xmlManager.loadCode(className1, langName2));
        assertEquals(codeBA, xmlManager.loadCode(className2, langName1));
        assertEquals(codeBB, xmlManager.loadCode(className2, langName2));

        version++;
        codeAA = getCode(className1, langName1, version);
        codeAB = getCode(className1, langName2, version);
        codeBA = getCode(className2, langName1, version);
        codeBB = getCode(className2, langName2, version);
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
     * Tests all methods.
     *
     * @throws main.app.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws java.io.IOException IO error
     * @throws org.xml.sax.SAXException SAX error
     */
    @Test
    public void allMethodsTest()
            throws ADataManagementException, IOException, ParserConfigurationException, TransformerException, SAXException {
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        String className1 = "PrintStream";
        String className2 = "Scanner";
        String className3 = "String";
        String className4 = "Math";
        String className5 = "Arrays";
        String className6 = "ArrayList";
        String langName1 = "C#";
        String langName2 = "Python";
        String langName3 = "PHP";
        String langName4 = "JavaScript";
        String langName5 = "C/C++";
        String langName6 = "Pascal/Object Pascal";

        ArrayList classList, langList;
        String code;
        int version;

        version = 1;

        classList = xmlManager.loadClassList();
        langList = xmlManager.loadLanguageList();

        assertTrue(classList.isEmpty());
        assertTrue(langList.isEmpty());

        xmlManager.addClass(className1);
        xmlManager.addClass(className2);
        xmlManager.addClass(className3);

        classList = xmlManager.loadClassList();
        assertEquals(3, classList.size());
        assertTrue(classList.contains(className1));
        assertTrue(classList.contains(className2));
        assertTrue(classList.contains(className3));
        assertTrue(directoryHasFileCount(3));
        assertTrue(directoryContainsValidClassFile(className1));
        assertTrue(directoryContainsValidClassFile(className2));
        assertTrue(directoryContainsValidClassFile(className3));

        xmlManager.editClass(className2, className5);
        xmlManager.editClass(className3, className6);

        xmlManager.removeClass(className6);

        xmlManager.addLanguage(langName1);
        xmlManager.addLanguage(langName2);
        xmlManager.addLanguage(langName3);

        langList = xmlManager.loadLanguageList();
        assertEquals(3, langList.size());
        assertTrue(langList.contains(langName1));
        assertTrue(langList.contains(langName2));
        assertTrue(langList.contains(langName3));
        assertTrue(allFilesHaveCodeCount(3));
        assertTrue(allFilesContainCodeInLang(langName1));
        assertTrue(allFilesContainCodeInLang(langName2));
        assertTrue(allFilesContainCodeInLang(langName3));

        xmlManager.editLanguage(langName1, langName4);
        xmlManager.editLanguage(langName2, langName5);

        xmlManager.removeLanguage(langName4);

        classList = xmlManager.loadClassList();
        assertEquals(2, classList.size());
        assertTrue(classList.contains(className1));
        assertTrue(classList.contains(className5));
        assertTrue(directoryHasFileCount(2));
        assertTrue(directoryContainsValidClassFile(className1));
        assertTrue(directoryContainsValidClassFile(className5));

        langList = xmlManager.loadLanguageList();
        assertEquals(2, langList.size());
        assertTrue(langList.contains(langName3));
        assertTrue(langList.contains(langName5));
        assertTrue(allFilesHaveCodeCount(2));
        assertTrue(allFilesContainCodeInLang(langName3));
        assertTrue(allFilesContainCodeInLang(langName5));

        code = xmlManager.loadCode(className1, langName3);
        assertEquals("", code);
        code = xmlManager.loadCode(className5, langName5);
        assertEquals("", code);

        String code13 = getCode(className1, langName3, version);
        String code55 = getCode(className5, className5, version);

        xmlManager.saveCode(className1, langName3, code13);
        xmlManager.saveCode(className5, langName5, code55);

        code = xmlManager.loadCode(className1, langName3);
        assertEquals(code13, code);
        code = xmlManager.loadCode(className5, langName5);
        assertEquals(code55, code);

        version++;

        classList = xmlManager.loadClassList();
        langList = xmlManager.loadLanguageList();

        assertTrue(!classList.isEmpty());
        assertTrue(!langList.isEmpty());

        xmlManager.addClass(className6);
        xmlManager.addClass(className4);
        xmlManager.addClass(className3);

        classList = xmlManager.loadClassList();
        assertEquals(5, classList.size());
        assertTrue(classList.contains(className1));
        assertTrue(classList.contains(className5));
        assertTrue(classList.contains(className6));
        assertTrue(classList.contains(className4));
        assertTrue(classList.contains(className3));
        assertTrue(directoryHasFileCount(5));
        assertTrue(directoryContainsValidClassFile(className1));
        assertTrue(directoryContainsValidClassFile(className5));
        assertTrue(directoryContainsValidClassFile(className6));
        assertTrue(directoryContainsValidClassFile(className4));
        assertTrue(directoryContainsValidClassFile(className3));

        xmlManager.editClass(className5, className2);
        xmlManager.editClass(className1, className5);

        xmlManager.removeClass(className5);

        xmlManager.addLanguage(langName6);
        xmlManager.addLanguage(langName4);
        xmlManager.addLanguage(langName2);

        langList = xmlManager.loadLanguageList();
        assertEquals(5, langList.size());
        assertTrue(langList.contains(langName3));
        assertTrue(langList.contains(langName5));
        assertTrue(langList.contains(langName6));
        assertTrue(langList.contains(langName4));
        assertTrue(langList.contains(langName2));
        assertTrue(allFilesHaveCodeCount(5));
        assertTrue(allFilesContainCodeInLang(langName3));
        assertTrue(allFilesContainCodeInLang(langName5));
        assertTrue(allFilesContainCodeInLang(langName6));
        assertTrue(allFilesContainCodeInLang(langName4));
        assertTrue(allFilesContainCodeInLang(langName2));

        xmlManager.editLanguage(langName6, langName1);
        xmlManager.editLanguage(langName2, langName6);

        xmlManager.removeLanguage(langName6);

        classList = xmlManager.loadClassList();
        assertEquals(4, classList.size());
        assertTrue(classList.contains(className2));
        assertTrue(classList.contains(className6));
        assertTrue(classList.contains(className4));
        assertTrue(classList.contains(className3));
        assertTrue(directoryHasFileCount(4));
        assertTrue(directoryContainsValidClassFile(className2));
        assertTrue(directoryContainsValidClassFile(className6));
        assertTrue(directoryContainsValidClassFile(className4));
        assertTrue(directoryContainsValidClassFile(className3));

        langList = xmlManager.loadLanguageList();
        assertEquals(4, langList.size());
        assertTrue(langList.contains(langName5));
        assertTrue(langList.contains(langName3));
        assertTrue(langList.contains(langName1));
        assertTrue(langList.contains(langName4));
        assertTrue(allFilesHaveCodeCount(4));
        assertTrue(allFilesContainCodeInLang(langName5));
        assertTrue(allFilesContainCodeInLang(langName3));
        assertTrue(allFilesContainCodeInLang(langName1));
        assertTrue(allFilesContainCodeInLang(langName4));

        code = xmlManager.loadCode(className2, langName5);
        assertEquals(code55, code);
        code = xmlManager.loadCode(className6, langName3);
        assertEquals("", code);
        code = xmlManager.loadCode(className4, langName1);
        assertEquals("", code);
        code = xmlManager.loadCode(className3, langName4);
        assertEquals("", code);

        String code25 = getCode(className2, langName5, version);
        String code63 = getCode(className6, langName3, version);
        String code41 = getCode(className4, langName1, version);
        String code43 = getCode(className3, langName4, version);

        xmlManager.saveCode(className2, langName5, code25);
        xmlManager.saveCode(className6, langName3, code63);
        xmlManager.saveCode(className4, langName1, code41);
        xmlManager.saveCode(className3, langName4, code43);

        code = xmlManager.loadCode(className2, langName5);
        assertEquals(code25, code);
        code = xmlManager.loadCode(className6, langName3);
        assertEquals(code63, code);
        code = xmlManager.loadCode(className4, langName1);
        assertEquals(code41, code);
        code = xmlManager.loadCode(className3, langName4);
        assertEquals(code43, code);
    }

    /*
     Builds a string which is used as a source code example.
     */
    private String getCode(String clazz, String lang, int version) {
        // formatting a source code string
        return String.format("\n{\n\tClass: %s,\n\tLanguage: %s,\n\tVersion: %d\n}\n", clazz, lang, version);
    }

    /*
     Checks if a valid XML file for the specified class exists in the current test testUtils directory
     */
    private boolean directoryContainsValidClassFile(String className)
            throws SAXException, IOException, ParserConfigurationException {
        // creating a document and searching for a required element representing the code list
        Document document = testUtils.readDocumentFromFile(testUtils.getFileFromClass(className));
        NodeList codeNodes = document.getElementsByTagName(XmlKeyword.CODE_ROOT_ELEMENT.getName());

        // checking if there is a valid number of required elements
        return codeNodes.getLength() == 1;
    }

    /*
     Checks if the current test testUtils directory has the specified number of files.
     */
    private boolean directoryHasFileCount(int count) {
        // comparing the number of files
        return testUtils.getSubfolder().listFiles().length == count;
    }

    /*
     Checks if all of the XML class files in the current test testUtils directory
     have the code element with the specified lang attribute.
     */
    private boolean allFilesContainCodeInLang(String lang)
            throws ParserConfigurationException, SAXException, IOException {
        File[] files = testUtils.getSubfolder().listFiles();

        // iterating through the files
        for (File file : files) {
            // parsing XML and searching for elements with source code
            Document document = testUtils.readDocumentFromFile(file);
            NodeList codeNodes = document.getElementsByTagName(XmlKeyword.CODE_ELEMENT.getName());

            // assumption of missing required code element
            boolean containsLang = false;

            // iterating through the code elements in the current file
            for (int i = 0; i < codeNodes.getLength(); i++) {
                Node codeNode = codeNodes.item(i);

                if (codeNode.getNodeType() == Node.ELEMENT_NODE
                        && ((Element) codeNode).getAttribute(XmlKeyword.LANGUAGE_ATTRIBUTE.getName()).equals(lang)) {
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
     Checks if all of the XML class files in the current test testUtils directory
     have the specified number of the code elements.
     */
    private boolean allFilesHaveCodeCount(int count)
            throws SAXException, IOException, ParserConfigurationException {
        File[] files = testUtils.getSubfolder().listFiles();

        // iterating through the files
        for (File file : files) {
            // parsing XML and searching for elements with source code
            Document document = testUtils.readDocumentFromFile(file);
            NodeList codeNodes = document.getElementsByTagName(XmlKeyword.CODE_ELEMENT.getName());

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
     saved as the text content of the corresponding XML element in the corresponding XML testUtils file.
     */
    private String readCodeFromFile(String clazz, String lang)
            throws ParserConfigurationException, SAXException, IOException {
        // creating a document and searching for the element containing the requested source code
        Document document = testUtils.readDocumentFromFile(testUtils.getFileFromClass(clazz));
        NodeList codeNodes = document.getElementsByTagName(XmlKeyword.CODE_ELEMENT.getName());

        // iterating through the code elements
        for (int i = 0; i < codeNodes.getLength(); i++) {
            Node codeNode = codeNodes.item(i);

            if (codeNode.getNodeType() == Node.ELEMENT_NODE) {
                Element codeElement = (Element) codeNode;

                // returning the escaped text content of the corresponding element
                if (codeElement.getAttribute(XmlKeyword.LANGUAGE_ATTRIBUTE.getName()).equals(lang)) {
                    return codeElement.getTextContent();
                }
            }
        }

        return null;
    }

}
