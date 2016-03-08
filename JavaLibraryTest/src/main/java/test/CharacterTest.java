package test;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code CharacterTest} class performs automatic testing of the
 * {@code Character} class.
 *
 * @author Petr Kozler
 */
public class CharacterTest {

    public static Logger logger = LogManager.getLogger(CharacterTest.class.getName());

    public static void runTestSuite() {
        CharacterTest.charValueTestCase();
        CharacterTest.compareToTestCase();
        CharacterTest.compareTestCase();
        CharacterTest.equalsTestCase();
        CharacterTest.toStringTestCase();
        CharacterTest.toStringTestCase2();
        CharacterTest.isDigitTestCase();
        CharacterTest.isLetterTestCase();
    }

    /**
     * Tests the charValue method.
     */
    public static void charValueTestCase() {
        Character a;
        char b;
        // uppercase letter
        a = new Character('A');
        b = a.charValue();
        logger.info(b);
        // lowercase letter
        a = new Character('a');
        b = a.charValue();
        logger.info(b);
        // digit
        a = new Character('0');
        b = a.charValue();
        logger.info(b);
    }

    /**
     * Tests the compareTo method.
     */
    public static void compareToTestCase() {
        Character a, b;
        int c;
        // digit and uppercase letter
        a = new Character('9');
        b = new Character('Z');
        c = a.compareTo(b);
        logger.info(c);
        // lowercase letter and digit
        a = new Character('z');
        b = new Character('9');
        c = a.compareTo(b);
        logger.info(c);
        // lowercase and uppercase letters
        a = new Character('z');
        b = new Character('A');
        c = a.compareTo(b);
        logger.info(c);
        // uppercase and lowercase letters
        a = new Character('Z');
        b = new Character('a');
        c = a.compareTo(b);
        logger.info(c);
        // both chars are uppercase letters
        a = new Character('Z');
        b = new Character('Z');
        c = a.compareTo(b);
        logger.info(c);
        // both chars are lowercase letters
        a = new Character('a');
        b = new Character('a');
        c = a.compareTo(b);
        logger.info(c);
    }

    /**
     * Tests the compare method.
     */
    public static void compareTestCase() {
        char a, b;
        int c;
        a = '9';
        b = 'Z';
        c = Character.compare(a, b);
        logger.info(c);
        a = 'z';
        b = '9';
        c = Character.compare(a, b);
        logger.info(c);
        a = 'z';
        b = 'A';
        c = Character.compare(a, b);
        logger.info(c);
        a = 'Z';
        b = 'a';
        c = Character.compare(a, b);
        logger.info(c);
        a = 'Z';
        b = 'Z';
        c = Character.compare(a, b);
        logger.info(c);
        a = 'a';
        b = 'a';
        c = Character.compare(a, b);
        logger.info(c);
    }

    /**
     * Tests the equals method.
     */
    public static void equalsTestCase() {
        Character a, b;
        boolean c;
        a = new Character('9');
        b = new Character('Z');
        c = a.equals(b);
        logger.info(c);
        a = new Character('z');
        b = new Character('9');
        c = a.equals(b);
        logger.info(c);
        a = new Character('z');
        b = new Character('A');
        c = a.equals(b);
        logger.info(c);
        a = new Character('Z');
        b = new Character('a');
        c = a.equals(b);
        logger.info(c);
        a = new Character('Z');
        b = new Character('Z');
        c = a.equals(b);
        logger.info(c);
        a = new Character('a');
        b = new Character('a');
        c = a.equals(b);
        logger.info(c);
    }

    /**
     * Tests the toString method.
     */
    public static void toStringTestCase() {
        Character a;
        String b;
        // digit text representation
        a = new Character('0');
        b = a.toString();
        logger.info(b);
        // uppercase letter text representation
        a = new Character('A');
        b = a.toString();
        logger.info(b);
        // lowercase letter text representation
        a = new Character('a');
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the static toString method.
     */
    public static void toStringTestCase2() {
        Character a;
        String b;
        a = new Character('0');
        b = Character.toString(a);
        logger.info(b);
        a = new Character('A');
        b = Character.toString(a);
        logger.info(b);
        a = new Character('a');
        b = Character.toString(a);
        logger.info(b);
    }

    /**
     * Tests the isDigit method.
     */
    public static void isDigitTestCase() {
        Character a;
        boolean b;
        // lowercase letter
        a = new Character('a');
        b = Character.isDigit(a);
        logger.info(b);
        // uppercase letter
        a = new Character('Z');
        b = Character.isDigit(a);
        logger.info(b);
        // digit
        a = new Character('0');
        b = Character.isDigit(a);
        logger.info(b);
        // another digit
        a = new Character('9');
        b = Character.isDigit(a);
        logger.info(b);
        // whitespace
        a = new Character(' ');
        b = Character.isDigit(a);
        logger.info(b);
    }

    /**
     * Tests the isLetter method.
     */
    public static void isLetterTestCase() {
        Character a;
        boolean b;
        a = new Character('a');
        b = Character.isLetter(a);
        logger.info(b);
        a = new Character('Z');
        b = Character.isLetter(a);
        logger.info(b);
        a = new Character('0');
        b = Character.isLetter(a);
        logger.info(b);
        a = new Character('9');
        b = Character.isLetter(a);
        logger.info(b);
        a = new Character(' ');
        b = Character.isLetter(a);
        logger.info(b);
    }

}
