namespace JavaClasses {

    /**
     * The class Math contains methods for performing basic numeric operations such as the elementary exponential,
     * logarithm, square root, and trigonometric functions.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public static class Math {

        /**
         * The double value that is closer than any other to e, the base of the natural logarithms.
         */
        public const double E = 2.7182818284590452354;

        /**
         * The double value that is closer than any other to pi, the ratio of the circumference of a circle to its diameter.
         */
        public const double PI = 3.14159265358979323846;

        /**
         * Returns the absolute value of a double value.
         *
         * @param a the argument whose absolute value is to be determined
         * @return the absolute value of the argument.
         */
        public static double abs(double a) {
            return System.Math.Abs(a);
        }

        /**
         * Returns the absolute value of a float value.
         *
         * @param a the argument whose absolute value is to be determined
         * @return the absolute value of the argument.
         */
        public static float abs(float a) {
            return System.Math.Abs(a);
        }

        /**
         * Returns the absolute value of an int value.
         *
         * @param a the argument whose absolute value is to be determined
         * @return the absolute value of the argument.
         */
        public static int abs(int a) {
            return System.Math.Abs(a);
        }

        /**
         * Returns the absolute value of a long value.
         *
         * @param a the argument whose absolute value is to be determined
         * @return the absolute value of the argument.
         */
        public static long abs(long a) {
            return System.Math.Abs(a);
        }

        /**
         * Returns the greater of two double values.
         *
         * @param a an argument.
         * @param b another argument.
         * @return the larger of a and b.
         */
        public static double max(double a, double b) {
            return System.Math.Max(a, b);
        }

        /**
         * Returns the greater of two float values.
         *
         * @param a an argument.
         * @param b another argument.
         * @return the larger of a and b.
         */
        public static float max(float a, float b) {
            return System.Math.Max(a, b);
        }

        /**
         * Returns the greater of two int values.
         *
         * @param a an argument.
         * @param b another argument.
         * @return the larger of a and b.
         */
        public static int max(int a, int b) {
            return System.Math.Max(a, b);
        }

        /**
         * Returns the greater of two long values.
         *
         * @param a an argument.
         * @param b another argument.
         * @return the larger of a and b.
         */
        public static long max(long a, long b) {
            return System.Math.Max(a, b);
        }

        /**
         * Returns the smaller of two double values.
         *
         * @param a an argument.
         * @param b another argument.
         * @return the smaller of a and b.
         */
        public static double min(double a, double b) {
            return System.Math.Min(a, b);
        }

        /**
         * Returns the smaller of two float values.
         *
         * @param a an argument.
         * @param b another argument.
         * @return the smaller of a and b.
         */
        public static float min(float a, float b) {
            return System.Math.Min(a, b);
        }

        /**
         * Returns the smaller of two int values.
         *
         * @param a an argument.
         * @param b another argument.
         * @return the smaller of a and b.
         */
        public static int min(int a, int b) {
            return System.Math.Min(a, b);
        }

        /**
         * Returns the smaller of two long values.
         *
         * @param a an argument.
         * @param b another argument.
         * @return the smaller of a and b.
         */
        public static long min(long a, long b) {
            return System.Math.Min(a, b);
        }

        /**
         * Returns the value of the first argument raised to the power of the second
         * argument.
         *
         * @param a the base.
         * @param b the exponent.
         * @return the value a^b.
         */
        public static double pow(double a, double b) {
            return System.Math.Pow(a, b);
        }

        /**
         * Returns the correctly rounded positive square root of a double value.
         *
         * @param a a value.
         * @return the positive square root of a. If the argument is NaN or less
         * than zero, the result is NaN.
         */
        public static double sqrt(double a) {
            return System.Math.Sqrt(a);
        }

        /**
         * Returns the natural logarithm (base e) of a double value.
         *
         * @param a a value
         * @return the value ln a, the natural logarithm of a.
         */
        public static double log(double a) {
            return System.Math.Log(a);
        }

        /**
         * Returns the base 10 logarithm of a double value.
         *
         * @param a a value
         * @return the base 10 logarithm of a.
         */
        public static double log10(double a) {
            return System.Math.Log10(a);
        }

        /**
         * Returns the trigonometric sine of an angle.
         *
         * @param a an angle, in radians.
         * @return the sine of the argument.
         */
        public static double sin(double a) {
            return System.Math.Sin(a);
        }

        /**
         * Returns the trigonometric cosine of an angle.
         *
         * @param a an angle, in radians.
         * @return the cosine of the argument.
         */
        public static double cos(double a) {
            return System.Math.Cos(a);
        }

        /**
         * Returns the trigonometric tangent of an angle.
         *
         * @param a an angle, in radians.
         * @return the tangent of the argument.
         */
        public static double tan(double a) {
            return System.Math.Tan(a);
        }

        /**
         * Returns the arc sine of a value; the returned angle is in the range -pi/2
         * through pi/2.
         *
         * @param a the value whose arc sine is to be returned.
         * @return the arc sine of the argument.
         */
        public static double asin(double a) {
            return System.Math.Asin(a);
        }

        /**
         * Returns the arc cosine of a value; the returned angle is in the range 0.0
         * through pi.
         *
         * @param a the value whose arc cosine is to be returned.
         * @return the arc cosine of the argument.
         */
        public static double acos(double a) {
            return System.Math.Acos(a);
        }

        /**
         * Returns the arc tangent of a value; the returned angle is in the range
         * -pi/2 through pi/2.
         *
         * @param a the value whose arc tangent is to be returned.
         * @return the arc tangent of the argument.
         */
        public static double atan(double a) {
            return System.Math.Atan(a);
        }

        /**
         * Returns the closest long to the argument, with ties rounding up.
         *
         * @param a a floating-point value to be rounded to a long.
         * @return the value of the argument rounded to the nearest long value.
         */
        public static long round(double a) {
            return (long) System.Math.Round(a);
        }

        /**
         * Returns the closest int to the argument, with ties rounding up.
         *
         * @param a a floating-point value to be rounded to an integer.
         * @return the value of the argument rounded to the nearest int value.
         */
        public static int round(float a) {
            return (int) System.Math.Round(a);
        }

    }

}
