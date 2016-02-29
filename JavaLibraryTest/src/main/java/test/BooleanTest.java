/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Boolean.
 *
 * @author Petr Kozler
 */
public class BooleanTest {
    
    public static Logger logger = LogManager.getLogger(BooleanTest.class.getName());
    
    public static void runTestSuite() {
        BooleanTest.booleanTestCase();
        BooleanTest.booleanValueTestCase();
        BooleanTest.compareToTestCase();
        BooleanTest.equalsTestCase();
        BooleanTest.toStringTestCase();
        BooleanTest.toStringTestCase2();
        BooleanTest.parseBooleanTestCase();
    }
    
    /**
     * Otestuje vytvoření hodnoty.
     */
    public static void booleanTestCase() {
        Boolean a;
        boolean b;
        a = new Boolean(true);
        b = a.booleanValue();
        logger.info(b);
        a = new Boolean(false);
        b = a.booleanValue();
        logger.info(b);
    }
    
    /**
     * Otestuje získání hodnoty příslušného vestavěného datového typu.
     */
    public static void booleanValueTestCase() {
        Boolean a;
        boolean b;
        a = new Boolean(false);
        b = a.booleanValue();
        logger.info(b);
        a = Boolean.parseBoolean("false");
        b = a.booleanValue();
        logger.info(b);
    }
    
    /**
     * Otestuje porovnání dvou hodnot.
     */
    public static void compareToTestCase() {
        Boolean a, b;
        int c;
        a = new Boolean(true);
        b = new Boolean(false);
        c = a.compareTo(b);
        logger.info(c);
        a = new Boolean(false);
        b = new Boolean(true);
        c = a.compareTo(b);
        logger.info(c);
        a = new Boolean(true);
        b = new Boolean(true);
        c = a.compareTo(b);
        logger.info(c);
        a = new Boolean(false);
        b = new Boolean(false);
        c = a.compareTo(b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou hodnot.
     */
    public static void equalsTestCase() {
        Boolean a, b;
        boolean c;
        a = new Boolean(true);
        b = new Boolean(false);
        c = a.equals(b);
        logger.info(c);
        a = new Boolean(false);
        b = new Boolean(true);
        c = a.equals(b);
        logger.info(c);
        a = new Boolean(true);
        b = new Boolean(true);
        c = a.equals(b);
        logger.info(c);
        a = new Boolean(false);
        b = new Boolean(false);
        c = a.equals(b);
        logger.info(c);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty.
     */
    public static void toStringTestCase() {
        Boolean a;
        String b;
        a = new Boolean(true);
        b = a.toString();
        logger.info(b);
        a = new Boolean(false);
        b = a.toString();
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty příslušného vestavěného datového typu.
     */
    public static void toStringTestCase2() {
        Boolean a;
        String b;
        a = new Boolean(true);
        b = Boolean.toString(a);
        logger.info(b);
        a = new Boolean(false);
        b = Boolean.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje převod textové reprezentace na hodnotu příslušného vestavěného datového typu.
     */
    public static void parseBooleanTestCase() {
        Boolean a;
        boolean b;
        a = Boolean.parseBoolean("true");
        b = a.booleanValue();
        logger.info(b);
        a = Boolean.parseBoolean("false");
        b = a.booleanValue();
        logger.info(b);
    }
    
}
