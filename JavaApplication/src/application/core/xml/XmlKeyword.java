package application.core.xml;

/**
 * The enum {@code XmlKeyword} represents a keyword (element or attribute) used
 * in any of XML data files.
 *
 * @author Petr Kozler
 */
enum XmlKeyword {

    CLASSES_ELEMENT("classes"),
    LANGUAGES_ELEMENT("languages"),
    CODES_ELEMENT("codes"),
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
