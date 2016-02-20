using System;

namespace JavaClasses {

    /**
     * The Short class wraps a value of primitive type short in an object.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Short {

        /**
         * A constant holding the maximum value a short can have, 2^15-1.
         */
        public const short MAX_VALUE = 32767;

        /**
         * A constant holding the minimum value a short can have, -2^15.
         */
        public const short MIN_VALUE = -32768;
        private short v;

        /**
         * Constructs a newly allocated Short object that represents the specified short value.
         */
        public Short(short value) {
            v = value;
        }

        /**
         * Returns the value of this Short as a short.
         */
        public short shortValue() {
            return v;
        }

        /**
         * Compares two Short objects numerically.
         */
        public int compareTo(Short anotherShort) {
            return v.CompareTo(anotherShort.v);
        }

        /**
         * Compares this object to the specified object.
         */
        public bool equals(Object obj) {
            return v.Equals((obj as Short).v);
        }

        public override string ToString() {
            return toString().ToString();
        }

        /**
         * Returns a String object representing this Short's value.
         */
        public String toString() {
            return Short.toString(v);
        }

        /**
         * Returns a new String object representing the specified short.
         */
        public static String toString(short s) {
            return s.ToString();
        }

        /**
         * Parses the string argument as a signed decimal short.
         */
        public static short parseShort(String s) {
            return short.Parse(s.ToString());
        }
    }
}
