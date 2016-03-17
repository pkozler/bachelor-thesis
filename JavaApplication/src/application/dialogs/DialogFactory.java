package application.dialogs;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Optional;
import java.util.ResourceBundle;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Priority;

/**
 * The class {@code DialogFactory} provides methods for creating dialog windows
 * of various types and returning user input to controllers.
 * 
 * @author Petr Kozler
 */
public class DialogFactory {

    // resource bundle for strings
    private final ResourceBundle BUNDLE;

    /**
     * Creates a new dialog factory.
     *
     * @param bundle strings resource
     */
    public DialogFactory(ResourceBundle bundle) {
        this.BUNDLE = bundle;
    }

    /**
     * Shows an information dialog.
     *
     * @param titleKey resource bundle key for a dialog title
     * @param headerKey resource bundle key for a dialog header
     * @param contentKey resource bundle key for a dialog content
     */
    public void showInfoInDialog(String titleKey, String headerKey, String contentKey) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(BUNDLE.getString(titleKey));
        alert.setHeaderText(BUNDLE.getString(headerKey));
        alert.setContentText(BUNDLE.getString(contentKey));
        alert.showAndWait();
    }

    /**
     * Shows a confirmation dialog.
     *
     * @param titleKey resource bundle key for a dialog title
     * @param headerKey resource bundle key for a dialog header
     * @param contentKey resource bundle key for a dialog content
     * @return TRUE, if user confirmed the dialog, FALSE otherwise
     */
    public boolean isConfirmedInDialog(String titleKey, String headerKey, String contentKey) {
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        alert.setTitle(BUNDLE.getString(titleKey));
        alert.setHeaderText(BUNDLE.getString(headerKey));
        alert.setContentText(BUNDLE.getString(contentKey));
        Optional<ButtonType> result = alert.showAndWait();

        return result.get() == ButtonType.OK;
    }
    
    /**
     * Shows a text input dialog.
     *
     * @param titleKey resource bundle key for a dialog title
     * @param headerKey resource bundle key for a dialog header
     * @param contentKey resource bundle key for a dialog content
     * @param detailKey resource bundle key for a text format hint
     * @param namePattern text format regex
     * @return user input text or NULL, if user canceled the dialog
     */
    public String getNameFromDialog(String titleKey, String headerKey, String contentKey, String detailKey, String namePattern) {
        TextInputDialog dialog = new TextInputDialog();
        dialog.setTitle(BUNDLE.getString(titleKey));
        dialog.setHeaderText(BUNDLE.getString(headerKey));
        dialog.setContentText(BUNDLE.getString(contentKey));
        
        Label label = new Label(BUNDLE.getString(detailKey));
        label.setWrapText(true);
        dialog.getDialogPane().setExpandableContent(label);
        
        while (true) {
            Optional<String> result = dialog.showAndWait();
        
            if (!result.isPresent()) {
                return null;
            }
            
            String name = result.get();
            
            if (!name.matches(namePattern)) {
                continue;
            }
            
            return name;
        }
    }
    
    /**
     * Shows an error dialog.
     * 
     * @param ex výjimka
     * @param titleKey resource bundle key for a dialog title
     * @param headerKey resource bundle key for a dialog header
     * @param contentKey resource bundle key for a dialog content
     */
    public void showExceptionInDialog(Exception ex, String titleKey, String headerKey, String contentKey) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(BUNDLE.getString(titleKey));
        alert.setHeaderText(BUNDLE.getString(headerKey));
        alert.setContentText(BUNDLE.getString(contentKey));
        
        // write a stack trace to string
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        ex.printStackTrace(pw);
        String exceptionText = sw.toString();

        Label label = new Label(BUNDLE.getString("exceptionLabel"));

        // creating a text area with a stack trace 
        TextArea textArea = new TextArea(exceptionText);
        textArea.setEditable(false);
        textArea.setWrapText(true);

        textArea.setMaxWidth(Double.MAX_VALUE);
        textArea.setMaxHeight(Double.MAX_VALUE);
        GridPane.setVgrow(textArea, Priority.ALWAYS);
        GridPane.setHgrow(textArea, Priority.ALWAYS);

        GridPane expContent = new GridPane();
        expContent.setMaxWidth(Double.MAX_VALUE);
        expContent.add(label, 0, 0);
        expContent.add(textArea, 0, 1);

        alert.getDialogPane().setExpandableContent(expContent);
        alert.showAndWait();
    }

}
