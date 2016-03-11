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
         * Constructs a newly allocated Byte object that represents the specified
         * byte value.
         *
         * @param value the value to be represented by the Byte.
         */
        public Byte(sbyte value) {
            v = value;
        }

        /**
         * Returns the value of this Byte as a byte.
         *
         * @return the numeric value represented by this object after conversion to
         * type byte.
         */
        public sbyte byteValue() {
            return v;
        }

        /**
         * Compares two Byte objects numerically.
         *
         * @param anotherByte the Byte to be compared.
         * @return the value 0 if this Byte is equal to the argument Byte; a value
         * less than 0 if this Byte is numerically less than the argument Byte; and
         * a value greater than 0 if this Byte is numerically greater than the
         * argument Byte (signed comparison).
         */
        public int compareTo(Byte anotherByte) {
            return compare(v, anotherByte.v);
        }

        /**
         * Compares two byte values numerically.
         *
         * @param x the first byte to compare
         * @param y the second byte to compare
         * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
         * > y
         */
        public static int compare(sbyte x, sbyte y) {
            /* positive number if x is greater, 0 if x equals y, negative number otherwise
             (same as for char and short types) */
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

            return v.Equals((obj as  Byte).v);
        }

        /**
         * Returns a String object representing this Byte's value.
         * 
         * @return a string representation of the value of this object in base 10.
         */
        public String toString() {
            return Byte.toString(v);
        }

        /**
         * Returns a new String object representing the specified byte.
         *
         * @param b the byte to be converted
         * @return the string representation of the specified byte
         */
        public static String toString(sbyte b) {
            return b.ToString();
        }

        /**
         * Parses the string argument as a signed decimal byte.
         *
         * @param s a String containing the byte representation to be parsed
         * @return the byte value represented by the argument in decimal
         */
        public static sbyte parseByte(String s) {
            return sbyte.Parse(s.ToString());
        }
        
        public override string ToString() {
            return toString().ToString();
        }

    }

}
