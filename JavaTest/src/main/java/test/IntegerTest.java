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
        IntegerTest.intValueTest();
        IntegerTest.compareToTest();
        IntegerTest.compareTest();
        IntegerTest.equalsTest();
        IntegerTest.toStringTest();
        IntegerTest.toStringTest2();
        IntegerTest.parseIntTest();
    }

    /**
     * Tests the intValue method.
     */
    public static void intValueTest() {
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
    public static void compareToTest() {
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
    public static void compareTest() {
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
    public static void equalsTest() {
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
    public static void toStringTest() {
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
    public static void toStringTest2() {
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
    public static void parseIntTest() {
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
