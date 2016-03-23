using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class BooleanTest
	{
        /**
         * Tests the booleanValue method.
         */
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

        /**
         * Tests the compareTo method.
         */
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

        /**
         * Tests the compare method.
         */
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

        /**
         * Tests the equals method.
         */
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

        /**
         * Tests the toString method.
         */
        [TestMethod]
		public void toStringTest()
        {
            Boolean a;
            String b;
            // true value text representation
            a = new Boolean(true);
            b = a.toString();
            Assert.AreEqual(true, b);
            // false value text representation
            a = new Boolean(false);
            b = a.toString();
            Assert.AreEqual(false, b);
        }

        /**
         * Tests the static toString method.
         */
        [TestMethod]
		public void toStringTest2()
        {
            Boolean a;
            String b;
            a = new Boolean(true);
            b = Boolean.toString(a);
            Assert.AreEqual(true, b);
            a = new Boolean(false);
            b = Boolean.toString(a);
            Assert.AreEqual(false, b);
        }

        /**
         * Tests the parseBoolean method.
         */
        [TestMethod]
		public void parseBooleanTest()
        {
            Boolean a;
            bool b;
            // true value parsing
            a = Boolean.parseBoolean("true");
            b = a.booleanValue();
            Assert.AreEqual(true, b);
            // false value parsing
            a = Boolean.parseBoolean("false");
            b = a.booleanValue();
            Assert.AreEqual(false, b);
        }
    }
}

