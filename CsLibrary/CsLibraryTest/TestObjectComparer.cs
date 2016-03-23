using System;
using System.Collections.Generic;

namespace JavaClasses
{

    /**
     * The {@code TestObjectComparer} class represents a comparator
     * for the {@code TestObject} class instances.
     *
     * @author Petr Kozler
     */
    public class TestObjectComparer : IComparer<TestObject> {

        /*
            Calls the object comparison.
        */
        public int Compare(TestObject x, TestObject y)
        {
            return compare(x, y);
        }
        
        /**
         * Compares its two arguments for order.
         *
         * @param o1 first object
         * @param o2 second object
         * @return comparison result
         */
        public int compare(TestObject o1, TestObject o2) {
            return (o1 as TestObject).getI() - (o2 as TestObject).getI();
        }
        
    }

}
