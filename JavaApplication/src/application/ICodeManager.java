package application;

import java.util.ArrayList;

/**
 * The interface {@code ICodeManager} provides general methods for managing
 * the application data stored in any way (text files, database etc.)
 * from the application user interface.
 * 
 * @author Petr Kozler
 */
public interface ICodeManager {
    
    /**
     * Loads the list of available Java classes.
     * 
     * @return Java class list
     * @throws application.CodeManagementException error
     */
    public ArrayList<String> loadClassList() throws CodeManagementException;
    
    /**
     * Loads the list of available programming languages.
     * 
     * @return programming language list
     * @throws application.CodeManagementException error
     */
    public ArrayList<String> loadLangList() throws CodeManagementException;
    
    /**
     * Creates a new class.
     * 
     * @param clazz class name
     * @throws application.CodeManagementException error
     */
    public void addClass(String clazz) throws CodeManagementException;
    
    /**
     * Renames a class.
     * 
     * @param oldClass old class name
     * @param newClass new class name
     * @throws application.CodeManagementException error
     */
    public void editClass(String oldClass, String newClass) throws CodeManagementException;
    
    /**
     * Deletes a class.
     * 
     * @param clazz class name
     * @throws application.CodeManagementException error
     */
    public void removeClass(String clazz) throws CodeManagementException;
    
    /**
     * Creates a new language.
     * 
     * @param lang language name
     * @throws application.CodeManagementException error
     */
    public void addLang(String lang) throws CodeManagementException;
    
    /**
     * Renames a language.
     * 
     * @param oldLang old language name
     * @param newLang new language name
     * @throws application.CodeManagementException error
     */
    public void editLang(String oldLang, String newLang) throws CodeManagementException;
    
    /**
     * Deletes a language.
     * 
     * @param lang language name
     * @throws application.CodeManagementException error
     */
    public void removeLang(String lang) throws CodeManagementException;
    
    /**
     * Loads the source code in a specified language for a specified class.
     * 
     * @param clazz class name
     * @param lang language name
     * @return source code
     * @throws application.CodeManagementException error
     */
    public String loadCode(String clazz, String lang) throws CodeManagementException;
    
    /**
     * Saves the source code in a specified language for a specified class.
     * 
     * @param clazz class name
     * @param lang language name
     * @param code source code
     * @throws application.CodeManagementException error
     */
    public void saveCode(String clazz, String lang, String code) throws CodeManagementException;
    
}
