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
         * Constructs a newly allocated Long object that represents the specified long argument.
         */
        public Long(long value) {
            v = value;
        }

        /**
         * Returns the value of this Long as a long value.
         */
        public long longValue() {
            return v;
        }

        /**
         * Compares two Long objects numerically.
         */
        public int compareTo(Long anotherLong) {
            return compare(v, anotherLong.v);
        }

        /**
         * Compares two long values numerically.
         */
        public static int compare(long x, long y) {
            return (x < y) ? -1 : ((x == y) ? 0 : 1);
        }

        /**
         * Compares this object to the specified object.
         */
        public bool equals(Object obj) {
            if (obj == null) {
                return false;
            }

            if (GetType() != obj.GetType()) {
                return false;
            }

            return v.Equals((obj as Long).v);
        }

        public override string ToString() {
            return toString().ToString();
        }

        /**
         * Returns a String object representing this Long's value.
         */
        public String toString() {
            return Long.toString(v);
        }

        /**
         * Returns a String object representing the specified long.
         */
        public static String toString(long l) {
            return l.ToString();
        }

        /**
         * Parses the string argument as a signed long in the radix specified by the second argument.
         */
        public static long parseLong(String s) {
            return long.Parse(s.ToString());
        }
    }
}
