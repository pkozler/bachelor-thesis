package application;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.stream.XMLStreamException;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

public class XmlManager {

    private ArrayList<String> classList = new ArrayList<>();
    private ArrayList<String> langList = new ArrayList<>();

    private DocumentBuilder db;

    public XmlManager() throws XMLStreamException, ParserConfigurationException, SAXException, IOException {
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        db = dbf.newDocumentBuilder();

        Document document = db.parse(new File(Config.CLASSES_FILE_DEST));
        document.getDocumentElement().normalize();

        NodeList languages = document.getElementsByTagName("language");

        for (int i = 0; i < languages.getLength(); i++) {
            Node language = languages.item(i);

            if (language.getNodeType() == Node.ELEMENT_NODE) {
                Element languageElement = (Element) language;
                langList.add(languageElement.getTextContent());
            }
        }

        NodeList classes = document.getElementsByTagName("class");

        for (int i = 0; i < classes.getLength(); i++) {
            Node clazz = classes.item(i);

            if (clazz.getNodeType() == Node.ELEMENT_NODE) {
                Element classElement = (Element) clazz;
                classList.add(classElement.getTextContent());
            }
        }

        Collections.sort(classList);
        Collections.sort(langList);
    }

    public String loadCode(String clazz, String lang) throws SAXException, IOException {
        Document document = db.parse(new File(Config.CLASSES_FOLDER_DEST + clazz.toLowerCase() + ".xml"));
        document.getDocumentElement().normalize();

        NodeList translations = document.getElementsByTagName("translation");

        for (int i = 0; i < translations.getLength(); i++) {
            Node translation = translations.item(i);

            if (translation.getNodeType() == Node.ELEMENT_NODE) {
                Element translationElement = (Element) translation;

                if (lang.equals(translationElement.getAttribute("lang"))) {
                    return translationElement.getTextContent();
                }
            }
        }

        return "";
    }

    public void saveCode(String clazz, String lang, String code) {
        // TODO zapsat změny do XML souboru
    }

    public ArrayList<String> getClassList() {
        return classList;
    }

    public ArrayList<String> getLangList() {
        return langList;
    }

}
