/**
 * The class {@code Config} is used for storing 
 * the application configuration constants.
 * 
 * @author Petr Kozler
 */
public final class Config {

    /** path to the FXML document of the main application window (application front-end) */
    public static final String WINDOW_FXML_DOCUMENT = "gui/fxml/Window.fxml";
    /** path to the class for application data management (application back-end) */
    public static final String CODE_MANAGER_CLASS = "app.xml.XmlManager";
    /** path to the XML data root folder */
    public static final String DATA_FOLDER_PATH = "data";
    /** name of the main XML data file with the lists of available Java classes and programming languages */
    public static final String MAIN_DATA_FILE_NAME = "main.xml";
    /** name of the subfolder with XML data files with translations of each class to each language */
    public static final String DATA_FILES_SUBFOLDER_NAME = "classes";
    /** path to the XML-specific strings resource bundle */
    public static final String XML_STRINGS_BUNDLE = "gui.strings.xml.XmlStrings";
    /** path to the strings resource bundle */
    public static final String STRINGS_BUNDLE = "gui.strings.Strings";
    /** default locale of the application */
    public static final String DEFAULT_LOCALE = "cs";
    
    /*
     * Prevents the instantiation of the class.
     */
    private Config() {
        // no code
    }

}
