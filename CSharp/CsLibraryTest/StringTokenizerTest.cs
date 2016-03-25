using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
    [TestClass]
    public class StringTokenizerTest
    {
        /*
         Creates the string representation of the array of tokens which are created
         from tokenized string.
         */
        private static String[] getStringArray(StringTokenizer a)
        {
            String[] b;
            int c;
            c = a.countTokens();
            b = new String[c];

            for (int i = 0; i < c; i++)
            {
                b[i] = a.nextToken();
            }

            return b;
        }

        /**
         * Tests the constructor.
         */
        [TestMethod]
        public void stringTokenizerTest()
        {
            StringTokenizer a;
            String[] b;
            // whitespaces inside the string
            a = new StringTokenizer("This is a test.");
            b = getStringArray(a);
            Assert.AreEqual(new String[] {"This", "is", "a", "test."}, b);
            // whitespaces inside and outside the string
            a = new StringTokenizer(" This is   a test. ");
            b = getStringArray(a);
            Assert.AreEqual(new String[] {"This", "is", "a", "test."}, b);
            // without whitespaces
            a = new StringTokenizer("This_is_a_test.");
            b = getStringArray(a);
            Assert.AreEqual(new String[] {"This_is_a_test."}, b);
            // one character
            a = new StringTokenizer("_");
            b = getStringArray(a);
            Assert.AreEqual(new String[] {"_"}, b);
            // empty string
            a = new StringTokenizer("");
            b = getStringArray(a);
            Assert.AreEqual(new String[] {}, b);
        }

        /**
         * Tests the constructor with a set of delimiters as a parameter.
         */
        [TestMethod]
        public void stringTokenizerTest2()
        {
            StringTokenizer a;
            String[] b;
            // non-white delimiter (non-existent in string)
            a = new StringTokenizer("This is a test.", "_");
            b = getStringArray(a);
            Assert.AreEqual(new String[] {"This is a test."}, b);
            // non-white delimiter (inside the string)
            a = new StringTokenizer("This_is_a_test.", "_");
            b = getStringArray(a);
            Assert.AreEqual(new String[] {"This", "is", "a", "test."}, b);
            // non-white delimiter (also the whitespaces inside the string)
            a = new StringTokenizer("This_is_ a _test.", "_");
            b = getStringArray(a);
            Assert.AreEqual(new String[] {"This", "is", " a ", "test."}, b);
            // non-white delimiter (also the whitespaces inside and outside the string)
            a = new StringTokenizer("_This_is___a_test._", "_");
            b = getStringArray(a);
            Assert.AreEqual(new String[] {"This", "is", "a", "test."}, b);
            // more delimiters (existing in the string)
            a = new StringTokenizer("This is_a test.", " _");
            b = getStringArray(a);
            Assert.AreEqual(new String[] {"This", "is", "a", "test."}, b);
            // more delimiters (non-existent in the string)
            a = new StringTokenizer("Thisisatest.", " _");
            b = getStringArray(a);
            Assert.AreEqual(new String[] {"Thisisatest."}, b);
        }

        /**
         * Tests the countTokens method.
         */
        [TestMethod]
        public void countTokensTest()
        {
            StringTokenizer a;
            int b;
            // tokenize with whitespaces as delimiters
            a = new StringTokenizer("This is a test.");
            b = a.countTokens();
            Assert.AreEqual(4, b);
            // tokenize with whitespaces as delimiters (more whitespaces)
            a = new StringTokenizer(" This is   a test. ");
            b = a.countTokens();
            Assert.AreEqual(4, b);
            // tokenize with whitespaces as delimiters (no whitespaces)
            a = new StringTokenizer("This_is_a_test.");
            b = a.countTokens();
            Assert.AreEqual(1, b);
            // tokenize with non-white characters as delimiters
            a = new StringTokenizer("This_is_a_test.", "_");
            b = a.countTokens();
            Assert.AreEqual(4, b);
            // tokenize an empty string
            a = new StringTokenizer("");
            b = a.countTokens();
            Assert.AreEqual(0, b);
        }

        /**
         * Tests the hasMoreTokens method.
         */
        [TestMethod]
        public void hasMoreTokensTest()
        {
            StringTokenizer a;
            bool b;
            a = new StringTokenizer("This is a test.");
            b = a.hasMoreTokens();
            Assert.AreEqual(true, b);
            a = new StringTokenizer(" This is   a test. ");
            b = a.hasMoreTokens();
            Assert.AreEqual(true, b);
            a = new StringTokenizer("This_is_a_test.");
            b = a.hasMoreTokens();
            Assert.AreEqual(true, b);
            a = new StringTokenizer("This_is_a_test.", "_");
            b = a.hasMoreTokens();
            Assert.AreEqual(true, b);
            a = new StringTokenizer("");
            b = a.hasMoreTokens();
            Assert.AreEqual(false, b);
        }

        /**
         * Tests the nextToken method.
         */
        [TestMethod]
        public void nextTokenTest()
        {
            StringTokenizer a;
            String b;
            // a test string
            a = new StringTokenizer("This is a test.");
            b = a.nextToken();
            Assert.AreEqual("This", b);
            b = a.nextToken();
            Assert.AreEqual("is", b);
            b = a.nextToken();
            Assert.AreEqual("a", b);
            b = a.nextToken();
            Assert.AreEqual("test.", b);
        }

    }

}

