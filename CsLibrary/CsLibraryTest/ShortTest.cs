using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class ShortTest
	{
        /**
         * Tests the shortValue method.
         */
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

        /**
         * Tests the compareTo method.
         */
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

        /**
         * Tests the compare method.
         */
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

        /**
         * Tests the equals method.
         */
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

        /**
         * Tests the toString method.
         */
        [TestMethod]
		public void toStringTest()
        {
            Short a;
            String b;
            a = new Short((short)1000);
            b = a.toString();
            Assert.AreEqual(1000, b);
            a = new Short((short)0);
            b = a.toString();
            Assert.AreEqual(0, b);
            a = new Short((short)-1000);
            b = a.toString();
            Assert.AreEqual(-1000, b);
        }

        /**
         * Tests the static toString method.
         */
        [TestMethod]
		public void toStringTest2()
        {
            Short a;
            String b;
            a = new Short((short)1000);
            b = Short.toString(a);
            Assert.AreEqual(1000, b);
            a = new Short((short)0);
            b = Short.toString(a);
            Assert.AreEqual(0, b);
            a = new Short((short)-1000);
            b = Short.toString(a);
            Assert.AreEqual(-1000, b);
        }

        /**
         * Tests the parseShort method.
         */
        [TestMethod]
		public void parseShortTest()
        {
            Short a;
            short b;
            a = Short.parseShort("1000");
            b = a.shortValue();
            Assert.AreEqual(1000, b);
            a = Short.parseShort("0");
            b = a.shortValue();
            Assert.AreEqual(0, b);
            a = Short.parseShort("-1000");
            b = a.shortValue();
            Assert.AreEqual(-1000, b);
        }
    }
}

