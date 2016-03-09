using System;
using System.Collections.Generic;

namespace JavaClasses {

    /**
     * This class contains various methods for manipulating arrays (such as sorting and searching).
     *
     * @author Petr Kozler (A13B0359P)
     */
    public static class Arrays {
        
        // komparátor pro porovnání 8-bitových celých čísel
        private class ByteComparer : IComparer<sbyte> {
            int IComparer<sbyte>.Compare(sbyte x, sbyte y) {
                return Byte.compare(x, y);
            }
        }

        // komparátor pro porovnání znaků
        private class CharacterComparer : IComparer<char> {
            int IComparer<char>.Compare(char x, char y) {
                return Character.compare(x, y);
            }
        }
        
        // komparátor pro porovnání desetinných čísel s dvojitou přesností
        private class DoubleComparer : IComparer<double> {
            int IComparer<double>.Compare(double x, double y) {
                return Double.compare(x, y);
            }
        }
        
        // komparátor pro porovnání desetinných čísel s jednoduchou přesností
        private class FloatComparer : IComparer<float> {
            int IComparer<float>.Compare(float x, float y) {
                return Float.compare(x, y);
            }
        }

        // komparátor pro porovnání 32-bitových celých čísel
        private class IntegerComparer : IComparer<int> {
            int IComparer<int>.Compare(int x, int y) {
                return Integer.compare(x, y);
            }
        }

        // komparátor pro porovnání 64-bitových celých čísel
        private class LongComparer : IComparer<long> {
            int IComparer<long>.Compare(long x, long y) {
                return Long.compare(x, y);
            }
        }

        // komparátor pro porovnání 16-bitových celých čísel
        private class ShortComparer : IComparer<short> {
            int IComparer<short>.Compare(short x, short y) {
                return Short.compare(x, y);
            }
        }
        
        // delegát pro definici porovnávací metody předávané metodám pro porovnání pole
        private delegate bool equalsDelegate<T>(T o1, T o2);
        
        /*
         * Provede binární vyhledávání ve zvolené části pole prvků
         * libovolného datového typu podle předané porovnávací třídy.
         * Předpokládá, že zvolená část pole je seřazená.
         */
        private static int binarySearchGeneric<T>(T[] a, int? fromIndex, int? toIndex, T key, IComparer<T> c = null) {
            int fromIndexValue = fromIndex ?? 0;
            int toIndexValue = toIndex ?? a.Length;

            // vyhledávání bez komparátoru
            if (c == null) {
                return Array.BinarySearch(a, fromIndexValue, toIndexValue - fromIndexValue, key);
            }

            // vyhledávání s komparátorem
            return Array.BinarySearch(a, fromIndexValue, toIndexValue - fromIndexValue, key, c);
        }

        /*
         * Provede kopírování zvolené části pole prvků libovolného datového typu.
         */
        private static T[] copyOfRangeGeneric<T>(T[] original, int? from, int to) {
            int fromValue = from ?? 0;

            // nové pole s velikostí, která je rovna rozdílu hranic původního pole
            T[] a = new T[to - fromValue];

            // zvolená horní hranice je větší než délka původního pole
            if (to > original.Length) {
                // kopírování hodnot z původního pole do jeho posledního prvku
                for (int i = fromValue; i < original.Length; i++) {
                    a[i - fromValue] = original[i];
                }

                // naplnění zbytku nového pole výchozími hodnotami daného typu
                for (int i = original.Length; i < to; i++) {
                    a[i - fromValue] =
                     default(T);
                }
            }
            // zvolená horní hranice je menší
            else {
                // kopírování hodnot z původního pole do prvku na zvolené horní hranici
                for (int i = fromValue; i < to; i++) {
                    a[i - fromValue] = original[i];
                }
            }

            return a;
        }

        /*
         * Provede porovnání dvou polí prvků libovolného datového typu
         * podle předané srovnávací metody.
         */
        private static bool equalsGeneric<T>(T[] a, T[] a2, equalsDelegate<T> equals) {
            // porovnání referencí
            if (a == a2) {
                return true;
            }

            // test na nulové hodnoty referencí
            if (a == null || a2 == null) {
                return false;
            }

            int length = a.Length;

            // porovnání délek polí
            if (a2.Length != length) {
                return false;
            }

            // porovnání jednotlivých prvků
            for (int i = 0; i < length; i++) {
                if (!equals(a[i], a2[i])) {
                    return false;
                }
            }

            return true;
        }

        /*
         * Provede naplnění zvolené části pole prvků libovolného datového typu předanou hodnotou.
         */
        private static void fillGeneric<T>(T[] a, int? fromIndex, int? toIndex, T val) {
            int fromIndexValue = fromIndex ?? 0;
            int toIndexValue = toIndex ?? a.Length;
            
            // kopírování jednotlivých prvků
            for (int i = fromIndexValue; i < toIndexValue; i++) {
                a[i] = val;
            }
        }

        /*
         * Provede seřazení zvolené části pole prvků
         * libovolného datového typu podle předané porovnávací třídy.
         */
        private static void sortGeneric<T>(T[] a, int? fromIndex = null, int? toIndex = null, IComparer<T> c = null) {
            int fromIndexValue = fromIndex ?? 0;
            int toIndexValue = toIndex ?? a.Length;

            // řazení bez komparátoru
            if (c == null) {
                Array.Sort(a, fromIndexValue, toIndexValue - fromIndexValue);
            }
            // řazení s komparátorem
            else
            {
                Array.Sort(a, fromIndexValue, toIndexValue - fromIndexValue, c);
            }
        }

        /*
         * Provede vytvoření textové reprezentace pole prvků libovolného datového typu.
         */
        private static String toStringGeneric<T>(T[] a) {
            return "[" + string.Join(", ", a) + "]";
        }

        /**
         * Searches the specified array of sbytes for the specified value using the binary search algorithm
         */
        public static int binarySearch(sbyte[] a, sbyte key) {
            return binarySearchGeneric(a, null, null, key, new ByteComparer());
        }

        /**
         * Searches a range of the specified array of sbytes for the specified value using the binary search algorithm.
         */
        public static int binarySearch(sbyte[] a, int fromIndex, int toIndex, sbyte key) {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new ByteComparer());
        }

        /**
         * Searches the specified array of chars for the specified value using the binary search algorithm.
         */
        public static int binarySearch(char[] a, char key) {
            return binarySearchGeneric(a, null, null, key, new CharacterComparer());
        }

        /**
         * Searches a range of the specified array of chars for the specified value using the binary search algorithm.
         */
        public static int binarySearch(char[] a, int fromIndex, int toIndex, char key) {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new CharacterComparer());
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
            return binarySearchGeneric(a, fromIndex, toIndex, key, new DoubleComparer());
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
            return binarySearchGeneric(a, fromIndex, toIndex, key, new FloatComparer());
        }

        /**
         * Searches the specified array of ints for the specified value using the binary search algorithm.
         */
        public static int binarySearch(int[] a, int key) {
            return binarySearchGeneric(a, null, null, key, new IntegerComparer());
        }

        /**
         * Searches a range of the specified array of ints for the specified value using the binary search algorithm.
         */
        public static int binarySearch(int[] a, int fromIndex, int toIndex, int key) {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new IntegerComparer());
        }

        /**
         * Searches the specified array of longs for the specified value using the binary search algorithm.
         */
        public static int binarySearch(long[] a, long key) {
            return binarySearchGeneric(a, null, null, key, new LongComparer());
        }

        /**
         * Searches a range of the specified array of longs for the specified value using the binary search algorithm.
         */
        public static int binarySearch(long[] a, int fromIndex, int toIndex, long key) {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new LongComparer());
        }

        /**
         * Searches the specified array for the specified object using the binary search algorithm.
         */
        public static int binarySearch(Object[] a, Object key) {
            return binarySearchGeneric(a, null, null, key);
        }

        /**
         * Searches a range of the specified array for the specified object using the binary search algorithm.
         */
        public static int binarySearch(Object[] a, int fromIndex, int toIndex, Object key) {
            return binarySearchGeneric(a, fromIndex, toIndex, key);
        }

        /**
         * Searches the specified array of shorts for the specified value using the binary search algorithm.
         */
        public static int binarySearch(short[] a, short key) {
            return binarySearchGeneric(a, null, null, key, new ShortComparer());
        }

        /**
         * Searches a range of the specified array of shorts for the specified value using the binary search algorithm.
         */
        public static int binarySearch(short[] a, int fromIndex, int toIndex, short key) {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new ShortComparer());
        }

        /**
         * Searches the specified array for the specified object using the binary search algorithm.
         */
        public static int binarySearch<T>(T[] a, T key, Comparer<T> c) {
            return binarySearchGeneric(a, null, null, key, c);
        }

        /**
         * Searches a range of the specified array for the specified object using the binary search algorithm.
         */
        public static int binarySearch<T>(T[] a, int fromIndex, int toIndex, T key, Comparer<T> c) {
            return binarySearchGeneric(a, fromIndex, toIndex, key, c);
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
            return equalsGeneric(a, a2, (x, y) => { return new Boolean(x).equals(new Boolean(y)); });
        }

        /**
         * Returns true if the two specified arrays of sbytes are equal to one another.
         */
        public static bool equals(sbyte[] a, sbyte[] a2) {
            return equalsGeneric(a, a2, (x, y) => { return new Byte(x).equals(new Byte(y)); });
        }

        /**
         * Returns true if the two specified arrays of chars are equal to one another.
         */
        public static bool equals(char[] a, char[] a2) {
            return equalsGeneric(a, a2, (x, y) => { return new Character(x).equals(new Character(y)); });
        }

        /**
         * Returns true if the two specified arrays of doubles are equal to one another.
         */
        public static bool equals(double[] a, double[] a2) {
            return equalsGeneric(a, a2, (x, y) => { return new Double(x).equals(new Double(y)); });
        }

        /**
         * Returns true if the two specified arrays of floats are equal to one another.
         */
        public static bool equals(float[] a, float[] a2) {
            return equalsGeneric(a, a2, (x, y) => { return new Float(x).equals(new Float(y)); });
        }

        /**
         * Returns true if the two specified arrays of ints are equal to one another.
         */
        public static bool equals(int[] a, int[] a2) {
            return equalsGeneric(a, a2, (x, y) => { return new Integer(x).equals(new Integer(y)); });
        }

        /**
         * Returns true if the two specified arrays of longs are equal to one another.
         */
        public static bool equals(long[] a, long[] a2) {
            return equalsGeneric(a, a2, (x, y) => { return new Long(x).equals(new Long(y)); });
        }

        /**
         * Returns true if the two specified arrays of Objects are equal to one another.
         */
        public static bool equals(Object[] a, Object[] a2) {
            return equalsGeneric(a, a2, (o1, o2) => { return (o1 == null ? o2 == null : o1.Equals(o2)); });
        }

        /**
         * Returns true if the two specified arrays of shorts are equal to one another.
         */
        public static bool equals(short[] a, short[] a2) {
            return equalsGeneric(a, a2, (x, y) => { return new Short(x).equals(new Short(y)); });
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
            sortGeneric(a, null, null, new ByteComparer());
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(sbyte[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex, new ByteComparer());
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(char[] a) {
            sortGeneric(a, null, null, new CharacterComparer());
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(char[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex, new CharacterComparer());
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(double[] a) {
            sortGeneric(a, null, null, new DoubleComparer());
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(double[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex, new DoubleComparer());
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(float[] a) {
            sortGeneric(a, null, null, new FloatComparer());
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(float[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex, new FloatComparer());
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(int[] a) {
            sortGeneric(a, null, null, new IntegerComparer());
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(int[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex, new IntegerComparer());
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(long[] a) {
            sortGeneric(a, null, null, new LongComparer());
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(long[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex, new LongComparer());
        }

        /**
         * Sorts the specified array of objects into ascending order,
         * according to the natural ordering of its elements.
         */
        public static void sort(Object[] a) {
            sortGeneric(a);
        }

        /**
         * Sorts the specified range of the specified array of objects into ascending order,
         * according to the natural ordering of its elements.
         */
        public static void sort(Object[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex);
        }

        /**
         * Sorts the specified array into ascending numerical order.
         */
        public static void sort(short[] a) {
            sortGeneric(a, null, null, new ShortComparer());
        }

        /**
         * Sorts the specified range of the array into ascending order.
         */
        public static void sort(short[] a, int fromIndex, int toIndex) {
            sortGeneric(a, fromIndex, toIndex, new ShortComparer());
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
            sortGeneric(a, fromIndex, toIndex, c);
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