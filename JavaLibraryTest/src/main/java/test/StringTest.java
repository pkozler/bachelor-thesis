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
        StringTest.stringTestCase();
        StringTest.stringTestCase2();
        StringTest.stringTestCase3();
        StringTest.compareToTestCase();
        StringTest.equalsTestCase();
        StringTest.substringTestCase();
        StringTest.substringTestCase2();
        StringTest.indexOfTestCase();
        StringTest.indexOfTestCase2();
        StringTest.indexOfTestCase3();
        StringTest.indexOfTestCase4();
        StringTest.lengthTestCase();
        StringTest.trimTestCase();
        StringTest.toLowerCaseTestCase();
        StringTest.toUpperCaseTestCase();
        StringTest.charAtTestCase();
        StringTest.replaceTestCase();
        StringTest.startsWithTestCase();
        StringTest.endsWithTestCase();
        StringTest.isEmptyTestCase();
        StringTest.toStringTestCase();
    }

    /**
     * Tests the constructor with standard string as a parameter.
     */
    public static void stringTestCase() {
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
    public static void stringTestCase2() {
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
    public static void stringTestCase3() {
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
    public static void compareToTestCase() {
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
    public static void equalsTestCase() {
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
    public static void substringTestCase() {
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
    public static void substringTestCase2() {
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
    public static void indexOfTestCase() {
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
    public static void indexOfTestCase2() {
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
    public static void indexOfTestCase3() {
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
    public static void indexOfTestCase4() {
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
    public static void lengthTestCase() {
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
    public static void trimTestCase() {
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
    public static void toLowerCaseTestCase() {
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
    public static void toUpperCaseTestCase() {
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
    public static void charAtTestCase() {
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
    public static void replaceTestCase() {
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
    public static void startsWithTestCase() {
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
    public static void endsWithTestCase() {
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
    public static void isEmptyTestCase() {
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
    public static void toStringTestCase() {
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
