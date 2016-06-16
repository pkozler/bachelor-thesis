using System;

namespace JavaClasses
{
    /// <summary>
    /// A Scanner class test utility.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    class Program
    {
        // a test method delegate
        private delegate void TestMethod();
        // a test class
        private static PrintStreamTest testClass = new PrintStreamTest();
        // an array of the test method delegates
        private static TestMethod[] testMethods = new TestMethod[]
        {
            testClass.printTest,
            testClass.printTest2,
            testClass.printTest3,
            testClass.printTest4,
            testClass.printTest5,
            testClass.printTest6,
            testClass.printTest7,
            testClass.printTest8,
            testClass.printTest9,
            testClass.printlnTest,
            testClass.printlnTest2,
            testClass.printlnTest3,
            testClass.printlnTest4,
            testClass.printlnTest5,
            testClass.printlnTest6,
            testClass.printlnTest7,
            testClass.printlnTest8,
            testClass.printlnTest9,
            testClass.printlnTest10
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
        }
    }
}
