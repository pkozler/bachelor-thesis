unit mathtestunit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, fpcunit, testutils, testregistry, MathUnit;

type

  MathTest= class(TTestCase)
  published
    procedure TestHookUp;
  end;

implementation

procedure MathTest.TestHookUp;
begin
  Fail('Napište si svůj vlastní test');
end;

/**
         * Tests the abs method with a double value.
         */
        [TestMethod]
		public void absTest()
        {
            double a, b;
            // negative value
            a = Double.MIN_VALUE + 1;
            b = Math.abs(a);
            Assert.AreEqual(1.0, b);
            // zero value
            a = 0;
            b = Math.abs(a);
            Assert.AreEqual(0.0, b);
            // positive value
            a = Double.MAX_VALUE - 1;
            b = Math.abs(a);
            Assert.AreEqual(1.7976931348623157E308, b);
        }

        /**
         * Tests the abs method with a float value.
         */
        [TestMethod]
		public void absTest2()
        {
            float a, b;
            a = Float.MIN_VALUE + 1;
            b = Math.abs(a);
            Assert.AreEqual(1.0, b);
            a = 0;
            b = Math.abs(a);
            Assert.AreEqual(0.0, b);
            a = Float.MAX_VALUE - 1;
            b = Math.abs(a);
            Assert.AreEqual(3.4028235E38, b);
        }

        /**
         * Tests the abs method with an int value.
         */
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

        /**
         * Tests the abs method with a long value.
         */
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

        /**
         * Tests the max method with a double value.
         */
        [TestMethod]
		public void maxTest()
        {
            double a, b, c;
            // negative and positive value
            a = Double.MIN_VALUE;
            b = Double.MAX_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(1.7976931348623157E308, c);
            // positive and negative value
            a = Double.MAX_VALUE;
            b = Double.MIN_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(1.7976931348623157E308, c);
            // negative and positive value (smaller difference)
            a = -1;
            b = 1;
            c = Math.max(a, b);
            Assert.AreEqual(1.0, c);
            // positive and negative value (bigger difference)
            a = 1;
            b = -1;
            c = Math.max(a, b);
            // equal values
            Assert.AreEqual(1.0, c);
            a = 0;
            b = 0;
            c = Math.max(a, b);
            Assert.AreEqual(0.0, c);
        }

        /**
         * Tests the max method with a float value.
         */
        [TestMethod]
		public void maxTest2()
        {
            float a, b, c;
            a = Float.MIN_VALUE;
            b = Float.MAX_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(3.4028235E38, c);
            a = Float.MAX_VALUE;
            b = Float.MIN_VALUE;
            c = Math.max(a, b);
            Assert.AreEqual(3.4028235E38, c);
            a = -1;
            b = 1;
            c = Math.max(a, b);
            Assert.AreEqual(1.0, c);
            a = 1;
            b = -1;
            c = Math.max(a, b);
            Assert.AreEqual(1.0, c);
            a = 0;
            b = 0;
            c = Math.max(a, b);
            Assert.AreEqual(0.0, c);
        }

        /**
         * Tests the max method with an int value.
         */
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

        /**
         * Tests the max method with a long value.
         */
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

        /**
         * Tests the min method with a double value.
         */
        [TestMethod]
		public void minTest()
        {
            double a, b, c;
            a = Double.MIN_VALUE;
            b = Double.MAX_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(4.9E-324, c);
            a = Double.MAX_VALUE;
            b = Double.MIN_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(4.9E-324, c);
            a = -1;
            b = 1;
            c = Math.min(a, b);
            Assert.AreEqual(-1.0, c);
            a = 1;
            b = -1;
            c = Math.min(a, b);
            Assert.AreEqual(-1.0, c);
            a = 0;
            b = 0;
            c = Math.min(a, b);
            Assert.AreEqual(0.0, c);
        }

        /**
         * Tests the min method with a float value.
         */
        [TestMethod]
		public void minTest2()
        {
            float a, b, c;
            a = Float.MIN_VALUE;
            b = Float.MAX_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(1.4E-45, c);
            a = Float.MAX_VALUE;
            b = Float.MIN_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(1.4E-45, c);
            a = -1;
            b = 1;
            c = Math.min(a, b);
            Assert.AreEqual(-1.0, c);
            a = 1;
            b = -1;
            c = Math.min(a, b);
            Assert.AreEqual(-1.0, c);
            a = 0;
            b = 0;
            c = Math.min(a, b);
            Assert.AreEqual(0.0, c);
        }

        /**
         * Tests the min method with an int value.
         */
        [TestMethod]
		public void minTest3()
        {
            int a, b, c;
            a = Integer.MIN_VALUE;
            b = Integer.MAX_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(-2147483648, c);
            a = Integer.MAX_VALUE;
            b = Integer.MIN_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(-2147483648, c);
            a = -1;
            b = 1;
            c = Math.min(a, b);
            Assert.AreEqual(-1, c);
            a = 1;
            b = -1;
            c = Math.min(a, b);
            Assert.AreEqual(-1, c);
            a = 0;
            b = 0;
            c = Math.min(a, b);
            Assert.AreEqual(0, c);
        }

        /**
         * Tests the min method with a long value.
         */
        [TestMethod]
		public void minTest4()
        {
            long a, b, c;
            a = Long.MIN_VALUE;
            b = Long.MAX_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(-9223372036854775808, c);
            a = Long.MAX_VALUE;
            b = Long.MIN_VALUE;
            c = Math.min(a, b);
            Assert.AreEqual(-9223372036854775808, c);
            a = -1;
            b = 1;
            c = Math.min(a, b);
            Assert.AreEqual(-1, c);
            a = 1;
            b = -1;
            c = Math.min(a, b);
            Assert.AreEqual(-1, c);
            a = 0;
            b = 0;
            c = Math.min(a, b);
            Assert.AreEqual(0, c);
        }

        /**
         * Test the pow method.
         */
        [TestMethod]
		public void powTest()
        {
            double a, b, c;
            // positive power of positive value
            a = 10;
            b = 2;
            c = Math.pow(a, b);
            Assert.AreEqual(100.0, c);
            // positive power of negative value
            a = -10;
            b = 2;
            c = Math.pow(a, b);
            Assert.AreEqual(100.0, c);
            // negative power of positive value
            a = 10;
            b = -2;
            c = Math.pow(a, b);
            // zore power
            Assert.AreEqual(0.01, c);
            a = 10;
            b = 0;
            c = Math.pow(a, b);
            Assert.AreEqual(1.0, c);
            // power of zero
            a = 0;
            b = 10;
            c = Math.pow(a, b);
            Assert.AreEqual(0.0, c);
        }

        /**
         * Tests the sqrt method.
         */
        [TestMethod]
		public void sqrtTest()
        {
            double a, b;
            // square root of bigger value
            a = 100;
            b = Math.sqrt(a);
            Assert.AreEqual(10.0, b);
            // square root of one
            a = 1;
            b = Math.sqrt(a);
            Assert.AreEqual(1.0, b);
            // square root of zero
            a = 0;
            b = Math.sqrt(a);
            Assert.AreEqual(0.0, b);
        }

        /**
         * Tests the log method.
         */
        [TestMethod]
		public void logTest()
        {
            double a, b;
            // logarithm of the square of E
            a = Math.E * Math.E;
            b = Math.log(a);
            Assert.AreEqual(2.0, b);
            // logarithm of E
            a = Math.E;
            b = Math.log(a);
            Assert.AreEqual(1.0, b);
            // logarithm of one
            a = 1;
            b = Math.log(a);
            Assert.AreEqual(0.0, b);
        }

        /**
         * Tests the log10 method.
         */
        [TestMethod]
		public void log10Test()
        {
            double a, b;
            // logarithm of the square of ten
            a = 100;
            b = Math.log10(a);
            Assert.AreEqual(2.0, b);
            // logarithm of ten
            a = 10;
            b = Math.log10(a);
            Assert.AreEqual(1.0, b);
            // logarithm of one
            a = 1;
            b = Math.log10(a);
            Assert.AreEqual(0.0, b);
        }

        /**
         * Tests the sin method.
         */
        [TestMethod]
		public void sinTest()
        {
            double a, b;
            // sine of PI
            a = Math.PI;
            b = Math.sin(a);
            Assert.AreEqual(1.2246467991473532E-16, b);
            // sine of minus PI
            a = -Math.PI;
            b = Math.sin(a);
            Assert.AreEqual(-1.2246467991473532E-16, b);
            // sine of zero
            a = 0;
            b = Math.sin(a);
            Assert.AreEqual(0.0, b);
        }

        /**
         * Tests the cos method.
         */
        [TestMethod]
		public void cosTest()
        {
            double a, b;
            // cosine of PI
            a = Math.PI;
            b = Math.cos(a);
            Assert.AreEqual(-1.0, b);
            // cosine of minus PI
            a = -Math.PI;
            b = Math.cos(a);
            Assert.AreEqual(-1.0, b);
            // cosine of zero
            a = 0;
            b = Math.cos(a);
            Assert.AreEqual(1.0, b);
        }

        /**
         * Tests the tan method.
         */
        [TestMethod]
		public void tanTest()
        {
            double a, b;
            // tangent of PI
            a = Math.PI;
            b = Math.tan(a);
            Assert.AreEqual(-1.2246467991473532E-16, b);
            // tangent of minus PI
            a = -Math.PI;
            b = Math.tan(a);
            Assert.AreEqual(1.2246467991473532E-16, b);
            // tangent of zero
            a = 0;
            b = Math.tan(a);
            Assert.AreEqual(0.0, b);
        }

        /**
         * Tests the asin method.
         */
        [TestMethod]
		public void asinTest()
        {
            double a, b;
            // arcsine of one
            a = 1;
            b = Math.asin(a);
            Assert.AreEqual(1.5707963267948966, b);
            // arcsine of minus one
            a = -1;
            b = Math.asin(a);
            Assert.AreEqual(-1.5707963267948966, b);
            // arcsine of zero
            a = 0;
            b = Math.asin(a);
            Assert.AreEqual(0.0, b);
        }

        /**
         * Tests the acos method.
         */
        [TestMethod]
		public void acosTest()
        {
            double a, b;
            // arccosine of one
            a = 1;
            b = Math.acos(a);
            Assert.AreEqual(0.0, b);
            // arccosine of minus one
            a = -1;
            b = Math.acos(a);
            Assert.AreEqual(3.141592653589793, b);
            // arccosine of zero
            a = 0;
            b = Math.acos(a);
            Assert.AreEqual(1.5707963267948966, b);
        }

        /**
         * Tests the atan method.
         */
        [TestMethod]
		public void atanTest()
        {
            double a, b;
            // arctangent of one
            a = 1;
            b = Math.atan(a);
            Assert.AreEqual(0.7853981633974483, b);
            // arctangent of minus one
            a = -1;
            b = Math.atan(a);
            Assert.AreEqual(-0.7853981633974483, b);
            // arctangent of zero
            a = 0;
            b = Math.atan(a);
            Assert.AreEqual(0.0, b);
        }

        /**
         * Tests the round method with a double value.
         */
        [TestMethod]
		public void roundTest()
        {
            double a, b;
            // rounding to even value
            a = 1.5;
            b = Math.round(a);
            Assert.AreEqual(2.0, b);
            // rounding to odd value
            a = 0.5;
            b = Math.round(a);
            Assert.AreEqual(1.0, b);
            // rounding of negative value
            a = -0.5;
            b = Math.round(a);
            Assert.AreEqual(0.0, b);
        }

        /**
         * Tests the round method with a float value.
         */
        [TestMethod]
		public void roundTest2()
        {
            float a, b;
            a = 1.5f;
            b = Math.round(a);
            Assert.AreEqual(2.0, b);
            a = 0.5f;
            b = Math.round(a);
            Assert.AreEqual(1.0, b);
            a = -0.5f;
            b = Math.round(a);
            Assert.AreEqual(0.0, b);
        }

initialization

  RegisterTest(MathTest);
end.

