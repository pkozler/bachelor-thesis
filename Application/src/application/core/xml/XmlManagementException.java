package application.core.xml;

import application.core.ADataManagementException;

/**
 * The class {@code XmlManagementException} represents an exception specific
 * for working with XML data files.
 * 
 * @author Petr Kozler
 */
public class XmlManagementException extends ADataManagementException {
    
    /*
     (non-Javadoc)
     @see application.core.ADataManagementException#ADataManagementException(java.lang.String)
     */
    public XmlManagementException(String message) {
        super(message);
    }
    
    /**
     * Creates a new exception with formatted message (arguments are typicaly
     * file paths or XML tag names).
     * 
     * @param messageFormat exception message format
     * @param messageArgs exception message arguments
     */
    public XmlManagementException(String messageFormat, Object... messageArgs) {
        this(String.format(messageFormat, messageArgs));
    }
    
}
