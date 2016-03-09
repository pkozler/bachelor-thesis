package application;

import java.util.Locale;

/**
 * The class {@code Config} is used for storing 
 * the application configuration constants.
 * 
 * @author Petr Kozler
 */
public final class Config {

    /** default locale of application */
    public static final Locale DEFAULT_LOCALE = new Locale("cs", "CZ");
    /** path to the resource bundle */
    public static final String STRINGS_BUNDLE = "bundles.Strings";
    /** path to the FXML document of the main application window (application front-end) */
    public static final String WINDOW_FXML_DOCUMENT = "Window.fxml";
    /** path to the class for application data management (application back-end) */
    public static final String CODE_MANAGER_CLASS = "application.XmlManager";
    
    /*
     * Prevents the instantiation of the class.
     */
    private Config() {
        // really no code
    }

}
