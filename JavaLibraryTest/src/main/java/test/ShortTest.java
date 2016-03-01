/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Short.
 *
 * @author Petr Kozler
 */
public class ShortTest {
    
    public static Logger logger = LogManager.getLogger(ShortTest.class.getName());
    
    public static void runTestSuite() {
        ShortTest.shortTestCase();
        ShortTest.shortValueTestCase();
        ShortTest.compareToTestCase();
        ShortTest.equalsTestCase();
        ShortTest.toStringTestCase();
        ShortTest.toStringTestCase2();
        ShortTest.parseShortTestCase();
    }
    
    /**
     * Otestuje vytvoření hodnoty.
     */
    public static void shortTestCase() {
        // otestováno pomocí testu získání hodnoty
    }
    
    /**
     * Otestuje získání hodnoty příslušného vestavěného datového typu.
     */
    public static void shortValueTestCase() {
        Short a;
        short b;
        a = new Short(Short.MIN_VALUE);
        b = a.shortValue();
        logger.info(b);
        a = new Short((short)0);
        b = a.shortValue();
        logger.info(b);
        a = new Short(Short.MAX_VALUE);
        b = a.shortValue();
        logger.info(b);
    }
    
    /**
     * Otestuje porovnání dvou hodnot.
     */
    public static void compareToTestCase() {
        Short a, b;
        int c;
        a = new Short(Short.MIN_VALUE);
        b = new Short((short)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Short(Short.MAX_VALUE);
        b = new Short((short)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Short((short)0);
        b = new Short((short)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Short((short)0);
        b = new Short((short)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Short((short)1);
        b = new Short((short)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Short((short)-1);
        b = new Short((short)-1);
        c = a.compareTo(b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou hodnot.
     */
    public static void equalsTestCase() {
        Short a, b;
        boolean c;
        a = new Short(Short.MIN_VALUE);
        b = new Short((short)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Short(Short.MAX_VALUE);
        b = new Short((short)1);
        c = a.equals(b);
        logger.info(c);
        a = new Short((short)0);
        b = new Short((short)1);
        c = a.equals(b);
        logger.info(c);
        a = new Short((short)0);
        b = new Short((short)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Short((short)1);
        b = new Short((short)1);
        c = a.equals(b);
        logger.info(c);
        a = new Short((short)-1);
        b = new Short((short)-1);
        c = a.equals(b);
        logger.info(c);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty.
     */
    public static void toStringTestCase() {
        Short a;
        String b;
        a = new Short((short)1000);
        b = a.toString();
        logger.info(b);
        a = new Short((short)0);
        b = a.toString();
        logger.info(b);
        a = new Short((short)-1000);
        b = a.toString();
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty příslušného vestavěného datového typu.
     */
    public static void toStringTestCase2() {
        Short a;
        String b;
        a = new Short((short)1000);
        b = Short.toString(a);
        logger.info(b);
        a = new Short((short)0);
        b = Short.toString(a);
        logger.info(b);
        a = new Short((short)-1000);
        b = Short.toString(a);
        logger.info(b);
    }
    
    public static void parseShortTestCase() {
        Short a;
        short b;
        a = Short.parseShort("1000");
        b = a.shortValue();
        logger.info(b);
        a = Short.parseShort("0");
        b = a.shortValue();
        logger.info(b);
        a = Short.parseShort("-1000");
        b = a.shortValue();
        logger.info(b);
    }
    
}
