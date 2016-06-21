namespace JavaClasses
{

    /// <summary>
    /// The class Math contains methods for performing basic numeric operations such as the elementary exponential,
    /// logarithm, square root, and trigonometric functions.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public static class Math
    {

        /// <summary>
        /// The double value that is closer than any other to e, the base of the natural logarithms.
        /// </summary>
        public const double E = 2.7182818284590452354;

        /// <summary>
        /// The double value that is closer than any other to pi, the ratio of the circumference of a circle to its diameter.
        /// </summary>
        public const double PI = 3.14159265358979323846;

        /// <summary>
        /// Returns the absolute value of a double value.
        /// </summary>
        /// <param name="a">the argument whose absolute value is to be determined
        /// </param><returns>the absolute value of the argument.
        /// </returns>
        public static double abs(double a)
        {
            return System.Math.Abs(a);
        }

        /// <summary>
        /// Returns the absolute value of a float value.
        /// </summary>
        /// <param name="a">the argument whose absolute value is to be determined
        /// </param><returns>the absolute value of the argument.
        /// </returns>
        public static float abs(float a)
        {
            return System.Math.Abs(a);
        }

        /// <summary>
        /// Returns the absolute value of an int value.
        /// </summary>
        /// <param name="a">the argument whose absolute value is to be determined
        /// </param><returns>the absolute value of the argument.
        /// </returns>
        public static int abs(int a)
        {
            return System.Math.Abs(a);
        }

        /// <summary>
        /// Returns the absolute value of a long value.
        /// </summary>
        /// <param name="a">the argument whose absolute value is to be determined
        /// </param><returns>the absolute value of the argument.
        /// </returns>
        public static long abs(long a)
        {
            return System.Math.Abs(a);
        }

        /// <summary>
        /// Returns the greater of two double values.
        /// </summary>
        /// <param name="a">an argument.
        /// </param><param name="b">another argument.
        /// </param><returns>the larger of a and b.
        /// </returns>
        public static double max(double a, double b)
        {
            return System.Math.Max(a, b);
        }

        /// <summary>
        /// Returns the greater of two float values.
        /// </summary>
        /// <param name="a">an argument.
        /// </param><param name="b">another argument.
        /// </param><returns>the larger of a and b.
        /// </returns>
        public static float max(float a, float b)
        {
            return System.Math.Max(a, b);
        }

        /// <summary>
        /// Returns the greater of two int values.
        /// </summary>
        /// <param name="a">an argument.
        /// </param><param name="b">another argument.
        /// </param><returns>the larger of a and b.
        /// </returns>
        public static int max(int a, int b)
        {
            return System.Math.Max(a, b);
        }

        /// <summary>
        /// Returns the greater of two long values.
        /// </summary>
        /// <param name="a">an argument.
        /// </param><param name="b">another argument.
        /// </param><returns>the larger of a and b.
        /// </returns>
        public static long max(long a, long b)
        {
            return System.Math.Max(a, b);
        }

        /// <summary>
        /// Returns the smaller of two double values.
        /// </summary>
        /// <param name="a">an argument.
        /// </param><param name="b">another argument.
        /// </param><returns>the smaller of a and b.
        /// </returns>
        public static double min(double a, double b)
        {
            return System.Math.Min(a, b);
        }

        /// <summary>
        /// Returns the smaller of two float values.
        /// </summary>
        /// <param name="a">an argument.
        /// </param><param name="b">another argument.
        /// </param><returns>the smaller of a and b.
        /// </returns>
        public static float min(float a, float b)
        {
            return System.Math.Min(a, b);
        }

        /// <summary>
        /// Returns the smaller of two int values.
        /// </summary>
        /// <param name="a">an argument.
        /// </param><param name="b">another argument.
        /// </param><returns>the smaller of a and b.
        /// </returns>
        public static int min(int a, int b)
        {
            return System.Math.Min(a, b);
        }

        /// <summary>
        /// Returns the smaller of two long values.
        /// </summary>
        /// <param name="a">an argument.
        /// </param><param name="b">another argument.
        /// </param><returns>the smaller of a and b.
        /// </returns>
        public static long min(long a, long b)
        {
            return System.Math.Min(a, b);
        }

        /// <summary>
        /// Returns the value of the first argument raised to the power of the second
        /// argument.
        /// </summary>
        /// <param name="a">the base.
        /// </param><param name="b">the exponent.
        /// </param><returns>the value a^b.
        /// </returns>
        public static double pow(double a, double b)
        {
            return System.Math.Pow(a, b);
        }

        /// <summary>
        /// Returns the correctly rounded positive square root of a double value.
        /// </summary>
        /// <param name="a">a value.
        /// </param><returns>the positive square root of a. If the argument is NaN or less
        /// than zero, the result is NaN.
        /// </returns>
        public static double sqrt(double a)
        {
            return System.Math.Sqrt(a);
        }

        /// <summary>
        /// Returns the natural logarithm (base e) of a double value.
        /// </summary>
        /// <param name="a">a value
        /// </param><returns>the value ln a, the natural logarithm of a.
        /// </returns>
        public static double log(double a)
        {
            return System.Math.Log(a);
        }

        /// <summary>
        /// Returns the base 10 logarithm of a double value.
        /// </summary>
        /// <param name="a">a value
        /// </param><returns>the base 10 logarithm of a.
        /// </returns>
        public static double log10(double a)
        {
            return System.Math.Log10(a);
        }

        /// <summary>
        /// Returns the trigonometric sine of an angle.
        /// </summary>
        /// <param name="a">an angle, in radians.
        /// </param><returns>the sine of the argument.
        /// </returns>
        public static double sin(double a)
        {
            return System.Math.Sin(a);
        }

        /// <summary>
        /// Returns the trigonometric cosine of an angle.
        /// </summary>
        /// <param name="a">an angle, in radians.
        /// </param><returns>the cosine of the argument.
        /// </returns>
        public static double cos(double a)
        {
            return System.Math.Cos(a);
        }

        /// <summary>
        /// Returns the trigonometric tangent of an angle.
        /// </summary>
        /// <param name="a">an angle, in radians.
        /// </param><returns>the tangent of the argument.
        /// </returns>
        public static double tan(double a)
        {
            return System.Math.Tan(a);
        }

        /// <summary>
        /// Returns the arc sine of a value; the returned angle is in the range -pi/2
        /// through pi/2.
        /// </summary>
        /// <param name="a">the value whose arc sine is to be returned.
        /// </param><returns>the arc sine of the argument.
        /// </returns>
        public static double asin(double a)
        {
            return System.Math.Asin(a);
        }

        /// <summary>
        /// Returns the arc cosine of a value; the returned angle is in the range 0.0
        /// through pi.
        /// </summary>
        /// <param name="a">the value whose arc cosine is to be returned.
        /// </param><returns>the arc cosine of the argument.
        /// </returns>
        public static double acos(double a)
        {
            return System.Math.Acos(a);
        }

        /// <summary>
        /// Returns the arc tangent of a value; the returned angle is in the range
        /// -pi/2 through pi/2.
        /// </summary>
        /// <param name="a">the value whose arc tangent is to be returned.
        /// </param><returns>the arc tangent of the argument.
        /// </returns>
        public static double atan(double a)
        {
            return System.Math.Atan(a);
        }

        /// <summary>
        /// Returns the closest long to the argument, with ties rounding up.
        /// </summary>
        /// <param name="a">a floating-point value to be rounded to a long.
        /// </param><returns>the value of the argument rounded to the nearest long value.
        /// </returns>
        public static long round(double a)
        {
            // if NaN, the result is 0
            if (Double.compare(a, Double.NaN) == 0)
            {
                return 0;
            }

            // if less than / equal to the corresponding integer type minimal value, the result is equal to that value
            if (Double.compare(a, Double.NEGATIVE_INFINITY) == 0
                || a <= Long.MIN_VALUE)
            {
                return Long.MIN_VALUE;
            }

            // if greater than / equal to the corresponding integer type maximal value, the result is equal to that value
            if (Double.compare(a, Double.POSITIVE_INFINITY) == 0
                || a >= Long.MAX_VALUE)
            {
                return Long.MAX_VALUE;
            }

            // rounding towards zero for negative values
            if (a < 0 && a - System.Math.Truncate(a) <= -0.5)
            {
                return (long)System.Math.Truncate(a);
            }

            // rounding away from zero for positive values
            return (long)System.Math.Round(a, System.MidpointRounding.AwayFromZero);
        }

        /// <summary>
        /// Returns the closest int to the argument, with ties rounding up.
        /// </summary>
        /// <param name="a">a floating-point value to be rounded to an integer.
        /// </param><returns>the value of the argument rounded to the nearest int value.
        /// </returns>
        public static int round(float a)
        {
            // if NaN, the result is 0
            if (Float.compare(a, Float.NaN) == 0)
            {
                return 0;
            }

            // if less than / equal to the corresponding integer type minimal value, the result is equal to that value
            if (Float.compare(a, Float.NEGATIVE_INFINITY) == 0
                || a <= Integer.MIN_VALUE)
            {
                return Integer.MIN_VALUE;
            }

            // if greater than / equal to the corresponding integer type maximal value, the result is equal to that value
            if (Float.compare(a, Float.POSITIVE_INFINITY) == 0
                || a >= Integer.MAX_VALUE)
            {
                return Integer.MAX_VALUE;
            }

            // rounding towards zero for negative values
            if (a < 0 && a - (float)System.Math.Truncate(a) <= -0.5f)
            {
                return (int)System.Math.Truncate(a);
            }

            // rounding away from zero for positive values
            return (int)System.Math.Round(a, System.MidpointRounding.AwayFromZero);
        }

    }

}
