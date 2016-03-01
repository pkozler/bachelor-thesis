package application;

import java.util.Locale;

public final class Config {

    /*
        TODO opravit cesty !!!
    */
    
    public static final Locale DEFAULT_LOCALE = new Locale("cs", "CZ");
    public static final String STRINGS_RB_DEST = "bundles.Strings";
    public static final String WINDOW_FXML = "resources/Window.fxml";
    public static final String CLASSES_FILE_DEST = "data/classes.xml";
    public static final String CLASSES_FOLDER_DEST = "data/classes/";

    private Config() {

    }

}
