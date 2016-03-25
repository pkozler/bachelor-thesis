using System.Collections.Generic;

namespace JavaClasses
{

    /// <summary>
    /// This class consists exclusively of static methods that operate on or return collections.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public static class Collections
    {

        /// <summary>
        /// Searches the specified list for the specified object using the binary
        /// search algorithm.
        /// </summary>
        /// <param name="list">the list to be searched.
        /// </param><param name="key">the key to be searched for.
        /// </param><returns>the index of the search key, if it is contained in the list;
        /// otherwise, (-(insertion point) - 1). The insertion point is defined as
        /// the point at which the key would be inserted into the list: the index of
        /// the first element greater than the key, or list.size() if all elements in
        /// the list are less than the specified key. Note that this guarantees that
        /// the return value will be >= 0 if and only if the key is found.
        /// </returns>
        public static int binarySearch<T>(ArrayList<T> list, T key) where T : Object
        {
            return list.l.BinarySearch(key);
        }

        /// <summary>
        /// Searches the specified list for the specified object using the binary
        /// search algorithm.
        /// </summary>
        /// <param name="list">the list to be searched.
        /// </param><param name="key">the key to be searched for.
        /// </param><param name="c">the comparator by which the list is ordered. A null value
        /// indicates that the elements' natural ordering should be used.
        /// </param><returns>the index of the search key, if it is contained in the list;
        /// otherwise, (-(insertion point) - 1). The insertion point is defined as
        /// the point at which the key would be inserted into the list: the index of
        /// the first element greater than the key, or list.size() if all elements in
        /// the list are less than the specified key. Note that this guarantees that
        /// the return value will be >= 0 if and only if the key is found.
        /// </returns>
        public static int binarySearch<T>(ArrayList<T> list, T key, IComparer<T> c) where T : Object
        {
            return list.l.BinarySearch(key, c);
        }

        /// <summary>
        /// Copies all of the elements from one list into another.
        /// </summary>
        /// <param name="dest">The destination list.
        /// </param><param name="src">The source list.
        /// </param>
        public static void copy<T>(List<T> dest, List<T> src) where T : Object
        {
            int length = src.size();

            // replacing the elements of the destination list with the elements of the source list
            for (int i = 0; i < length; i++)
            {
                dest.set(i, src.get(i));
            }
        }

        /// <summary>
        /// Replaces all of the elements of the specified list with the specified
        /// element.
        /// </summary>
        /// <param name="list">the list to be filled with the specified element.
        /// </param><param name="obj">The element with which to fill the specified list.
        /// </param>
        public static void fill<T>(List<T> list, T obj) where T : Object
        {
            int length = list.size();

            // replacing the elements of the list with the specified value
            for (int i = 0; i < length; i++)
            {
                list.set(i, obj);
            }
        }

        /// <summary>
        /// Sorts the specified list into ascending order, according to the natural
        /// ordering of its elements.
        /// </summary>
        /// <param name="list">the list to be sorted.
        /// </param>
        public static void sort<T>(ArrayList<T> list) where T : Object
        {
            list.l.Sort();
        }

        /// <summary>
        /// Sorts the specified list according to the order induced by the specified
        /// comparator
        /// </summary>
        /// <param name="list">the list to be sorted.
        /// </param><param name="c">the comparator to determine the order of the list. A null value
        /// indicates that the elements' natural ordering should be used.
        /// </param>
        public static void sort<T>(ArrayList<T> list, IComparer<T> c) where T : Object
        {
            list.l.Sort(c);
        }

    }

}
