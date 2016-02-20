using System;

namespace JavaClasses {

    /**
     * The Double class wraps a value of the primitive type double in an object.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Double {

        /**
         * A constant holding the largest positive finite value of type double, (2-2^-52)·2^1023.
         */
        public const double MAX_VALUE = 1.7976931348623157e+308;

        /**
         * A constant holding the smallest positive nonzero value of type double, 2^-1074.
         */
        public const double MIN_VALUE = 4.9e-324;
        private double v;

        /**
         * Constructs a newly allocated Double object that represents the primitive double argument.
         */
        public Double(double value) {
            v = value;
        }

        /**
         * Returns the double value of this Double object.
         */
        public double doubleValue() {
            return v;
        }

        /**
         * Compares two Double objects numerically.
         */
        public int compareTo(Double anotherDouble) {
            return v.CompareTo(anotherDouble.v);
        }

        /**
         * Compares this object against the specified object.
         */
        public bool equals(Object obj) {
            return v.Equals((obj as Double).v);
        }

        public override string ToString() {
            return toString().ToString();
        }

        /**
         * Returns a string representation of this Double object.
         */
        public String toString() {
            return Double.toString(v);
        }

        /**
         * Returns a string representation of the double argument.
         */
        public static String toString(double d) {
            return d.ToString();
        }

        /**
         * Returns a new double initialized to the value represented by the specified String,
         * as performed by the valueOf method of class Double.
         */
        public static double parseDouble(String s) {
            return double.Parse(s.ToString());
        }
    }
}
