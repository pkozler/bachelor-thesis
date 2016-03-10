using System;

namespace JavaClasses {

    /**
     * The Byte class wraps a value of primitive type byte in an object.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Byte {

        /**
         * A constant holding the maximum value a byte can have, 2^7-1.
         */
        public const sbyte MAX_VALUE = 127;

        /**
         * A constant holding the minimum value a byte can have, -2^7.
         */
        public const sbyte MIN_VALUE = -128;

        private sbyte v;

        /**
         * Constructs a newly allocated Byte object that represents the specified byte value.
         */
        public Byte(sbyte value) {
            v = value;
        }

        /**
         * Returns the value of this Byte as a byte.
         */
        public sbyte byteValue() {
            return v;
        }

        /**
         * Compares two Byte objects numerically.
         */
        public int compareTo(Byte anotherByte) {
            return compare(v, anotherByte.v);
        }

        /**
         * Compares two byte values numerically.
         */
        public static int compare(sbyte x, sbyte y) {
            /* positive number if x is greater, 0 if x equals y, negative number otherwise
               (same as for char and short types) */
            return x - y;
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

            return v.Equals((obj as Byte).v);
        }

        public override string ToString() {
            return toString().ToString();
        }

        /**
         * Returns a String object representing this Byte's value.
         */
        public String toString() {
            return Byte.toString(v);
        }

        /**
         * Returns a new String object representing the specified byte.
         */
        public static String toString(sbyte b) {
            return b.ToString();
        }

        /**
         * Parses the string argument as a signed decimal byte.
         */
        public static sbyte parseByte(String s) {
            return sbyte.Parse(s.ToString());
        }
    }
}
