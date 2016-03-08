package test;

import java.util.Comparator;

/**
 * The {@code DummyObjectComparer} class represents a comparator
 * for the {@code DummyObject} class instances.
 *
 * @author Petr Kozler
 */
public class DummyObjectComparer implements Comparator<DummyObject> {

    /**
     * Compares its two arguments for order.
     *
     * @param o1 first object
     * @param o2 second object
     * @return comparison result
     */
    @Override
    public int compare(DummyObject o1, DummyObject o2) {
        return o1.getI() - o2.getI();
    }

}
