/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny String.
 *
 * @author Petr Kozler
 */
public class StringTest {
    
    public static Logger logger = LogManager.getLogger(StringTest.class.getName());
    
    public static void runTestSuite() {
        StringTest.stringTestCase();
        StringTest.stringTestCase2();
        StringTest.stringTestCase3();
        StringTest.compareToTestCase();
        StringTest.equalsTestCase();
        StringTest.substringTestCase();
        StringTest.substringTestCase2();
        StringTest.indexOfTestCase();
        StringTest.indexOfTestCase2();
        StringTest.indexOfTestCase3();
        StringTest.indexOfTestCase4();
        StringTest.lengthTestCase();
        StringTest.trimTestCase();
        StringTest.toLowerCaseTestCase();
        StringTest.toUpperCaseTestCase();
        StringTest.charAtTestCase();
        StringTest.replaceTestCase();
        StringTest.startsWithTestCase();
        StringTest.endsWithTestCase();
        StringTest.isEmptyTestCase();
        StringTest.toStringTestCase();
    }
    
    /**
     * Otestuje vytvoření řetězce z literálu.
     */
    public static void stringTestCase() {
        String a;
        // řetězec s bílými znaky
        a = "This is a test.";
        logger.info(a);
        // písmena
        a = "test";
        logger.info(a);
        // číslice
        a = "1234";
        logger.info(a);
        // jeden znak
        a = "a";
        logger.info(a);
        // žádný znak
        a = "";
        logger.info(a);
    }
    
    /**
     * Otestuje vytvoření řetězce z pole bytů.
     */
    public static void stringTestCase2() {
        byte[] a; 
        String b;
        // pole s větším počtem prvků včetně bílých znaků
        a = new byte[]{'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '.'};
        b = new String(a);
        logger.info(b);
        // pole bez bílých znaků
        a = new byte[]{'1', '2', '3', '4'};
        b = new String(a);
        logger.info(b);
        // prázdné pole
        a = new byte[]{};
        b = new String(a);
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření řetězce ze zadaného počtu bytů v poli od zadaného indexu.
     */
    public static void stringTestCase3() {
        byte[] a; 
        String b;
        // zvolení části pole s větším počtem znaků
        a = new byte[]{'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '.'};
        b = new String(a, 10, 4);
        logger.info(b);
    }
    
    /**
     * Otestuje porovnání dvou řetězců.
     */
    public static void compareToTestCase() {
        String a, b;
        int c;
        // rozdílné řetězce od začátku
        a = "aaa";
        b = "bbb";
        c = a.compareTo(b);
        logger.info(c);
        // rozdílné řetězce na konci
        a = "aaaa";
        b = "aaab";
        c = a.compareTo(b);
        logger.info(c);
        // rozdílné řetězce od začátku (prohozené)
        a = "bbb";
        b = "aaa";
        c = a.compareTo(b);
        logger.info(c);
        // rozdílné řetězce na konci (prohozené)
        a = "aaab";
        b = "aaaa";
        c = a.compareTo(b);
        logger.info(c);
        // shodné řetězce
        a = "aaa";
        b = "aaa";
        c = a.compareTo(b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou řetězců.
     */
    public static void equalsTestCase() {
        String a, b;
        boolean c;
        // rozdílné řetězce od začátku
        a = "aaa";
        b = "bbb";
        c = a.equals(b);
        logger.info(c);
        // rozdílné řetězce na konci
        a = "aaaa";
        b = "aaab";
        c = a.equals(b);
        logger.info(c);
        // rozdílné řetězce od začátku (prohozené)
        a = "bbb";
        b = "aaa";
        c = a.equals(b);
        logger.info(c);
        // rozdílné řetězce na konci (prohozené)
        a = "aaab";
        b = "aaaa";
        c = a.equals(b);
        logger.info(c);
        // shodné řetězce
        a = "aaa";
        b = "aaa";
        c = a.equals(b);
        logger.info(c);
    }
    
    /**
     * Otestuje získání podřetězce od zadaného indexu.
     */
    public static void substringTestCase() {
        String a, b;
        a = "This is a test.";
        // řetězec od počátku
        b = a.substring(0);
        logger.info(b);
        // řetězec od jiné pozice
        b = a.substring(10);
        logger.info(b);
    }
    
    /**
     * Otestuje získání podřetězce zadané délky od zadaného indexu.
     */
    public static void substringTestCase2() {
        String a, b;
        a = "This is a test.";
        // řetězec od počátku do pozice blízké počátku
        b = a.substring(0, 4);
        logger.info(b);
        // řetězec od pozice vzdálenější počátku
        b = a.substring(10, 14);
        logger.info(b);
        // řetězec z konce
        b = a.substring(14, 15);
        logger.info(b);
        // stejná počáteční i konečná pozice
        b = a.substring(10, 10);
        logger.info(b);
    }
    
    /**
     * Otestuje určení indexu prvního výskytu znaku.
     */
    public static void indexOfTestCase() {
        String a;
        int b;
        a = "This is a test.";
        // znak vyskytující se jednou (uvnitř)
        b = a.indexOf('a');
        logger.info(b);
        // znak vyskytující se vícekrát
        b = a.indexOf('t');
        logger.info(b);
        // znak vyskytující se jednou (na začátku)
        b = a.indexOf('T');
        logger.info(b);
        // znak vyskytující se jednou (na konci)
        b = a.indexOf('.');
        logger.info(b);
        // nevyskytující se znak
        b = a.indexOf('_');
        logger.info(b);
    }
    
    /**
     * Otestuje určení indexu prvního výskytu znaku od zadané pozice v řetězci.
     */
    public static void indexOfTestCase2() {
        String a;
        int b;
        a = "This is a test.";
        b = a.indexOf('a', 10);
        logger.info(b);
        b = a.indexOf('t', 10);
        logger.info(b);
        b = a.indexOf('i', 0);
        logger.info(b);
        b = a.indexOf('i', 4);
        logger.info(b);
        b = a.indexOf('i', 10);
        logger.info(b);
    }
    
    /**
     * Otestuje určení indexu prvního výskytu podřetězce.
     */
    public static void indexOfTestCase3() {
        String a;
        int b;
        a = "This is a test.";
        // vyskytující se řetězec (na začátku)
        b = a.indexOf("This");
        logger.info(b);
        // vyskytující se řetězec (na konci)
        b = a.indexOf("test");
        logger.info(b);
        // nevyskytující se řetězec
        b = a.indexOf("aaa");
        logger.info(b);
    }
    
    /**
     * Otestuje určení indexu prvního výskytu podřetězce od zadané pozice v řetězci.
     */
    public static void indexOfTestCase4() {
        String a;
        int b;
        a = "This is a test.";
        b = a.indexOf("This", 0);
        logger.info(b);
        b = a.indexOf("test", 4);
        logger.info(b);
        b = a.indexOf("This", 10);
        logger.info(b);
    }
    
    /**
     * Otestuje určení délky řetězce.
     */
    public static void lengthTestCase() {
        String a;
        int b;
        // řetězec o nenulové délce
        a = "This is a test.";
        b = a.length();
        logger.info(b);
        // řetězec o délce jednoho znaku
        a = ".";
        b = a.length();
        logger.info(b);
        // řetězec o nulové délce
        a = "";
        b = a.length();
        logger.info(b);
    }
    
    /**
     * Otestuje odstranění bílých znaků ze začátku a konce řetězce.
     */
    public static void trimTestCase() {
        String a, b;
        // řetězec bez bílých znaků
        a = "test";
        b = a.trim();
        logger.info(b);
        // levostranné bílé znaky
        a = "   test";
        b = a.trim();
        logger.info(b);
        // pravostranné bílé znaky
        a = "test   ";
        b = a.trim();
        logger.info(b);
        // oboustranné bílé znaky
        a = " test ";
        b = a.trim();
        logger.info(b);
        // bílé znaky uvnitř
        a = "t e s t";
        b = a.trim();
        logger.info(b);
    }
    
    /**
     * Otestuje převod řětezce na malá písmena.
     */
    public static void toLowerCaseTestCase() {
        String a, b;
        // všechna písmena malá
        a = "test";
        b = a.toLowerCase();
        logger.info(b);
        // všechna písmena velká
        a = "TEST";
        b = a.toLowerCase();
        logger.info(b);
        // různá velikost písmen
        a = "TesT";
        b = a.toLowerCase();
        logger.info(b);
    }
    
    /**
     * Otestuje převod řětezce na velká písmena.
     */
    public static void toUpperCaseTestCase() {
        String a, b;
        // všechna písmena malá
        a = "test";
        b = a.toUpperCase();
        logger.info(b);
        // všechna písmena velká
        a = "TEST";
        b = a.toUpperCase();
        logger.info(b);
        // různá velikost písmen
        a = "TesT";
        b = a.toUpperCase();
        logger.info(b);
    }
    
    /**
     * Otestuje získání znaku na určitém indexu řetězce.
     */
    public static void charAtTestCase() {
        String a;
        char b;
        a = "This is a test.";
        // na počátku
        b = a.charAt(0);
        logger.info(b);
        // uvnitř
        b = a.charAt(10);
        logger.info(b);
        // na konci
        b = a.charAt(14);
        logger.info(b);
    }
    
    /**
     * Otestuje nahrazení všech výskytů zadaného znaku v řetězci druhým zadaným znakem.
     */
    public static void replaceTestCase() {
        String a, b;
        a = "This is a test.";
        // nahrazení znaků uvnitř řetězce
        b = a.replace(' ', '_');
        logger.info(b);
        // nahrazení znaku z počátku
        b = a.replace('T', 't');
        logger.info(b);
        // nahrazení znaku z konce
        b = a.replace('.', '!');
        logger.info(b);
        // nahrazení neexistujícího znaku
        b = a.replace('?', ':');
        logger.info(b);
    }
    
    /**
     * Otestuje zjištění, zda řetězec začíná zadaným podřetězcem.
     */
    public static void startsWithTestCase() {
        String a, b;
        boolean c;
        a = "This is a test.";
        // řetězec na začátku
        b = "This ";
        c = a.startsWith(b);
        logger.info(c);
        // řetězec uvnitř
        b = "is";
        c = a.startsWith(b);
        logger.info(c);
        // řetězec na konci
        b = "test.";
        c = a.startsWith(b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění, zda řetězec končí zadaným podřetězcem.
     */
    public static void endsWithTestCase() {
        String a, b;
        boolean c;
        a = "This is a test.";
        // řetězec na začátku
        b = "This ";
        c = a.endsWith(b);
        logger.info(c);
        // řetězec uvnitř
        b = "is";
        c = a.endsWith(b);
        logger.info(c);
        // řetězec na konci
        b = "test.";
        c = a.endsWith(b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění, zda je řetězec prázdný.
     */
    public static void isEmptyTestCase() {
        String a;
        boolean b;
        // neprázdný řetězec
        a = "This is a test.";
        b = a.isEmpty();
        logger.info(b);
        // neprázdný řetězec s jediným znakem
        a = ".";
        b = a.isEmpty();
        logger.info(b);
        // prázdný řetězec
        a = "";
        b = a.isEmpty();
        logger.info(b);
    }
    
    /**
     * Otestuje získání textové reprezentace v podobě standardního řetězce.
     */
    public static void toStringTestCase() {
        String a, b;
        // několik znaků
        a = "This is a test.";
        b = a.toString();
        logger.info(b);
        // jeden znak
        a = ".";
        b = a.toString();
        logger.info(b);
        // žádný znak
        a = "";
        b = a.toString();
        logger.info(b);
    }
    
}
