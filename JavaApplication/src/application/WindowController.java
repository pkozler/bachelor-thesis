package application;

import java.net.URL;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;

import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.transformation.SortedList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.ListView;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.Clipboard;
import javafx.scene.input.ClipboardContent;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;

/**
 * The class {@code WindowController} provides methods for GUI components
 * event handling and therefore serves as a mediator between the GUI components
 * and the core data management application logic.
 * 
 * @author Petr Kozler
 */
public class WindowController implements Initializable {

    @FXML
    private AnchorPane mainWindow;
    @FXML
    private ComboBox<String> langSelectComboBox;
    @FXML
    private ListView<String> classNamesListView;
    @FXML
    private TextField classSearchTextField;
    @FXML
    private Button classSearchButton;
    @FXML
    private TextArea codeTextArea;
    @FXML
    private MenuItem copyCodeMenuItem;
    @FXML
    private MenuItem editCodeMenuItem;
    @FXML
    private MenuItem pasteCodeMenuItem;
    @FXML
    private MenuItem saveCodeMenuItem;
    @FXML
    private Button copyCodeButton;
    @FXML
    private Button editCodeButton;
    @FXML
    private Button pasteCodeButton;
    @FXML
    private Button saveCodeButton;
    @FXML
    private MenuItem addClassMenuItem;
    @FXML
    private MenuItem editClassMenuItem;
    @FXML
    private MenuItem removeClassMenuItem;
    @FXML
    private Button addClassButton;
    @FXML
    private Button editClassButton;
    @FXML
    private Button removeClassButton;
    @FXML
    private MenuItem addLangMenuItem;
    @FXML
    private MenuItem editLangMenuItem;
    @FXML
    private MenuItem removeLangMenuItem;
    @FXML
    private Button addLangButton;
    @FXML
    private Button editLangButton;
    @FXML
    private Button removeLangButton;
    
    // resource bundle for strings
    private ResourceBundle bundle;
    // source code manager
    private ICodeManager codeManager;
    // factory for creating the dialog windows
    private DialogFactory dialogFactory;

    /**
     * Starts the class search after clicking the search button
     * and shows the result in a class list.
     * 
     * @param event
     */
    @FXML
    public void handleSearchClassAction(ActionEvent event) {
        classNamesListView.getSelectionModel().select(classSearchTextField.getText().trim());
    }

    /**
     * Starts adding a new class after clicking the corresponding button
     * or menu item.
     * 
     * @param event
     */
    @FXML
    public void handleAddClassAction(ActionEvent event) {
        String name = dialogFactory.getNameFromDialog("addClass", "enterName", "addClassText");

        if (name != null) {
            try {
                codeManager.addClass(name);
            } catch (CodeManagementException ex) {
                Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        setListItems();
    }

    /**
     * Starts editing a selected class after clicking the corresponding button
     * or menu item.
     * 
     * @param event
     */
    @FXML
    public void handleEditClassAction(ActionEvent event) {
        String oldName = classNamesListView.getSelectionModel().getSelectedItem();
        String name = dialogFactory.getNameFromDialog("editClass", "enterName", "editClassText");

        if (name != null) {
            try {
                codeManager.editClass(oldName, name);
            } catch (CodeManagementException ex) {
                Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        setListItems();
    }

    /**
     * Starts removing a selected class after clicking the corresponding button
     * or menu item.
     * 
     * @param event
     */
    @FXML
    public void handleRemoveClassAction(ActionEvent event) {
        String name = classNamesListView.getSelectionModel().getSelectedItem();

        if (dialogFactory.isConfirmedInDialog("removeClass", "confirmation", "removeClassText")) {
            try {
                codeManager.removeClass(name);
            } catch (CodeManagementException ex) {
                Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        setListItems();
    }

    /**
     * Starts adding a new language after clicking the corresponding button
     * or menu item.
     *
     * @param event
     */
    @FXML
    public void handleAddLangAction(ActionEvent event) {
        String name = dialogFactory.getNameFromDialog("addLang", "enterName", "addLangText");

        if (name != null) {
            try {
                codeManager.addLang(name);
            } catch (CodeManagementException ex) {
                Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        setListItems();
    }

    /**
     * Starts editing a selected language after clicking the corresponding button
     * or menu item.
     *
     * @param event
     */
    @FXML
    public void handleEditLangAction(ActionEvent event) {
        String oldName = classNamesListView.getSelectionModel().getSelectedItem();
        String name = dialogFactory.getNameFromDialog("editLang", "enterName", "editLangText");

        if (name != null) {
            try {
                codeManager.editLang(oldName, name);
            } catch (CodeManagementException ex) {
                Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        setListItems();
    }

    /**
     * Starts removing a selected language after clicking the corresponding button
     * or menu item.
     *
     * @param event
     */
    @FXML
    public void handleRemoveLangAction(ActionEvent event) {
        String name = classNamesListView.getSelectionModel().getSelectedItem();

        if (dialogFactory.isConfirmedInDialog("removeLang", "confirmation", "removeLangText")) {
            try {
                codeManager.removeLang(name);
            } catch (CodeManagementException ex) {
                Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        setListItems();
    }

    /**
     * Cause program termination after clicking the corresponding menu item.
     *
     * @param event
     */
    @FXML
    public void handleExitAction(ActionEvent event) {
        if (codeTextArea.isEditable()) {
            if (!dialogFactory.isConfirmedInDialog("cancelCode", "confirmation", "cancelCodeText")) {
                return;
            }
        }
        
        ((Stage) mainWindow.getScene().getWindow()).close();
    }

    /**
     * Copies the source code text area content to the system clipboard.
     * 
     * @param event
     */
    @FXML
    public void handleCopyCodeAction(ActionEvent event) {
        if (!codeTextArea.getText().isEmpty()) {
            ClipboardContent content = new ClipboardContent();
            content.putString(codeTextArea.getText());
            Clipboard.getSystemClipboard().setContent(content);
        }
    }

    /**
     * Switch the application window interface to the source code edit mode
     * (enables editing of the source code text area).
     * 
     * @param event
     */
    @FXML
    public void handleEditCodeAction(ActionEvent event) {
        setCodeEditMode(true);
    }

    /**
     * Pastes the content of the system clipboard to the source code text area.
     * 
     * @param event
     */
    @FXML
    public void handlePasteCodeAction(ActionEvent event) {
        if (codeTextArea.isEditable()) {
            Clipboard clipboard = Clipboard.getSystemClipboard();

            if (clipboard.hasString()) {
                codeTextArea.setText(clipboard.getString());
            }
        }
    }

    /**
     * Saves the changes made in the current source code showed in the
     * source code text area and switches the application window interface
     * back to the showing mode (disables editing of the source code text area).
     * 
     * @param event
     */
    @FXML
    public void handleSaveCodeAction(ActionEvent event) {
        try {
            codeManager.saveCode(
                    classNamesListView.getSelectionModel().getSelectedItem(),
                    langSelectComboBox.getSelectionModel().getSelectedItem(),
                    codeTextArea.getText());
            refreshCodeTextArea();
        } catch (CodeManagementException ex) {
            Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    /**
     * Shows the dialog with the application info.
     *
     * @param event
     */
    @FXML
    public void handleAboutAction(ActionEvent event) {
        dialogFactory.showInfoInDialog("about", "windowTitle", "aboutText");
    }
    
    /**
     * Initializes the dialog window factory.
     * 
     * @param dialogFactory dialog window factory
     */
    public void setDialogFactory(DialogFactory dialogFactory) {
        this.dialogFactory = dialogFactory;
    }

    /**
     * Initializes the source code manager and fills the lists of available 
     * Java classes and programming languages.
     * 
     * @param codeManager source code manager
     */
    public void setCodeManager(ICodeManager codeManager) {
        this.codeManager = codeManager;
        setListItems();
        setCodeEditMode(false);
    }

    /**
     * Initialize the windows controller components.
     * 
     * @param url address
     * @param rb resources
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        bundle = rb;
        classNamesListView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        setListeners();
    }

    /*
        Cancels the changes made in the current source code,
        loads the previous version of the code and disables
        the edit mode.
     */
    private void handleCancelCodeAction(ActionEvent event) {
        if (dialogFactory.isConfirmedInDialog("cancelCode", "confirmation", "cancelCodeText")) {
            refreshCodeTextArea();
        }
    }

    /*
        Sets the items of a list view component representing the list of
        available Java classes and the items of a combo box component
        representing the list of available programming languages.
     */
    private void setListItems() {
        try {
            classNamesListView.setItems(new SortedList(
                    FXCollections.observableArrayList(codeManager.loadClassList()), String.CASE_INSENSITIVE_ORDER));
            langSelectComboBox.setItems(new SortedList(
                    FXCollections.observableArrayList(codeManager.loadLangList()), String.CASE_INSENSITIVE_ORDER));
        } catch (CodeManagementException ex) {
            Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    /*
        Sets the action listeners for class list view, 
        language combo box and search text field components.
     */
    private void setListeners() {
        classNamesListView.getSelectionModel().selectedIndexProperty().addListener(
                (ObservableValue<? extends Number> observable, Number oldValue, Number newValue) -> refreshCodeTextArea());
        langSelectComboBox.getSelectionModel().selectedIndexProperty().addListener(
                (ObservableValue<? extends Number> observable, Number oldValue, Number newValue) -> refreshCodeTextArea());
        classSearchTextField.focusedProperty().addListener(
                (ObservableValue<? extends Boolean> arg0, Boolean oldPropertyValue, Boolean newPropertyValue)
                -> setSearchButtonAsDefault(newPropertyValue));
    }

    /*
        Sets the activation of components for source code editing.
     */
    private void setCodeControlsEnabled(boolean enabled) {
        if (enabled) {
            editCodeButton.setText(bundle.getString("cancelCode"));
            editCodeMenuItem.setText(bundle.getString("cancelCode"));
            editCodeButton.setOnAction((event) -> handleCancelCodeAction(event));
            editCodeMenuItem.setOnAction((event) -> handleCancelCodeAction(event));
        } else {
            editCodeButton.setText(bundle.getString("editCode"));
            editCodeMenuItem.setText(bundle.getString("editCode"));
            editCodeButton.setOnAction((event) -> handleEditCodeAction(event));
            editCodeMenuItem.setOnAction((event) -> handleEditCodeAction(event));
        }
        
        if (classNamesListView.getSelectionModel().getSelectedItem() != null
                && langSelectComboBox.getSelectionModel().getSelectedItem() != null) {
            codeTextArea.setEditable(enabled);
            copyCodeButton.setDisable(false);
            copyCodeMenuItem.setDisable(false);
            editCodeButton.setDisable(false);
            editCodeMenuItem.setDisable(false);
            pasteCodeButton.setDisable(!enabled);
            saveCodeButton.setDisable(!enabled);
            pasteCodeMenuItem.setDisable(!enabled);
            saveCodeMenuItem.setDisable(!enabled);
        } else {
            codeTextArea.setEditable(false);
            copyCodeButton.setDisable(true);
            copyCodeMenuItem.setDisable(true);
            editCodeButton.setDisable(true);
            editCodeMenuItem.setDisable(true);
            pasteCodeButton.setDisable(true);
            saveCodeButton.setDisable(true);
            pasteCodeMenuItem.setDisable(true);
            saveCodeMenuItem.setDisable(true);
        }
    }

    /*
        Sets the activation of components for class list management.
     */
    private void setClassControlsEnabled(boolean enabled) {
        if (classNamesListView.getSelectionModel().getSelectedItem() != null) {
            editClassButton.setDisable(!enabled);
            removeClassButton.setDisable(!enabled);
            editClassMenuItem.setDisable(!enabled);
            removeClassMenuItem.setDisable(!enabled);
        } else {
            editClassButton.setDisable(true);
            removeClassButton.setDisable(true);
            editClassMenuItem.setDisable(true);
            removeClassMenuItem.setDisable(true);
        }

        addClassButton.setDisable(!enabled);
        addClassMenuItem.setDisable(!enabled);
        classNamesListView.setDisable(!enabled);
        classSearchButton.setDisable(!enabled);
        classSearchTextField.setDisable(!enabled);
    }

    /*
        Sets the activation of components for language list management.
     */
    private void setLangControlsEnabled(boolean enabled) {
        if (langSelectComboBox.getSelectionModel().getSelectedItem() != null) {
            editLangButton.setDisable(!enabled);
            removeLangButton.setDisable(!enabled);
            editLangMenuItem.setDisable(!enabled);
            removeLangMenuItem.setDisable(!enabled);
        } else {
            editLangButton.setDisable(true);
            removeLangButton.setDisable(true);
            editLangMenuItem.setDisable(true);
            removeLangMenuItem.setDisable(true);
        }

        addLangButton.setDisable(!enabled);
        addLangMenuItem.setDisable(!enabled);
        langSelectComboBox.setDisable(!enabled);
    }

    /*
        Sets the activation of each group of components according to the current
        application interface mode (TRUE sets the source code editing mode,
        FALSE sets the showing / searching mode).
     */
    private void setCodeEditMode(boolean activated) {
        setCodeControlsEnabled(activated);
        setClassControlsEnabled(!activated);
        setLangControlsEnabled(!activated);
    }

    /*
        Sets the class search button as a default button when the class search
        text field has focus.
     */
    private void setSearchButtonAsDefault(Boolean newPropertyValue) {
        if (newPropertyValue) {
            classSearchButton.setDefaultButton(true);
        } else {
            classSearchButton.setDefaultButton(false);
        }
    }

    /*
        Performs the main window components refresh after selecting 
        the new class or language from the corresponding list, which includes
        disabling the code edit mode (if enabled), loading
        the corresponding source code for the current selected Java class
        in the current selected programming language and showing this code
        in the source code text area.
     */
    private void refreshCodeTextArea() {
        setCodeEditMode(false);

        String clazz = classNamesListView.getSelectionModel().getSelectedItem();
        String lang = langSelectComboBox.getSelectionModel().getSelectedItem();

        if (clazz == null || lang == null) {
            return;
        }

        try {
            codeTextArea.setText(codeManager.loadCode(clazz, lang));
        } catch (CodeManagementException ex) {
            dialogFactory.showExceptionInDialog(ex, "codeLoad", "error", "codeLoadError");
        }
    }

    /**
     * Sets the handler for the window closing request.
     */
    public void setOnCloseHandler() {
        ((Stage) mainWindow.getScene().getWindow()).setOnCloseRequest((WindowEvent event) -> {
            event.consume();
            handleExitAction(null);
        });
    }

}
