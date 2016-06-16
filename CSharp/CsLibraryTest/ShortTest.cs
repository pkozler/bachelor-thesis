using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{

    /// <summary>
    /// A Short class test suite.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
	[TestClass]
	public class ShortTest
	{

        /// <summary>
        /// Tests the shortValue method.
        /// </summary>
        [TestMethod]
		public void shortValueTest()
        {
            Short a;
            short b;
            a = new Short(Short.MIN_VALUE);
            b = a.shortValue();
            Assert.AreEqual(-32768, b);
            a = new Short((short)0);
            b = a.shortValue();
            Assert.AreEqual(0, b);
            a = new Short(Short.MAX_VALUE);
            b = a.shortValue();
            Assert.AreEqual(32767, b);
        }

        /// <summary>
        /// Tests the compareTo method.
        /// </summary>
        [TestMethod]
		public void compareToTest()
        {
            Short a, b;
            int c;
            a = new Short(Short.MIN_VALUE);
            b = new Short((short)-1);
            c = a.compareTo(b);
            Assert.AreEqual(-32767, c);
            a = new Short(Short.MAX_VALUE);
            b = new Short((short)1);
            c = a.compareTo(b);
            Assert.AreEqual(32766, c);
            a = new Short((short)0);
            b = new Short((short)1);
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            a = new Short((short)0);
            b = new Short((short)-1);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            a = new Short((short)1);
            b = new Short((short)1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
            a = new Short((short)-1);
            b = new Short((short)-1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the compare method.
        /// </summary>
        [TestMethod]
		public void compareTest()
        {
            short a, b;
            int c;
            a = Short.MIN_VALUE;
            b = (short)-1;
            c = Short.compare(a, b);
            Assert.AreEqual(-32767, c);
            a = Short.MAX_VALUE;
            b = (short)1;
            c = Short.compare(a, b);
            Assert.AreEqual(32766, c);
            a = (short)0;
            b = (short)1;
            c = Short.compare(a, b);
            Assert.AreEqual(-1, c);
            a = (short)0;
            b = (short)-1;
            c = Short.compare(a, b);
            Assert.AreEqual(1, c);
            a = (short)1;
            b = (short)1;
            c = Short.compare(a, b);
            Assert.AreEqual(0, c);
            a = (short)-1;
            b = (short)-1;
            c = Short.compare(a, b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the equals method.
        /// </summary>
        [TestMethod]
		public void equalsTest()
        {
            Short a, b;
            bool c;
            a = new Short(Short.MIN_VALUE);
            b = new Short((short)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Short(Short.MAX_VALUE);
            b = new Short((short)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Short((short)0);
            b = new Short((short)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Short((short)0);
            b = new Short((short)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Short((short)1);
            b = new Short((short)1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
            a = new Short((short)-1);
            b = new Short((short)-1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest()
        {
            Short a;
            String b;
            a = new Short((short)1000);
            b = a.toString();
            Assert.AreEqual("1000", b);
            a = new Short((short)0);
            b = a.toString();
            Assert.AreEqual("0", b);
            a = new Short((short)-1000);
            b = a.toString();
            Assert.AreEqual("-1000", b);
        }

        /// <summary>
        /// Tests the static toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest2()
        {
            short a;
            String b;
            a = (short)1000;
            b = Short.toString(a);
            Assert.AreEqual("1000", b);
            a = (short)0;
            b = Short.toString(a);
            Assert.AreEqual("0", b);
            a = (short)-1000;
            b = Short.toString(a);
            Assert.AreEqual("-1000", b);
        }

        /// <summary>
        /// Tests the parseShort method.
        /// </summary>
        [TestMethod]
		public void parseShortTest()
        {
            short a;
            a = Short.parseShort("1000");
            Assert.AreEqual(1000, a);
            a = Short.parseShort("0");
            Assert.AreEqual(0, a);
            a = Short.parseShort("-1000");
            Assert.AreEqual(-1000, a);
        }

    }
}

