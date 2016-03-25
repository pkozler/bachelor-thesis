
import application.config.Config;
import application.core.ADataManagementException;
import application.core.xml.XmlKeyword;
import application.core.xml.XmlManager;
import java.io.File;
import java.io.IOException;
import java.util.Locale;
import java.util.ResourceBundle;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.xml.sax.SAXException;

/**
 * The {@code XmlManagerTestUtils} class contains fields and methods that are
 * used for preparing the test data for automatic testing of the
 * {@code XmlManager} class.
 *
 * @author Petr Kozler
 */
final class XmlManagerTestUtils {

    /**
     * positive test type
     */
    public static final String POSITIVE_TEST = "positive";
    /**
     * negative test type
     */
    public static final String NEGATIVE_TEST = "negative";
    /**
     * path to the root folder with temporary test data directories (relative to
     * the project root folder)
     */
    public static final String ROOT_TEST_TEMP_DATA_FOLDER = "temp-data";
    // exception message used if directory was not created
    private static final String NOT_CREATED_MESSAGE = "Failed to create a directory: ";
    // exception message used if directory was not deleted
    private static final String NOT_DELETED_MESSAGE = "Failed to delete a directory: ";
    // type of current test (positive or negative)
    private final String CURRENT_TEST_TYPE;
    // builder for reading XML files
    private final DocumentBuilder DOCUMENT_BUILDER;
    // transformer for writing XML files
    private final Transformer TRANSFORMER;
    // resource bundle for XML-specific strings
    private final ResourceBundle XML_BUNDLE
            = ResourceBundle.getBundle(Config.XML_STRINGS_BUNDLE, new Locale(Config.DEFAULT_LOCALE));
    // real path to the root folder for current test
    private String currentTestFolderPath;
    // real path to the current test main file
    private String testMainFilePath;
    // real path to the current test subfolder
    private String testSubfolderPath;

    /**
     * Initializes the reusable objects and sets the type of current test.
     *
     * @param testType string representing the type of current tests
     * @throws IOException
     * @throws ParserConfigurationException
     * @throws TransformerException
     */
    public XmlManagerTestUtils(String testType)
            throws IOException, ParserConfigurationException, TransformerException {
        this.CURRENT_TEST_TYPE = testType;
        // creating the builder for reading XML files
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DOCUMENT_BUILDER = dbf.newDocumentBuilder();
        // creating the TRANSFORMER for writing XML files
        TransformerFactory tf = TransformerFactory.newInstance();
        TRANSFORMER = tf.newTransformer();
    }

    /**
     * Prepares the temporary fake data directory for current test and performs
     * the XML manager initialization.
     *
     * @param xmlManager XML manager to initialize
     * @param testName name of the current test
     * @throws ADataManagementException
     * @throws IOException
     * @throws ParserConfigurationException
     * @throws TransformerException
     */
    public void initializeTestDirectory(XmlManager xmlManager, String testName)
            throws ADataManagementException, IOException, ParserConfigurationException, TransformerException {
        initializeTestDirectory(xmlManager, testName, true);
    }

    /**
     * Prepares the temporary fake data directory for current test and
     * optionally performs the XML manager initialization (setting the paths to
     * the data files).
     *
     * @param xmlManager XML manager
     * @param testName name of the current test (will be used in lowercase for
     * building the current test data subfolder path)
     * @throws ADataManagementException
     * @throws IOException
     * @throws ParserConfigurationException
     * @throws TransformerException
     */
    public void initializeTestDirectory(XmlManager xmlManager, String testName, boolean initializeXmlManager)
            throws ADataManagementException, IOException, ParserConfigurationException, TransformerException {
        // building the real path to the temporary test root data folder for current testing
        currentTestFolderPath = ROOT_TEST_TEMP_DATA_FOLDER + File.separator + testName.toLowerCase() + "-" + CURRENT_TEST_TYPE;
        // deleting temporary test root data folder from previous testing
        File file = new File(currentTestFolderPath);

        if (file.exists()) {
            deleteDirectoryRecursively(file);
        }

        testSubfolderPath = currentTestFolderPath + File.separator + Config.DATA_FILES_SUBFOLDER_NAME;
        testMainFilePath = currentTestFolderPath + File.separator + Config.MAIN_DATA_FILE_NAME;

        // creating the file folder for the current test
        createTestSubfolder(new File(testSubfolderPath));
        // creating the main file for the current test
        createTestMainFile(new File(testMainFilePath));

        if (initializeXmlManager) {
            initializeXmlManager(xmlManager);
        }
    }

    /**
     * Performs the XML manager initialization.
     *
     * @param xmlManager XML manager
     */
    public void initializeXmlManager(XmlManager xmlManager) throws ADataManagementException {
        xmlManager.initialize(
                testMainFilePath,
                testSubfolderPath,
                XML_BUNDLE);
    }

    /**
     * Returns the formatted message with specifed arguments.
     *
     * @param formatKey format string resource bundle key
     * @param args message arguments
     * @return formatted message
     */
    public String getFormattedMessage(String formatKey, Object... args) {
        return String.format(XML_BUNDLE.getString(formatKey), args);
    }

    /**
     * Returns the main XML file.
     *
     * @return main file
     */
    public File getMainFile() {
        return new File(testMainFilePath);
    }

    /**
     * Returns the XML subfolder.
     *
     * @return subfolder
     */
    public File getSubfolder() {
        return new File(testSubfolderPath);
    }

    /**
     * Returns the XML data file corresponding to the specified class name.
     *
     * @param className class name
     * @return class file
     */
    public File getFileFromClass(String className) {
        return new File(testSubfolderPath + File.separator + className.toLowerCase() + XmlManager.XML_FILE_EXTENSION);
    }

    /**
     * Parses a XML document from existing file.
     *
     * @param file XML file
     * @return parsed XML document
     * @throws SAXException SAX error
     * @throws IOException IO error
     */
    public Document readDocumentFromFile(File file)
            throws SAXException, IOException {
        DOCUMENT_BUILDER.reset();
        // creating a document
        Document document = DOCUMENT_BUILDER.parse(file);
        // normalizing a document
        document.getDocumentElement().normalize();
        // returning document
        return document;
    }

    /**
     * Saves the XML document to the specified file.
     *
     * @param className XML file
     * @param document XML document
     * @throws TransformerException TRANSFORMER error
     */
    public void writeDocumentToFile(File file, Document document)
            throws TransformerException {
        TRANSFORMER.reset();
        TRANSFORMER.setOutputProperty(OutputKeys.INDENT, "yes");
        // creating the stream for a file
        StreamResult result = new StreamResult(file);
        // creating a new DOM source
        DOMSource source = new DOMSource(document);
        // writing the DOM to the stream
        TRANSFORMER.transform(source, result);
    }

    /*
     Creates a new folder for test XML data files associated with current test.
     */
    private void createTestSubfolder(File subfolder)
            throws IOException {
        // creating the directory for current test
        if (!subfolder.mkdirs()) {
            throw new IOException(NOT_CREATED_MESSAGE + subfolder.getAbsolutePath());
        }
    }

    /*
     Creates a new main test XML data file associated with current test.
     */
    private void createTestMainFile(File mainFile)
            throws ParserConfigurationException, TransformerException, IOException {
        mainFile.createNewFile();

        // creating basic document elements
        Document document = DOCUMENT_BUILDER.newDocument();
        Element root = document.createElement(XmlKeyword.LIST_ROOT_ELEMENT.getName());
        Element langList = document.createElement(XmlKeyword.LANGUAGE_LIST_ELEMENT.getName());
        Element classList = document.createElement(XmlKeyword.CLASS_LIST_ELEMENT.getName());
        root.appendChild(langList);
        root.appendChild(classList);
        document.appendChild(root);
        document.normalize();

        // creating the main file
        writeDocumentToFile(mainFile, document);
    }

    /*
     Performs the recursive deleting operation upon the existing temporary directory.
     */
    private void deleteDirectoryRecursively(File file) throws IOException {
        if (file.isDirectory()) {
            File[] files = file.listFiles();

            for (File f : files) {
                deleteDirectoryRecursively(f);
            }
        }

        file.delete();
    }

}
