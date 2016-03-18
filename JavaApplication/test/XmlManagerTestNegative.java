
import application.core.ADataManagementException;
import application.core.xml.XmlKeyword;
import application.core.xml.XmlManager;
import java.io.File;
import java.io.IOException;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import org.junit.Before;
import org.junit.Test;
import org.junit.Rule;
import org.junit.rules.ExpectedException;
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

    // tested XML manager
    private XmlManager xmlManager;
    // data for tested XML manager
    private XmlManagerTestUtils testUtils;

    @Rule
    public ExpectedException expectedException = ExpectedException.none();

    /**
     * Creates a clean test test data directory structure and creates the XML
     * manager before each test is run.
     *
     * @throws ParserConfigurationException parser error
     * @throws TransformerException transformer error
     * @throws IOException IO error
     */
    @Before
    public void setUp()
            throws IOException, ParserConfigurationException, TransformerException {
        xmlManager = new XmlManager();
        testUtils = new XmlManagerTestUtils();
    }

    /**
     * Tests the setPaths method.
     *
     * @throws application.core.ADataManagementException an error
     * @throws java.io.IOException IO error
     */
    @Test
    public void setPathsTest()
            throws ADataManagementException, IOException {
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("notAMainFile", testUtils.getMainDataFile().getName()));

        testUtils.getMainDataFile().delete();
        testUtils.initXmlManager(xmlManager);
    }

    /**
     * Tests the setPaths method.
     *
     * @throws application.core.ADataManagementException an error
     * @throws java.io.IOException IO error
     */
    @Test
    public void setPathsTest2()
            throws ADataManagementException, IOException {
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("notADirectory", testUtils.getDataFilesFolder().getName()));

        testUtils.getDataFilesFolder().delete();
        testUtils.initXmlManager(xmlManager);
    }

    @Test
    public void loadClassListTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "duplicateElements", XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);

        addListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.loadClassList();
        // getClassList - duplicateElements
    }

    @Test
    public void loadClassListTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementNotFound", XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);

        removeListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.loadClassList();
        // getClassList - elementNotFound
    }

    @Test
    public void loadLangListTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "duplicateElements", XmlKeyword.LANGUAG_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);

        addListElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName());
        xmlManager.loadLangList();
        // getLangList - duplicateElements
    }

    @Test
    public void loadLangListTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementNotFound", XmlKeyword.LANGUAG_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);

        removeListElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName());
        xmlManager.loadLangList();
        // getLangList - elementNotFound
    }

    @Test
    public void addClassTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "duplicateElements", XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);

        addListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.addClass(classA);
        // getClassList - duplicateElements
    }

    @Test
    public void addClassTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementNotFound", XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);

        removeListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.addClass(classA);
        // getClassList - elementNotFound
    }

    @Test
    public void addClassTest3()
            throws ADataManagementException, IOException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("fileExists", testUtils.getFileFromClass(classA).getName()));
        testUtils.initXmlManager(xmlManager);

        createClassFile(classA);
        xmlManager.addClass(classA);
        // createDocument - fileExists
    }

    @Test
    public void addClassTest4()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithValueExists", XmlKeyword.CLASS_ELEMENT.getName(), classA));
        testUtils.initXmlManager(xmlManager);

        addItemElement(XmlKeyword.CLASS_LIST_ELEMENT.getName(), XmlKeyword.CLASS_ELEMENT.getName(), classA);
        xmlManager.addClass(classA);
        // addClassItem - elementWithValueExists
    }

    @Test
    public void editClassTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String classB = "Scanner";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "duplicateElements", XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);

        addListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.editClass(classA, classB);
        // getClassList - duplicateElements
    }

    @Test
    public void editClassTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String classB = "Scanner";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementNotFound", XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);

        removeListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.editClass(classA, classB);
        // getClassList - elementNotFound
    }

    @Test
    public void editClassTest3()
            throws ADataManagementException {
        String classA = "System";
        String classB = "Scanner";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("notAFile", testUtils.getFileFromClass(classA).getName()));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addClass(classA);

        deleteClassFile(classA);
        xmlManager.editClass(classA, classB);
        // renameDocument - notAFile
    }

    @Test
    public void editClassTest4()
            throws ADataManagementException, IOException {
        String classA = "System";
        String classB = "Scanner";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("fileExists", testUtils.getFileFromClass(classB).getName()));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addClass(classA);

        createClassFile(classB);
        xmlManager.editClass(classA, classB);
        // renameDocument - fileExists
    }

    @Test
    public void editClassTest5()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String classB = "Scanner";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithValueNotFound", XmlKeyword.CLASS_ELEMENT.getName(), classA));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addClass(classA);

        removeItemElement(XmlKeyword.CLASS_LIST_ELEMENT.getName(), XmlKeyword.CLASS_ELEMENT.getName(), classA);
        xmlManager.editClass(classA, classB);
        // editClassItem - elementWithValueNotFound
    }

    @Test
    public void editClassTest6()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String classB = "Scanner";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithValueExists", XmlKeyword.CLASS_ELEMENT.getName(), classB));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addClass(classA);

        addItemElement(XmlKeyword.CLASS_LIST_ELEMENT.getName(), XmlKeyword.CLASS_ELEMENT.getName(), classB);
        xmlManager.editClass(classA, classB);
        // editClassItem - elementWithValueExists
    }

    @Test
    public void removeClassTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "duplicateElements", XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addClass(classA);

        addListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.removeClass(classA);
        // getClassList - duplicateElements
    }

    @Test
    public void removeClassTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementNotFound", XmlKeyword.CLASS_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addClass(classA);

        removeListElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        xmlManager.removeClass(classA);
        // getClassList - elementNotFound
    }

    @Test
    public void removeClassTest3()
            throws ADataManagementException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage("notAFile", testUtils.getFileFromClass(classA).getName()));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addClass(classA);

        deleteClassFile(classA);
        xmlManager.removeClass(classA);
        // deleteDocument - notAFile
    }

    @Test
    public void removeClassTest4()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithValueNotFound", XmlKeyword.CLASS_ELEMENT.getName(), classA));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addClass(classA);

        removeItemElement(XmlKeyword.CLASS_LIST_ELEMENT.getName(), XmlKeyword.CLASS_ELEMENT.getName(), classA);
        xmlManager.removeClass(classA);
        // removeClassItem - elementWithValueNotFound
    }

    @Test
    public void addLangTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "duplicateElements", XmlKeyword.LANGUAG_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);

        addListElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName());
        xmlManager.addLang(langA);
        // getClassList - duplicateElements
    }

    @Test
    public void addLangTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementNotFound", XmlKeyword.LANGUAG_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);

        removeListElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName());
        xmlManager.addLang(langA);
        // getClassList - elementNotFound
    }

    @Test
    public void addLangTest3()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithAttributeExists", XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE, langA));
        testUtils.initXmlManager(xmlManager);

        addCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA);
        xmlManager.addLang(langA);
        // addCodeItem - elementWithAttributeExists
    }

    @Test
    public void addLangTest4()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithValueExists", XmlKeyword.LANGUAGE_ELEMENT.getName(), langA));
        testUtils.initXmlManager(xmlManager);

        addItemElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName(), XmlKeyword.LANGUAGE_ELEMENT.getName(), langA);
        xmlManager.addLang(langA);
        // addLangItem - elementWithValueExists
    }

    @Test
    public void editLangTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "duplicateElements", XmlKeyword.LANGUAG_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addLang(langA);

        addListElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName());
        xmlManager.editLang(langA, langB);
        // getClassList - duplicateElements
    }

    @Test
    public void editLangTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementNotFound", XmlKeyword.LANGUAG_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addLang(langA);

        removeListElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName());
        xmlManager.editLang(langA, langB);
        // getClassList - elementNotFound
    }

    @Test
    public void editLangTest3()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithAttributeExists", XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE, langA));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addLang(langA);

        removeCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA);
        xmlManager.editLang(langA, langB);
        // editCodeItem - elementWithAttributeNotFound
    }

    @Test
    public void editLangTest4()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithAttributeExists", XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE, langB));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addClass(classA);
        xmlManager.addLang(langA);

        addCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langB);
        xmlManager.editLang(langA, langB);
        // editCodeItem - elementWithAttributeExists
    }

    @Test
    public void editLangTest5()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithValueNotFound", XmlKeyword.LANGUAGE_ELEMENT.getName(), langA));
        testUtils.initXmlManager(xmlManager);

        removeItemElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName(), XmlKeyword.LANGUAGE_ELEMENT.getName(), langA);
        xmlManager.editLang(langA, langB);
        // editLangItem - elementWithValueNotFound
    }

    @Test
    public void editLangTest6()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        String langB = "C#";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithValueExists", XmlKeyword.LANGUAGE_ELEMENT.getName(), langA));
        testUtils.initXmlManager(xmlManager);

        addItemElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName(), XmlKeyword.LANGUAGE_ELEMENT.getName(), langA);
        xmlManager.editLang(langA, langB);
        // editLangItem - elementWithValueExists
    }

    @Test
    public void removeLangTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "duplicateElements", XmlKeyword.LANGUAG_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);

        addListElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName());
        xmlManager.removeLang(langA);
        // getClassList - duplicateElements
    }

    @Test
    public void removeLangTest2()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementNotFound", XmlKeyword.LANGUAG_LIST_ELEMENT.getName()));
        testUtils.initXmlManager(xmlManager);
        removeListElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName());
        xmlManager.removeLang(langA);
        // getClassList - elementNotFound
    }

    @Test
    public void removeLangTest3()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithAttributeNotFound", XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE, langA));
        testUtils.initXmlManager(xmlManager);

        removeCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA);
        xmlManager.removeLang(langA);
        // removeCodeItem - elementWithAttributeNotFound
    }

    @Test
    public void removeLangTest4()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String langA = "Pascal";
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithValueNotFound", XmlKeyword.LANGUAGE_ELEMENT.getName(), langA));
        testUtils.initXmlManager(xmlManager);

        removeItemElement(XmlKeyword.LANGUAG_LIST_ELEMENT.getName(), XmlKeyword.LANGUAGE_ELEMENT.getName(), langA);
        xmlManager.removeLang(langA);
        // removeLangItem - elementWithValueNotFound
    }

    @Test
    public void saveCodeTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";
        String codeA = "print(\"Hello world!\");";

        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithAttributeNotFound", XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE, langA));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addClass(classA);
        xmlManager.addLang(langA);

        removeCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA);
        xmlManager.saveCode(classA, langA, codeA);
        // saveCode - elementWithAttributeNotFound
    }

    @Test
    public void loadCodeTest()
            throws ADataManagementException, ParserConfigurationException, SAXException, IOException, TransformerException {
        String classA = "System";
        String langA = "Pascal";

        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testUtils.getFormattedMessage(
                "elementWithAttributeNotFound", XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE, langA));
        testUtils.initXmlManager(xmlManager);
        xmlManager.addClass(classA);
        xmlManager.addLang(langA);

        removeCodeElement(classA, XmlKeyword.CODE_ELEMENT.getName(), XmlKeyword.LANGUAGE_ATTRIBUTE.getName(), langA);
        xmlManager.loadCode(classA, langA);
        // loadCode - elementWithAttributeNotFound
    }

    /*
     Creates a file representing the source codes for a class with the specified name
     without adding the corresponding classes list item to the main XMl file.
     */
    private void createClassFile(String className)
            throws IOException {
        File classFile = testUtils.getFileFromClass(className);
        classFile.createNewFile();
    }

    /*
     Deletes a file representing the source codes for a class with the specified name
     without removing the corresponding classes list item from the main XMl file.
     */
    private void deleteClassFile(String className) {
        File classFile = testUtils.getFileFromClass(className);
        classFile.delete();
    }

    /*
     Adds a duplicate element representing the list (of classes or languages)
     in the main XML file.
     */
    private void addListElement(String elementName)
            throws ParserConfigurationException, SAXException, IOException, TransformerConfigurationException, TransformerException {
        Document document = testUtils.readDocumentFromFile(testUtils.getMainDataFile());
        Element root = document.getDocumentElement();
        Element newList = document.createElement(elementName);
        root.appendChild(newList);
        testUtils.writeDocumentToFile(testUtils.getMainDataFile(), document);
    }

    /*
     Removes the mandatory element representing the list (of classes or languages)
     from the main XML file.
     */
    private void removeListElement(String elementName)
            throws ParserConfigurationException, SAXException, IOException, TransformerConfigurationException, TransformerException {
        Document document = testUtils.readDocumentFromFile(testUtils.getMainDataFile());
        Element root = document.getDocumentElement();
        Element oldList = (Element) document.getElementsByTagName(elementName).item(0);
        root.removeChild(oldList);
        testUtils.writeDocumentToFile(testUtils.getMainDataFile(), document);
    }

    /*
     Adds a specified list item (class or language) to the main XMl file without creating
     the corresponding source code file.
     */
    private void addItemElement(String parentElementName, String elementName, String elementValue)
            throws ParserConfigurationException, SAXException, IOException, TransformerConfigurationException, TransformerException {
        Document document = testUtils.readDocumentFromFile(testUtils.getMainDataFile());
        Element list = (Element) document.getElementsByTagName(parentElementName).item(0);
        Element newItem = document.createElement(elementName);
        newItem.setTextContent(elementValue);
        list.appendChild(newItem);
        testUtils.writeDocumentToFile(testUtils.getMainDataFile(), document);
    }

    /*
     Removes a specified list item (class or language) from the main XMl file without deleting
     the corresponding source code file.
     */
    private void removeItemElement(String parentElementName, String elementName, String elementValue)
            throws ParserConfigurationException, SAXException, IOException, TransformerConfigurationException, TransformerException {
        Document document = testUtils.readDocumentFromFile(testUtils.getMainDataFile());
        Element list = (Element) document.getElementsByTagName(parentElementName).item(0);
        NodeList nodeList = list.getElementsByTagName(elementName);

        for (int i = 0; i < nodeList.getLength(); i++) {
            Element oldItem = (Element) nodeList.item(i);

            if (oldItem.getTextContent().equals(elementValue)) {
                list.removeChild(oldItem);
                break;
            }
        }

        testUtils.writeDocumentToFile(testUtils.getMainDataFile(), document);
    }

    /*
     Adds a specified source code element to the specified class source codes file without adding
     the corresponding languages list item to the main XMl file.
     */
    private void addCodeElement(String className, String elementName, String elementAttributeName, String elementAttributeValue)
            throws ParserConfigurationException, SAXException, IOException, TransformerConfigurationException, TransformerException {
        Document document = testUtils.readDocumentFromFile(testUtils.getFileFromClass(className));
        Element root = document.getDocumentElement();
        Element newItem = document.createElement(elementName);
        newItem.setAttribute(elementAttributeName, elementAttributeValue);
        root.appendChild(newItem);
        testUtils.writeDocumentToFile(testUtils.getMainDataFile(), document);
    }

    /*
     Removes a specified source code element from the specified class source codes file without removing
     the corresponding languages list item from the main XMl file.
     */
    private void removeCodeElement(String className, String elementName, String elementAttributeName, String elementAttributeValue)
            throws ParserConfigurationException, SAXException, IOException, TransformerConfigurationException, TransformerException {
        Document document = testUtils.readDocumentFromFile(testUtils.getFileFromClass(className));
        Element root = document.getDocumentElement();
        NodeList nodeList = root.getElementsByTagName(elementName);

        for (int i = 0; i < nodeList.getLength(); i++) {
            Element oldItem = (Element) nodeList.item(i);

            if (elementAttributeValue.equals(oldItem.getAttribute(elementAttributeName))) {
                root.removeChild(oldItem);
                break;
            }
        }

        testUtils.writeDocumentToFile(testUtils.getMainDataFile(), document);
    }

}
