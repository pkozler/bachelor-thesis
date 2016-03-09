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
    }

    /**
     * Tests the print method with a boolean value.
     */
    public static void printTest() {
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
    public static void printTest2() {
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
    public static void printTest3() {
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
    public static void printTest4() {
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
    public static void printTest5() {
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
    public static void printTest6() {
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
    public static void printTest7() {
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
    public static void printTest8() {
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
    public static void printTest9() {
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
    public static void printlnTest() {
        // print of an empty line
        System.out.println();
    }

    /**
     * Tests the println method with a boolean value.
     */
    public static void printlnTest2() {
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
    public static void printlnTest3() {
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
    public static void printlnTest4() {
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
    public static void printlnTest5() {
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
    public static void printlnTest6() {
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
    public static void printlnTest7() {
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
    public static void printlnTest8() {
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
    public static void printlnTest9() {
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
    public static void printlnTest10() {
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
