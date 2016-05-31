using System;
using System.Text.RegularExpressions;
using System.Threading;

namespace JavaClasses
{

    /// <summary>
    /// A simple text scanner which can parse primitive types and strings using regular expressions.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class Scanner : Object
    {

        // current line
        private string line = "";

        /// <summary>
        /// Constructs a new Scanner that produces values scanned from the specified
        /// input stream.
        /// </summary>
        /// <param name="source">An input stream to be scanned</param>
        public Scanner(InputStream source)
        {
            Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
        }

        /*
             Returns the next token of the current line or reads the new line
             from the standard input if the current line has been scanned completely.
         */
        private String getNextToken()
        {
            // reading the next line if the current is empty
            while (string.IsNullOrWhiteSpace(line))
            {
                // removing all leading whitespaces
                line = Console.ReadLine().TrimStart();
            }
            
            // getting the next token (all characters to the first whitespace) from the current line
            Match match = Regex.Match(line, @"([^\s]+)");
            // removing the token from the current line
            line = line.Remove(0, match.Index + match.Length);

            return match.Value;
        }

        /// <summary>
        /// Finds and returns the next complete token from this scanner.
        /// </summary>
        /// <returns>the next token
        /// </returns>
        public String next()
        {
            return getNextToken();
        }

        /// <summary>
        /// Scans the next token of the input into a boolean value and returns that
        /// value.
        /// </summary>
        /// <returns>the boolean scanned from the input
        /// </returns>
        public bool nextBoolean()
        {
            return Boolean.parseBoolean(getNextToken());
        }

        /// <summary>
        /// Scans the next token of the input as a byte.
        /// </summary>
        /// <returns>the byte scanned from the input
        /// </returns>
        public sbyte nextByte()
        {
            return Byte.parseByte(getNextToken());
        }

        /// <summary>
        /// Scans the next token of the input as a short.
        /// </summary>
        /// <returns>the short scanned from the input
        /// </returns>
        public short nextShort()
        {
            return Short.parseShort(getNextToken());
        }

        /// <summary>
        /// Scans the next token of the input as an int.
        /// </summary>
        /// <returns>the int scanned from the input
        /// </returns>
        public int nextInt()
        {
            return Integer.parseInt(getNextToken());
        }

        /// <summary>
        /// Scans the next token of the input as a long.
        /// </summary>
        /// <returns>the long scanned from the input
        /// </returns>
        public long nextLong()
        {
            return Long.parseLong(getNextToken());
        }

        /// <summary>
        /// Scans the next token of the input as a float.
        /// </summary>
        /// <returns>the float scanned from the input
        /// </returns>
        public float nextFloat()
        {
            return Float.parseFloat(getNextToken());
        }

        /// <summary>
        /// Scans the next token of the input as a double.
        /// </summary>
        /// <returns>the double scanned from the input
        /// </returns>
        public double nextDouble()
        {
            return Double.parseDouble(getNextToken());
        }

        /// <summary>
        /// Advances this scanner past the current line and returns the input that was skipped.
        /// </summary>
        /// <returns>the line that was skipped
        /// </returns>
        public String nextLine()
        {
            // reading the next line if the current is empty
            if (string.IsNullOrEmpty(line))
            {
                return Console.ReadLine();
            }

            // returning the rest of the current line if not empty
            String str = line;
            line = "";

            return str;
        }

    }

}
