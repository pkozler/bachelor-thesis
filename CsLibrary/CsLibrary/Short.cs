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
         * Constructs a newly allocated Short object that represents the specified
         * short value.
         *
         * @param value the value to be represented by the Short.
         */
        public Short(short value) {
            v = value;
        }

        /**
         * Returns the value of this Short as a short.
         *
         * @return the numeric value represented by this object after conversion to
         * type short.
         */
        public short shortValue() {
            return v;
        }

        /**
         * Compares two Short objects numerically.
         *
         * @param anotherShort the Short to be compared.
         * @return the value 0 if this Short is equal to the argument Short; a value
         * less than 0 if this Short is numerically less than the argument Short;
         * and a value greater than 0 if this Short is numerically greater than the
         * argument Short (signed comparison).
         */
        public int compareTo(Short anotherShort) {
            return compare(v, anotherShort.v);
        }

        /**
         * Compares two short values numerically.
         *
         * @param x the first short to compare
         * @param y the second short to compare
         * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
         * > y
         */
        public static int compare(short x, short y) {
            return x - y;
        }

        /**
         * Compares this object to the specified object.
         *
         * @param obj the object to compare with
         * @return true if the objects are the same; false otherwise.
         */
        public bool equals(Object obj) {
            if (obj == null) {
                return false;
            }

            if (GetType() != obj.GetType()) {
                return false;
            }

            return v.Equals((obj as  Short).v);
        }

        /**
         * Returns a String object representing this Short's value.
         *
         * @return a string representation of the value of this object in base 10.
         */
        public String toString() {
            return Short.toString(v);
        }

        /**
         * Returns a new String object representing the specified short.
         *
         * @param s the short to be converted
         * @return the string representation of the specified short
         */
        public static String toString(short s) {
            return s.ToString();
        }

        /**
         * Parses the string argument as a signed decimal short.
         *
         * @param s a String containing the short representation to be parsed
         * @return the short value represented by the argument in decimal.
         */
        public static short parseShort(String s) {
            return short.Parse(s.ToString());
        }
        
        public override string ToString() {
            return toString().ToString();
        }

    }

}
