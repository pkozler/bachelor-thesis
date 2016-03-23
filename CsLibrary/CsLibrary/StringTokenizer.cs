using System;

namespace JavaClasses
{

    /// <summary>
    /// The string tokenizer class allows an application to break a string into tokens.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class StringTokenizer
    {

        // current string array containing tokens
        private string[] tokens;
        // current position in the array
        private int tokenCounter = 0;

        /*
            Performs the string splitting.
         */
        private void initialize(string str, string delim = " \t\n\r\f")
        {
            // splitting the string to the array by the specified set of delimiters
            tokens = str.Split(delim.ToCharArray(), StringSplitOptions.None);
        }

        /// <summary>
        /// Constructs a string tokenizer for the specified string.
        /// </summary>
        /// <param name="str">a string to be parsed.
        /// </param>
        public StringTokenizer(String str)
        {
            initialize(str.ToString());
        }

        /// <summary>
        /// Constructs a string tokenizer for the specified string.
        /// </summary>
        /// <param name="str">a string to be parsed.
        /// </param><param name="delim">the delimiters.
        /// </param>
        public StringTokenizer(String str, String delim)
        {
            initialize(str.ToString(), delim.ToString());
        }

        /// <summary>
        /// Calculates the number of times that this tokenizer's nextToken method can
        /// be called before it generates an exception.
        /// </summary>
        /// <returns>the number of tokens remaining in the string using the current
        /// delimiter set.
        /// </returns>
        public int countTokens()
        {
            return tokens.Length - tokenCounter;
        }

        /// <summary>
        /// Tests if there are more tokens available from this tokenizer's string.
        /// </summary>
        /// <returns>true if and only if there is at least one token in the string
        /// after the current position; false otherwise.
        /// </returns>
        public bool hasMoreTokens()
        {
            return countTokens() > 0;
        }

        /// <summary>
        /// Returns the next token from this string tokenizer.
        /// </summary>
        /// <returns>the next token from this string tokenizer.
        /// </returns>
        public String nextToken()
        {
            return tokens[tokenCounter++];
        }

    }

}
