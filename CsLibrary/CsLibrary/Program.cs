using System;

namespace JavaClasses {

    class Program {

        private static void printCompareTo(double d1, double d2)
        {
            Console.WriteLine("{0} compareTo {1}: {2}", new Double(d1), new Double(d2), new Double(d1).compareTo(new Double(d2)));
        }

        private static void printEquals(double d1, double d2)
        {
            Console.WriteLine("{0} equals {1}: {2}", new Double(d1), new Double(d2), new Double(d1).equals(new Double(d2)));
        }

        private static void printCompareToF(float f1, float f2)
        {
            Console.WriteLine("{0} equals {1}: {2}", new Float(f1), new Float(f2), new Float(f1).compareTo(new Float(f2)));
        }

        private static void printEqualsF(float f1, float f2)
        {
            Console.WriteLine("{0} equals {1}: {2}", new Float(f1), new Float(f2), new Float(f1).equals(new Float(f2)));
        }

        /**
         * @author Petr Kozler (A13B0359P)
         */
        private static void Main(string[] args)
        {
            /*System_.out_.println("double 0: " + Double.positiveZeroBits);
            System_.out_.println("double -0: " + Double.negativeZeroBits);
            System_.out_.println("float 0: " + Float.positiveZeroBits);
            System_.out_.println("float -0: " + Float.negativeZeroBits);*/

            System_.out_.println("\n=== Java compareTo ===");
            printCompareTo(1.0, 1.0);
            printCompareTo(1.0, -1.0);
            printCompareTo(-1.0, 1.0);
            printCompareTo(-1.0, -1.0);
            printCompareTo(0.0, 0.0);
            printCompareTo(0.0, -0.0);
            printCompareTo(-0.0, 0.0);
            printCompareTo(-0.0, -0.0);
            printCompareTo(double.NaN, double.PositiveInfinity);
            printCompareTo(double.NaN, double.NegativeInfinity);
            printCompareTo(double.PositiveInfinity, double.NaN);
            printCompareTo(double.NegativeInfinity, double.NaN);
            printCompareTo(double.NaN, double.NaN);
            printCompareTo(double.NaN, -double.NaN);

            System_.out_.println("\n=== Java equals ===");
            printEquals(1.0, 1.0);
            printEquals(1.0, -1.0);
            printEquals(-1.0, 1.0);
            printEquals(-1.0, -1.0);
            printEquals(0.0, 0.0);
            printEquals(0.0, -0.0);
            printEquals(-0.0, 0.0);
            printEquals(-0.0, -0.0);
            printEquals(double.NaN, double.PositiveInfinity);
            printEquals(double.NaN, double.NegativeInfinity);
            printEquals(double.PositiveInfinity, double.NaN);
            printEquals(double.NegativeInfinity, double.NaN);
            printEquals(double.NaN, double.NaN);
            printEquals(double.NaN, -double.NaN);

            System_.out_.println("\n=== Java compareTo Float ===");
            printCompareToF(1.0f, 1.0f);
            printCompareToF(1.0f, -1.0f);
            printCompareToF(-1.0f, 1.0f);
            printCompareToF(-1.0f, -1.0f);
            printCompareToF(0.0f, 0.0f);
            printCompareToF(0.0f, -0.0f);
            printCompareToF(-0.0f, 0.0f);
            printCompareToF(-0.0f, -0.0f);
            printCompareToF(float.NaN, float.PositiveInfinity);
            printCompareToF(float.NaN, float.NegativeInfinity);
            printCompareToF(float.PositiveInfinity, float.NaN);
            printCompareToF(float.NegativeInfinity, float.NaN);
            printCompareToF(float.NaN, float.NaN);
            printCompareToF(float.NaN, -float.NaN);

            System_.out_.println("\n=== Java equals float ===");
            printEqualsF(1.0f, 1.0f);
            printEqualsF(1.0f, -1.0f);
            printEqualsF(-1.0f, 1.0f);
            printEqualsF(-1.0f, -1.0f);
            printEqualsF(0.0f, 0.0f);
            printEqualsF(0.0f, -0.0f);
            printEqualsF(-0.0f, 0.0f);
            printEqualsF(-0.0f, -0.0f);
            printEqualsF(float.NaN, float.PositiveInfinity);
            printEqualsF(float.NaN, float.NegativeInfinity);
            printEqualsF(float.PositiveInfinity, float.NaN);
            printEqualsF(float.NegativeInfinity, float.NaN);
            printEqualsF(float.NaN, float.NaN);
            printEqualsF(float.NaN, -float.NaN);

            Scanner sc = new Scanner(System_.in_);
            sc.nextLine();

            /*
			int i = sc.nextInt();
			System_.@out.println (i);
            ArrayList<String> arrayList = new ArrayList<String>();
            arrayList.add("first");
            arrayList.add("second");
            arrayList.add("third");
            System_.out_.println(arrayList.toString());
            */
        }
    }
}
