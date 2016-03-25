using System;

namespace JavaClasses
{

    /// <summary>
    /// The Float class wraps a value of primitive type float in an object.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class Float : Comparable<Float>
    {

        /// <summary>
        /// A constant holding the positive infinity of type float.
        /// </summary>
        public const double POSITIVE_INFINITY = 1.0f / 0.0f;

        /// <summary>
        /// A constant holding the negative infinity of type float.
        /// </summary>
        public const double NEGATIVE_INFINITY = -1.0f / 0.0f;

        /// <summary>
        /// A constant holding a Not-a-Number (NaN) value of type float.
        /// </summary>
        public const double NaN = 0.0f / 0.0f;

        /// <summary>
        /// A constant holding the largest positive finite value of type float, (2-2^-23)·2^127.
        /// </summary>
        public const float MAX_VALUE = 3.4028235e+38f;

        /// <summary>
        /// A constant holding the smallest positive nonzero value of type float, 2-^149.
        /// </summary>
        public const float MIN_VALUE = 1.4e-45f;

        /// <summary>
        /// Maximum exponent a finite float variable may have.
        /// </summary>
        public const int MAX_EXPONENT = 127;

        /// <summary>
        /// Minimum exponent a normalized float variable may have.
        /// </summary>
        public const int MIN_EXPONENT = -126;

        /// <summary>
        /// A constant holding the smallest positive normal value of type float, 2^-126.
        /// </summary>
        public const double MIN_NORMAL = 1.17549435E-38f;

        private static readonly int negativeZeroBits = floatToInt32Bits(-0.0f);
        private float v;

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

        /// <summary>
        /// Constructs a newly allocated Float object that represents the primitive
        /// float argument.
        /// </summary>
        /// <param name="value">the value to be represented by the Float.
        /// </param>
        public Float(float value)
        {
            v = value;
        }

        /// <summary>
        /// Returns the float value of this Float object.
        /// </summary>
        /// <returns>the float value represented by this object
        /// </returns>
        public float floatValue()
        {
            return v;
        }

        /// <summary>
        /// Compares two Float objects numerically.
        /// </summary>
        /// <param name="anotherFloat">the Float to be compared.
        /// </param><returns>the value 0 if anotherFloat is numerically equal to this Float; a
        /// value less than 0 if this Float is numerically less than anotherFloat;
        /// and a value greater than 0 if this Float is numerically greater than
        /// anotherFloat.
        /// </returns>
        public override int compareTo(Float anotherFloat)
        {
            return compare(v, anotherFloat.v);
        }

        /// <summary>
        /// Compares the two specified float values.
        /// </summary>
        /// <param name="f1">the first float to compare.
        /// </param><param name="f2">the second float to compare.
        /// </param><returns>the value 0 if f1 is numerically equal to f2; a value less than 0
        /// if f1 is numerically less than f2; and a value greater than 0 if f1 is
        /// numerically greater than f2.
        /// </returns>
        public static int compare(float f1, float f2)
        {
            if (float.IsNaN(f1))
            {
                if (float.IsNaN(f2))
                {
                    return 0;
                }

                return 1;
            }

            if (float.IsNaN(f2))
            {
                return -1;
            }

            if (floatToInt32Bits(f1) == 0
                && floatToInt32Bits(f2) == negativeZeroBits)
            {
                return 1;
            }

            if (floatToInt32Bits(f1) == negativeZeroBits
                && floatToInt32Bits(f2) == 0)
            {
                return -1;
            }

            return (f1 > f2 ? 1 : f1 < f2 ? -1 : 0);
        }

        /// <summary>
        /// Compares this object against the specified object.
        /// </summary>
        /// <param name="obj">the object to be compared
        /// </param><returns>true if the objects are the same; false otherwise.
        /// </returns>
        public override bool equals(Object obj)
        {
            if (obj == null)
            {
                return false;
            }

            if (GetType() != obj.GetType())
            {
                return false;
            }

            float v2 = (obj as Float).v;

            if (float.IsNaN(v) && float.IsNaN(v2))
            {
                return true;
            }

            if (floatToInt32Bits(v) == negativeZeroBits)
            {
                return floatToInt32Bits(v2) == negativeZeroBits;
            }

            if (floatToInt32Bits(v2) == negativeZeroBits)
            {
                return floatToInt32Bits(v) == negativeZeroBits;
            }

            return (v == v2);
        }

        /// <summary>
        /// Returns a string representation of this Float object.
        /// </summary>
        /// <returns>a String representation of this object.
        /// </returns>
        public override String toString()
        {
            return Float.toString(v);
        }

        /// <summary>
        /// Returns a string representation of the float argument.
        /// </summary>
        /// <param name="f">the float to be converted.
        /// </param><returns>a string representation of the argument.
        /// </returns>
        public static String toString(float f)
        {
            return new String(f.ToString());
        }

        /// <summary>
        /// Returns a new float initialized to the value represented by the specified
        /// String, as performed by the valueOf method of class Float.
        /// </summary>
        /// <param name="s">the string to be parsed.
        /// </param><returns>the float value represented by the string argument.
        /// </returns>
        public static float parseFloat(String s)
        {
            return float.Parse(s.ToString());
        }
        
        public static implicit operator Float(float original)
        {
            return new Float(original);
        }
        
    }

}
