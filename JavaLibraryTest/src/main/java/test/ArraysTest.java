/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import java.util.Arrays;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Arrays.
 *
 * @author Petr Kozler
 */
public class ArraysTest {
    
    public static Logger logger = LogManager.getLogger(ArraysTest.class.getName());
    
    public static void runTestSuite() {
        ArraysTest.binarySearchTestCase();
        ArraysTest.binarySearchTestCase2();
        ArraysTest.binarySearchTestCase3();
        ArraysTest.binarySearchTestCase4();
        ArraysTest.binarySearchTestCase5();
        ArraysTest.binarySearchTestCase6();
        ArraysTest.binarySearchTestCase7();
        ArraysTest.binarySearchTestCase8();
        ArraysTest.binarySearchTestCase9();
        ArraysTest.binarySearchTestCase10();
        ArraysTest.binarySearchTestCase11();
        ArraysTest.binarySearchTestCase12();
        ArraysTest.binarySearchTestCase13();
        ArraysTest.binarySearchTestCase14();
        ArraysTest.binarySearchTestCase15();
        ArraysTest.binarySearchTestCase16();
        ArraysTest.binarySearchTestCase17();
        ArraysTest.binarySearchTestCase18();
        ArraysTest.copyOfTestCase();
        ArraysTest.copyOfTestCase2();
        ArraysTest.copyOfTestCase3();
        ArraysTest.copyOfTestCase4();
        ArraysTest.copyOfTestCase5();
        ArraysTest.copyOfTestCase6();
        ArraysTest.copyOfTestCase7();
        ArraysTest.copyOfTestCase8();
        ArraysTest.copyOfTestCase9();
        ArraysTest.copyOfRangeTestCase1();
        ArraysTest.copyOfRangeTestCase2();
        ArraysTest.copyOfRangeTestCase3();
        ArraysTest.copyOfRangeTestCase4();
        ArraysTest.copyOfRangeTestCase5();
        ArraysTest.copyOfRangeTestCase6();
        ArraysTest.copyOfRangeTestCase7();
        ArraysTest.copyOfRangeTestCase8();
        ArraysTest.copyOfRangeTestCase9();
        ArraysTest.equalsTestCase();
        ArraysTest.equalsTestCase2();
        ArraysTest.equalsTestCase3();
        ArraysTest.equalsTestCase4();
        ArraysTest.equalsTestCase5();
        ArraysTest.equalsTestCase6();
        ArraysTest.equalsTestCase7();
        ArraysTest.equalsTestCase8();
        ArraysTest.equalsTestCase9();
        ArraysTest.fillTestCase();
        ArraysTest.fillTestCase2();
        ArraysTest.fillTestCase3();
        ArraysTest.fillTestCase4();
        ArraysTest.fillTestCase5();
        ArraysTest.fillTestCase6();
        ArraysTest.fillTestCase7();
        ArraysTest.fillTestCase8();
        ArraysTest.fillTestCase9();
        ArraysTest.fillTestCase10();
        ArraysTest.fillTestCase11();
        ArraysTest.fillTestCase12();
        ArraysTest.fillTestCase13();
        ArraysTest.fillTestCase14();
        ArraysTest.fillTestCase15();
        ArraysTest.fillTestCase16();
        ArraysTest.fillTestCase17();
        ArraysTest.fillTestCase18();
        ArraysTest.sortTestCase();
        ArraysTest.sortTestCase2();
        ArraysTest.sortTestCase3();
        ArraysTest.sortTestCase4();
        ArraysTest.sortTestCase5();
        ArraysTest.sortTestCase6();
        ArraysTest.sortTestCase7();
        ArraysTest.sortTestCase8();
        ArraysTest.sortTestCase9();
        ArraysTest.sortTestCase10();
        ArraysTest.sortTestCase11();
        ArraysTest.sortTestCase12();
        ArraysTest.sortTestCase13();
        ArraysTest.sortTestCase14();
        ArraysTest.sortTestCase15();
        ArraysTest.sortTestCase16();
        ArraysTest.sortTestCase17();
        ArraysTest.sortTestCase18();
        ArraysTest.toStringTestCase();
        ArraysTest.toStringTestCase2();
        ArraysTest.toStringTestCase3();
        ArraysTest.toStringTestCase4();
        ArraysTest.toStringTestCase5();
        ArraysTest.toStringTestCase6();
        ArraysTest.toStringTestCase7();
        ArraysTest.toStringTestCase8();
        ArraysTest.toStringTestCase9();
    }
    
    /**
     * Otestuje binární vyhledávání v poli 8-bitových celých čísel.
     */
    public static void binarySearchTestCase() {
        byte[] a;
        int b;
        a = new byte[]{(byte)3, (byte)2, (byte)8, (byte)7, (byte)6};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, (byte)8);
        logger.info(b);
        b = Arrays.binarySearch(a, (byte)4);
        logger.info(b);
    }
    
    /**
     * Otestuje binární vyhledávání v zadaném počtu prvků pole 8-bitových celých čísel od zadaného indexu.
     */
    public static void binarySearchTestCase2() {
        byte[] a;
        int b;
        a = new byte[]{(byte)3, (byte)2, (byte)8, (byte)7, (byte)6};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 1, 4, (byte)8);
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, (byte)4);
        logger.info(b);
    }
    
    /**
     * Otestuje binární vyhledávání v poli znaků.
     */
    public static void binarySearchTestCase3() {
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
     * Otestuje binární vyhledávání v zadaném počtu prvků pole znaků od zadaného indexu.
     */
    public static void binarySearchTestCase4() {
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
     * Otestuje binární vyhledávání v poli desetinných čísel s dvojitou přesností.
     */
    public static void binarySearchTestCase5() {
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
     * Otestuje binární vyhledávání v zadaném počtu prvků pole desetinných čísel s dvojitou přesností od zadaného indexu.
     */
    public static void binarySearchTestCase6() {
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
     * Otestuje binární vyhledávání v poli desetinných čísel s jednoduchou přesností.
     */
    public static void binarySearchTestCase7() {
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
     * Otestuje binární vyhledávání v zadaném počtu prvků pole desetinných čísel s jednoduchou přesností od zadaného indexu.
     */
    public static void binarySearchTestCase8() {
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
     * Otestuje binární vyhledávání v poli 32-bitových celých čísel.
     */
    public static void binarySearchTestCase9() {
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
     * Otestuje binární vyhledávání v zadaném počtu prvků pole 32-bitových celých čísel od zadaného indexu.
     */
    public static void binarySearchTestCase10() {
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
     * Otestuje binární vyhledávání v poli 64-bitových celých čísel.
     */
    public static void binarySearchTestCase11() {
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
     * Otestuje binární vyhledávání v zadaném počtu prvků pole 64-bitových celých čísel od zadaného indexu.
     */
    public static void binarySearchTestCase12() {
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
     * Otestuje binární vyhledávání v poli porovnatelných objektů.
     */
    public static void binarySearchTestCase13() {
        DummyObject[] a;
        int b;
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 6),
            new DummyObject("sixth", 3),
            new DummyObject("seventh", 2),
            new DummyObject("eighth", 8),
            new DummyObject("nineth", 7),
            new DummyObject("tenth", 6)
        };
        Arrays.sort(a);
        b = Arrays.binarySearch(a, new DummyObject("sixth", 6));
        logger.info(b);
        b = Arrays.binarySearch(a, new DummyObject("sixth", 4));
        logger.info(b);
    }
    
    /**
     * Otestuje binární vyhledávání v zadaném počtu prvků pole porovnatelných objektů od zadaného indexu.
     */
    public static void binarySearchTestCase14() {
        DummyObject[] a;
        int b;
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 6),
            new DummyObject("sixth", 3),
            new DummyObject("seventh", 2),
            new DummyObject("eighth", 8),
            new DummyObject("nineth", 7),
            new DummyObject("tenth", 6)
        };
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 1, 4, new DummyObject("sixth", 6));
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, new DummyObject("sixth", 4));
        logger.info(b);
    }
    
    /**
     * Otestuje binární vyhledávání v poli 16-bitových celých čísel.
     */
    public static void binarySearchTestCase15() {
        short[] a;
        int b;
        a = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, (short)8);
        logger.info(b);
        b = Arrays.binarySearch(a, (short)4);
        logger.info(b);
    }
    
    /**
     * Otestuje binární vyhledávání v zadaném počtu prvků pole 16-bitových celých čísel od zadaného indexu.
     */
    public static void binarySearchTestCase16() {
        short[] a;
        int b;
        a = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
        Arrays.sort(a);
        b = Arrays.binarySearch(a, 1, 4, (short)8);
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, (short)4);
        logger.info(b);
    }
    
    /**
     * Otestuje binární vyhledávání v poli objektů podle zadaného komparátoru.
     */
    public static void binarySearchTestCase17() {
        DummyObject[] a;
        int b;
        DummyObjectComparer c;
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 6),
            new DummyObject("sixth", 3),
            new DummyObject("seventh", 2),
            new DummyObject("eighth", 8),
            new DummyObject("nineth", 7),
            new DummyObject("tenth", 6)
        };
        c = new DummyObjectComparer();
        Arrays.sort(a, c);
        b = Arrays.binarySearch(a, new DummyObject("sixth", 6), c);
        logger.info(b);
        b = Arrays.binarySearch(a, new DummyObject("sixth", 4), c);
        logger.info(b);
    }
    
    /**
     * Otestuje binární vyhledávání v zadaném počtu prvků pole objektů podle zadaného komparátoru od zadaného indexu.
     */
    public static void binarySearchTestCase18() {
        DummyObject[] a;
        int b;
        DummyObjectComparer c;
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 6),
            new DummyObject("sixth", 3),
            new DummyObject("seventh", 2),
            new DummyObject("eighth", 8),
            new DummyObject("nineth", 7),
            new DummyObject("tenth", 6)
        };
        c = new DummyObjectComparer();
        Arrays.sort(a, c);
        b = Arrays.binarySearch(a, 1, 4, new DummyObject("sixth", 6), c);
        logger.info(b);
        b = Arrays.binarySearch(a, 1, 4, new DummyObject("sixth", 4), c);
        logger.info(b);
    }
    
    /**
     * Otestuje kopírování obsahu jednoho pole logických hodnot do druhého.
     */
    public static void copyOfTestCase() {
        boolean[] a, b;
        String c;
        a = new boolean[]{true, false, false, false, true};
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
     * Otestuje kopírování obsahu jednoho pole 8-bitových celých čísel do druhého.
     */
    public static void copyOfTestCase2() {
        byte[] a, b;
        String c;
        a = new byte[]{(byte)3, (byte)2, (byte)8, (byte)7, (byte)6};
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
     * Otestuje kopírování obsahu jednoho pole znaků do druhého.
     */
    public static void copyOfTestCase3() {
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
     * Otestuje kopírování obsahu jednoho pole desetinných čísel s dvojitou přesností do druhého.
     */
    public static void copyOfTestCase4() {
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
     * Otestuje kopírování obsahu jednoho pole desetinných čísel s jednoduchou přesností do druhého.
     */
    public static void copyOfTestCase5() {
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
     * Otestuje kopírování obsahu jednoho pole 32-bitových celých čísel do druhého.
     */
    public static void copyOfTestCase6() {
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
     * Otestuje kopírování obsahu jednoho pole 64-bitových celých čísel do druhého.
     */
    public static void copyOfTestCase7() {
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
     * Otestuje kopírování obsahu jednoho pole 16-bitových celých čísel do druhého.
     */
    public static void copyOfTestCase8() {
        short[] a, b;
        String c;
        a = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
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
     * Otestuje kopírování obsahu jednoho pole objektů do druhého.
     */
    public static void copyOfTestCase9() {
        DummyObject[] a, b;
        String c;
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 6),
        };
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
     * Otestuje kopírování obsahu zadaného počtu prvků jednoho pole logických hodnot od zadaného indexu do druhého pole.
     */
    public static void copyOfRangeTestCase1() {
        boolean[] a, b;
        String c;
        a = new boolean[]{true, false, false, false, true};
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
     * Otestuje kopírování obsahu zadaného počtu prvků jednoho pole 8-bitových celých čísel od zadaného indexu do druhého pole.
     */
    public static void copyOfRangeTestCase2() {
        byte[] a, b;
        String c;
        a = new byte[]{(byte)3, (byte)2, (byte)8, (byte)7, (byte)6};
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
     * Otestuje kopírování obsahu zadaného počtu prvků jednoho pole znaků od zadaného indexu do druhého pole.
     */
    public static void copyOfRangeTestCase3() {
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
     * Otestuje kopírování obsahu zadaného počtu prvků jednoho pole desetinných čísel s dvojitou přesností od zadaného indexu do druhého pole.
     */
    public static void copyOfRangeTestCase4() {
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
     * Otestuje kopírování obsahu zadaného počtu prvků jednoho pole desetinných čísel s jednoduchou přesností od zadaného indexu do druhého pole.
     */
    public static void copyOfRangeTestCase5() {
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
     * Otestuje kopírování obsahu zadaného počtu prvků jednoho pole 32-bitových celých čísel od zadaného indexu do druhého pole.
     */
    public static void copyOfRangeTestCase6() {
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
     * Otestuje kopírování obsahu zadaného počtu prvků jednoho pole 64-bitových celých čísel od zadaného indexu do druhého pole.
     */
    public static void copyOfRangeTestCase7() {
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
     * Otestuje kopírování obsahu zadaného počtu prvků jednoho pole 16-bitových celých čísel od zadaného indexu do druhého pole.
     */
    public static void copyOfRangeTestCase8() {
        short[] a, b;
        String c;
        a = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
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
     * Otestuje kopírování obsahu zadaného počtu prvků jednoho pole objektů od zadaného indexu do druhého pole.
     */
    public static void copyOfRangeTestCase9() {
        DummyObject[] a, b;
        String c;
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 6),
        };
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
     * Otestuje zjištění rovnosti dvou polí logických hodnot.
     */
    public static void equalsTestCase() {
        boolean[] a, b;
        boolean c;
        a = new boolean[]{true, false, false, false, true};
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new boolean[]{true};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new boolean[]{true, false, false, false, false};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new boolean[]{true, false, false, false, true};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou polí 8-bitových celých čísel.
     */
    public static void equalsTestCase2() {
        byte[] a, b;
        boolean c;
        a = new byte[]{(byte)3, (byte)2, (byte)8, (byte)7, (byte)6};
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new byte[]{(byte)3};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new byte[]{(byte)3, (byte)2, (byte)8, (byte)7, (byte)3};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new byte[]{(byte)3, (byte)2, (byte)8, (byte)7, (byte)6};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou polí znaků.
     */
    public static void equalsTestCase3() {
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
     * Otestuje zjištění rovnosti dvou polí desetinných čísel s dvojitou přesností.
     */
    public static void equalsTestCase4() {
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
     * Otestuje zjištění rovnosti dvou polí desetinných čísel s jednoduchou přesností.
     */
    public static void equalsTestCase5() {
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
     * Otestuje zjištění rovnosti dvou polí 32-bitových celých čísel.
     */
    public static void equalsTestCase6() {
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
     * Otestuje zjištění rovnosti dvou polí 64-bitových celých čísel.
     */
    public static void equalsTestCase7() {
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
     * Otestuje zjištění rovnosti dvou polí objektů.
     */
    public static void equalsTestCase8() {
        DummyObject[] a, b;
        boolean c;
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 6),
        };
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        a = new DummyObject[]{
            new DummyObject("first", 3)
        };
        c = Arrays.equals(a, b);
        logger.info(c);
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 3),
        };
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new DummyObject[]{
            new DummyObject("sixth", 3),
            new DummyObject("seventh", 2),
            new DummyObject("eighth", 8),
            new DummyObject("nineth", 7),
            new DummyObject("tenth", 6)
        };
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje zjištění rovnosti dvou polí 16-bitových celých čísel.
     */
    public static void equalsTestCase9() {
        short[] a, b;
        boolean c;
        a = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
        b = null;
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new short[]{(short)3};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new short[]{(short)3, (short)2, (short)8, (short)7, (short)3};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
        c = Arrays.equals(a, b);
        logger.info(c);
        b = a;
        c = Arrays.equals(a, b);
        logger.info(c);
    }
    
    /**
     * Otestuje naplnění pole logických hodnot zadaným prvkem.
     */
    public static void fillTestCase() {
        boolean[] a;
        String b;
        a = new boolean[5];
        Arrays.fill(a, true);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění zadaného počtu prvků pole logických hodnot od zadaného indexu zadaným prvkem.
     */
    public static void fillTestCase2() {
        boolean[] a;
        String b;
        a = new boolean[5];
        Arrays.fill(a, 1, 4, true);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění pole 8-bitových celých čísel zadaným prvkem.
     */
    public static void fillTestCase3() {
        byte[] a;
        String b;
        a = new byte[5];
        Arrays.fill(a, (byte)8);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění zadaného počtu prvků pole 8-bitových celých čísel od zadaného indexu zadaným prvkem.
     */
    public static void fillTestCase4() {
        byte[] a;
        String b;
        a = new byte[5];
        Arrays.fill(a, 1, 4, (byte)8);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění pole znaků zadaným prvkem.
     */
    public static void fillTestCase5() {
        char[] a;
        String b;
        a = new char[5];
        Arrays.fill(a, 'h');
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění zadaného počtu prvků pole znaků od zadaného indexu zadaným prvkem.
     */
    public static void fillTestCase6() {
        char[] a;
        String b;
        a = new char[5];
        Arrays.fill(a, 1, 4, 'h');
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění pole desetinných čísel s dvojitou přesností zadaným prvkem.
     */
    public static void fillTestCase7() {
        double[] a;
        String b;
        a = new double[5];
        Arrays.fill(a, 8.0);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění zadaného počtu prvků pole desetinných čísel s dvojitou přesností od zadaného indexu zadaným prvkem.
     */
    public static void fillTestCase8() {
        double[] a;
        String b;
        a = new double[5];
        Arrays.fill(a, 1, 4, 8.0);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění pole desetinných čísel s jednoduchou přesností zadaným prvkem.
     */
    public static void fillTestCase9() {
        float[] a;
        String b;
        a = new float[5];
        Arrays.fill(a, 8.0F);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění zadaného počtu prvků pole desetinných čísel s jednoduchou přesností od zadaného indexu zadaným prvkem.
     */
    public static void fillTestCase10() {
        float[] a;
        String b;
        a = new float[5];
        Arrays.fill(a, 1, 4, 8.0F);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění pole 32-bitových celých čísel zadaným prvkem.
     */
    public static void fillTestCase11() {
        int[] a;
        String b;
        a = new int[5];
        Arrays.fill(a, 8);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění zadaného počtu prvků pole 32-bitových celých čísel od zadaného indexu zadaným prvkem.
     */
    public static void fillTestCase12() {
        int[] a;
        String b;
        a = new int[5];
        Arrays.fill(a, 1, 4, 8);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění pole 64-bitových celých čísel zadaným prvkem.
     */
    public static void fillTestCase13() {
        long[] a;
        String b;
        a = new long[5];
        Arrays.fill(a, 8L);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění zadaného počtu prvků pole 64-bitových celých čísel od zadaného indexu zadaným prvkem.
     */
    public static void fillTestCase14() {
        long[] a;
        String b;
        a = new long[5];
        Arrays.fill(a, 1, 4, 8L);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění pole objektů zadaným prvkem.
     */
    public static void fillTestCase15() {
        DummyObject[] a;
        String b;
        a = new DummyObject[5];
        Arrays.fill(a, new DummyObject("sixth", 6));
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění zadaného počtu prvků pole objektů od zadaného indexu zadaným prvkem.
     */
    public static void fillTestCase16() {
        DummyObject[] a;
        String b;
        a = new DummyObject[5];
        Arrays.fill(a, 1, 4, new DummyObject("sixth", 6));
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění pole 16-bitových celých čísel zadaným prvkem.
     */
    public static void fillTestCase17() {
        short[] a;
        String b;
        a = new short[5];
        Arrays.fill(a, (short)8);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje naplnění zadaného počtu prvků pole 16-bitových celých čísel od zadaného indexu zadaným prvkem.
     */
    public static void fillTestCase18() {
        short[] a;
        String b;
        a = new short[5];
        Arrays.fill(a, 1, 4, (short)8);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení pole 8-bitových celých čísel.
     */
    public static void sortTestCase() {
        byte[] a;
        String b;
        a = new byte[]{(byte)3, (byte)2, (byte)8, (byte)7, (byte)6};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení zadaného počtu prvků pole 8-bitových celých čísel od zadaného indexu.
     */
    public static void sortTestCase2() {
        byte[] a;
        String b;
        a = new byte[]{(byte)3, (byte)2, (byte)8, (byte)7, (byte)6};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení pole znaků.
     */
    public static void sortTestCase3() {
        char[] a;
        String b;
        a = new char[]{'c', 'b', 'h', 'g', 'f'};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení zadaného počtu prvků pole znaků od zadaného indexu.
     */
    public static void sortTestCase4() {
        char[] a;
        String b;
        a = new char[]{'c', 'b', 'h', 'g', 'f'};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení pole desetinných čísel s dvojitou přesností.
     */
    public static void sortTestCase5() {
        double[] a;
        String b;
        a = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení zadaného počtu prvků pole desetinných čísel s dvojitou přesností od zadaného indexu.
     */
    public static void sortTestCase6() {
        double[] a;
        String b;
        a = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení pole desetinných čísel s jednoduchou přesností.
     */
    public static void sortTestCase7() {
        float[] a;
        String b;
        a = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení zadaného počtu prvků pole desetinných čísel s jednoduchou přesností od zadaného indexu.
     */
    public static void sortTestCase8() {
        float[] a;
        String b;
        a = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení pole 32-bitových celých čísel.
     */
    public static void sortTestCase9() {
        int[] a;
        String b;
        a = new int[]{3, 2, 8, 7, 6};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení zadaného počtu prvků pole 32-bitových celých čísel od zadaného indexu.
     */
    public static void sortTestCase10() {
        int[] a;
        String b;
        a = new int[]{3, 2, 8, 7, 6};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení pole 64-bitových celých čísel.
     */
    public static void sortTestCase11() {
        long[] a;
        String b;
        a = new long[]{3L, 2L, 8L, 7L, 6L};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení zadaného počtu prvků pole 64-bitových celých čísel od zadaného indexu.
     */
    public static void sortTestCase12() {
        long[] a;
        String b;
        a = new long[]{3L, 2L, 8L, 7L, 6L};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení pole porovnatelných objektů.
     */
    public static void sortTestCase13() {
        DummyObject[] a;
        String b;
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 6),
            new DummyObject("sixth", 3),
            new DummyObject("seventh", 2),
            new DummyObject("eighth", 8),
            new DummyObject("nineth", 7),
            new DummyObject("tenth", 6)
        };
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení zadaného počtu prvků pole porovnatelných objektů od zadaného indexu.
     */
    public static void sortTestCase14() {
        DummyObject[] a;
        String b;
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 6),
            new DummyObject("sixth", 3),
            new DummyObject("seventh", 2),
            new DummyObject("eighth", 8),
            new DummyObject("nineth", 7),
            new DummyObject("tenth", 6)
        };
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení pole 16-bitových celých čísel.
     */
    public static void sortTestCase15() {
        short[] a;
        String b;
        a = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
        Arrays.sort(a);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení zadaného počtu prvků pole 16-bitových celých čísel od zadaného indexu.
     */
    public static void sortTestCase16() {
        short[] a;
        String b;
        a = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
        Arrays.sort(a, 1, 4);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení pole objektů podle zadaného komparátoru.
     */
    public static void sortTestCase17() {
        DummyObject[] a;
        String b;
        DummyObjectComparer c;
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 6),
            new DummyObject("sixth", 3),
            new DummyObject("seventh", 2),
            new DummyObject("eighth", 8),
            new DummyObject("nineth", 7),
            new DummyObject("tenth", 6)
        };
        c = new DummyObjectComparer();
        Arrays.sort(a, c);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje řazení zadaného počtu prvků pole objektů podle zadaného komparátoru od zadaného indexu.
     */
    public static void sortTestCase18() {
        DummyObject[] a;
        String b;
        DummyObjectComparer c;
        a = new DummyObject[]{
            new DummyObject("first", 3),
            new DummyObject("second", 2),
            new DummyObject("third", 8),
            new DummyObject("fourth", 7),
            new DummyObject("fifth", 6),
            new DummyObject("sixth", 3),
            new DummyObject("seventh", 2),
            new DummyObject("eighth", 8),
            new DummyObject("nineth", 7),
            new DummyObject("tenth", 6)
        };
        c = new DummyObjectComparer();
        Arrays.sort(a, 1, 4, c);
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace pole logických hodnot.
     */
    public static void toStringTestCase() {
        boolean[] a;
        String b;
        a = new boolean[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new boolean[]{true};
        b = Arrays.toString(a);
        logger.info(b);
        a = new boolean[]{true, false, false, false, true};
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace pole 8-bitových celých čísel.
     */
    public static void toStringTestCase2() {
        byte[] a;
        String b;
        a = new byte[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new byte[]{(byte)3};
        b = Arrays.toString(a);
        logger.info(b);
        a = new byte[]{(byte)3, (byte)2, (byte)8, (byte)7, (byte)6};
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace pole znaků.
     */
    public static void toStringTestCase3() {
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
     * Otestuje vytvoření textové reprezentace pole desetinných čísel s dvojitou přesností.
     */
    public static void toStringTestCase4() {
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
     * Otestuje vytvoření textové reprezentace pole desetinných čísel s jednoduchou přesností.
     */
    public static void toStringTestCase5() {
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
     * Otestuje vytvoření textové reprezentace pole 32-bitových celých čísel.
     */
    public static void toStringTestCase6() {
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
     * Otestuje vytvoření textové reprezentace pole 64-bitových celých čísel.
     */
    public static void toStringTestCase7() {
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
     * Otestuje vytvoření textové reprezentace pole objektů.
     */
    public static void toStringTestCase8() {
        DummyObject[] a;
        String b;
        a = new DummyObject[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new DummyObject[]{new DummyObject("first", 1)};
        b = Arrays.toString(a);
        logger.info(b);
        a = new DummyObject[]{null};
        b = Arrays.toString(a);
        logger.info(b);
        a = new DummyObject[]{new DummyObject("first", 1), new DummyObject("second", 2), new DummyObject("third", 3)};
        b = Arrays.toString(a);
        logger.info(b);
        a = new DummyObject[]{new DummyObject("first", 1), null, new DummyObject("third", 3)};
        b = Arrays.toString(a);
        logger.info(b);
        a = new DummyObject[]{null, null, null};
        b = Arrays.toString(a);
        logger.info(b);
    }
    
    /**
     * Otestuje vytvoření textové reprezentace pole 16-bitových celých čísel.
     */
    public static void toStringTestCase9() {
        short[] a;
        String b;
        a = new short[]{};
        b = Arrays.toString(a);
        logger.info(b);
        a = new short[]{(short)3};
        b = Arrays.toString(a);
        logger.info(b);
        a = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
        b = Arrays.toString(a);
        logger.info(b);
    }
    
}
