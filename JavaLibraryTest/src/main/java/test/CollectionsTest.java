/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import java.util.ArrayList;
import java.util.Collections;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * Třída pro automatické testování knihovny Collections.
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
     * Otestuje binární vyhledávání v seznamu.
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
     * Otestuje binární vyhledávání v zadaném počtu prvků seznamu od zadaného indexu.
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
     * Otestuje kopírování prvků zdrojového seznamu do cílového seznamu.
     */
    public static void copyTestCase() {
        ArrayList<DummyObject> a, b;
        String c;
        a = new ArrayList<>();
        a.add(new DummyObject("first", 3));
        a.add(new DummyObject("second", 2));
        a.add(new DummyObject("third", 8));
        a.add(new DummyObject("fourth", 7));
        a.add(new DummyObject("fifth", 6));
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
     * Otestuje nahrazování prvků spojového seznamu zadaným prvkem.
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
     * Otestuje řazení seznamu.
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
     * Otestuje řazení zadaného počtu prvků seznamu od zadaného indexu.
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
