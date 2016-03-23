package test;

import java.util.ArrayList;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code ArrayListTest} class performs automatic testing of the
 * {@code ArrayList} class.
 *
 * @author Petr Kozler
 */
public class ArrayListTest {

    public static Logger logger = LogManager.getLogger(ArrayListTest.class.getName());

    public static void runTestSuite() {
        ArrayListTest.arrayListTest();
        ArrayListTest.arrayListTest2();
        ArrayListTest.addTest();
        ArrayListTest.addTest2();
        ArrayListTest.getTest();
        ArrayListTest.setTest();
        ArrayListTest.removeTest();
        ArrayListTest.sizeTest();
        ArrayListTest.isEmptyTest();
        ArrayListTest.clearTest();
        ArrayListTest.toStringTest();
    }

    /**
     * Tests the constructor.
     */
    public static void arrayListTest() {
        ArrayList<TestObject> a;
        String b;
        // empty list
        a = new ArrayList<>();
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the constructor with ArrayList as a parameter.
     */
    public static void arrayListTest2() {
        ArrayList<TestObject> a, b;
        TestObject c;
        String d;
        // creating the list from an empty list
        a = new ArrayList<>();
        b = new ArrayList<>(a);
        d = b.toString();
        logger.info(d);
        // creating the list from a list with one element
        a = new ArrayList<>();
        c = new TestObject("first", 1);
        a.add(c);
        b = new ArrayList<>(a);
        d = b.toString();
        logger.info(d);
        // creating the list from a list with some elements
        a = new ArrayList<>();
        c = new TestObject("first", 1);
        a.add(c);
        c = new TestObject("second", 2);
        a.add(c);
        c = new TestObject("third", 3);
        a.add(c);
        b = new ArrayList<>(a);
        d = b.toString();
        logger.info(d);
    }

    /**
     * Tests the add method.
     */
    public static void addTest() {
        ArrayList<TestObject> a;
        TestObject b;
        String c;
        // adding some elements at the end of the list
        a = new ArrayList<>();
        b = new TestObject("first", 1);
        a.add(b);
        c = a.toString();
        logger.info(c);
        b = new TestObject("second", 2);
        a.add(b);
        c = a.toString();
        logger.info(c);
        b = new TestObject("first", 2);
        a.add(b);
        c = a.toString();
        logger.info(c);
        b = new TestObject("second", 1);
        a.add(b);
        c = a.toString();
        logger.info(c);
        b = new TestObject("first", 1);
        a.add(b);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the add method with index as a parameter.
     */
    public static void addTest2() {
        ArrayList<TestObject> a;
        TestObject b;
        String c;
        a = new ArrayList<>();
        // adding an element at the beginning
        b = new TestObject("first", 1);
        a.add(0, b);
        c = a.toString();
        logger.info(c);
        // adding an element at the end
        b = new TestObject("second", 2);
        a.add(1, b);
        c = a.toString();
        logger.info(c);
        // adding an element at the beginning
        b = new TestObject("third", 3);
        a.add(0, b);
        c = a.toString();
        logger.info(c);
        // adding an element in the middle
        b = new TestObject("fourth", 4);
        a.add(1, b);
        c = a.toString();
        logger.info(c);
        // adding an element in the middle
        b = new TestObject("fifth", 5);
        a.add(2, b);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the get method.
     */
    public static void getTest() {
        ArrayList<TestObject> a;
        TestObject b;
        String c;
        a = new ArrayList<>();
        // getting an element from the beginning
        b = new TestObject("first", 1);
        a.add(b);
        b = a.get(0);
        c = b.toString();
        logger.info(c);
        // getting an element from the beginning (more elements in the list)
        b = new TestObject("second", 2);
        a.add(b);
        b = a.get(0);
        c = b.toString();
        logger.info(c);
        // getting an element from the end
        b = a.get(1);
        c = b.toString();
        logger.info(c);
        b = new TestObject("third", 3);
        a.add(b);
        b = new TestObject("fourth", 4);
        a.add(b);
        b = new TestObject("fifth", 5);
        a.add(b);
        // getting an element from the beginning
        b = a.get(0);
        c = b.toString();
        logger.info(c);
        // getting an element from the end
        b = a.get(4);
        c = b.toString();
        logger.info(c);
    }

    /**
     * Tests the set method.
     */
    public static void setTest() {
        ArrayList<TestObject> a;
        TestObject b;
        String c;
        a = new ArrayList<>();
        b = new TestObject("first", 1);
        a.add(b);
        b = new TestObject("second", 2);
        a.add(b);
        b = new TestObject("third", 3);
        a.add(b);
        b = new TestObject("fourth", 4);
        a.add(b);
        b = new TestObject("fifth", 5);
        a.add(b);
        b = new TestObject("sixth", 6);
        // replacing an element at the beginning
        a.set(0, b);
        c = a.toString();
        logger.info(c);
        // replacing an element in the middle
        b = new TestObject("seventh", 7);
        a.set(2, b);
        c = a.toString();
        logger.info(c);
        // replacing an element at the end
        b = new TestObject("eighth", 8);
        a.set(4, b);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the remove method.
     */
    public static void removeTest() {
        ArrayList<TestObject> a;
        TestObject b;
        String c;
        a = new ArrayList<>();
        b = new TestObject("first", 1);
        a.add(b);
        b = new TestObject("second", 2);
        a.add(b);
        b = new TestObject("third", 3);
        a.add(b);
        b = new TestObject("fourth", 4);
        a.add(b);
        b = new TestObject("fifth", 5);
        // removing an element from the beginning
        a.add(b);
        a.remove(0);
        c = a.toString();
        logger.info(c);
        // removing the element from the middle
        a.remove(1);
        c = a.toString();
        logger.info(c);
        // removing an element from the end
        a.remove(2);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the size method.
     */
    public static void sizeTest() {
        ArrayList<TestObject> a;
        TestObject b;
        int c;
        a = new ArrayList<>();
        // size in the beginning
        c = a.size();
        logger.info(c);
        b = new TestObject("first", 1);
        // size after adding one element
        a.add(b);
        c = a.size();
        logger.info(c);
        // size after adding more elements
        b = new TestObject("second", 2);
        a.add(b);
        b = new TestObject("third", 3);
        a.add(b);
        c = a.size();
        logger.info(c);
        // size after removing one element
        a.remove(0);
        c = a.size();
        logger.info(c);
        // size after removing more elements
        a.remove(0);
        a.remove(0);
        c = a.size();
        logger.info(c);
    }

    /**
     * Tests the isEmpty method.
     */
    public static void isEmptyTest() {
        ArrayList<TestObject> a;
        TestObject b;
        boolean c;
        a = new ArrayList<>();
        c = a.isEmpty();
        logger.info(c);
        b = new TestObject("first", 1);
        a.add(b);
        c = a.isEmpty();
        logger.info(c);
        b = new TestObject("second", 2);
        a.add(b);
        b = new TestObject("third", 3);
        a.add(b);
        c = a.isEmpty();
        logger.info(c);
        a.remove(0);
        c = a.isEmpty();
        logger.info(c);
        a.remove(0);
        a.remove(0);
        c = a.isEmpty();
        logger.info(c);
    }

    /**
     * Tests the clear method.
     */
    public static void clearTest() {
        ArrayList<TestObject> a;
        TestObject b;
        String c;
        a = new ArrayList<>();
        // clear in the beginning
        a.clear();
        c = a.toString();
        logger.info(c);
        // clear after adding one element
        b = new TestObject("first", 1);
        a.add(b);
        a.clear();
        c = a.toString();
        logger.info(c);
        // clear after adding more elements
        b = new TestObject("first", 1);
        a.add(b);
        b = new TestObject("second", 2);
        a.add(b);
        b = new TestObject("third", 3);
        a.add(b);
        a.clear();
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the toString method.
     */
    public static void toStringTest() {
        ArrayList<TestObject> a;
        TestObject b;
        String c;
        // the text representation of an empty list
        a = new ArrayList<>();
        c = a.toString();
        logger.info(c);
        // the text representation of a list with one element
        b = new TestObject("first", 1);
        a.add(b);
        c = a.toString();
        logger.info(c);
        // the text representation of a list with some elements
        b = new TestObject("second", 2);
        a.add(b);
        b = new TestObject("third", 3);
        a.add(b);
        c = a.toString();
        logger.info(c);
    }

}
