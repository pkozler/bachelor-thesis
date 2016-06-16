using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{

    /// <summary>
    /// A Byte class test suite.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
	[TestClass]
	public class ByteTest
	{

        /// <summary>
        /// Tests the byteValue method.
        /// </summary>
        [TestMethod]
		public void byteValueTest()
        {
            Byte a;
            sbyte b;
            // minimal value
            a = new Byte(Byte.MIN_VALUE);
            b = a.byteValue();
            Assert.AreEqual(-128, b);
            // zero value
            a = new Byte((sbyte)0);
            b = a.byteValue();
            Assert.AreEqual(0, b);
            // maximal value
            a = new Byte(Byte.MAX_VALUE);
            b = a.byteValue();
            Assert.AreEqual(127, b);
        }

        /// <summary>
        /// Tests the compareTo method.
        /// </summary>
        [TestMethod]
		public void compareToTest()
        {
            Byte a, b;
            int c;
            // minimal and bigger negative value
            a = new Byte(Byte.MIN_VALUE);
            b = new Byte((sbyte)-1);
            c = a.compareTo(b);
            Assert.AreEqual(-127, c);
            // maximal and smaller positive value
            a = new Byte(Byte.MAX_VALUE);
            b = new Byte((sbyte)1);
            c = a.compareTo(b);
            Assert.AreEqual(126, c);
            // zero and positive value
            a = new Byte((sbyte)0);
            b = new Byte((sbyte)1);
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            // zero and negative value
            a = new Byte((sbyte)0);
            b = new Byte((sbyte)-1);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            // both values are positive
            a = new Byte((sbyte)1);
            b = new Byte((sbyte)1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
            // both values are negative
            a = new Byte((sbyte)-1);
            b = new Byte((sbyte)-1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the compare method.
        /// </summary>
        [TestMethod]
		public void compareTest()
        {
            sbyte a, b;
            int c;
            a = Byte.MIN_VALUE;
            b = (sbyte)-1;
            c = Byte.compare(a, b);
            Assert.AreEqual(-127, c);
            a = Byte.MAX_VALUE;
            b = (sbyte)1;
            c = Byte.compare(a, b);
            Assert.AreEqual(126, c);
            a = (sbyte)0;
            b = (sbyte)1;
            c = Byte.compare(a, b);
            Assert.AreEqual(-1, c);
            a = (sbyte)0;
            b = (sbyte)-1;
            c = Byte.compare(a, b);
            Assert.AreEqual(1, c);
            a = (sbyte)1;
            b = (sbyte)1;
            c = Byte.compare(a, b);
            Assert.AreEqual(0, c);
            a = (sbyte)-1;
            b = (sbyte)-1;
            c = Byte.compare(a, b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the equals method.
        /// </summary>
        [TestMethod]
		public void equalsTest()
        {
            Byte a, b;
            bool c;
            a = new Byte(Byte.MIN_VALUE);
            b = new Byte((sbyte)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Byte(Byte.MAX_VALUE);
            b = new Byte((sbyte)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Byte((sbyte)0);
            b = new Byte((sbyte)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Byte((sbyte)0);
            b = new Byte((sbyte)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Byte((sbyte)1);
            b = new Byte((sbyte)1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
            a = new Byte((sbyte)-1);
            b = new Byte((sbyte)-1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest()
        {
            Byte a;
            String b;
            // positive value text representation
            a = new Byte((sbyte)100);
            b = a.toString();
            Assert.AreEqual("100", b);
            // zero value text representation
            a = new Byte((sbyte)0);
            b = a.toString();
            Assert.AreEqual("0", b);
            // negative value text representation
            a = new Byte((sbyte)-100);
            b = a.toString();
            Assert.AreEqual("-100", b);
        }

        /// <summary>
        /// Tests the static toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest2()
        {
            sbyte a;
            String b;
            a = (sbyte)100;
            b = Byte.toString(a);
            Assert.AreEqual("100", b);
            a = (sbyte)0;
            b = Byte.toString(a);
            Assert.AreEqual("0", b);
            a = (sbyte)-100;
            b = Byte.toString(a);
            Assert.AreEqual("-100", b);
        }

        /// <summary>
        /// Tests the parseByte method.
        /// </summary>
        [TestMethod]
		public void parseByteTest()
        {
            sbyte a;
            // positive value parsing
            a = Byte.parseByte("100");
            Assert.AreEqual(100, a);
            // zero value parsing
            a = Byte.parseByte("0");
            Assert.AreEqual(0, a);
            // negative value parsing
            a = Byte.parseByte("-100");
            Assert.AreEqual(-100, a);
        }

    }
}

