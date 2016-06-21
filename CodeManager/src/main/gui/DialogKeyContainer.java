/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main.gui;

/**
 * The class {@code DialogKeyContainer} contains string resource bundle keys
 * for dialog title, header and content text.
 *
 * @author Petr Kozler
 */
public class DialogKeyContainer {
    
    public final String TITLE_KEY;
    public final String HEADER_TEXT_KEY;
    public final String CONTENT_TEXT_KEY;
    
    /**
     * Creates a new key container.
     * 
     * @param titleKey resource bundle key for a dialog title
     * @param headerKey resource bundle key for a dialog header
     * @param contentKey resource bundle key for a dialog content
     */
    public DialogKeyContainer(String titleKey, String headerKey, String contentKey) {
        TITLE_KEY = titleKey;
        HEADER_TEXT_KEY = headerKey;
        CONTENT_TEXT_KEY = contentKey;
    }
    
}
