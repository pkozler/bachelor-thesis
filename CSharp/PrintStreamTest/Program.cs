using System;

namespace JavaClasses
{
    class Program
    {
        private delegate void TestMethod();

        private static SystemTest testClass = new SystemTest();
        
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

        private static void usage()
        {
            Console.WriteLine("Zadejte platné číslo testovací metody. ({0} - {1})", 1, testMethods.Length - 1);
            Environment.Exit(1);
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
        }
    }
}
