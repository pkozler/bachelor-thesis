package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code IntegerTest} class performs automatic testing of the
 * {@code Integer} class.
 *
 * @author Petr Kozler
 */
public class IntegerTest {

    public static Logger logger = LogManager.getLogger(IntegerTest.class.getName());

    public static void runTestSuite() {
        IntegerTest.intValueTestCase();
        IntegerTest.compareToTestCase();
        IntegerTest.compareTestCase();
        IntegerTest.equalsTestCase();
        IntegerTest.toStringTestCase();
        IntegerTest.toStringTestCase2();
        IntegerTest.parseIntTestCase();
    }

    /**
     * Tests the intValue method.
     */
    public static void intValueTestCase() {
        Integer a;
        int b;
        a = new Integer(Integer.MIN_VALUE);
        b = a.intValue();
        logger.info(b);
        a = new Integer((int) 0);
        b = a.intValue();
        logger.info(b);
        a = new Integer(Integer.MAX_VALUE);
        b = a.intValue();
        logger.info(b);
    }

    /**
     * Tests the compareTo method.
     */
    public static void compareToTestCase() {
        Integer a, b;
        int c;
        a = new Integer(Integer.MIN_VALUE);
        b = new Integer((int) -1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Integer(Integer.MAX_VALUE);
        b = new Integer((int) 1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Integer((int) 0);
        b = new Integer((int) 1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Integer((int) 0);
        b = new Integer((int) -1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Integer((int) 1);
        b = new Integer((int) 1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Integer((int) -1);
        b = new Integer((int) -1);
        c = a.compareTo(b);
        logger.info(c);
    }

    /**
     * Tests the compare method.
     */
    public static void compareTestCase() {
        int a, b;
        int c;
        a = Integer.MIN_VALUE;
        b = (int) -1;
        c = Integer.compare(a, b);
        logger.info(c);
        a = Integer.MAX_VALUE;
        b = (int) 1;
        c = Integer.compare(a, b);
        logger.info(c);
        a = (int) 0;
        b = (int) 1;
        c = Integer.compare(a, b);
        logger.info(c);
        a = (int) 0;
        b = (int) -1;
        c = Integer.compare(a, b);
        logger.info(c);
        a = (int) 1;
        b = (int) 1;
        c = Integer.compare(a, b);
        logger.info(c);
        a = (int) -1;
        b = (int) -1;
        c = Integer.compare(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method.
     */
    public static void equalsTestCase() {
        Integer a, b;
        boolean c;
        a = new Integer(Integer.MIN_VALUE);
        b = new Integer((int) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Integer(Integer.MAX_VALUE);
        b = new Integer((int) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Integer((int) 0);
        b = new Integer((int) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Integer((int) 0);
        b = new Integer((int) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Integer((int) 1);
        b = new Integer((int) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Integer((int) -1);
        b = new Integer((int) -1);
        c = a.equals(b);
        logger.info(c);
    }

    /**
     * Tests the toString method.
     */
    public static void toStringTestCase() {
        Integer a;
        String b;
        a = new Integer((int) 100000);
        b = a.toString();
        logger.info(b);
        a = new Integer((int) 0);
        b = a.toString();
        logger.info(b);
        a = new Integer((int) -100000);
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the static toString method.
     */
    public static void toStringTestCase2() {
        Integer a;
        String b;
        a = new Integer((int) 100000);
        b = Integer.toString(a);
        logger.info(b);
        a = new Integer((int) 0);
        b = Integer.toString(a);
        logger.info(b);
        a = new Integer((int) -100000);
        b = Integer.toString(a);
        logger.info(b);
    }

    /**
     * Tests the parseInt method.
     */
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
