using System;

namespace JavaClasses
{

    /// <summary>
    /// The Character class wraps a value of the primitive type char in an object.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class Character : IComparable<Character>
    {

        private char v;

        /// <summary>
        /// Constructs a newly allocated Character object that represents the
        /// specified char value.
        /// </summary>
        /// <param name="value">the value to be represented by the Character object.
        /// </param>
        public Character(char value)
        {
            v = value;
        }

        /// <summary>
        /// Returns the value of this Character object.
        /// </summary>
        /// <returns>the primitive char value represented by this object.
        /// </returns>
        public char charValue()
        {
            return v;
        }

        /// <summary>
        /// Compares two Character objects numerically.
        /// </summary>
        /// <param name="anotherCharacter">the Character to be compared.
        /// </param><returns>the value 0 if the argument Character is equal to this Character;
        /// a value less than 0 if this Character is numerically less than the
        /// Character argument; and a value greater than 0 if this Character is
        /// numerically greater than the Character argument (unsigned comparison).
        /// Note that this is strictly a numerical comparison; it is not
        /// locale-dependent.
        /// </returns>
        public int compareTo(Character anotherCharacter)
        {
            return compare(v, anotherCharacter.v);
        }

        /// <summary>
        /// Compares two char values numerically.
        /// </summary>
        /// <param name="x">the first char to compare
        /// </param><param name="y">the second char to compare
        /// </param><returns>the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
        /// > y
        /// </returns>
        public static int compare(char x, char y)
        {
            return x - y;
        }

        /// <summary>
        /// Compares this object against the specified object.
        /// </summary>
        /// <param name="obj">the object to compare with.
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

            return v.Equals((obj as Character).v);
        }

        /// <summary>
        /// Returns a String object representing this Character's value.
        /// </summary>
        /// <returns>a string representation of this object.
        /// </returns>
        public String toString()
        {
            return Character.toString(v);
        }

        /// <summary>
        /// Returns a String object representing the specified char.
        /// </summary>
        /// <param name="c">the char to be converted
        /// </param><returns>the string representation of the specified char
        /// </returns>
        public static String toString(char c)
        {
            return c.ToString();
        }

        /// <summary>
        /// Determines if the specified character is a digit.
        /// </summary>
        /// <param name="ch">the character to be tested.
        /// </param><returns>true if the character is a digit; false otherwise.
        /// </returns>
        public static bool isDigit(char ch)
        {
            return char.IsDigit(ch);
        }

        /// <summary>
        /// Determines if the specified character is a letter.
        /// </summary>
        /// <param name="ch">the character to be tested.
        /// </param><returns>true if the character is a letter; false otherwise.
        /// </returns>
        public static bool isLetter(char ch)
        {
            return char.IsLetter(ch);
        }

        public override string ToString()
        {
            return toString();
        }

        public int CompareTo(Character other)
        {
            return compareTo(other);
        }

        public static implicit operator Character(char original)
        {
            return new Character(original);
        }

        public static implicit operator char (Character original)
        {
            return original.charValue();
        }

    }

}
