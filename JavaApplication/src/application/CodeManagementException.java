package application;

/**
 * The class {@code CodeManagementException} represents the general exception
 * which is throwed in case of error occurrence 
 * during the application data management.
 * 
 * @author Petr Kozler
 */
public class CodeManagementException extends Exception {
    
    /**
     * Creates a new exception.
     * 
     * @param message exception message
     */
    public CodeManagementException(String message) {
        super(message);
    }
    
}
