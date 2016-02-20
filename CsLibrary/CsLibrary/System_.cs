using System;

namespace JavaClasses {

    /**
     * The System class contains several useful class fields and methods.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class PrintStream {

        /**
         * Prints a boolean value.
         */
        public void print(bool b) {
            Console.Write(b);
        }

        /**
         * Prints a character.
         */
        public void print(char c) {
            Console.Write(c);
        }

        /**
         * Prints an array of characters.
         */
        public void print(char[] s) {
            Console.Write(s);
        }

        /**
         * Prints a double-precision floating-point number.
         */
        public void print(double d) {
            Console.Write(d);
        }

        /**
         * Prints a floating-point number.
         */
        public void print(float f) {
            Console.Write(f);
        }

        /**
         * Prints an integer.
         */
        public void print(int i) {
            Console.Write(i);
        }

        /**
         * Prints a long integer.
         */
        public void print(long l) {
            Console.Write(l);
        }

        /**
         * Prints an object.
         */
        public void print(Object obj) {
            Console.Write(obj);
        }

        /**
         * Prints a string.
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
         */
        public void println(bool b) {
            Console.WriteLine(b);
        }

        /**
         * Prints a character and then terminate the line.
         */
        public void println(char c) {
            Console.WriteLine(c);
        }

        /**
         * Prints an array of characters and then terminate the line.
         */
        public void println(char[] s) {
            Console.WriteLine(s);
        }

        /**
         * Prints a double and then terminate the line.
         */
        public void println(double d) {
            Console.WriteLine(d);
        }

        /**
         * Prints a float and then terminate the line.
         */
        public void println(float f) {
            Console.WriteLine(f);
        }

        /**
         * Prints an integer and then terminate the line.
         */
        public void println(int i) {
            Console.WriteLine(i);
        }

        /**
         * Prints a long and then terminate the line.
         */
        public void println(long l) {
            Console.WriteLine(l);
        }

        /**
         * Prints an Object and then terminate the line.
         */
        public void println(Object obj) {
            Console.WriteLine(obj);
        }

        /**
         * Prints a String and then terminate the line.
         */
        public void println(String s) {
            Console.WriteLine(s);
        }
    }

    /**
     * A PrintStream adds functionality to another output stream,
     * namely the ability to print representations of various data values conveniently.
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
