package test;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code PrintStreamTest} class performs automatic testing of the
 * {@code PrintStream} class.
 *
 * @author Petr Kozler
 */
public class PrintStreamTest {

    public static Logger logger = LogManager.getLogger(PrintStreamTest.class.getName());
    private static File stdoutFile = new File("logs/PrintStream_STDOUT.txt");
    private static PrintStream System_out;

    public static void runTestSuite() throws FileNotFoundException {
        System_out = new PrintStream(stdoutFile);

        PrintStreamTest.printTest();
        PrintStreamTest.printTest2();
        PrintStreamTest.printTest3();
        PrintStreamTest.printTest4();
        PrintStreamTest.printTest5();
        PrintStreamTest.printTest6();
        PrintStreamTest.printTest7();
        PrintStreamTest.printTest8();
        PrintStreamTest.printTest9();
        PrintStreamTest.printlnTest();
        PrintStreamTest.printlnTest2();
        PrintStreamTest.printlnTest3();
        PrintStreamTest.printlnTest4();
        PrintStreamTest.printlnTest5();
        PrintStreamTest.printlnTest6();
        PrintStreamTest.printlnTest7();
        PrintStreamTest.printlnTest8();
        PrintStreamTest.printlnTest9();
        PrintStreamTest.printlnTest10();

        System_out.close();

        concatFiles();
    }

    private static void concatFiles() {
        try {
            File logFile = new File("logs/PrintStreamTest.txt");

            Scanner sc = new Scanner(logFile);
            ArrayList logLines = new ArrayList();

            while (sc.hasNextLine()) {
                logLines.add(sc.nextLine());
                sc.nextLine();
            }

            sc.close();

            sc = new Scanner(stdoutFile);
            ArrayList stdoutLines = new ArrayList();

            while (sc.hasNextLine()) {
                stdoutLines.add(sc.nextLine());
            }

            sc.close();

            File resultFile = new File("logs/SystemTest.txt");
            System_out = new PrintStream(resultFile);

            for (int i = 0; i < stdoutLines.size(); i++) {
                System_out.println(logLines.get(i));
                System_out.println(stdoutLines.get(i));
            }

            System_out.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    /**
     * Tests the print method with a boolean value.
     */
    public static void printTest() {
        boolean a;
        // print of boolean values
        a = true;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = false;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
    }

    /**
     * Tests the print method with a char value.
     */
    public static void printTest2() {
        char a;
        // print of lowercase letters
        a = 'a';
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = 'z';
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // print of uppercase letters
        a = 'A';
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = 'Z';
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // print of digits
        a = '0';
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = '9';
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
    }

    /**
     * Tests the print method with array of chars.
     */
    public static void printTest3() {
        char[] a;
        // empty char array
        a = new char[]{};
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // char array with one char
        a = new char[]{'a'};
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // char array with some chars
        a = new char[]{'a', 'z', 'A', 'Z', '0', '9'};
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
    }

    /**
     * Tests the print method with a double value.
     */
    public static void printTest4() {
        double a;
        // zeros with and without sign
        a = 0;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = -0;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // ones with and without sign
        a = 1;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = -1;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // maximal absolute value with and without sign
        a = Double.MAX_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = -Double.MAX_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // minimal absolute value with and without sign
        a = Double.MIN_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = -Double.MIN_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
    }

    /**
     * Tests the print method with a float value.
     */
    public static void printTest5() {
        float a;
        a = 0;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = -0;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = 1;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = -1;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = Float.MAX_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = -Float.MAX_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = Float.MIN_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = -Float.MIN_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
    }

    /**
     * Tests the print method with an int value.
     */
    public static void printTest6() {
        int a;
        // zero
        a = 0;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // ones with and without sign
        a = 1;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = -1;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // maximal and minimal value
        a = Integer.MAX_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = Integer.MIN_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
    }

    /**
     * Tests the print method with a long value.
     */
    public static void printTest7() {
        long a;
        a = 0;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = 1;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = -1;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = Long.MAX_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = Long.MIN_VALUE;
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
    }

    /**
     * Tests the print method with an object.
     */
    public static void printTest8() {
        TestObject a;
        // object with an empty string
        a = new TestObject("", 0);
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // object with digits
        a = new TestObject("0", 1);
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = new TestObject("9", -1);
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // object with letters
        a = new TestObject("Aa", Integer.MAX_VALUE);
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        a = new TestObject("Zz", Integer.MIN_VALUE);
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
    }

    /**
     * Tests the print method with a string.
     */
    public static void printTest9() {
        String a;
        // empty string
        a = "";
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // string with one char
        a = "a";
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
        // string with some chars
        a = "azAZ09";
        logger.info("");
        System_out.print(a);
        System_out.print("\n");
    }

    /**
     * Tests the println method.
     */
    public static void printlnTest() {
        // print of an empty line 
        logger.info("");
        System_out.println();
    }

    /**
     * Tests the println method with a boolean value.
     */
    public static void printlnTest2() {
        boolean a;
        a = true;
        logger.info("");
        System_out.println(a);
        a = false;
        logger.info("");
        System_out.println(a);
    }

    /**
     * Tests the println method with a char value.
     */
    public static void printlnTest3() {
        char a;
        a = 'a';
        logger.info("");
        System_out.println(a);
        a = 'z';
        logger.info("");
        System_out.println(a);
        a = 'A';
        logger.info("");
        System_out.println(a);
        a = 'Z';
        logger.info("");
        System_out.println(a);
        a = '0';
        logger.info("");
        System_out.println(a);
        a = '9';
        logger.info("");
        System_out.println(a);
    }

    /**
     * Tests the println method with array of chars.
     */
    public static void printlnTest4() {
        char[] a;
        a = new char[]{};
        logger.info("");
        System_out.println(a);
        a = new char[]{'a'};
        logger.info("");
        System_out.println(a);
        a = new char[]{'a', 'z', 'A', 'Z', '0', '9'};
        logger.info("");
        System_out.println(a);
    }

    /**
     * Tests the println method with a double value.
     */
    public static void printlnTest5() {
        double a;
        a = 0;
        logger.info("");
        System_out.println(a);
        a = -0;
        logger.info("");
        System_out.println(a);
        a = 1;
        logger.info("");
        System_out.println(a);
        a = -1;
        logger.info("");
        System_out.println(a);
        a = Double.MAX_VALUE;
        logger.info("");
        System_out.println(a);
        a = -Double.MAX_VALUE;
        logger.info("");
        System_out.println(a);
        a = Double.MIN_VALUE;
        logger.info("");
        System_out.println(a);
        a = -Double.MIN_VALUE;
        logger.info("");
        System_out.println(a);
    }

    /**
     * Tests the println method with a float value.
     */
    public static void printlnTest6() {
        float a;
        a = 0;
        logger.info("");
        System_out.println(a);
        a = -0;
        logger.info("");
        System_out.println(a);
        a = 1;
        logger.info("");
        System_out.println(a);
        a = -1;
        logger.info("");
        System_out.println(a);
        a = Float.MAX_VALUE;
        logger.info("");
        System_out.println(a);
        a = -Float.MAX_VALUE;
        logger.info("");
        System_out.println(a);
        a = Float.MIN_VALUE;
        logger.info("");
        System_out.println(a);
        a = -Float.MIN_VALUE;
        logger.info("");
        System_out.println(a);
    }

    /**
     * Tests the println method with an int value.
     */
    public static void printlnTest7() {
        int a;
        a = 0;
        logger.info("");
        System_out.println(a);
        a = 1;
        logger.info("");
        System_out.println(a);
        a = -1;
        logger.info("");
        System_out.println(a);
        a = Integer.MAX_VALUE;
        logger.info("");
        System_out.println(a);
        a = Integer.MIN_VALUE;
        logger.info("");
        System_out.println(a);
    }

    /**
     * Tests the println method with a long value.
     */
    public static void printlnTest8() {
        long a;
        a = 0;
        logger.info("");
        System_out.println(a);
        a = 1;
        logger.info("");
        System_out.println(a);
        a = -1;
        logger.info("");
        System_out.println(a);
        a = Long.MAX_VALUE;
        logger.info("");
        System_out.println(a);
        a = Long.MIN_VALUE;
        logger.info("");
        System_out.println(a);
    }

    /**
     * Tests the println method with an object.
     */
    public static void printlnTest9() {
        TestObject a;
        a = new TestObject("", 0);
        logger.info("");
        System_out.println(a);
        a = new TestObject("0", 1);
        logger.info("");
        System_out.println(a);
        a = new TestObject("9", -1);
        logger.info("");
        System_out.println(a);
        a = new TestObject("Aa", Integer.MAX_VALUE);
        logger.info("");
        System_out.println(a);
        a = new TestObject("Zz", Integer.MIN_VALUE);
        logger.info("");
        System_out.println(a);
    }

    /**
     * Tests the println method with a string.
     */
    public static void printlnTest10() {
        String a;
        a = "";
        logger.info("");
        System_out.println(a);
        a = "a";
        logger.info("");
        System_out.println(a);
        a = "azAZ09";
        logger.info("");
        System_out.println(a);
    }
}
