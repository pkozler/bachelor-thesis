/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package application;

import java.util.Optional;
import java.util.ResourceBundle;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.scene.control.TextInputDialog;

/**
 * Třída {@code DialogFactory} poskytuje metody pro vytváření dialogů různého
 * typu a návrat uživatelského vstupu pro kontrolery.
 *
 * @author Petr Kozler
 */
public class DialogFactory {

    // zdroj textů
    private final ResourceBundle BUNDLE;

    /**
     * Vytvoří novou továrnu dialogů.
     *
     * @param bundle zdroj textů
     */
    public DialogFactory(ResourceBundle bundle) {
        this.BUNDLE = bundle;
    }

    /**
     * Zobrazí informační dialog.
     *
     * @param titleKey klíč textu pro titulek dialogu
     * @param headerKey klíč textu pro hlavičku dialogu
     * @param contentKey klíč textu pro obsah dialogu
     */
    public void showInfoInDialog(String titleKey, String headerKey, String contentKey) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(BUNDLE.getString(titleKey));
        alert.setHeaderText(BUNDLE.getString(headerKey));
        alert.setContentText(BUNDLE.getString(contentKey));
        alert.showAndWait();
    }

    /**
     * Zobrazí potvrzovací dialog.
     *
     * @param titleKey klíč textu pro titulek dialogu
     * @param headerKey klíč textu pro hlavičku dialogu
     * @param contentKey klíč textu pro obsah dialogu
     * @return TRUE, pokud uživatel dialog potvrdil, jinak FALSE
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
     * Zobrazí dialog pro zadání textu.
     *
     * @param titleKey klíč textu pro titulek dialogu
     * @param headerKey klíč textu pro hlavičku dialogu
     * @param contentKey klíč textu pro obsah dialogu
     * @return uživatelem zadaný text nebo NULL, pokud uživatel dialog zrušil
     */
    public String getNameFromDialog(String titleKey, String headerKey, String contentKey) {
        TextInputDialog dialog = new TextInputDialog();
        dialog.setTitle(BUNDLE.getString(titleKey));
        dialog.setHeaderText(BUNDLE.getString(headerKey));
        dialog.setContentText(BUNDLE.getString(contentKey));
        Optional<String> result = dialog.showAndWait();

        return result.isPresent() ? result.get() : null;
    }

}
