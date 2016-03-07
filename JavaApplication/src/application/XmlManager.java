package application;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.apache.commons.lang3.StringEscapeUtils;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;


/**
 * Třída {@code XmlManager} poskytuje metody pro čtení, vytváření, úpravu a
 * odstraňování XML souborů s daty aplikace a slouží tak jako správce datové
 * části aplikace.
 *
 * @author Petr Kozler
 */
public class XmlManager {

    // objekt pro načítání XML dokumentů
    private final DocumentBuilder DOCUMENT_BUILDER;
    // hlavní datový XML dokument
    private final Document MAIN_DOCUMENT;
    // adresář ostatních XML dokumentů
    private final String DIRECTORY_PATH;
    
    private interface IDocumentCallable {
        
        public void callOnDocument(Document document);
        
    }

    /**
     * Vytvoří nový XML manažer a načte základní data ze souborů.
     * 
     * @param mainFilePath cesta k hlavnímu souboru
     * @param directoryPath adresář ostatních souborů
     * @throws ParserConfigurationException chyba parseru
     * @throws SAXException SAX chyba
     * @throws IOException IO chyba
     */
    public XmlManager(String mainFilePath, String directoryPath)
            throws ParserConfigurationException, SAXException, IOException {
        File mainFile = new File(mainFilePath);

        if (!mainFile.exists()) {
            // TODO vyhodit výjimku
        }

        File directory = new File(directoryPath);

        if (!directory.isDirectory()) {
            // TODO vyhodit výjimku
        }

        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        DOCUMENT_BUILDER = dbf.newDocumentBuilder();
        MAIN_DOCUMENT = DOCUMENT_BUILDER.parse(mainFile);
        MAIN_DOCUMENT.getDocumentElement().normalize();
        DIRECTORY_PATH = directoryPath;
    }
    
    /**
     * Načte seznam dostupných Java tříd z hlavního XML souboru.
     * 
     * @return seznam Java tříd
     */
    public ArrayList<String> loadClassList() {
        return loadArrayListFromDocument("class");
    }

    /**
     * Načte seznam dostupných programovacích jazyků z hlavního XML souboru.
     * 
     * @return seznam programovacích jazyků
     */
    public ArrayList<String> loadLangList() {
        return loadArrayListFromDocument("language");
    }
    
    /**
     * Přidá novou třídu.
     * 
     * @param clazz název třídy
     * @throws TransformerException chyba vytváření XML souboru
     */
    public void addClass(String clazz) throws TransformerException {
        createDocument(clazz);
        Element classList = getClassList();
        addClassItem(classList, clazz);
    }

    /**
     * Přejmenuje třídu.
     * 
     * @param oldClass původní název
     * @param newClass nový název
     */
    public void editClass(String oldClass, String newClass) {
        renameDocument(oldClass, newClass);
        Element classList = getClassList();
        editClassItem(classList, oldClass, newClass);
    }

    /**
     * Odstraní třídu.
     * 
     * @param clazz název třídy
     */
    public void removeClass(String clazz) {
        deleteDocument(clazz);
        Element classList = getClassList();
        removeClassItem(classList, clazz);
    }

    /**
     * Přidá nový jazyk.
     * 
     * @param lang název jazyka
     * @throws SAXException SAX chyba
     * @throws IOException IO chyba
     */
    public void addLang(String lang) throws SAXException, IOException {
        Element classList = getClassList();
        NodeList classes = classList.getChildNodes();
        iterateClasses((document) -> addCodeItem(document, lang), classes);
        Element langList = getLangList();
        addLangItem(langList, lang);
    }

    /**
     * Přejmenuje jazyk.
     * 
     * @param oldLang původní název
     * @param newLang nový název
     * @throws SAXException SAX chyba
     * @throws IOException IO chyba
     */
    public void editLang(String oldLang, String newLang) throws SAXException, IOException {
        Element classList = getClassList();
        NodeList classes = classList.getChildNodes();
        iterateClasses((document) -> editCodeItem(document, oldLang, newLang), classes);
        Element langList = getLangList();
        editLangItem(langList, oldLang, newLang);
    }

    /**
     * Odstraní jazyk.
     * 
     * @param lang název jazyka
     * @throws SAXException SAX chyba
     * @throws IOException IO chyba
     */
    public void removeLang(String lang) throws SAXException, IOException {
        Element classList = getClassList();
        NodeList classes = classList.getChildNodes();
        iterateClasses((document) -> removeCodeItem(document, lang), classes);
        Element langList = getLangList();
        removeLangItem(langList, lang);
    }
    
    /**
     * Načte zdrojový kód v daném jazyce pro danou třídu.
     * 
     * @param clazz název třídy
     * @param lang název jazyka
     * @return zdrojový kód
     * @throws SAXException SAX chyba
     * @throws IOException IO chyba
     */
    public String loadCode(String clazz, String lang) 
            throws SAXException, IOException {
        Document document = openDocument(clazz);
        Element codeElement = getCodeItem(document, lang);
        
        if (codeElement != null) {
            return codeElement.getTextContent();
        }
        
        return "";
    }

    /**
     * Uloží zdrojový kód v daném jazyce pro danou třídu.
     * 
     * @param clazz název třídy
     * @param lang název jazyka
     * @throws SAXException SAX chyba
     * @throws IOException IO chyba
     */
    public void saveCode(String clazz, String lang, String code) 
            throws SAXException, IOException {
        String escapedCode = StringEscapeUtils.escapeXml10(code);
        Document document = openDocument(clazz);
        Element codeElement = getCodeItem(document, lang);
        
        if (codeElement != null) {
            codeElement.setTextContent(escapedCode);
        }
        else {
            // TODO výjimka
        }
    }
    
    private void iterateClasses(IDocumentCallable callable, NodeList classes) throws SAXException, IOException {
        for (int i = 0; i < classes.getLength(); i++) {
            Node classNode = classes.item(i);
            
            if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                Element classElement = (Element) classNode;
                Document document = openDocument(
                        DIRECTORY_PATH + classElement.getTextContent().toLowerCase() + ".xml");
                callable.callOnDocument(document);
            }
        }
    }
    
    private ArrayList<String> loadArrayListFromDocument(String tagName) {
        ArrayList<String> list = new ArrayList<>();
        NodeList nodes = MAIN_DOCUMENT.getElementsByTagName(tagName);

        for (int i = 0; i < nodes.getLength(); i++) {
            Node language = nodes.item(i);

            if (language.getNodeType() == Node.ELEMENT_NODE) {
                Element languageElement = (Element) language;
                list.add(languageElement.getTextContent());
            }
        }

        return list;
    }
    
    private Document openDocument(String clazz) 
            throws SAXException, IOException {
        Document document = DOCUMENT_BUILDER.parse(
                new File(DIRECTORY_PATH + clazz.toLowerCase() + ".xml"));
        document.getDocumentElement().normalize();

        return document;
    }
    
    private void createDocument(String newClass) throws TransformerException {
        File file = new File(DIRECTORY_PATH + newClass.toLowerCase() + ".xml");
        
        if (file.exists()) {
            // TODO výjimka
        }
        
        StreamResult result = new StreamResult(file);
        Document document = DOCUMENT_BUILDER.newDocument();
        Element root = document.createElement("codes");
        document.appendChild(root);
        DOMSource source = new DOMSource(document);
        TransformerFactory factory = TransformerFactory.newInstance();
        Transformer transformer = factory.newTransformer();
        transformer.transform(source, result);
    }
    
    private void renameDocument(String oldClass, String newClass) {
        File oldFile = new File(DIRECTORY_PATH + oldClass.toLowerCase() + ".xml");
        
        if (!oldFile.exists()) {
            // TODO výjimka
        }
        
        File newFile = new File(DIRECTORY_PATH + newClass.toLowerCase() + ".xml");
        
        if (newFile.exists()) {
            // TODO výjimka
        }
        
        boolean renamed = oldFile.renameTo(newFile);
        
        if (!renamed) {
            // TODO výjimka
        }
    }
    
    private void deleteDocument(String oldClass) {
        File file = new File(DIRECTORY_PATH + oldClass.toLowerCase() + ".xml");
        
        if (!file.exists()) {
            // TODO výjimka
        }
        
        file.delete();
    }
    
    private Element getClassList() {
        return getList(MAIN_DOCUMENT, "classes");
    }
    
    private Element getLangList() {
        return getList(MAIN_DOCUMENT, "languages");
    }
    
    private Element getCodeList(Document clazz) {
        return getList(clazz, "codes");
    }
    
    private Element getList(Document document, String tagName) {
        NodeList items = document.getElementsByTagName(tagName);
        
        if (items.getLength() != 1) {
            // TODO výjimka
        }
        
        Node itemsNode = items.item(0);
        
        if (itemsNode.getNodeType() != Node.ELEMENT_NODE) {
            // TODO výjimka
        }
        
        return (Element) itemsNode;
    }
    
    private Element getClassItem(Element classList, String clazz) {
        NodeList classes = classList.getElementsByTagName("class");
        
        for (int i = 0; i < classes.getLength(); i++) {
            Node classNode = classes.item(i);

            if (classNode.getNodeType() == Node.ELEMENT_NODE) {
                Element classElement = (Element) classNode;
                
                if (classElement.getTextContent().equals(clazz)) {
                    return classElement;
                }
            }
        }
        
        return null;
    }
    
    private Element getLangItem(Element langList, String lang) {
        NodeList languages = langList.getElementsByTagName("language");
        
        for (int i = 0; i < languages.getLength(); i++) {
            Node langNode = languages.item(i);

            if (langNode.getNodeType() == Node.ELEMENT_NODE) {
                Element langElement = (Element) langNode;
                
                if (langElement.getTextContent().equals(lang)) {
                    return langElement;
                }
            }
        }
        
        return null;
    }
    
    private Element getCodeItem(Document clazz, String lang) {
        NodeList codeNodes = clazz.getElementsByTagName("code");
        
        for (int i = 0; i < codeNodes.getLength(); i++) {
            Node codeNode = codeNodes.item(i);

            if (codeNode.getNodeType() == Node.ELEMENT_NODE) {
                Element codeElement = (Element) codeNode;

                if (lang.equals(codeElement.getAttribute("lang"))) {
                    return codeElement;
                }
            }
        }
        
        return null;
    }
    
    private void addClassItem(Element classList, String newClass) {
        Element newClassElement = getClassItem(classList, newClass);
        
        if (newClassElement != null) {
            // TODO výjimka
        }
        
        newClassElement = MAIN_DOCUMENT.createElement("class");
        newClassElement.setTextContent(newClass);
        classList.appendChild(newClassElement);
    }
    
    private void addLangItem(Element langList, String newLang) {
        Element newLangElement = getLangItem(langList, newLang);
        
        if (newLangElement != null) {
            // TODO výjimka
        }
        
        newLangElement = MAIN_DOCUMENT.createElement("language");
        newLangElement.setTextContent(newLang);
        langList.appendChild(newLangElement);
    }
    
    private void addCodeItem(Document clazz, String newLang) {
        Element newCodeElement = getCodeItem(clazz, newLang);
        
        if (newCodeElement != null) {
            // TODO výjimka
        }
        
        newCodeElement = clazz.createElement("code");
        newCodeElement.setAttribute("lang", newLang);
        getCodeList(clazz).appendChild(newCodeElement);
    }
    
    private void editClassItem(Element classList, String oldClass, String newClass) {
        Element oldClassElement = getClassItem(classList, oldClass);
        
        if (oldClassElement == null) {
            // TODO výjimka
        }
        
        Element newClassElement = getClassItem(classList, newClass);
        
        if (newClassElement != null) {
            // TODO výjimka
        }
        
        oldClassElement.setTextContent(newClass);
    }
    
    private void editLangItem(Element langList, String oldLang, String newLang) {
        Element oldLangElement = getClassItem(langList, oldLang);
        
        if (oldLangElement == null) {
            // TODO výjimka
        }
        
        Element newLangElement = getClassItem(langList, newLang);
        
        if (newLangElement != null) {
            // TODO výjimka
        }
        
        oldLangElement.setTextContent(newLang);
    }
    
    private void editCodeItem(Document clazz, String oldLang, String newLang) {
        Element oldCodeElement = getCodeItem(clazz, oldLang);
        
        if (oldCodeElement == null) {
            // TODO výjimka
        }
        
        Element newCodeElement = getCodeItem(clazz, newLang);
        
        if (newCodeElement != null) {
            // TODO výjimka
        }
        
        oldCodeElement.setAttribute("lang", newLang);
    }
    
    private void removeClassItem(Element classList, String oldClass) {
        Element oldClassElement = getClassItem(classList, oldClass);
        
        if (oldClassElement == null) {
            // TODO výjimka
        }
        
        classList.removeChild(oldClassElement);
    }
    
    private void removeLangItem(Element langList, String oldLang) {
        Element oldLangElement = getClassItem(langList, oldLang);
        
        if (oldLangElement == null) {
            // TODO výjimka
        }
        
        langList.removeChild(oldLangElement);
    }
    
    private void removeCodeItem(Document clazz, String oldLang) {
        Element oldCodeElement = getCodeItem(clazz, oldLang);
        
        if (oldCodeElement == null) {
            // TODO výjimka
        }
        
        getCodeList(clazz).removeChild(oldCodeElement);
    }

    @Override
    protected void finalize() throws Throwable {
        // TODO zavřít soubory
        super.finalize();
    }
    
}
