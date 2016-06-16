package gui;

import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Optional;
import java.util.ResourceBundle;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Dialog;
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

    /*
     Sets the dialog title, header and content text to strings from resource bundle
     with keys specified in given key keyContainer.
     */
    private void setDialogText(Dialog dialog, DialogKeyContainer keyContainer) {
        dialog.setTitle(BUNDLE.getString(keyContainer.TITLE_KEY));
        dialog.setHeaderText(BUNDLE.getString(keyContainer.HEADER_TEXT_KEY));
        dialog.setContentText(BUNDLE.getString(keyContainer.CONTENT_TEXT_KEY));
    }
    
    /*
    Adds an expendable text area with detailed information to the given dialog.
    */
    private void addExpendableContent(Dialog dialog, String labelContentKey, String textAreaContent) {
        Label label = new Label(BUNDLE.getString(labelContentKey));

        // creating a text area with a stack trace 
        TextArea textArea = new TextArea(textAreaContent);
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

        dialog.getDialogPane().setExpandableContent(expContent);
    }

    /**
     * Shows an information dialog.
     *
     * @param keyContainer string resource bundle dialog text key container
     */
    public void showInfoInDialog(DialogKeyContainer keyContainer) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        setDialogText(alert, keyContainer);
        alert.showAndWait();
    }

    /**
     * Shows a confirmation dialog.
     *
     * @param keyContainer string resource bundle dialog text key container
     * @return TRUE, if user confirmed the dialog, FALSE otherwise
     */
    public boolean isConfirmedInDialog(DialogKeyContainer keyContainer) {
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        setDialogText(alert, keyContainer);
        Optional<ButtonType> result = alert.showAndWait();

        return result.get() == ButtonType.OK;
    }

    /**
     * Shows a text input dialog.
     *
     * @param keyContainer string resource bundle dialog text key container
     * @param detailKey resource bundle key for a text format hint
     * @return user input text or NULL, if user canceled the dialog
     */
    public String getNameFromDialog(DialogKeyContainer keyContainer, String detailKey) {
        TextInputDialog dialog = new TextInputDialog();
        setDialogText(dialog, keyContainer);

        addExpendableContent(dialog, "nameFormatLabel", BUNDLE.getString(detailKey));
        Optional<String> result = dialog.showAndWait();

        return !result.isPresent() ? null : result.get();
    }

    /**
     * Shows an error dialog.
     *
     * @param ex výjimka
     * @param keyContainer string resource bundle dialog text key container
     */
    public void showExceptionInDialog(Exception ex, DialogKeyContainer keyContainer) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        setDialogText(alert, keyContainer);

        // writing the stack trace to the string
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        ex.printStackTrace(pw);
        String exceptionText = sw.toString();

        addExpendableContent(alert, "exceptionLabel", exceptionText);
        alert.showAndWait();
    }

}
