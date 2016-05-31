using System;
using System.Collections.Generic;

namespace JavaClasses
{

    /// <summary>
    /// This class contains various methods for manipulating arrays (such as sorting and searching).
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public static class Arrays
    {

        // delegate for testing if two values are equal
        private delegate bool EqualsMethod<T>(T o1, T o2);

        // comparator for 8-bit signed integer values
        private class ByteComparer : IComparer<sbyte>
        {
            public int Compare(sbyte x, sbyte y)
            {
                return Byte.compare(x, y);
            }
        }

        // comparator for characters
        private class CharacterComparer : IComparer<char>
        {
            public int Compare(char x, char y)
            {
                return Character.compare(x, y);
            }
        }

        // comparator for double-precision decimal values
        private class DoubleComparer : IComparer<double>
        {
            public int Compare(double x, double y)
            {
                return Double.compare(x, y);
            }
        }

        // comparator for single-precision decimal values
        private class FloatComparer : IComparer<float>
        {
            public int Compare(float x, float y)
            {
                return Float.compare(x, y);
            }
        }

        // comparator for 32-bit signed integer values
        private class IntegerComparer : IComparer<int>
        {
            public int Compare(int x, int y)
            {
                return Integer.compare(x, y);
            }
        }

        // comparator for 64-bit signed integer values
        private class LongComparer : IComparer<long>
        {
            public int Compare(long x, long y)
            {
                return Long.compare(x, y);
            }
        }

        // comparator for 16-bit signed integer values
        private class ObjectComparer : IComparer<Object>
        {
            public int Compare(Object x, Object y)
            {

                return (x as Comparable).compareTo(y as Comparable);
            }
        }

        // comparator for 16-bit signed integer values
        private class ShortComparer : IComparer<short>
        {
            public int Compare(short x, short y)
            {
                return Short.compare(x, y);
            }
        }

        /*
            Represents the type-agnostic method for binary searching
            in the specified sorted part of any array according to a specified comparator.
         */
        private static int binarySearchGeneric<T>(T[] a, int? fromIndex, int? toIndex, T key, IComparer<T> c)
        {
            int fromIndexValue = fromIndex ?? 0;
            int toIndexValue = toIndex ?? a.Length;
            
            return Array.BinarySearch(a, fromIndexValue, toIndexValue - fromIndexValue, key, c);
        }

        /*
            Represents the type-agnostic method for copying
            the specified part of any array.
         */
        private static T[] copyOfRangeGeneric<T>(T[] original, int? from, int to)
        {
            int fromValue = from ?? 0;

            // a new array with the length equal to the difference of boundaries of the original array
            T[] a = new T[to - fromValue];

            // the specified upper boundary if greater than the original array length
            if (to > original.Length)
            {
                // copying the values from the original array to its last element
                for (int i = fromValue; i < original.Length; i++)
                {
                    a[i - fromValue] = original[i];
                }

                // filling the rest of the new array with the default value of the given type
                for (int i = original.Length; i < to; i++)
                {
                    a[i - fromValue] =
                     default(T);
                }
            }
            // the specified upper boundary is less then the original array length
            else
            {
                // copying the values from the original array to the element on the specified upper boundary
                for (int i = fromValue; i < to; i++)
                {
                    a[i - fromValue] = original[i];
                }
            }

            return a;
        }

        /*
            Represents the type-agnostic method for testing if two
            specified arrays are equal.
         */
        private static bool equalsGeneric<T>(T[] a, T[] a2, EqualsMethod<T> equals)
        {
            // comparing references
            if (a == a2)
            {
                return true;
            }

            // testing the references for a NULL value
            if (a == null || a2 == null)
            {
                return false;
            }

            int length = a.Length;

            // compring the array lengths
            if (a2.Length != length)
            {
                return false;
            }

            // comparing corresponding elements of arrays
            for (int i = 0; i < length; i++)
            {
                if (!equals(a[i], a2[i]))
                {
                    return false;
                }
            }

            return true;
        }

        /*
            Represents the type-agnostic method for filling
            the specified part of any array with the specified value.
         */
        private static void fillGeneric<T>(T[] a, int? fromIndex, int? toIndex, T val)
        {
            int fromIndexValue = fromIndex ?? 0;
            int toIndexValue = toIndex ?? a.Length;

            // setting each element with the value
            for (int i = fromIndexValue; i < toIndexValue; i++)
            {
                a[i] = val;
            }
        }

        /*
            Represents the type-agnostic method for sorting
            the specified part of any array according to a specified comparator.
         */
        private static void sortGeneric<T>(T[] a, int? fromIndex, int? toIndex, IComparer<T> c)
        {
            int fromIndexValue = fromIndex ?? 0;
            int toIndexValue = toIndex ?? a.Length;

            Array.Sort(a, fromIndexValue, toIndexValue - fromIndexValue, c);
        }

        /*
            Represents the type-agnostic method for creating
            the string representation of any array.
         */
        private static String toStringGeneric<T>(T[] a)
        {
            StringBuilder sb = new StringBuilder();
            sb.append(new String("["));

            if (a.Length > 0)
            {
                sb.append(a[0] == null ? "null" : a[0].ToString());
            }

            for (int i = 1; i < a.Length; i++)
            {
                sb.append(new String(", ")).append(a[i] == null ? "null" : a[i].ToString());
            }

            return sb.append(new String("]")).toString();
        }

        /// <summary>
        /// Searches the specified array of bytes for the specified value using the
        /// binary search algorithm
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array;
        /// otherwise, (-(insertion point) - 1). The insertion point is defined as
        /// the point at which the key would be inserted into the array: the index of
        /// the first element greater than the key, or a.length if all elements in
        /// the array are less than the specified key. Note that this guarantees that
        /// the return value will be >= 0 if and only if the key is found.
        /// </returns>
        public static int binarySearch(sbyte[] a, sbyte key)
        {
            return binarySearchGeneric(a, null, null, key, new ByteComparer());
        }

        /// <summary>
        /// Searches a range of the specified array of bytes for the specified value
        /// using the binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be
        /// searched
        /// </param><param name="toIndex">the index of the last element (exclusive) to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array within
        /// the specified range; otherwise, (-(insertion point) - 1). The insertion
        /// point is defined as the point at which the key would be inserted into the
        /// array: the index of the first element in the range greater than the key,
        /// or toIndex if all elements in the range are less than the specified key.
        /// Note that this guarantees that the return value will be >= 0 if and only
        /// if the key is found.
        /// </returns>
        public static int binarySearch(sbyte[] a, int fromIndex, int toIndex, sbyte key)
        {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new ByteComparer());
        }

        /// <summary>
        /// Searches the specified array of chars for the specified value using the
        /// binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array;
        /// otherwise, (-(insertion point) - 1). The insertion point is defined as
        /// the point at which the key would be inserted into the array: the index of
        /// the first element greater than the key, or a.length if all elements in
        /// the array are less than the specified key. Note that this guarantees that
        /// the return value will be >= 0 if and only if the key is found.
        /// </returns>
        public static int binarySearch(char[] a, char key)
        {
            return binarySearchGeneric(a, null, null, key, new CharacterComparer());
        }

        /// <summary>
        /// Searches a range of the specified array of chars for the specified value
        /// using the binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be
        /// searched
        /// </param><param name="toIndex">the index of the last element (exclusive) to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array within
        /// the specified range; otherwise, (-(insertion point) - 1). The insertion
        /// point is defined as the point at which the key would be inserted into the
        /// array: the index of the first element in the range greater than the key,
        /// or toIndex if all elements in the range are less than the specified key.
        /// Note that this guarantees that the return value will be >= 0 if and only
        /// if the key is found.
        /// </returns>
        public static int binarySearch(char[] a, int fromIndex, int toIndex, char key)
        {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new CharacterComparer());
        }

        /// <summary>
        /// Searches the specified array of doubles for the specified value using the
        /// binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array;
        /// otherwise, (-(insertion point) - 1). The insertion point is defined as
        /// the point at which the key would be inserted into the array: the index of
        /// the first element greater than the key, or a.length if all elements in
        /// the array are less than the specified key. Note that this guarantees that
        /// the return value will be >= 0 if and only if the key is found.
        /// </returns>
        public static int binarySearch(double[] a, double key)
        {
            return binarySearchGeneric(a, null, null, key, new DoubleComparer());
        }

        /// <summary>
        /// Searches a range of the specified array of doubles for the specified
        /// value using the binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be
        /// searched
        /// </param><param name="toIndex">the index of the last element (exclusive) to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array within
        /// the specified range; otherwise, (-(insertion point) - 1). The insertion
        /// point is defined as the point at which the key would be inserted into the
        /// array: the index of the first element in the range greater than the key,
        /// or toIndex if all elements in the range are less than the specified key.
        /// Note that this guarantees that the return value will be >= 0 if and only
        /// if the key is found.
        /// </returns>
        public static int binarySearch(double[] a, int fromIndex, int toIndex, double key)
        {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new DoubleComparer());
        }

        /// <summary>
        /// Searches the specified array of floats for the specified value using the
        /// binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array;
        /// otherwise, (-(insertion point) - 1). The insertion point is defined as
        /// the point at which the key would be inserted into the array: the index of
        /// the first element greater than the key, or a.length if all elements in
        /// the array are less than the specified key. Note that this guarantees that
        /// the return value will be >= 0 if and only if the key is found.
        /// </returns>
        public static int binarySearch(float[] a, float key)
        {
            return binarySearchGeneric(a, null, null, key, new FloatComparer());
        }

        /// <summary>
        /// Searches a range of the specified array of floats for the specified value
        /// using the binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be
        /// searched
        /// </param><param name="toIndex">the index of the last element (exclusive) to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array within
        /// the specified range; otherwise, (-(insertion point) - 1). The insertion
        /// point is defined as the point at which the key would be inserted into the
        /// array: the index of the first element in the range greater than the key,
        /// or toIndex if all elements in the range are less than the specified key.
        /// Note that this guarantees that the return value will be >= 0 if and only
        /// if the key is found.
        /// </returns>
        public static int binarySearch(float[] a, int fromIndex, int toIndex, float key)
        {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new FloatComparer());
        }

        /// <summary>
        /// Searches the specified array of ints for the specified value using the
        /// binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array;
        /// otherwise, (-(insertion point) - 1). The insertion point is defined as
        /// the point at which the key would be inserted into the array: the index of
        /// the first element greater than the key, or a.length if all elements in
        /// the array are less than the specified key. Note that this guarantees that
        /// the return value will be >= 0 if and only if the key is found.
        /// </returns>
        public static int binarySearch(int[] a, int key)
        {
            return binarySearchGeneric(a, null, null, key, new IntegerComparer());
        }

        /// <summary>
        /// Searches a range of the specified array of ints for the specified value
        /// using the binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be
        /// searched
        /// </param><param name="toIndex">the index of the last element (exclusive) to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array within
        /// the specified range; otherwise, (-(insertion point) - 1). The insertion
        /// point is defined as the point at which the key would be inserted into the
        /// array: the index of the first element in the range greater than the key,
        /// or toIndex if all elements in the range are less than the specified key.
        /// Note that this guarantees that the return value will be >= 0 if and only
        /// if the key is found.
        /// </returns>
        public static int binarySearch(int[] a, int fromIndex, int toIndex, int key)
        {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new IntegerComparer());
        }

        /// <summary>
        /// Searches the specified array of longs for the specified value using the
        /// binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array;
        /// otherwise, (-(insertion point) - 1). The insertion point is defined as
        /// the point at which the key would be inserted into the array: the index of
        /// the first element greater than the key, or a.length if all elements in
        /// the array are less than the specified key. Note that this guarantees that
        /// the return value will be >= 0 if and only if the key is found.
        /// </returns>
        public static int binarySearch(long[] a, long key)
        {
            return binarySearchGeneric(a, null, null, key, new LongComparer());
        }

        /// <summary>
        /// Searches a range of the specified array of longs for the specified value
        /// using the binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be
        /// searched
        /// </param><param name="toIndex">the index of the last element (exclusive) to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array within
        /// the specified range; otherwise, (-(insertion point) - 1). The insertion
        /// point is defined as the point at which the key would be inserted into the
        /// array: the index of the first element in the range greater than the key,
        /// or toIndex if all elements in the range are less than the specified key.
        /// Note that this guarantees that the return value will be >= 0 if and only
        /// if the key is found.
        /// </returns>
        public static int binarySearch(long[] a, int fromIndex, int toIndex, long key)
        {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new LongComparer());
        }

        /// <summary>
        /// Searches the specified array for the specified object using the binary
        /// search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array;
        /// otherwise, (-(insertion point) - 1). The insertion point is defined as
        /// the point at which the key would be inserted into the array: the index of
        /// the first element greater than the key, or a.length if all elements in
        /// the array are less than the specified key. Note that this guarantees that
        /// the return value will be >= 0 if and only if the key is found.
        /// </returns>
        public static int binarySearch(Object[] a, Object key)
        {
            return binarySearchGeneric(a, null, null, key, new ObjectComparer());
        }

        /// <summary>
        /// Searches a range of the specified array for the specified object using
        /// the binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be
        /// searched
        /// </param><param name="toIndex">the index of the last element (exclusive) to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array within
        /// the specified range; otherwise, (-(insertion point) - 1). The insertion
        /// point is defined as the point at which the key would be inserted into the
        /// array: the index of the first element in the range greater than the key,
        /// or toIndex if all elements in the range are less than the specified key.
        /// Note that this guarantees that the return value will be >= 0 if and only
        /// if the key is found.
        /// </returns>
        public static int binarySearch(Object[] a, int fromIndex, int toIndex, Object key)
        {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new ObjectComparer());
        }

        /// <summary>
        /// Searches the specified array of shorts for the specified value using the
        /// binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array;
        /// otherwise, (-(insertion point) - 1). The insertion point is defined as
        /// the point at which the key would be inserted into the array: the index of
        /// the first element greater than the key, or a.length if all elements in
        /// the array are less than the specified key. Note that this guarantees that
        /// the return value will be >= 0 if and only if the key is found.
        /// </returns>
        public static int binarySearch(short[] a, short key)
        {
            return binarySearchGeneric(a, null, null, key, new ShortComparer());
        }

        /// <summary>
        /// Searches a range of the specified array of shorts for the specified value
        /// using the binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be
        /// searched
        /// </param><param name="toIndex">the index of the last element (exclusive) to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><returns>index of the search key, if it is contained in the array within
        /// the specified range; otherwise, (-(insertion point) - 1). The insertion
        /// point is defined as the point at which the key would be inserted into the
        /// array: the index of the first element in the range greater than the key,
        /// or toIndex if all elements in the range are less than the specified key.
        /// Note that this guarantees that the return value will be >= 0 if and only
        /// if the key is found.
        /// </returns>
        public static int binarySearch(short[] a, int fromIndex, int toIndex, short key)
        {
            return binarySearchGeneric(a, fromIndex, toIndex, key, new ShortComparer());
        }

        /// <summary>
        /// Searches the specified array for the specified object using the binary
        /// search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><param name="c">the comparator by which the array is ordered. A null value
        /// indicates that the elements' natural ordering should be used.
        /// </param><returns>index of the search key, if it is contained in the array;
        /// otherwise, (-(insertion point) - 1). The insertion point is defined as
        /// the point at which the key would be inserted into the array: the index of
        /// the first element greater than the key, or a.length if all elements in
        /// the array are less than the specified key. Note that this guarantees that
        /// the return value will be >= 0 if and only if the key is found.
        /// </returns>
        public static int binarySearch<T>(T[] a, T key, Comparator c) where T : Object
        {
            return binarySearchGeneric(a, null, null, key, c);
        }

        /// <summary>
        /// Searches a range of the specified array for the specified object using
        /// the binary search algorithm.
        /// </summary>
        /// <param name="a">the array to be searched
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be
        /// searched
        /// </param><param name="toIndex">the index of the last element (exclusive) to be searched
        /// </param><param name="key">the value to be searched for
        /// </param><param name="c">the comparator by which the array is ordered. A null value
        /// indicates that the elements' natural ordering should be used.
        /// </param><returns>index of the search key, if it is contained in the array within
        /// the specified range; otherwise, (-(insertion point) - 1). The insertion
        /// point is defined as the point at which the key would be inserted into the
        /// array: the index of the first element in the range greater than the key,
        /// or toIndex if all elements in the range are less than the specified key.
        /// Note that this guarantees that the return value will be >= 0 if and only
        /// if the key is found.
        /// </returns>
        public static int binarySearch<T>(T[] a, int fromIndex, int toIndex, T key, Comparator c) where T : Object
        {
            return binarySearchGeneric(a, fromIndex, toIndex, key, c);
        }

        /// <summary>
        /// Copies the specified array, truncating or padding with false (if
        /// necessary) so the copy has the specified length.
        /// </summary>
        /// <param name="original">the array to be copied
        /// </param><param name="newLength">the length of the copy to be returned
        /// </param><returns>a copy of the original array, truncated or padded with false
        /// elements to obtain the specified length
        /// </returns>
        public static bool[] copyOf(bool[] original, int newLength)
        {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /// <summary>
        /// Copies the specified array, truncating or padding with zeros (if
        /// necessary) so the copy has the specified length.
        /// </summary>
        /// <param name="original">the array to be copied
        /// </param><param name="newLength">the length of the copy to be returned
        /// </param><returns>a copy of the original array, truncated or padded with zeros to
        /// obtain the specified length
        /// </returns>
        public static sbyte[] copyOf(sbyte[] original, int newLength)
        {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /// <summary>
        /// Copies the specified array, truncating or padding with null characters
        /// (if necessary) so the copy has the specified length.
        /// </summary>
        /// <param name="original">the array to be copied
        /// </param><param name="newLength">the length of the copy to be returned
        /// </param><returns>a copy of the original array, truncated or padded with null
        /// characters to obtain the specified length
        /// </returns>
        public static char[] copyOf(char[] original, int newLength)
        {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /// <summary>
        /// Copies the specified array, truncating or padding with zeros (if
        /// necessary) so the copy has the specified length.
        /// </summary>
        /// <param name="original">the array to be copied
        /// </param><param name="newLength">the length of the copy to be returned
        /// </param><returns>a copy of the original array, truncated or padded with zeros to
        /// obtain the specified length
        /// </returns>
        public static double[] copyOf(double[] original, int newLength)
        {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /// <summary>
        /// Copies the specified array, truncating or padding with zeros (if
        /// necessary) so the copy has the specified length.
        /// </summary>
        /// <param name="original">the array to be copied
        /// </param><param name="newLength">the length of the copy to be returned
        /// </param><returns>a copy of the original array, truncated or padded with zeros to
        /// obtain the specified length
        /// </returns>
        public static float[] copyOf(float[] original, int newLength)
        {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /// <summary>
        /// Copies the specified array, truncating or padding with zeros (if
        /// necessary) so the copy has the specified length.
        /// </summary>
        /// <param name="original">the array to be copied
        /// </param><param name="newLength">the length of the copy to be returned
        /// </param><returns>a copy of the original array, truncated or padded with zeros to
        /// obtain the specified length
        /// </returns>
        public static int[] copyOf(int[] original, int newLength)
        {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /// <summary>
        /// Copies the specified array, truncating or padding with zeros (if
        /// necessary) so the copy has the specified length.
        /// </summary>
        /// <param name="original">the array to be copied
        /// </param><param name="newLength">the length of the copy to be returned
        /// </param><returns>a copy of the original array, truncated or padded with zeros to
        /// obtain the specified length
        /// </returns>
        public static long[] copyOf(long[] original, int newLength)
        {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /// <summary>
        /// Copies the specified array, truncating or padding with zeros (if
        /// necessary) so the copy has the specified length.
        /// </summary>
        /// <param name="original">the array to be copied
        /// </param><param name="newLength">the length of the copy to be returned
        /// </param><returns>a copy of the original array, truncated or padded with zeros to
        /// obtain the specified length
        /// </returns>
        public static short[] copyOf(short[] original, int newLength)
        {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /// <summary>
        /// Copies the specified array, truncating or padding with nulls (if
        /// necessary) so the copy has the specified length.
        /// </summary>
        /// <param name="original">the array to be copied
        /// </param><param name="newLength">the length of the copy to be returned
        /// </param><returns>a copy of the original array, truncated or padded with nulls to
        /// obtain the specified length
        /// </returns>
        public static T[] copyOf<T>(T[] original, int newLength)
        {
            return copyOfRangeGeneric(original, null, newLength);
        }

        /// <summary>
        /// Copies the specified range of the specified array into a new array.
        /// </summary>
        /// <param name="original">the array from which a range is to be copied
        /// </param><param name="from">the initial index of the range to be copied, inclusive
        /// </param><param name="to">the final index of the range to be copied, exclusive. (This
        /// index may lie outside the array.)
        /// </param><returns>a new array containing the specified range from the original
        /// array, truncated or padded with false elements to obtain the required
        /// length
        /// </returns>
        public static bool[] copyOfRange(bool[] original, int from, int to)
        {
            return copyOfRangeGeneric(original, from, to);
        }

        /// <summary>
        /// Copies the specified range of the specified array into a new array.
        /// </summary>
        /// <param name="original">the array from which a range is to be copied
        /// </param><param name="from">the initial index of the range to be copied, inclusive
        /// </param><param name="to">the final index of the range to be copied, exclusive. (This
        /// index may lie outside the array.)
        /// </param><returns>a new array containing the specified range from the original
        /// array, truncated or padded with zeros to obtain the required length
        /// </returns>
        public static sbyte[] copyOfRange(sbyte[] original, int from, int to)
        {
            return copyOfRangeGeneric(original, from, to);
        }

        /// <summary>
        /// Copies the specified range of the specified array into a new array.
        /// </summary>
        /// <param name="original">the array from which a range is to be copied
        /// </param><param name="from">the initial index of the range to be copied, inclusive
        /// </param><param name="to">the final index of the range to be copied, exclusive. (This
        /// index may lie outside the array.)
        /// </param><returns>a new array containing the specified range from the original
        /// array, truncated or padded with null characters to obtain the required
        /// length
        /// </returns>
        public static char[] copyOfRange(char[] original, int from, int to)
        {
            return copyOfRangeGeneric(original, from, to);
        }

        /// <summary>
        /// Copies the specified range of the specified array into a new array.
        /// </summary>
        /// <param name="original">the array from which a range is to be copied
        /// </param><param name="from">the initial index of the range to be copied, inclusive
        /// </param><param name="to">the final index of the range to be copied, exclusive. (This
        /// index may lie outside the array.)
        /// </param><returns>a new array containing the specified range from the original
        /// array, truncated or padded with zeros to obtain the required length
        /// </returns>
        public static double[] copyOfRange(double[] original, int from, int to)
        {
            return copyOfRangeGeneric(original, from, to);
        }

        /// <summary>
        /// Copies the specified range of the specified array into a new array.
        /// </summary>
        /// <param name="original">the array from which a range is to be copied
        /// </param><param name="from">the initial index of the range to be copied, inclusive
        /// </param><param name="to">the final index of the range to be copied, exclusive. (This
        /// index may lie outside the array.)
        /// </param><returns>a new array containing the specified range from the original
        /// array, truncated or padded with zeros to obtain the required length
        /// </returns>
        public static float[] copyOfRange(float[] original, int from, int to)
        {
            return copyOfRangeGeneric(original, from, to);
        }

        /// <summary>
        /// Copies the specified range of the specified array into a new array.
        /// </summary>
        /// <param name="original">the array from which a range is to be copied
        /// </param><param name="from">the initial index of the range to be copied, inclusive
        /// </param><param name="to">the final index of the range to be copied, exclusive. (This
        /// index may lie outside the array.)
        /// </param><returns>a new array containing the specified range from the original
        /// array, truncated or padded with zeros to obtain the required length
        /// </returns>
        public static int[] copyOfRange(int[] original, int from, int to)
        {
            return copyOfRangeGeneric(original, from, to);
        }

        /// <summary>
        /// Copies the specified range of the specified array into a new array.
        /// </summary>
        /// <param name="original">the array from which a range is to be copied
        /// </param><param name="from">the initial index of the range to be copied, inclusive
        /// </param><param name="to">the final index of the range to be copied, exclusive. (This
        /// index may lie outside the array.)
        /// </param><returns>a new array containing the specified range from the original
        /// array, truncated or padded with zeros to obtain the required length
        /// </returns>
        public static long[] copyOfRange(long[] original, int from, int to)
        {
            return copyOfRangeGeneric(original, from, to);
        }

        /// <summary>
        /// Copies the specified range of the specified array into a new array.
        /// </summary>
        /// <param name="original">the array from which a range is to be copied
        /// </param><param name="from">the initial index of the range to be copied, inclusive
        /// </param><param name="to">the final index of the range to be copied, exclusive. (This
        /// index may lie outside the array.)
        /// </param><returns>a new array containing the specified range from the original
        /// array, truncated or padded with zeros to obtain the required length
        /// </returns>
        public static short[] copyOfRange(short[] original, int from, int to)
        {
            return copyOfRangeGeneric(original, from, to);
        }

        /// <summary>
        /// Copies the specified range of the specified array into a new array.
        /// </summary>
        /// <param name="original">the array from which a range is to be copied
        /// </param><param name="from">the initial index of the range to be copied, inclusive
        /// </param><param name="to">the final index of the range to be copied, exclusive. (This
        /// index may lie outside the array.)
        /// </param><returns>a new array containing the specified range from the original
        /// array, truncated or padded with nulls to obtain the required length
        /// </returns>
        public static T[] copyOfRange<T>(T[] original, int from, int to)
        {
            return copyOfRangeGeneric(original, from, to);
        }

        /// <summary>
        /// Returns true if the two specified arrays of booleans are equal to one
        /// another.
        /// </summary>
        /// <param name="a">one array to be tested for equality
        /// </param><param name="a2">the other array to be tested for equality
        /// </param><returns>true if the two arrays are equal
        /// </returns>
        public static bool equals(bool[] a, bool[] a2)
        {
            return equalsGeneric(a, a2, (x, y) =>
            {
                return new Boolean(x).equals(new Boolean(y));
            });
        }

        /// <summary>
        /// Returns true if the two specified arrays of bytes are equal to one
        /// another.
        /// </summary>
        /// <param name="a">one array to be tested for equality
        /// </param><param name="a2">the other array to be tested for equality
        /// </param><returns>true if the two arrays are equal
        /// </returns>
        public static bool equals(sbyte[] a, sbyte[] a2)
        {
            return equalsGeneric(a, a2, (x, y) =>
            {
                return new Byte(x).equals(new Byte(y));
            });
        }

        /// <summary>
        /// Returns true if the two specified arrays of chars are equal to one
        /// another.
        /// </summary>
        /// <param name="a">one array to be tested for equality
        /// </param><param name="a2">the other array to be tested for equality
        /// </param><returns>true if the two arrays are equal
        /// </returns>
        public static bool equals(char[] a, char[] a2)
        {
            return equalsGeneric(a, a2, (x, y) =>
            {
                return new Character(x).equals(new Character(y));
            });
        }

        /// <summary>
        /// Returns true if the two specified arrays of doubles are equal to one
        /// another.
        /// </summary>
        /// <param name="a">one array to be tested for equality
        /// </param><param name="a2">the other array to be tested for equality
        /// </param><returns>true if the two arrays are equal
        /// </returns>
        public static bool equals(double[] a, double[] a2)
        {
            return equalsGeneric(a, a2, (x, y) =>
            {
                return new Double(x).equals(new Double(y));
            });
        }

        /// <summary>
        /// Returns true if the two specified arrays of floats are equal to one
        /// another.
        /// </summary>
        /// <param name="a">one array to be tested for equality
        /// </param><param name="a2">the other array to be tested for equality
        /// </param><returns>true if the two arrays are equal
        /// </returns>
        public static bool equals(float[] a, float[] a2)
        {
            return equalsGeneric(a, a2, (x, y) =>
            {
                return new Float(x).equals(new Float(y));
            });
        }

        /// <summary>
        /// Returns true if the two specified arrays of ints are equal to one
        /// another.
        /// </summary>
        /// <param name="a">one array to be tested for equality
        /// </param><param name="a2">the other array to be tested for equality
        /// </param><returns>true if the two arrays are equal
        /// </returns>
        public static bool equals(int[] a, int[] a2)
        {
            return equalsGeneric(a, a2, (x, y) =>
            {
                return new Integer(x).equals(new Integer(y));
            });
        }

        /// <summary>
        /// Returns true if the two specified arrays of longs are equal to one
        /// another.
        /// </summary>
        /// <param name="a">one array to be tested for equality
        /// </param><param name="a2">the other array to be tested for equality
        /// </param><returns>true if the two arrays are equal
        /// </returns>
        public static bool equals(long[] a, long[] a2)
        {
            return equalsGeneric(a, a2, (x, y) =>
            {
                return new Long(x).equals(new Long(y));
            });
        }

        /// <summary>
        /// Returns true if the two specified arrays of Objects are equal to one
        /// another.
        /// </summary>
        /// <param name="a">one array to be tested for equality
        /// </param><param name="a2">the other array to be tested for equality
        /// </param><returns>true if the two arrays are equal
        /// </returns>
        public static bool equals(Object[] a, Object[] a2)
        {
            return equalsGeneric(a, a2, (o1, o2) =>
            {
                return (o1 == null ? o2 == null : o1.Equals(o2));
            });
        }

        /// <summary>
        /// Returns true if the two specified arrays of shorts are equal to one
        /// another.
        /// </summary>
        /// <param name="a">one array to be tested for equality
        /// </param><param name="a2">the other array to be tested for equality
        /// </param><returns>true if the two arrays are equal
        /// </returns>
        public static bool equals(short[] a, short[] a2)
        {
            return equalsGeneric(a, a2, (x, y) =>
            {
                return new Short(x).equals(new Short(y));
            });
        }

        /// <summary>
        /// Assigns the specified boolean value to each element of the specified
        /// array of booleans.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(bool[] a, bool val)
        {
            fillGeneric(a, null, null, val);
        }

        /// <summary>
        /// Assigns the specified boolean value to each element of the specified
        /// range of the specified array of booleans.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be filled
        /// with the specified value
        /// </param><param name="toIndex">the index of the last element (exclusive) to be filled
        /// with the specified value
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(bool[] a, int fromIndex, int toIndex, bool val)
        {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /// <summary>
        /// Assigns the specified byte value to each element of the specified array
        /// of bytes.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(sbyte[] a, sbyte val)
        {
            fillGeneric(a, null, null, val);
        }

        /// <summary>
        /// Assigns the specified byte value to each element of the specified range
        /// of the specified array of bytes.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be filled
        /// with the specified value
        /// </param><param name="toIndex">the index of the last element (exclusive) to be filled
        /// with the specified value
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(sbyte[] a, int fromIndex, int toIndex, sbyte val)
        {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /// <summary>
        /// Assigns the specified char value to each element of the specified array
        /// of chars.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(char[] a, char val)
        {
            fillGeneric(a, null, null, val);
        }

        /// <summary>
        /// Assigns the specified char value to each element of the specified range
        /// of the specified array of chars.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be filled
        /// with the specified value
        /// </param><param name="toIndex">the index of the last element (exclusive) to be filled
        /// with the specified value
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(char[] a, int fromIndex, int toIndex, char val)
        {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /// <summary>
        /// Assigns the specified double value to each element of the specified array
        /// of doubles.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(double[] a, double val)
        {
            fillGeneric(a, null, null, val);
        }

        /// <summary>
        /// Assigns the specified double value to each element of the specified range
        /// of the specified array of doubles.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be filled
        /// with the specified value
        /// </param><param name="toIndex">the index of the last element (exclusive) to be filled
        /// with the specified value
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(double[] a, int fromIndex, int toIndex, double val)
        {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /// <summary>
        /// Assigns the specified float value to each element of the specified array
        /// of floats.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(float[] a, float val)
        {
            fillGeneric(a, null, null, val);
        }

        /// <summary>
        /// Assigns the specified float value to each element of the specified range
        /// of the specified array of floats.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be filled
        /// with the specified value
        /// </param><param name="toIndex">the index of the last element (exclusive) to be filled
        /// with the specified value
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(float[] a, int fromIndex, int toIndex, float val)
        {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /// <summary>
        /// Assigns the specified int value to each element of the specified array of
        /// ints.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(int[] a, int val)
        {
            fillGeneric(a, null, null, val);
        }

        /// <summary>
        /// Assigns the specified int value to each element of the specified range of
        /// the specified array of ints.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be filled
        /// with the specified value
        /// </param><param name="toIndex">the index of the last element (exclusive) to be filled
        /// with the specified value
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(int[] a, int fromIndex, int toIndex, int val)
        {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /// <summary>
        /// Assigns the specified long value to each element of the specified array
        /// of longs.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(long[] a, long val)
        {
            fillGeneric(a, null, null, val);
        }

        /// <summary>
        /// Assigns the specified long value to each element of the specified range
        /// of the specified array of longs.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be filled
        /// with the specified value
        /// </param><param name="toIndex">the index of the last element (exclusive) to be filled
        /// with the specified value
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(long[] a, int fromIndex, int toIndex, long val)
        {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /// <summary>
        /// Assigns the specified Object reference to each element of the specified
        /// array of Objects.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(Object[] a, Object val)
        {
            fillGeneric(a, null, null, val);
        }

        /// <summary>
        /// Assigns the specified Object reference to each element of the specified
        /// range of the specified array of Objects.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be filled
        /// with the specified value
        /// </param><param name="toIndex">the index of the last element (exclusive) to be filled
        /// with the specified value
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(Object[] a, int fromIndex, int toIndex, Object val)
        {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /// <summary>
        /// Assigns the specified short value to each element of the specified array
        /// of shorts.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(short[] a, short val)
        {
            fillGeneric(a, null, null, val);
        }

        /// <summary>
        /// Assigns the specified short value to each element of the specified range
        /// of the specified array of shorts.
        /// </summary>
        /// <param name="a">the array to be filled
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be filled
        /// with the specified value
        /// </param><param name="toIndex">the index of the last element (exclusive) to be filled
        /// with the specified value
        /// </param><param name="val">the value to be stored in all elements of the array
        /// </param>
        public static void fill(short[] a, int fromIndex, int toIndex, short val)
        {
            fillGeneric(a, fromIndex, toIndex, val);
        }

        /// <summary>
        /// Sorts the specified array into ascending numerical order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param>
        public static void sort(sbyte[] a)
        {
            sortGeneric(a, null, null, new ByteComparer());
        }

        /// <summary>
        /// Sorts the specified range of the array into ascending order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be sorted
        /// </param><param name="toIndex">the index of the last element (exclusive) to be sorted
        /// </param>
        public static void sort(sbyte[] a, int fromIndex, int toIndex)
        {
            sortGeneric(a, fromIndex, toIndex, new ByteComparer());
        }

        /// <summary>
        /// Sorts the specified array into ascending numerical order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param>
        public static void sort(char[] a)
        {
            sortGeneric(a, null, null, new CharacterComparer());
        }

        /// <summary>
        /// Sorts the specified range of the array into ascending order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be sorted
        /// </param><param name="toIndex">the index of the last element (exclusive) to be sorted
        /// </param>
        public static void sort(char[] a, int fromIndex, int toIndex)
        {
            sortGeneric(a, fromIndex, toIndex, new CharacterComparer());
        }

        /// <summary>
        /// Sorts the specified array into ascending numerical order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param>
        public static void sort(double[] a)
        {
            sortGeneric(a, null, null, new DoubleComparer());
        }

        /// <summary>
        /// Sorts the specified range of the array into ascending order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be sorted
        /// </param><param name="toIndex">the index of the last element (exclusive) to be sorted
        /// </param>
        public static void sort(double[] a, int fromIndex, int toIndex)
        {
            sortGeneric(a, fromIndex, toIndex, new DoubleComparer());
        }

        /// <summary>
        /// Sorts the specified array into ascending numerical order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param>
        public static void sort(float[] a)
        {
            sortGeneric(a, null, null, new FloatComparer());
        }

        /// <summary>
        /// Sorts the specified range of the array into ascending order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be sorted
        /// </param><param name="toIndex">the index of the last element (exclusive) to be sorted
        /// </param>
        public static void sort(float[] a, int fromIndex, int toIndex)
        {
            sortGeneric(a, fromIndex, toIndex, new FloatComparer());
        }

        /// <summary>
        /// Sorts the specified array into ascending numerical order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param>
        public static void sort(int[] a)
        {
            sortGeneric(a, null, null, new IntegerComparer());
        }

        /// <summary>
        /// Sorts the specified range of the array into ascending order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be sorted
        /// </param><param name="toIndex">the index of the last element (exclusive) to be sorted
        /// </param>
        public static void sort(int[] a, int fromIndex, int toIndex)
        {
            sortGeneric(a, fromIndex, toIndex, new IntegerComparer());
        }

        /// <summary>
        /// Sorts the specified array into ascending numerical order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param>
        public static void sort(long[] a)
        {
            sortGeneric(a, null, null, new LongComparer());
        }

        /// <summary>
        /// Sorts the specified range of the array into ascending order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be sorted
        /// </param><param name="toIndex">the index of the last element (exclusive) to be sorted
        /// </param>
        public static void sort(long[] a, int fromIndex, int toIndex)
        {
            sortGeneric(a, fromIndex, toIndex, new LongComparer());
        }

        /// <summary>
        /// Sorts the specified array of objects into ascending order, according to
        /// the natural ordering of its elements.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param>
        public static void sort(Object[] a)
        {
            sortGeneric(a, null, null, new ObjectComparer());
        }

        /// <summary>
        /// Sorts the specified range of the specified array of objects into
        /// ascending order, according to the natural ordering of its elements.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be sorted
        /// </param><param name="toIndex">the index of the last element (exclusive) to be sorted
        /// </param>
        public static void sort(Object[] a, int fromIndex, int toIndex)
        {
            sortGeneric(a, fromIndex, toIndex, new ObjectComparer());
        }

        /// <summary>
        /// Sorts the specified array into ascending numerical order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param>
        public static void sort(short[] a)
        {
            sortGeneric(a, null, null, new ShortComparer());
        }

        /// <summary>
        /// Sorts the specified range of the array into ascending order.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be sorted
        /// </param><param name="toIndex">the index of the last element (exclusive) to be sorted
        /// </param>
        public static void sort(short[] a, int fromIndex, int toIndex)
        {
            sortGeneric(a, fromIndex, toIndex, new ShortComparer());
        }

        /// <summary>
        /// Sorts the specified array of objects according to the order induced by
        /// the specified comparator.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param><param name="c">the comparator to determine the order of the array. A null value
        /// indicates that the elements' natural ordering should be used.
        /// </param>
        public static void sort<T>(T[] a, Comparator c) where T : Object
        {
            sortGeneric(a, null, null, c);
        }

        /// <summary>
        /// Sorts the specified range of the specified array of objects according to
        /// the order induced by the specified comparator.
        /// </summary>
        /// <param name="a">the array to be sorted
        /// </param><param name="fromIndex">the index of the first element (inclusive) to be sorted
        /// </param><param name="toIndex">the index of the last element (exclusive) to be sorted
        /// </param><param name="c">the comparator to determine the order of the array. A null value
        /// indicates that the elements' natural ordering should be used.
        /// </param>
        public static void sort<T>(T[] a, int fromIndex, int toIndex, Comparator c) where T : Object
        {
            sortGeneric(a, fromIndex, toIndex, c);
        }

        /// <summary>
        /// Returns a string representation of the contents of the specified array.
        /// </summary>
        /// <param name="a">the array whose string representation to return
        /// </param><returns>a string representation of a
        /// </returns>
        public static String toString(bool[] a)
        {
            return toStringGeneric(a).toLowerCase();
        }

        /// <summary>
        /// Returns a string representation of the contents of the specified array.
        /// </summary>
        /// <param name="a">the array whose string representation to return
        /// </param><returns>a string representation of a
        /// </returns>
        public static String toString(sbyte[] a)
        {
            return toStringGeneric(a);
        }

        /// <summary>
        /// Returns a string representation of the contents of the specified array.
        /// </summary>
        /// <param name="a">the array whose string representation to return
        /// </param><returns>a string representation of a
        /// </returns>
        public static String toString(char[] a)
        {
            return toStringGeneric(a);
        }

        /// <summary>
        /// Returns a string representation of the contents of the specified array.
        /// </summary>
        /// <param name="a">the array whose string representation to return
        /// </param><returns>a string representation of a
        /// </returns>
        public static String toString(double[] a)
        {
            return toStringGeneric(a);
        }

        /// <summary>
        /// Returns a string representation of the contents of the specified array.
        /// </summary>
        /// <param name="a">the array whose string representation to return
        /// </param><returns>a string representation of a
        /// </returns>
        public static String toString(float[] a)
        {
            return toStringGeneric(a);
        }

        /// <summary>
        /// Returns a string representation of the contents of the specified array.
        /// </summary>
        /// <param name="a">the array whose string representation to return
        /// </param><returns>a string representation of a
        /// </returns>
        public static String toString(int[] a)
        {
            return toStringGeneric(a);
        }

        /// <summary>
        /// Returns a string representation of the contents of the specified array.
        /// </summary>
        /// <param name="a">the array whose string representation to return
        /// </param><returns>a string representation of a
        /// </returns>
        public static String toString(long[] a)
        {
            return toStringGeneric(a);
        }

        /// <summary>
        /// Returns a string representation of the contents of the specified array.
        /// </summary>
        /// <param name="a">the array whose string representation to return
        /// </param><returns>a string representation of a
        /// </returns>
        public static String toString(Object[] a)
        {
            return toStringGeneric(a);
        }

        /// <summary>
        /// Returns a string representation of the contents of the specified array.
        /// </summary>
        /// <param name="a">the array whose string representation to return
        /// </param><returns>a string representation of a
        /// </returns>
        public static String toString(short[] a)
        {
            return toStringGeneric(a);
        }

    }

}