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
        MathTest.absTest();
        MathTest.absTest2();
        MathTest.absTest3();
        MathTest.absTest4();
        MathTest.maxTest();
        MathTest.maxTest2();
        MathTest.maxTest3();
        MathTest.maxTest4();
        MathTest.minTest();
        MathTest.minTest2();
        MathTest.minTest3();
        MathTest.minTest4();
        MathTest.powTest();
        MathTest.sqrtTest();
        MathTest.logTest();
        MathTest.log10Test();
        MathTest.sinTest();
        MathTest.cosTest();
        MathTest.tanTest();
        MathTest.asinTest();
        MathTest.acosTest();
        MathTest.atanTest();
        MathTest.roundTest();
        MathTest.roundTest2();
    }

    /**
     * Tests the abs method with a double value.
     */
    public static void absTest() {
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
    public static void absTest2() {
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
    public static void absTest3() {
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
    public static void absTest4() {
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
    public static void maxTest() {
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
    public static void maxTest2() {
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
    public static void maxTest3() {
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
    public static void maxTest4() {
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
    public static void minTest() {
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
    public static void minTest2() {
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
    public static void minTest3() {
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
    public static void minTest4() {
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
    public static void powTest() {
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
    public static void sqrtTest() {
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
    public static void logTest() {
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
    public static void log10Test() {
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
    public static void sinTest() {
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
    public static void cosTest() {
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
    public static void tanTest() {
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
    public static void asinTest() {
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
    public static void acosTest() {
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
    public static void atanTest() {
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
    public static void roundTest() {
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
    public static void roundTest2() {
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
