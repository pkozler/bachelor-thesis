package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code StringTest} class performs automatic testing of the {@code String}
 * class.
 *
 * @author Petr Kozler
 */
public class StringTest {

    public static Logger logger = LogManager.getLogger(StringTest.class.getName());

    public static void runTestSuite() {
        StringTest.stringTest();
        StringTest.stringTest2();
        StringTest.stringTest3();
        StringTest.compareToTest();
        StringTest.equalsTest();
        StringTest.substringTest();
        StringTest.substringTest2();
        StringTest.indexOfTest();
        StringTest.indexOfTest2();
        StringTest.indexOfTest3();
        StringTest.indexOfTest4();
        StringTest.lengthTest();
        StringTest.trimTest();
        StringTest.toLowerCaseTest();
        StringTest.toUpperCaseTest();
        StringTest.charAtTest();
        StringTest.replaceTest();
        StringTest.startsWithTest();
        StringTest.endsWithTest();
        StringTest.isEmptyTest();
        StringTest.toStringTest();
    }

    /**
     * Tests the constructor with standard string as a parameter.
     */
    public static void stringTest() {
        String a;
        // a string with whitespaces
        a = "This is a test.";
        logger.info(a);
        // letters
        a = "test";
        logger.info(a);
        // digits
        a = "1234";
        logger.info(a);
        // one char
        a = "a";
        logger.info(a);
        // empty string
        a = "";
        logger.info(a);
    }

    /**
     * Tests the constructor with array of bytes as a parameter.
     */
    public static void stringTest2() {
        byte[] a;
        String b;
        // array with some whitespaces
        a = new byte[]{'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '.'};
        b = new String(a);
        logger.info(b);
        // array without whitespaces
        a = new byte[]{'1', '2', '3', '4'};
        b = new String(a);
        logger.info(b);
        // empty array
        a = new byte[]{};
        b = new String(a);
        logger.info(b);
    }

    /**
     * Tests the constructor with array of bytes and indexes as parameters.
     */
    public static void stringTest3() {
        byte[] a;
        String b;
        // choosing a part of array with some chars
        a = new byte[]{'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'e', 's', 't', '.'};
        b = new String(a, 10, 4);
        logger.info(b);
    }

    /**
     * Tests the compareTo method.
     */
    public static void compareToTest() {
        String a, b;
        int c;
        // differens strings at the beginning
        a = "aaa";
        b = "bbb";
        c = a.compareTo(b);
        logger.info(c);
        // different strings at the end
        a = "aaaa";
        b = "aaab";
        c = a.compareTo(b);
        logger.info(c);
        // differens strings at the beginning (swapped)
        a = "bbb";
        b = "aaa";
        c = a.compareTo(b);
        logger.info(c);
        // different strings at the end (swapped)
        a = "aaab";
        b = "aaaa";
        c = a.compareTo(b);
        logger.info(c);
        // equal strings
        a = "aaa";
        b = "aaa";
        c = a.compareTo(b);
        logger.info(c);
    }

    /**
     * Tests the equals method.
     */
    public static void equalsTest() {
        String a, b;
        boolean c;
        a = "aaa";
        b = "bbb";
        c = a.equals(b);
        logger.info(c);
        a = "aaaa";
        b = "aaab";
        c = a.equals(b);
        logger.info(c);
        a = "bbb";
        b = "aaa";
        c = a.equals(b);
        logger.info(c);
        a = "aaab";
        b = "aaaa";
        c = a.equals(b);
        logger.info(c);
        a = "aaa";
        b = "aaa";
        c = a.equals(b);
        logger.info(c);
    }

    /**
     * Tests the substring method.
     */
    public static void substringTest() {
        String a, b;
        a = "This is a test.";
        // string from the beginning
        b = a.substring(0);
        logger.info(b);
        // string from some other position
        b = a.substring(10);
        logger.info(b);
    }

    /**
     * Tests the substring method with end index as a parameter.
     */
    public static void substringTest2() {
        String a, b;
        a = "This is a test.";
        // string from the beginning to the position near the beginning
        b = a.substring(0, 4);
        logger.info(b);
        // string from the beginning to the position far from the beginning
        b = a.substring(10, 14);
        logger.info(b);
        // string from the end
        b = a.substring(14, 15);
        logger.info(b);
        // equal indexes
        b = a.substring(10, 10);
        logger.info(b);
    }

    /**
     * Tests the indexOf method with a char value.
     */
    public static void indexOfTest() {
        String a;
        int b;
        a = "This is a test.";
        // char occurring once
        b = a.indexOf('a');
        logger.info(b);
        // char occuring more times
        b = a.indexOf('t');
        logger.info(b);
        // char occurring once (at the beginning)
        b = a.indexOf('T');
        logger.info(b);
        // char occurring once (at the end)
        b = a.indexOf('.');
        logger.info(b);
        // char not occurring
        b = a.indexOf('_');
        logger.info(b);
    }

    /**
     * Tests the indexOf method with a char value and end index as a parameter.
     */
    public static void indexOfTest2() {
        String a;
        int b;
        a = "This is a test.";
        b = a.indexOf('a', 10);
        logger.info(b);
        b = a.indexOf('t', 10);
        logger.info(b);
        b = a.indexOf('i', 0);
        logger.info(b);
        b = a.indexOf('i', 4);
        logger.info(b);
        b = a.indexOf('i', 10);
        logger.info(b);
    }

    /**
     * Tests the indexOf method with a string.
     */
    public static void indexOfTest3() {
        String a;
        int b;
        a = "This is a test.";
        // occurring string (at the beginning)
        b = a.indexOf("This");
        logger.info(b);
        // occurring string (at the end)
        b = a.indexOf("test");
        logger.info(b);
        // non-occurring string
        b = a.indexOf("aaa");
        logger.info(b);
    }

    /**
     * Tests the indexOf method with a string and end index as a parameter.
     */
    public static void indexOfTest4() {
        String a;
        int b;
        a = "This is a test.";
        b = a.indexOf("This", 0);
        logger.info(b);
        b = a.indexOf("test", 4);
        logger.info(b);
        b = a.indexOf("This", 10);
        logger.info(b);
    }

    /**
     * Tests the length method.
     */
    public static void lengthTest() {
        String a;
        int b;
        // string with multiple chars
        a = "This is a test.";
        b = a.length();
        logger.info(b);
        // string with one char
        a = ".";
        b = a.length();
        logger.info(b);
        // empty string
        a = "";
        b = a.length();
        logger.info(b);
    }

    /**
     * Tests the trim method.
     */
    public static void trimTest() {
        String a, b;
        // string without whitespaces
        a = "test";
        b = a.trim();
        logger.info(b);
        // whitespaces on the left side
        a = "   test";
        b = a.trim();
        logger.info(b);
        // whitespaces on the right side
        a = "test   ";
        b = a.trim();
        logger.info(b);
        // whitespaces on bots sides
        a = " test ";
        b = a.trim();
        logger.info(b);
        // whitespaces inside
        a = "t e s t";
        b = a.trim();
        logger.info(b);
    }

    /**
     * Tests the toLower method.
     */
    public static void toLowerCaseTest() {
        String a, b;
        // all letters lowercase
        a = "test";
        b = a.toLowerCase();
        logger.info(b);
        // all letters uppercase
        a = "TEST";
        b = a.toLowerCase();
        logger.info(b);
        // different cases
        a = "TesT";
        b = a.toLowerCase();
        logger.info(b);
    }

    /**
     * Tests the toUpper method.
     */
    public static void toUpperCaseTest() {
        String a, b;
        a = "test";
        b = a.toUpperCase();
        logger.info(b);
        a = "TEST";
        b = a.toUpperCase();
        logger.info(b);
        a = "TesT";
        b = a.toUpperCase();
        logger.info(b);
    }

    /**
     * Tests the charAt method.
     */
    public static void charAtTest() {
        String a;
        char b;
        a = "This is a test.";
        // at the beginning
        b = a.charAt(0);
        logger.info(b);
        // in the middle
        b = a.charAt(10);
        logger.info(b);
        // at the end
        b = a.charAt(14);
        logger.info(b);
    }

    /**
     * Tests the replace method.
     */
    public static void replaceTest() {
        String a, b;
        a = "This is a test.";
        // replacing chars inside the string
        b = a.replace(' ', '_');
        logger.info(b);
        // replacing chars in the beginning of the string
        b = a.replace('T', 't');
        logger.info(b);
        // replacing chars in the end of the string
        b = a.replace('.', '!');
        logger.info(b);
        // replacing of the non-existent chars
        b = a.replace('?', ':');
        logger.info(b);
    }

    /**
     * Tests the startsWith method.
     */
    public static void startsWithTest() {
        String a, b;
        boolean c;
        a = "This is a test.";
        // string at the beginning
        b = "This ";
        c = a.startsWith(b);
        logger.info(c);
        // string inside
        b = "is";
        c = a.startsWith(b);
        logger.info(c);
        // string at the end
        b = "test.";
        c = a.startsWith(b);
        logger.info(c);
    }

    /**
     * Tests the endsWith method.
     */
    public static void endsWithTest() {
        String a, b;
        boolean c;
        a = "This is a test.";
        b = "This ";
        c = a.endsWith(b);
        logger.info(c);
        b = "is";
        c = a.endsWith(b);
        logger.info(c);
        b = "test.";
        c = a.endsWith(b);
        logger.info(c);
    }

    /**
     * Tests the isEmpty method.
     */
    public static void isEmptyTest() {
        String a;
        boolean b;
        // non-empty string
        a = "This is a test.";
        b = a.isEmpty();
        logger.info(b);
        // non-empty string with a single char
        a = ".";
        b = a.isEmpty();
        logger.info(b);
        // empty string
        a = "";
        b = a.isEmpty();
        logger.info(b);
    }

    /**
     * Tests the toString method.
     */
    public static void toStringTest() {
        String a, b;
        // multiple chars
        a = "This is a test.";
        b = a.toString();
        logger.info(b);
        // one char
        a = ".";
        b = a.toString();
        logger.info(b);
        // no char
        a = "";
        b = a.toString();
        logger.info(b);
    }

}
