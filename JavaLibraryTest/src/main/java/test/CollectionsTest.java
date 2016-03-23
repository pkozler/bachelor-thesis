package test;

import java.util.ArrayList;
import java.util.Collections;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * The {@code CollectionsTest} class performs automatic testing of the
 * {@code Collections} class.
 *
 * @author Petr Kozler
 */
public class CollectionsTest {

    public static Logger logger = LogManager.getLogger(CollectionsTest.class.getName());

    public static void runTestSuite() {
        CollectionsTest.binarySearchTest();
        CollectionsTest.binarySearchTest2();
        CollectionsTest.copyTest();
        CollectionsTest.fillTest();
        CollectionsTest.sortTest();
        CollectionsTest.sortTest2();
    }

    /**
     * Tests the binarySearch method.
     */
    public static void binarySearchTest() {
        ArrayList<TestObject> a;
        int b;
        a = new ArrayList<>();
        a.add(new TestObject("first", 3));
        a.add(new TestObject("second", 2));
        a.add(new TestObject("third", 8));
        a.add(new TestObject("fourth", 7));
        a.add(new TestObject("fifth", 6));
        a.add(new TestObject("sixth", 3));
        a.add(new TestObject("seventh", 2));
        a.add(new TestObject("eighth", 8));
        a.add(new TestObject("nineth", 7));
        a.add(new TestObject("tenth", 6));
        Collections.sort(a);
        b = Collections.binarySearch(a, new TestObject("sixth", 6));
        logger.info(b);
        b = Collections.binarySearch(a, new TestObject("sixth", 4));
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with comparator as a parameter.
     */
    public static void binarySearchTest2() {
        ArrayList<TestObject> a;
        int b;
        TestObjectComparer c;
        a = new ArrayList<>();
        a.add(new TestObject("first", 3));
        a.add(new TestObject("second", 2));
        a.add(new TestObject("third", 8));
        a.add(new TestObject("fourth", 7));
        a.add(new TestObject("fifth", 6));
        a.add(new TestObject("sixth", 3));
        a.add(new TestObject("seventh", 2));
        a.add(new TestObject("eighth", 8));
        a.add(new TestObject("nineth", 7));
        a.add(new TestObject("tenth", 6));
        c = new TestObjectComparer();
        Collections.sort(a);
        b = Collections.binarySearch(a, new TestObject("sixth", 6), c);
        logger.info(b);
        b = Collections.binarySearch(a, new TestObject("sixth", 4), c);
        logger.info(b);
    }

    /**
     * Tests the copy method.
     */
    public static void copyTest() {
        ArrayList<TestObject> a, b;
        String c;
        // source list
        a = new ArrayList<>();
        a.add(new TestObject("first", 3));
        a.add(new TestObject("second", 2));
        a.add(new TestObject("third", 8));
        a.add(new TestObject("fourth", 7));
        a.add(new TestObject("fifth", 6));
        // destination list
        b = new ArrayList<>();
        b.add(new TestObject("zeroth", 0));
        b.add(new TestObject("zeroth", 0));
        b.add(new TestObject("zeroth", 0));
        b.add(new TestObject("zeroth", 0));
        b.add(new TestObject("zeroth", 0));
        b.add(new TestObject("zeroth", 0));
        Collections.copy(b, a);
        c = b.toString();
        logger.info(c);
    }

    /**
     * Tests the fill method.
     */
    public static void fillTest() {
        ArrayList<TestObject> a;
        String b;
        a = new ArrayList<>();
        a.add(new TestObject("first", 3));
        a.add(new TestObject("second", 2));
        a.add(new TestObject("third", 8));
        a.add(new TestObject("fourth", 7));
        a.add(new TestObject("fifth", 6));
        Collections.fill(a, new TestObject("sixth", 6));
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the sort method.
     */
    public static void sortTest() {
        ArrayList<TestObject> a;
        String b;
        a = new ArrayList<>();
        a.add(new TestObject("first", 3));
        a.add(new TestObject("second", 2));
        a.add(new TestObject("third", 8));
        a.add(new TestObject("fourth", 7));
        a.add(new TestObject("fifth", 6));
        a.add(new TestObject("sixth", 3));
        a.add(new TestObject("seventh", 2));
        a.add(new TestObject("eighth", 8));
        a.add(new TestObject("nineth", 7));
        a.add(new TestObject("tenth", 6));
        Collections.sort(a);
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the sort method with comparator as a parameter.
     */
    public static void sortTest2() {
        ArrayList<TestObject> a;
        String b;
        TestObjectComparer c;
        a = new ArrayList<>();
        a.add(new TestObject("first", 3));
        a.add(new TestObject("second", 2));
        a.add(new TestObject("third", 8));
        a.add(new TestObject("fourth", 7));
        a.add(new TestObject("fifth", 6));
        a.add(new TestObject("sixth", 3));
        a.add(new TestObject("seventh", 2));
        a.add(new TestObject("eighth", 8));
        a.add(new TestObject("nineth", 7));
        a.add(new TestObject("tenth", 6));
        c = new TestObjectComparer();
        Collections.sort(a, c);
        b = a.toString();
        logger.info(b);
    }

}
