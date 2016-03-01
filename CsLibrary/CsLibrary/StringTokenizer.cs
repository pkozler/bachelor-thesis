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

        /**
         * Constructs a string tokenizer for the specified string.
         */
        public StringTokenizer(String str) {
            tokens = str.ToString().Split(" \t\n\r\f".ToCharArray(), StringSplitOptions.None);
        }

        /**
         * Constructs a string tokenizer for the specified string.
         */
        public StringTokenizer(String str, String delim) {
            tokens = str.ToString().Split(delim.ToString().ToCharArray(), StringSplitOptions.None);
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
