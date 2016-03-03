using System;

namespace JavaClasses {

    /**
     * The Double class wraps a value of the primitive type double in an object.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class Double {
        
        /**
         * A constant holding the positive infinity of type double.
         */
        public const double POSITIVE_INFINITY = 1.0 / 0.0;

        /**
         * A constant holding the negative infinity of type double.
         */
        public const double NEGATIVE_INFINITY = -1.0 / 0.0;

        /**
         * A constant holding a Not-a-Number (NaN) value of type double.
         */
        public const double NaN = 0.0 / 0.0;

        /**
         * A constant holding the largest positive finite value of type double, (2-2^-52)·2^1023.
         */
        public const double MAX_VALUE = 1.7976931348623157e+308;

        /**
         * A constant holding the smallest positive nonzero value of type double, 2^-1074.
         */
        public const double MIN_VALUE = 4.9e-324;

        /**
         * Maximum exponent a finite double variable may have.
         */
        public const int MAX_EXPONENT = 1023;

        /**
         * Minimum exponent a normalized double variable may have.
         */
        public const int MIN_EXPONENT = -1022;

        /**
         * A constant holding the smallest positive normal value of type double, 2^-1022.
         */
        public const double MIN_NORMAL = 2.2250738585072014E-308;
        
        // binární reprezentace záporné nuly (pro účely porovnávání)
        private static readonly long negativeZeroBits = BitConverter.DoubleToInt64Bits(-0.0);

        private double v;

        /**
         * Constructs a newly allocated Double object that represents the primitive double argument.
         */
        public Double(double value) {
            v = value;
        }

        /**
         * Returns the double value of this Double object.
         */
        public double doubleValue() {
            return v;
        }

        /**
         * Compares two Double objects numerically.
         */
        public int compareTo(Double anotherDouble) {
            return compare(v, anotherDouble.v);
        }

        /**
         * Compares the two specified double values.
         */
        public static int compare(double v, double v2) {
            // porovnání hodnoty Not a Number
            if (double.IsNaN(v)) {
                // dvě NaN hodnoty se při tomto způsobu porovnání rovnají
                if (double.IsNaN(v2)) {
                    return 0;
                }

                return 1;
            }

            // hodnota NaN je větší než jakákoliv jiná hodnota (včetně kladného nekonečna)
            if (double.IsNaN(v2)) {
                return -1;
            }

            // porovnání kladné a záporné nuly (kladná je vyhodnocena jako větší)
            if (BitConverter.DoubleToInt64Bits(v) == 0
                && BitConverter.DoubleToInt64Bits(v2) == negativeZeroBits) {
                return 1;
            }

            // porovnání kladné a záporné nuly (obráceně)
            if (BitConverter.DoubleToInt64Bits(v) == negativeZeroBits
                && BitConverter.DoubleToInt64Bits(v2) == 0) {
                return -1;
            }

            // běžné porovnání pro ostatní hodnoty
            return (v > v2 ? 1 : v < v2 ? -1 : 0);
        }

        /**
         * Compares this object against the specified object.
         */
        public bool equals(Object obj) {
            if (obj == null) {
                return false;
            }

            if (GetType() != obj.GetType()) {
                return false;
            }

            double v2 = (obj as Double).v;

            // porovnání hodnoty Not a Number (dvě NaN hodnoty se považují za shodné)
            if (double.IsNaN(v) && double.IsNaN(v2)) {
                return true;
            }

            // porovnání kladné a záporné nuly (považují se za rozdílné hodnoty)
            if (BitConverter.DoubleToInt64Bits(v) == negativeZeroBits) {
                return BitConverter.DoubleToInt64Bits(v2) == negativeZeroBits;
            }

            // porovnání kladné a záporné nuly (obráceně)
            if (BitConverter.DoubleToInt64Bits(v2) == negativeZeroBits) {
                return BitConverter.DoubleToInt64Bits(v) == negativeZeroBits;
            }

            // běžné vyhodnocení rovnosti pro ostatní hodnoty
            return (v == v2);
        }

        public override string ToString() {
            return toString().ToString();
        }

        /**
         * Returns a string representation of this Double object.
         */
        public String toString() {
            return Double.toString(v);
        }

        /**
         * Returns a string representation of the double argument.
         */
        public static String toString(double d) {
            return d.ToString();
        }

        /**
         * Returns a new double initialized to the value represented by the specified String,
         * as performed by the valueOf method of class Double.
         */
        public static double parseDouble(String s) {
            return double.Parse(s.ToString());
        }
    }
}
