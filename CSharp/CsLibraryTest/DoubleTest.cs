using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class DoubleTest
	{

        /// <summary>
        /// Tests the doubleValue method.
        /// </summary>
        [TestMethod]
		public void doubleValueTest()
        {
            Double a;
            double b;
            // minimal non-zero absolute value
            a = new Double(Double.MIN_VALUE);
            b = a.doubleValue();
            Assert.AreEqual(4.9E-324, b);
            // zero value
            a = new Double((double)0);
            b = a.doubleValue();
            Assert.AreEqual(0.0, b);
            // maximal finite absolute value
            a = new Double(Double.MAX_VALUE);
            b = a.doubleValue();
            Assert.AreEqual(1.7976931348623157E308, b);
        }

        /// <summary>
        /// Tests the compareTo method.
        /// </summary>
        [TestMethod]
		public void compareToTest()
        {
            Double a, b;
            int c;
            // minimal non-zero absolute value and bigger fractional value
            a = new Double(Double.MIN_VALUE);
            b = new Double((double)0.1);
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            // maximal finite absolute value and smaller integer value
            a = new Double(Double.MAX_VALUE);
            b = new Double((double)1);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            // zero and positive value
            a = new Double((double)0);
            b = new Double((double)1);
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            // zero and negative value
            a = new Double((double)0);
            b = new Double((double)-1);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            // both values are positive
            a = new Double((double)1);
            b = new Double((double)1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
            // both values are negative
            a = new Double((double)-1);
            b = new Double((double)-1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the compare method.
        /// </summary>
        [TestMethod]
		public void compareTest()
        {
            double a, b;
            int c;
            a = Double.MIN_VALUE;
            b = (double)0.1;
            c = Double.compare(a, b);
            Assert.AreEqual(-1, c);
            a = Double.MAX_VALUE;
            b = (double)1;
            c = Double.compare(a, b);
            Assert.AreEqual(1, c);
            a = (double)0;
            b = (double)1;
            c = Double.compare(a, b);
            Assert.AreEqual(-1, c);
            a = (double)0;
            b = (double)-1;
            c = Double.compare(a, b);
            Assert.AreEqual(1, c);
            a = (double)1;
            b = (double)1;
            c = Double.compare(a, b);
            Assert.AreEqual(0, c);
            a = (double)-1;
            b = (double)-1;
            c = Double.compare(a, b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the equals method.
        /// </summary>
        [TestMethod]
		public void equalsTest()
        {
            Double a, b;
            bool c;
            a = new Double(Double.MIN_VALUE);
            b = new Double((double)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Double(Double.MAX_VALUE);
            b = new Double((double)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Double((double)0);
            b = new Double((double)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Double((double)0);
            b = new Double((double)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Double((double)1);
            b = new Double((double)1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
            a = new Double((double)-1);
            b = new Double((double)-1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest()
        {
            Double a;
            String b;
            // positive value text representation
            a = new Double((double)0.0000000000000000000000000000000000000000000001);
            b = a.toString();
            Assert.AreEqual("1.0E-46", b);
            // zero value text representation
            a = new Double((double)0);
            b = a.toString();
            Assert.AreEqual("0.0", b);
            // negative value text representation
            a = new Double((double)-0.0000000000000000000000000000000000000000000001);
            b = a.toString();
            Assert.AreEqual("-1.0E-46", b);
        }

        /// <summary>
        /// Tests the static toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest2()
        {
            double a;
            String b;
            a = (double)0.0000000000000000000000000000000000000000000001;
            b = Double.toString(a);
            Assert.AreEqual("1.0E-46", b);
            a = (double)0;
            b = Double.toString(a);
            Assert.AreEqual("0.0", b);
            a = (double)-0.0000000000000000000000000000000000000000000001;
            b = Double.toString(a);
            Assert.AreEqual("-1.0E-46", b);
        }

        /// <summary>
        /// Tests the parseDouble method.
        /// </summary>
        [TestMethod]
		public void parseDoubleTest()
        {
            double a;
            // positive value parsing
            a = Double.parseDouble("0.0000000000000000000000000000000000000000000001");
            Assert.AreEqual(1.0E-46, a);
            // zero value parsing
            a = Double.parseDouble("0");
            Assert.AreEqual(0.0, a);
            // negative value parsing
            a = Double.parseDouble("-0.0000000000000000000000000000000000000000000001");
            Assert.AreEqual(-1.0E-46, a);
        }

    }
}

