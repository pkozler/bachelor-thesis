using System;

namespace JavaClasses
{
    /// <summary>
    /// A PrintStream class test utility.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    class Program
    {
        // a test method delegate
        private delegate void TestMethod();
        // a test class
        private static ScannerTest testClass = new ScannerTest();
        // an array of the test method delegates
        private static TestMethod[] testMethods = new TestMethod[]
        {
            testClass.scannerTest,
            testClass.nextTest,
            testClass.nextBooleanTest,
            testClass.nextByteTest,
            testClass.nextShortTest,
            testClass.nextIntTest,
            testClass.nextLongTest,
            testClass.nextFloatTest,
            testClass.nextDoubleTest,
            testClass.nextLineTest
        };

        /*
            Prints help message if the specified method index is not valid.
        */
        private static void usage()
        {
            Console.WriteLine("Zadejte platné číslo testovací metody. ({0} - {1})", 0, testMethods.Length - 1);
            Environment.Exit(-1);
        }

        /// <summary>
        /// Invokes the PrintStream test method with the index specified in the command-line argument
        /// and returns the count of errors found during the test as the exit status.
        /// </summary>
        /// <param name="args">command-line arguments</param>
        static void Main(string[] args)
        {
            int n;

            if (args.Length < 1)
            {
                usage();
            }

            if (!int.TryParse(args[0], out n))
            {
                usage();
            }

            testMethods[n]();

            Environment.Exit(testClass.errorsInMethod);
        }
    }
}
