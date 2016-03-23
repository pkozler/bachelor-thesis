using System;

namespace JavaClasses
{
    abstract class Comparable<T> : IComparable<T>
    {
        public abstract int compareTo(T o);

        public int CompareTo(T o)
        {
            return compareTo(o);
        }
    }
}
