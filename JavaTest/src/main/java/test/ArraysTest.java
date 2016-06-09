package test;

import java.util.Arrays;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code ArraysTest} class performs automatic testing of the {@code Arrays}
 * class.
 *
 * @author Petr Kozler
 */
public class ArraysTest {

    public static Logger logger = LogManager.getLogger(ArraysTest.class.getName());

    public static void runTestSuite() {
//        ArraysTest.binarySearchTest();
//        ArraysTest.binarySearchTest2();
//        ArraysTest.binarySearchTest3();
//        ArraysTest.binarySearchTest4();
//        ArraysTest.binarySearchTest5();
//        ArraysTest.binarySearchTest6();
//        ArraysTest.binarySearchTest7();
//        ArraysTest.binarySearchTest8();
//        ArraysTest.binarySearchTest9();
//        ArraysTest.binarySearchTest10();
//        ArraysTest.binarySearchTest11();
//        ArraysTest.binarySearchTest12();
//        ArraysTest.binarySearchTest13();
//        ArraysTest.binarySearchTest14();
//        ArraysTest.binarySearchTest15();
//        ArraysTest.binarySearchTest16();
//        ArraysTest.binarySearchTest17();
//        ArraysTest.binarySearchTest18();
//        ArraysTest.copyOfTest();
//        ArraysTest.copyOfTest2();
//        ArraysTest.copyOfTest3();
//        ArraysTest.copyOfTest4();
//        ArraysTest.copyOfTest5();
//        ArraysTest.copyOfTest6();
//        ArraysTest.copyOfTest7();
//        ArraysTest.copyOfTest8();
//        ArraysTest.copyOfTest9();
//        ArraysTest.copyOfRangeTest1();
//        ArraysTest.copyOfRangeTest2();
//        ArraysTest.copyOfRangeTest3();
//        ArraysTest.copyOfRangeTest4();
//        ArraysTest.copyOfRangeTest5();
//        ArraysTest.copyOfRangeTest6();
//        ArraysTest.copyOfRangeTest7();
//        ArraysTest.copyOfRangeTest8();
//        ArraysTest.copyOfRangeTest9();
//        ArraysTest.equalsTest();
//        ArraysTest.equalsTest2();
//        ArraysTest.equalsTest3();
//        ArraysTest.equalsTest4();
//        ArraysTest.equalsTest5();
//        ArraysTest.equalsTest6();
//        ArraysTest.equalsTest7();
        ArraysTest.equalsTest8();
//        ArraysTest.equalsTest9();
//        ArraysTest.fillTest();
//        ArraysTest.fillTest2();
//        ArraysTest.fillTest3();
//        ArraysTest.fillTest4();
//        ArraysTest.fillTest5();
//        ArraysTest.fillTest6();
//        ArraysTest.fillTest7();
//        ArraysTest.fillTest8();
//        ArraysTest.fillTest9();
//        ArraysTest.fillTest10();
//        ArraysTest.fillTest11();
//        ArraysTest.fillTest12();
//        ArraysTest.fillTest13();
//        ArraysTest.fillTest14();
//        ArraysTest.fillTest15();
//        ArraysTest.fillTest16();
//        ArraysTest.fillTest17();
//        ArraysTest.fillTest18();
//        ArraysTest.sortTest();
//        ArraysTest.sortTest2();
//        ArraysTest.sortTest3();
//        ArraysTest.sortTest4();
//        ArraysTest.sortTest5();
//        ArraysTest.sortTest6();
//        ArraysTest.sortTest7();
//        ArraysTest.sortTest8();
//        ArraysTest.sortTest9();
//        ArraysTest.sortTest10();
//        ArraysTest.sortTest11();
//        ArraysTest.sortTest12();
//        ArraysTest.sortTest13();
//        ArraysTest.sortTest14();
//        ArraysTest.sortTest15();
//        ArraysTest.sortTest16();
//        ArraysTest.sortTest17();
//        ArraysTest.sortTest18();
//        ArraysTest.toStringTest();
//        ArraysTest.toStringTest2();
//        ArraysTest.toStringTest3();
//        ArraysTest.toStringTest4();
//        ArraysTest.toStringTest5();
//        ArraysTest.toStringTest6();
//        ArraysTest.toStringTest7();
//        ArraysTest.toStringTest8();
//        ArraysTest.toStringTest9();
    }

    /**
     * Tests the binarySearch method with array of bytes.
     */
    public static void binarySearchTest() {
        byte[] a;
        int b;
        a = new byte[]{(byte) 3, (byte) 2, (byte) 8, (byte) 7, (byte) 6};
        Arrays.sort(a);
        // existing element search
        b = Arrays.binarySearch(a, (byte) 8);
        logger.info(b);
        // non-existent element search
        b = Arrays.binarySearch(a, (byte) 4);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of bytes and indexes as
     * parameters.
     */
    public static void binarySearchTest2() {
        byte[] a;
        int b;
        a = new byte[]{(byte) 3, (byte) 2, (byte) 8, (byte) 7, (byte) 6};
        Arrays.sort(a);
        // existing element search
        b = Arrays.binarySearch(a, 1, 4, (byte) 8);
        logger.info(b);
        // non-existent element search in a part of array
        b = Arrays.binarySearch(a, 1, 4, (byte) 4);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of chars.
     */
    public static void binarySearchTest3() {
        char[] a;
        int b;
        a = new char[]{'c', 'b', 'h', 'g', 'f'};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 'h');
        logger.info(b);
        b = Arrays.binarySearch(a, 'd');
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of chars and indexes as
     * parameters.
     */
    public static void binarySearchTest4() {
        char[] a;
        int b;
        a = new char[]{'c', 'b', 'h', 'g', 'f'};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 1, 4, 'h');
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, 'd');
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of doubles.
     */
    public static void binarySearchTest5() {
        double[] a;
        int b;
        a = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 8.0);
        logger.info(b);
        b = Arrays.binarySearch(a, 4.0);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of doubles and indexes as
     * parameters.
     */
    public static void binarySearchTest6() {
        double[] a;
        int b;
        a = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 1, 4, 8.0);
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, 4.0);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of floats.
     */
    public static void binarySearchTest7() {
        float[] a;
        int b;
        a = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 8.0F);
        logger.info(b);
        b = Arrays.binarySearch(a, 4.0F);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of floats and indexes as
     * parameters.
     */
    public static void binarySearchTest8() {
        float[] a;
        int b;
        a = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 1, 4, 8.0F);
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, 4.0F);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of ints.
     */
    public static void binarySearchTest9() {
        int[] a;
        int b;
        a = new int[]{3, 2, 8, 7, 6};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 8);
        logger.info(b);
        b = Arrays.binarySearch(a, 4);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of ints and indexes as
     * parameters.
     */
    public static void binarySearchTest10() {
        int[] a;
        int b;
        a = new int[]{3, 2, 8, 7, 6};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 1, 4, 8);
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, 4);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of longs.
     */
    public static void binarySearchTest11() {
        long[] a;
        int b;
        a = new long[]{3L, 2L, 8L, 7L, 6L};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 8L);
        logger.info(b);
        b = Arrays.binarySearch(a, 4L);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of longs and indexes as
     * parameters.
     */
    public static void binarySearchTest12() {
        long[] a;
        int b;
        a = new long[]{3L, 2L, 8L, 7L, 6L};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 1, 4, 8L);
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, 4L);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of objects.
     */
    public static void binarySearchTest13() {
        TestObject[] a;
        int b;
        a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
        Arrays.sort(a);
        b = Arrays.binarySearch(a, new TestObject("sixth", 6));
        logger.info(b);
        b = Arrays.binarySearch(a, new TestObject("sixth", 4));
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of objects and indexes as
     * parameters.
     */
    public static void binarySearchTest14() {
        TestObject[] a;
        int b;
        a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 1, 4, new TestObject("sixth", 6));
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, new TestObject("sixth", 4));
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of shorts.
     */
    public static void binarySearchTest15() {
        short[] a;
        int b;
        a = new short[]{(short) 3, (short) 2, (short) 8, (short) 7, (short) 6};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, (short) 8);
        logger.info(b);
        b = Arrays.binarySearch(a, (short) 4);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of shorts and indexes as
     * parameters.
     */
    public static void binarySearchTest16() {
        short[] a;
        int b;
        a = new short[]{(short) 3, (short) 2, (short) 8, (short) 7, (short) 6};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 1, 4, (short) 8);
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, (short) 4);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of objects and comparator as a
     * parameter.
     */
    public static void binarySearchTest17() {
        TestObject[] a;
        int b;
        TestObjectComparer c;
        a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
        c = new TestObjectComparer();
        Arrays.sort(a, c);
        b = Arrays.binarySearch(a, new TestObject("sixth", 6), c);
        logger.info(b);
        b = Arrays.binarySearch(a, new TestObject("sixth", 4), c);
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with array of shorts and indexes and
     * comparator as parameters.
     */
    public static void binarySearchTest18() {
        TestObject[] a;
        int b;
        TestObjectComparer c;
        a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
        c = new TestObjectComparer();
        Arrays.sort(a, c);
        b = Arrays.binarySearch(a, 1, 4, new TestObject("sixth", 6), c);
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, new TestObject("sixth", 4), c);
        logger.info(b);
    }

    /**
     * Tests the copyOf method with array of booleans.
     */
    public static void copyOfTest() {
        boolean[] a, b;
        String c;
        a = new boolean[]{true, false, false, false, true};
        // new array is smaller
        b = Arrays.copyOf(a, 3);
        c = Arrays.toString(b);
        logger.info(c);
        // new array has the same length
        b = Arrays.copyOf(a, 5);
        c = Arrays.toString(b);
        logger.info(c);
        // new array is bigger
        b = Arrays.copyOf(a, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOf method with array of bytes.
     */
    public static void copyOfTest2() {
        byte[] a, b;
        String c;
        a = new byte[]{(byte) 3, (byte) 2, (byte) 8, (byte) 7, (byte) 6};
        b = Arrays.copyOf(a, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOf method with array of chars.
     */
    public static void copyOfTest3() {
        char[] a, b;
        String c;
        a = new char[]{'c', 'b', 'h', 'g', 'f'};
        b = Arrays.copyOf(a, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOf method with array of doubles.
     */
    public static void copyOfTest4() {
        double[] a, b;
        String c;
        a = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
        b = Arrays.copyOf(a, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOf method with array of floats.
     */
    public static void copyOfTest5() {
        float[] a, b;
        String c;
        a = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
        b = Arrays.copyOf(a, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOf method with array of ints.
     */
    public static void copyOfTest6() {
        int[] a, b;
        String c;
        a = new int[]{3, 2, 8, 7, 6};
        b = Arrays.copyOf(a, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOf method with array of longs.
     */
    public static void copyOfTest7() {
        long[] a, b;
        String c;
        a = new long[]{3L, 2L, 8L, 7L, 6L};
        b = Arrays.copyOf(a, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOf method with array of shorts.
     */
    public static void copyOfTest8() {
        short[] a, b;
        String c;
        a = new short[]{(short) 3, (short) 2, (short) 8, (short) 7, (short) 6};
        b = Arrays.copyOf(a, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOf method with array of objects.
     */
    public static void copyOfTest9() {
        TestObject[] a, b;
        String c;
        a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),};
        b = Arrays.copyOf(a, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOf(a, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOfRange method with array of booleans.
     */
    public static void copyOfRangeTest1() {
        boolean[] a, b;
        String c;
        a = new boolean[]{true, false, false, false, true};
        // copy from the beginning
        b = Arrays.copyOfRange(a, 0, 3);
        c = Arrays.toString(b);
        logger.info(c);
        // copy from the middle
        b = Arrays.copyOfRange(a, 2, 5);
        c = Arrays.toString(b);
        logger.info(c);
        // copy from the end
        b = Arrays.copyOfRange(a, 4, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOfRange method with array of bytes.
     */
    public static void copyOfRangeTest2() {
        byte[] a, b;
        String c;
        a = new byte[]{(byte) 3, (byte) 2, (byte) 8, (byte) 7, (byte) 6};
        b = Arrays.copyOfRange(a, 0, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 2, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 4, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOfRange method with array of chars.
     */
    public static void copyOfRangeTest3() {
        char[] a, b;
        String c;
        a = new char[]{'c', 'b', 'h', 'g', 'f'};
        b = Arrays.copyOfRange(a, 0, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 2, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 4, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOfRange method with array of doubles.
     */
    public static void copyOfRangeTest4() {
        double[] a, b;
        String c;
        a = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
        b = Arrays.copyOfRange(a, 0, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 2, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 4, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOfRange method with array of floats.
     */
    public static void copyOfRangeTest5() {
        float[] a, b;
        String c;
        a = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
        b = Arrays.copyOfRange(a, 0, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 2, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 4, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOfRange method with array of ints.
     */
    public static void copyOfRangeTest6() {
        int[] a, b;
        String c;
        a = new int[]{3, 2, 8, 7, 6};
        b = Arrays.copyOfRange(a, 0, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 2, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 4, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOfRange method with array of longs.
     */
    public static void copyOfRangeTest7() {
        long[] a, b;
        String c;
        a = new long[]{3L, 2L, 8L, 7L, 6L};
        b = Arrays.copyOfRange(a, 0, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 2, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 4, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOfRange method with array of shorts.
     */
    public static void copyOfRangeTest8() {
        short[] a, b;
        String c;
        a = new short[]{(short) 3, (short) 2, (short) 8, (short) 7, (short) 6};
        b = Arrays.copyOfRange(a, 0, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 2, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 4, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the copyOfRange method with array of objects.
     */
    public static void copyOfRangeTest9() {
        TestObject[] a, b;
        String c;
        a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),};
        b = Arrays.copyOfRange(a, 0, 3);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 2, 5);
        c = Arrays.toString(b);
        logger.info(c);
        b = Arrays.copyOfRange(a, 4, 7);
        c = Arrays.toString(b);
        logger.info(c);
    }

    /**
     * Tests the equals method with array of booleans.
     */
    public static void equalsTest() {
        boolean[] a, b;
        boolean c;
        a = new boolean[]{true, false, false, false, true};
        // reference to the second array is null
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        // arrays do not have the same length
        b = new boolean[]{true};
        c = Arrays.equals(a, b);
        logger.info(c);
        // arrays have the same length but different elements
        b = new boolean[]{true, false, false, false, false};
        c = Arrays.equals(a, b);
        logger.info(c);
        // arrays have the same length and elements
        b = new boolean[]{true, false, false, false, true};
        c = Arrays.equals(a, b);
        logger.info(c);
        // references are equal
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method with array of bytes.
     */
    public static void equalsTest2() {
        byte[] a, b;
        boolean c;
        a = new byte[]{(byte) 3, (byte) 2, (byte) 8, (byte) 7, (byte) 6};
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new byte[]{(byte) 3};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new byte[]{(byte) 3, (byte) 2, (byte) 8, (byte) 7, (byte) 3};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new byte[]{(byte) 3, (byte) 2, (byte) 8, (byte) 7, (byte) 6};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method with array of chars.
     */
    public static void equalsTest3() {
        char[] a, b;
        boolean c;
        a = new char[]{'c', 'b', 'h', 'g', 'f'};
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new char[]{'c'};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new char[]{'c', 'b', 'h', 'g', 'c'};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new char[]{'c', 'b', 'h', 'g', 'f'};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method with array of doubles.
     */
    public static void equalsTest4() {
        double[] a, b;
        boolean c;
        a = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new double[]{3.0};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new double[]{3.0, 2.0, 8.0, 7.0, 3.0};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method with array of floats.
     */
    public static void equalsTest5() {
        float[] a, b;
        boolean c;
        a = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new float[]{3.0F};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 3.0F};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method with array of ints.
     */
    public static void equalsTest6() {
        int[] a, b;
        boolean c;
        a = new int[]{3, 2, 8, 7, 6};
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new int[]{3};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new int[]{3, 2, 8, 7, 3};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new int[]{3, 2, 8, 7, 6};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method with array of longs.
     */
    public static void equalsTest7() {
        long[] a, b;
        boolean c;
        a = new long[]{3L, 2L, 8L, 7L, 6L};
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new long[]{3L};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new long[]{3L, 2L, 8L, 7L, 3L};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new long[]{3L, 2L, 8L, 7L, 6L};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method with array of objects.
     */
    public static void equalsTest8() {
        TestObject[] a, b;
        boolean c;
        a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),};
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new TestObject[]{
            new TestObject("first", 3)
        };
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 3),};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new TestObject[]{
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method with array of shorts.
     */
    public static void equalsTest9() {
        short[] a, b;
        boolean c;
        a = new short[]{(short) 3, (short) 2, (short) 8, (short) 7, (short) 6};
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new short[]{(short) 3};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new short[]{(short) 3, (short) 2, (short) 8, (short) 7, (short) 3};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new short[]{(short) 3, (short) 2, (short) 8, (short) 7, (short) 6};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }

    /**
     * Tests the fill method with array of booleans.
     */
    public static void fillTest() {
        boolean[] a;
        String b;
        // the array for filling
        a = new boolean[5];
        Arrays.fill(a, true);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of booleans and indexes as parameters.
     */
    public static void fillTest2() {
        boolean[] a;
        String b;
        // the array for partial filling
        a = new boolean[5];
        Arrays.fill(a, 1, 4, true);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of bytes.
     */
    public static void fillTest3() {
        byte[] a;
        String b;
        a = new byte[5];
        Arrays.fill(a, (byte) 8);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of bytes and indexes as parameters.
     */
    public static void fillTest4() {
        byte[] a;
        String b;
        a = new byte[5];
        Arrays.fill(a, 1, 4, (byte) 8);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of chars.
     */
    public static void fillTest5() {
        char[] a;
        String b;
        a = new char[5];
        Arrays.fill(a, 'h');
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of chars and indexes as parameters.
     */
    public static void fillTest6() {
        char[] a;
        String b;
        a = new char[5];
        Arrays.fill(a, 1, 4, 'h');
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of doubles.
     */
    public static void fillTest7() {
        double[] a;
        String b;
        a = new double[5];
        Arrays.fill(a, 8.0);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of doubles and indexes as parameters.
     */
    public static void fillTest8() {
        double[] a;
        String b;
        a = new double[5];
        Arrays.fill(a, 1, 4, 8.0);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of floats.
     */
    public static void fillTest9() {
        float[] a;
        String b;
        a = new float[5];
        Arrays.fill(a, 8.0F);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of floats and indexes as parameters.
     */
    public static void fillTest10() {
        float[] a;
        String b;
        a = new float[5];
        Arrays.fill(a, 1, 4, 8.0F);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of ints.
     */
    public static void fillTest11() {
        int[] a;
        String b;
        a = new int[5];
        Arrays.fill(a, 8);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of ints and indexes as parameters.
     */
    public static void fillTest12() {
        int[] a;
        String b;
        a = new int[5];
        Arrays.fill(a, 1, 4, 8);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of longs.
     */
    public static void fillTest13() {
        long[] a;
        String b;
        a = new long[5];
        Arrays.fill(a, 8L);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of longs and indexes as parameters.
     */
    public static void fillTest14() {
        long[] a;
        String b;
        a = new long[5];
        Arrays.fill(a, 1, 4, 8L);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of objects.
     */
    public static void fillTest15() {
        TestObject[] a;
        String b;
        a = new TestObject[5];
        Arrays.fill(a, new TestObject("sixth", 6));
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of objects and indexes as parameters.
     */
    public static void fillTest16() {
        TestObject[] a;
        String b;
        a = new TestObject[5];
        Arrays.fill(a, 1, 4, new TestObject("sixth", 6));
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of shorts.
     */
    public static void fillTest17() {
        short[] a;
        String b;
        a = new short[5];
        Arrays.fill(a, (short) 8);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the fill method with array of shorts and indexes as parameters.
     */
    public static void fillTest18() {
        short[] a;
        String b;
        a = new short[5];
        Arrays.fill(a, 1, 4, (short) 8);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of bytes.
     */
    public static void sortTest() {
        byte[] a;
        String b;
        // the array for sorting
        a = new byte[]{(byte) 3, (byte) 2, (byte) 8, (byte) 7, (byte) 6};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of bytes and indexes as parameters.
     */
    public static void sortTest2() {
        byte[] a;
        String b;
        // the array for partial sorting
        a = new byte[]{(byte) 3, (byte) 2, (byte) 8, (byte) 7, (byte) 6};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of chars.
     */
    public static void sortTest3() {
        char[] a;
        String b;
        a = new char[]{'c', 'b', 'h', 'g', 'f'};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of chars and indexes as parameters.
     */
    public static void sortTest4() {
        char[] a;
        String b;
        a = new char[]{'c', 'b', 'h', 'g', 'f'};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of doubles.
     */
    public static void sortTest5() {
        double[] a;
        String b;
        a = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of doubles and indexes as parameters.
     */
    public static void sortTest6() {
        double[] a;
        String b;
        a = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of floats.
     */
    public static void sortTest7() {
        float[] a;
        String b;
        a = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of floats and indexes as parameters.
     */
    public static void sortTest8() {
        float[] a;
        String b;
        a = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of ints.
     */
    public static void sortTest9() {
        int[] a;
        String b;
        a = new int[]{3, 2, 8, 7, 6};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of ints and indexes as parameters.
     */
    public static void sortTest10() {
        int[] a;
        String b;
        a = new int[]{3, 2, 8, 7, 6};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of longs.
     */
    public static void sortTest11() {
        long[] a;
        String b;
        a = new long[]{3L, 2L, 8L, 7L, 6L};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of longs and indexes as parameters.
     */
    public static void sortTest12() {
        long[] a;
        String b;
        a = new long[]{3L, 2L, 8L, 7L, 6L};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of objects.
     */
    public static void sortTest13() {
        TestObject[] a;
        String b;
        a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of objects and indexes as parameters.
     */
    public static void sortTest14() {
        TestObject[] a;
        String b;
        a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of shorts.
     */
    public static void sortTest15() {
        short[] a;
        String b;
        a = new short[]{(short) 3, (short) 2, (short) 8, (short) 7, (short) 6};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of shorts and indexes as parameters.
     */
    public static void sortTest16() {
        short[] a;
        String b;
        a = new short[]{(short) 3, (short) 2, (short) 8, (short) 7, (short) 6};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of objects and comparator as a
     * parameter.
     */
    public static void sortTest17() {
        TestObject[] a;
        String b;
        TestObjectComparer c;
        a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
        c = new TestObjectComparer();
        Arrays.sort(a, c);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the sort method with array of objects and indexes and comparator as
     * parameters.
     */
    public static void sortTest18() {
        TestObject[] a;
        String b;
        TestObjectComparer c;
        a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
        c = new TestObjectComparer();
        Arrays.sort(a, 1, 4, c);
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the toString method with array of booleans.
     */
    public static void toStringTest() {
        boolean[] a;
        String b;
        // the text represenation of an empty array
        a = new boolean[]{};
        b = Arrays.toString(a);
        logger.info(b);
        // the text represenation of an array with one element
        a = new boolean[]{true};
        b = Arrays.toString(a);
        logger.info(b);
        // the text represenation of an array with some elements
        a = new boolean[]{true, false, false, false, true};
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the toString method with array of bytes.
     */
    public static void toStringTest2() {
        byte[] a;
        String b;
        a = new byte[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new byte[]{(byte) 3};
        b = Arrays.toString(a);
        logger.info(b);
        a = new byte[]{(byte) 3, (byte) 2, (byte) 8, (byte) 7, (byte) 6};
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the toString method with array of chars.
     */
    public static void toStringTest3() {
        char[] a;
        String b;
        a = new char[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new char[]{'c'};
        b = Arrays.toString(a);
        logger.info(b);
        a = new char[]{'c', 'b', 'h', 'g', 'f'};
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the toString method with array of doubles.
     */
    public static void toStringTest4() {
        double[] a;
        String b;
        a = new double[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new double[]{3.0};
        b = Arrays.toString(a);
        logger.info(b);
        a = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the toString method with array of floats.
     */
    public static void toStringTest5() {
        float[] a;
        String b;
        a = new float[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new float[]{3.0F};
        b = Arrays.toString(a);
        logger.info(b);
        a = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the toString method with array of ints.
     */
    public static void toStringTest6() {
        int[] a;
        String b;
        a = new int[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new int[]{3};
        b = Arrays.toString(a);
        logger.info(b);
        a = new int[]{3, 2, 8, 7, 6};
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the toString method with array of longs.
     */
    public static void toStringTest7() {
        long[] a;
        String b;
        a = new long[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new long[]{3L};
        b = Arrays.toString(a);
        logger.info(b);
        a = new long[]{3L, 2L, 8L, 7L, 6L};
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the toString method with array of objects.
     */
    public static void toStringTest8() {
        TestObject[] a;
        String b;
        a = new TestObject[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new TestObject[]{new TestObject("first", 1)};
        b = Arrays.toString(a);
        logger.info(b);
        a = new TestObject[]{null};
        b = Arrays.toString(a);
        logger.info(b);
        a = new TestObject[]{new TestObject("first", 1), new TestObject("second", 2), new TestObject("third", 3)};
        b = Arrays.toString(a);
        logger.info(b);
        a = new TestObject[]{new TestObject("first", 1), null, new TestObject("third", 3)};
        b = Arrays.toString(a);
        logger.info(b);
        a = new TestObject[]{null, null, null};
        b = Arrays.toString(a);
        logger.info(b);
    }

    /**
     * Tests the toString method with array of shorts.
     */
    public static void toStringTest9() {
        short[] a;
        String b;
        a = new short[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new short[]{(short) 3};
        b = Arrays.toString(a);
        logger.info(b);
        a = new short[]{(short) 3, (short) 2, (short) 8, (short) 7, (short) 6};
        b = Arrays.toString(a);
        logger.info(b);
    }

}
