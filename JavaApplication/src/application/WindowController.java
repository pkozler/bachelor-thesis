package application;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;

import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.transformation.SortedList;
import javafx.event.ActionEvent;
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
import javax.xml.transform.TransformerException;
import org.xml.sax.SAXException;

/**
 * Třída {@code WindowController} poskytuje metody pro obsluhu událostí nad
 * grafickými komponentami hlavního okna aplikace a slouží tak jako prostředník
 * mezi GUI a logickou vrstvou představovanou objekty pro správu datových XML
 * souborů.
 *
 * @author Petr Kozler
 */
public class WindowController implements Initializable {

    // kořenový element okna
    @FXML
    private AnchorPane mainWindow;
    // seznam dostupných programovacích jazyků
    @FXML
    private ComboBox<String> langSelectComboBox;
    // seznam dostupných Java tříd
    @FXML
    private ListView<String> classNamesListView;
    // textové pole pro vyhledávání třídy
    @FXML
    private TextField classSearchTextField;
    // tlačítko pro vyhledávání třídy
    @FXML
    private Button classSearchButton;
    // textové pole pro zdrojový kód překladu třídy
    @FXML
    private TextArea codeTextArea;
    // položka menu pro kopírování kódu
    @FXML
    private MenuItem copyCodeMenuItem;
    // položka menu pro vložení kódu
    @FXML
    private MenuItem editCodeMenuItem;
    // položka menu pro vložení kódu
    @FXML
    private MenuItem pasteCodeMenuItem;
    // položka menu pro uložení změn v kódu
    @FXML
    private MenuItem saveCodeMenuItem;
    // tlačítko pro kopírování kódu
    @FXML
    private Button copyCodeButton;
    // tlačítko pro úpravy kódu
    @FXML
    private Button editCodeButton;
    // tlačítko pro vložení kódu
    @FXML
    private Button pasteCodeButton;
    // tlačítko pro uložení změn v kódu
    @FXML
    private Button saveCodeButton;
    // položka menu pro vytvoření třídy
    @FXML
    private MenuItem addClassMenuItem;
    // položka menu pro úpravu názvu třídy
    @FXML
    private MenuItem editClassMenuItem;
    // položka menu pro odstranění třídy
    @FXML
    private MenuItem removeClassMenuItem;
    // tlačítko pro vytvoření třídy
    @FXML
    private Button addClassButton;
    // tlačítko pro úpravu názvu třídy
    @FXML
    private Button editClassButton;
    // tlačítko pro odstranění třídy
    @FXML
    private Button removeClassButton;
    // položka menu pro vytvoření jazyka
    @FXML
    private MenuItem addLangMenuItem;
    // položka menu pro úpravu názvu jazyka
    @FXML
    private MenuItem editLangMenuItem;
    // položka menu pro odstranění jazyka
    @FXML
    private MenuItem removeLangMenuItem;
    // tlačítko pro vytvoření jazyka
    @FXML
    private Button addLangButton;
    // tlačítko pro úpravu názvu jazyka
    @FXML
    private Button editLangButton;
    // tlačítko pro odstranění jazyka
    @FXML
    private Button removeLangButton;
    // zdroj textů
    private ResourceBundle bundle;
    // správce XML souborů
    private XmlManager xmlManager;
    // továrna pro vytváření dialogů
    private DialogFactory dialogFactory;

    /**
     * Spustí vyhledávání třídy s názvem zadaným ve vyhledávacím poli po stisku
     * tlačítka vyhledávání a při nalezení záznamu vybere příslušnou položku v
     * seznamu.
     *
     * @param event událost
     */
    @FXML
    public void handleSearchClassAction(ActionEvent event) {
        classNamesListView.getSelectionModel().select(classSearchTextField.getText().trim());
    }

    /**
     * Spustí vytváření záznamu o nové třídě po stisku příslušného tlačítka nabo
     * položky menu.
     *
     * @param event událost
     */
    @FXML
    public void handleAddClassAction(ActionEvent event) {
        String name = dialogFactory.getNameFromDialog("addClass", "enterName", "addClassText");

        if (name != null) {
            try {
                xmlManager.addClass(name);
            } catch (TransformerException ex) {
                Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        setListItems();
    }

    /**
     * Spustí úpravu názvu třídy po stisku příslušného tlačítka nabo položky
     * menu.
     *
     * @param event událost
     */
    @FXML
    public void handleEditClassAction(ActionEvent event) {
        String oldName = classNamesListView.getSelectionModel().getSelectedItem();
        String name = dialogFactory.getNameFromDialog("editClass", "enterName", "editClassText");

        if (name != null) {
            xmlManager.editClass(oldName, name);
        }

        setListItems();
    }

    /**
     * Spustí odstranění záznamu o třídě po stisku příslušného tlačítka nabo
     * položky menu.
     *
     * @param event událost
     */
    @FXML
    public void handleRemoveClassAction(ActionEvent event) {
        String name = classNamesListView.getSelectionModel().getSelectedItem();

        if (dialogFactory.isConfirmedInDialog("removeClass", "confirmation", "removeClassText")) {
            xmlManager.removeClass(name);
        }

        setListItems();
    }

    /**
     * Spustí vytváření záznamu o novém jazyku po stisku příslušného tlačítka
     * nabo položky menu.
     *
     * @param event událost
     */
    @FXML
    public void handleAddLangAction(ActionEvent event) {
        String name = dialogFactory.getNameFromDialog("addLang", "enterName", "addLangText");

        if (name != null) {
            try {
                xmlManager.addLang(name);
            } catch (SAXException | IOException ex) {
                Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        setListItems();
    }

    /**
     * Spustí úpravu názvu jazyka po stisku příslušného tlačítka nabo položky
     * menu.
     *
     * @param event událost
     */
    @FXML
    public void handleEditLangAction(ActionEvent event) {
        String oldName = classNamesListView.getSelectionModel().getSelectedItem();
        String name = dialogFactory.getNameFromDialog("editLang", "enterName", "editLangText");

        if (name != null) {
            try {
                xmlManager.editLang(oldName, name);
            } catch (SAXException | IOException ex) {
                Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        setListItems();
    }

    /**
     * Spustí odstranění záznamu o jazyku po stisku příslušného tlačítka nabo
     * položky menu.
     *
     * @param event událost
     */
    @FXML
    public void handleRemoveLangAction(ActionEvent event) {
        String name = classNamesListView.getSelectionModel().getSelectedItem();

        if (dialogFactory.isConfirmedInDialog("removeLang", "confirmation", "removeLangText")) {
            try {
                xmlManager.removeLang(name);
            } catch (SAXException | IOException ex) {
                Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        setListItems();
    }

    /**
     * Vyvolá ukončení aplikace po stisku příslušné položky menu.
     *
     * @param event událost
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
     * Zkopíruje do schránky kompletní obsah textového pole pro zobrazení
     * zdrojového kódu po stistku příslušného tlačítka nebo položky menu.
     *
     * @param event událost
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
     * Po stisku příslušného tlačítka nebo položky menu přepne rozhraní aplikace
     * do režimu úpravy zdrojového kódu (umožní editovat obsah textového pole).
     *
     * @param event událost
     */
    @FXML
    public void handleEditCodeAction(ActionEvent event) {
        setCodeEditMode(true);
    }

    /**
     * Přepíše zdrojový kód aktuálně zobrazený v textovém poli obsahem schránky
     * po stistku příslušného tlačítka nebo položky menu.
     *
     * @param event událost
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
     * Po stisku příslušného tlačítka nebo položky menu spustí uložení
     * provedených změn v aktuálním zdrojovém kódu a vrátí rozhraní aplikace do
     * režimu vyhledávání a zobrazení kódu (znemožní editovat obsah textového
     * pole).
     *
     * @param event událost
     */
    @FXML
    public void handleSaveCodeAction(ActionEvent event) {
        try {
            xmlManager.saveCode(
                    classNamesListView.getSelectionModel().getSelectedItem(),
                    langSelectComboBox.getSelectionModel().getSelectedItem(),
                    codeTextArea.getText());
        } catch (SAXException | IOException ex) {
            Logger.getLogger(WindowController.class.getName()).log(Level.SEVERE, null, ex);
        }
        refreshCodeTextArea();
    }

    /**
     * Vyvolá zobrazení dialogu se základním popisem aplikace po stisku
     * příslušné položky menu.
     *
     * @param event událost
     */
    @FXML
    public void handleAboutAction(ActionEvent event) {
        dialogFactory.showInfoInDialog("about", "windowTitle", "aboutText");
    }
    
    /**
     * Inicializuje továrnu pro vytváření dialogových oken.
     * 
     * @param dialogFactory továrna dialogů
     */
    public void setDialogFactory(DialogFactory dialogFactory) {
        this.dialogFactory = dialogFactory;
    }

    /**
     * Inicializuje manažera datových XML souborů se zdrojovými kódy
     * (zahrnuje načtení záznamů dostupných tříd a jazyků
     * z hlavního datového souboru pro zobrazení do seznamů).
     * 
     * @param xmlManager XML manažer
     */
    public void setXmlManager(XmlManager xmlManager) {
        this.xmlManager = xmlManager;
        setListItems();
        setCodeEditMode(false);
    }

    /**
     * Provede inicializaci komponent kontroleru při zobrazení okna aplikace.
     *
     * @param url adresa
     * @param rb zdroje
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        /*((Stage) mainWindow.getScene().getWindow()).onCloseRequestProperty()
                .addListener(event -> handleExitAction(null));*/
        bundle = rb;
        classNamesListView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        setListeners();
    }

    /*
     Po stisku příslušného tlačítka nebo položky menu zruší provedené změny 
     ve zdrojovém kódu, spustí načtení původní podoby z datového souboru
     a vrátí rozhraní aplikace do režimu vyhledávání a zobrazení kódu.
     */
    private void handleCancelCodeAction(ActionEvent event) {
        if (dialogFactory.isConfirmedInDialog("cancelCode", "confirmation", "cancelCodeText")) {
            refreshCodeTextArea();
        }
    }

    /*
     Nastaví záznamy o dostupných třídách a jazycích načtené při inicializaci
     XML manažera jako položky do odpovídajících grafických komponent okna
     představujících seznamy.
     */
    private void setListItems() {
        classNamesListView.setItems(new SortedList(
                FXCollections.observableArrayList(xmlManager.loadClassList()), String.CASE_INSENSITIVE_ORDER));
        langSelectComboBox.setItems(new SortedList(
                FXCollections.observableArrayList(xmlManager.loadLangList()), String.CASE_INSENSITIVE_ORDER));
    }

    /*
     Nastaví posluchače vyhledávání a výběru položky v seznamu tříd nebo jazyků
     pro aktualizaci obsahu textového pole pro zobrazení zdrojového kódu.
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
     Nastaví aktivaci komponent pro úpravu zdrojového kódu.
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
     Nastaví aktivaci komponent pro práci se seznamem tříd.
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
     Nastaví aktivaci komponent pro práci se seznamem jazyků.
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
     Přepne aktivaci jednotlivých skupin komponent podle zvoleného režimu rozhraní aplikace
     (hodnota TRUE nastaví režim úpravy kódu, hodnota FALSE nastaví režim vyhledávání a zobrazení).
     */
    private void setCodeEditMode(boolean activated) {
        setCodeControlsEnabled(activated);
        setClassControlsEnabled(!activated);
        setLangControlsEnabled(!activated);
    }

    /*
     Nastaví tlačítko vyhledávání třídy jako výchozí (umožní stisk 
     pomocí klávesy Enter) při zadávání vstupu do vyhledávacího pole.
     */
    private void setSearchButtonAsDefault(Boolean newPropertyValue) {
        if (newPropertyValue) {
            classSearchButton.setDefaultButton(true);
        } else {
            classSearchButton.setDefaultButton(false);
        }
    }

    /*
     Provede obnovu okna při změně výběru třídy nebo jazyka nebo při
     uložení nebo zrušení změn ve zdrojovém kódu, tj. nastaví rozhraní
     na režim vyhledávání a zobrazení a spustí načtení zdrojového kódu
     knihovny odpovídající aktuálně vybrané třídě pro vybraný jazyk
     z datového souboru a jeho zobrazení do textového pole.
     */
    private void refreshCodeTextArea() {
        setCodeEditMode(false);

        String clazz = classNamesListView.getSelectionModel().getSelectedItem();
        String lang = langSelectComboBox.getSelectionModel().getSelectedItem();

        if (clazz == null || lang == null) {
            return;
        }

        try {
            codeTextArea.setText(xmlManager.loadCode(clazz, lang));
        } catch (SAXException | IOException ex) {
            dialogFactory.showExceptionInDialog(ex, "codeLoad", "error", "codeLoadError");
        }
    }

}
