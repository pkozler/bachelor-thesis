using System;

namespace JavaClasses {

    /**
     * The string tokenizer class allows an application to break a string into tokens.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class StringTokenizer {
        private string[] tokens;
        private int tokenCounter = 0;

        private void initialize(string str, string delim = " \t\n\r\f") {
            // splitting the string to the array by the specified set of delimiters
            tokens = str.Split(delim.ToCharArray(), StringSplitOptions.None);
        }

        /**
         * Constructs a string tokenizer for the specified string.
         */
        public StringTokenizer(String str) {
            initialize(str.ToString());
        }

        /**
         * Constructs a string tokenizer for the specified string.
         */
        public StringTokenizer(String str, String delim) {
            initialize(str.ToString(), delim.ToString());
        }

        /**
         * Calculates the number of times that this tokenizer's nextToken method can be called before it generates an exception.
         */
        public int countTokens() {
            return tokens.Length - tokenCounter;
        }

        /**
         * Tests if there are more tokens available from this tokenizer's string.
         */
        public bool hasMoreTokens() {
            return countTokens() > 0;
        }

        /**
         * Returns the next token from this string tokenizer.
         */
        public String nextToken() {
            return tokens[tokenCounter++];
        }
    }
}
