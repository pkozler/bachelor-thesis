using System;

namespace JavaClasses {

    /**
     * The string tokenizer class allows an application to break a string into tokens.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class StringTokenizer {

        // current string array containing tokens
        private string[] tokens;
        // current position in the array
        private int tokenCounter = 0;

        /*
            Performs the string splitting.
         */
        private void initialize(string str, string delim = " \t\n\r\f") {
            // splitting the string to the array by the specified set of delimiters
            tokens = str.Split(delim.ToCharArray(), StringSplitOptions.None);
        }

        /**
         * Constructs a string tokenizer for the specified string.
         *
         * @param str a string to be parsed.
         */
        public StringTokenizer(String str) {
            initialize(str.ToString());
        }

        /**
         * Constructs a string tokenizer for the specified string.
         *
         * @param str a string to be parsed.
         * @param delim the delimiters.
         */
        public StringTokenizer(String str, String delim) {
            initialize(str.ToString(), delim.ToString());
        }

        /**
         * Calculates the number of times that this tokenizer's nextToken method can
         * be called before it generates an exception.
         *
         * @return the number of tokens remaining in the string using the current
         * delimiter set.
         */
        public int countTokens() {
            return tokens.Length - tokenCounter;
        }

        /**
         * Tests if there are more tokens available from this tokenizer's string.
         *
         * @return true if and only if there is at least one token in the string
         * after the current position; false otherwise.
         */
        public bool hasMoreTokens() {
            return countTokens() > 0;
        }

        /**
         * Returns the next token from this string tokenizer.
         *
         * @return the next token from this string tokenizer.
         */
        public String nextToken() {
            return tokens[tokenCounter++];
        }

    }

}
