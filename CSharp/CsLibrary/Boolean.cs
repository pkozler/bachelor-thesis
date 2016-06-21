using System;

namespace JavaClasses
{

    /// <summary>
    /// The Boolean class wraps a value of the primitive type bool (representing a boolean value) in an object.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class Boolean : Comparable
    {

        // an inner value
        private bool v;

        /// <summary>
        /// Allocates a Boolean object representing the value argument.
        /// </summary>
        /// <param name="value">the value of the Boolean.
        /// </param>
        public Boolean(bool value)
        {
            v = value;
        }

        /// <summary>
        /// Returns the value of this Boolean object as a boolean primitive.
        /// </summary>
        /// <returns>the primitive boolean value of this object.
        /// </returns>
        public bool booleanValue()
        {
            return v;
        }

        /// <summary>
        /// Compares this Boolean instance with another.
        /// </summary>
        /// <param name="b">the Boolean instance to be compared
        /// </param><returns>zero if this object represents the same boolean value as the
        /// argument; a positive value if this object represents true and the
        /// argument represents false; and a negative value if this object represents
        /// false and the argument represents true
        /// </returns>
        public override int compareTo(Object b)
        {
            return compare(v, (b as Boolean).v);
        }

        /// <summary>
        /// Compares two boolean values.
        /// </summary>
        /// <param name="x">the first boolean to compare
        /// </param><param name="y">the second boolean to compare
        /// </param><returns>the value 0 if x == y; a value less than 0 if !x && y; and a
        /// value greater than 0 if x && !y
        /// </returns>
        public static int compare(bool x, bool y)
        {
            // 0 if x equals y, 1 if x is TRUE and y is FALSE, -1 otherwise
            return (x == y) ? 0 : (x ? 1 : -1);
        }

        /// <summary>
        /// Returns true if and only if the argument is not null and is a Boolean
        /// object that represents the same boolean value as this object.
        /// </summary>
        /// <param name="obj">the object to compare with.
        /// </param><returns>true if the Boolean objects represent the same value; false
        /// otherwise.
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

            // testing object fields equality
            return v.Equals((obj as Boolean).v);
        }

        /// <summary>
        /// Returns a String object representing this Boolean's value.
        /// </summary>
        /// <returns>a string representation of this object.
        /// </returns>
        public override String toString()
        {
            return Boolean.toString(v);
        }

        /// <summary>
        /// Returns a String object representing the specified boolean.
        /// </summary>
        /// <param name="b">the boolean to be converted
        /// </param><returns>the string representation of the specified boolean
        /// </returns>
        public static String toString(bool b)
        {
            return new String(b.ToString().ToLower());
        }

        /// <summary>
        /// Parses the string argument as a boolean.
        /// </summary>
        /// <param name="s">the String containing the boolean representation to be parsed
        /// </param><returns>the boolean represented by the string argument
        /// </returns>
        public static bool parseBoolean(String s)
        {
            return bool.Parse(s.ToString());
        }
        
        public static implicit operator Boolean(bool original)
        {
            return new Boolean(original);
        }
        
    }

}
