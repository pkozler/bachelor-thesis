using System;
using System.Text;

namespace JavaClasses {

    /**
     * The String class represents character strings.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class String {

        private string s;
        
        /**
         * Constructs a new String by decoding the specified array of bytes using
         * the platform's default charset.
         *
         * @param bytes The bytes to be decoded into characters
         */
        public String(sbyte[] bytes) {
            // parsing to the unsigned byte array
            byte[] unsigned = (byte[]) (Array) bytes;
            s = Encoding.Default.GetString(unsigned);
        }

        /**
         * Constructs a new String by decoding the specified subarray of bytes using
         * the platform's default charset.
         *
         * @param bytes The bytes to be decoded into characters
         * @param offset The index of the first byte to decode
         * @param length The number of bytes to decode
         */
        public String(sbyte[] bytes, int offset, int length) {
            byte[] unsigned = (byte[]) (Array) bytes;
            s = Encoding.Default.GetString(unsigned, offset, length);
        }

        /**
         * Initializes a newly created String object so that it represents the same
         * sequence of characters as the argument; in other words, the newly created
         * string is a copy of the argument string. Unless an explicit copy of
         * original is needed, use of this constructor is unnecessary since Strings
         * are immutable.
         *
         * @param original A String
         */
        public String(string original) {
            s = original;
        }

        /**
         * Compares two strings lexicographically.
         *
         * @param anotherString the String to be compared.
         * @return the value 0 if the argument string is equal to this string; a
         * value less than 0 if this string is lexicographically less than the
         * string argument; and a value greater than 0 if this string is
         * lexicographically greater than the string argument.
         */
        public int compareTo(String anotherString) {
            return s.CompareTo(anotherString.s);
        }

        /**
         * Compares this string to the specified object.
         *
         * @param anObject The object to compare this String against
         * @return true if the given object represents a String equivalent to this
         * string, false otherwise
         */
        public bool equals(Object anObject) {
            if (anObject == null) {
                return false;
            }

            if (GetType() != anObject.GetType()) {
                return false;
            }

            return s.Equals((anObject as  String).s);
        }

        /**
         * Returns a new string that is a substring of this string.
         * 
         * @param beginIndex the beginning index, inclusive.
         * @return the specified substring.
         */
        public String substring(int beginIndex) {
            return s.Substring(beginIndex);
        }

        /**
         * Returns a new string that is a substring of this string.
         *
         * @param beginIndex the beginning index, inclusive.
         * @param endIndex the ending index, exclusive.
         * @return the specified substring.
         */
        public String substring(int beginIndex, int endIndex) {
            // calculating the length from the specified end index
            return s.Substring(beginIndex, endIndex - beginIndex);
        }

        /**
         * Returns the index within this string of the first occurrence of the
         * specified character.
         *
         * @param ch a character (Unicode code point).
         * @return the index of the first occurrence of the character in the
         * character sequence represented by this object, or -1 if the character
         * does not occur.
         */
        public int indexOf(int ch) {
            return s.IndexOf((char) ch);
        }

        /**
         * Returns the index within this string of the first occurrence of the
         * specified character, starting the search at the specified index.
         *
         * @param ch a character (Unicode code point).
         * @param fromIndex the index to start the search from.
         * @return the index of the first occurrence of the character in the
         * character sequence represented by this object that is greater than or
         * equal to fromIndex, or -1 if the character does not occur.
         */
        public int indexOf(int ch, int fromIndex) {
            return s.IndexOf((char) ch, fromIndex);
        }

        /**
         * Returns the index within this string of the first occurrence of the
         * specified substring.
         *
         * @param str the substring to search for.
         * @return the index of the first occurrence of the specified substring, or
         * -1 if there is no such occurrence.
         */
        public int indexOf(String str) {
            return s.IndexOf(str.s);
        }

        /**
         * Returns the index within this string of the first occurrence of the
         * specified substring, starting at the specified index.
         *
         * @param str the substring to search for.
         * @param fromIndex the index from which to start the search.
         * @return the index of the first occurrence of the specified substring,
         * starting at the specified index, or -1 if there is no such occurrence.
         */
        public int indexOf(String str, int fromIndex) {
            return s.IndexOf(str.s, fromIndex);
        }

        /**
         * Returns the length of this string.
         *
         * @return the length of the sequence of characters represented by this
         * object.
         */
        public int length() {
            return s.Length;
        }

        /**
         * Returns a copy of the string, with leading and trailing whitespace
         * omitted.
         *
         * @return A copy of this string with leading and trailing white space
         * removed, or this string if it has no leading or trailing white space.
         */
        public String trim() {
            return s.Trim();
        }

        /**
         * Converts all of the characters in this String to lower case using the
         * rules of the default locale.
         *
         * @return the String, converted to lowercase.
         */
        public String toLowerCase() {
            return s.ToLower();
        }

        /**
         * Converts all of the characters in this String to upper case using the
         * rules of the default locale.
         *
         * @return the String, converted to uppercase.
         */
        public String toUpperCase() {
            return s.ToUpper();
        }

        /**
         * Returns the char value at the specified index.
         *
         * @param index the index of the char value.
         * @return the char value at the specified index of this string. The first
         * char value is at index 0.
         */
        public char charAt(int index) {
            return s[index];
        }

        /**
         * Returns a new string resulting from replacing all occurrences of oldChar
         * in this string with newChar.
         *
         * @param oldChar the old character.
         * @param newChar the new character.
         * @return a string derived from this string by replacing every occurrence
         * of oldChar with newChar.
         */
        public String replace(char oldChar, char newChar) {
            return s.Replace(oldChar, newChar);
        }

        /**
         * Tests if this string starts with the specified prefix.
         *
         * @param prefix the prefix.
         * @return true if the character sequence represented by the argument is a
         * prefix of the character sequence represented by this string; false
         * otherwise. Note also that true will be returned if the argument is an
         * empty string or is equal to this String object as determined by the
         * equals(Object) method.
         */
        public bool startsWith(String prefix) {
            return s.StartsWith(prefix.s);
        }

        /**
         * Tests if this string ends with the specified suffix.
         *
         * @param suffix the suffix.
         * @return true if the character sequence represented by the argument is a
         * suffix of the character sequence represented by this object; false
         * otherwise. Note that the result will be true if the argument is the empty
         * string or is equal to this String object as determined by the
         * equals(Object) method.
         */
        public bool endsWith(String suffix) {
            return s.EndsWith(suffix.s);
        }

        /**
         * Returns true if, and only if, length() is 0.
         *
         * @return true if length() is 0, otherwise false
         */
        public bool isEmpty() {
            return s.Length == 0;
        }

        /*
            Returns the inner string value for processing by standard library classes.
        */
        public override string ToString() {
            return s;
        }

        /*
            Defines the implicit operator so it is possible to instantiate
            this class by standard string value assignment.
        */
        public static implicit operator String(string original) {
            return new String(original);
        }

        /*
            Defines the operator of concatenation so it is posible
            to use the plus operator the same way as for the standard strings.
        */
        public static String operator +(String s1, String s2) {
            return s1.s + s2.s;
        }

    }

}
