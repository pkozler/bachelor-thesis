/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Long.
 *
 * @author Petr Kozler
 */
public class LongTest {
    
    public static Logger logger = LogManager.getLogger(LongTest.class.getName());
    
    public static void runTestSuite() {
        LongTest.longTestCase();
        LongTest.longValueTestCase();
        LongTest.compareToTestCase();
        LongTest.equalsTestCase();
        LongTest.toStringTestCase();
        LongTest.toStringTestCase2();
        LongTest.parseLongTestCase();
    }
    
    /**
     * Otestuje vytvoření hodnoty.
     */
    public static void longTestCase() {
        // otestováno pomocí testu získání hodnoty
    }
    
    /**
     * Otestuje získání hodnoty příslušného vestavěného datového typu.
     */
    public static void longValueTestCase() {
        Long a;
        long b;
        a = new Long(Long.MIN_VALUE);
        b = a.longValue();
        logger.info(b);
        a = new Long((long)0);
        b = a.longValue();
        logger.info(b);
        a = new Long(Long.MAX_VALUE);
        b = a.longValue();
        logger.info(b);
    }
    
    /**
     * Otestuje porovnání dvou hodnot.
     */
    public static void compareToTestCase() {
        Long a, b;
        int c;
        a = new Long(Long.MIN_VALUE);
        b = new Long((long)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Long(Long.MAX_VALUE);
        b = new Long((long)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Long((long)0);
        b = new Long((long)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Long((long)0);
        b = new Long((long)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Long((long)1);
        b = new Long((long)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Long((long)-1);
        b = new Long((long)-1);
        c = a.compareTo(b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou hodnot.
     */
    public static void equalsTestCase() {
        Long a, b;
        boolean c;
        a = new Long(Long.MIN_VALUE);
        b = new Long((long)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Long(Long.MAX_VALUE);
        b = new Long((long)1);
        c = a.equals(b);
        logger.info(c);
        a = new Long((long)0);
        b = new Long((long)1);
        c = a.equals(b);
        logger.info(c);
        a = new Long((long)0);
        b = new Long((long)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Long((long)1);
        b = new Long((long)1);
        c = a.equals(b);
        logger.info(c);
        a = new Long((long)-1);
        b = new Long((long)-1);
        c = a.equals(b);
        logger.info(c);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty.
     */
    public static void toStringTestCase() {
        Long a;
        String b;
        a = new Long((long)10000000000L);
        b = a.toString();
        logger.info(b);
        a = new Long((long)0);
        b = a.toString();
        logger.info(b);
        a = new Long((long)-10000000000L);
        b = a.toString();
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty příslušného vestavěného datového typu.
     */
    public static void toStringTestCase2() {
        Long a;
        String b;
        a = new Long((long)10000000000L);
        b = Long.toString(a);
        logger.info(b);
        a = new Long((long)0);
        b = Long.toString(a);
        logger.info(b);
        a = new Long((long)-10000000000L);
        b = Long.toString(a);
        logger.info(b);
    }
    
    public static void parseLongTestCase() {
        Long a;
        long b;
        a = Long.parseLong("10000000000");
        b = a.longValue();
        logger.info(b);
        a = Long.parseLong("0");
        b = a.longValue();
        logger.info(b);
        a = Long.parseLong("-10000000000");
        b = a.longValue();
        logger.info(b);
    }
    
}
