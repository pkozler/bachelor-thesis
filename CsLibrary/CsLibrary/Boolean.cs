using System;

namespace JavaClasses {

    /**
     * The Boolean class wraps a value of the primitive type boolean in an object.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Boolean {

        private bool v;

        /**
         * Allocates a Boolean object representing the value argument.
         *
         * @param value the value of the Boolean.
         */
        public Boolean(bool value) {
            v = value;
        }

        /**
         * Returns the value of this Boolean object as a boolean primitive.
         *
         * @return the primitive boolean value of this object.
         */
        public bool booleanValue() {
            return v;
        }

        /**
         * Compares this Boolean instance with another.
         *
         * @param b the Boolean instance to be compared
         * @return zero if this object represents the same boolean value as the
         * argument; a positive value if this object represents true and the
         * argument represents false; and a negative value if this object represents
         * false and the argument represents true
         */
        public int compareTo(Boolean b) {
            return compare(v, b.v);
        }

        /**
         * Compares two boolean values.
         *
         * @param x the first boolean to compare
         * @param y the second boolean to compare
         * @return the value 0 if x == y; a value less than 0 if !x && y; and a
         * value greater than 0 if x && !y
         */
        public static int compare(bool x, bool y) {
            /* 0 if x equals y, 1 if x is TRUE and y is FALSE, -1 otherwise 
             (analogical for integer values) */
            return (x == y) ? 0 : (x ? 1 : -1);
        }

        /**
         * Returns true if and only if the argument is not null and is a Boolean
         * object that represents the same boolean value as this object.
         *
         * @param obj the object to compare with.
         * @return true if the Boolean objects represent the same value; false
         * otherwise.
         */
        public bool equals(Object obj) {
            // testing another object reference for a NULL value
            if (obj == null) {
                return false;
            }

            // testing object class equality
            if (GetType() != obj.GetType()) {
                return false;
            }

            // testing object fields equality
            return v.Equals((obj as  Boolean).v);
        }

        /**
         * Returns a String object representing this Boolean's value.
         * 
         * @return a string representation of this object.
         */
        public String toString() {
            return Boolean.toString(v);
        }

        /**
         * Returns a String object representing the specified boolean.
         *
         * @param b the boolean to be converted
         * @return the string representation of the specified boolean
         */
        public static String toString(bool b) {
            return b.ToString();
        }

        /**
         * Parses the string argument as a boolean.
         *
         * @param s the String containing the boolean representation to be parsed
         * @return the boolean represented by the string argument
         */
        public static bool parseBoolean(String s) {
            return bool.Parse(s.ToString());
        }

    }

}
