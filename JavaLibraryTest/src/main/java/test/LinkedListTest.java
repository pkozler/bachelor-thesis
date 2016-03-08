package test;

import java.util.LinkedList;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code LinkedListTest} class performs automatic testing of the
 * {@code LinkedList} class.
 *
 * @author Petr Kozler
 */
public class LinkedListTest {

    public static Logger logger = LogManager.getLogger(LinkedListTest.class.getName());

    public static void runTestSuite() {
        LinkedListTest.linkedListTestCase();
        LinkedListTest.linkedListTestCase2();
        LinkedListTest.addTestCase();
        LinkedListTest.addTestCase2();
        LinkedListTest.getTestCase();
        LinkedListTest.setTestCase();
        LinkedListTest.removeTestCase();
        LinkedListTest.sizeTestCase();
        LinkedListTest.isEmptyTestCase();
        LinkedListTest.clearTestCase();
        LinkedListTest.toStringTestCase();
    }

    /**
     * Tests the constructor.
     */
    public static void linkedListTestCase() {
        LinkedList<DummyObject> a;
        String b;
        a = new LinkedList<>();
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the constructor with LinkedList as a parameter.
     */
    public static void linkedListTestCase2() {
        LinkedList<DummyObject> a, b;
        DummyObject c;
        String d;
        a = new LinkedList<>();
        b = new LinkedList<>(a);
        d = b.toString();
        logger.info(d);
        a = new LinkedList<>();
        c = new DummyObject("first", 1);
        a.add(c);
        b = new LinkedList<>(a);
        d = b.toString();
        logger.info(d);
        a = new LinkedList<>();
        c = new DummyObject("first", 1);
        a.add(c);
        c = new DummyObject("second", 2);
        a.add(c);
        c = new DummyObject("third", 3);
        a.add(c);
        b = new LinkedList<>(a);
        d = b.toString();
        logger.info(d);
    }

    /**
     * Tests the add method.
     */
    public static void addTestCase() {
        LinkedList<DummyObject> a;
        DummyObject b;
        String c;
        a = new LinkedList<>();
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
        LinkedList<DummyObject> a;
        DummyObject b;
        String c;
        a = new LinkedList<>();
        b = new DummyObject("first", 1);
        a.add(0, b);
        c = a.toString();
        logger.info(c);
        b = new DummyObject("second", 2);
        a.add(1, b);
        c = a.toString();
        logger.info(c);
        b = new DummyObject("third", 3);
        a.add(0, b);
        c = a.toString();
        logger.info(c);
        b = new DummyObject("fourth", 4);
        a.add(1, b);
        c = a.toString();
        logger.info(c);
        b = new DummyObject("fifth", 5);
        a.add(2, b);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the get method.
     */
    public static void getTestCase() {
        LinkedList<DummyObject> a;
        DummyObject b;
        String c;
        a = new LinkedList<>();
        b = new DummyObject("first", 1);
        a.add(b);
        b = a.get(0);
        c = b.toString();
        logger.info(c);
        b = new DummyObject("second", 2);
        a.add(b);
        b = a.get(0);
        c = b.toString();
        logger.info(c);
        b = a.get(1);
        c = b.toString();
        logger.info(c);
        b = new DummyObject("third", 3);
        a.add(b);
        b = new DummyObject("fourth", 4);
        a.add(b);
        b = new DummyObject("fifth", 5);
        a.add(b);
        b = a.get(0);
        c = b.toString();
        logger.info(c);
        b = a.get(4);
        c = b.toString();
        logger.info(c);
    }

    /**
     * Tests the set method.
     */
    public static void setTestCase() {
        LinkedList<DummyObject> a;
        DummyObject b;
        String c;
        a = new LinkedList<>();
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
        a.set(0, b);
        c = a.toString();
        logger.info(c);
        b = new DummyObject("seventh", 7);
        a.set(2, b);
        c = a.toString();
        logger.info(c);
        b = new DummyObject("eighth", 8);
        a.set(4, b);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the remove method.
     */
    public static void removeTestCase() {
        LinkedList<DummyObject> a;
        DummyObject b;
        String c;
        a = new LinkedList<>();
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
        a.remove(0);
        c = a.toString();
        logger.info(c);
        a.remove(1);
        c = a.toString();
        logger.info(c);
        a.remove(2);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the size method.
     */
    public static void sizeTestCase() {
        LinkedList<DummyObject> a;
        DummyObject b;
        int c;
        a = new LinkedList<>();
        c = a.size();
        logger.info(c);
        b = new DummyObject("first", 1);
        a.add(b);
        c = a.size();
        logger.info(c);
        b = new DummyObject("second", 2);
        a.add(b);
        b = new DummyObject("third", 3);
        a.add(b);
        c = a.size();
        logger.info(c);
        a.remove(0);
        c = a.size();
        logger.info(c);
        a.remove(0);
        a.remove(0);
        c = a.size();
        logger.info(c);
    }

    /**
     * Tests the isEmpty method.
     */
    public static void isEmptyTestCase() {
        LinkedList<DummyObject> a;
        DummyObject b;
        boolean c;
        a = new LinkedList<>();
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
        LinkedList<DummyObject> a;
        DummyObject b;
        String c;
        a = new LinkedList<>();
        a.clear();
        c = a.toString();
        logger.info(c);
        b = new DummyObject("first", 1);
        a.add(b);
        a.clear();
        c = a.toString();
        logger.info(c);
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
        LinkedList<DummyObject> a;
        DummyObject b;
        String c;
        a = new LinkedList<>();
        c = a.toString();
        logger.info(c);
        a = new LinkedList<>();
        b = new DummyObject("first", 1);
        a.add(b);
        c = a.toString();
        logger.info(c);
        a = new LinkedList<>();
        b = new DummyObject("first", 1);
        a.add(b);
        b = new DummyObject("second", 2);
        a.add(b);
        b = new DummyObject("third", 3);
        a.add(b);
        c = a.toString();
        logger.info(c);
    }

}
