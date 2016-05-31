﻿using System;
using System.Collections.Generic;

namespace JavaClasses
{

    /**
     * The {@code TestObjectComparator} class represents a comparator
     * for the {@code TestObject} class instances.
     *
     * @author Petr Kozler
     */
    public class TestObjectComparator : Comparator {
        
        /**
         * Compares its two arguments for order.
         *
         * @param o1 first object
         * @param o2 second object
         * @return comparison result
         */
        public override int compare(Object o1, Object o2) {
            return (o1 as TestObject).getI() - (o2 as TestObject).getI();
        }
        
    }

}
