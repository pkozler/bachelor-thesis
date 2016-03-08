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
        ArrayListTest.arrayListTestCase();
        ArrayListTest.arrayListTestCase2();
        ArrayListTest.addTestCase();
        ArrayListTest.addTestCase2();
        ArrayListTest.getTestCase();
        ArrayListTest.setTestCase();
        ArrayListTest.removeTestCase();
        ArrayListTest.sizeTestCase();
        ArrayListTest.isEmptyTestCase();
        ArrayListTest.clearTestCase();
        ArrayListTest.toStringTestCase();
    }

    /**
     * Tests the constructor.
     */
    public static void arrayListTestCase() {
        ArrayList<DummyObject> a;
        String b;
        // empty list
        a = new ArrayList<>();
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the constructor with ArrayList as a parameter.
     */
    public static void arrayListTestCase2() {
        ArrayList<DummyObject> a, b;
        DummyObject c;
        String d;
        // creating the list from an empty list
        a = new ArrayList<>();
        b = new ArrayList<>(a);
        d = b.toString();
        logger.info(d);
        // creating the list from a list with one element
        a = new ArrayList<>();
        c = new DummyObject("first", 1);
        a.add(c);
        b = new ArrayList<>(a);
        d = b.toString();
        logger.info(d);
        // creating the list from a list with some elements
        a = new ArrayList<>();
        c = new DummyObject("first", 1);
        a.add(c);
        c = new DummyObject("second", 2);
        a.add(c);
        c = new DummyObject("third", 3);
        a.add(c);
        b = new ArrayList<>(a);
        d = b.toString();
        logger.info(d);
    }

    /**
     * Tests the add method.
     */
    public static void addTestCase() {
        ArrayList<DummyObject> a;
        DummyObject b;
        String c;
        // adding some elements at the end of the list
        a = new ArrayList<>();
        b = new DummyObject("first", 1);
        a.add(b);
        c = a.toString();
        logger.info(c);
        b = new DummyObject("second", 2);
        a.add(b);
        c = a.toString();
        logger.info(c);
        b = new DummyObject("first", 2);
        a.add(b);
        c = a.toString();
        logger.info(c);
        b = new DummyObject("second", 1);
        a.add(b);
        c = a.toString();
        logger.info(c);
        b = new DummyObject("first", 1);
        a.add(b);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the add method with index as a parameter.
     */
    public static void addTestCase2() {
        ArrayList<DummyObject> a;
        DummyObject b;
        String c;
        a = new ArrayList<>();
        // adding an element at the beginning
        b = new DummyObject("first", 1);
        a.add(0, b);
        c = a.toString();
        logger.info(c);
        // adding an element at the end
        b = new DummyObject("second", 2);
        a.add(1, b);
        c = a.toString();
        logger.info(c);
        // adding an element at the beginning
        b = new DummyObject("third", 3);
        a.add(0, b);
        c = a.toString();
        logger.info(c);
        // adding an element in the middle
        b = new DummyObject("fourth", 4);
        a.add(1, b);
        c = a.toString();
        logger.info(c);
        // adding an element in the middle
        b = new DummyObject("fifth", 5);
        a.add(2, b);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the get method.
     */
    public static void getTestCase() {
        ArrayList<DummyObject> a;
        DummyObject b;
        String c;
        a = new ArrayList<>();
        // getting an element from the beginning
        b = new DummyObject("first", 1);
        a.add(b);
        b = a.get(0);
        c = b.toString();
        logger.info(c);
        // getting an element from the beginning (more elements in the list)
        b = new DummyObject("second", 2);
        a.add(b);
        b = a.get(0);
        c = b.toString();
        logger.info(c);
        // getting an element from the end
        b = a.get(1);
        c = b.toString();
        logger.info(c);
        b = new DummyObject("third", 3);
        a.add(b);
        b = new DummyObject("fourth", 4);
        a.add(b);
        b = new DummyObject("fifth", 5);
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
    public static void setTestCase() {
        ArrayList<DummyObject> a;
        DummyObject b;
        String c;
        a = new ArrayList<>();
        b = new DummyObject("first", 1);
        a.add(b);
        b = new DummyObject("second", 2);
        a.add(b);
        b = new DummyObject("third", 3);
        a.add(b);
        b = new DummyObject("fourth", 4);
        a.add(b);
        b = new DummyObject("fifth", 5);
        a.add(b);
        b = new DummyObject("sixth", 6);
        // replacing an element at the beginning
        a.set(0, b);
        c = a.toString();
        logger.info(c);
        // replacing an element in the middle
        b = new DummyObject("seventh", 7);
        a.set(2, b);
        c = a.toString();
        logger.info(c);
        // replacing an element at the end
        b = new DummyObject("eighth", 8);
        a.set(4, b);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the remove method.
     */
    public static void removeTestCase() {
        ArrayList<DummyObject> a;
        DummyObject b;
        String c;
        a = new ArrayList<>();
        b = new DummyObject("first", 1);
        a.add(b);
        b = new DummyObject("second", 2);
        a.add(b);
        b = new DummyObject("third", 3);
        a.add(b);
        b = new DummyObject("fourth", 4);
        a.add(b);
        b = new DummyObject("fifth", 5);
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
    public static void sizeTestCase() {
        ArrayList<DummyObject> a;
        DummyObject b;
        int c;
        a = new ArrayList<>();
        // size in the beginning
        c = a.size();
        logger.info(c);
        b = new DummyObject("first", 1);
        // size after adding one element
        a.add(b);
        c = a.size();
        logger.info(c);
        // size after adding more elements
        b = new DummyObject("second", 2);
        a.add(b);
        b = new DummyObject("third", 3);
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
    public static void isEmptyTestCase() {
        ArrayList<DummyObject> a;
        DummyObject b;
        boolean c;
        a = new ArrayList<>();
        c = a.isEmpty();
        logger.info(c);
        b = new DummyObject("first", 1);
        a.add(b);
        c = a.isEmpty();
        logger.info(c);
        b = new DummyObject("second", 2);
        a.add(b);
        b = new DummyObject("third", 3);
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
    public static void clearTestCase() {
        ArrayList<DummyObject> a;
        DummyObject b;
        String c;
        a = new ArrayList<>();
        // clear in the beginning
        a.clear();
        c = a.toString();
        logger.info(c);
        // clear after adding one element
        b = new DummyObject("first", 1);
        a.add(b);
        a.clear();
        c = a.toString();
        logger.info(c);
        // clear after adding more elements
        b = new DummyObject("first", 1);
        a.add(b);
        b = new DummyObject("second", 2);
        a.add(b);
        b = new DummyObject("third", 3);
        a.add(b);
        a.clear();
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the toString method.
     */
    public static void toStringTestCase() {
        ArrayList<DummyObject> a;
        DummyObject b;
        String c;
        // the text representation of an empty list
        a = new ArrayList<>();
        c = a.toString();
        logger.info(c);
        // the text representation of a list with one element
        b = new DummyObject("first", 1);
        a.add(b);
        c = a.toString();
        logger.info(c);
        // the text representation of a list with some elements
        b = new DummyObject("second", 2);
        a.add(b);
        b = new DummyObject("third", 3);
        a.add(b);
        c = a.toString();
        logger.info(c);
    }

}
