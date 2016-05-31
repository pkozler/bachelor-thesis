using System;
using System.Threading;

namespace JavaClasses
{

    /// <summary>
    /// A PrintStream adds functionality to another output stream,
    /// namely the ability to print representations of various data values conveniently.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class PrintStream : Object
    {

        public PrintStream()
        {
            // setting the standard output format
            Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
        }

        /// <summary>
        /// Prints a boolean value.
        /// </summary>
        /// <param name="b">The boolean to be printed
        /// </param>
        public void print(bool b)
        {
            Console.Write(b);
        }

        /// <summary>
        /// Prints a character.
        /// </summary>
        /// <param name="c">The char to be printed
        /// </param>
        public void print(char c)
        {
            Console.Write(c);
        }

        /// <summary>
        /// Prints an array of characters.
        /// </summary>
        /// <param name="s">The array of chars to be printed
        /// </param>
        public void print(char[] s)
        {
            Console.Write(s);
        }

        /// <summary>
        /// Prints a double-precision floating-point number.
        /// </summary>
        /// <param name="d">The double to be printed
        /// </param>
        public void print(double d)
        {
            Console.Write(d);
        }

        /// <summary>
        /// Prints a floating-point number.
        /// </summary>
        /// <param name="f">The float to be printed
        /// </param>
        public void print(float f)
        {
            Console.Write(f);
        }

        /// <summary>
        /// Prints an integer.
        /// </summary>
        /// <param name="i">The int to be printed
        /// </param>
        public void print(int i)
        {
            Console.Write(i);
        }

        /// <summary>
        /// Prints a long integer.
        /// </summary>
        /// <param name="l">The long to be printed
        /// </param>
        public void print(long l)
        {
            Console.Write(l);
        }

        /// <summary>
        /// Prints an object.
        /// </summary>
        /// <param name="obj">The Object to be printed
        /// </param>
        public void print(Object obj)
        {
            Console.Write(obj);
        }

        /// <summary>
        /// Prints a string.
        /// </summary>
        /// <param name="s">The String to be printed
        /// </param>
        public void print(String s)
        {
            Console.Write(s);
        }

        /// <summary>
        /// Terminates the current line by writing the line separator string.
        public void println()
        {
            Console.WriteLine();
        }

        /// <summary>
        /// Prints a boolean and then terminate the line.
        /// </summary>
        /// <param name="x">The boolean to be printed
        /// </param>
        public void println(bool x)
        {
            Console.WriteLine(x);
        }

        /// <summary>
        /// Prints a character and then terminate the line.
        /// </summary>
        /// <param name="x">The char to be printed.
        /// </param>
        public void println(char x)
        {
            Console.WriteLine(x);
        }

        /// <summary>
        /// Prints an array of characters and then terminate the line.
        /// </summary>
        /// <param name="x">an array of chars to print.
        /// </param>
        public void println(char[] x)
        {
            Console.WriteLine(x);
        }

        /// <summary>
        /// Prints a double and then terminate the line.
        /// </summary>
        /// <param name="x">The double to be printed.
        /// </param>
        public void println(double x)
        {
            Console.WriteLine(x);
        }

        /// <summary>
        /// Prints a float and then terminate the line.
        /// </summary>
        /// <param name="x">The float to be printed.
        /// </param>
        public void println(float x)
        {
            Console.WriteLine(x);
        }

        /// <summary>
        /// Prints an integer and then terminate the line.
        /// </summary>
        /// <param name="x">The int to be printed.
        /// </param>
        public void println(int x)
        {
            Console.WriteLine(x);
        }

        /// <summary>
        /// Prints a long and then terminate the line.
        /// </summary>
        /// <param name="x">The long to be printed.
        /// </param>
        public void println(long x)
        {
            Console.WriteLine(x);
        }

        /// <summary>
        /// Prints an Object and then terminate the line.
        /// </summary>
        /// <param name="x">The Object to be printed.
        /// </param>
        public void println(Object x)
        {
            Console.WriteLine(x);
        }

        /// <summary>
        /// Prints a String and then terminate the line.
        /// </summary>
        /// <param name="x">The String to be printed.
        /// </param>
        public void println(String x)
        {
            Console.WriteLine(x);
        }

    }

    /// <summary>
    /// This abstract class is the superclass of all classes 
    /// representing an input stream of bytes.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class InputStream : Object
    {
        // really no code
    }

    /// <summary>
    /// The System class contains several useful class fields and methods.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class System_ : Object
    {

        /// <summary>
        /// The "standard" input stream.
        /// </summary>
        public readonly static InputStream in_ = new InputStream();

        /// <summary>
        /// The "standard" output stream.
        /// </summary>
        public readonly static PrintStream out_ = new PrintStream();

    }

}
