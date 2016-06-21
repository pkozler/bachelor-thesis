package main.app.xml;

/**
 * The enum {@code XmlKeyword} represents a keyword (element or attribute) used
 * in any of XML data files.
 *
 * @author Petr Kozler
 */
public enum XmlKeyword {

    LIST_ROOT_ELEMENT("lists"),
    CLASS_LIST_ELEMENT("classes"),
    LANGUAGE_LIST_ELEMENT("languages"),
    CODE_ROOT_ELEMENT("codes"),
    CLASS_ELEMENT("class"),
    LANGUAGE_ELEMENT("language"),
    CODE_ELEMENT("code"),
    LANGUAGE_ATTRIBUTE("lang");

    private final String NAME;

    /**
     * Returns the keyword.
     * 
     * @return keyword
     */
    public String getName() {
        return NAME;
    }
    
    /**
     * Creates a new keyword.
     * 
     * @param name keyword
     */
    XmlKeyword(String name) {
        this.NAME = name;
    }
    
}
