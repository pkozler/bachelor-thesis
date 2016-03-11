using System;

namespace JavaClasses {

    /**
     * A PrintStream adds functionality to another output stream,
     * namely the ability to print representations of various data values conveniently.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class PrintStream {

        /**
         * Prints a boolean value.
         *
         * @param b The boolean to be printed
         */
        public void print(bool b) {
            Console.Write(b);
        }

        /**
         * Prints a character.
         *
         * @param c The char to be printed
         */
        public void print(char c) {
            Console.Write(c);
        }

        /**
         * Prints an array of characters.
         *
         * @param s The array of chars to be printed
         */
        public void print(char[] s) {
            Console.Write(s);
        }

        /**
         * Prints a double-precision floating-point number.
         *
         * @param d The double to be printed
         */
        public void print(double d) {
            Console.Write(d);
        }

        /**
         * Prints a floating-point number.
         *
         * @param f The float to be printed
         */
        public void print(float f) {
            Console.Write(f);
        }

        /**
         * Prints an integer.
         *
         * @param i The int to be printed
         */
        public void print(int i) {
            Console.Write(i);
        }

        /**
         * Prints a long integer.
         *
         * @param l The long to be printed
         */
        public void print(long l) {
            Console.Write(l);
        }

        /**
         * Prints an object.
         *
         * @param obj The Object to be printed
         */
        public void print(Object obj) {
            Console.Write(obj);
        }

        /**
         * Prints a string.
         *
         * @param s The String to be printed
         */
        public void print(String s) {
            Console.Write(s);
        }

        /**
         * Terminates the current line by writing the line separator string.
         */
        public void println() {
            Console.WriteLine();
        }

        /**
         * Prints a boolean and then terminate the line.
         *
         * @param x The boolean to be printed
         */
        public void println(bool x) {
            Console.WriteLine(x);
        }

        /**
         * Prints a character and then terminate the line.
         *
         * @param x The char to be printed.
         */
        public void println(char x) {
            Console.WriteLine(x);
        }

        /**
         * Prints an array of characters and then terminate the line.
         *
         * @param x an array of chars to print.
         */
        public void println(char[] x) {
            Console.WriteLine(x);
        }

        /**
         * Prints a double and then terminate the line.
         *
         * @param x The double to be printed.
         */
        public void println(double x) {
            Console.WriteLine(x);
        }

        /**
         * Prints a float and then terminate the line.
         *
         * @param x The float to be printed.
         */
        public void println(float x) {
            Console.WriteLine(x);
        }

        /**
         * Prints an integer and then terminate the line.
         *
         * @param x The int to be printed.
         */
        public void println(int x) {
            Console.WriteLine(x);
        }

        /**
         * Prints a long and then terminate the line.
         *
         * @param x The long to be printed.
         */
        public void println(long x) {
            Console.WriteLine(x);
        }

        /**
         * Prints an Object and then terminate the line.
         *
         * @param x The Object to be printed.
         */
        public void println(Object x) {
            Console.WriteLine(x);
        }

        /**
         * Prints a String and then terminate the line.
         *
         * @param x The String to be printed.
         */
        public void println(String x) {
            Console.WriteLine(x);
        }

    }
    
    /**
     * The System class contains several useful class fields and methods.
     *
     * @author Petr Kozler (A13B0359P)
     */
    class System_ {

        /**
         * The "standard" input stream.
         */
        public readonly static Object in_ = null;

        /**
         * The "standard" output stream.
         */
        public readonly static PrintStream out_ = new PrintStream();

    }

}
