/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny StringBuilder.
 *
 * @author Petr Kozler
 */
public class StringBuilderTest {
    
    public static Logger logger = LogManager.getLogger(StringBuilderTest.class.getName());
    
    public static void runTestSuite() {
        StringBuilderTest.stringBuilderTestCase();
        StringBuilderTest.appendTestCase();
        StringBuilderTest.toStringTestCase();
    }
    
    /**
     * Otestuje vytvoření stringbuilderu.
     */
    public static void stringBuilderTestCase() {
        StringBuilder a;
        String b;
        // nový prázdný stringbuilder
        a = new StringBuilder();
        b = a.toString();
        logger.info(b);
    }
    
    /**
     * Otestuje připojení nového řetězce.
     */
    public static void appendTestCase() {
        StringBuilder a;
        String b;
        // připojení prázdného řetězce
        a = new StringBuilder();
        a.append("");
        b = a.toString();
        logger.info(b);
        // připojení jednoho znaku
        a = new StringBuilder();
        a.append(".");
        b = a.toString();
        logger.info(b);
        // připojení více znaků
        a = new StringBuilder();
        a.append("test");
        b = a.toString();
        logger.info(b);
        // vícenásobné připojení (prázdný řetězec na konci)
        a = new StringBuilder();
        a.append("test");
        a.append(".");
        a.append("");
        b = a.toString();
        logger.info(b);
        // vícenásobné připojení (prázdný řetězec uprostřed)
        a = new StringBuilder();
        a.append(".");
        a.append("");
        a.append("test");
        b = a.toString();
        logger.info(b);
        // vícenásobné připojení (prázdný řetězec na začátku)
        a = new StringBuilder();
        a.append("");
        a.append("test");
        a.append(".");
        b = a.toString();
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření výsledného řetězce.
     */
    public static void toStringTestCase() {
        StringBuilder a;
        String b;
        // připojení řetězce najednou
        a = new StringBuilder();
        a.append("This is a test");
        b = a.toString();
        logger.info(b);
        // připojení řetězce po částech
        a = new StringBuilder();
        a.append("This").append(" is").append(" a").append(" test.");
        b = a.toString();
        logger.info(b);
        // připojení řetězce po částech (větší počet)
        a = new StringBuilder();
        a.append("This").append(" ").append("is").append(" ").append("a").append(" ").append("test").append(".");
        b = a.toString();
        logger.info(b);
    }
    
}
