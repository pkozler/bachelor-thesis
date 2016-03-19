
import application.config.Config;
import application.core.ADataManagementException;
import application.core.xml.XmlKeyword;
import application.core.xml.XmlManager;
import java.io.File;
import java.io.IOException;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.TransformerException;
import org.junit.Before;
import org.junit.Test;
import org.junit.Rule;
import org.junit.rules.ExpectedException;
import org.junit.rules.TestName;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

/**
 * The {@code XmlManagerTestNegative} class performs automatic unit testing of
 * the {@code XmlManager} class with wrong inputs.
 *
 * @author Petr Kozler
 */
public class XmlManagerTestNegative {

    /**
     * rule for accessing the test method names
     */
    @Rule
    public TestName testName = new TestName();

    /**
     * rule for specification of expected exception
     */
    @Rule
    public ExpectedException expectedException = ExpectedException.none();

    // tested XML manager
    private XmlManager xmlManager;
    // data for tested XML manager
    private XmlManagerTestUtils testUtils;

    /**
     * Creates a clean test test data directory structure and creates the XML
     * manager before each test is run.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws org.xml.sax.SAXException SAX error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws java.io.IOException IO error
     */
    @Before
    public void setUp()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        xmlManager = new XmlManager();
        testUtils = new XmlManagerTestUtils(XmlManagerTestUtils.NEGATIVE_TEST);
    }

    /**
     * Tests the initialize method without the main file.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void initializeTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        // initializing test directory
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName(), false);

        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("notAMainFile",
                Config.MAIN_DATA_FILE_NAME));

        // deleting the main file
        testUtils.getMainFile().delete();

        // setting paths to XML manager
        testUtils.initializeXmlManager(xmlManager);
    }

    /**
     * Tests the initialize method without the data subfolder.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void initializeTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        // initializing test directory
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName(), false);

        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("notADirectory",
                Config.DATA_FILES_SUBFOLDER_NAME));

        // deleting the data folder
        testUtils.getSubfolder().delete();

        // setting paths to XML manager
        testUtils.initializeXmlManager(xmlManager);
    }

    /**
     * Tests the loadClassList method with duplicate class list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void loadClassListTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("duplicateElements",
                XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        addListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.loadClassList();
    }

    /**
     * Tests the loadClassList method with no class list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void loadClassListTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementNotFound",
                XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        removeListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.loadClassList();
    }

    /**
     * Tests the loadLanguageList method with duplicate language list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void loadLanguageListTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("duplicateElements",
                XmlKeyword.LANGUAGE_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        addListElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
        xmlManager.loadLanguageList();
    }

    /**
     * Tests the loadLanguageList method with no language list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void loadLanguageListTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementNotFound",
                XmlKeyword.LANGUAGE_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        removeListElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
        xmlManager.loadLanguageList();
    }

    /**
     * Tests the addClass method with duplicate class list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addClassTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("duplicateElements",
                XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        addListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.addClass(classA);
    }

    /**
     * Tests the addClass method with no class list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addClassTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementNotFound",
                XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        removeListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.addClass(classA);
    }

    /**
     * Tests the addClass method with already existing class file for the new class.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addClassTest3()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName(), false);
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("fileExists",
                testUtils.getFileFromClass(classA).getName()));
        testUtils.initializeXmlManager(xmlManager);

        testUtils.getFileFromClass(classA).createNewFile();
        xmlManager.addClass(classA);
    }

    /**
     * Tests the addClass method with already existing item in the main file for the new class.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addClassTest4()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithValueExists",
                XmlKeyword.CLASS_ELEMENT.getName(), classA));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        addItemElement(XmlKeyword.CLASS_LIST_ELEMENT.getName(), XmlKeyword.CLASS_ELEMENT.getName(), classA);
        xmlManager.addClass(classA);
    }

    /**
     * Tests the editClass method with duplicate class list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editClassTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String classB = "Scanner";
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName(), false);
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("duplicateElements",
                XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initializeXmlManager(xmlManager);
        xmlManager.addClass(classA);

        addListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.editClass(classA, classB);
    }

    /**
     * Tests the editClass method with no class list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editClassTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String classB = "Scanner";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementNotFound",
                XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);

        removeListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.editClass(classA, classB);
    }

    /**
     * Tests the editClass method with missing class file for the old class.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editClassTest3()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String classB = "Scanner";
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName(), false);
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("notAFile",
                testUtils.getFileFromClass(classA).getName()));
        testUtils.initializeXmlManager(xmlManager);
        xmlManager.addClass(classA);

        testUtils.getFileFromClass(classA).delete();
        xmlManager.editClass(classA, classB);
    }

    /**
     * Tests the editClass method with already existing class file for the new class.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editClassTest4()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String classB = "Scanner";
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName(), false);
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("fileExists",
                testUtils.getFileFromClass(classB).getName()));
        testUtils.initializeXmlManager(xmlManager);
        xmlManager.addClass(classA);

        testUtils.getFileFromClass(classB).createNewFile();
        xmlManager.editClass(classA, classB);
    }

    /**
     * Tests the editClass method with missing item in the main file for the old class.
     * 
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editClassTest5()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String classB = "Scanner";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithValueNotFound",
                XmlKeyword.CLASS_ELEMENT.getName(), classA));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);

        removeItemElement(XmlKeyword.CLASS_LIST_ELEMENT.getName(), XmlKeyword.CLASS_ELEMENT.getName(), classA);
        xmlManager.editClass(classA, classB);
    }

    /**
     * Tests the editClass method with already existing item in the main file for the new class.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editClassTest6()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String classB = "Scanner";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithValueExists",
                XmlKeyword.CLASS_ELEMENT.getName(), classB));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);

        addItemElement(XmlKeyword.CLASS_LIST_ELEMENT.getName(), XmlKeyword.CLASS_ELEMENT.getName(), classB);
        xmlManager.editClass(classA, classB);
    }

    /**
     * Tests the removeClass method with duplicate class list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeClassTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("duplicateElements",
                XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);

        addListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.removeClass(classA);
    }

    /**
     * Tests the removeClass method with no class list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeClassTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementNotFound",
                XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);

        removeListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.removeClass(classA);
    }

    /**
     * Tests the removeClass method with missing class file for the old class.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeClassTest3()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName(), false);
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("notAFile",
                testUtils.getFileFromClass(classA).getName()));
        testUtils.initializeXmlManager(xmlManager);
        xmlManager.addClass(classA);

        testUtils.getFileFromClass(classA).delete();
        xmlManager.removeClass(classA);
    }

    /**
     * Tests the removeClass method with missing item in the main file for the old class.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeClassTest4()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithValueNotFound",
                XmlKeyword.CLASS_ELEMENT.getName(), classA));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);

        removeItemElement(XmlKeyword.CLASS_LIST_ELEMENT.getName(), XmlKeyword.CLASS_ELEMENT.getName(), classA);
        xmlManager.removeClass(classA);
    }

    /**
     * Tests the addLanguage method with duplicate language list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addLanguageTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("duplicateElements",
                XmlKeyword.LANGUAGE_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        addListElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
        xmlManager.addLanguage(langA);
    }

    /**
     * Tests the addLanguage method with no language list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addLanguageTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementNotFound",
                XmlKeyword.LANGUAGE_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        removeListElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
        xmlManager.addLanguage(langA);
    }

    /**
     * Tests the addLanguage method with already existing code in a class file for the new language.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addLanguageTest3()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithAttributeExists",
                XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);
        xmlManager.addLanguage(langA);

        addCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA);
        xmlManager.addLanguage(langA);
    }

    /**
     * Tests the addLanguage method with already existing item in the main file for the new language.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void addLanguageTest4()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithValueExists",
                XmlKeyword.LANGUAGE_ELEMENT.getName(), langA));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        addItemElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName(), XmlKeyword.LANGUAGE_ELEMENT.getName(), langA);
        xmlManager.addLanguage(langA);
    }

    /**
     * Tests the editLanguage method with duplicate language list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editLanguageTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("duplicateElements",
                XmlKeyword.LANGUAGE_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addLanguage(langA);

        addListElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
        xmlManager.editLanguage(langA, langB);
    }

    /**
     * Tests the editLanguage method with no language list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editLanguageTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementNotFound",
                XmlKeyword.LANGUAGE_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addLanguage(langA);

        removeListElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
        xmlManager.editLanguage(langA, langB);
    }

    /**
     * Tests the editLanguage method with missing code in a class file for the old language.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editLanguageTest3()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithAttributeNotFound",
                XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);
        xmlManager.addLanguage(langA);

        removeCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA);
        xmlManager.editLanguage(langA, langB);
    }

    /**
     * Tests the editLanguage method with already existing code in a class file for the new language.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editLanguageTest4()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithAttributeExists",
                XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langB));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);
        xmlManager.addLanguage(langA);

        addCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langB);
        xmlManager.editLanguage(langA, langB);
    }

    /**
     * Tests the editLanguage method with missing item in the main file for the old language.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editLanguageTest5()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithValueNotFound",
                XmlKeyword.LANGUAGE_ELEMENT.getName(), langA));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        removeItemElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName(), XmlKeyword.LANGUAGE_ELEMENT.getName(), langA);
        xmlManager.editLanguage(langA, langB);
    }

    /**
     * Tests the editLanguage method with already existing item in the main file for the new language.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void editLanguageTest6()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithValueExists",
                XmlKeyword.LANGUAGE_ELEMENT.getName(), langB));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addLanguage(langA);

        addItemElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName(), XmlKeyword.LANGUAGE_ELEMENT.getName(), langB);
        xmlManager.editLanguage(langA, langB);
    }

    /**
     * Tests the removeLanguage method with duplicate language list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeLanguageTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("duplicateElements",
                XmlKeyword.LANGUAGE_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        addListElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
        xmlManager.removeLanguage(langA);
    }

    /**
     * Tests the removeLanguage method with no language list element.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeLanguageTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementNotFound",
                XmlKeyword.LANGUAGE_LIST_ELEMENT.getName()));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        removeListElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
        xmlManager.removeLanguage(langA);
    }

    /**
     * Tests the removeLanguage method with missing code in a class file for the old language.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeLanguageTest3()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithAttributeNotFound",
                XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);

        removeCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA);
        xmlManager.removeLanguage(langA);
    }

    /**
     * Tests the removeLanguage method with missing item in the main file for the old language.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void removeLanguageTest4()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithValueNotFound",
                XmlKeyword.LANGUAGE_ELEMENT.getName(), langA));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());

        removeItemElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName(), XmlKeyword.LANGUAGE_ELEMENT.getName(), langA);
        xmlManager.removeLanguage(langA);
    }

    /**
     * Tests the saveCode method with missing the code element for the specified language.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void saveCodeTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";
        String codeA = "WriteLn('Hello world!');";

        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithAttributeNotFound",
                XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);
        xmlManager.addLanguage(langA);

        removeCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA);
        xmlManager.saveCode(classA, langA, codeA);
    }

    /**
     * Tests the loadCode method with missing the code element for the specified language.
     *
     * @throws application.core.ADataManagementException an error
     * @throws javax.xml.parsers.ParserConfigurationException parser error
     * @throws javax.xml.transform.TransformerException transformer error
     * @throws org.xml.sax.SAXException SAX error
     * @throws java.io.IOException IO error
     */
    @Test
    public void loadCodeTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";

        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("elementWithAttributeNotFound",
                XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA));
        testUtils.initializeTestDirectory(xmlManager, testName.getMethodName());
        xmlManager.addClass(classA);
        xmlManager.addLanguage(langA);

        removeCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA);
        xmlManager.loadCode(classA, langA);
    }

    /*
     Adds a duplicate element representing the list (of classes or languages)
     in the main XML file.
     */
    private void addListElement(String elementName)
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        // creating a document from the main file
        Document document = testUtils.readDocumentFromFile(testUtils.getMainFile());
        Element root = document.getDocumentElement();
        // adding a list element
        Element newList = document.createElement(elementName);
        root.appendChild(newList);
        // writing changes
        testUtils.writeDocumentToFile(testUtils.getMainFile(), document);
    }

    /*
     Removes the mandatory element representing the list (of classes or languages)
     from the main XML file.
     */
    private void removeListElement(String elementName)
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        // creating a document from the main file
        Document document = testUtils.readDocumentFromFile(testUtils.getMainFile());
        Element root = document.getDocumentElement();
        // removing a list element
        Element oldList = (Element) document.getElementsByTagName(elementName).item(0);
        root.removeChild(oldList);
        // writing changes
        testUtils.writeDocumentToFile(testUtils.getMainFile(), document);
    }

    /*
     Adds a specified list item (class or language) to the main XMl file without creating
     the corresponding source code file.
     */
    private void addItemElement(String parentElementName, String elementName, String elementValue)
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        // creating a document from the main file
        Document document = testUtils.readDocumentFromFile(testUtils.getMainFile());
        Element list = (Element) document.getElementsByTagName(parentElementName).item(0);
        // adding an item element
        Element newItem = document.createElement(elementName);
        newItem.setTextContent(elementValue);
        list.appendChild(newItem);
        // writing changes
        testUtils.writeDocumentToFile(testUtils.getMainFile(), document);
    }

    /*
     Removes a specified list item (class or language) from the main XMl file without deleting
     the corresponding source code file.
     */
    private void removeItemElement(String parentElementName, String elementName, String elementValue)
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        // creating a document from the main file
        Document document = testUtils.readDocumentFromFile(testUtils.getMainFile());
        Element list = (Element) document.getElementsByTagName(parentElementName).item(0);
        // getting all item elements
        NodeList nodeList = list.getElementsByTagName(elementName);

        // searching for an item element
        for (int i = 0; i < nodeList.getLength(); i++) {
            Element oldItem = (Element) nodeList.item(i);

            // removing the element
            if (oldItem.getTextContent().equals(elementValue)) {
                list.removeChild(oldItem);
                break;
            }
        }

        // writing changes
        testUtils.writeDocumentToFile(testUtils.getMainFile(), document);
    }

    /*
     Adds a specified source code element to the specified class source codes file without adding
     the corresponding languages list item to the main XMl file.
     */
    private void addCodeElement(String className, String elementName, String elementAttributeName, String elementAttributeValue)
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        // creating a document from the specified source code file
        File file = testUtils.getFileFromClass(className);
        Document document = testUtils.readDocumentFromFile(file);
        Element root = document.getDocumentElement();
        Element newItem = document.createElement(elementName);
        newItem.setAttribute(elementAttributeName, elementAttributeValue);
        root.appendChild(newItem);
        // writing changes
        testUtils.writeDocumentToFile(file, document);
    }

    /*
     Removes a specified source code element from the specified class source codes file without removing
     the corresponding languages list item from the main XMl file.
     */
    private void removeCodeElement(String className, String elementName, String elementAttributeName, String elementAttributeValue)
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        // creating a document from the specified source code file
        File file = testUtils.getFileFromClass(className);
        Document document = testUtils.readDocumentFromFile(file);
        Element root = document.getDocumentElement();
        NodeList nodeList = root.getElementsByTagName(elementName);

        for (int i = 0; i < nodeList.getLength(); i++) {
            Element oldItem = (Element) nodeList.item(i);

            if (elementAttributeValue.equals(oldItem.getAttribute(elementAttributeName))) {
                root.removeChild(oldItem);
                break;
            }
        }

        // writing changes
        testUtils.writeDocumentToFile(file, document);
    }

}
