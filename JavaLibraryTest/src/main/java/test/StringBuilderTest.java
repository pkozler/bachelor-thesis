package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code StringBuilderTest} class performs automatic testing of the
 * {@code StringBuilder} class.
 *
 * @author Petr Kozler
 */
public class StringBuilderTest {

    public static Logger logger = LogManager.getLogger(StringBuilderTest.class.getName());

    public static void runTestSuite() {
        StringBuilderTest.stringBuilderTest();
        StringBuilderTest.appendTest();
        StringBuilderTest.toStringTest();
    }

    /**
     * Tests the constructor.
     */
    public static void stringBuilderTest() {
        StringBuilder a;
        String b;
        // new empty stringbuilder
        a = new StringBuilder();
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the append method.
     */
    public static void appendTest() {
        StringBuilder a;
        String b;
        // appending of empty string
        a = new StringBuilder();
        a.append("");
        b = a.toString();
        logger.info(b);
        // appending of one char
        a = new StringBuilder();
        a.append(".");
        b = a.toString();
        logger.info(b);
        // appending of more chars
        a = new StringBuilder();
        a.append("test");
        b = a.toString();
        logger.info(b);
        // multiple appendings (empty string at the beginning)
        a = new StringBuilder();
        a.append("test");
        a.append(".");
        a.append("");
        b = a.toString();
        logger.info(b);
        // multiple appendings (empty string in the middle)
        a = new StringBuilder();
        a.append(".");
        a.append("");
        a.append("test");
        b = a.toString();
        logger.info(b);
        // multiple appendings (empty string at the end)
        a = new StringBuilder();
        a.append("");
        a.append("test");
        a.append(".");
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the toString method.
     */
    public static void toStringTest() {
        StringBuilder a;
        String b;
        // appending a string at once
        a = new StringBuilder();
        a.append("This is a test");
        b = a.toString();
        logger.info(b);
        // appending a string piecewise
        a = new StringBuilder();
        a.append("This").append(" is").append(" a").append(" test.");
        b = a.toString();
        logger.info(b);
        // appending a string piecewise (more pieces)
        a = new StringBuilder();
        a.append("This").append(" ").append("is").append(" ").append("a").append(" ").append("test").append(".");
        b = a.toString();
        logger.info(b);
    }

}
