using System;
using System.Text.RegularExpressions;

namespace JavaClasses {

    /**
     * A simple text scanner which can parse primitive types and strings using regular expressions.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Scanner {
        private string line = "";
        private string[] tokens = new string[0];
        private int counter = 0;

        /**
         * Constructs a new Scanner that produces values scanned from the specified input stream.
         */
        public Scanner(Object source) {
        }

        public Scanner() {
        }

        private string nextElement() {
            if (string.IsNullOrEmpty(line)) {
                line = Console.ReadLine();
                tokens = Regex.Split(line, @"(?<=\s)");
                counter = 0;
            }

            line.Remove(0, tokens[counter].Length);
            return tokens[counter++];
        }

        /**
         * Finds and returns the next complete token from this scanner.
         */
        public String next() {
            return nextElement().Trim();
        }

        /**
         * Scans the next token of the input into a boolean value and returns that value.
         */
        public bool nextBoolean() {
            return bool.Parse(nextElement().Trim());
        }

        /**
         * Scans the next token of the input as a byte.
         */
        public sbyte nextByte() {
            return sbyte.Parse(nextElement().Trim());
        }

        /**
         * Scans the next token of the input as a short.
         */
        public short nextShort() {
            return short.Parse(nextElement().Trim());
        }

        /**
         * Scans the next token of the input as an int.
         */
        public int nextInt() {
            return int.Parse(nextElement().Trim());
        }

        /**
         * Scans the next token of the input as a long.
         */
        public long nextLong() {
            return long.Parse(nextElement().Trim());
        }

        /**
         * Scans the next token of the input as a float.
         */
        public float nextFloat() {
            return float.Parse(nextElement().Trim());
        }

        /**
         * Scans the next token of the input as a double.
         */
        public double nextDouble() {
            return double.Parse(nextElement().Trim());
        }

        /**
         * Advances this scanner past the current line and returns the input that was skipped.
         */
        public String nextLine() {
            String s;

            if (string.IsNullOrEmpty(line)) {
                s = Console.ReadLine();
            }
            else {
                s = line;
                line = "";
            }

            tokens = new string[0];
            counter = 0;

            return s;
        }
    }
}
