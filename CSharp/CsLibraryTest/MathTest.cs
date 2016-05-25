using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class MathTest
	{
        const double DEFAULT_EPSILON = 1E-20;

        /// <summary>
        /// Tests the abs method with a double value.
        /// </summary>
        [TestMethod]
		public void absTest()
        {
            double a, b;
            // negative value
            a = Double.MIN_VALUE + 1;
            b = Math.abs(a);
            Assert.AreEqual(1.0, b, DEFAULT_EPSILON);
            // zero value
            a = 0;
            b = Math.abs(a);
            Assert.AreEqual(0.0, b, DEFAULT_EPSILON);
            // positive value
            a = Double.MAX_VALUE - 1;
            b = Math.abs(a);
            Assert.AreEqual(1.7976931348623157E308, b, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the abs method with a float value.
        /// </summary>
        [TestMethod]
		public void absTest2()
        {
            float a, b;
            a = Float.MIN_VALUE + 1;
            b = Math.abs(a);
            Assert.AreEqual(1.0, b, DEFAULT_EPSILON);
            a = 0;
            b = Math.abs(a);
            Assert.AreEqual(0.0, b, DEFAULT_EPSILON);
            a = Float.MAX_VALUE - 1;
            b = Math.abs(a);
            Assert.AreEqual(3.4028235E38f, b, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the abs method with an int value.
        /// </summary>
        [TestMethod]
		public void absTest3()
        {
            int a, b;
            a = Integer.MIN_VALUE + 1;
            b = Math.abs(a);
            Assert.AreEqual(2147483647, b);
            a = 0;
            b = Math.abs(a);
            Assert.AreEqual(0, b);
            a = Integer.MAX_VALUE - 1;
            b = Math.abs(a);
            Assert.AreEqual(2147483646, b);
        }

        /// <summary>
        /// Tests the abs method with a long value.
        /// </summary>
        [TestMethod]
		public void absTest4()
        {
            long a, b;
            a = Long.MIN_VALUE + 1;
            b = Math.abs(a);
            Assert.AreEqual(9223372036854775807, b);
            a = 0;
            b = Math.abs(a);
            Assert.AreEqual(0, b);
            a = Long.MAX_VALUE - 1;
            b = Math.abs(a);
            Assert.AreEqual(9223372036854775806, b);
        }

        /// <summary>
        /// Tests the max method with a double value.
        /// </summary>
        [TestMethod]
		public void maxTest()
        {
            double a, b, c;
            // negative and positive value
            a = Double.MIN_VALUE;
            b = Double.MAX_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(1.7976931348623157E308, c, DEFAULT_EPSILON);
            // positive and negative value
            a = Double.MAX_VALUE;
            b = Double.MIN_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(1.7976931348623157E308, c, DEFAULT_EPSILON);
            // negative and positive value (smaller difference)
            a = -1;
            b = 1;
            c = Math.max(a, b);
            Assert.AreEqual(1.0, c, DEFAULT_EPSILON);
            // positive and negative value (bigger difference)
            a = 1;
            b = -1;
            c = Math.max(a, b);
            // equal values
            Assert.AreEqual(1.0, c, DEFAULT_EPSILON);
            a = 0;
            b = 0;
            c = Math.max(a, b);
            Assert.AreEqual(0.0, c, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the max method with a float value.
        /// </summary>
        [TestMethod]
		public void maxTest2()
        {
            float a, b, c;
            a = Float.MIN_VALUE;
            b = Float.MAX_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(3.4028235E38, c, DEFAULT_EPSILON);
            a = Float.MAX_VALUE;
            b = Float.MIN_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(3.4028235E38, c, DEFAULT_EPSILON);
            a = -1;
            b = 1;
            c = Math.max(a, b);
            Assert.AreEqual(1.0, c, DEFAULT_EPSILON);
            a = 1;
            b = -1;
            c = Math.max(a, b);
            Assert.AreEqual(1.0, c, DEFAULT_EPSILON);
            a = 0;
            b = 0;
            c = Math.max(a, b);
            Assert.AreEqual(0.0, c, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the max method with an int value.
        /// </summary>
        [TestMethod]
		public void maxTest3()
        {
            int a, b, c;
            a = Integer.MIN_VALUE;
            b = Integer.MAX_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(2147483647, c);
            a = Integer.MAX_VALUE;
            b = Integer.MIN_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(2147483647, c);
            a = -1;
            b = 1;
            c = Math.max(a, b);
            Assert.AreEqual(1, c);
            a = 1;
            b = -1;
            c = Math.max(a, b);
            Assert.AreEqual(1, c);
            a = 0;
            b = 0;
            c = Math.max(a, b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the max method with a long value.
        /// </summary>
        [TestMethod]
		public void maxTest4()
        {
            long a, b, c;
            a = Long.MIN_VALUE;
            b = Long.MAX_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(9223372036854775807, c);
            a = Long.MAX_VALUE;
            b = Long.MIN_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(9223372036854775807, c);
            a = -1;
            b = 1;
            c = Math.max(a, b);
            Assert.AreEqual(1, c);
            a = 1;
            b = -1;
            c = Math.max(a, b);
            Assert.AreEqual(1, c);
            a = 0;
            b = 0;
            c = Math.max(a, b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the min method with a double value.
        /// </summary>
        [TestMethod]
		public void minTest()
        {
            double a, b, c;
            a = Double.MIN_VALUE;
            b = Double.MAX_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(4.9E-324, c, DEFAULT_EPSILON);
            a = Double.MAX_VALUE;
            b = Double.MIN_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(4.9E-324, c, DEFAULT_EPSILON);
            a = -1;
            b = 1;
            c = Math.min(a, b);
            Assert.AreEqual(-1.0, c, DEFAULT_EPSILON);
            a = 1;
            b = -1;
            c = Math.min(a, b);
            Assert.AreEqual(-1.0, c, DEFAULT_EPSILON);
            a = 0;
            b = 0;
            c = Math.min(a, b);
            Assert.AreEqual(0.0, c, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the min method with a float value.
        /// </summary>
        [TestMethod]
		public void minTest2()
        {
            float a, b, c;
            a = Float.MIN_VALUE;
            b = Float.MAX_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(1.4E-45, c, DEFAULT_EPSILON);
            a = Float.MAX_VALUE;
            b = Float.MIN_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(1.4E-45, c, DEFAULT_EPSILON);
            a = -1;
            b = 1;
            c = Math.min(a, b);
            Assert.AreEqual(-1.0, c, DEFAULT_EPSILON);
            a = 1;
            b = -1;
            c = Math.min(a, b);
            Assert.AreEqual(-1.0, c, DEFAULT_EPSILON);
            a = 0;
            b = 0;
            c = Math.min(a, b);
            Assert.AreEqual(0.0, c, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the min method with an int value.
        /// </summary>
        [TestMethod]
		public void minTest3()
        {
            int a, b, c;
            a = Integer.MIN_VALUE;
            b = Integer.MAX_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(-2147483648, c, DEFAULT_EPSILON);
            a = Integer.MAX_VALUE;
            b = Integer.MIN_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(-2147483648, c, DEFAULT_EPSILON);
            a = -1;
            b = 1;
            c = Math.min(a, b);
            Assert.AreEqual(-1, c, DEFAULT_EPSILON);
            a = 1;
            b = -1;
            c = Math.min(a, b);
            Assert.AreEqual(-1, c, DEFAULT_EPSILON);
            a = 0;
            b = 0;
            c = Math.min(a, b);
            Assert.AreEqual(0, c, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the min method with a long value.
        /// </summary>
        [TestMethod]
		public void minTest4()
        {
            long a, b, c;
            a = Long.MIN_VALUE;
            b = Long.MAX_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(-9223372036854775808, c, DEFAULT_EPSILON);
            a = Long.MAX_VALUE;
            b = Long.MIN_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(-9223372036854775808, c, DEFAULT_EPSILON);
            a = -1;
            b = 1;
            c = Math.min(a, b);
            Assert.AreEqual(-1, c, DEFAULT_EPSILON);
            a = 1;
            b = -1;
            c = Math.min(a, b);
            Assert.AreEqual(-1, c, DEFAULT_EPSILON);
            a = 0;
            b = 0;
            c = Math.min(a, b);
            Assert.AreEqual(0, c, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Test the pow method.
        /// </summary>
        [TestMethod]
		public void powTest()
        {
            double a, b, c;
            // positive power of positive value
            a = 10;
            b = 2;
            c = Math.pow(a, b);
            Assert.AreEqual(100.0, c, DEFAULT_EPSILON);
            // positive power of negative value
            a = -10;
            b = 2;
            c = Math.pow(a, b);
            Assert.AreEqual(100.0, c, DEFAULT_EPSILON);
            // negative power of positive value
            a = 10;
            b = -2;
            c = Math.pow(a, b);
            // zore power
            Assert.AreEqual(0.01, c, DEFAULT_EPSILON);
            a = 10;
            b = 0;
            c = Math.pow(a, b);
            Assert.AreEqual(1.0, c, DEFAULT_EPSILON);
            // power of zero
            a = 0;
            b = 10;
            c = Math.pow(a, b);
            Assert.AreEqual(0.0, c, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the sqrt method.
        /// </summary>
        [TestMethod]
		public void sqrtTest()
        {
            double a, b;
            // square root of bigger value
            a = 100;
            b = Math.sqrt(a);
            Assert.AreEqual(10.0, b, DEFAULT_EPSILON);
            // square root of one
            a = 1;
            b = Math.sqrt(a);
            Assert.AreEqual(1.0, b, DEFAULT_EPSILON);
            // square root of zero
            a = 0;
            b = Math.sqrt(a);
            Assert.AreEqual(0.0, b, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the log method.
        /// </summary>
        [TestMethod]
		public void logTest()
        {
            double a, b;
            // logarithm of the square of E
            a = Math.E * Math.E;/// Math.E;
            b = Math.log(a);
            Assert.AreEqual(2.0, b, DEFAULT_EPSILON);
            // logarithm of E
            a = Math.E;
            b = Math.log(a);
            Assert.AreEqual(1.0, b, DEFAULT_EPSILON);
            // logarithm of one
            a = 1;
            b = Math.log(a);
            Assert.AreEqual(0.0, b, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the log10 method.
        /// </summary>
        [TestMethod]
		public void log10Test()
        {
            double a, b;
            // logarithm of the square of ten
            a = 100;
            b = Math.log10(a);
            Assert.AreEqual(2.0, b, DEFAULT_EPSILON);
            // logarithm of ten
            a = 10;
            b = Math.log10(a);
            Assert.AreEqual(1.0, b, DEFAULT_EPSILON);
            // logarithm of one
            a = 1;
            b = Math.log10(a);
            Assert.AreEqual(0.0, b, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the sin method.
        /// </summary>
        [TestMethod]
		public void sinTest()
        {
            double a, b;
            // sine of PI
            a = Math.PI;
            b = Math.sin(a);
            Assert.AreEqual(1.2246467991473532E-16, b, DEFAULT_EPSILON);
            // sine of minus PI
            a = -Math.PI;
            b = Math.sin(a);
            Assert.AreEqual(-1.2246467991473532E-16, b, DEFAULT_EPSILON);
            // sine of zero
            a = 0;
            b = Math.sin(a);
            Assert.AreEqual(0.0, b, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the cos method.
        /// </summary>
        [TestMethod]
		public void cosTest()
        {
            double a, b;
            // cosine of PI
            a = Math.PI;
            b = Math.cos(a);
            Assert.AreEqual(-1.0, b, DEFAULT_EPSILON);
            // cosine of minus PI
            a = -Math.PI;
            b = Math.cos(a);
            Assert.AreEqual(-1.0, b, DEFAULT_EPSILON);
            // cosine of zero
            a = 0;
            b = Math.cos(a);
            Assert.AreEqual(1.0, b, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the tan method.
        /// </summary>
        [TestMethod]
		public void tanTest()
        {
            double a, b;
            // tangent of PI
            a = Math.PI;
            b = Math.tan(a);
            Assert.AreEqual(-1.2246467991473532E-16, b, DEFAULT_EPSILON);
            // tangent of minus PI
            a = -Math.PI;
            b = Math.tan(a);
            Assert.AreEqual(1.2246467991473532E-16, b, DEFAULT_EPSILON);
            // tangent of zero
            a = 0;
            b = Math.tan(a);
            Assert.AreEqual(0.0, b, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the asin method.
        /// </summary>
        [TestMethod]
		public void asinTest()
        {
            double a, b;
            // arcsine of one
            a = 1;
            b = Math.asin(a);
            Assert.AreEqual(1.5707963267948966, b, DEFAULT_EPSILON);
            // arcsine of minus one
            a = -1;
            b = Math.asin(a);
            Assert.AreEqual(-1.5707963267948966, b, DEFAULT_EPSILON);
            // arcsine of zero
            a = 0;
            b = Math.asin(a);
            Assert.AreEqual(0.0, b, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the acos method.
        /// </summary>
        [TestMethod]
		public void acosTest()
        {
            double a, b;
            // arccosine of one
            a = 1;
            b = Math.acos(a);
            Assert.AreEqual(0.0, b, DEFAULT_EPSILON);
            // arccosine of minus one
            a = -1;
            b = Math.acos(a);
            Assert.AreEqual(3.141592653589793, b, DEFAULT_EPSILON);
            // arccosine of zero
            a = 0;
            b = Math.acos(a);
            Assert.AreEqual(1.5707963267948966, b, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the atan method.
        /// </summary>
        [TestMethod]
		public void atanTest()
        {
            double a, b;
            // arctangent of one
            a = 1;
            b = Math.atan(a);
            Assert.AreEqual(0.7853981633974483, b, DEFAULT_EPSILON);
            // arctangent of minus one
            a = -1;
            b = Math.atan(a);
            Assert.AreEqual(-0.7853981633974483, b, DEFAULT_EPSILON);
            // arctangent of zero
            a = 0;
            b = Math.atan(a);
            Assert.AreEqual(0.0, b, DEFAULT_EPSILON);
        }

        /// <summary>
        /// Tests the round method with a double value.
        /// </summary>
        [TestMethod]
		public void roundTest()
        {
            double a;
            long b;
            // rounding to even value
            a = 1.5;
            b = Math.round(a);
            Assert.AreEqual(2, b);
            // rounding to odd value
            a = 0.5;
            b = Math.round(a);
            Assert.AreEqual(1, b);
            // rounding of negative value
            a = -0.5;
            b = Math.round(a);
            Assert.AreEqual(0, b);
        }

        /// <summary>
        /// Tests the round method with a float value.
        /// </summary>
        [TestMethod]
		public void roundTest2()
        {
            float a;
            int b;
            a = 1.5f;
            b = Math.round(a);
            Assert.AreEqual(2, b);
            a = 0.5f;
            b = Math.round(a);
            Assert.AreEqual(1, b);
            a = -0.5f;
            b = Math.round(a);
            Assert.AreEqual(0, b);
        }

    }
}

