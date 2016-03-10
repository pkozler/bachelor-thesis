using System;

namespace JavaClasses {

    /**
     * The Character class wraps a value of the primitive type char in an object.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Character {
        private char v;

        /**
         * Constructs a newly allocated Character object that represents the specified char value.
         */
        public Character(char value) {
            v = value;
        }

        /**
         * Returns the value of this Character object.
         */
        public char charValue() {
            return v;
        }

        /**
         * Compares two Character objects numerically.
         */
        public int compareTo(Character anotherCharacter) {
            return compare(v, anotherCharacter.v);
        }

        /**
         * Compares two char values numerically.
         */
        public static int compare(char x, char y) {
            return x - y;
        }

        /**
         * Compares this object against the specified object.
         */
        public bool equals(Object obj) {
            if (obj == null) {
                return false;
            }

            if (GetType() != obj.GetType()) {
                return false;
            }

            return v.Equals((obj as Character).v);
        }

        public override string ToString() {
            return toString().ToString();
        }

        /**
         * Returns a String object representing this Character's value.
         */
        public String toString() {
            return Character.toString(v);
        }

        /**
         * Returns a String object representing the specified char.
         */
        public static String toString(char c) {
            return c.ToString();
        }

        /**
         * Determines if the specified character is a digit.
         */
        public static bool isDigit(char ch) {
            return char.IsDigit(ch);
        }

        /**
         * Determines if the specified character is a letter.
         */
        public static bool isLetter(char ch) {
            return char.IsLetter(ch);
        }
    }
}
