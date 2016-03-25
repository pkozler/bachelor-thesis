using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class IntegerTest
	{
        /**
         * Tests the intValue method.
         */
        [TestMethod]
		public void intValueTest()
        {
            Integer a;
            int b;
            a = new Integer(Integer.MIN_VALUE);
            b = a.intValue();
            Assert.AreEqual(-2147483648, b);
            a = new Integer((int)0);
            b = a.intValue();
            Assert.AreEqual(0, b);
            a = new Integer(Integer.MAX_VALUE);
            b = a.intValue();
            Assert.AreEqual(2147483647, b);
        }

        /**
         * Tests the compareTo method.
         */
        [TestMethod]
		public void compareToTest()
        {
            Integer a, b;
            int c;
            a = new Integer(Integer.MIN_VALUE);
            b = new Integer((int)-1);
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            a = new Integer(Integer.MAX_VALUE);
            b = new Integer((int)1);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            a = new Integer((int)0);
            b = new Integer((int)1);
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            a = new Integer((int)0);
            b = new Integer((int)-1);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            a = new Integer((int)1);
            b = new Integer((int)1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
            a = new Integer((int)-1);
            b = new Integer((int)-1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
        }

        /**
         * Tests the compare method.
         */
        [TestMethod]
		public void compareTest()
        {
            int a, b;
            int c;
            a = Integer.MIN_VALUE;
            b = (int)-1;
            c = Integer.compare(a, b);
            Assert.AreEqual(-1, c);
            a = Integer.MAX_VALUE;
            b = (int)1;
            c = Integer.compare(a, b);
            Assert.AreEqual(1, c);
            a = (int)0;
            b = (int)1;
            c = Integer.compare(a, b);
            Assert.AreEqual(-1, c);
            a = (int)0;
            b = (int)-1;
            c = Integer.compare(a, b);
            Assert.AreEqual(1, c);
            a = (int)1;
            b = (int)1;
            c = Integer.compare(a, b);
            Assert.AreEqual(0, c);
            a = (int)-1;
            b = (int)-1;
            c = Integer.compare(a, b);
            Assert.AreEqual(0, c);
        }

        /**
         * Tests the equals method.
         */
        [TestMethod]
		public void equalsTest()
        {
            Integer a, b;
            bool c;
            a = new Integer(Integer.MIN_VALUE);
            b = new Integer((int)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Integer(Integer.MAX_VALUE);
            b = new Integer((int)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Integer((int)0);
            b = new Integer((int)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Integer((int)0);
            b = new Integer((int)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Integer((int)1);
            b = new Integer((int)1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
            a = new Integer((int)-1);
            b = new Integer((int)-1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
        }

        /**
         * Tests the toString method.
         */
        [TestMethod]
		public void toStringTest()
        {
            Integer a;
            String b;
            a = new Integer((int)100000);
            b = a.toString();
            Assert.AreEqual(100000, b);
            a = new Integer((int)0);
            b = a.toString();
            Assert.AreEqual(0, b);
            a = new Integer((int)-100000);
            b = a.toString();
            Assert.AreEqual(-100000, b);
        }

        /**
         * Tests the static toString method.
         */
        [TestMethod]
		public void toStringTest2()
        {
            Integer a;
            String b;
            a = new Integer((int)100000);
            b = Integer.toString(a);
            Assert.AreEqual(100000, b);
            a = new Integer((int)0);
            b = Integer.toString(a);
            Assert.AreEqual(0, b);
            a = new Integer((int)-100000);
            b = Integer.toString(a);
            Assert.AreEqual(-100000, b);
        }

        /**
         * Tests the parseInt method.
         */
        [TestMethod]
		public void parseIntTest()
        {
            Integer a;
            int b;
            a = Integer.parseInt("100000");
            b = a.intValue();
            Assert.AreEqual(100000, b);
            a = Integer.parseInt("0");
            b = a.intValue();
            Assert.AreEqual(0, b);
            a = Integer.parseInt("-100000");
            b = a.intValue();
            Assert.AreEqual(-100000, b);
        }
    }
}

