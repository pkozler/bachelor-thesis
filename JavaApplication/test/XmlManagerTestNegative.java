
import application.core.ADataManagementException;
import application.core.xml.XmlManager;
import java.io.IOException;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.TransformerException;
import org.junit.Before;
import org.junit.Test;
import org.junit.Rule;
import org.junit.rules.ExpectedException;

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
    private XmlManagerTestData testData;

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
    public void setUp() throws IOException, ParserConfigurationException, TransformerException {
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
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testData.getFormattedMessage(
                "notAMainFile", testData.getMainDataFile().getName()));
        testData.getMainDataFile().delete();
        testData.initXmlManager(xmlManager);
    }

    /**
     * Tests the setPaths method.
     *
     * @throws application.core.ADataManagementException an error
     * @throws java.io.IOException IO error
     */
    @Test
    public void setPathsTest2() throws ADataManagementException, IOException {
        expectedException.expect(ADataManagementException.class);
        expectedException.expectMessage(testData.getFormattedMessage(
                "notADirectory", testData.getDataFilesFolder().getName()));
        testData.getDataFilesFolder().delete();
        testData.initXmlManager(xmlManager);
    }
    
    @Test
    public void loadClassListTest() {
        // getClassList - duplicateElements
    }

    @Test
    public void loadClassListTest2() {
        // getClassList - elementNotFound
    }

    @Test
    public void loadLangListTest() {
        // getLangList - duplicateElements
    }

    @Test
    public void loadLangListTest2() {
        // getLangList - elementNotFound
    }
    
    @Test
    public void addClassTest() {
        // getClassList - duplicateElements
    }

    @Test
    public void addClassTest2() {
        // getClassList - elementNotFound
    }

    @Test
    public void addClassTest3() {
        // createDocument - fileExists
    }

    @Test
    public void addClassTest4() {
        // addClassItem - elementWithValueExists
    }
    
    @Test
    public void editClassTest() {
        // getClassList - duplicateElements
    }

    @Test
    public void editClassTest2() {
        // getClassList - elementNotFound
    }

    @Test
    public void editClassTest3() {
        // renameDocument - notAFile
    }

    @Test
    public void editClassTest4() {
        // renameDocument - fileExists
    }

    @Test
    public void editClassTest5() {
        // editClassItem - elementWithValueNotFound
    }

    @Test
    public void editClassTest6() {
        // editClassItem - elementWithValueExists
    }

    @Test
    public void removeClassTest() {
        // getClassList - duplicateElements
    }

    @Test
    public void removeClassTest2() {
        // getClassList - elementNotFound
    }

    @Test
    public void removeClassTest3() {
        // deleteDocument - notAFile
    }

    @Test
    public void removeClassTest4() {
        // removeClassItem - elementWithValueNotFound
    }

    @Test
    public void addLangTest() {
        // getClassList - duplicateElements
    }

    @Test
    public void addLangTest2() {
        // getClassList - elementNotFound
    }

    @Test
    public void addLangTest3() {
        // openDocument - notAFile
    }

    @Test
    public void addLangTest4() {
        // addCodeItem - elementWithAttributeExists
    }

    @Test
    public void addLangTest5() {
        // addLangItem - elementWithValueExists
    }

    @Test
    public void editLangTest() {
        // getClassList - duplicateElements
    }

    @Test
    public void editLangTest2() {
        // getClassList - elementNotFound
    }

    @Test
    public void editLangTest3() {
        // openDocument - notAFile
    }

    @Test
    public void editLangTest4() {
        // editCodeItem - elementWithAttributeNotFound
    }

    @Test
    public void editLangTest5() {
        // editCodeItem - elementWithAttributeExists
    }

    @Test
    public void editLangTest6() {
        // editLangItem - elementWithValueNotFound
    }

    @Test
    public void editLangTest7() {
        // editLangItem - elementWithValueExists
    }

    @Test
    public void removeLangTest() {
        // getClassList - duplicateElements
    }

    @Test
    public void removeLangTest2() {
        // getClassList - elementNotFound
    }

    @Test
    public void removeLangTest3() {
        // openDocument - notAFile
    }

    @Test
    public void removeLangTest4() {
        // removeCodeItem - elementWithAttributeNotFound
    }

    @Test
    public void removeLangTest5() {
        // removeLangItem - elementWithValueNotFound
    }

    @Test
    public void saveCodeTest() {
        // openDocument - notAFile
    }

    @Test
    public void saveCodeTest2() {
        // saveCode - elementWithAttributeNotFound
    }

    @Test
    public void loadCodeTest() {
        // openDocument - notAFile
    }

    @Test
    public void loadCodeTest2() {
        // loadCode - elementWithAttributeNotFound
    }

    private void createFile() {
        
    }
    
    private void deleteFile() {
        
    }
    
    private void createElement() {
        
    }
    
    private void deleteElement() {
        
    }
    
    private void createElementWithValue() {
        
    }
    
    private void deleteElementWithValue() {
        
    }
    
    private void createElementWithAttribute() {
        
    }
    
    private void deleteElementWithAttribute() {
        
    }
    
}
