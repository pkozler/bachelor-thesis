using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class LongTest
	{
        /**
         * Tests the longValue method.
         */
        [TestMethod]
		public void longValueTest()
        {
            Long a;
            long b;
            a = new Long(Long.MIN_VALUE);
            b = a.longValue();
            Assert.AreEqual(-9223372036854775808, b);
            a = new Long((long)0);
            b = a.longValue();
            Assert.AreEqual(0, b);
            a = new Long(Long.MAX_VALUE);
            b = a.longValue();
            Assert.AreEqual(9223372036854775807, b);
        }

        /**
         * Tests the compareTo method.
         */
        [TestMethod]
		public void compareToTest()
        {
            Long a, b;
            int c;
            a = new Long(Long.MIN_VALUE);
            b = new Long((long)-1);
            c = Long.compare(a, b);
            Assert.AreEqual(-1, c);
            a = new Long(Long.MAX_VALUE);
            b = new Long((long)1);
            c = Long.compare(a, b);
            Assert.AreEqual(1, c);
            a = new Long((long)0);
            b = new Long((long)1);
            c = Long.compare(a, b);
            Assert.AreEqual(-1, c);
            a = new Long((long)0);
            b = new Long((long)-1);
            c = Long.compare(a, b);
            Assert.AreEqual(1, c);
            a = new Long((long)1);
            b = new Long((long)1);
            c = Long.compare(a, b);
            Assert.AreEqual(0, c);
            a = new Long((long)-1);
            b = new Long((long)-1);
            c = Long.compare(a, b);
            Assert.AreEqual(0, c);
        }

        /**
         * Tests the compare method.
         */
        [TestMethod]
		public void compareTest()
        {
            long a, b;
            int c;
            a = Long.MIN_VALUE;
            b = (long)-1;
            c = Long.compare(a, b);
            Assert.AreEqual(-1, c);
            a = Long.MAX_VALUE;
            b = (long)1;
            c = Long.compare(a, b);
            Assert.AreEqual(1, c);
            a = (long)0;
            b = (long)1;
            c = Long.compare(a, b);
            Assert.AreEqual(-1, c);
            a = (long)0;
            b = (long)-1;
            c = Long.compare(a, b);
            Assert.AreEqual(1, c);
            a = (long)1;
            b = (long)1;
            c = Long.compare(a, b);
            Assert.AreEqual(0, c);
            a = (long)-1;
            b = (long)-1;
            c = Long.compare(a, b);
            Assert.AreEqual(0, c);
        }

        /**
         * Tests the equals method.
         */
        [TestMethod]
		public void equalsTest()
        {
            Long a, b;
            bool c;
            a = new Long(Long.MIN_VALUE);
            b = new Long((long)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Long(Long.MAX_VALUE);
            b = new Long((long)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Long((long)0);
            b = new Long((long)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Long((long)0);
            b = new Long((long)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Long((long)1);
            b = new Long((long)1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
            a = new Long((long)-1);
            b = new Long((long)-1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
        }

        /**
         * Tests the toString method.
         */
        [TestMethod]
		public void toStringTest()
        {
            Long a;
            String b;
            a = new Long((long)10000000000L);
            b = a.toString();
            Assert.AreEqual(10000000000, b);
            a = new Long((long)0);
            b = a.toString();
            Assert.AreEqual(0, b);
            a = new Long((long)-10000000000L);
            b = a.toString();
            Assert.AreEqual(-10000000000, b);
        }

        /**
         * Tests the static toString method.
         */
        [TestMethod]
		public void toStringTest2()
        {
            Long a;
            String b;
            a = new Long((long)10000000000L);
            b = Long.toString(a);
            Assert.AreEqual(10000000000, b);
            a = new Long((long)0);
            b = Long.toString(a);
            Assert.AreEqual(0, b);
            a = new Long((long)-10000000000L);
            b = Long.toString(a);
            Assert.AreEqual(-10000000000, b);
        }

        /**
         * Tests the parseLong method.
         */
        [TestMethod]
		public void parseLongTest()
        {
            Long a;
            long b;
            a = Long.parseLong("10000000000");
            b = a.longValue();
            Assert.AreEqual(10000000000, b);
            a = Long.parseLong("0");
            b = a.longValue();
            Assert.AreEqual(0, b);
            a = Long.parseLong("-10000000000");
            b = a.longValue();
            Assert.AreEqual(-10000000000, b);
        }
    }
}

