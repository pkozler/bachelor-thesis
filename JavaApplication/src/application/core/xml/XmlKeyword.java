package application.core.xml;

/**
 * The enum {@code XmlKeyword} represents a keyword (element or attribute) used
 * in any of XML data files.
 *
 * @author Petr Kozler
 */
public enum XmlKeyword {

    LIST_ROOT_ELEMENT("lists"),
    CLASS_LIST_ELEMENT("classes"),
    LANGUAG_LIST_ELEMENT("languages"),
    CODE_ROOT_ELEMENT("codes"),
    CLASS_ELEMENT("class"),
    LANGUAGE_ELEMENT("language"),
    CODE_ELEMENT("code"),
    LANGUAGE_ATTRIBUTE("lang");

    private final String name;

    /**
     * Returns the keyword.
     * 
     * @return keyword
     */
    public String getName() {
        return name;
    }
    
    /**
     * Creates a new keyword.
     * 
     * @param name keyword
     */
    XmlKeyword(String name) {
        this.name = name;
    }
    
}
