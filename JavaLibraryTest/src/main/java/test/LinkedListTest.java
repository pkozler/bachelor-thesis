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
        LinkedListTest.linkedListTest();
        LinkedListTest.linkedListTest2();
        LinkedListTest.addTest();
        LinkedListTest.addTest2();
        LinkedListTest.getTest();
        LinkedListTest.setTest();
        LinkedListTest.removeTest();
        LinkedListTest.sizeTest();
        LinkedListTest.isEmptyTest();
        LinkedListTest.clearTest();
        LinkedListTest.toStringTest();
    }

    /**
     * Tests the constructor.
     */
    public static void linkedListTest() {
        LinkedList<TestObject> a;
        String b;
        a = new LinkedList<>();
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the constructor with LinkedList as a parameter.
     */
    public static void linkedListTest2() {
        LinkedList<TestObject> a, b;
        TestObject c;
        String d;
        a = new LinkedList<>();
        b = new LinkedList<>(a);
        d = b.toString();
        logger.info(d);
        a = new LinkedList<>();
        c = new TestObject("first", 1);
        a.add(c);
        b = new LinkedList<>(a);
        d = b.toString();
        logger.info(d);
        a = new LinkedList<>();
        c = new TestObject("first", 1);
        a.add(c);
        c = new TestObject("second", 2);
        a.add(c);
        c = new TestObject("third", 3);
        a.add(c);
        b = new LinkedList<>(a);
        d = b.toString();
        logger.info(d);
    }

    /**
     * Tests the add method.
     */
    public static void addTest() {
        LinkedList<TestObject> a;
        TestObject b;
        String c;
        a = new LinkedList<>();
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
        LinkedList<TestObject> a;
        TestObject b;
        String c;
        a = new LinkedList<>();
        b = new TestObject("first", 1);
        a.add(0, b);
        c = a.toString();
        logger.info(c);
        b = new TestObject("second", 2);
        a.add(1, b);
        c = a.toString();
        logger.info(c);
        b = new TestObject("third", 3);
        a.add(0, b);
        c = a.toString();
        logger.info(c);
        b = new TestObject("fourth", 4);
        a.add(1, b);
        c = a.toString();
        logger.info(c);
        b = new TestObject("fifth", 5);
        a.add(2, b);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the get method.
     */
    public static void getTest() {
        LinkedList<TestObject> a;
        TestObject b;
        String c;
        a = new LinkedList<>();
        b = new TestObject("first", 1);
        a.add(b);
        b = a.get(0);
        c = b.toString();
        logger.info(c);
        b = new TestObject("second", 2);
        a.add(b);
        b = a.get(0);
        c = b.toString();
        logger.info(c);
        b = a.get(1);
        c = b.toString();
        logger.info(c);
        b = new TestObject("third", 3);
        a.add(b);
        b = new TestObject("fourth", 4);
        a.add(b);
        b = new TestObject("fifth", 5);
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
    public static void setTest() {
        LinkedList<TestObject> a;
        TestObject b;
        String c;
        a = new LinkedList<>();
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
        a.set(0, b);
        c = a.toString();
        logger.info(c);
        b = new TestObject("seventh", 7);
        a.set(2, b);
        c = a.toString();
        logger.info(c);
        b = new TestObject("eighth", 8);
        a.set(4, b);
        c = a.toString();
        logger.info(c);
    }

    /**
     * Tests the remove method.
     */
    public static void removeTest() {
        LinkedList<TestObject> a;
        TestObject b;
        String c;
        a = new LinkedList<>();
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
    public static void sizeTest() {
        LinkedList<TestObject> a;
        TestObject b;
        int c;
        a = new LinkedList<>();
        c = a.size();
        logger.info(c);
        b = new TestObject("first", 1);
        a.add(b);
        c = a.size();
        logger.info(c);
        b = new TestObject("second", 2);
        a.add(b);
        b = new TestObject("third", 3);
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
    public static void isEmptyTest() {
        LinkedList<TestObject> a;
        TestObject b;
        boolean c;
        a = new LinkedList<>();
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
        LinkedList<TestObject> a;
        TestObject b;
        String c;
        a = new LinkedList<>();
        a.clear();
        c = a.toString();
        logger.info(c);
        b = new TestObject("first", 1);
        a.add(b);
        a.clear();
        c = a.toString();
        logger.info(c);
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
        LinkedList<TestObject> a;
        TestObject b;
        String c;
        a = new LinkedList<>();
        c = a.toString();
        logger.info(c);
        a = new LinkedList<>();
        b = new TestObject("first", 1);
        a.add(b);
        c = a.toString();
        logger.info(c);
        a = new LinkedList<>();
        b = new TestObject("first", 1);
        a.add(b);
        b = new TestObject("second", 2);
        a.add(b);
        b = new TestObject("third", 3);
        a.add(b);
        c = a.toString();
        logger.info(c);
    }

}
