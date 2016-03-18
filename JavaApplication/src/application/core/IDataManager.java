package application.core;

import java.util.ArrayList;

/**
 * The interface {@code IDataManager} provides general methods for managing the
 * application data stored in any way (text files, database etc.) from the
 * application user interface.
 *
 * @author Petr Kozler
 */
public interface IDataManager {

    /**
     * Loads the list of available Java classes.
     *
     * @return Java class list
     * @throws application.core.ADataManagementException error
     */
    public ArrayList<String> loadClassList() throws ADataManagementException;

    /**
     * Loads the list of available programming languages.
     *
     * @return programming language list
     * @throws application.core.ADataManagementException error
     */
    public ArrayList<String> loadLangList() throws ADataManagementException;

    /**
     * Creates a new class.
     *
     * @param clazz class name
     * @throws application.core.ADataManagementException error
     */
    public void addClass(String clazz) throws ADataManagementException;

    /**
     * Renames a class.
     *
     * @param oldClass old class name
     * @param newClass new class name
     * @throws application.core.ADataManagementException error
     */
    public void editClass(String oldClass, String newClass) throws ADataManagementException;

    /**
     * Deletes a class.
     *
     * @param clazz class name
     * @throws application.core.ADataManagementException error
     */
    public void removeClass(String clazz) throws ADataManagementException;

    /**
     * Creates a new language.
     *
     * @param lang language name
     * @throws application.core.ADataManagementException error
     */
    public void addLang(String lang) throws ADataManagementException;

    /**
     * Renames a language.
     *
     * @param oldLang old language name
     * @param newLang new language name
     * @throws application.core.ADataManagementException error
     */
    public void editLang(String oldLang, String newLang) throws ADataManagementException;

    /**
     * Deletes a language.
     *
     * @param lang language name
     * @throws application.core.ADataManagementException error
     */
    public void removeLang(String lang) throws ADataManagementException;

    /**
     * Loads the source code in a specified language for a specified class.
     *
     * @param clazz class name
     * @param lang language name
     * @return source code
     * @throws application.core.ADataManagementException error
     */
    public String loadCode(String clazz, String lang) throws ADataManagementException;

    /**
     * Saves the source code in a specified language for a specified class.
     *
     * @param clazz class name
     * @param lang language name
     * @param code source code
     * @throws application.core.ADataManagementException error
     */
    public void saveCode(String clazz, String lang, String code) throws ADataManagementException;

    /**
     * Validates a class name.
     * 
     * @param clazz class name
     * @return TRUE if the class name is valid, FALSE otherwise
     * @throws application.core.ADataManagementException error
     */
    public boolean validateClass(String clazz) throws ADataManagementException;
    
    /**
     * Validates a language name.
     * 
     * @param lang language name
     * @return TRUE if the class name is valid, FALSE otherwise
     * @throws application.core.ADataManagementException error
     */
    public boolean validateLanguage(String lang) throws ADataManagementException;
    
}
