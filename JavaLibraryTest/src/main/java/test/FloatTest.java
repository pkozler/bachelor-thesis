package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code FloatTest} class performs automatic testing of the {@code Float}
 * class.
 *
 * @author Petr Kozler
 */
public class FloatTest {

    public static Logger logger = LogManager.getLogger(FloatTest.class.getName());

    public static void runTestSuite() {
        FloatTest.floatValueTestCase();
        FloatTest.compareToTestCase();
        FloatTest.compareTestCase();
        FloatTest.equalsTestCase();
        FloatTest.toStringTestCase();
        FloatTest.toStringTestCase2();
        FloatTest.parseFloatTestCase();
    }

    /**
     * Tests the floatValue method.
     */
    public static void floatValueTestCase() {
        Float a;
        float b;
        a = new Float(Float.MIN_VALUE);
        b = a.floatValue();
        logger.info(b);
        a = new Float((float) 0);
        b = a.floatValue();
        logger.info(b);
        a = new Float(Float.MAX_VALUE);
        b = a.floatValue();
        logger.info(b);
    }

    /**
     * Tests the compareTo method.
     */
    public static void compareToTestCase() {
        Float a, b;
        int c;
        a = new Float(Float.MIN_VALUE);
        b = new Float((float) -1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Float(Float.MAX_VALUE);
        b = new Float((float) 1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Float((float) 0);
        b = new Float((float) 1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Float((float) 0);
        b = new Float((float) -1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Float((float) 1);
        b = new Float((float) 1);
        c = a.compareTo(b);
        logger.info(c);
        a = new Float((float) -1);
        b = new Float((float) -1);
        c = a.compareTo(b);
        logger.info(c);
    }

    /**
     * Tests the compare method.
     */
    public static void compareTestCase() {
        float a, b;
        int c;
        a = Float.MIN_VALUE;
        b = (float) -1;
        c = Float.compare(a, b);
        logger.info(c);
        a = Float.MAX_VALUE;
        b = (float) 1;
        c = Float.compare(a, b);
        logger.info(c);
        a = (float) 0;
        b = (float) 1;
        c = Float.compare(a, b);
        logger.info(c);
        a = (float) 0;
        b = (float) -1;
        c = Float.compare(a, b);
        logger.info(c);
        a = (float) 1;
        b = (float) 1;
        c = Float.compare(a, b);
        logger.info(c);
        a = (float) -1;
        b = (float) -1;
        c = Float.compare(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method.
     */
    public static void equalsTestCase() {
        Float a, b;
        boolean c;
        a = new Float(Float.MIN_VALUE);
        b = new Float((float) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Float(Float.MAX_VALUE);
        b = new Float((float) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Float((float) 0);
        b = new Float((float) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Float((float) 0);
        b = new Float((float) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Float((float) 1);
        b = new Float((float) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Float((float) -1);
        b = new Float((float) -1);
        c = a.equals(b);
        logger.info(c);
    }

    /**
     * Tests the toString method.
     */
    public static void toStringTestCase() {
        Float a;
        String b;
        a = new Float((float) 0.1);
        b = a.toString();
        logger.info(b);
        a = new Float((float) 0);
        b = a.toString();
        logger.info(b);
        a = new Float((float) -0.1);
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the static toString method.
     */
    public static void toStringTestCase2() {
        Float a;
        String b;
        a = new Float((float) 0.1);
        b = Float.toString(a);
        logger.info(b);
        a = new Float((float) 0);
        b = Float.toString(a);
        logger.info(b);
        a = new Float((float) -0.1);
        b = Float.toString(a);
        logger.info(b);
    }

    /**
     * Tests the parseFloat method.
     */
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
