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
         */
        public static double abs(double a) {
            return System.Math.Abs(a);
        }

        /**
         * Returns the absolute value of a float value.
         */
        public static float abs(float a) {
            return System.Math.Abs(a);
        }

        /**
         * Returns the absolute value of an int value.
         */
        public static int abs(int a) {
            return System.Math.Abs(a);
        }

        /**
         * Returns the absolute value of a long value.
         */
        public static long abs(long a) {
            return System.Math.Abs(a);
        }

        /**
         * Returns the greater of two double values.
         */
        public static double max(double a, double b) {
            return System.Math.Max(a, b);
        }

        /**
         * Returns the greater of two float values.
         */
        public static float max(float a, float b) {
            return System.Math.Max(a, b);
        }

        /**
         * Returns the greater of two int values.
         */
        public static int max(int a, int b) {
            return System.Math.Max(a, b);
        }

        /**
         * Returns the greater of two long values.
         */
        public static long max(long a, long b) {
            return System.Math.Max(a, b);
        }

        /**
         * Returns the smaller of two double values.
         */
        public static double min(double a, double b) {
            return System.Math.Min(a, b);
        }

        /**
         * Returns the smaller of two float values.
         */
        public static float min(float a, float b) {
            return System.Math.Min(a, b);
        }

        /**
         * Returns the smaller of two int values.
         */
        public static int min(int a, int b) {
            return System.Math.Min(a, b);
        }

        /**
         * Returns the smaller of two long values.
         */
        public static long min(long a, long b) {
            return System.Math.Min(a, b);
        }

        /**
         * Returns the value of the first argument raised to the power of the second argument.
         */
        public static double pow(double a, double b) {
            return System.Math.Pow(a, b);
        }

        /**
         * Returns the correctly rounded positive square root of a double value.
         */
        public static double sqrt(double a) {
            return System.Math.Sqrt(a);
        }

        /**
         * Returns the natural logarithm (base e) of a double value.
         */
        public static double log(double a) {
            return System.Math.Log(a);
        }

        /**
         * Returns the base 10 logarithm of a double value.
         */
        public static double log10(double a) {
            return System.Math.Log10(a);
        }

        /**
         * Returns the trigonometric sine of an angle.
         */
        public static double sin(double a) {
            return System.Math.Sin(a);
        }

        /**
         * Returns the trigonometric cosine of an angle.
         */
        public static double cos(double a) {
            return System.Math.Cos(a);
        }

        /**
         * Returns the trigonometric tangent of an angle.
         */
        public static double tan(double a) {
            return System.Math.Tan(a);
        }

        /**
         * Returns the arc sine of a value; the returned angle is in the range -pi/2 through pi/2.
         */
        public static double asin(double a) {
            return System.Math.Asin(a);
        }

        /**
         * Returns the arc cosine of a value; the returned angle is in the range 0.0 through pi.
         */
        public static double acos(double a) {
            return System.Math.Acos(a);
        }

        /**
         * Returns the arc tangent of a value; the returned angle is in the range -pi/2 through pi/2.
         */
        public static double atan(double a) {
            return System.Math.Atan(a);
        }

        /**
         * Returns the closest long to the argument, with ties rounding up.
         */
        public static long round(double a) {
            return (long)System.Math.Round(a);
        }

        /**
         * Returns the closest int to the argument, with ties rounding up.
         */
        public static int round(float a) {
            return (int)System.Math.Round(a);
        }
    }
}
