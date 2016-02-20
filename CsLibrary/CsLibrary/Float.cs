using System;

namespace JavaClasses {

    /**
     * The Float class wraps a value of primitive type float in an object.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Float {

        /**
         * A constant holding the largest positive finite value of type float, (2-2^-23)·2^127.
         */
        public const float MAX_VALUE = 3.4028235e+38f;

        /**
         * A constant holding the smallest positive nonzero value of type float, 2-^149.
         */
        public const float MIN_VALUE = 1.4e-45f;
        private float v;

        /**
         * Constructs a newly allocated Float object that represents the primitive float argument.
         */
        public Float(float value) {
            v = value;
        }

        /**
         * Returns the float value of this Float object.
         */
        public float floatValue() {
            return v;
        }

        /**
         * Compares two Float objects numerically.
         */
        public int compareTo(Float anotherFloat) {
            return v.CompareTo(anotherFloat.v);
        }

        /**
         * Compares this object against the specified object.
         */
        public bool equals(Object obj) {
            return v.Equals((obj as Float).v);
        }

        public override string ToString() {
            return toString().ToString();
        }

        /**
         * Returns a string representation of this Float object.
         */
        public String toString() {
            return Float.toString(v);
        }

        /**
         * Returns a string representation of the float argument.
         */
        public static String toString(float f) {
            return f.ToString();
        }

        /**
         * Returns a new float initialized to the value represented by the specified String,
         * as performed by the valueOf method of class Float.
         */
        public static float parseFloat(String s) {
            return float.Parse(s.ToString());
        }
    }
}
