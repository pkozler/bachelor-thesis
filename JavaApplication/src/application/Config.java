package application;

import java.util.Locale;

/**
 * Třída {@code Config} slouží k uchovávání konfiguračních konstant programu.
 * 
 * @author Petr Kozler
 */
public final class Config {

    /** jazykové prostředí aplikace */
    public static final Locale DEFAULT_LOCALE = new Locale("cs", "CZ");
    /** cesta k souborům s řetězci */
    public static final String STRINGS_BUNDLE = "bundles.Strings";
    /** název FXML dokumentu hlavního okna aplikace */
    public static final String WINDOW_FXML_DOCUMENT = "Window.fxml";
    /** cesta k hlavnímu XML datovému souboru se seznamy Java tříd a programovacích jazyků */
    public static final String MAIN_DATA_FILE = "data/classes.xml";
    /** cesta k adresáři s XML datovými soubory s překlady jednotlivých tříd do jiných jazyků */
    public static final String DATA_FILES_FOLDER = "data/classes/";

    /*
     * Zamezuje vytvoření instance.
     */
    private Config() {
        // žádný kód
    }

}
