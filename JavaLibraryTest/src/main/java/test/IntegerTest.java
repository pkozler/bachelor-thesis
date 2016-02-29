/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Integer.
 *
 * @author Petr Kozler
 */
public class IntegerTest {
    
    public static Logger logger = LogManager.getLogger(IntegerTest.class.getName());
    
    public static void runTestSuite() {
        IntegerTest.integerTestCase();
        IntegerTest.intValueTestCase();
        IntegerTest.compareToTestCase();
        IntegerTest.equalsTestCase();
        IntegerTest.toStringTestCase();
        IntegerTest.toStringTestCase2();
        IntegerTest.parseIntTestCase();	
    }
    
    /**
     * Otestuje vytvoření hodnoty.
     */
    public static void integerTestCase() {
        Integer a;
        int b;
        a = new Integer(Integer.MIN_VALUE);
        b = a.intValue();
        logger.info(b);
        a = new Integer((int)0);
        b = a.intValue();
        logger.info(b);
        a = new Integer(Integer.MAX_VALUE);
        b = a.intValue();
        logger.info(b);
    }
    
    /**
     * Otestuje získání hodnoty příslušného vestavěného datového typu.
     */
    public static void intValueTestCase() {
        Integer a;
        int b;
        a = new Integer((int)0);
        b = a.intValue();
        logger.info(b);
        a = Integer.parseInt("0");
        b = a.intValue();
        logger.info(b);
    }
    
    /**
     * Otestuje porovnání dvou hodnot.
     */
    public static void compareToTestCase() {
        Integer a, b;
        int c;
        a = new Integer(Integer.MIN_VALUE);
        b = new Integer((int)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Integer(Integer.MAX_VALUE);
        b = new Integer((int)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Integer((int)0);
        b = new Integer((int)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Integer((int)0);
        b = new Integer((int)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Integer((int)1);
        b = new Integer((int)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Integer((int)-1);
        b = new Integer((int)-1);
        c = a.compareTo(b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou hodnot.
     */
    public static void equalsTestCase() {
        Integer a, b;
        boolean c;
        a = new Integer(Integer.MIN_VALUE);
        b = new Integer((int)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Integer(Integer.MAX_VALUE);
        b = new Integer((int)1);
        c = a.equals(b);
        logger.info(c);
        a = new Integer((int)0);
        b = new Integer((int)1);
        c = a.equals(b);
        logger.info(c);
        a = new Integer((int)0);
        b = new Integer((int)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Integer((int)1);
        b = new Integer((int)1);
        c = a.equals(b);
        logger.info(c);
        a = new Integer((int)-1);
        b = new Integer((int)-1);
        c = a.equals(b);
        logger.info(c);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty.
     */
    public static void toStringTestCase() {
        Integer a;
        String b;
        a = new Integer((int)100000);
        b = a.toString();
        logger.info(b);
        a = new Integer((int)0);
        b = a.toString();
        logger.info(b);
        a = new Integer((int)-100000);
        b = a.toString();
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty příslušného vestavěného datového typu.
     */
    public static void toStringTestCase2() {
        Integer a;
        String b;
        a = new Integer((int)100000);
        b = Integer.toString(a);
        logger.info(b);
        a = new Integer((int)0);
        b = Integer.toString(a);
        logger.info(b);
        a = new Integer((int)-100000);
        b = Integer.toString(a);
        logger.info(b);
    }
    
    public static void parseIntTestCase() {
        Integer a;
        int b;
        a = Integer.parseInt("100000");
        b = a.intValue();
        logger.info(b);
        a = Integer.parseInt("0");
        b = a.intValue();
        logger.info(b);
        a = Integer.parseInt("-100000");
        b = a.intValue();
        logger.info(b);
    }
    
}
