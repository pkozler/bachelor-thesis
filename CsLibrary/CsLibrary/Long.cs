using System;

namespace JavaClasses {

    /**
     * The Long class wraps a value of the primitive type long in an object.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Long {

        /**
         * A constant holding the maximum value a long can have, 2^63-1.
         */
        public const long MAX_VALUE = 9223372036854775807;

        /**
         * A constant holding the minimum value a long can have, -2^63.
         */
        public const long MIN_VALUE = -9223372036854775808;

        private long v;

        /**
         * Constructs a newly allocated Long object that represents the specified
         * long argument.
         *
         * @param value the value to be represented by the Long object.
         */
        public Long(long value) {
            v = value;
        }

        /**
         * Returns the value of this Long as a long value.
         *
         * @return the numeric value represented by this object after conversion to
         * type long.
         */
        public long longValue() {
            return v;
        }

        /**
         * Compares two Long objects numerically.
         *
         * @param anotherLong the Long to be compared.
         * @return the value 0 if this Long is equal to the argument Long; a value
         * less than 0 if this Long is numerically less than the argument Long; and
         * a value greater than 0 if this Long is numerically greater than the
         * argument Long (signed comparison).
         */
        public int compareTo(Long anotherLong) {
            return compare(v, anotherLong.v);
        }

        /**
         * Compares two long values numerically.
         *
         * @param x the first long to compare
         * @param y the second long to compare
         * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
         * > y
         */
        public static int compare(long x, long y) {
            return (x < y) ? -1 : ((x == y) ? 0 : 1);
        }

        /**
         * Compares this object to the specified object.
         *
         * @param obj the object to compare with.
         * @return true if the objects are the same; false otherwise.
         */
        public bool equals(Object obj) {
            if (obj == null) {
                return false;
            }

            if (GetType() != obj.GetType()) {
                return false;
            }

            return v.Equals((obj as  Long).v);
        }

        /**
         * Returns a String object representing this Long's value.
         *
         * @return a string representation of the value of this object in base 10.
         */
        public String toString() {
            return Long.toString(v);
        }

        /**
         * Returns a String object representing the specified long.
         *
         * @param l a long to be converted.
         * @return a string representation of the argument in base 10.
         */
        public static String toString(long l) {
            return l.ToString();
        }

        /**
         * Parses the string argument as a signed long in the radix specified by the
         * second argument.
         *
         * @param s a String containing the long representation to be parsed
         * @return the long represented by the argument in decimal.
         */
        public static long parseLong(String s) {
            return long.Parse(s.ToString());
        }
        
        public override string ToString() {
            return toString().ToString();
        }

    }

}
