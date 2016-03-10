using System.Collections.Generic;

namespace JavaClasses {

    /**
     * This class consists exclusively of static methods that operate on or return collections.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public static class Collections {

        /**
         * Searches the specified list for the specified object using the binary search algorithm.
         */
        public static int binarySearch<T>(ArrayList<T> list, T key) {
            return list.l.BinarySearch(key);
        }

        /**
         * Searches the specified list for the specified object using the binary search algorithm.
         */
        public static int binarySearch<T>(ArrayList<T> list, T key, Comparer<T> c) {
            return list.l.BinarySearch(key, c);
        }

        /**
         * Copies all of the elements from one list into another.
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
         * Replaces all of the elements of the specified list with the specified element.
         */
        public static void fill<T>(ArrayList<T> list, T obj) {
            List<T> l = list.l;

            // replacing the elements of the list with the specified value
            for (int i = 0; i < l.Count; i++) {
                l[i] = obj;
            }
        }

        /**
         * Sorts the specified list into ascending order, according to the natural ordering of its elements.
         */
        public static void sort<T>(ArrayList<T> list) {
            list.l.Sort();
        }

        /**
         * Sorts the specified list according to the order induced by the specified comparator
         */
        public static void sort<T>(ArrayList<T> list, Comparer<T> c) {
            list.l.Sort(c);
        }
    }
}
