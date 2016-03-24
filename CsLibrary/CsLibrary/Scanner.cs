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
             from the standard input if the current line was completely scanned.
         */
        private string nextElement()
        {
            // removing leading whitespaces from the current token
            line.TrimStart();

            // reading the next line if the current is empty
            if (string.IsNullOrEmpty(line))
            {
                line = Console.ReadLine();
            }

            // removing the next token (delimited by whitespaces) from the current line
            Match match = Regex.Match(line, @"(?<=\s)");
            string token = line.Remove(0, match.Index + match.Length);

            return token;
        }

        /// <summary>
        /// Finds and returns the next complete token from this scanner.
        /// </summary>
        /// <returns>the next token
        /// </returns>
        public String next()
        {
            return nextElement();
        }

        /// <summary>
        /// Scans the next token of the input into a boolean value and returns that
        /// value.
        /// </summary>
        /// <returns>the boolean scanned from the input
        /// </returns>
        public bool nextBoolean()
        {
            return bool.Parse(nextElement());
        }

        /// <summary>
        /// Scans the next token of the input as a byte.
        /// </summary>
        /// <returns>the byte scanned from the input
        /// </returns>
        public sbyte nextByte()
        {
            return sbyte.Parse(nextElement());
        }

        /// <summary>
        /// Scans the next token of the input as a short.
        /// </summary>
        /// <returns>the short scanned from the input
        /// </returns>
        public short nextShort()
        {
            return short.Parse(nextElement());
        }

        /// <summary>
        /// Scans the next token of the input as an int.
        /// </summary>
        /// <returns>the int scanned from the input
        /// </returns>
        public int nextInt()
        {
            return int.Parse(nextElement());
        }

        /// <summary>
        /// Scans the next token of the input as a long.
        /// </summary>
        /// <returns>the long scanned from the input
        /// </returns>
        public long nextLong()
        {
            return long.Parse(nextElement());
        }

        /// <summary>
        /// Scans the next token of the input as a float.
        /// </summary>
        /// <returns>the float scanned from the input
        /// </returns>
        public float nextFloat()
        {
            return float.Parse(nextElement());
        }

        /// <summary>
        /// Scans the next token of the input as a double.
        /// </summary>
        /// <returns>the double scanned from the input
        /// </returns>
        public double nextDouble()
        {
            return double.Parse(nextElement());
        }

        /// <summary>
        /// Advances this scanner past the current line and returns the input that was skipped.
        /// </summary>
        /// <returns>the line that was skipped
        /// </returns>
        public String nextLine()
        {
            // reading the next line if the current is empty and returning it
            if (string.IsNullOrEmpty(line))
            {
                return Console.ReadLine();
            } // reading the rest of the current line if it is not empty
            else
            {
                String str = line;
                line = "";

                return str;
            }
        }

    }

}
