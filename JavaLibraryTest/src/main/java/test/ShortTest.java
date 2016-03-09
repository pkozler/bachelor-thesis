package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code ShortTest} class performs automatic testing of the {@code Short}
 * class.
 *
 * @author Petr Kozler
 */
public class ShortTest {

    public static Logger logger = LogManager.getLogger(ShortTest.class.getName());

    public static void runTestSuite() {
        ShortTest.shortValueTest();
        ShortTest.compareToTest();
        ShortTest.compareTest();
        ShortTest.equalsTest();
        ShortTest.toStringTest();
        ShortTest.toStringTest2();
        ShortTest.parseShortTest();
    }

    /**
     * Tests the shortValue method.
     */
    public static void shortValueTest() {
        Short a;
        short b;
        a = new Short(Short.MIN_VALUE);
        b = a.shortValue();
        logger.info(b);
        a = new Short((short) 0);
        b = a.shortValue();
        logger.info(b);
        a = new Short(Short.MAX_VALUE);
        b = a.shortValue();
        logger.info(b);
    }

    /**
     * Tests the compareTo method.
     */
    public static void compareToTest() {
        Short a, b;
        int c;
        a = new Short(Short.MIN_VALUE);
        b = new Short((short) -1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Short(Short.MAX_VALUE);
        b = new Short((short) 1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Short((short) 0);
        b = new Short((short) 1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Short((short) 0);
        b = new Short((short) -1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Short((short) 1);
        b = new Short((short) 1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Short((short) -1);
        b = new Short((short) -1);
        c = a.compareTo(b);
        logger.info(c);
    }

    /**
     * Tests the compare method.
     */
    public static void compareTest() {
        short a, b;
        int c;
        a = Short.MIN_VALUE;
        b = (short) -1;
        c = Short.compare(a, b);
        logger.info(c);
        a = Short.MAX_VALUE;
        b = (short) 1;
        c = Short.compare(a, b);
        logger.info(c);
        a = (short) 0;
        b = (short) 1;
        c = Short.compare(a, b);
        logger.info(c);
        a = (short) 0;
        b = (short) -1;
        c = Short.compare(a, b);
        logger.info(c);
        a = (short) 1;
        b = (short) 1;
        c = Short.compare(a, b);
        logger.info(c);
        a = (short) -1;
        b = (short) -1;
        c = Short.compare(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method.
     */
    public static void equalsTest() {
        Short a, b;
        boolean c;
        a = new Short(Short.MIN_VALUE);
        b = new Short((short) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Short(Short.MAX_VALUE);
        b = new Short((short) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Short((short) 0);
        b = new Short((short) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Short((short) 0);
        b = new Short((short) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Short((short) 1);
        b = new Short((short) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Short((short) -1);
        b = new Short((short) -1);
        c = a.equals(b);
        logger.info(c);
    }

    /**
     * Tests the toString method.
     */
    public static void toStringTest() {
        Short a;
        String b;
        a = new Short((short) 1000);
        b = a.toString();
        logger.info(b);
        a = new Short((short) 0);
        b = a.toString();
        logger.info(b);
        a = new Short((short) -1000);
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the static toString method.
     */
    public static void toStringTest2() {
        Short a;
        String b;
        a = new Short((short) 1000);
        b = Short.toString(a);
        logger.info(b);
        a = new Short((short) 0);
        b = Short.toString(a);
        logger.info(b);
        a = new Short((short) -1000);
        b = Short.toString(a);
        logger.info(b);
    }

    /**
     * Tests the parseShort method.
     */
    public static void parseShortTest() {
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
