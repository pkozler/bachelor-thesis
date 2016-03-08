package test;

import java.util.Arrays;
import java.util.StringTokenizer;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code StringTokenizerTest} class performs automatic testing of the
 * {@code StringTokenizer} class.
 *
 * @author Petr Kozler
 */
public class StringTokenizerTest {

    public static Logger logger = LogManager.getLogger(StringTokenizerTest.class.getName());

    public static void runTestSuite() {
        StringTokenizerTest.stringTokenizerTestCase();
        StringTokenizerTest.stringTokenizerTestCase2();
        StringTokenizerTest.countTokensTestCase();
        StringTokenizerTest.hasMoreTokensTestCase();
        StringTokenizerTest.nextTokenTestCase();
    }

    /*
     Creates the string representation of the array of tokens which are created
     from tokenized string.
     */
    private static String getStringArray(StringTokenizer a) {
        String[] b;
        int c;
        c = a.countTokens();
        b = new String[c];

        for (int i = 0; i < c; i++) {
            b[i] = a.nextToken();
        }

        return Arrays.toString(b);
    }

    /**
     * Tests the constructor.
     */
    public static void stringTokenizerTestCase() {
        StringTokenizer a;
        String b;
        // whitespaces inside the string
        a = new StringTokenizer("This is a test.");
        b = getStringArray(a);
        logger.info(b);
        // whitespaces inside and outside the string
        a = new StringTokenizer(" This is   a test. ");
        b = getStringArray(a);
        logger.info(b);
        // without whitespaces
        a = new StringTokenizer("This_is_a_test.");
        b = getStringArray(a);
        logger.info(b);
        // one character
        a = new StringTokenizer("_");
        b = getStringArray(a);
        logger.info(b);
        // empty string
        a = new StringTokenizer("");
        b = getStringArray(a);
        logger.info(b);
    }

    /**
     * Tests the constructor with a set of delimiters as a parameter.
     */
    public static void stringTokenizerTestCase2() {
        StringTokenizer a;
        String b;
        // non-white delimiter (non-existent in string)
        a = new StringTokenizer("This is a test.", "_");
        b = getStringArray(a);
        logger.info(b);
        // non-white delimiter (inside the string)
        a = new StringTokenizer("This_is_a_test.", "_");
        b = getStringArray(a);
        logger.info(b);
        // non-white delimiter (also the whitespaces inside the string)
        a = new StringTokenizer("This_is_ a _test.", "_");
        b = getStringArray(a);
        logger.info(b);
        // non-white delimiter (also the whitespaces inside and outside the string)
        a = new StringTokenizer("_This_is___a_test._", "_");
        b = getStringArray(a);
        logger.info(b);
        // more delimiters (existing in the string)
        a = new StringTokenizer("This is_a test.", " _");
        b = getStringArray(a);
        logger.info(b);
        // more delimiters (non-existent in the string)
        a = new StringTokenizer("Thisisatest.", " _");
        b = getStringArray(a);
        logger.info(b);
    }

    /**
     * Tests the countTokens method.
     */
    public static void countTokensTestCase() {
        StringTokenizer a;
        int b;
        // tokenize with whitespaces as delimiters
        a = new StringTokenizer("This is a test.");
        b = a.countTokens();
        logger.info(b);
        // tokenize with whitespaces as delimiters (more whitespaces)
        a = new StringTokenizer(" This is   a test. ");
        b = a.countTokens();
        logger.info(b);
        // tokenize with whitespaces as delimiters (no whitespaces)
        a = new StringTokenizer("This_is_a_test.");
        b = a.countTokens();
        logger.info(b);
        // tokenize with non-white characters as delimiters
        a = new StringTokenizer("This_is_a_test.", "_");
        b = a.countTokens();
        logger.info(b);
        // tokenize an empty string
        a = new StringTokenizer("");
        b = a.countTokens();
        logger.info(b);
    }

    /**
     * Tests the hasMoreTokens method.
     */
    public static void hasMoreTokensTestCase() {
        StringTokenizer a;
        boolean b;
        a = new StringTokenizer("This is a test.");
        b = a.hasMoreTokens();
        logger.info(b);
        a = new StringTokenizer(" This is   a test. ");
        b = a.hasMoreTokens();
        logger.info(b);
        a = new StringTokenizer("This_is_a_test.");
        b = a.hasMoreTokens();
        logger.info(b);
        a = new StringTokenizer("This_is_a_test.", "_");
        b = a.hasMoreTokens();
        logger.info(b);
        a = new StringTokenizer("");
        b = a.hasMoreTokens();
        logger.info(b);
    }

    /**
     * Tests the nextToken method.
     */
    public static void nextTokenTestCase() {
        StringTokenizer a;
        String b;
        // a test string
        a = new StringTokenizer("This is a test.");
        b = a.nextToken();
        logger.info(b);
        b = a.nextToken();
        logger.info(b);
        b = a.nextToken();
        logger.info(b);
        b = a.nextToken();
        logger.info(b);
    }

}
