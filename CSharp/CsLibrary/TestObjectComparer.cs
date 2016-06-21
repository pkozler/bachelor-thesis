using System;
using System.Collections.Generic;

namespace JavaClasses
{
    
    /// <summary>
    /// The TestObjectComparator class represents a comparator
    /// for the TestObject class instances.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class TestObjectComparator : Comparator {
        
        /// <summary>
        /// Compares its two arguments for order.
        /// </summary>
        /// <param name="o1">first object</param>
        /// <param name="o2">second object</param>
        /// <returns>comparison result</returns>
        public override int compare(Object o1, Object o2) {
            return (o1 as TestObject).getI() - (o2 as TestObject).getI();
        }
        
    }

}
