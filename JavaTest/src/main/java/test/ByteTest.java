package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code ByteTest} class performs automatic testing of the {@code Byte}
 * class.
 *
 * @author Petr Kozler
 */
public class ByteTest {

    public static Logger logger = LogManager.getLogger(ByteTest.class.getName());

    public static void runTestSuite() {
        ByteTest.byteValueTest();
        ByteTest.compareToTest();
        ByteTest.compareTest();
        ByteTest.equalsTest();
        ByteTest.toStringTest();
        ByteTest.toStringTest2();
        ByteTest.parseByteTest();
    }

    /**
     * Tests the byteValue method.
     */
    public static void byteValueTest() {
        Byte a;
        byte b;
        // minimal value
        a = new Byte(Byte.MIN_VALUE);
        b = a.byteValue();
        logger.info(b);
        // zero value
        a = new Byte((byte) 0);
        b = a.byteValue();
        logger.info(b);
        // maximal value
        a = new Byte(Byte.MAX_VALUE);
        b = a.byteValue();
        logger.info(b);
    }

    /**
     * Tests the compareTo method.
     */
    public static void compareToTest() {
        Byte a, b;
        int c;
        // minimal and bigger negative value
        a = new Byte(Byte.MIN_VALUE);
        b = new Byte((byte) -1);
        c = a.compareTo(b);
        logger.info(c);
        // maximal and smaller positive value
        a = new Byte(Byte.MAX_VALUE);
        b = new Byte((byte) 1);
        c = a.compareTo(b);
        logger.info(c);
        // zero and positive value
        a = new Byte((byte) 0);
        b = new Byte((byte) 1);
        c = a.compareTo(b);
        logger.info(c);
        // zero and negative value
        a = new Byte((byte) 0);
        b = new Byte((byte) -1);
        c = a.compareTo(b);
        logger.info(c);
        // both values are positive
        a = new Byte((byte) 1);
        b = new Byte((byte) 1);
        c = a.compareTo(b);
        logger.info(c);
        // both values are negative
        a = new Byte((byte) -1);
        b = new Byte((byte) -1);
        c = a.compareTo(b);
        logger.info(c);
    }

    /**
     * Tests the compare method.
     */
    public static void compareTest() {
        byte a, b;
        int c;
        a = Byte.MIN_VALUE;
        b = (byte) -1;
        c = Byte.compare(a, b);
        logger.info(c);
        a = Byte.MAX_VALUE;
        b = (byte) 1;
        c = Byte.compare(a, b);
        logger.info(c);
        a = (byte) 0;
        b = (byte) 1;
        c = Byte.compare(a, b);
        logger.info(c);
        a = (byte) 0;
        b = (byte) -1;
        c = Byte.compare(a, b);
        logger.info(c);
        a = (byte) 1;
        b = (byte) 1;
        c = Byte.compare(a, b);
        logger.info(c);
        a = (byte) -1;
        b = (byte) -1;
        c = Byte.compare(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method.
     */
    public static void equalsTest() {
        Byte a, b;
        boolean c;
        a = new Byte(Byte.MIN_VALUE);
        b = new Byte((byte) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Byte(Byte.MAX_VALUE);
        b = new Byte((byte) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Byte((byte) 0);
        b = new Byte((byte) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Byte((byte) 0);
        b = new Byte((byte) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Byte((byte) 1);
        b = new Byte((byte) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Byte((byte) -1);
        b = new Byte((byte) -1);
        c = a.equals(b);
        logger.info(c);
    }

    /**
     * Tests the toString method.
     */
    public static void toStringTest() {
        Byte a;
        String b;
        // positive value text representation
        a = new Byte((byte) 100);
        b = a.toString();
        logger.info(b);
        // zero value text representation
        a = new Byte((byte) 0);
        b = a.toString();
        logger.info(b);
        // negative value text representation
        a = new Byte((byte) -100);
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the static toString method.
     */
    public static void toStringTest2() {
        Byte a;
        String b;
        a = new Byte((byte) 100);
        b = Byte.toString(a);
        logger.info(b);
        a = new Byte((byte) 0);
        b = Byte.toString(a);
        logger.info(b);
        a = new Byte((byte) -100);
        b = Byte.toString(a);
        logger.info(b);
    }

    /**
     * Tests the parseByte method.
     */
    public static void parseByteTest() {
        Byte a;
        byte b;
        // positive value parsing
        a = Byte.parseByte("100");
        b = a.byteValue();
        logger.info(b);
        // zero value parsing
        a = Byte.parseByte("0");
        b = a.byteValue();
        logger.info(b);
        // negative value parsing
        a = Byte.parseByte("-100");
        b = a.byteValue();
        logger.info(b);
    }

}
