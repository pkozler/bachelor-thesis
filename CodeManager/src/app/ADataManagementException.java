package app;

/**
 * The class {@code ADataManagementException} represents the general exception
 * which is throwed in case of error occurrence 
 * during the application data management.
 * 
 * @author Petr Kozler
 */
public abstract class ADataManagementException extends Exception {
    
    /**
     * Creates a new exception.
     * 
     * @param message exception message
     */
    public ADataManagementException(String message) {
        super(message);
    }
    
}
