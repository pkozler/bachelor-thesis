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
        CollectionsTest.binarySearchTestCase();
        CollectionsTest.binarySearchTestCase2();
        CollectionsTest.copyTestCase();
        CollectionsTest.fillTestCase();
        CollectionsTest.sortTestCase();
        CollectionsTest.sortTestCase2();
    }

    /**
     * Tests the binarySearch method.
     */
    public static void binarySearchTestCase() {
        ArrayList<DummyObject> a;
        int b;
        a = new ArrayList<>();
        a.add(new DummyObject("first", 3));
        a.add(new DummyObject("second", 2));
        a.add(new DummyObject("third", 8));
        a.add(new DummyObject("fourth", 7));
        a.add(new DummyObject("fifth", 6));
        a.add(new DummyObject("sixth", 3));
        a.add(new DummyObject("seventh", 2));
        a.add(new DummyObject("eighth", 8));
        a.add(new DummyObject("nineth", 7));
        a.add(new DummyObject("tenth", 6));
        Collections.sort(a);
        b = Collections.binarySearch(a, new DummyObject("sixth", 6));
        logger.info(b);
        b = Collections.binarySearch(a, new DummyObject("sixth", 4));
        logger.info(b);
    }

    /**
     * Tests the binarySearch method with comparator as a parameter.
     */
    public static void binarySearchTestCase2() {
        ArrayList<DummyObject> a;
        int b;
        DummyObjectComparer c;
        a = new ArrayList<>();
        a.add(new DummyObject("first", 3));
        a.add(new DummyObject("second", 2));
        a.add(new DummyObject("third", 8));
        a.add(new DummyObject("fourth", 7));
        a.add(new DummyObject("fifth", 6));
        a.add(new DummyObject("sixth", 3));
        a.add(new DummyObject("seventh", 2));
        a.add(new DummyObject("eighth", 8));
        a.add(new DummyObject("nineth", 7));
        a.add(new DummyObject("tenth", 6));
        c = new DummyObjectComparer();
        Collections.sort(a);
        b = Collections.binarySearch(a, new DummyObject("sixth", 6), c);
        logger.info(b);
        b = Collections.binarySearch(a, new DummyObject("sixth", 4), c);
        logger.info(b);
    }

    /**
     * Tests the copy method.
     */
    public static void copyTestCase() {
        ArrayList<DummyObject> a, b;
        String c;
        // source list
        a = new ArrayList<>();
        a.add(new DummyObject("first", 3));
        a.add(new DummyObject("second", 2));
        a.add(new DummyObject("third", 8));
        a.add(new DummyObject("fourth", 7));
        a.add(new DummyObject("fifth", 6));
        // destination list
        b = new ArrayList<>();
        b.add(new DummyObject("zeroth", 0));
        b.add(new DummyObject("zeroth", 0));
        b.add(new DummyObject("zeroth", 0));
        b.add(new DummyObject("zeroth", 0));
        b.add(new DummyObject("zeroth", 0));
        b.add(new DummyObject("zeroth", 0));
        Collections.copy(b, a);
        c = b.toString();
        logger.info(c);
    }

    /**
     * Tests the fill method.
     */
    public static void fillTestCase() {
        ArrayList<DummyObject> a;
        String b;
        a = new ArrayList<>();
        a.add(new DummyObject("first", 3));
        a.add(new DummyObject("second", 2));
        a.add(new DummyObject("third", 8));
        a.add(new DummyObject("fourth", 7));
        a.add(new DummyObject("fifth", 6));
        Collections.fill(a, new DummyObject("sixth", 6));
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the sort method.
     */
    public static void sortTestCase() {
        ArrayList<DummyObject> a;
        String b;
        a = new ArrayList<>();
        a.add(new DummyObject("first", 3));
        a.add(new DummyObject("second", 2));
        a.add(new DummyObject("third", 8));
        a.add(new DummyObject("fourth", 7));
        a.add(new DummyObject("fifth", 6));
        a.add(new DummyObject("sixth", 3));
        a.add(new DummyObject("seventh", 2));
        a.add(new DummyObject("eighth", 8));
        a.add(new DummyObject("nineth", 7));
        a.add(new DummyObject("tenth", 6));
        Collections.sort(a);
        b = a.toString();
        logger.info(b);
    }

    /**
     * Tests the sort method with comparator as a parameter.
     */
    public static void sortTestCase2() {
        ArrayList<DummyObject> a;
        String b;
        DummyObjectComparer c;
        a = new ArrayList<>();
        a.add(new DummyObject("first", 3));
        a.add(new DummyObject("second", 2));
        a.add(new DummyObject("third", 8));
        a.add(new DummyObject("fourth", 7));
        a.add(new DummyObject("fifth", 6));
        a.add(new DummyObject("sixth", 3));
        a.add(new DummyObject("seventh", 2));
        a.add(new DummyObject("eighth", 8));
        a.add(new DummyObject("nineth", 7));
        a.add(new DummyObject("tenth", 6));
        c = new DummyObjectComparer();
        Collections.sort(a, c);
        b = a.toString();
        logger.info(b);
    }

}
