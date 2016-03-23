using System;

namespace JavaClasses
{

    /// <summary>
    /// The Byte class wraps a value of primitive type byte in an object.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class Byte : IComparable<Byte>
    {

        /// <summary>
        /// A constant holding the maximum value a byte can have, 2^7-1.
        public const sbyte MAX_VALUE = 127;

        /// <summary>
        /// A constant holding the minimum value a byte can have, -2^7.
        public const sbyte MIN_VALUE = -128;

        private sbyte v;

        /// <summary>
        /// Constructs a newly allocated Byte object that represents the specified
        /// byte value.
        /// </summary>
        /// <param name="value">the value to be represented by the Byte.
        /// </param>
        public Byte(sbyte value)
        {
            v = value;
        }

        /// <summary>
        /// Returns the value of this Byte as a byte.
        /// </summary>
        /// <returns>the numeric value represented by this object after conversion to
        /// type byte.
        /// </returns>
        public sbyte byteValue()
        {
            return v;
        }

        /// <summary>
        /// Compares two Byte objects numerically.
        /// </summary>
        /// <param name="anotherByte">the Byte to be compared.
        /// </param><returns>the value 0 if this Byte is equal to the argument Byte; a value
        /// less than 0 if this Byte is numerically less than the argument Byte; and
        /// a value greater than 0 if this Byte is numerically greater than the
        /// argument Byte (signed comparison).
        /// </returns>
        public int compareTo(Byte anotherByte)
        {
            return compare(v, anotherByte.v);
        }

        /// <summary>
        /// Compares two byte values numerically.
        /// </summary>
        /// <param name="x">the first byte to compare
        /// </param><param name="y">the second byte to compare
        /// </param><returns>the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
        /// > y
        /// </returns>
        public static int compare(sbyte x, sbyte y)
        {
            /* positive number if x is greater, 0 if x equals y, negative number otherwise
             (same as for char and short types) */
            return x - y;
        }

        /// <summary>
        /// Compares this object to the specified object.
        /// </summary>
        /// <param name="obj">the object to compare with
        /// </param><returns>true if the objects are the same; false otherwise.
        /// </returns>
        public bool equals(Object obj)
        {
            if (obj == null)
            {
                return false;
            }

            if (GetType() != obj.GetType())
            {
                return false;
            }

            return v.Equals((obj as Byte).v);
        }

        /// <summary>
        /// Returns a String object representing this Byte's value.
        /// </summary>
        /// <returns>a string representation of the value of this object in base 10.
        /// </returns>
        public String toString()
        {
            return Byte.toString(v);
        }

        /// <summary>
        /// Returns a new String object representing the specified byte.
        /// </summary>
        /// <param name="b">the byte to be converted
        /// </param><returns>the string representation of the specified byte
        /// </returns>
        public static String toString(sbyte b)
        {
            return b.ToString();
        }

        /// <summary>
        /// Parses the string argument as a signed decimal byte.
        /// </summary>
        /// <param name="s">a String containing the byte representation to be parsed
        /// </param><returns>the byte value represented by the argument in decimal
        /// </returns>
        public static sbyte parseByte(String s)
        {
            return sbyte.Parse(s.ToString());
        }

        public override string ToString()
        {
            return toString();
        }

        public int CompareTo(Byte other)
        {
            return compareTo(other);
        }

        public static implicit operator Byte(sbyte original)
        {
            return new Byte(original);
        }

        public static implicit operator sbyte (Byte original)
        {
            return original.byteValue();
        }

    }

}
