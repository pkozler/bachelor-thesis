package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code BooleanTest} class performs automatic testing of the
 * {@code Boolean} class.
 *
 * @author Petr Kozler
 */
public class BooleanTest {

    public static Logger logger = LogManager.getLogger(BooleanTest.class.getName());

    public static void runTestSuite() {
        BooleanTest.booleanValueTestCase();
        BooleanTest.compareToTestCase();
        BooleanTest.compareTestCase();
        BooleanTest.equalsTestCase();
        BooleanTest.toStringTestCase();
        BooleanTest.toStringTestCase2();
        BooleanTest.parseBooleanTestCase();
    }

    /**
     * Tests the booleanValue method.
     */
    public static void booleanValueTestCase() {
        Boolean a;
        boolean b;
        // true value
        a = new Boolean(true);
        b = a.booleanValue();
        logger.info(b);
        // false falue
        a = new Boolean(false);
        b = a.booleanValue();
        logger.info(b);
    }

    /**
     * Tests the compareTo method.
     */
    public static void compareToTestCase() {
        Boolean a, b;
        int c;
        // true and false
        a = new Boolean(true);
        b = new Boolean(false);
        c = a.compareTo(b);
        logger.info(c);
        // false and true
        a = new Boolean(false);
        b = new Boolean(true);
        c = a.compareTo(b);
        logger.info(c);
        // both values are true
        a = new Boolean(true);
        b = new Boolean(true);
        c = a.compareTo(b);
        logger.info(c);
        // both values are false
        a = new Boolean(false);
        b = new Boolean(false);
        c = a.compareTo(b);
        logger.info(c);
    }

    /**
     * Tests the compare method.
     */
    public static void compareTestCase() {
        boolean a, b;
        int c;
        a = true;
        b = false;
        c = Boolean.compare(a, b);
        logger.info(c);
        a = false;
        b = true;
        c = Boolean.compare(a, b);
        logger.info(c);
        a = true;
        b = true;
        c = Boolean.compare(a, b);
        logger.info(c);
        a = false;
        b = false;
        c = Boolean.compare(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method.
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
     * Tests the toString method.
     */
    public static void toStringTestCase() {
        Boolean a;
        String b;
        // true value text representation
        a = new Boolean(true);
        b = a.toString();
        logger.info(b);
        // false value text representation
        a = new Boolean(false);
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the static toString method.
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
     * Tests the parseBoolean method.
     */
    public static void parseBooleanTestCase() {
        Boolean a;
        boolean b;
        // true value parsing
        a = Boolean.parseBoolean("true");
        b = a.booleanValue();
        logger.info(b);
        // false value parsing
        a = Boolean.parseBoolean("false");
        b = a.booleanValue();
        logger.info(b);
    }

}
