package application;

import application.config.Config;
import application.controller.WindowController;
import application.dialogs.DialogFactory;
import application.core.ADataManagementException;
import application.core.xml.XmlManager;
import java.io.File;
import java.io.IOException;
import java.util.Locale;
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
        // loading the string resources
        ResourceBundle rb = ResourceBundle.getBundle(Config.STRINGS_BUNDLE, new Locale(Config.DEFAULT_LOCALE));
        // initializing the factory for showing dialogs
        DialogFactory df = new DialogFactory(rb);
        
        ClassLoader classLoader = Main.class.getClassLoader();
        XmlManager xmlManager;
        
        try {
            // loading the class for managing the XML data files with source codes
            Class xmlManagerClass = classLoader.loadClass(Config.CODE_MANAGER_CLASS);
            xmlManager = (XmlManager) xmlManagerClass.newInstance();
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException ex) {
            df.showExceptionInDialog(ex, "classLoad", "error", "classLoadError");
            return;
        }
        
        ResourceBundle xmlRb = ResourceBundle.getBundle(Config.XML_STRINGS_BUNDLE, new Locale(Config.DEFAULT_LOCALE));
        
        try {
            // initializing the XML files manager
            xmlManager.setPaths(new File(Config.MAIN_DATA_FILE_DEST), new File(Config.DATA_FILES_FOLDER_DEST), xmlRb);
        } catch (ADataManagementException ex) {
            df.showExceptionInDialog(ex, "dataInit", "error", "dataInitError");
            return;
        }
        
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource(Config.WINDOW_FXML_DOCUMENT), rb);
        Parent root;

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

        // creating the scene
        Scene scene = new Scene(root);
        stage.setScene(scene);
        stage.setTitle(rb.getString("windowTitle"));
        controller.setOnCloseHandler();

        // showing the main window
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
