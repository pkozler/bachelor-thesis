/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import java.util.Arrays;
import java.util.StringTokenizer;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny StringTokenizer.
 *
 * @author Petr Kozler
 */
public class StringTokenizerTest {
    
    public static Logger logger = LogManager.getLogger(StringTokenizerTest.class.getName());
    
    public static void runTestSuite() {
        StringTokenizerTest.stringTokenizerTestCase();
        StringTokenizerTest.stringTokenizerTestCase2();
        StringTokenizerTest.countTokensTestCase();
        StringTokenizerTest.hasMoreTokensTestCase();
        StringTokenizerTest.nextTokenTestCase();
    }
    
    /**
     * Vytvoří řetězcovou reprezentaci pole tokenů vytvořených z rozděleného řetězce.
     */
    private static String getStringArray(StringTokenizer a) {
        String[] b;
        int c;
        c = a.countTokens();
        b = new String[c];
        
        for (int i = 0; i < c; i++) {
            b[i] = a.nextToken();
        }
        
        return Arrays.toString(b);
    }
    
    /**
     * Otestuje vytvoření stringtokenizeru.
     */
    public static void stringTokenizerTestCase() {
        StringTokenizer a;
        String b;
        // bílé znaky uvnitř řetězce
        a = new StringTokenizer("This is a test.");
        b = getStringArray(a);
        logger.info(b);
        // bílé znaky uvnitř i vně řetězce
        a = new StringTokenizer(" This is   a test. ");
        b = getStringArray(a);
        logger.info(b);
        // bez bílých znaků
        a = new StringTokenizer("This_is_a_test.");
        b = getStringArray(a);
        logger.info(b);
        // jeden znak
        a = new StringTokenizer("_");
        b = getStringArray(a);
        logger.info(b);
        // prázdný řetězec
        a = new StringTokenizer("");
        b = getStringArray(a);
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření stringtokenizeru se zadaným řetězcem představujícím množinu oddělovačů.
     */
    public static void stringTokenizerTestCase2() {
        StringTokenizer a;
        String b;
        // nebílý oddělovač (v řetězci neexistuje)
        a = new StringTokenizer("This is a test.", "_");
        b = getStringArray(a);
        logger.info(b);
        // nebílý oddělovač (v řetězci existuje uvnitř)
        a = new StringTokenizer("This_is_a_test.", "_");
        b = getStringArray(a);
        logger.info(b);
        // nebílý oddělovač (v řetězci existují i bílé znaky)
        a = new StringTokenizer("This_is_ a _test.", "_");
        b = getStringArray(a);
        logger.info(b);
        // nebílý oddělovač (v řetězci existuje uvnitř i vně)
        a = new StringTokenizer("_This_is___a_test._", "_");
        b = getStringArray(a);
        logger.info(b);
        // více oddělovačů (v řetězci existují)
        a = new StringTokenizer("This is_a test.", " _");
        b = getStringArray(a);
        logger.info(b);
        // více oddělovačů (v řetězci neexistují)
        a = new StringTokenizer("Thisisatest.", " _");
        b = getStringArray(a);
        logger.info(b);
    }
    
    /**
     * Otestuje zjištění počtu tokenů.
     */
    public static void countTokensTestCase() {
        StringTokenizer a;
        int b;
        // rozdělení podle bílých znaků
        a = new StringTokenizer("This is a test.");
        b = a.countTokens();
        logger.info(b);
        // rozdělení podle bílých znaků (větší počet)
        a = new StringTokenizer(" This is   a test. ");
        b = a.countTokens();
        logger.info(b);
        // rozdělení podle bílých znaků (žádné)
        a = new StringTokenizer("This_is_a_test.");
        b = a.countTokens();
        logger.info(b);
        // rozdělení podle nebílých znaků
        a = new StringTokenizer("This_is_a_test.", "_");
        b = a.countTokens();
        logger.info(b);
        // prázdný řetězec
        a = new StringTokenizer("");
        b = a.countTokens();
        logger.info(b);
    }
    
    /**
     * Otestuje zjištění existence dalších tokenů.
     */
    public static void hasMoreTokensTestCase() {
        StringTokenizer a;
        boolean b;
        // rozdělení podle bílých znaků
        a = new StringTokenizer("This is a test.");
        b = a.hasMoreTokens();
        logger.info(b);
        // rozdělení podle bílých znaků (větší počet)
        a = new StringTokenizer(" This is   a test. ");
        b = a.hasMoreTokens();
        logger.info(b);
        // rozdělení podle bílých znaků (žádné)
        a = new StringTokenizer("This_is_a_test.");
        b = a.hasMoreTokens();
        logger.info(b);
        // rozdělení podle nebílých znaků
        a = new StringTokenizer("This_is_a_test.", "_");
        b = a.hasMoreTokens();
        logger.info(b);
        // prázdný řetězec
        a = new StringTokenizer("");
        b = a.hasMoreTokens();
        logger.info(b);
    }
    
    /**
     * Otestuje načtení tokenu.
     */
    public static void nextTokenTestCase() {
        StringTokenizer a;
        String b;
        // testovací řetězec
        a = new StringTokenizer("This is a test.");
        b = a.nextToken();
        logger.info(b);
        b = a.nextToken();
        logger.info(b);
        b = a.nextToken();
        logger.info(b);
        b = a.nextToken();
        logger.info(b);
    }
    
}
