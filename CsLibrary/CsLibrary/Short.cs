using System;

namespace JavaClasses
{

    /// <summary>
    /// The Short class wraps a value of primitive type short in an object.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class Short : Comparable<Short>
    {

        /// <summary>
        /// A constant holding the maximum value a short can have, 2^15-1.
        /// </summary>
        public const short MAX_VALUE = 32767;

        /// <summary>
        /// A constant holding the minimum value a short can have, -2^15.
        /// </summary>
        public const short MIN_VALUE = -32768;

        private short v;

        /// <summary>
        /// Constructs a newly allocated Short object that represents the specified
        /// short value.
        /// </summary>
        /// <param name="value">the value to be represented by the Short.
        /// </param>
        public Short(short value)
        {
            v = value;
        }

        /// <summary>
        /// Returns the value of this Short as a short.
        /// </summary>
        /// <returns>the numeric value represented by this object after conversion to
        /// type short.
        /// </returns>
        public short shortValue()
        {
            return v;
        }

        /// <summary>
        /// Compares two Short objects numerically.
        /// </summary>
        /// <param name="anotherShort">the Short to be compared.
        /// </param><returns>the value 0 if this Short is equal to the argument Short; a value
        /// less than 0 if this Short is numerically less than the argument Short;
        /// and a value greater than 0 if this Short is numerically greater than the
        /// argument Short (signed comparison).
        /// </returns>
        public override int compareTo(Short anotherShort)
        {
            return compare(v, anotherShort.v);
        }

        /// <summary>
        /// Compares two short values numerically.
        /// </summary>
        /// <param name="x">the first short to compare
        /// </param><param name="y">the second short to compare
        /// </param><returns>the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
        /// > y
        /// </returns>
        public static int compare(short x, short y)
        {
            return x - y;
        }

        /// <summary>
        /// Compares this object to the specified object.
        /// </summary>
        /// <param name="obj">the object to compare with
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

            return v.Equals((obj as Short).v);
        }

        /// <summary>
        /// Returns a String object representing this Short's value.
        /// </summary>
        /// <returns>a string representation of the value of this object in base 10.
        /// </returns>
        public override String toString()
        {
            return Short.toString(v);
        }

        /// <summary>
        /// Returns a new String object representing the specified short.
        /// </summary>
        /// <param name="s">the short to be converted
        /// </param><returns>the string representation of the specified short
        /// </returns>
        public static String toString(short s)
        {
            return new String(s.ToString());
        }

        /// <summary>
        /// Parses the string argument as a signed decimal short.
        /// </summary>
        /// <param name="s">a String containing the short representation to be parsed
        /// </param><returns>the short value represented by the argument in decimal.
        /// </returns>
        public static short parseShort(String s)
        {
            return short.Parse(s.ToString());
        }
        
        public static implicit operator Short(short original)
        {
            return new Short(original);
        }
        
    }

}
