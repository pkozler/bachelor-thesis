package application.config;

/**
 * The class {@code Config} is used for storing 
 * the application configuration constants.
 * 
 * @author Petr Kozler
 */
public final class Config {

    /** path to the FXML document of the main application window (application front-end) */
    public static final String WINDOW_FXML_DOCUMENT = "/resources/fxml/Window.fxml";
    /** path to the class for application data management (application back-end) */
    public static final String CODE_MANAGER_CLASS = "application.core.xml.XmlManager";
    /** path to the main XML data file with the lists of available Java classes and programming languages */
    public static final String MAIN_DATA_FILE_DEST = "data/classes.xml";
    /** path to the folder with XML data files with translations of each class to each language */
    public static final String DATA_FILES_FOLDER_DEST = "data/classes/";
    /** path to the XML-specific strings resource bundle */
    public static final String XML_STRINGS_BUNDLE = "resources.strings.XmlStrings";
    /** path to the strings resource bundle */
    public static final String STRINGS_BUNDLE = "resources.strings.Strings";
    /** regular expression representing the set of allowed Java class names */
    public static final String CLASS_NAME_PATTERN = "[a-zA-Z_][0-9a-zA-Z_]*";
    /** regular expression representing the set of allowed programming language names */
    public static final String LANG_NAME_PATTERN = " +( +| )* *";
    /** default locale of the application */
    public static final String DEFAULT_LOCALE = "cs";
    
    /*
     * Prevents the instantiation of the class.
     */
    private Config() {
        // really no code
    }

}
