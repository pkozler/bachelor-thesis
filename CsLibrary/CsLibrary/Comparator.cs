using System.Collections.Generic;

namespace JavaClasses
{
    abstract class Comparator<T> : IComparer<T>
    {
        public abstract int compare(T o1, T o2);

        public int Compare(T o1, T o2)
        {
            return compare(o1, o2);
        }
    }
}
