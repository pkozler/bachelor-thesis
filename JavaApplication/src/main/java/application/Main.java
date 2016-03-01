package application;

import java.util.ResourceBundle;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 *
 * @author Petr Kozler
 */
public class Main extends Application {

    @Override
    public void start(Stage stage) throws Exception {
        ResourceBundle rb = ResourceBundle.getBundle(Config.STRINGS_RB_DEST, Config.DEFAULT_LOCALE);
        Parent root = FXMLLoader.load(getClass().getResource(Config.WINDOW_FXML), rb);

        Scene scene = new Scene(root);

        stage.setScene(scene);
        stage.setTitle(rb.getString("windowTitle"));
        stage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

}
