using System;

namespace JavaClasses
{
    class Program
    {
        private delegate void TestMethod();

        private static ScannerTest testClass = new ScannerTest();

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
            testClass.nextDoubleTest
        };

        private static void usage()
        {
            Console.WriteLine("Enter the valid test method number.");
            Environment.Exit(-1);
        }

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
