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
         * Constructs a new String by decoding the specified array of bytes using the platform's default charset.
         */
        public String(sbyte[] bytes) {
            byte[] unsigned = (byte[])(Array)bytes;
            s = Encoding.Default.GetString(unsigned);
        }

        /**
         * Constructs a new String by decoding the specified subarray of bytes using the platform's default charset.
         */
        public String(sbyte[] bytes, int offset, int length) {
            byte[] unsigned = (byte[])(Array)bytes;
            s = Encoding.Default.GetString(unsigned, offset, length);
        }

        public String(string original) {
            s = original;
        }

        /**
         * Compares two strings lexicographically.
         */
        public int compareTo(String anotherString) {
            return s.CompareTo(anotherString.s);
        }

        /**
         * Compares this string to the specified object.
         */
        public bool equals(Object anObject) {
            return s.Equals((anObject as String).s);
        }

        /**
         * Returns a new string that is a substring of this string.
         */
        public String substring(int beginIndex) {
            return s.Substring(beginIndex);
        }

        /**
         * Returns a new string that is a substring of this string.
         */
        public String substring(int beginIndex, int endIndex) {
            return s.Substring(beginIndex, endIndex - beginIndex);
        }

        /**
         * Returns the index within this string of the first occurrence of the specified character.
         */
        public int indexOf(int ch) {
            return s.IndexOf((char)ch);
        }

        /**
         * Returns the index within this string of the first occurrence of the specified character, starting the search at the specified index.
         */
        public int indexOf(int ch, int fromIndex) {
            return s.IndexOf((char)ch, fromIndex);
        }

        /**
         * Returns the index within this string of the first occurrence of the specified substring.
         */
        public int indexOf(String str) {
            return s.IndexOf(str.s);
        }

        /**
         * Returns the index within this string of the first occurrence of the specified substring, starting at the specified index.
         */
        public int indexOf(String str, int fromIndex) {
            return s.IndexOf(str.s, fromIndex);
        }

        /**
         * Returns the length of this string.
         */
        public int length() {
            return s.Length;
        }

        /**
         * Returns a copy of the string, with leading and trailing whitespace omitted.
         */
        public String trim() {
            return s.Trim();
        }

        /**
         * Converts all of the characters in this String to lower case using the rules of the default locale.
         */
        public String toLowerCase() {
            return s.ToLower();
        }

        /**
         * Converts all of the characters in this String to upper case using the rules of the default locale.
         */
        public String toUpperCase() {
            return s.ToUpper();
        }

        /**
         * Returns the char value at the specified index.
         */
        public char charAt(int index) {
            return s[index];
        }

        /**
         * Returns a new string resulting from replacing all occurrences of oldChar in this string with newChar.
         */
        public String replace(char oldChar, char newChar) {
            return s.Replace(oldChar, newChar);
        }

        /**
         * Tests if this string starts with the specified prefix.
         */
        public bool startsWith(String prefix) {
            return s.StartsWith(prefix.s);
        }

        /**
         * Tests if this string ends with the specified suffix.
         */
        public bool endsWith(String suffix) {
            return s.EndsWith(suffix.s);
        }

        /**
         * Returns true if, and only if, length() is 0.
         */
        public bool isEmpty() {
            return s.Length == 0;
        }

        public override string ToString() {
            return s;
        }

        public static implicit operator String(string original) {
            return new String(original);
        }

        public static String operator +(String s1, String s2) {
            return s1.s + s2.s;
        }
    }
}
