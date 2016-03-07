package application;

import java.io.IOException;
import java.util.ResourceBundle;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javax.xml.parsers.ParserConfigurationException;
import org.xml.sax.SAXException;

/**
 * Třída {@code Main} představuje hlavní třídu aplikace.
 *
 * @author Petr Kozler
 */
public class Main extends Application {

    /**
     * Načte soubory potřebné pro běh grafického uživatelského rozhraní a otevře
     * hlavní okno aplikace.
     *
     * @param stage kontejner JavaFX komponent
     */
    @Override
    public void start(Stage stage) {
        XmlManager xmlManager = null;

        try {
            xmlManager = new XmlManager(Config.MAIN_DATA_FILE, Config.DATA_FILES_FOLDER);
        } catch (ParserConfigurationException | SAXException | IOException ex) {
            ex.printStackTrace();
        }

        // načtení textů pro GUI
        ResourceBundle rb = ResourceBundle.getBundle(Config.STRINGS_BUNDLE, Config.DEFAULT_LOCALE);
        // načtení FXML dokumentu
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource(Config.WINDOW_FXML_DOCUMENT), rb);

        Parent root = null;

        try {
            root = (Parent) fxmlLoader.load();
        } catch (IOException ex) {
            ex.printStackTrace();
        }

        WindowController controller = fxmlLoader.<WindowController>getController();
        controller.setDialogFactory(new DialogFactory(rb));
        controller.setXmlManager(xmlManager);

        // vytvoření okna
        Scene scene = new Scene(root);
        stage.setScene(scene);
        stage.setTitle(rb.getString("windowTitle"));
        stage.show();
    }

    /**
     * Spustí celou aplikaci.
     *
     * @param args argumenty příkazového řádku
     */
    public static void main(String[] args) {
        launch(args);
    }

}
