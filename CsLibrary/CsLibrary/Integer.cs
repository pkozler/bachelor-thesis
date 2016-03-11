using System;

namespace JavaClasses {

    /// <summary>
    /// The Integer class wraps a value of the primitive type int in an object.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class Integer {

        /// <summary>
        /// A constant holding the maximum value an int can have, 2^31-1.
        /// </summary>
        public const int MAX_VALUE = 2147483647;

        /// <summary>
        /// A constant holding the minimum value an int can have, -2^31.
        /// </summary>
        public const int MIN_VALUE = -2147483648;

        private int v;

        /// <summary>
        /// Constructs a newly allocated Integer object that represents the specified
        /// int value.
        /// </summary>
        /// <param name="value">the value to be represented by the Integer object.
        /// </param>
        public Integer(int value) {
            v = value;
        }

        /// <summary>
        /// Returns the value of this Integer as an int.
        /// </summary>
        /// <returns>the numeric value represented by this object after conversion to
        /// type int.
        /// </returns>
        public int intValue() {
            return v;
        }

        /// <summary>
        /// Compares two Integer objects numerically.
        /// </summary>
        /// <param name="anotherInteger">the Integer to be compared.
        /// </param><returns>the value 0 if this Integer is equal to the argument Integer; a
        /// value less than 0 if this Integer is numerically less than the argument
        /// Integer; and a value greater than 0 if this Integer is numerically
        /// greater than the argument Integer (signed comparison).
        /// </returns>
        public int compareTo(Integer anotherInteger) {
            return compare(v, anotherInteger.v);
        }

        /// <summary>
        /// Compares two int values numerically.
        /// </summary>
        /// <param name="x">the first int to compare
        /// </param><param name="y">the second int to compare
        /// </param><returns>the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
        /// > y
        /// </returns>
        public static int compare(int x, int y) {
            /* 1 if x is greater, 0 if x equals y, -1 otherwise
             (same as for a long type) */
            return (x < y) ? -1 : ((x == y) ? 0 : 1);
        }

        /// <summary>
        /// Compares this object to the specified object.
        /// </summary>
        /// <param name="obj">the object to compare with.
        /// </param><returns>true if the objects are the same; false otherwise.
        /// </returns>
        public bool equals(Object obj) {
            if (obj == null) {
                return false;
            }

            if (GetType() != obj.GetType()) {
                return false;
            }

            return v.Equals((obj as  Integer).v);
        }

        /// <summary>
        /// Returns a String object representing this Integer's value.
        /// </summary>
        /// <returns>a string representation of the value of this object in base 10.
        /// </returns>
        public String toString() {
            return Integer.toString(v);
        }

        /// <summary>
        /// Returns a String object representing the specified integer.
        /// </summary>
        /// <param name="i">an integer to be converted.
        /// </param><returns>a string representation of the argument in base 10.
        /// </returns>
        public static String toString(int i) {
            return i.ToString();
        }

        /// <summary>
        /// Parses the string argument as a signed decimal integer.
        /// </summary>
        /// <param name="s">a String containing the int representation to be parsed
        /// </param><returns>the integer value represented by the argument in decimal.
        /// </returns>
        public static int parseInt(String s) {
            return int.Parse(s.ToString());
        }
        
        public override string ToString() {
            return toString().ToString();
        }

    }

}
