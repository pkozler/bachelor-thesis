package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code MathTest} class performs automatic testing of the {@code Math}
 * class.
 *
 * @author Petr Kozler
 */
public class MathTest {

    public static Logger logger = LogManager.getLogger(MathTest.class.getName());

    public static void runTestSuite() {
        MathTest.absTestCase();
        MathTest.absTestCase2();
        MathTest.absTestCase3();
        MathTest.absTestCase4();
        MathTest.maxTestCase();
        MathTest.maxTestCase2();
        MathTest.maxTestCase3();
        MathTest.maxTestCase4();
        MathTest.minTestCase();
        MathTest.minTestCase2();
        MathTest.minTestCase3();
        MathTest.minTestCase4();
        MathTest.powTestCase();
        MathTest.sqrtTestCase();
        MathTest.logTestCase();
        MathTest.log10TestCase();
        MathTest.sinTestCase();
        MathTest.cosTestCase();
        MathTest.tanTestCase();
        MathTest.asinTestCase();
        MathTest.acosTestCase();
        MathTest.atanTestCase();
        MathTest.roundTestCase();
        MathTest.roundTestCase2();
    }

    /**
     * Tests the abs method with a double value.
     */
    public static void absTestCase() {
        double a, b;
        // negative value
        a = Double.MIN_VALUE + 1;
        b = Math.abs(a);
        logger.info(b);
        // zero value
        a = 0;
        b = Math.abs(a);
        logger.info(b);
        // positive value
        a = Double.MAX_VALUE - 1;
        b = Math.abs(a);
        logger.info(b);
    }

    /**
     * Tests the abs method with a float value.
     */
    public static void absTestCase2() {
        float a, b;
        a = Float.MIN_VALUE + 1;
        b = Math.abs(a);
        logger.info(b);
        a = 0;
        b = Math.abs(a);
        logger.info(b);
        a = Float.MAX_VALUE - 1;
        b = Math.abs(a);
        logger.info(b);
    }

    /**
     * Tests the abs method with an int value.
     */
    public static void absTestCase3() {
        int a, b;
        a = Integer.MIN_VALUE + 1;
        b = Math.abs(a);
        logger.info(b);
        a = 0;
        b = Math.abs(a);
        logger.info(b);
        a = Integer.MAX_VALUE - 1;
        b = Math.abs(a);
        logger.info(b);
    }

    /**
     * Tests the abs method with a long value.
     */
    public static void absTestCase4() {
        long a, b;
        a = Long.MIN_VALUE + 1;
        b = Math.abs(a);
        logger.info(b);
        a = 0;
        b = Math.abs(a);
        logger.info(b);
        a = Long.MAX_VALUE - 1;
        b = Math.abs(a);
        logger.info(b);
    }

    /**
     * Tests the max method with a double value.
     */
    public static void maxTestCase() {
        double a, b, c;
        // negative and positive value
        a = Double.MIN_VALUE;
        b = Double.MAX_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        // positive and negative value
        a = Double.MAX_VALUE;
        b = Double.MIN_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        // negative and positive value (smaller difference)
        a = -1;
        b = 1;
        c = Math.max(a, b);
        logger.info(c);
        // positive and negative value (bigger difference)
        a = 1;
        b = -1;
        c = Math.max(a, b);
        // equal values
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.max(a, b);
        logger.info(c);
    }

    /**
     * Tests the max method with a float value.
     */
    public static void maxTestCase2() {
        float a, b, c;
        a = Float.MIN_VALUE;
        b = Float.MAX_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = Float.MAX_VALUE;
        b = Float.MIN_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.max(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.max(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.max(a, b);
        logger.info(c);
    }

    /**
     * Tests the max method with an int value.
     */
    public static void maxTestCase3() {
        int a, b, c;
        a = Integer.MIN_VALUE;
        b = Integer.MAX_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = Integer.MAX_VALUE;
        b = Integer.MIN_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.max(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.max(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.max(a, b);
        logger.info(c);
    }

    /**
     * Tests the max method with a long value.
     */
    public static void maxTestCase4() {
        long a, b, c;
        a = Long.MIN_VALUE;
        b = Long.MAX_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = Long.MAX_VALUE;
        b = Long.MIN_VALUE;
        c = Math.max(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.max(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.max(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.max(a, b);
        logger.info(c);
    }

    /**
     * Tests the min method with a double value.
     */
    public static void minTestCase() {
        double a, b, c;
        a = Double.MIN_VALUE;
        b = Double.MAX_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = Double.MAX_VALUE;
        b = Double.MIN_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.min(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.min(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.min(a, b);
        logger.info(c);
    }

    /**
     * Tests the min method with a float value.
     */
    public static void minTestCase2() {
        float a, b, c;
        a = Float.MIN_VALUE;
        b = Float.MAX_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = Float.MAX_VALUE;
        b = Float.MIN_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.min(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.min(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.min(a, b);
        logger.info(c);
    }

    /**
     * Tests the min method with an int value.
     */
    public static void minTestCase3() {
        int a, b, c;
        a = Integer.MIN_VALUE;
        b = Integer.MAX_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = Integer.MAX_VALUE;
        b = Integer.MIN_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.min(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.min(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.min(a, b);
        logger.info(c);
    }

    /**
     * Tests the min method with a long value.
     */
    public static void minTestCase4() {
        long a, b, c;
        a = Long.MIN_VALUE;
        b = Long.MAX_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = Long.MAX_VALUE;
        b = Long.MIN_VALUE;
        c = Math.min(a, b);
        logger.info(c);
        a = -1;
        b = 1;
        c = Math.min(a, b);
        logger.info(c);
        a = 1;
        b = -1;
        c = Math.min(a, b);
        logger.info(c);
        a = 0;
        b = 0;
        c = Math.min(a, b);
        logger.info(c);
    }

    /**
     * Test the pow method.
     */
    public static void powTestCase() {
        double a, b, c;
        // positive power of positive value
        a = 10;
        b = 2;
        c = Math.pow(a, b);
        logger.info(c);
        // positive power of negative value
        a = -10;
        b = 2;
        c = Math.pow(a, b);
        logger.info(c);
        // negative power of positive value
        a = 10;
        b = -2;
        c = Math.pow(a, b);
        // zore power
        logger.info(c);
        a = 10;
        b = 0;
        c = Math.pow(a, b);
        logger.info(c);
        // power of zero
        a = 0;
        b = 10;
        c = Math.pow(a, b);
        logger.info(c);
    }

    /**
     * Tests the sqrt method.
     */
    public static void sqrtTestCase() {
        double a, b;
        // square root of bigger value
        a = 100;
        b = Math.sqrt(a);
        logger.info(b);
        // square root of one
        a = 1;
        b = Math.sqrt(a);
        logger.info(b);
        // square root of zero
        a = 0;
        b = Math.sqrt(a);
        logger.info(b);
    }

    /**
     * Tests the log method.
     */
    public static void logTestCase() {
        double a, b;
        // logarithm of the square of E
        a = Math.E * Math.E;
        b = Math.log(a);
        logger.info(b);
        // logarithm of E
        a = Math.E;
        b = Math.log(a);
        logger.info(b);
        // logarithm of one
        a = 1;
        b = Math.log(a);
        logger.info(b);
    }

    /**
     * Tests the log10 method.
     */
    public static void log10TestCase() {
        double a, b;
        // logarithm of the square of ten
        a = 100;
        b = Math.log10(a);
        logger.info(b);
        // logarithm of ten
        a = 10;
        b = Math.log10(a);
        logger.info(b);
        // logarithm of one
        a = 1;
        b = Math.log10(a);
        logger.info(b);
    }

    /**
     * Tests the sin method.
     */
    public static void sinTestCase() {
        double a, b;
        // sine of PI
        a = Math.PI;
        b = Math.sin(a);
        logger.info(b);
        // sine of minus PI
        a = -Math.PI;
        b = Math.sin(a);
        logger.info(b);
        // sine of zero
        a = 0;
        b = Math.sin(a);
        logger.info(b);
    }

    /**
     * Tests the cos method.
     */
    public static void cosTestCase() {
        double a, b;
        // cosine of PI
        a = Math.PI;
        b = Math.cos(a);
        logger.info(b);
        // cosine of minus PI
        a = -Math.PI;
        b = Math.cos(a);
        logger.info(b);
        // cosine of zero
        a = 0;
        b = Math.cos(a);
        logger.info(b);
    }

    /**
     * Tests the tan method.
     */
    public static void tanTestCase() {
        double a, b;
        // tangent of PI
        a = Math.PI;
        b = Math.tan(a);
        logger.info(b);
        // tangent of minus PI
        a = -Math.PI;
        b = Math.tan(a);
        logger.info(b);
        // tangent of zero
        a = 0;
        b = Math.tan(a);
        logger.info(b);
    }

    /**
     * Tests the asin method.
     */
    public static void asinTestCase() {
        double a, b;
        // arcsine of one
        a = 1;
        b = Math.asin(a);
        logger.info(b);
        // arcsine of minus one
        a = -1;
        b = Math.asin(a);
        logger.info(b);
        // arcsine of zero
        a = 0;
        b = Math.asin(a);
        logger.info(b);
    }

    /**
     * Tests the acos method.
     */
    public static void acosTestCase() {
        double a, b;
        // arccosine of one
        a = 1;
        b = Math.acos(a);
        logger.info(b);
        // arccosine of minus one
        a = -1;
        b = Math.acos(a);
        logger.info(b);
        // arccosine of zero
        a = 0;
        b = Math.acos(a);
        logger.info(b);
    }

    /**
     * Tests the atan method.
     */
    public static void atanTestCase() {
        double a, b;
        // arctangent of one
        a = 1;
        b = Math.atan(a);
        logger.info(b);
        // arctangent of minus one
        a = -1;
        b = Math.atan(a);
        logger.info(b);
        // arctangent of zero
        a = 0;
        b = Math.atan(a);
        logger.info(b);
    }

    /**
     * Tests the round method with a double value.
     */
    public static void roundTestCase() {
        double a, b;
        // rounding to even value
        a = 1.5;
        b = Math.round(a);
        logger.info(b);
        // rounding to odd value
        a = 0.5;
        b = Math.round(a);
        logger.info(b);
        // rounding of negative value
        a = -0.5;
        b = Math.round(a);
        logger.info(b);
    }

    /**
     * Tests the round method with a float value.
     */
    public static void roundTestCase2() {
        float a, b;
        a = 1.5f;
        b = Math.round(a);
        logger.info(b);
        a = 0.5f;
        b = Math.round(a);
        logger.info(b);
        a = -0.5f;
        b = Math.round(a);
        logger.info(b);
    }

}
