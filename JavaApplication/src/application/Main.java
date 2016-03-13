package application;

import java.io.IOException;
import java.util.ResourceBundle;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 * The class {@code Main} represents the main application class.
 *
 * @author Petr Kozler
 */
public class Main extends Application {

    /**
     * Loads the files required for GUI to run and opens the main application window.
     * 
     * @param stage JavaFX container
     */
    @Override
    public void start(Stage stage) {
        // loading the resource bundle for GUI
        ResourceBundle rb = ResourceBundle.getBundle(Config.STRINGS_BUNDLE, Config.DEFAULT_LOCALE);
        DialogFactory df = new DialogFactory(rb);
        XmlManager xmlManager = null;
        ClassLoader classLoader = Main.class.getClassLoader();

        try {
            // loading the class for managing the XML data files with source codes
            Class xmlManagerClass = classLoader.loadClass(Config.CODE_MANAGER_CLASS);
            xmlManager = (XmlManager) xmlManagerClass.newInstance();
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException ex) {
            df.showExceptionInDialog(ex, "classLoad", "error", "classLoadError");
            return;
        }
        
        try {
            // initializing the XML files manager
            xmlManager.setPaths(Config.MAIN_DATA_FILE_DEST, Config.DATA_FILES_FOLDER_DEST);
        } catch (CodeManagementException ex) {
            df.showExceptionInDialog(ex, "dataInit", "error", "dataInitError");
            return;
        }
        
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource(Config.WINDOW_FXML_DOCUMENT), rb);
        Parent root = null;

        try {
            // loading the FXML document
            root = (Parent) fxmlLoader.load();
        } catch (IOException ex) {
            df.showExceptionInDialog(ex, "fxmlLoad", "error", "fxmlLoadError");
            return;
        }

        // initializing the main window controller
        WindowController controller = fxmlLoader.<WindowController>getController();
        controller.setDialogFactory(df);
        controller.setCodeManager(xmlManager);

        // showing the main window
        Scene scene = new Scene(root);
        stage.setScene(scene);
        stage.setTitle(rb.getString("windowTitle"));
        controller.setOnCloseHandler();
        stage.show();
    }

    /**
     * Starts the application.
     *
     * @param args command-line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

}
