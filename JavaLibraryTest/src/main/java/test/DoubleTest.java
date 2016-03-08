package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code DoubleTest} class performs automatic testing of the {@code Double}
 * class.
 *
 * @author Petr Kozler
 */
public class DoubleTest {

    public static Logger logger = LogManager.getLogger(DoubleTest.class.getName());

    public static void runTestSuite() {
        DoubleTest.doubleValueTestCase();
        DoubleTest.compareToTestCase();
        DoubleTest.compareTestCase();
        DoubleTest.equalsTestCase();
        DoubleTest.toStringTestCase();
        DoubleTest.toStringTestCase2();
        DoubleTest.parseDoubleTestCase();
    }

    /**
     * Tests the doubleValue method.
     */
    public static void doubleValueTestCase() {
        Double a;
        double b;
        // minimal non-zero absolute value
        a = new Double(Double.MIN_VALUE);
        b = a.doubleValue();
        logger.info(b);
        // zero value
        a = new Double((double) 0);
        b = a.doubleValue();
        logger.info(b);
        // maximal finite absolute value
        a = new Double(Double.MAX_VALUE);
        b = a.doubleValue();
        logger.info(b);
    }

    /**
     * Tests the compareTo method.
     */
    public static void compareToTestCase() {
        Double a, b;
        int c;
        // minimal non-zero absolute value and bigger fractional value
        a = new Double(Double.MIN_VALUE);
        b = new Double((double) 0.1);
        c = a.compareTo(b);
        logger.info(c);
        // maximal finite absolute value and smaller integer value
        a = new Double(Double.MAX_VALUE);
        b = new Double((double) 1);
        c = a.compareTo(b);
        logger.info(c);
        // zero and positive value
        a = new Double((double) 0);
        b = new Double((double) 1);
        c = a.compareTo(b);
        logger.info(c);
        // zero and negative value
        a = new Double((double) 0);
        b = new Double((double) -1);
        c = a.compareTo(b);
        logger.info(c);
        // both values are positive
        a = new Double((double) 1);
        b = new Double((double) 1);
        c = a.compareTo(b);
        logger.info(c);
        // both values are negative
        a = new Double((double) -1);
        b = new Double((double) -1);
        c = a.compareTo(b);
        logger.info(c);
    }

    /**
     * Tests the compare method.
     */
    public static void compareTestCase() {
        double a, b;
        int c;
        a = Double.MIN_VALUE;
        b = (double) 0.1;
        c = Double.compare(a, b);
        logger.info(c);
        a = Double.MAX_VALUE;
        b = (double) 1;
        c = Double.compare(a, b);
        logger.info(c);
        a = (double) 0;
        b = (double) 1;
        c = Double.compare(a, b);
        logger.info(c);
        a = (double) 0;
        b = (double) -1;
        c = Double.compare(a, b);
        logger.info(c);
        a = (double) 1;
        b = (double) 1;
        c = Double.compare(a, b);
        logger.info(c);
        a = (double) -1;
        b = (double) -1;
        c = Double.compare(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method.
     */
    public static void equalsTestCase() {
        Double a, b;
        boolean c;
        a = new Double(Double.MIN_VALUE);
        b = new Double((double) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Double(Double.MAX_VALUE);
        b = new Double((double) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Double((double) 0);
        b = new Double((double) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Double((double) 0);
        b = new Double((double) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Double((double) 1);
        b = new Double((double) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Double((double) -1);
        b = new Double((double) -1);
        c = a.equals(b);
        logger.info(c);
    }

    /**
     * Tests the toString method.
     */
    public static void toStringTestCase() {
        Double a;
        String b;
        // positive value text representation
        a = new Double((double) 0.0000000000000000000000000000000000000000000001);
        b = a.toString();
        logger.info(b);
        // zero value text representation
        a = new Double((double) 0);
        b = a.toString();
        logger.info(b);
        // negative value text representation
        a = new Double((double) -0.0000000000000000000000000000000000000000000001);
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the static toString method.
     */
    public static void toStringTestCase2() {
        Double a;
        String b;
        a = new Double((double) 0.0000000000000000000000000000000000000000000001);
        b = Double.toString(a);
        logger.info(b);
        a = new Double((double) 0);
        b = Double.toString(a);
        logger.info(b);
        a = new Double((double) -0.0000000000000000000000000000000000000000000001);
        b = Double.toString(a);
        logger.info(b);
    }

    /**
     * Tests the parseDouble method.
     */
    public static void parseDoubleTestCase() {
        Double a;
        double b;
        // positive value parsing
        a = Double.parseDouble("0.0000000000000000000000000000000000000000000001");
        b = a.doubleValue();
        logger.info(b);
        // zero value parsing
        a = Double.parseDouble("0");
        b = a.doubleValue();
        logger.info(b);
        // negative value parsing
        a = Double.parseDouble("-0.0000000000000000000000000000000000000000000001");
        b = a.doubleValue();
        logger.info(b);
    }

}
