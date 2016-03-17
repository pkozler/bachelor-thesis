package application.core.xml;
import java.io.File;
import org.w3c.dom.Document;

/**
 * The class {@code XmlContainer} represents a container that binds XML document
 * object to the corresponding XML data file.
 *
 * @author Petr Kozler
 */
class XmlContainer {

    /**
     * XML file
     */
    public final File FILE;
    /**
     * Document object
     */
    public final Document DOCUMENT;

    /**
     * Creates a new container.
     *
     * @param file XML file
     * @param document Document object
     */
    public XmlContainer(File file, Document document) {
        FILE = file;
        DOCUMENT = document;
    }

}
