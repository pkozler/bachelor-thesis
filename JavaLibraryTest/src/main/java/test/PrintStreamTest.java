package test;

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

    public static void runTestSuite() {
        PrintStreamTest.printTestCase();
        PrintStreamTest.printTestCase2();
        PrintStreamTest.printTestCase3();
        PrintStreamTest.printTestCase4();
        PrintStreamTest.printTestCase5();
        PrintStreamTest.printTestCase6();
        PrintStreamTest.printTestCase7();
        PrintStreamTest.printTestCase8();
        PrintStreamTest.printTestCase9();
        PrintStreamTest.printlnTestCase();
        PrintStreamTest.printlnTestCase2();
        PrintStreamTest.printlnTestCase3();
        PrintStreamTest.printlnTestCase4();
        PrintStreamTest.printlnTestCase5();
        PrintStreamTest.printlnTestCase6();
        PrintStreamTest.printlnTestCase7();
        PrintStreamTest.printlnTestCase8();
        PrintStreamTest.printlnTestCase9();
        PrintStreamTest.printlnTestCase10();
    }

    /**
     * Tests the print method with a boolean value.
     */
    public static void printTestCase() {
        boolean a;
        // print of boolean values
        a = true;
        System.out.print(a);
        System.out.println();
        a = false;
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the print method with a char value.
     */
    public static void printTestCase2() {
        char a;
        // print of lowercase letters
        a = 'a';
        System.out.print(a);
        System.out.println();
        a = 'z';
        System.out.print(a);
        System.out.println();
        // print of uppercase letters
        a = 'A';
        System.out.print(a);
        System.out.println();
        a = 'Z';
        System.out.print(a);
        System.out.println();
        // print of digits
        a = '0';
        System.out.print(a);
        System.out.println();
        a = '9';
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the print method with array of chars.
     */
    public static void printTestCase3() {
        char[] a;
        // empty char array
        a = new char[]{};
        System.out.print(a);
        System.out.println();
        // char array with one char
        a = new char[]{'a'};
        System.out.print(a);
        System.out.println();
        // char array with some chars
        a = new char[]{'a', 'z', 'A', 'Z', '0', '9'};
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the print method with a double value.
     */
    public static void printTestCase4() {
        double a;
        // zeros with and without sign
        a = 0;
        System.out.print(a);
        System.out.println();
        a = -0;
        System.out.print(a);
        System.out.println();
        // ones with and without sign
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        // maximal absolute value with and without sign
        a = Double.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Double.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        // minimal absolute value with and without sign
        a = Double.MIN_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Double.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the print method with a float value.
     */
    public static void printTestCase5() {
        float a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = -0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Float.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Float.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Float.MIN_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Float.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the print method with an int value.
     */
    public static void printTestCase6() {
        int a;
        // zero
        a = 0;
        System.out.print(a);
        System.out.println();
        // ones with and without sign
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        // maximal and minimal value
        a = Integer.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Integer.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the print method with a long value.
     */
    public static void printTestCase7() {
        long a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Long.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Long.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the print method with an object.
     */
    public static void printTestCase8() {
        DummyObject a;
        // object with an empty string
        a = new DummyObject("", 0);
        System.out.print(a);
        System.out.println();
        // object with digits
        a = new DummyObject("0", 1);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("9", -1);
        System.out.print(a);
        System.out.println();
        // object with letters
        a = new DummyObject("Aa", Integer.MAX_VALUE);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("Zz", Integer.MIN_VALUE);
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the print method with a string.
     */
    public static void printTestCase9() {
        String a;
        // empty string
        a = "";
        System.out.print(a);
        System.out.println();
        // string with one char
        a = "a";
        System.out.print(a);
        System.out.println();
        // string with some chars
        a = "azAZ09";
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the println method.
     */
    public static void printlnTestCase() {
        // print of an empty line
        System.out.println();
    }

    /**
     * Tests the println method with a boolean value.
     */
    public static void printlnTestCase2() {
        boolean a;
        a = true;
        System.out.print(a);
        System.out.println();
        a = false;
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the println method with a char value.
     */
    public static void printlnTestCase3() {
        char a;
        a = 'a';
        System.out.print(a);
        System.out.println();
        a = 'z';
        System.out.print(a);
        System.out.println();
        a = 'A';
        System.out.print(a);
        System.out.println();
        a = 'Z';
        System.out.print(a);
        System.out.println();
        a = '0';
        System.out.print(a);
        System.out.println();
        a = '9';
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the println method with array of chars.
     */
    public static void printlnTestCase4() {
        char[] a;
        a = new char[]{};
        System.out.print(a);
        System.out.println();
        a = new char[]{'a'};
        System.out.print(a);
        System.out.println();
        a = new char[]{'a', 'z', 'A', 'Z', '0', '9'};
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the println method with a double value.
     */
    public static void printlnTestCase5() {
        double a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = -0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Double.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Double.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Double.MIN_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Double.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the println method with a float value.
     */
    public static void printlnTestCase6() {
        float a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = -0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Float.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Float.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Float.MIN_VALUE;
        System.out.print(a);
        System.out.println();
        a = -Float.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the println method with an int value.
     */
    public static void printlnTestCase7() {
        int a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Integer.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Integer.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the println method with a long value.
     */
    public static void printlnTestCase8() {
        long a;
        a = 0;
        System.out.print(a);
        System.out.println();
        a = 1;
        System.out.print(a);
        System.out.println();
        a = -1;
        System.out.print(a);
        System.out.println();
        a = Long.MAX_VALUE;
        System.out.print(a);
        System.out.println();
        a = Long.MIN_VALUE;
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the println method with an object.
     */
    public static void printlnTestCase9() {
        DummyObject a;
        a = new DummyObject("", 0);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("0", 1);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("9", -1);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("Aa", Integer.MAX_VALUE);
        System.out.print(a);
        System.out.println();
        a = new DummyObject("Zz", Integer.MIN_VALUE);
        System.out.print(a);
        System.out.println();
    }

    /**
     * Tests the println method with a string.
     */
    public static void printlnTestCase10() {
        String a;
        a = "";
        System.out.print(a);
        System.out.println();
        a = "a";
        System.out.print(a);
        System.out.println();
        a = "azAZ09";
        System.out.print(a);
        System.out.println();
    }

}
