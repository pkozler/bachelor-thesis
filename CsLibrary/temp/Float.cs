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
        
        /**
         * Constructs a newly allocated Float object that represents the primitive float argument.
         */
        public Float(float value) {
            v = value;
        }

        /*
            Converts a single-precision decimal value to the 32-bit integer value
            with exactly the same binary representation.
         */
        private static int floatToInt32Bits(float f)
        {
            // copying the array with one float value to the byte array with corresponding length
            float[] floats = new[] { f };
            byte[] bytes = new byte[4];
            Buffer.BlockCopy(floats, 0, bytes, 0, 4);

            // converting the byte array to the corresponding integer value
            return BitConverter.ToInt32(bytes, 0);
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
            return compare(v, anotherFloat.v);
        }

        /**
         * Compares the two specified float values.
         */
        public static int compare(float v, float v2) {
            if (float.IsNaN(v)) {
                if (float.IsNaN(v2)) {
                    return 0;
                }

                return 1;
            }

            if (float.IsNaN(v2)) {
                return -1;
            }

            if (floatToInt32Bits(v) == 0
                && floatToInt32Bits(v2) == negativeZeroBits) {
                return 1;
            }

            if (floatToInt32Bits(v) == negativeZeroBits
                && floatToInt32Bits(v2) == 0) {
                return -1;
            }

            return (v > v2 ? 1 : v < v2 ? -1 : 0);
        }

        /**
         * Compares this object against the specified object.
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
