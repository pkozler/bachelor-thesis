using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class FloatTest
	{

        /// <summary>
        /// Tests the floatValue method.
        /// </summary>
        [TestMethod]
		public void floatValueTest()
        {
            Float a;
            float b;
            a = new Float(Float.MIN_VALUE);
            b = a.floatValue();
            Assert.AreEqual(1.4E-45, b);
            a = new Float((float)0);
            b = a.floatValue();
            Assert.AreEqual(0.0, b);
            a = new Float(Float.MAX_VALUE);
            b = a.floatValue();
            Assert.AreEqual(3.4028235E38, b);
        }

        /// <summary>
        /// Tests the compareTo method.
        /// </summary>
        [TestMethod]
		public void compareToTest()
        {
            Float a, b;
            int c;
            a = new Float(Float.MIN_VALUE);
            b = new Float((float)-1);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            a = new Float(Float.MAX_VALUE);
            b = new Float((float)1);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            a = new Float((float)0);
            b = new Float((float)1);
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            a = new Float((float)0);
            b = new Float((float)-1);
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            a = new Float((float)1);
            b = new Float((float)1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
            a = new Float((float)-1);
            b = new Float((float)-1);
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the compare method.
        /// </summary>
        [TestMethod]
		public void compareTest()
        {
            float a, b;
            int c;
            a = Float.MIN_VALUE;
            b = (float)-1;
            c = Float.compare(a, b);
            Assert.AreEqual(1, c);
            a = Float.MAX_VALUE;
            b = (float)1;
            c = Float.compare(a, b);
            Assert.AreEqual(1, c);
            a = (float)0;
            b = (float)1;
            c = Float.compare(a, b);
            Assert.AreEqual(-1, c);
            a = (float)0;
            b = (float)-1;
            c = Float.compare(a, b);
            Assert.AreEqual(1, c);
            a = (float)1;
            b = (float)1;
            c = Float.compare(a, b);
            Assert.AreEqual(0, c);
            a = (float)-1;
            b = (float)-1;
            c = Float.compare(a, b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the equals method.
        /// </summary>
        [TestMethod]
		public void equalsTest()
        {
            Float a, b;
            bool c;
            a = new Float(Float.MIN_VALUE);
            b = new Float((float)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Float(Float.MAX_VALUE);
            b = new Float((float)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Float((float)0);
            b = new Float((float)1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Float((float)0);
            b = new Float((float)-1);
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Float((float)1);
            b = new Float((float)1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
            a = new Float((float)-1);
            b = new Float((float)-1);
            c = a.equals(b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest()
        {
            Float a;
            String b;
            a = new Float((float)0.1);
            b = a.toString();
            Assert.AreEqual("0.1", b);
            a = new Float((float)0);
            b = a.toString();
            Assert.AreEqual("0.0", b);
            a = new Float((float)-0.1);
            b = a.toString();
            Assert.AreEqual("-0.1", b);
        }

        /// <summary>
        /// Tests the static toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest2()
        {
            float a;
            String b;
            a = (float)0.1;
            b = Float.toString(a);
            Assert.AreEqual("0.1", b);
            a = (float)0;
            b = Float.toString(a);
            Assert.AreEqual("0.0", b);
            a = (float)-0.1;
            b = Float.toString(a);
            Assert.AreEqual("-0.1", b);
        }

        /// <summary>
        /// Tests the parseFloat method.
        /// </summary>
        [TestMethod]
		public void parseFloatTest()
        {
            float a;
            a = Float.parseFloat("0.1");
            Assert.AreEqual(0.1, a);
            a = Float.parseFloat("0");
            Assert.AreEqual(0.0, a);
            a = Float.parseFloat("-0.1");
            Assert.AreEqual(-0.1, a);
        }

    }
}

