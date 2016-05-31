using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
    [TestClass]
    public class StringTokenizerTest
    {
        
        /*
         Creates the array of tokens which are created the from tokenized string.
        */
        private static String[] toStringArray(StringTokenizer a)
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

        /// <summary>
        /// Tests the constructor.
        /// </summary>
        [TestMethod]
        public void stringTokenizerTest()
        {
            StringTokenizer a;
            String[] b;
            bool c;
            // whitespaces inside the string
            a = new StringTokenizer("This is a test.");
            b = toStringArray(a);
            c = Arrays.equals(new String[] { "This", "is", "a", "test." }, b);
            Assert.AreEqual(true, c);
            // whitespaces inside and outside the string
            a = new StringTokenizer(" This is   a test. ");
            b = toStringArray(a);
            c = Arrays.equals(new String[] { "This", "is", "a", "test." }, b);
            Assert.AreEqual(true, c);
            // without whitespaces
            a = new StringTokenizer("This_is_a_test.");
            b = toStringArray(a);
            c = Arrays.equals(new String[] { "This_is_a_test." }, b);
            Assert.AreEqual(true, c);
            // one character
            a = new StringTokenizer("_");
            b = toStringArray(a);
            c = Arrays.equals(new String[] { "_" }, b);
            Assert.AreEqual(true, c);
            // empty string
            a = new StringTokenizer("");
            b = toStringArray(a);
            c = Arrays.equals(new String[] { }, b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the constructor with a set of delimiters as a parameter.
        /// </summary>
        [TestMethod]
        public void stringTokenizerTest2()
        {
            StringTokenizer a;
            String[] b;
            bool c;
            // non-white delimiter (non-existent in string)
            a = new StringTokenizer("This is a test.", "_");
            b = toStringArray(a);
            c = Arrays.equals(new String[] { "This is a test." }, b);
            Assert.AreEqual(true, c);
            // non-white delimiter (inside the string)
            a = new StringTokenizer("This_is_a_test.", "_");
            b = toStringArray(a);
            c = Arrays.equals(new String[] { "This", "is", "a", "test." }, b);
            Assert.AreEqual(true, c);
            // non-white delimiter (also the whitespaces inside the string)
            a = new StringTokenizer("This_is_ a _test.", "_");
            b = toStringArray(a);
            c = Arrays.equals(new String[] { "This", "is", " a ", "test." }, b);
            Assert.AreEqual(true, c);
            // non-white delimiter (also the whitespaces inside and outside the string)
            a = new StringTokenizer("_This_is___a_test._", "_");
            b = toStringArray(a);
            c = Arrays.equals(new String[] { "This", "is", "a", "test." }, b);
            Assert.AreEqual(true, c);
            // more delimiters (existing in the string)
            a = new StringTokenizer("This is_a test.", " _");
            b = toStringArray(a);
            c = Arrays.equals(new String[] { "This", "is", "a", "test." }, b);
            Assert.AreEqual(true, c);
            // more delimiters (non-existent in the string)
            a = new StringTokenizer("Thisisatest.", " _");
            b = toStringArray(a);
            c = Arrays.equals(new String[] { "Thisisatest." }, b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the countTokens method.
        /// </summary>
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

        /// <summary>
        /// Tests the hasMoreTokens method.
        /// </summary>
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

        /// <summary>
        /// Tests the nextToken method.
        /// </summary>
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

