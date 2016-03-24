using System;
using System.Collections.Generic;
using System.Text;

namespace JavaClasses
{

    /// <summary>
    /// Class Object is the root of the class hierarchy.
    /// </summary>
    public class Object
    {

        /// <summary>
        /// Indicates whether some other object is "equal to" this one.
        /// </summary>
        /// <param name="obj">the reference object with which to compare.</param>
        /// <returns>true if this object is the same as the obj argument; false otherwise.</returns>
        public virtual bool equals(Object obj)
        {
            return this == obj;
        }

        /// <summary>
        /// Returns a string representation of the object.
        /// </summary>
        /// <returns>a string representation of the object.</returns>
        public virtual String toString()
        {
            return new String(base.ToString());
        }

        public override bool Equals(object obj)
        {
            return equals(obj as Object);
        }

        public override string ToString()
        {
            return toString().s;
        }

    }

    /// <summary>
    /// This interface imposes a total ordering on the objects of each class that implements it.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public abstract class Comparable<T> : Object, IComparable<T> where T : Object
    {

        /// <summary>
        /// Compares this object with the specified object for order.
        /// </summary>
        /// <param name="o">the object to be compared.</param>
        /// <returns>a negative integer, zero, or a positive integer as this object
        /// is less than, equal to, or greater than the specified object.</returns>
        public abstract int compareTo(T o);

        public int CompareTo(T o)
        {
            return compareTo(o);
        }

    }

    /// <summary>
    /// A comparison function, which imposes a total ordering on some collection of objects.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public abstract class Comparator<T> : Object, IComparer<T> where T : Object
    {

        /// <summary>
        /// Compares its two arguments for order.
        /// </summary>
        /// <param name="o1">the first object to be compared.</param>
        /// <param name="o2">the second object to be compared.</param>
        /// <returns>negative integer, zero, or a positive integer as the
        /// first argument is less than, equal to, or greater than the second.</returns>
        public abstract int compare(T o1, T o2);

        public int Compare(T o1, T o2)
        {
            return compare(o1, o2);
        }

    }

    /// <summary>
    /// The String class represents character strings.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class String : Comparable<String>
    {

        public string s { get; private set; }

        /// <summary>
        /// Constructs a new String by decoding the specified array of bytes using
        /// the platform's default charset.
        /// </summary>
        /// <param name="bytes">The bytes to be decoded into characters
        /// </param>
        public String(sbyte[] bytes)
        {
            // parsing to the unsigned byte array
            byte[] unsigned = (byte[])(Array)bytes;
            s = Encoding.Default.GetString(unsigned);
        }

        /// <summary>
        /// Constructs a new String by decoding the specified subarray of bytes using
        /// the platform's default charset.
        /// </summary>
        /// <param name="bytes">The bytes to be decoded into characters
        /// </param><param name="offset">The index of the first byte to decode
        /// </param><param name="length">The number of bytes to decode
        /// </param>
        public String(sbyte[] bytes, int offset, int length)
        {
            byte[] unsigned = (byte[])(Array)bytes;
            s = Encoding.Default.GetString(unsigned, offset, length);
        }

        /// <summary>
        /// Initializes a newly created String object so that it represents the same
        /// sequence of characters as the argument; in other words, the newly created
        /// string is a copy of the argument string. Unless an explicit copy of
        /// original is needed, use of this constructor is unnecessary since Strings
        /// are immutable.
        /// </summary>
        /// <param name="original">A String
        /// </param>
        public String(string original)
        {
            s = original;
        }

        /// <summary>
        /// Compares two strings lexicographically.
        /// </summary>
        /// <param name="anotherString">the String to be compared.
        /// </param><returns>the value 0 if the argument string is equal to this string; a
        /// value less than 0 if this string is lexicographically less than the
        /// string argument; and a value greater than 0 if this string is
        /// lexicographically greater than the string argument.
        /// </returns>
        public override int compareTo(String anotherString)
        {
            return s.CompareTo(anotherString.s);
        }

        /// <summary>
        /// Compares this string to the specified object.
        /// </summary>
        /// <param name="anObject">The object to compare this String against
        /// </param><returns>true if the given object represents a String equivalent to this
        /// string, false otherwise
        /// </returns>
        public override bool equals(Object anObject)
        {
            if (anObject == null)
            {
                return false;
            }

            if (GetType() != anObject.GetType())
            {
                return false;
            }

            return s.Equals((anObject as String).s);
        }

        /// <summary>
        /// Returns a new string that is a substring of this string.
        /// </summary>
        /// <param name="beginIndex">the beginning index, inclusive.
        /// </param><returns>the specified substring.
        /// </returns>
        public String substring(int beginIndex)
        {
            return new String(s.Substring(beginIndex));
        }

        /// <summary>
        /// Returns a new string that is a substring of this string.
        /// </summary>
        /// <param name="beginIndex">the beginning index, inclusive.
        /// </param><param name="endIndex">the ending index, exclusive.
        /// </param><returns>the specified substring.
        /// </returns>
        public String substring(int beginIndex, int endIndex)
        {
            // calculating the length from the specified end index
            return new String(s.Substring(beginIndex, endIndex - beginIndex));
        }

        /// <summary>
        /// Returns the index within this string of the first occurrence of the
        /// specified character.
        /// </summary>
        /// <param name="ch">a character (Unicode code point).
        /// </param><returns>the index of the first occurrence of the character in the
        /// character sequence represented by this object, or -1 if the character
        /// does not occur.
        /// </returns>
        public int indexOf(int ch)
        {
            return s.IndexOf((char)ch);
        }

        /// <summary>
        /// Returns the index within this string of the first occurrence of the
        /// specified character, starting the search at the specified index.
        /// </summary>
        /// <param name="ch">a character (Unicode code point).
        /// </param><param name="fromIndex">the index to start the search from.
        /// </param><returns>the index of the first occurrence of the character in the
        /// character sequence represented by this object that is greater than or
        /// equal to fromIndex, or -1 if the character does not occur.
        /// </returns>
        public int indexOf(int ch, int fromIndex)
        {
            return s.IndexOf((char)ch, fromIndex);
        }

        /// <summary>
        /// Returns the index within this string of the first occurrence of the
        /// specified substring.
        /// </summary>
        /// <param name="str">the substring to search for.
        /// </param><returns>the index of the first occurrence of the specified substring, or
        /// -1 if there is no such occurrence.
        /// </returns>
        public int indexOf(String str)
        {
            return s.IndexOf(str.s);
        }

        /// <summary>
        /// Returns the index within this string of the first occurrence of the
        /// specified substring, starting at the specified index.
        /// </summary>
        /// <param name="str">the substring to search for.
        /// </param><param name="fromIndex">the index from which to start the search.
        /// </param><returns>the index of the first occurrence of the specified substring,
        /// starting at the specified index, or -1 if there is no such occurrence.
        /// </returns>
        public int indexOf(String str, int fromIndex)
        {
            return s.IndexOf(str.s, fromIndex);
        }

        /// <summary>
        /// Returns the length of this string.
        /// </summary>
        /// <returns>the length of the sequence of characters represented by this
        /// object.
        /// </returns>
        public int length()
        {
            return s.Length;
        }

        /// <summary>
        /// Returns a copy of the string, with leading and trailing whitespace
        /// omitted.
        /// </summary>
        /// <returns>A copy of this string with leading and trailing white space
        /// removed, or this string if it has no leading or trailing white space.
        /// </returns>
        public String trim()
        {
            return new String(s.Trim());
        }

        /// <summary>
        /// Converts all of the characters in this String to lower case using the
        /// rules of the default locale.
        /// </summary>
        /// <returns>the String, converted to lowercase.
        /// </returns>
        public String toLowerCase()
        {
            return new String(s.ToLower());
        }

        /// <summary>
        /// Converts all of the characters in this String to upper case using the
        /// rules of the default locale.
        /// </summary>
        /// <returns>the String, converted to uppercase.
        /// </returns>
        public String toUpperCase()
        {
            return new String(s.ToUpper());
        }

        /// <summary>
        /// Returns the char value at the specified index.
        /// </summary>
        /// <param name="index">the index of the char value.
        /// </param><returns>the char value at the specified index of this string. The first
        /// char value is at index 0.
        /// </returns>
        public char charAt(int index)
        {
            return s[index];
        }

        /// <summary>
        /// Returns a new string resulting from replacing all occurrences of oldChar
        /// in this string with newChar.
        /// </summary>
        /// <param name="oldChar">the old character.
        /// </param><param name="newChar">the new character.
        /// </param><returns>a string derived from this string by replacing every occurrence
        /// of oldChar with newChar.
        /// </returns>
        public String replace(char oldChar, char newChar)
        {
            return new String(s.Replace(oldChar, newChar));
        }

        /// <summary>
        /// Tests if this string starts with the specified prefix.
        /// </summary>
        /// <param name="prefix">the prefix.
        /// </param><returns>true if the character sequence represented by the argument is a
        /// prefix of the character sequence represented by this string; false
        /// otherwise. Note also that true will be returned if the argument is an
        /// empty string or is equal to this String object as determined by the
        /// equals(Object) method.
        /// </returns>
        public bool startsWith(String prefix)
        {
            return s.StartsWith(prefix.s);
        }

        /// <summary>
        /// Tests if this string ends with the specified suffix.
        /// </summary>
        /// <param name="suffix">the suffix.
        /// </param><returns>true if the character sequence represented by the argument is a
        /// suffix of the character sequence represented by this object; false
        /// otherwise. Note that the result will be true if the argument is the empty
        /// string or is equal to this String object as determined by the
        /// equals(Object) method.
        /// </returns>
        public bool endsWith(String suffix)
        {
            return s.EndsWith(suffix.s);
        }

        /// <summary>
        /// Returns true if, and only if, length() is 0.
        /// </summary>
        /// <returns>true if length() is 0, otherwise false
        /// </returns>
        public bool isEmpty()
        {
            return s.Length == 0;
        }

        /// <summary>
        /// This object (which is already a string!) is itself returned.
        /// </summary>
        /// <returns>the string itself.</returns>
        public override String toString()
        {
            return new String(s);
        }
        
        public static implicit operator String(string original)
        {
            return new String(original);
        }
        
    }

}
