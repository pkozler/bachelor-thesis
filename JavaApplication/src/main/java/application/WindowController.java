package application;

import java.io.IOException;
import java.net.URL;
import java.util.Collections;
import java.util.ResourceBundle;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.stream.XMLStreamException;

import org.xml.sax.SAXException;

import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
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

/**
 *
 * @author Petr Kozler
 */
public class WindowController implements Initializable {
    
    @FXML
    private AnchorPane mainWindow;
    @FXML
    private TextField classSearchTextField;
    @FXML
    private Button classSearchButton;
    @FXML
    private ComboBox<String> langSelectComboBox;
    @FXML
    private ListView<String> classNamesListView;
    @FXML
    private TextArea codeTextArea;
    @FXML
    private MenuItem editCodeMenuItem;
    @FXML
    private MenuItem pasteCodeMenuItem;
    @FXML
    private MenuItem saveCodeMenuItem;
    @FXML
    private Button editCodeButton;
    @FXML
    private Button pasteCodeButton;
    @FXML
    private Button saveCodeButton;

    private ResourceBundle bundle;
    private XmlManager xmlManager;

    private void setCodeEditEnabled(boolean enabled) {
        if (enabled) {
            editCodeButton.setText(bundle.getString("cancelCode"));
            editCodeMenuItem.setText(bundle.getString("cancelCode"));
            editCodeButton.setOnAction((event) -> handleOnSelectedItemChanged(event));
            editCodeMenuItem.setOnAction((event) -> handleOnSelectedItemChanged(event));
        } else {
            editCodeButton.setText(bundle.getString("editCode"));
            editCodeMenuItem.setText(bundle.getString("editCode"));
            editCodeButton.setOnAction((event) -> handleEditCodeAction(event));
            editCodeMenuItem.setOnAction((event) -> handleEditCodeAction(event));
        }
        codeTextArea.setEditable(enabled);
        pasteCodeButton.setDisable(!enabled);
        saveCodeButton.setDisable(!enabled);
        pasteCodeMenuItem.setDisable(!enabled);
        saveCodeMenuItem.setDisable(!enabled);
    }

    private void loadCodeToTextArea() {
        try {
            codeTextArea.setText(
                    xmlManager.loadCode(classNamesListView.getSelectionModel().getSelectedItem(),
                            langSelectComboBox.getSelectionModel().getSelectedItem()));
        } catch (SAXException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void handleClassSearchTextFieldFocusChanged(Boolean newPropertyValue) {
        if (newPropertyValue) {
            classSearchButton.setDefaultButton(true);
        } else {
            classSearchButton.setDefaultButton(false);
        }
    }

    @FXML
    public void handleClassSearchButtonAction(ActionEvent event) {
        String className = classSearchTextField.getText().trim();
        int index = Collections.binarySearch(
                classNamesListView.getItems(), className, String.CASE_INSENSITIVE_ORDER);
        classNamesListView.getSelectionModel().select(index);
    }

    @FXML
    public void handleOnSelectedItemChanged(ActionEvent event) {
        if (codeTextArea.isEditable()) {
            // TODO zobrazit dialog potvrzení
        }

        loadCodeToTextArea();
        setCodeEditEnabled(false);
    }
    
    @FXML
    public void handleAddClassAction(ActionEvent event) {
        
    }
    
    @FXML
    public void handleEditClassAction(ActionEvent event) {
        
    }
    
    @FXML
    public void handleRemoveClassAction(ActionEvent event) {
        
    }
    
    @FXML
    public void handleAddLangAction(ActionEvent event) {
        
    }
    
    @FXML
    public void handleEditLangAction(ActionEvent event) {
        
    }
    
    @FXML
    public void handleRemoveLangAction(ActionEvent event) {
        
    }
    
    @FXML
    public void handleExitAction(ActionEvent event) {
        ((Stage) mainWindow.getScene().getWindow()).close();
    }
    
    @FXML
    public void handleCopyCodeAction(ActionEvent event) {
        if (!codeTextArea.getText().isEmpty()) {
            Clipboard clipboard = Clipboard.getSystemClipboard();
            ClipboardContent content = new ClipboardContent();
            content.putString(codeTextArea.getText());
            clipboard.setContent(content);
        }
    }

    @FXML
    public void handleEditCodeAction(ActionEvent event) {
        setCodeEditEnabled(true);
    }

    @FXML
    public void handlePasteCodeAction(ActionEvent event) {
        if (codeTextArea.isEditable()) {
            Clipboard clipboard = Clipboard.getSystemClipboard();
            if (clipboard.hasString()) {
                codeTextArea.setText(clipboard.getString());
            }
        }
    }

    @FXML
    public void handleSaveCodeAction(ActionEvent event) {
        // TODO zobrazit dialog potvrzení
        xmlManager.saveCode(
                classNamesListView.getSelectionModel().getSelectedItem(),
                langSelectComboBox.getSelectionModel().getSelectedItem(),
                codeTextArea.getText());
        loadCodeToTextArea();
        setCodeEditEnabled(false);
    }
    
    @FXML
    public void handleAboutAction(ActionEvent event) {
        Alert alert = new Alert(AlertType.INFORMATION);
        alert.setTitle(bundle.getString("about"));
        alert.setHeaderText(bundle.getString("windowTitle"));
        alert.setContentText(bundle.getString("aboutText"));
        alert.showAndWait();
    }

    private void setListeners() {
        classNamesListView.getSelectionModel().selectedItemProperty().addListener(
                (ObservableValue<? extends String> observable, String oldValue, String newValue)
                -> handleOnSelectedItemChanged(null));

        langSelectComboBox.getSelectionModel().selectedItemProperty().addListener(
                (ObservableValue<? extends String> observable, String oldValue, String newValue)
                -> handleOnSelectedItemChanged(null));

        classSearchTextField.focusedProperty().addListener(
                (ObservableValue<? extends Boolean> arg0, Boolean oldPropertyValue, Boolean newPropertyValue)
                -> handleClassSearchTextFieldFocusChanged(newPropertyValue));
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        bundle = rb;
        
        try {
            xmlManager = new XmlManager();
        } catch (XMLStreamException e) {
            e.printStackTrace();
        } catch (ParserConfigurationException e) {
            e.printStackTrace();
        } catch (SAXException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        classNamesListView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        classNamesListView.setItems(FXCollections.observableArrayList(xmlManager.getClassList()));
        langSelectComboBox.setItems(FXCollections.observableArrayList(xmlManager.getLangList()));

        setListeners();
    }

}
