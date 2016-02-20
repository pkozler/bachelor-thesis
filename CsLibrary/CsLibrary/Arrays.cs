using System;
using System.Text;
using System.Globalization;
using System.Collections.Generic;

namespace JavaClasses {

    /**
     * This class contains various methods for manipulating arrays (such as sorting and searching).
     *
     * @author Petr Kozler (A13B0359P)
     */
    public static class Arrays {
        private class DoubleComparer : IComparer<double> {
            int IComparer<double>.Compare(double x, double y) {
                Double d1 = new Double(x);
                Double d2 = new Double(y);

                return d1.compareTo(d2);
            }
        }

        private class FloatComparer : IComparer<float> {
            int IComparer<float>.Compare(float x, float y) {
                Float f1 = new Float(x);
                Float f2 = new Float(y);

                return f1.compareTo(f2);
            }
        }

        private delegate bool equalsDelegate<T>(T o1, T o2);

        private static bool equalsBool(bool a, bool b) {
            return a == b;
        }

        private static bool equalsB(sbyte a, sbyte b) {
            return a == b;
        }

        private static bool equalsC(char a, char b) {
            return a == b;
        }

        private static bool equalsD(double a, double b) {
            Double d1 = new Double(a);
            Double d2 = new Double(b);

            return d1.equals(d2);
        }

        private static bool equalsF(float a, float b) {
            Float f1 = new Float(a);
            Float f2 = new Float(a);

            return f1.equals(f2);
        }

        private static bool equalsI(int a, int b) {
            return a == b;
        }

        private static bool equalsL(long a, long b) {
            return a == b;
        }

        private static bool equalsS(short a, short b) {
            return a == b;
        }

        private static bool equalsObj(Object o1, Object o2) {
            return (o1 == null ? o2 == null : o1.Equals(o2));
        }

        private static int binarySearchGeneric<T>(T[] a, int? fromIndex, int? toIndex, T key, IComparer<T> c) {
            int fromIndexValue = fromIndex ?? 0;
            int toIndexValue = toIndex ?? a.Length;

            if (c == null) {
                return Array.BinarySearch(a, fromIndexValue, toIndexValue, key);
            }

            return Array.BinarySearch(a, fromIndexValue, toIndexValue, key, c);
        }

        private static T[] copyOfRangeGeneric<T>(T[] original, int? from, int to) {
            int fromValue = from ?? 0;

            T[] a = new T[to - fromValue];

            if (to > original.Length) {
                for (int i = fromValue; i < original.Length; i++) {
                    a[i - fromValue] = original[i];
                }

                for (int i = original.Length; i < to; i++) {
                    a[i - fromValue] =
                     default(T);
                }
            }
            else {
                for (int i = fromValue; i < to; i++) {
                    a[i - fromValue] = original[i];
                }
            }

            return a;
        }

        private static bool equalsGeneric<T>(T[] a, T[] a2, equalsDelegate<T> equals) {
            if (a == a2) {
                return true;
            }

            if (a == null || a2 == null) {
                return false;
            }

            int length = a.Length;

            if (a2.Length != length) {
                return false;
            }

            for (int i = 0; i < length; i++) {
                if (!equals(a[i], a2[i])) {
                    return false;
                }
            }

            return true;
        }

        private static void fillGeneric<T>(T[] a, int? fromIndex, int? toIndex, T val) {
            int fromIndexValue = fromIndex ?? 0;
            int toIndexValue = toIndex ?? a.Length;

            for (int i = fromIndexValue; i < toIndexValue; i++) {
                a[i] = val;
            }
        }

        private static void sortGeneric<T>(T[] a, int? fromIndex, int? toIndex, IComparer<T> c) {
            int fromIndexValue = fromIndex ?? 0;
            int toIndexValue = toIndex ?? a.Length;

            if (c == null) {
                Array.Sort(a, fromIndexValue, toIndexValue - fromIndexValue);
            }
            else {
                Array.Sort(a, fromIndexValue, toIndexValue - fromIndexValue, c);
            }
        }

        private static String toStringGeneric<T>(T[] a) {
            return toStringGeneric(a);
        }

        /**
         * Searches the specified array of sbytes for the specified value using the binary search algorithm
         */
        public static int binarySearch(sbyte[] a, sbyte key) {
            return binarySearchGeneric(a, null, null, key, null);
        }

        /**
         * Searches a range of the specified array of sbytes for the specified value using the binary search algorithm.
         */
        public static int binarySearch(sbyte[] a, int fromIndex, int toIndex, sbyte key) {
            return binarySearchGeneric(a, fromIndex, toIndex - fromIndex, key, null);
        }

        /**
         * Searches the specified array of chars for the specified value using the binary search algorithm.
         */
        public static int binarySearch(char[] a, char key) {
            return binarySearchGeneric(a, null, null, key, null);
        }

        /**
         * Searches a range of the specified array of chars for the specified value using the binary search algorithm.
         */
        public static int binarySearch(char[] a, int fromIndex, int toIndex, char key) {
            return binarySearchGeneric(a, fromIndex, toIndex - fromIndex, key, null);
        }

        /**
         * Searches the specified array of doubles for the specified value using the binary search algorithm.
         */
        public static int binarySearch(double[] a, double key) {
            return binarySearchGeneric(a, null, null, key, new DoubleComparer());
        }

        /**
         * Searches a range of the specified array of doubles for the specified value using the binary search algorithm.
         */
        public static int binarySearch(double[] a, int fromIndex, int toIndex, double key) {
            return binarySearchGeneric(a, fromIndex, toIndex - fromIndex, key, new DoubleComparer());
        }

        /**
         * Searches the specified array of floats for the specified value using the binary search algorithm.
         */
        public static int binarySearch(float[] a, float key) {
            return binarySearchGeneric(a, null, null, key, new FloatComparer());
        }

        /**
         * Searches a range of the specified array of floats for the specified value using the binary search algorithm.
         */
        public static int binarySearch(float[] a, int fromIndex, int toIndex, float key) {
            return binarySearchGeneric(a, fromIndex, toIndex - fromIndex, key, new FloatComparer());
        }

        /**
         * Searches the specified array of ints for the specified value using the binary search algorithm.
         */
        public static int binarySearch(int[] a, int key) {
            return binarySearchGeneric(a, null, null, key, null);
        }

        /**
         * Searches a range of the specified array of ints for the specified value using the binary search algorithm.
         */
        public static int binarySearch(int[] a, int fromIndex, int toIndex, int key) {
            return binarySearchGeneric(a, fromIndex, toIndex - fromIndex, key, null);
        }

        /**
         * Searches the specified array of longs for the specified value using the binary search algorithm.
         */
        public static int binarySearch(long[] a, long key) {
            return binarySearchGeneric(a, null, null, key, null);
        }

        /**
         * Searches a range of the specified array of longs for the specified value using the binary search algorithm.
         */
        public static int binarySearch(long[] a, int fromIndex, int toIndex, long key) {
            return binarySearchGeneric(a, fromIndex, toIndex - fromIndex, key, null);
        }

        /**
         * Searches the specified array for the specified object using the binary search algorithm.
         */
        public static int binarySearch(Object[] a, Object key) {
            return binarySearchGeneric(a, null, null, key, null);
        }

        /**
         * Searches a range of the specified array for the specified object using the binary search algorithm.
         */
        public static int binarySearch(Object[] a, int fromIndex, int toIndex, Object key) {
            return binarySearchGeneric(a, fromIndex, toIndex - fromIndex, key, null);
        }

        /**
         * Searches the specified array of shorts for the specified value using the binary search algorithm.
         */
        public static int binarySearch(short[] a, short key) {
            return binarySearchGeneric(a, null, null, key, null);
        }

        /**
         * Searches a range of the specified array of shorts for the specified value using the binary search algorithm.
         */
        public static int binarySearch(short[] a, int fromIndex, int toIndex, short key) {
            return binarySearchGeneric(a, fromIndex, toIndex - fromIndex, key, null);
        }

        /**
         * Searches the specified array for the specified object using the binary search algorithm.
         */
        public static int binarySearch<T>(T[] a, T key, Comparer<T> c) {
            return binarySearchGeneric(a, null, null, key, null);
        }

        /**
         * Searches a range of the specified array for the specified object using the binary search algorithm.
         */
        public static int binarySearch<T>(T[] a, int fromIndex, int toIndex, T key, Comparer<T> c) {
            return binarySearchGeneric(a, fromIndex, toIndex - fromIndex, key, null);
        }

        /**
         * Copies the specified array, truncating or padding with false (if necessary) so the copy has the specified length.
         */
        public static bool[] copyOf(bool[] original, int newLength) {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /**
         * Copies the specified array, truncating or padding with zeros (if necessary) so the copy has the specified length.
         */
        public static sbyte[] copyOf(sbyte[] original, int newLength) {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /**
         * Copies the specified array, truncating or padding with null characters (if necessary) so the copy has the specified length.
         */
        public static char[] copyOf(char[] original, int newLength) {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /**
         * Copies the specified array, truncating or padding with zeros (if necessary) so the copy has the specified length.
         */
        public static double[] copyOf(double[] original, int newLength) {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /**
         * Copies the specified array, truncating or padding with zeros (if necessary) so the copy has the specified length.
         */
        public static float[] copyOf(float[] original, int newLength) {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /**
         * Copies the specified array, truncating or padding with zeros (if necessary) so the copy has the specified length.
         */
        public static int[] copyOf(int[] original, int newLength) {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /**
         * Copies the specified array, truncating or padding with zeros (if necessary) so the copy has the specified length.
         */
        public static long[] copyOf(long[] original, int newLength) {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /**
         * Copies the specified array, truncating or padding with zeros (if necessary) so the copy has the specified length.
         */
        public static short[] copyOf(short[] original, int newLength) {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /**
         * Copies the specified array, truncating or padding with nulls (if necessary) so the copy has the specified length.
         */
        public static T[] copyOf<T>(T[] original, int newLength) {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /**
         * Copies the specified range of the specified array into a new array.
         */
        public static bool[] copyOfRange(bool[] original, int from, int to) {
            return copyOfRangeGeneric(original, from, to);
        }

        /**
         * Copies the specified range of the specified array into a new array.
         */
        public static sbyte[] copyOfRange(sbyte[] original, int from, int to) {
            return copyOfRangeGeneric(original, from, to);
        }

        /**
         * Copies the specified range of the specified array into a new array.
         */
        public static char[] copyOfRange(char[] original, int from, int to) {
            return copyOfRangeGeneric(original, from, to);
        }

        /**
         * Copies the specified range of the specified array into a new array.
         */
        public static double[] copyOfRange(double[] original, int from, int to) {
            return copyOfRangeGeneric(original, from, to);
        }

        /**
         * Copies the specified range of the specified array into a new array.
         */
        public static float[] copyOfRange(float[] original, int from, int to) {
            return copyOfRangeGeneric(original, from, to);
        }

        /**
         * Copies the specified range of the specified array into a new array.
         */
        public static int[] copyOfRange(int[] original, int from, int to) {
            return copyOfRangeGeneric(original, from, to);
        }

        /**
         * Copies the specified range of the specified array into a new array.
         */
        public static long[] copyOfRange(long[] original, int from, int to) {
            return copyOfRangeGeneric(original, from, to);
        }

        /**
         * Copies the specified range of the specified array into a new array.
         */
        public static short[] copyOfRange(short[] original, int from, int to) {
            return copyOfRangeGeneric(original, from, to);
        }

        /**
         * Copies the specified range of the specified array into a new array.
         */
        public static T[] copyOfRange<T>(T[] original, int from, int to) {
            return copyOfRangeGeneric(original, from, to);
        }

        /**
         * Returns true if the two specified arrays of booleans are equal to one another.
         */
        public static bool equals(bool[] a, bool[] a2) {
            return equalsGeneric(a, a2, equalsBool);
        }

        /**
         * Returns true if the two specified arrays of sbytes are equal to one another.
         */
        public static bool equals(sbyte[] a, sbyte[] a2) {
            return equalsGeneric(a, a2, equalsB);
        }

        /**
         * Returns true if the two specified arrays of chars are equal to one another.
         */
        public static bool equals(char[] a, char[] a2) {
            return equalsGeneric(a, a2, equalsC);
        }

        /**
         * Returns true if the two specified arrays of doubles are equal to one another.
         */
        public static bool equals(double[] a, double[] a2) {
            return equalsGeneric(a, a2, equalsD);
        }

        /**
         * Returns true if the two specified arrays of floats are equal to one another.
         */
        public static bool equals(float[] a, float[] a2) {
            return equalsGeneric(a, a2, equalsF);
        }

        /**
         * Returns true if the two specified arrays of ints are equal to one another.
         */
        public static bool equals(int[] a, int[] a2) {
            return equalsGeneric(a, a2, equalsI);
        }

        /**
         * Returns true if the two specified arrays of longs are equal to one another.
         */
        public static bool equals(long[] a, long[] a2) {
            return equalsGeneric(a, a2, equalsL);
        }

        /**
         * Returns true if the two specified arrays of Objects are equal to one another.
         */
        public static bool equals(Object[] a, Object[] a2) {
            return equalsGeneric(a, a2, equalsObj);
        }

        /**
         * Returns true if the two specified arrays of shorts are equal to one another.
         */
        public static bool equals(short[] a, short[] a2) {
            return equalsGeneric(a, a2, equalsS);
        }

        /**
         * Assigns the specified boolean value to each element of the specified array of booleans.
         */
        public static void fill(bool[] a, bool val) {
            fillGeneric(a, null, null, val);
        }

        /**
         * Assigns the specified boolean value to each element of the specified range of the specified array of booleans.
         */
        public static void fill(bool[] a, int fromIndex, int toIndex, bool val) {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /**
         * Assigns the specified sbyte value to each element of the specified array of sbytes.
         */
        public static void fill(sbyte[] a, sbyte val) {
            fillGeneric(a, null, null, val);
        }

        /**
         * Assigns the specified sbyte value to each element of the specified range of the specified array of sbytes.
         */
        public static void fill(sbyte[] a, int fromIndex, int toIndex, sbyte val) {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /**
         * Assigns the specified char value to each element of the specified array of chars.
         */
        public static void fill(char[] a, char val) {
            fillGeneric(a, null, null, val);
        }

        /**
         * Assigns the specified char value to each element of the specified range of the specified array of chars.
         */
        public static void fill(char[] a, int fromIndex, int toIndex, char val) {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /**
         * Assigns the specified double value to each element of the specified array of doubles.
         */
        public static void fill(double[] a, double val) {
            fillGeneric(a, null, null, val);
        }

        /**
         * Assigns the specified double value to each element of the specified range of the specified array of doubles.
         */
        public static void fill(double[] a, int fromIndex, int toIndex, double val) {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /**
         * Assigns the specified float value to each element of the specified array of floats.
         */
        public static void fill(float[] a, float val) {
            fillGeneric(a, null, null, val);
        }

        /**
         * Assigns the specified float value to each element of the specified range of the specified array of floats.
         */
        public static void fill(float[] a, int fromIndex, int toIndex, float val) {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /**
         * Assigns the specified int value to each element of the specified array of ints.
         */
        public static void fill(int[] a, int val) {
            fillGeneric(a, null, null, val);
        }

        /**
         * Assigns the specified int value to each element of the specified range of the specified array of ints.
         */
        public static void fill(int[] a, int fromIndex, int toIndex, int val) {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /**
         * Assigns the specified long value to each element of the specified array of longs.
         */
        public static void fill(long[] a, long val) {
            fillGeneric(a, null, null, val);
        }

        /**
         * Assigns the specified long value to each element of the specified range of the specified array of longs.
         */
        public static void fill(long[] a, int fromIndex, int toIndex, long val) {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /**
         * Assigns the specified Object reference to each element of the specified array of Objects.
         */
        public static void fill(Object[] a, Object val) {
            fillGeneric(a, null, null, val);
        }

        /**
         * Assigns the specified Object reference to each element of the specified range of the specified array of Objects.
         */
        public static void fill(Object[] a, int fromIndex, int toIndex, Object val) {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /**
         * Assigns the specified short value to each element of the specified array of shorts.
         */
        public static void fill(short[] a, short val) {
            fillGeneric(a, null, null, val);
        }

        /**
         * Assigns the specified short value to each element of the specified range of the specified array of shorts.
         */
        public static void fill(short[] a, int fromIndex, int toIndex, short val) {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(sbyte[] a) {
            sortGeneric(a, null, null, null);
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(sbyte[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex - fromIndex, null);
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(char[] a) {
            sortGeneric(a, null, null, null);
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(char[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex - fromIndex, null);
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(double[] a) {
            Array.Sort(a, new DoubleComparer());
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(double[] a, int fromIndex, int toIndex) {
            Array.Sort(a, fromIndex, toIndex - fromIndex, new DoubleComparer());
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(float[] a) {
            Array.Sort(a, new FloatComparer());
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(float[] a, int fromIndex, int toIndex) {
            Array.Sort(a, fromIndex, toIndex - fromIndex, new FloatComparer());
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(int[] a) {
            sortGeneric(a, null, null, null);
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(int[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex - fromIndex, null);
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(long[] a) {
            sortGeneric(a, null, null, null);
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(long[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex - fromIndex, null);
        }

        /**
         * Sorts the specified array of objects into ascending order,
         * according to the natural ordering of its elements.
         */
        public static void sort(Object[] a) {
            sortGeneric(a, null, null, null);
        }

        /**
         * Sorts the specified range of the specified array of objects into ascending order,
         * according to the natural ordering of its elements.
         */
        public static void sort(Object[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex - fromIndex, null);
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(short[] a) {
            sortGeneric(a, null, null, null);
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(short[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex - fromIndex, null);
        }

        /**
         * Sorts the specified array of objects according to the order induced by the specified comparator.
         */
        public static void sort<T>(T[] a, Comparer<T> c) {
            sortGeneric(a, null, null, c);
        }

        /**
         * Sorts the specified range of the specified array of objects according to the order induced by the specified comparator.
         */
        public static void sort<T>(T[] a, int fromIndex, int toIndex, Comparer<T> c) {
            sortGeneric(a, fromIndex, toIndex - fromIndex, c);
        }

        /**
         * Returns a string representation of the contents of the specified array.
         */
        public static String toString(bool[] a) {
            return toStringGeneric(a).toLowerCase();
        }

        /**
         * Returns a string representation of the contents of the specified array.
         */
        public static String toString(sbyte[] a) {
            return toStringGeneric(a);
        }

        /**
         * Returns a string representation of the contents of the specified array.
         */
        public static String toString(char[] a) {
            return toStringGeneric(a);
        }

        /**
         * Returns a string representation of the contents of the specified array.
         */
        public static String toString(double[] a) {
            return toStringGeneric(a);
        }

        /**
         * Returns a string representation of the contents of the specified array.
         */
        public static String toString(float[] a) {
            return toStringGeneric(a);
        }

        /**
         * Returns a string representation of the contents of the specified array.
         */
        public static String toString(int[] a) {
            return toStringGeneric(a);
        }

        /**
         * Returns a string representation of the contents of the specified array.
         */
        public static String toString(long[] a) {
            return toStringGeneric(a);
        }

        /**
         * Returns a string representation of the contents of the specified array.
         */
        public static String toString(Object[] a) {
            return toStringGeneric(a);
        }

        /**
         * Returns a string representation of the contents of the specified array.
         */
        public static String toString(short[] a) {
            return toStringGeneric(a);
        }
    }
}