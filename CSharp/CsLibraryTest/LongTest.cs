using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class LongTest
	{

        /// <summary>
        /// Tests the longValue method.
        /// </summary>
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

        /// <summary>
        /// Tests the compareTo method.
        /// </summary>
        [TestMethod]
		public void compareToTest()
        {
            Long a, b;
            int c;
            a = new Long(Long.MIN_VALUE);
            b = new Long((long)-1);
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            a = new Long(Long.MAX_VALUE);
            b = new Long((long)1);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            a = new Long((long)0);
            b = new Long((long)1);
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            a = new Long((long)0);
            b = new Long((long)-1);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            a = new Long((long)1);
            b = new Long((long)1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
            a = new Long((long)-1);
            b = new Long((long)-1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the compare method.
        /// </summary>
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

        /// <summary>
        /// Tests the equals method.
        /// </summary>
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

        /// <summary>
        /// Tests the toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest()
        {
            Long a;
            String b;
            a = new Long((long)10000000000L);
            b = a.toString();
            Assert.AreEqual("10000000000", b);
            a = new Long((long)0);
            b = a.toString();
            Assert.AreEqual("0", b);
            a = new Long((long)-10000000000L);
            b = a.toString();
            Assert.AreEqual("-10000000000", b);
        }

        /// <summary>
        /// Tests the static toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest2()
        {
            long a;
            String b;
            a = (long)10000000000L;
            b = Long.toString(a);
            Assert.AreEqual("10000000000", b);
            a = (long)0;
            b = Long.toString(a);
            Assert.AreEqual("0", b);
            a = (long)-10000000000L;
            b = Long.toString(a);
            Assert.AreEqual("-10000000000", b);
        }

        /// <summary>
        /// Tests the parseLong method.
        /// </summary>
        [TestMethod]
		public void parseLongTest()
        {
            long a;
            a = Long.parseLong("10000000000");
            Assert.AreEqual(10000000000, a);
            a = Long.parseLong("0");
            Assert.AreEqual(0, a);
            a = Long.parseLong("-10000000000");
            Assert.AreEqual(-10000000000, a);
        }

    }
}

