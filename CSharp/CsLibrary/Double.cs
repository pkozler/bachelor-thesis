using System;
using System.Globalization;

namespace JavaClasses
{

    /// <summary>
    /// The Double class wraps a value of the primitive type double in an object.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class Double : Comparable
    {

        /// <summary>
        /// A constant holding the positive infinity of type double.
        /// </summary>
        public const double POSITIVE_INFINITY = 1.0 / 0.0;

        /// <summary>
        /// A constant holding the negative infinity of type double.
        /// </summary>
        public const double NEGATIVE_INFINITY = -1.0 / 0.0;

        /// <summary>
        /// A constant holding a Not-a-Number (NaN) value of type double.
        /// </summary>
        public const double NaN = 0.0 / 0.0;

        /// <summary>
        /// A constant holding the largest positive finite value of type double, (2-2^-52)·2^1023.
        /// </summary>
        public const double MAX_VALUE = 1.7976931348623157e+308;

        /// <summary>
        /// A constant holding the smallest positive nonzero value of type double, 2^-1074.
        /// </summary>
        public const double MIN_VALUE = 4.9e-324;

        /// <summary>
        /// Maximum exponent a finite double variable may have.
        /// </summary>
        public const int MAX_EXPONENT = 1023;

        /// <summary>
        /// Minimum exponent a normalized double variable may have.
        /// </summary>
        public const int MIN_EXPONENT = -1022;

        /// <summary>
        /// A constant holding the smallest positive normal value of type double, 2^-1022.
        /// </summary>
        public const double MIN_NORMAL = 2.2250738585072014E-308;

        // a "binary representation" of negative zero value for comparison purposes
        private static readonly long negativeZeroBits = BitConverter.DoubleToInt64Bits(-0.0);

        // an inner value
        private double v;

        /// <summary>
        /// Constructs a newly allocated Double object that represents the primitive
        /// double argument.
        /// </summary>
        /// <param name="value">the value to be represented by the Double.
        /// </param>
        public Double(double value)
        {
            v = value;
        }

        /// <summary>
        /// Returns the double value of this Double object.
        /// </summary>
        /// <returns>the double value represented by this object
        /// </returns>
        public double doubleValue()
        {
            return v;
        }

        /// <summary>
        /// Compares two Double objects numerically.
        /// </summary>
        /// <param name="anotherDouble">the Double to be compared.
        /// </param><returns>the value 0 if anotherDouble is numerically equal to this Double;
        /// a value less than 0 if this Double is numerically less than
        /// anotherDouble; and a value greater than 0 if this Double is numerically
        /// greater than anotherDouble.
        /// </returns>
        public override int compareTo(Object anotherDouble)
        {
            return compare(v, (anotherDouble as Double).v);
        }

        /// <summary>
        /// Compares the two specified double values.
        /// </summary>
        /// <param name="d1">the first double to compare
        /// </param><param name="d2">the second double to compare
        /// </param><returns>the value 0 if d1 is numerically equal to d2; a value less than 0
        /// if d1 is numerically less than d2; and a value greater than 0 if d1 is
        /// numerically greater than d2.
        /// </returns>
        public static int compare(double d1, double d2)
        {
            /* testing for NaN values (a NaN value is considered greated
               than any other, including positive infinity,
               and two NaN values are considered equal) */
            if (double.IsNaN(d1))
            {
                if (double.IsNaN(d2))
                {
                    return 0;
                }

                return 1;
            }

            if (double.IsNaN(d2))
            {
                return -1;
            }

            /* testing for +0.0 and -0.0 value (a positive zero
               is considered greater than a negative zero) */
            if (BitConverter.DoubleToInt64Bits(d1) == 0
                && BitConverter.DoubleToInt64Bits(d2) == negativeZeroBits)
            {
                return 1;
            }

            if (BitConverter.DoubleToInt64Bits(d1) == negativeZeroBits
                && BitConverter.DoubleToInt64Bits(d2) == 0)
            {
                return -1;
            }

            /* testing for other values and returning
               1 if first value is greater, 0 if first value 
               equals second value, -1 otherwise */
            return (d1 > d2 ? 1 : d1 < d2 ? -1 : 0);
        }

        /// <summary>
        /// Compares this object against the specified object.
        /// </summary>
        /// <param name="obj">the object to compare with.
        /// </param><returns>true if the objects are the same; false otherwise.
        /// </returns>
        public override bool equals(Object obj)
        {
            // testing another object reference for a NULL value
            if (obj == null)
            {
                return false;
            }

            // testing object class equality
            if (GetType() != obj.GetType())
            {
                return false;
            }

            double v2 = (obj as Double).v;

            // testing for NaN values (two NaN values are considered equal)
            if (double.IsNaN(v) && double.IsNaN(v2))
            {
                return true;
            }

            // testing for zero values (+0.0 is considered greater than -0.0)
            if (BitConverter.DoubleToInt64Bits(v) == negativeZeroBits)
            {
                return BitConverter.DoubleToInt64Bits(v2) == negativeZeroBits;
            }

            if (BitConverter.DoubleToInt64Bits(v2) == negativeZeroBits)
            {
                return BitConverter.DoubleToInt64Bits(v) == negativeZeroBits;
            }

            // testing other values
            return (v == v2);
        }

        /// <summary>
        /// Returns a string representation of this Double object.
        /// </summary>
        /// <returns>a String representation of this object.
        /// </returns>
        public override String toString()
        {
            return Double.toString(v);
        }

        /// <summary>
        /// Returns a string representation of the double argument.
        /// </summary>
        /// <param name="d">the double to be converted.
        /// </param><returns>a string representation of the argument.
        /// </returns>
        public static String toString(double d)
        {
            return new String(d.ToString(CultureInfo.InvariantCulture));
        }

        /// <summary>
        /// Returns a new double initialized to the value represented by the
        /// specified String, as performed by the valueOf method of class Double.
        /// </summary>
        /// <param name="s">the string to be parsed.
        /// </param><returns>the double value represented by the string argument.
        /// </returns>
        public static double parseDouble(String s)
        {
            // parsing with invariant culture formatting
            double value = double.Parse(s.ToString(), CultureInfo.InvariantCulture);

            // negative zero handling
            if (value == 0 && s.startsWith("-"))
            {
                return -0.0;
            }

            return value;
        }
        
        public static implicit operator Double(double original)
        {
            return new Double(original);
        }
        
    }

}
