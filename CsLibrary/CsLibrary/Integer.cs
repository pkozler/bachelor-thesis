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
         * Constructs a newly allocated Integer object that represents the specified
         * int value.
         *
         * @param value the value to be represented by the Integer object.
         */
        public Integer(int value) {
            v = value;
        }

        /**
         * Returns the value of this Integer as an int.
         *
         * @return the numeric value represented by this object after conversion to
         * type int.
         */
        public int intValue() {
            return v;
        }

        /**
         * Compares two Integer objects numerically.
         *
         * @param anotherInteger the Integer to be compared.
         * @return the value 0 if this Integer is equal to the argument Integer; a
         * value less than 0 if this Integer is numerically less than the argument
         * Integer; and a value greater than 0 if this Integer is numerically
         * greater than the argument Integer (signed comparison).
         */
        public int compareTo(Integer anotherInteger) {
            return compare(v, anotherInteger.v);
        }

        /**
         * Compares two int values numerically.
         *
         * @param x the first int to compare
         * @param y the second int to compare
         * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
         * > y
         */
        public static int compare(int x, int y) {
            /* 1 if x is greater, 0 if x equals y, -1 otherwise
             (same as for a long type) */
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

            return v.Equals((obj as  Integer).v);
        }

        /**
         * Returns a String object representing this Integer's value.
         * 
         * @return a string representation of the value of this object in base 10.
         */
        public String toString() {
            return Integer.toString(v);
        }

        /**
         * Returns a String object representing the specified integer.
         *
         * @param i an integer to be converted.
         * @return a string representation of the argument in base 10.
         */
        public static String toString(int i) {
            return i.ToString();
        }

        /**
         * Parses the string argument as a signed decimal integer.
         *
         * @param s a String containing the int representation to be parsed
         * @return the integer value represented by the argument in decimal.
         */
        public static int parseInt(String s) {
            return int.Parse(s.ToString());
        }
        
        public override string ToString() {
            return toString().ToString();
        }

    }

}
