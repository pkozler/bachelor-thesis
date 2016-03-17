
import application.config.Config;
import application.core.ADataManagementException;
import application.core.xml.XmlManager;
import java.io.File;
import java.io.IOException;
import java.util.Locale;
import java.util.ResourceBundle;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 * The {@code XmlManagerTestData} class contains fields and methods that are
 * used for preparing the test data for automatic testing of the
 * {@code XmlManager} class.
 *
 * @author Petr Kozler
 */
final class XmlManagerTestData {

    // resource bundle for XML-specific strings
    private static final ResourceBundle XML_BUNDLE = ResourceBundle.getBundle(Config.XML_STRINGS_BUNDLE, new Locale(Config.DEFAULT_LOCALE));
    // path to the folder with test data directories (relative to the project root folder)
    private static final String TEST_DATA_FOLDER = "temp/";
    // a counter of test runs for building the real path to the current test data directory
    private static int testCounter = 0;
    // the real path to the main test XML data file for current test
    private File mainDataFile;
    // the real path to the folder with test XML data files for current test
    private File dataFilesFolder;

    /**
     * Prepares the test data for XML manager.
     *
     * @throws IOException IO error
     * @throws ParserConfigurationException parser error
     * @throws TransformerException transformer error
     */
    public XmlManagerTestData() throws IOException, ParserConfigurationException, TransformerException {
        testCounter++;
        // building the real path to the temporary test root data folder for current testing
        String tempFolderDest = TEST_DATA_FOLDER + testCounter + "/";
        // deleting temporary test root data folder from previous testing
        deleteFolderRecursively(new File(tempFolderDest));
        // creating the file folder for the current test
        createTestDataDirectory(tempFolderDest + Config.DATA_FILES_FOLDER_DEST);
        // creating the main file for the current test
        createTestDataMainFile(tempFolderDest + Config.MAIN_DATA_FILE_DEST);
    }

    /**
     * Returns the test main data file.
     *
     * @return the test main data file
     */
    public File getMainDataFile() {
        return mainDataFile;
    }

    /**
     * Returns the test data files folder.
     *
     * @return the test data files folder
     */
    public File getDataFilesFolder() {
        return dataFilesFolder;
    }
    
    /**
     * Returns the formatted message with specifed arguments.
     * 
     * @param formatKey format string resource bundle key
     * @param args message arguments
     * @return formatted message
     */
    public String getFormattedMessage(String formatKey, Object... args) {
        System.err.println(String.format(XML_BUNDLE.getString(formatKey), args));
        return String.format(XML_BUNDLE.getString(formatKey), args);
    }
    
    /**
     * Returns the XML data file object corresponding to the specified class name.
     * 
     * @param className class name
     * @return data file
     */
    public File getFileFromClass(String className) {
        return new File(dataFilesFolder.getPath() + "/" + className.toLowerCase() + ".xml");
    }
    
    /**
     * Performs the XML manager initialization (setting the paths to data files). 
     * 
     * @param xmlManager XML manager
     * @throws ADataManagementException an error
     */
    public void initXmlManager(XmlManager xmlManager) throws ADataManagementException {
        xmlManager.setPaths(mainDataFile, dataFilesFolder, XML_BUNDLE);
    }

    /*
     Deletes the existing temporary directory.
     */
    private void deleteFolderRecursively(File file) {
        if (file.isDirectory()) {
            File[] files = file.listFiles();
            
            for (File f : files) {
                deleteFolderRecursively(f);
            }
        }
        
        file.delete();
    }

    /*
     Creates a new folder for test XML data files associated with current test.
     */
    private void createTestDataDirectory(String dataFilesFolderDest) throws IOException {
        dataFilesFolder = new File(dataFilesFolderDest);

        // creating the directory for current test
        if (!dataFilesFolder.mkdirs()) {
            throw new IOException("Failed to create directory: " + dataFilesFolder);
        }
    }

    /*
     Creates a new main test XML data file associated with current test.
     */
    private void createTestDataMainFile(String mainDataFileDest) throws ParserConfigurationException, TransformerException {
        mainDataFile = new File(mainDataFileDest);

        // creating the stream for a new main file
        StreamResult result = new StreamResult(mainDataFile);
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

}
