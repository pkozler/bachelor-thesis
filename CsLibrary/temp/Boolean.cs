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
         */
        public Boolean(bool value) {
            v = value;
        }

        /**
         * Returns the value of this Boolean object as a boolean primitive.
         */
        public bool booleanValue() {
            return v;
        }
        
        /**
         * Compares this Boolean instance with another.
         */
        public int compareTo(Boolean anotherBoolean) {
            return compare(v, anotherBoolean.v);
        }

        /**
         * Compares two boolean values.
         */
        public static int compare(bool x, bool y) {
            /* 0 if x equals y, 1 if x is TRUE and y is FALSE, -1 otherwise 
               (analogical for integer values) */
            return (x == y) ? 0 : (x ? 1 : -1);
        }

        /**
         * Returns true if and only if the argument is not null and is
         * a Boolean object that represents the same boolean value as this object.
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
            return v.Equals((obj as Boolean).v);
        }

        public override string ToString() {
            return toString().ToString();
        }

        /**
         * Returns a String object representing this Boolean's value.
         */
        public String toString() {
            return Boolean.toString(v);
        }

        /**
         * Returns a String object representing the specified boolean.
         */
        public static String toString(bool b) {
            return b.ToString();
        }

        /**
         * Parses the string argument as a boolean.
         */
        public static bool parseBoolean(String s) {
            return bool.Parse(s.ToString());
        }
    }
}
