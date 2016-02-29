/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Float.
 *
 * @author Petr Kozler
 */
public class FloatTest {
    
    public static Logger logger = LogManager.getLogger(FloatTest.class.getName());
    
    public static void runTestSuite() {
        FloatTest.floatTestCase();
        FloatTest.floatValueTestCase();
        FloatTest.compareToTestCase();
        FloatTest.equalsTestCase();
        FloatTest.toStringTestCase();
        FloatTest.toStringTestCase2();
        FloatTest.parseFloatTestCase();
    }
    
    /**
     * Otestuje vytvoření hodnoty.
     */
    public static void floatTestCase() {
        Float a;
        float b;
        a = new Float(Float.MIN_VALUE);
        b = a.floatValue();
        logger.info(b);
        a = new Float((float)0);
        b = a.floatValue();
        logger.info(b);
        a = new Float(Float.MAX_VALUE);
        b = a.floatValue();
        logger.info(b);
    }
    
    /**
     * Otestuje získání hodnoty příslušného vestavěného datového typu.
     */
    public static void floatValueTestCase() {
        Float a;
        float b;
        a = new Float((float)0);
        b = a.floatValue();
        logger.info(b);
        a = Float.parseFloat("0");
        b = a.floatValue();
        logger.info(b);
    }
    
    /**
     * Otestuje porovnání dvou hodnot.
     */
    public static void compareToTestCase() {
        Float a, b;
        int c;
        a = new Float(Float.MIN_VALUE);
        b = new Float((float)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Float(Float.MAX_VALUE);
        b = new Float((float)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Float((float)0);
        b = new Float((float)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Float((float)0);
        b = new Float((float)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Float((float)1);
        b = new Float((float)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Float((float)-1);
        b = new Float((float)-1);
        c = a.compareTo(b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou hodnot.
     */
    public static void equalsTestCase() {
        Float a, b;
        boolean c;
        a = new Float(Float.MIN_VALUE);
        b = new Float((float)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Float(Float.MAX_VALUE);
        b = new Float((float)1);
        c = a.equals(b);
        logger.info(c);
        a = new Float((float)0);
        b = new Float((float)1);
        c = a.equals(b);
        logger.info(c);
        a = new Float((float)0);
        b = new Float((float)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Float((float)1);
        b = new Float((float)1);
        c = a.equals(b);
        logger.info(c);
        a = new Float((float)-1);
        b = new Float((float)-1);
        c = a.equals(b);
        logger.info(c);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty.
     */
    public static void toStringTestCase() {
        Float a;
        String b;
        a = new Float((float)0.1);
        b = a.toString();
        logger.info(b);
        a = new Float((float)0);
        b = a.toString();
        logger.info(b);
        a = new Float((float)-0.1);
        b = a.toString();
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty příslušného vestavěného datového typu.
     */
    public static void toStringTestCase2() {
        Float a;
        String b;
        a = new Float((float)0.1);
        b = Float.toString(a);
        logger.info(b);
        a = new Float((float)0);
        b = Float.toString(a);
        logger.info(b);
        a = new Float((float)-0.1);
        b = Float.toString(a);
        logger.info(b);
    }
    
    public static void parseFloatTestCase() {
        Float a;
        float b;
        a = Float.parseFloat("0.1");
        b = a.floatValue();
        logger.info(b);
        a = Float.parseFloat("0");
        b = a.floatValue();
        logger.info(b);
        a = Float.parseFloat("-0.1");
        b = a.floatValue();
        logger.info(b);
    }
    
}
