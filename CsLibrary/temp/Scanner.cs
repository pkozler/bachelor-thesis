using System;
using System.Text.RegularExpressions;

namespace JavaClasses {

    /**
     * A simple text scanner which can parse primitive types and strings using regular expressions.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Scanner {
        // current line
        private string line = "";
        
        /**
         * Constructs a new Scanner that produces values scanned from the specified input stream.
         */
        public Scanner(Object source) {
            // really no code
        }

        /*
            Serves as the convenience method for creating the new scanner
            without unnecessary imitation of specifying the Java input stream.
        */
        public Scanner() {
            // really no code
        }

        /*
            Returns the next token of the current line or reads the new line
            from the standard input if the current line was completely scanned.
        */
        private string nextElement() {
            // reading the next line if the current is empty
            if (string.IsNullOrEmpty(line)) {
                line = Console.ReadLine().TrimStart();
            }
            
            // removes the next token (delimited by whitespaces) from the current line
            Match match = Regex.Match(line, @"(?<=\s)");
            string token = line.Remove(0, match.Index + match.Length).TrimEnd();

            return token;
        }

        /**
         * Finds and returns the next complete token from this scanner.
         */
        public String next() {
            return nextElement();
        }

        /**
         * Scans the next token of the input into a boolean value and returns that value.
         */
        public bool nextBoolean() {
            return bool.Parse(nextElement());
        }

        /**
         * Scans the next token of the input as a byte.
         */
        public sbyte nextByte() {
            return sbyte.Parse(nextElement());
        }

        /**
         * Scans the next token of the input as a short.
         */
        public short nextShort() {
            return short.Parse(nextElement());
        }

        /**
         * Scans the next token of the input as an int.
         */
        public int nextInt() {
            return int.Parse(nextElement());
        }

        /**
         * Scans the next token of the input as a long.
         */
        public long nextLong() {
            return long.Parse(nextElement());
        }

        /**
         * Scans the next token of the input as a float.
         */
        public float nextFloat() {
            return float.Parse(nextElement());
        }

        /**
         * Scans the next token of the input as a double.
         */
        public double nextDouble() {
            return double.Parse(nextElement());
        }

        /**
         * Advances this scanner past the current line and returns the input that was skipped.
         */
        public String nextLine() {
            // reading the next line if the current is empty and returning it
            if (string.IsNullOrEmpty(line)) {
                return Console.ReadLine();
            }
            // reading the rest of the current line if it is not empty
            else {
                String str = line;
                line = "";

                return str;
            }
        }
    }
}
