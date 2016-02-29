/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Byte.
 *
 * @author Petr Kozler
 */
public class ByteTest {
    
    public static Logger logger = LogManager.getLogger(ByteTest.class.getName());
    
    public static void runTestSuite() {
        ByteTest.byteTestCase();
        ByteTest.byteValueTestCase();
        ByteTest.compareToTestCase();
        ByteTest.equalsTestCase();
        ByteTest.toStringTestCase();
        ByteTest.toStringTestCase2();
        ByteTest.parseByteTestCase();
    }
    
    /**
     * Otestuje vytvoření hodnoty.
     */
    public static void byteTestCase() {
        Byte a;
        byte b;
        a = new Byte(Byte.MIN_VALUE);
        b = a.byteValue();
        logger.info(b);
        a = new Byte((byte)0);
        b = a.byteValue();
        logger.info(b);
        a = new Byte(Byte.MAX_VALUE);
        b = a.byteValue();
        logger.info(b);
    }
    
    /**
     * Otestuje získání hodnoty příslušného vestavěného datového typu.
     */
    public static void byteValueTestCase() {
        Byte a;
        byte b;
        a = new Byte((byte)0);
        b = a.byteValue();
        logger.info(b);
        a = Byte.parseByte("0");
        b = a.byteValue();
        logger.info(b);
    }
    
    /**
     * Otestuje porovnání dvou hodnot.
     */
    public static void compareToTestCase() {
        Byte a, b;
        int c;
        a = new Byte(Byte.MIN_VALUE);
        b = new Byte((byte)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Byte(Byte.MAX_VALUE);
        b = new Byte((byte)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Byte((byte)0);
        b = new Byte((byte)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Byte((byte)0);
        b = new Byte((byte)-1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Byte((byte)1);
        b = new Byte((byte)1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Byte((byte)-1);
        b = new Byte((byte)-1);
        c = a.compareTo(b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou hodnot.
     */
    public static void equalsTestCase() {
        Byte a, b;
        boolean c;
        a = new Byte(Byte.MIN_VALUE);
        b = new Byte((byte)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Byte(Byte.MAX_VALUE);
        b = new Byte((byte)1);
        c = a.equals(b);
        logger.info(c);
        a = new Byte((byte)0);
        b = new Byte((byte)1);
        c = a.equals(b);
        logger.info(c);
        a = new Byte((byte)0);
        b = new Byte((byte)-1);
        c = a.equals(b);
        logger.info(c);
        a = new Byte((byte)1);
        b = new Byte((byte)1);
        c = a.equals(b);
        logger.info(c);
        a = new Byte((byte)-1);
        b = new Byte((byte)-1);
        c = a.equals(b);
        logger.info(c);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty.
     */
    public static void toStringTestCase() {
        Byte a;
        String b;
        a = new Byte((byte)100);
        b = a.toString();
        logger.info(b);
        a = new Byte((byte)0);
        b = a.toString();
        logger.info(b);
        a = new Byte((byte)-100);
        b = a.toString();
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace hodnoty příslušného vestavěného datového typu.
     */
    public static void toStringTestCase2() {
        Byte a;
        String b;
        a = new Byte((byte)100);
        b = Byte.toString(a);
        logger.info(b);
        a = new Byte((byte)0);
        b = Byte.toString(a);
        logger.info(b);
        a = new Byte((byte)-100);
        b = Byte.toString(a);
        logger.info(b);
    }
    
    public static void parseByteTestCase() {
        Byte a;
        byte b;
        a = Byte.parseByte("100");
        b = a.byteValue();
        logger.info(b);
        a = Byte.parseByte("0");
        b = a.byteValue();
        logger.info(b);
        a = Byte.parseByte("-100");
        b = a.byteValue();
        logger.info(b);
    }
    
}
