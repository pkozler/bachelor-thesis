using System;

namespace JavaClasses {

    /**
     * The Float class wraps a value of primitive type float in an object.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Float {
        
        /**
         * A constant holding the positive infinity of type float.
         */
        public const double POSITIVE_INFINITY = 1.0f / 0.0f;

        /**
         * A constant holding the negative infinity of type float.
         */
        public const double NEGATIVE_INFINITY = -1.0f / 0.0f;

        /**
         * A constant holding a Not-a-Number (NaN) value of type float.
         */
        public const double NaN = 0.0f / 0.0f;

        /**
         * A constant holding the largest positive finite value of type float, (2-2^-23)·2^127.
         */
        public const float MAX_VALUE = 3.4028235e+38f;

        /**
         * A constant holding the smallest positive nonzero value of type float, 2-^149.
         */
        public const float MIN_VALUE = 1.4e-45f;

        /**
         * Maximum exponent a finite float variable may hav
         */
        public const int MAX_EXPONENT = 127;

        /**
         * Minimum exponent a normalized float variable may have.
         */
        public const int MIN_EXPONENT = -126;

        /**
         * A constant holding the smallest positive normal value of type float, 2^-126.
         */
        public const double MIN_NORMAL = 1.17549435E-38f;
        
        private static readonly int negativeZeroBits = floatToInt32Bits(-0.0f);
        private float v;
        
        /*
            Converts a single-precision decimal value to the 32-bit integer value
            with exactly the same binary representation.
         */
        private static int floatToInt32Bits(float f) {
            // copying the array with one float value to the byte array with corresponding length
            float[] floats = new []{f};
            byte[] bytes = new byte[4];
            Buffer.BlockCopy(floats, 0, bytes, 0, 4);

            // converting the byte array to the corresponding integer value
            return BitConverter.ToInt32(bytes, 0);
        }

        /**
         * Constructs a newly allocated Float object that represents the primitive
         * float argument.
         *
         * @param value the value to be represented by the Float.
         */
        public Float(float value) {
            v = value;
        }

        /**
         * Returns the float value of this Float object.
         *
         * @return the float value represented by this object
         */
        public float floatValue() {
            return v;
        }

        /**
         * Compares two Float objects numerically.
         *
         * @param anotherFloat the Float to be compared.
         * @return the value 0 if anotherFloat is numerically equal to this Float; a
         * value less than 0 if this Float is numerically less than anotherFloat;
         * and a value greater than 0 if this Float is numerically greater than
         * anotherFloat.
         */
        public int compareTo(Float anotherFloat) {
            return compare(v, anotherFloat.v);
        }

        /**
         * Compares the two specified float values.
         *
         * @param f1 the first float to compare.
         * @param f2 the second float to compare.
         * @return the value 0 if f1 is numerically equal to f2; a value less than 0
         * if f1 is numerically less than f2; and a value greater than 0 if f1 is
         * numerically greater than f2.
         */
        public static int compare(float f1, float f2) {
            if (float.IsNaN(f1)) {
                if (float.IsNaN(f2)) {
                    return 0;
                }

                return 1;
            }

            if (float.IsNaN(f2)) {
                return -1;
            }

            if (floatToInt32Bits(f1) == 0
                && floatToInt32Bits(f2) == negativeZeroBits) {
                return 1;
            }

            if (floatToInt32Bits(f1) == negativeZeroBits
                && floatToInt32Bits(f2) == 0) {
                return -1;
            }

            return (f1 > f2 ? 1 : f1 < f2 ? -1 : 0);
        }

        /**
         * Compares this object against the specified object.
         *
         * @param obj the object to be compared
         * @return true if the objects are the same; false otherwise.
         */
        public bool equals(Object obj) {
            if (obj == null) {
                return false;
            }

            if (GetType() != obj.GetType()) {
                return false;
            }

            float v2 = (obj as Float).v;

            if (float.IsNaN(v) && float.IsNaN(v2)) {
                return true;
            }

            if (floatToInt32Bits(v) == negativeZeroBits) {
                return floatToInt32Bits(v2) == negativeZeroBits;
            }

            if (floatToInt32Bits(v2) == negativeZeroBits) {
                return floatToInt32Bits(v) == negativeZeroBits;
            }

            return (v == v2);
        }

        /**
         * Returns a string representation of this Float object.
         *
         * @return a String representation of this object.
         */
        public String toString() {
            return Float.toString(v);
        }

        /**
         * Returns a string representation of the float argument.
         *
         * @param f the float to be converted.
         * @return a string representation of the argument.
         */
        public static String toString(float f) {
            return f.ToString();
        }

        /**
         * Returns a new float initialized to the value represented by the specified
         * String, as performed by the valueOf method of class Float.
         *
         * @param s the string to be parsed.
         * @return the float value represented by the string argument.
         */
        public static float parseFloat(String s) {
            return float.Parse(s.ToString());
        }
        
        public override string ToString() {
            return toString().ToString();
        }

    }

}
