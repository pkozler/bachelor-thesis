using System;

namespace JavaClasses
{

    /// <summary>
    /// The Long class wraps a value of the primitive type long in an object.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class Long : Comparable<Long>
    {

        /// <summary>
        /// A constant holding the maximum value a long can have, 2^63-1.
        /// </summary>
        public const long MAX_VALUE = 9223372036854775807;

        /// <summary>
        /// A constant holding the minimum value a long can have, -2^63.
        /// </summary>
        public const long MIN_VALUE = -9223372036854775808;

        // an inner value
        private long v;

        /// <summary>
        /// Constructs a newly allocated Long object that represents the specified
        /// long argument.
        /// </summary>
        /// <param name="value">the value to be represented by the Long object.
        /// </param>
        public Long(long value)
        {
            v = value;
        }

        /// <summary>
        /// Returns the value of this Long as a long value.
        /// </summary>
        /// <returns>the numeric value represented by this object after conversion to
        /// type long.
        /// </returns>
        public long longValue()
        {
            return v;
        }

        /// <summary>
        /// Compares two Long objects numerically.
        /// </summary>
        /// <param name="anotherLong">the Long to be compared.
        /// </param><returns>the value 0 if this Long is equal to the argument Long; a value
        /// less than 0 if this Long is numerically less than the argument Long; and
        /// a value greater than 0 if this Long is numerically greater than the
        /// argument Long (signed comparison).
        /// </returns>
        public override int compareTo(Long anotherLong)
        {
            return compare(v, anotherLong.v);
        }

        /// <summary>
        /// Compares two long values numerically.
        /// </summary>
        /// <param name="x">the first long to compare
        /// </param><param name="y">the second long to compare
        /// </param><returns>the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
        /// > y
        /// </returns>
        public static int compare(long x, long y)
        {
            return (x < y) ? -1 : ((x == y) ? 0 : 1);
        }

        /// <summary>
        /// Compares this object to the specified object.
        /// </summary>
        /// <param name="obj">the object to compare with.
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

            return v.Equals((obj as Long).v);
        }

        /// <summary>
        /// Returns a String object representing this Long's value.
        /// </summary>
        /// <returns>a string representation of the value of this object in base 10.
        /// </returns>
        public override String toString()
        {
            return Long.toString(v);
        }

        /// <summary>
        /// Returns a String object representing the specified long.
        /// </summary>
        /// <param name="l">a long to be converted.
        /// </param><returns>a string representation of the argument in base 10.
        /// </returns>
        public static String toString(long l)
        {
            return new String(l.ToString());
        }

        /// <summary>
        /// Parses the string argument as a signed long in the radix specified by the
        /// second argument.
        /// </summary>
        /// <param name="s">a String containing the long representation to be parsed
        /// </param><returns>the long represented by the argument in decimal.
        /// </returns>
        public static long parseLong(String s)
        {
            return long.Parse(s.ToString());
        }
        
        public static implicit operator Long(long original)
        {
            return new Long(original);
        }
        
    }

}
