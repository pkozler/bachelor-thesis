package test;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code ScannerTest} class performs automatic testing of the
 * {@code Scanner} class.
 *
 * @author Petr Kozler
 */
public class ScannerTest {

    public static Logger logger = LogManager.getLogger(ScannerTest.class.getName());

    private static final String INITIAL_TEST = "src/main/resources/test.txt";
    private static final String NEXTLINE_TEST = "src/main/resources/nextLineTest.txt";
    private static final String NEXT_TEST = "src/main/resources/nextTest.txt";
    private static final String NEXTBOOLEAN_TEST = "src/main/resources/nextBooleanTest.txt";
    private static final String NEXTBYTE_TEST = "src/main/resources/nextByteTest.txt";
    private static final String NEXTSHORT_TEST = "src/main/resources/nextShortTest.txt";
    private static final String NEXTINT_TEST = "src/main/resources/nextIntTest.txt";
    private static final String NEXTLONG_TEST = "src/main/resources/nextLongTest.txt";
    private static final String NEXTFLOAT_TEST = "src/main/resources/nextFloatTest.txt";
    private static final String NEXTDOUBLE_TEST = "src/main/resources/nextDoubleTest.txt";
    private static final int NEXTLINE_TOKEN_COUNT = 8;
    private static final int NEXT_TOKEN_COUNT = 9;
    private static final int NEXTBOOLEAN_TOKEN_COUNT = 8;
    private static final int NEXTBYTE_TOKEN_COUNT = 10;
    private static final int NEXTSHORT_TOKEN_COUNT = 10;
    private static final int NEXTINT_TOKEN_COUNT = 10;
    private static final int NEXTLONG_TOKEN_COUNT = 10;
    private static final int NEXTFLOAT_TOKEN_COUNT = 30;
    private static final int NEXTDOUBLE_TOKEN_COUNT = 30;

    public static void runTestSuite() {
        ScannerTest.scannerTest();
        ScannerTest.nextTest();
        ScannerTest.nextBooleanTest();
        ScannerTest.nextByteTest();
        ScannerTest.nextShortTest();
        ScannerTest.nextIntTest();
        ScannerTest.nextLongTest();
        ScannerTest.nextFloatTest();
        ScannerTest.nextDoubleTest();
        ScannerTest.nextLineTest();
    }

    /*
     Loads the data from a text file for simulating user input.
     */
    private static void setInput(String testFileName) {
        try {
            String content = new Scanner(new File(testFileName)).useDelimiter("\\Z").next();
            System.setIn(new ByteArrayInputStream(content.getBytes()));
        } catch (FileNotFoundException ex) {
            System.err.println(ex.getMessage());
        }
    }

    /**
     * Tests the constructor.
     */
    public static void scannerTest() {
        setInput(INITIAL_TEST);
        Scanner a;
        String b;
        boolean c;
        long d;
        double e;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);

        // random test of different type values scanning
        b = a.next();
        logger.info(b);
        c = a.nextBoolean();
        logger.info(c);
        d = a.nextByte();
        logger.info(d);
        d = a.nextShort();
        logger.info(d);
        d = a.nextInt();
        logger.info(d);
        d = a.nextLong();
        logger.info(d);
        e = a.nextFloat();
        logger.info(e);
        e = a.nextDouble();
        logger.info(e);
        b = a.nextLine();
        logger.info(b);
    }

    /**
     * Tests the next method.
     */
    public static void nextTest() {
        setInput(NEXT_TEST);
        Scanner a;
        String b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);

        // scanning of strings delimited by different counts of whitespaces
        for (int i = 0; i < NEXT_TOKEN_COUNT; i++) {
            b = a.next();
            logger.info(b);
        }
    }

    /**
     * Tests the nextBoolean method.
     */
    public static void nextBooleanTest() {
        setInput(NEXTBOOLEAN_TEST);
        Scanner a;
        boolean b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);

        // scanning of strings representing boolean values
        for (int i = 0; i < NEXTBOOLEAN_TOKEN_COUNT; i++) {
            b = a.nextBoolean();
            logger.info(b);
        }
    }

    /**
     * Tests the nextByte method.
     */
    public static void nextByteTest() {
        setInput(NEXTBYTE_TEST);
        Scanner a;
        byte b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);

        // scanning of integers (zeroes, ones, positive and negative minimal and maximal values)
        for (int i = 0; i < NEXTBYTE_TOKEN_COUNT; i++) {
            b = a.nextByte();
            logger.info(b);
        }
    }

    /**
     * Tests the nextShort method.
     */
    public static void nextShortTest() {
        setInput(NEXTSHORT_TEST);
        Scanner a;
        short b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);

        for (int i = 0; i < NEXTSHORT_TOKEN_COUNT; i++) {
            b = a.nextShort();
            logger.info(b);
        }
    }

    /**
     * Tests the nextInt method.
     */
    public static void nextIntTest() {
        setInput(NEXTINT_TEST);
        Scanner a;
        int b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);

        for (int i = 0; i < NEXTINT_TOKEN_COUNT; i++) {
            b = a.nextInt();
            logger.info(b);
        }
    }

    /**
     * Tests the nextLong method.
     */
    public static void nextLongTest() {
        setInput(NEXTLONG_TEST);
        Scanner a;
        long b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);

        for (int i = 0; i < NEXTLONG_TOKEN_COUNT; i++) {
            b = a.nextLong();
            logger.info(b);
        }
    }

    /**
     * Tests the nextFloat method.
     */
    public static void nextFloatTest() {
        setInput(NEXTFLOAT_TEST);
        Scanner a;
        float b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);

        /* 
         scanning of decimal values
         (with and without sign and decimal dot and with omission of digits on different positions,
         scanning of zeroes, ones, minimal and maximal absolute values)
         */
        for (int i = 0; i < NEXTFLOAT_TOKEN_COUNT; i++) {
            b = a.nextFloat();
            logger.info(b);
        }
    }

    /**
     * Tests the nextDouble method.
     */
    public static void nextDoubleTest() {
        setInput(NEXTDOUBLE_TEST);
        Scanner a;
        double b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);

        for (int i = 0; i < NEXTDOUBLE_TOKEN_COUNT; i++) {
            b = a.nextDouble();
            logger.info(b);
        }
    }

    /**
     * Tests the nextLine method.
     */
    public static void nextLineTest() {
        setInput(NEXTLINE_TEST);
        Scanner a;
        String b;
        a = new Scanner(System.in);
        a.useLocale(Locale.US);

        // scanning of lines with different types of string
        for (int i = 0; i < NEXTLINE_TOKEN_COUNT; i++) {
            b = a.nextLine();
            logger.info(b);
        }
    }

}
