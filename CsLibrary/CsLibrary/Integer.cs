using System;

namespace JavaClasses {

    /**
     * The Integer class wraps a value of the primitive type int in an object.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Integer {

        /**
         * A constant holding the maximum value an int can have, 2^31-1.
         */
        public const int MAX_VALUE = 2147483647;

        /**
         * A constant holding the minimum value an int can have, -2^31.
         */
        public const int MIN_VALUE = -2147483648;
        private int v;

        /**
         * Constructs a newly allocated Integer object that represents the specified int value.
         */
        public Integer(int value) {
            v = value;
        }

        /**
         * Returns the value of this Integer as an int.
         */
        public int intValue() {
            return v;
        }

        /**
         * Compares two Integer objects numerically.
         */
        public int compareTo(Integer anotherInteger) {
            return v.CompareTo(anotherInteger.v);
        }

        /**
         * Compares this object to the specified object.
         */
        public bool equals(Object obj) {
            return v.Equals((obj as Integer).v);
        }

        public override string ToString() {
            return toString().ToString();
        }

        /**
         * Returns a String object representing this Integer's value.
         */
        public String toString() {
            return Integer.toString(v);
        }

        /**
         * Returns a String object representing the specified integer.
         */
        public static String toString(int i) {
            return i.ToString();
        }

        /**
         * Parses the string argument as a signed decimal integer.
         */
        public static int parseInt(String s) {
            return int.Parse(s.ToString());
        }
    }
}
