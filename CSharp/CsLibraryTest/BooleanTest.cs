using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{

    /// <summary>
    /// A Boolean class test suite.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
	[TestClass]
	public class BooleanTest
	{

        /// <summary>
        /// Tests the booleanValue method.
        /// </summary>
        [TestMethod]
		public void booleanValueTest()
        {
            Boolean a;
            bool b;
            // true value
            a = new Boolean(true);
            b = a.booleanValue();
            Assert.AreEqual(true, b);
            // false falue
            a = new Boolean(false);
            b = a.booleanValue();
            Assert.AreEqual(false, b);
        }

        /// <summary>
        /// Tests the compareTo method.
        /// </summary>
        [TestMethod]
		public void compareToTest()
        {
            Boolean a, b;
            int c;
            // true and false
            a = new Boolean(true);
            b = new Boolean(false);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            // false and true
            a = new Boolean(false);
            b = new Boolean(true);
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            // both values are true
            a = new Boolean(true);
            b = new Boolean(true);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
            // both values are false
            a = new Boolean(false);
            b = new Boolean(false);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the compare method.
        /// </summary>
        [TestMethod]
		public void compareTest()
        {
            bool a, b;
            int c;
            a = true;
            b = false;
            c = Boolean.compare(a, b);
            Assert.AreEqual(1, c);
            a = false;
            b = true;
            c = Boolean.compare(a, b);
            Assert.AreEqual(-1, c);
            a = true;
            b = true;
            c = Boolean.compare(a, b);
            Assert.AreEqual(0, c);
            a = false;
            b = false;
            c = Boolean.compare(a, b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the equals method.
        /// </summary>
        [TestMethod]
		public void equalsTest()
        {
            Boolean a, b;
            bool c;
            a = new Boolean(true);
            b = new Boolean(false);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Boolean(false);
            b = new Boolean(true);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Boolean(true);
            b = new Boolean(true);
            c = a.equals(b);
            Assert.AreEqual(true, c);
            a = new Boolean(false);
            b = new Boolean(false);
            c = a.equals(b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest()
        {
            Boolean a;
            String b;
            // true value text representation
            a = new Boolean(true);
            b = a.toString();
            Assert.AreEqual("true", b);
            // false value text representation
            a = new Boolean(false);
            b = a.toString();
            Assert.AreEqual("false", b);
        }

        /// <summary>
        /// Tests the static toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest2()
        {
            bool a;
            String b;
            a = true;
            b = Boolean.toString(a);
            Assert.AreEqual("true", b);
            a = false;
            b = Boolean.toString(a);
            Assert.AreEqual("false", b);
        }

        /// <summary>
        /// Tests the parseBoolean method.
        /// </summary>
        [TestMethod]
		public void parseBooleanTest()
        {
            bool a;
            // true value parsing
            a = Boolean.parseBoolean("true");
            Assert.AreEqual(true, a);
            // false value parsing
            a = Boolean.parseBoolean("false");
            Assert.AreEqual(false, a);
        }

    }
}

