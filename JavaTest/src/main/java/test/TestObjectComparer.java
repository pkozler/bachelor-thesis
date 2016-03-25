package test;

import java.util.Comparator;

/**
 * The {@code TestObjectComparer} class represents a comparator
 * for the {@code TestObject} class instances.
 *
 * @author Petr Kozler
 */
public class TestObjectComparer implements Comparator<TestObject> {

    /**
     * Compares its two arguments for order.
     *
     * @param o1 first object
     * @param o2 second object
     * @return comparison result
     */
    @Override
    public int compare(TestObject o1, TestObject o2) {
        return o1.getI() - o2.getI();
    }

}
