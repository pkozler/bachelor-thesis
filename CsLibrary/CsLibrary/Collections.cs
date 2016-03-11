using System.Collections.Generic;

namespace JavaClasses {

    /**
     * This class consists exclusively of static methods that operate on or return collections.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public static class Collections {

        /**
         * Searches the specified list for the specified object using the binary
         * search algorithm.
         *
         * @param list the list to be searched.
         * @param key the key to be searched for.
         * @return the index of the search key, if it is contained in the list;
         * otherwise, (-(insertion point) - 1). The insertion point is defined as
         * the point at which the key would be inserted into the list: the index of
         * the first element greater than the key, or list.size() if all elements in
         * the list are less than the specified key. Note that this guarantees that
         * the return value will be >= 0 if and only if the key is found.
         */
        public static int binarySearch<T>(ArrayList<T> list, T key) {
            return list.l.BinarySearch(key);
        }

        /**
         * Searches the specified list for the specified object using the binary
         * search algorithm.
         *
         * @param list the list to be searched.
         * @param key the key to be searched for.
         * @param c the comparator by which the list is ordered. A null value
         * indicates that the elements' natural ordering should be used.
         * @return the index of the search key, if it is contained in the list;
         * otherwise, (-(insertion point) - 1). The insertion point is defined as
         * the point at which the key would be inserted into the list: the index of
         * the first element greater than the key, or list.size() if all elements in
         * the list are less than the specified key. Note that this guarantees that
         * the return value will be >= 0 if and only if the key is found.
         */
        public static int binarySearch<T>(ArrayList<T> list, T key, Comparer<T> c) {
            return list.l.BinarySearch(key, c);
        }

        /**
         * Copies all of the elements from one list into another.
         *
         * @param dest The destination list.
         * @param src The source list.
         */
        public static void copy<T>(ArrayList<T> dest, ArrayList<T> src) {
            List<T> destList = dest.l;
            List<T> srcList = src.l;

            // replacing the elements of the destination list with the elements of the source list
            for (int i = 0; i < srcList.Count; i++) {
                destList[i] = srcList[i];
            }
        }

        /**
         * Replaces all of the elements of the specified list with the specified
         * element.
         *
         * @param list the list to be filled with the specified element.
         * @param obj The element with which to fill the specified list.
         */
        public static void fill<T>(ArrayList<T> list, T obj) {
            List<T> l = list.l;

            // replacing the elements of the list with the specified value
            for (int i = 0; i < l.Count; i++) {
                l[i] = obj;
            }
        }

        /**
         * Sorts the specified list into ascending order, according to the natural
         * ordering of its elements.
         *
         * @param list the list to be sorted.
         */
        public static void sort<T>(ArrayList<T> list) {
            list.l.Sort();
        }

        /**
         * Sorts the specified list according to the order induced by the specified
         * comparator
         *
         * @param list the list to be sorted.
         * @param c the comparator to determine the order of the list. A null value
         * indicates that the elements' natural ordering should be used.
         */
        public static void sort<T>(ArrayList<T> list, Comparer<T> c) {
            list.l.Sort(c);
        }

    }

}
