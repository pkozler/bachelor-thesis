/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Double.
 *
 * @author Petr Kozler
 */
public class DoubleTest {
    
    public static Logger logger = LogManager.getLogger(DoubleTest.class.getName());
    
    public static void runTestSuite() {
        DoubleTest.doubleTestCase();
        DoubleTest.doubleValueTestCase();
        DoubleTest.compareToTestCase();
        DoubleTest.equalsTestCase();
        DoubleTest.toStringTestCase();
        DoubleTest.toStringTestCase2();
        DoubleTest.parseDoubleTestCase();
    }
    
    /**
     * Otestuje vytvoření hodnoty.
     */
    public static void doubleTestCase() {
        Double a;
        double b;
        a = new Double(Double.MIN_VALUE);
        b = a.doubleValue();
        logger.info(b);
        a = new Double((double)0);
        b = a.doubleValue();
        logger.info(b);
        a = new Double(Double.MAX_VALUE);
        b = a.doubleValue();
        logger.info(b);
    }
    
    /**
     * Otestuje získání hodnoty příslušného vestavěného datového typu.
     */
    public static void doubleValueTestCase() {
        Double a;
        double b;
        a = new Double((double)0);
        b = a.doubleValue();
        logger.info(b);
        a = Double.parseDouble("0");
        b = a.doubleValue();
        logger.info(b);
    }
    
    /**
     * Otestuje porovnání dvou hodnot.
     */
    public static void compareToTestCase() {
        Double a, b;
        int c;
        a = new Double(Double.MIN_VALUE);
        b = new Double((double)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Double(Double.MAX_VALUE);
        b = new Double((double)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Double((double)0);
        b = new Double((double)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Double((double)0);
        b = new Double((double)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Double((double)1);
        b = new Double((double)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Double((double)-1);
        b = new Double((double)-1);
        c = a.compareTo(b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou hodnot.
     */
    public static void equalsTestCase() {
        Double a, b;
        boolean c;
        a = new Double(Double.MIN_VALUE);
        b = new Double((double)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Double(Double.MAX_VALUE);
        b = new Double((double)1);
        c = a.equals(b);
        logger.info(c);
        a = new Double((double)0);
        b = new Double((double)1);
        c = a.equals(b);
        logger.info(c);
        a = new Double((double)0);
        b = new Double((double)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Double((double)1);
        b = new Double((double)1);
        c = a.equals(b);
        logger.info(c);
        a = new Double((double)-1);
        b = new Double((double)-1);
        c = a.equals(b);
        logger.info(c);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty.
     */
    public static void toStringTestCase() {
        Double a;
        String b;
        a = new Double((double)0.0000000000000000000000000000000000000000000001);
        b = a.toString();
        logger.info(b);
        a = new Double((double)0);
        b = a.toString();
        logger.info(b);
        a = new Double((double)-0.0000000000000000000000000000000000000000000001);
        b = a.toString();
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty příslušného vestavěného datového typu.
     */
    public static void toStringTestCase2() {
        Double a;
        String b;
        a = new Double((double)0.0000000000000000000000000000000000000000000001);
        b = Double.toString(a);
        logger.info(b);
        a = new Double((double)0);
        b = Double.toString(a);
        logger.info(b);
        a = new Double((double)-0.0000000000000000000000000000000000000000000001);
        b = Double.toString(a);
        logger.info(b);
    }
    
    public static void parseDoubleTestCase() {
        Double a;
        double b;
        a = Double.parseDouble("0.0000000000000000000000000000000000000000000001");
        b = a.doubleValue();
        logger.info(b);
        a = Double.parseDouble("0");
        b = a.doubleValue();
        logger.info(b);
        a = Double.parseDouble("-0.0000000000000000000000000000000000000000000001");
        b = a.doubleValue();
        logger.info(b);
    }
    
}
