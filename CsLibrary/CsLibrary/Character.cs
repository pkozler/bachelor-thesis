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
         * Constructs a newly allocated Character object that represents the
         * specified char value.
         *
         * @param value the value to be represented by the Character object.
         */
        public Character(char value) {
            v = value;
        }

        /**
         * Returns the value of this Character object.
         *
         * @return the primitive char value represented by this object.
         */
        public char charValue() {
            return v;
        }

        /**
         * Compares two Character objects numerically.
         *
         * @param anotherCharacter the Character to be compared.
         * @return the value 0 if the argument Character is equal to this Character;
         * a value less than 0 if this Character is numerically less than the
         * Character argument; and a value greater than 0 if this Character is
         * numerically greater than the Character argument (unsigned comparison).
         * Note that this is strictly a numerical comparison; it is not
         * locale-dependent.
         */
        public int compareTo(Character anotherCharacter) {
            return compare(v, anotherCharacter.v);
        }

        /**
         * Compares two char values numerically.
         *
         * @param x the first char to compare
         * @param y the second char to compare
         * @return the value 0 if x == y; a value less than 0 if x < y; and a value greater than 0 if x
         * > y
         */
        public static int compare(char x, char y) {
            return x - y;
        }

        /**
         * Compares this object against the specified object.
         *
         * @param obj the object to compare with.
         * @return true if the objects are the same; false otherwise.
         */
        public bool equals(Object obj) {
            if (obj == null) {
                return false;
            }

            if (GetType() != obj.GetType()) {
                return false;
            }

            return v.Equals((obj as  Character).v);
        }

        /**
         * Returns a String object representing this Character's value.
         * 
         * @return a string representation of this object.
         */
        public String toString() {
            return Character.toString(v);
        }

        /**
         * Returns a String object representing the specified char.
         *
         * @param c the char to be converted
         * @return the string representation of the specified char
         */
        public static String toString(char c) {
            return c.ToString();
        }

        /**
         * Determines if the specified character is a digit.
         *
         * @param ch the character to be tested.
         * @return true if the character is a digit; false otherwise.
         */
        public static bool isDigit(char ch) {
            return char.IsDigit(ch);
        }

        /**
         * Determines if the specified character is a letter.
         * 
         * @param ch the character to be tested.
         * @return true if the character is a letter; false otherwise.
         */
        public static bool isLetter(char ch) {
            return char.IsLetter(ch);
        }

    }

}
