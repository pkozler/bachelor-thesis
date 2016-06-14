package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code LongTest} class performs automatic testing of the {@code Long}
 * class.
 *
 * @author Petr Kozler
 */
public class LongTest {

    public static Logger logger = LogManager.getLogger(LongTest.class.getName());

    public static void runTestSuite() {
        LongTest.longValueTest();
        LongTest.compareToTest();
        LongTest.compareTest();
        LongTest.equalsTest();
        LongTest.toStringTest();
        LongTest.toStringTest2();
        LongTest.parseLongTest();
    }

    /**
     * Tests the longValue method.
     */
    public static void longValueTest() {
        Long a;
        long b;
        a = new Long(Long.MIN_VALUE);
        b = a.longValue();
        logger.info(b);
        a = new Long((long) 0);
        b = a.longValue();
        logger.info(b);
        a = new Long(Long.MAX_VALUE);
        b = a.longValue();
        logger.info(b);
    }

    /**
     * Tests the compareTo method.
     */
    public static void compareToTest() {
        Long a, b;
        int c;
        a = new Long(Long.MIN_VALUE);
        b = new Long((long) -1);
        c = Long.compare(a, b);
        logger.info(c);
        a = new Long(Long.MAX_VALUE);
        b = new Long((long) 1);
        c = Long.compare(a, b);
        logger.info(c);
        a = new Long((long) 0);
        b = new Long((long) 1);
        c = Long.compare(a, b);
        logger.info(c);
        a = new Long((long) 0);
        b = new Long((long) -1);
        c = Long.compare(a, b);
        logger.info(c);
        a = new Long((long) 1);
        b = new Long((long) 1);
        c = Long.compare(a, b);
        logger.info(c);
        a = new Long((long) -1);
        b = new Long((long) -1);
        c = Long.compare(a, b);
        logger.info(c);
    }

    /**
     * Tests the compare method.
     */
    public static void compareTest() {
        long a, b;
        int c;
        a = Long.MIN_VALUE;
        b = (long) -1;
        c = Long.compare(a, b);
        logger.info(c);
        a = Long.MAX_VALUE;
        b = (long) 1;
        c = Long.compare(a, b);
        logger.info(c);
        a = (long) 0;
        b = (long) 1;
        c = Long.compare(a, b);
        logger.info(c);
        a = (long) 0;
        b = (long) -1;
        c = Long.compare(a, b);
        logger.info(c);
        a = (long) 1;
        b = (long) 1;
        c = Long.compare(a, b);
        logger.info(c);
        a = (long) -1;
        b = (long) -1;
        c = Long.compare(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method.
     */
    public static void equalsTest() {
        Long a, b;
        boolean c;
        a = new Long(Long.MIN_VALUE);
        b = new Long((long) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Long(Long.MAX_VALUE);
        b = new Long((long) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Long((long) 0);
        b = new Long((long) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Long((long) 0);
        b = new Long((long) -1);
        c = a.equals(b);
        logger.info(c);
        a = new Long((long) 1);
        b = new Long((long) 1);
        c = a.equals(b);
        logger.info(c);
        a = new Long((long) -1);
        b = new Long((long) -1);
        c = a.equals(b);
        logger.info(c);
    }

    /**
     * Tests the toString method.
     */
    public static void toStringTest() {
        Long a;
        String b;
        a = new Long((long) 10000000000L);
        b = a.toString();
        logger.info(b);
        a = new Long((long) 0);
        b = a.toString();
        logger.info(b);
        a = new Long((long) -10000000000L);
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the static toString method.
     */
    public static void toStringTest2() {
        Long a;
        String b;
        a = new Long((long) 10000000000L);
        b = Long.toString(a);
        logger.info(b);
        a = new Long((long) 0);
        b = Long.toString(a);
        logger.info(b);
        a = new Long((long) -10000000000L);
        b = Long.toString(a);
        logger.info(b);
    }

    /**
     * Tests the parseLong method.
     */
    public static void parseLongTest() {
        Long a;
        long b;
        a = Long.parseLong("10000000000");
        b = a.longValue();
        logger.info(b);
        a = Long.parseLong("0");
        b = a.longValue();
        logger.info(b);
        a = Long.parseLong("-10000000000");
        b = a.longValue();
        logger.info(b);
    }

}