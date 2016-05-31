using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
    [TestClass]
    public class ArraysTest
    {

        /// <summary>
        /// Tests the binarySearch method with array of bytes.
        /// </summary>
        [TestMethod]
        public void binarySearchTest()
        {
            sbyte[] a;
            int b;
            a = new sbyte[] { (sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6 };
            Arrays.sort(a);
            // existing element search
            b = Arrays.binarySearch(a, (sbyte)8);
            Assert.AreEqual(4, b);
            // non-existent element search
            b = Arrays.binarySearch(a, (sbyte)4);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of bytes and indexes as
        /// parameters.
        /// </summary>
        [TestMethod]
        public void binarySearchTest2()
        {
            sbyte[] a;
            int b;
            a = new sbyte[] { (sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6 };
            Arrays.sort(a);
            // existing element search
            b = Arrays.binarySearch(a, 1, 4, (sbyte)8);
            Assert.AreEqual(-5, b);
            // non-existent element search in a part of array
            b = Arrays.binarySearch(a, 1, 4, (sbyte)4);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of chars.
        /// </summary>
        [TestMethod]
        public void binarySearchTest3()
        {
            char[] a;
            int b;
            a = new char[] { 'c', 'b', 'h', 'g', 'f' };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 'h');
            Assert.AreEqual(4, b);
            b = Arrays.binarySearch(a, 'd');
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of chars and indexes as
        /// parameters.
        /// </summary>
        [TestMethod]
        public void binarySearchTest4()
        {
            char[] a;
            int b;
            a = new char[] { 'c', 'b', 'h', 'g', 'f' };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 1, 4, 'h');
            Assert.AreEqual(-5, b);
            b = Arrays.binarySearch(a, 1, 4, 'd');
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of doubles.
        /// </summary>
        [TestMethod]
        public void binarySearchTest5()
        {
            double[] a;
            int b;
            a = new double[] { 3.0, 2.0, 8.0, 7.0, 6.0 };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 8.0);
            Assert.AreEqual(4, b);
            b = Arrays.binarySearch(a, 4.0);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of doubles and indexes as
        /// parameters.
        /// </summary>
        [TestMethod]
        public void binarySearchTest6()
        {
            double[] a;
            int b;
            a = new double[] { 3.0, 2.0, 8.0, 7.0, 6.0 };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 1, 4, 8.0);
            Assert.AreEqual(-5, b);
            b = Arrays.binarySearch(a, 1, 4, 4.0);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of floats.
        /// </summary>
        [TestMethod]
        public void binarySearchTest7()
        {
            float[] a;
            int b;
            a = new float[] { 3.0F, 2.0F, 8.0F, 7.0F, 6.0F };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 8.0F);
            Assert.AreEqual(4, b);
            b = Arrays.binarySearch(a, 4.0F);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of floats and indexes as
        /// parameters.
        /// </summary>
        [TestMethod]
        public void binarySearchTest8()
        {
            float[] a;
            int b;
            a = new float[] { 3.0F, 2.0F, 8.0F, 7.0F, 6.0F };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 1, 4, 8.0F);
            Assert.AreEqual(-5, b);
            b = Arrays.binarySearch(a, 1, 4, 4.0F);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of ints.
        /// </summary>
        [TestMethod]
        public void binarySearchTest9()
        {
            int[] a;
            int b;
            a = new int[] { 3, 2, 8, 7, 6 };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 8);
            Assert.AreEqual(4, b);
            b = Arrays.binarySearch(a, 4);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of ints and indexes as
        /// parameters.
        /// </summary>
        [TestMethod]
        public void binarySearchTest10()
        {
            int[] a;
            int b;
            a = new int[] { 3, 2, 8, 7, 6 };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 1, 4, 8);
            Assert.AreEqual(-5, b);
            b = Arrays.binarySearch(a, 1, 4, 4);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of longs.
        /// </summary>
        [TestMethod]
        public void binarySearchTest11()
        {
            long[] a;
            int b;
            a = new long[] { 3L, 2L, 8L, 7L, 6L };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 8L);
            Assert.AreEqual(4, b);
            b = Arrays.binarySearch(a, 4L);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of longs and indexes as
        /// parameters.
        /// </summary>
        [TestMethod]
        public void binarySearchTest12()
        {
            long[] a;
            int b;
            a = new long[] { 3L, 2L, 8L, 7L, 6L };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 1, 4, 8L);
            Assert.AreEqual(-5, b);
            b = Arrays.binarySearch(a, 1, 4, 4L);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of objects.
        /// </summary>
        [TestMethod]
        public void binarySearchTest13()
        {
            TestObject[] a;
            int b;
            a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, new TestObject("sixth", 6));
            Assert.AreEqual(4, b);
            b = Arrays.binarySearch(a, new TestObject("sixth", 4));
            Assert.AreEqual(-5, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of objects and indexes as
        /// parameters.
        /// </summary>
        [TestMethod]
        public void binarySearchTest14()
        {
            TestObject[] a;
            int b;
            a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 1, 4, new TestObject("sixth", 6));
            Assert.AreEqual(-5, b);
            b = Arrays.binarySearch(a, 1, 4, new TestObject("sixth", 4));
            Assert.AreEqual(-5, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of shorts.
        /// </summary>
        [TestMethod]
        public void binarySearchTest15()
        {
            short[] a;
            int b;
            a = new short[] { (short)3, (short)2, (short)8, (short)7, (short)6 };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, (short)8);
            Assert.AreEqual(4, b);
            b = Arrays.binarySearch(a, (short)4);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of shorts and indexes as
        /// parameters.
        /// </summary>
        [TestMethod]
        public void binarySearchTest16()
        {
            short[] a;
            int b;
            a = new short[] { (short)3, (short)2, (short)8, (short)7, (short)6 };
            Arrays.sort(a);
            b = Arrays.binarySearch(a, 1, 4, (short)8);
            Assert.AreEqual(-5, b);
            b = Arrays.binarySearch(a, 1, 4, (short)4);
            Assert.AreEqual(-3, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of objects and comparator as a
        /// parameter.
        /// </summary>
        [TestMethod]
        public void binarySearchTest17()
        {
            TestObject[] a;
            int b;
            TestObjectComparator c;
            a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
            c = new TestObjectComparator();
            Arrays.sort(a, c);
            b = Arrays.binarySearch(a, new TestObject("sixth", 6), c);
            Assert.AreEqual(4, b);
            b = Arrays.binarySearch(a, new TestObject("sixth", 4), c);
            Assert.AreEqual(-5, b);
        }

        /// <summary>
        /// Tests the binarySearch method with array of shorts and indexes and
        /// comparator as parameters.
        /// </summary>
        [TestMethod]
        public void binarySearchTest18()
        {
            TestObject[] a;
            int b;
            TestObjectComparator c;
            a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
            c = new TestObjectComparator();
            Arrays.sort(a, c);
            b = Arrays.binarySearch(a, 1, 4, new TestObject("sixth", 6), c);
            Assert.AreEqual(-5, b);
            b = Arrays.binarySearch(a, 1, 4, new TestObject("sixth", 4), c);
            Assert.AreEqual(-5, b);
        }

        /// <summary>
        /// Tests the copyOf method with array of booleans.
        /// </summary>
        [TestMethod]
        public void copyOfTest()
        {
            bool[] a, b;
            bool c;
            a = new bool[] { true, false, false, false, true };
            // new array is smaller
            b = Arrays.copyOf(a, 3);
            c = Arrays.equals(b, new bool[] {true, false, false});
            Assert.AreEqual(true, c);
            // new array has the same length
            b = Arrays.copyOf(a, 5);
            c = Arrays.equals(b, new bool[] {true, false, false, false, true});
            Assert.AreEqual(true, c);
            // new array is bigger
            b = Arrays.copyOf(a, 7);
            c = Arrays.equals(b, new bool[] {true, false, false, false, true, false, false});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOf method with array of bytes.
        /// </summary>
        [TestMethod]
        public void copyOfTest2()
        {
            sbyte[] a, b;
            bool c;
            a = new sbyte[] { (sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6 };
            b = Arrays.copyOf(a, 3);
            c = Arrays.equals(b, new sbyte[] {3, 2, 8});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 5);
            c = Arrays.equals(b, new sbyte[] {3, 2, 8, 7, 6});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 7);
            c = Arrays.equals(b, new sbyte[] {3, 2, 8, 7, 6, 0, 0});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOf method with array of chars.
        /// </summary>
        [TestMethod]
        public void copyOfTest3()
        {
            char[] a, b;
            bool c;
            a = new char[] { 'c', 'b', 'h', 'g', 'f' };
            b = Arrays.copyOf(a, 3);
            c = Arrays.equals(b, new char[] {'c', 'b', 'h'});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 5);
            c = Arrays.equals(b, new char[] {'c', 'b', 'h', 'g', 'f'});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 7);
            c = Arrays.equals(b, new char[] {'c', 'b', 'h', 'g', 'f', '\0', '\0' });
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOf method with array of doubles.
        /// </summary>
        [TestMethod]
        public void copyOfTest4()
        {
            double[] a, b;
            bool c;
            a = new double[] { 3.0, 2.0, 8.0, 7.0, 6.0 };
            b = Arrays.copyOf(a, 3);
            c = Arrays.equals(b, new double[] {3.0, 2.0, 8.0});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 5);
            c = Arrays.equals(b, new double[] {3.0, 2.0, 8.0, 7.0, 6.0});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 7);
            c = Arrays.equals(b, new double[] {3.0, 2.0, 8.0, 7.0, 6.0, 0.0, 0.0});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOf method with array of floats.
        /// </summary>
        [TestMethod]
        public void copyOfTest5()
        {
            float[] a, b;
            bool c;
            a = new float[] { 3.0F, 2.0F, 8.0F, 7.0F, 6.0F };
            b = Arrays.copyOf(a, 3);
            c = Arrays.equals(b, new float[] {3.0F, 2.0F, 8.0F});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 5);
            c = Arrays.equals(b, new float[] {3.0F, 2.0F, 8.0F, 7.0F, 6.0F});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 7);
            c = Arrays.equals(b, new float[] {3.0F, 2.0F, 8.0F, 7.0F, 6.0F, 0.0F, 0.0F});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOf method with array of ints.
        /// </summary>
        [TestMethod]
        public void copyOfTest6()
        {
            int[] a, b;
            bool c;
            a = new int[] { 3, 2, 8, 7, 6 };
            b = Arrays.copyOf(a, 3);
            c = Arrays.equals(b, new int[] {3, 2, 8});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 5);
            c = Arrays.equals(b, new int[] {3, 2, 8, 7, 6});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 7);
            c = Arrays.equals(b, new int[] {3, 2, 8, 7, 6, 0, 0});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOf method with array of longs.
        /// </summary>
        [TestMethod]
        public void copyOfTest7()
        {
            long[] a, b;
            bool c;
            a = new long[] { 3L, 2L, 8L, 7L, 6L };
            b = Arrays.copyOf(a, 3);
            c = Arrays.equals(b, new long[] {3, 2, 8});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 5);
            c = Arrays.equals(b, new long[] {3, 2, 8, 7, 6});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 7);
            c = Arrays.equals(b, new long[] {3, 2, 8, 7, 6, 0, 0});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOf method with array of shorts.
        /// </summary>
        [TestMethod]
        public void copyOfTest8()
        {
            short[] a, b;
            bool c;
            a = new short[] { (short)3, (short)2, (short)8, (short)7, (short)6 };
            b = Arrays.copyOf(a, 3);
            c = Arrays.equals(b, new short[] {3, 2, 8});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 5);
            c = Arrays.equals(b, new short[] {3, 2, 8, 7, 6});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 7);
            c = Arrays.equals(b, new short[] {3, 2, 8, 7, 6, 0, 0});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOf method with array of objects.
        /// </summary>
        [TestMethod]
        public void copyOfTest9()
        {
            TestObject[] a, b;
            bool c;
            a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),};
            b = Arrays.copyOf(a, 3);
            c = Arrays.equals(b, new TestObject[] {new TestObject("first", 3), new TestObject("second", 2), new TestObject("third", 8)});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 5);
            c = Arrays.equals(b, new TestObject[] {new TestObject("first", 3), new TestObject("second", 2), new TestObject("third", 8), new TestObject("fourth", 7), new TestObject("fifth", 6)});
            Assert.AreEqual(true, c);
            b = Arrays.copyOf(a, 7);
            c = Arrays.equals(b, new TestObject[] {new TestObject("first", 3), new TestObject("second", 2), new TestObject("third", 8), new TestObject("fourth", 7), new TestObject("fifth", 6), null, null});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOfRange method with array of booleans.
        /// </summary>
        [TestMethod]
        public void copyOfRangeTest1()
        {
            bool[] a, b;
            bool c;
            a = new bool[] { true, false, false, false, true };
            // copy from the beginning
            b = Arrays.copyOfRange(a, 0, 3);
            c = Arrays.equals(b, new bool[] {true, false, false});
            Assert.AreEqual(true, c);
            // copy from the middle
            b = Arrays.copyOfRange(a, 2, 5);
            c = Arrays.equals(b, new bool[] {false, false, true});
            Assert.AreEqual(true, c);
            // copy from the end
            b = Arrays.copyOfRange(a, 4, 7);
            c = Arrays.equals(b, new bool[] {true, false, false});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOfRange method with array of bytes.
        /// </summary>
        [TestMethod]
        public void copyOfRangeTest2()
        {
            sbyte[] a, b;
            bool c;
            a = new sbyte[] { (sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6 };
            b = Arrays.copyOfRange(a, 0, 3);
            c = Arrays.equals(b, new sbyte[] {3, 2, 8});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 2, 5);
            c = Arrays.equals(b, new sbyte[] {8, 7, 6});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 4, 7);
            c = Arrays.equals(b, new sbyte[] {6, 0, 0});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOfRange method with array of chars.
        /// </summary>
        [TestMethod]
        public void copyOfRangeTest3()
        {
            char[] a, b;
            bool c;
            a = new char[] { 'c', 'b', 'h', 'g', 'f' };
            b = Arrays.copyOfRange(a, 0, 3);
            c = Arrays.equals(b, new char[] {'c', 'b', 'h'});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 2, 5);
            c = Arrays.equals(b, new char[] {'h', 'g', 'f'});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 4, 7);
            c = Arrays.equals(b, new char[] {'f', '\0', '\0' });
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOfRange method with array of doubles.
        /// </summary>
        [TestMethod]
        public void copyOfRangeTest4()
        {
            double[] a, b;
            bool c;
            a = new double[] { 3.0, 2.0, 8.0, 7.0, 6.0 };
            b = Arrays.copyOfRange(a, 0, 3);
            c = Arrays.equals(b, new double[] {3.0, 2.0, 8.0});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 2, 5);
            c = Arrays.equals(b, new double[] {8.0, 7.0, 6.0});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 4, 7);
            c = Arrays.equals(b, new double[] {6.0, 0.0, 0.0});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOfRange method with array of floats.
        /// </summary>
        [TestMethod]
        public void copyOfRangeTest5()
        {
            float[] a, b;
            bool c;
            a = new float[] { 3.0F, 2.0F, 8.0F, 7.0F, 6.0F };
            b = Arrays.copyOfRange(a, 0, 3);
            c = Arrays.equals(b, new float[] {3.0F, 2.0F, 8.0F});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 2, 5);
            c = Arrays.equals(b, new float[] {8.0F, 7.0F, 6.0F});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 4, 7);
            c = Arrays.equals(b, new float[] {6.0F, 0.0F, 0.0F});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOfRange method with array of ints.
        /// </summary>
        [TestMethod]
        public void copyOfRangeTest6()
        {
            int[] a, b;
            bool c;
            a = new int[] { 3, 2, 8, 7, 6 };
            b = Arrays.copyOfRange(a, 0, 3);
            c = Arrays.equals(b, new int[] {3, 2, 8});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 2, 5);
            c = Arrays.equals(b, new int[] {8, 7, 6});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 4, 7);
            c = Arrays.equals(b, new int[] {6, 0, 0});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOfRange method with array of longs.
        /// </summary>
        [TestMethod]
        public void copyOfRangeTest7()
        {
            long[] a, b;
            bool c;
            a = new long[] { 3L, 2L, 8L, 7L, 6L };
            b = Arrays.copyOfRange(a, 0, 3);
            c = Arrays.equals(b, new long[] {3, 2, 8});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 2, 5);
            c = Arrays.equals(b, new long[] {8, 7, 6});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 4, 7);
            c = Arrays.equals(b, new long[] {6, 0, 0});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOfRange method with array of shorts.
        /// </summary>
        [TestMethod]
        public void copyOfRangeTest8()
        {
            short[] a, b;
            bool c;
            a = new short[] { (short)3, (short)2, (short)8, (short)7, (short)6 };
            b = Arrays.copyOfRange(a, 0, 3);
            c = Arrays.equals(b, new short[] {3, 2, 8});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 2, 5);
            c = Arrays.equals(b, new short[] {8, 7, 6});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 4, 7);
            c = Arrays.equals(b, new short[] {6, 0, 0});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the copyOfRange method with array of objects.
        /// </summary>
        [TestMethod]
        public void copyOfRangeTest9()
        {
            TestObject[] a, b;
            bool c;
            a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),};
            b = Arrays.copyOfRange(a, 0, 3);
            c = Arrays.equals(b, new TestObject[] {new TestObject("first", 3), new TestObject("second", 2), new TestObject("third", 8)});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 2, 5);
            c = Arrays.equals(b, new TestObject[] {new TestObject("third", 8), new TestObject("fourth", 7), new TestObject("fifth", 6)});
            Assert.AreEqual(true, c);
            b = Arrays.copyOfRange(a, 4, 7);
            c = Arrays.equals(b, new TestObject[] {new TestObject("fifth", 6), null, null});
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the equals method with array of booleans.
        /// </summary>
        [TestMethod]
        public void equalsTest()
        {
            bool[] a, b;
            bool c;
            a = new bool[] { true, false, false, false, true };
            // reference to the second array is null
            b = null;
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            // arrays do not have the same length
            b = new bool[] { true };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            // arrays have the same length but different elements
            b = new bool[] { true, false, false, false, false };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            // arrays have the same length and elements
            b = new bool[] { true, false, false, false, true };
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
            // references are equal
            b = a;
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the equals method with array of bytes.
        /// </summary>
        [TestMethod]
        public void equalsTest2()
        {
            sbyte[] a, b;
            bool c;
            a = new sbyte[] { (sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6 };
            b = null;
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new sbyte[] { (sbyte)3 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new sbyte[] { (sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)3 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new sbyte[] { (sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
            b = a;
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the equals method with array of chars.
        /// </summary>
        [TestMethod]
        public void equalsTest3()
        {
            char[] a, b;
            bool c;
            a = new char[] { 'c', 'b', 'h', 'g', 'f' };
            b = null;
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new char[] { 'c' };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new char[] { 'c', 'b', 'h', 'g', 'c' };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new char[] { 'c', 'b', 'h', 'g', 'f' };
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
            b = a;
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the equals method with array of doubles.
        /// </summary>
        [TestMethod]
        public void equalsTest4()
        {
            double[] a, b;
            bool c;
            a = new double[] { 3.0, 2.0, 8.0, 7.0, 6.0 };
            b = null;
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new double[] { 3.0 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new double[] { 3.0, 2.0, 8.0, 7.0, 3.0 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new double[] { 3.0, 2.0, 8.0, 7.0, 6.0 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
            b = a;
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the equals method with array of floats.
        /// </summary>
        [TestMethod]
        public void equalsTest5()
        {
            float[] a, b;
            bool c;
            a = new float[] { 3.0F, 2.0F, 8.0F, 7.0F, 6.0F };
            b = null;
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new float[] { 3.0F };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new float[] { 3.0F, 2.0F, 8.0F, 7.0F, 3.0F };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new float[] { 3.0F, 2.0F, 8.0F, 7.0F, 6.0F };
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
            b = a;
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the equals method with array of ints.
        /// </summary>
        [TestMethod]
        public void equalsTest6()
        {
            int[] a, b;
            bool c;
            a = new int[] { 3, 2, 8, 7, 6 };
            b = null;
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new int[] { 3 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new int[] { 3, 2, 8, 7, 3 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new int[] { 3, 2, 8, 7, 6 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
            b = a;
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the equals method with array of longs.
        /// </summary>
        [TestMethod]
        public void equalsTest7()
        {
            long[] a, b;
            bool c;
            a = new long[] { 3L, 2L, 8L, 7L, 6L };
            b = null;
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new long[] { 3L };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new long[] { 3L, 2L, 8L, 7L, 3L };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new long[] { 3L, 2L, 8L, 7L, 6L };
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
            b = a;
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the equals method with array of objects.
        /// </summary>
        [TestMethod]
        public void equalsTest8()
        {
            TestObject[] a, b;
            bool c;
            a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),};
            b = null;
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            a = new TestObject[]{
            new TestObject("first", 3)
        };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 3),};
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new TestObject[]{
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = a;
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the equals method with array of shorts.
        /// </summary>
        [TestMethod]
        public void equalsTest9()
        {
            short[] a, b;
            bool c;
            a = new short[] { (short)3, (short)2, (short)8, (short)7, (short)6 };
            b = null;
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new short[] { (short)3 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new short[] { (short)3, (short)2, (short)8, (short)7, (short)3 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(false, c);
            b = new short[] { (short)3, (short)2, (short)8, (short)7, (short)6 };
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
            b = a;
            c = Arrays.equals(a, b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the fill method with array of booleans.
        /// </summary>
        [TestMethod]
        public void fillTest()
        {
            bool[] a;
            bool b;
            // the array for filling
            a = new bool[5];
            Arrays.fill(a, true);
            b = Arrays.equals(a, new bool[] {true, true, true, true, true});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of booleans and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void fillTest2()
        {
            bool[] a;
            bool b;
            // the array for partial filling
            a = new bool[5];
            Arrays.fill(a, 1, 4, true);
            b = Arrays.equals(a, new bool[] {false, true, true, true, false});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of bytes.
        /// </summary>
        [TestMethod]
        public void fillTest3()
        {
            sbyte[] a;
            bool b;
            a = new sbyte[5];
            Arrays.fill(a, (sbyte)8);
            b = Arrays.equals(a, new sbyte[] {8, 8, 8, 8, 8});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of bytes and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void fillTest4()
        {
            sbyte[] a;
            bool b;
            a = new sbyte[5];
            Arrays.fill(a, 1, 4, (sbyte)8);
            b = Arrays.equals(a, new sbyte[] {0, 8, 8, 8, 0});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of chars.
        /// </summary>
        [TestMethod]
        public void fillTest5()
        {
            char[] a;
            bool b;
            a = new char[5];
            Arrays.fill(a, 'h');
            b = Arrays.equals(a, new char[] {'h', 'h', 'h', 'h', 'h'});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of chars and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void fillTest6()
        {
            char[] a;
            bool b;
            a = new char[5];
            Arrays.fill(a, 1, 4, 'h');
            b = Arrays.equals(a, new char[] {'\0', 'h', 'h', 'h', '\0'});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of doubles.
        /// </summary>
        [TestMethod]
        public void fillTest7()
        {
            double[] a;
            bool b;
            a = new double[5];
            Arrays.fill(a, 8.0);
            b = Arrays.equals(a, new double[] {8.0, 8.0, 8.0, 8.0, 8.0});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of doubles and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void fillTest8()
        {
            double[] a;
            bool b;
            a = new double[5];
            Arrays.fill(a, 1, 4, 8.0);
            b = Arrays.equals(a, new double[] {0.0, 8.0, 8.0, 8.0, 0.0});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of floats.
        /// </summary>
        [TestMethod]
        public void fillTest9()
        {
            float[] a;
            bool b;
            a = new float[5];
            Arrays.fill(a, 8.0F);
            b = Arrays.equals(a, new float[] {8.0F, 8.0F, 8.0F, 8.0F, 8.0F});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of floats and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void fillTest10()
        {
            float[] a;
            bool b;
            a = new float[5];
            Arrays.fill(a, 1, 4, 8.0F);
            b = Arrays.equals(a, new float[] {0.0F, 8.0F, 8.0F, 8.0F, 0.0F});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of ints.
        /// </summary>
        [TestMethod]
        public void fillTest11()
        {
            int[] a;
            bool b;
            a = new int[5];
            Arrays.fill(a, 8);
            b = Arrays.equals(a, new int[] {8, 8, 8, 8, 8});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of ints and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void fillTest12()
        {
            int[] a;
            bool b;
            a = new int[5];
            Arrays.fill(a, 1, 4, 8);
            b = Arrays.equals(a, new int[] {0, 8, 8, 8, 0});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of longs.
        /// </summary>
        [TestMethod]
        public void fillTest13()
        {
            long[] a;
            bool b;
            a = new long[5];
            Arrays.fill(a, 8L);
            b = Arrays.equals(a, new long[] {8, 8, 8, 8, 8});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of longs and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void fillTest14()
        {
            long[] a;
            bool b;
            a = new long[5];
            Arrays.fill(a, 1, 4, 8L);
            b = Arrays.equals(a, new long[] {0, 8, 8, 8, 0});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of objects.
        /// </summary>
        [TestMethod]
        public void fillTest15()
        {
            TestObject[] a;
            bool b;
            a = new TestObject[5];
            Arrays.fill(a, new TestObject("sixth", 6));
            b = Arrays.equals(a, new TestObject[] {new TestObject("sixth", 6), new TestObject("sixth", 6), new TestObject("sixth", 6), new TestObject("sixth", 6), new TestObject("sixth", 6)});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of objects and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void fillTest16()
        {
            TestObject[] a;
            bool b;
            a = new TestObject[5];
            Arrays.fill(a, 1, 4, new TestObject("sixth", 6));
            b = Arrays.equals(a, new TestObject[] {null, new TestObject("sixth", 6), new TestObject("sixth", 6), new TestObject("sixth", 6), null});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of shorts.
        /// </summary>
        [TestMethod]
        public void fillTest17()
        {
            short[] a;
            bool b;
            a = new short[5];
            Arrays.fill(a, (short)8);
            b = Arrays.equals(a, new short[] {8, 8, 8, 8, 8});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the fill method with array of shorts and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void fillTest18()
        {
            short[] a;
            bool b;
            a = new short[5];
            Arrays.fill(a, 1, 4, (short)8);
            b = Arrays.equals(a, new short[] {0, 8, 8, 8, 0});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of bytes.
        /// </summary>
        [TestMethod]
        public void sortTest()
        {
            sbyte[] a;
            bool b;
            // the array for sorting
            a = new sbyte[] { (sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6 };
            Arrays.sort(a);
            b = Arrays.equals(a, new sbyte[] {2, 3, 6, 7, 8});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of bytes and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void sortTest2()
        {
            sbyte[] a;
            bool b;
            // the array for partial sorting
            a = new sbyte[] { (sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6 };
            Arrays.sort(a, 1, 4);
            b = Arrays.equals(a, new sbyte[] {3, 2, 7, 8, 6});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of chars.
        /// </summary>
        [TestMethod]
        public void sortTest3()
        {
            char[] a;
            bool b;
            a = new char[] { 'c', 'b', 'h', 'g', 'f' };
            Arrays.sort(a);
            b = Arrays.equals(a, new char[] {'b', 'c', 'f', 'g', 'h'});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of chars and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void sortTest4()
        {
            char[] a;
            bool b;
            a = new char[] { 'c', 'b', 'h', 'g', 'f' };
            Arrays.sort(a, 1, 4);
            b = Arrays.equals(a, new char[] {'c', 'b', 'g', 'h', 'f'});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of doubles.
        /// </summary>
        [TestMethod]
        public void sortTest5()
        {
            double[] a;
            bool b;
            a = new double[] { 3.0, 2.0, 8.0, 7.0, 6.0 };
            Arrays.sort(a);
            b = Arrays.equals(a, new double[] {2.0, 3.0, 6.0, 7.0, 8.0});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of doubles and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void sortTest6()
        {
            double[] a;
            bool b;
            a = new double[] { 3.0, 2.0, 8.0, 7.0, 6.0 };
            Arrays.sort(a, 1, 4);
            b = Arrays.equals(a, new double[] {3.0, 2.0, 7.0, 8.0, 6.0});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of floats.
        /// </summary>
        [TestMethod]
        public void sortTest7()
        {
            float[] a;
            bool b;
            a = new float[] { 3.0F, 2.0F, 8.0F, 7.0F, 6.0F };
            Arrays.sort(a);
            b = Arrays.equals(a, new float[] {2.0F, 3.0F, 6.0F, 7.0F, 8.0F});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of floats and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void sortTest8()
        {
            float[] a;
            bool b;
            a = new float[] { 3.0F, 2.0F, 8.0F, 7.0F, 6.0F };
            Arrays.sort(a, 1, 4);
            b = Arrays.equals(a, new float[] {3.0F, 2.0F, 7.0F, 8.0F, 6.0F});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of ints.
        /// </summary>
        [TestMethod]
        public void sortTest9()
        {
            int[] a;
            bool b;
            a = new int[] { 3, 2, 8, 7, 6 };
            Arrays.sort(a);
            b = Arrays.equals(a, new int[] {2, 3, 6, 7, 8});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of ints and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void sortTest10()
        {
            int[] a;
            bool b;
            a = new int[] { 3, 2, 8, 7, 6 };
            Arrays.sort(a, 1, 4);
            b = Arrays.equals(a, new int[] {3, 2, 7, 8, 6});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of longs.
        /// </summary>
        [TestMethod]
        public void sortTest11()
        {
            long[] a;
            bool b;
            a = new long[] { 3L, 2L, 8L, 7L, 6L };
            Arrays.sort(a);
            b = Arrays.equals(a, new long[] {2, 3, 6, 7, 8});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of longs and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void sortTest12()
        {
            long[] a;
            bool b;
            a = new long[] { 3L, 2L, 8L, 7L, 6L };
            Arrays.sort(a, 1, 4);
            b = Arrays.equals(a, new long[] {3, 2, 7, 8, 6});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of objects.
        /// </summary>
        [TestMethod]
        public void sortTest13()
        {
            TestObject[] a;
            bool b;
            a = new TestObject[]{
                new TestObject("first", 3),
                new TestObject("second", 2),
                new TestObject("third", 8),
                new TestObject("fourth", 7),
                new TestObject("fifth", 6),
                new TestObject("sixth", 3),
                new TestObject("seventh", 2),
                new TestObject("eighth", 8),
                new TestObject("nineth", 7),
                new TestObject("tenth", 6)
            };
            Arrays.sort(a);
            b = Arrays.equals(a, new TestObject[] {new TestObject("second", 2), new TestObject("seventh", 2), new TestObject("first", 3), new TestObject("sixth", 3), new TestObject("fifth", 6), new TestObject("tenth", 6), new TestObject("fourth", 7), new TestObject("nineth", 7), new TestObject("third", 8), new TestObject("eighth", 8)});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of objects and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void sortTest14()
        {
            TestObject[] a;
            bool b;
            a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
            Arrays.sort(a, 1, 4);
            b = Arrays.equals(a, new TestObject[] {new TestObject("first", 3), new TestObject("second", 2), new TestObject("fourth", 7), new TestObject("third", 8), new TestObject("fifth", 6), new TestObject("sixth", 3), new TestObject("seventh", 2), new TestObject("eighth", 8), new TestObject("nineth", 7), new TestObject("tenth", 6)});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of shorts.
        /// </summary>
        [TestMethod]
        public void sortTest15()
        {
            short[] a;
            bool b;
            a = new short[] { (short)3, (short)2, (short)8, (short)7, (short)6 };
            Arrays.sort(a);
            b = Arrays.equals(a, new short[] {2, 3, 6, 7, 8});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of shorts and indexes as parameters.
        /// </summary>
        [TestMethod]
        public void sortTest16()
        {
            short[] a;
            bool b;
            a = new short[] { (short)3, (short)2, (short)8, (short)7, (short)6 };
            Arrays.sort(a, 1, 4);
            b = Arrays.equals(a, new short[] {3, 2, 7, 8, 6});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of objects and comparator as a
        /// parameter.
        /// </summary>
        [TestMethod]
        public void sortTest17()
        {
            TestObject[] a;
            bool b;
            TestObjectComparator c;
            a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
            c = new TestObjectComparator();
            Arrays.sort(a, c);
            b = Arrays.equals(a, new TestObject[] {new TestObject("second", 2), new TestObject("seventh", 2), new TestObject("first", 3), new TestObject("sixth", 3), new TestObject("fifth", 6), new TestObject("tenth", 6), new TestObject("fourth", 7), new TestObject("nineth", 7), new TestObject("third", 8), new TestObject("eighth", 8)});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the sort method with array of objects and indexes and comparator as
        /// parameters.
        /// </summary>
        [TestMethod]
        public void sortTest18()
        {
            TestObject[] a;
            bool b;
            TestObjectComparator c;
            a = new TestObject[]{
            new TestObject("first", 3),
            new TestObject("second", 2),
            new TestObject("third", 8),
            new TestObject("fourth", 7),
            new TestObject("fifth", 6),
            new TestObject("sixth", 3),
            new TestObject("seventh", 2),
            new TestObject("eighth", 8),
            new TestObject("nineth", 7),
            new TestObject("tenth", 6)
        };
            c = new TestObjectComparator();
            Arrays.sort(a, 1, 4, c);
            b = Arrays.equals(a, new TestObject[] {new TestObject("first", 3), new TestObject("second", 2), new TestObject("fourth", 7), new TestObject("third", 8), new TestObject("fifth", 6), new TestObject("sixth", 3), new TestObject("seventh", 2), new TestObject("eighth", 8), new TestObject("nineth", 7), new TestObject("tenth", 6)});
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the toString method with array of booleans.
        /// </summary>
        [TestMethod]
        public void toStringTest()
        {
            bool[] a;
            String b;
            // the text represenation of an empty array
            a = new bool[] { };
            b = Arrays.toString(a);
            Assert.AreEqual("[]", b);
            // the text represenation of an array with one element
            a = new bool[] { true };
            b = Arrays.toString(a);
            Assert.AreEqual("[true]", b);
            // the text represenation of an array with some elements
            a = new bool[] { true, false, false, false, true };
            b = Arrays.toString(a);
            Assert.AreEqual("[true, false, false, false, true]", b);
        }

        /// <summary>
        /// Tests the toString method with array of bytes.
        /// </summary>
        [TestMethod]
        public void toStringTest2()
        {
            sbyte[] a;
            String b;
            a = new sbyte[] { };
            b = Arrays.toString(a);
            Assert.AreEqual("[]", b);
            a = new sbyte[] { (sbyte)3 };
            b = Arrays.toString(a);
            Assert.AreEqual("[3]", b);
            a = new sbyte[] { (sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6 };
            b = Arrays.toString(a);
            Assert.AreEqual("[3, 2, 8, 7, 6]", b);
        }

        /// <summary>
        /// Tests the toString method with array of chars.
        /// </summary>
        [TestMethod]
        public void toStringTest3()
        {
            char[] a;
            String b;
            a = new char[] { };
            b = Arrays.toString(a);
            Assert.AreEqual("[]", b);
            a = new char[] { 'c' };
            b = Arrays.toString(a);
            Assert.AreEqual("[c]", b);
            a = new char[] { 'c', 'b', 'h', 'g', 'f' };
            b = Arrays.toString(a);
            Assert.AreEqual("[c, b, h, g, f]", b);
        }

        /// <summary>
        /// Tests the toString method with array of doubles.
        /// </summary>
        [TestMethod]
        public void toStringTest4()
        {
            double[] a;
            String b;
            a = new double[] { };
            b = Arrays.toString(a);
            Assert.AreEqual("[]", b);
            a = new double[] { 3.0 };
            b = Arrays.toString(a);
            Assert.AreEqual("[3.0]", b);
            a = new double[] { 3.0, 2.0, 8.0, 7.0, 6.0 };
            b = Arrays.toString(a);
            Assert.AreEqual("[3.0, 2.0, 8.0, 7.0, 6.0]", b);
        }

        /// <summary>
        /// Tests the toString method with array of floats.
        /// </summary>
        [TestMethod]
        public void toStringTest5()
        {
            float[] a;
            String b;
            a = new float[] { };
            b = Arrays.toString(a);
            Assert.AreEqual("[]", b);
            a = new float[] { 3.0F };
            b = Arrays.toString(a);
            Assert.AreEqual("[3.0]", b);
            a = new float[] { 3.0F, 2.0F, 8.0F, 7.0F, 6.0F };
            b = Arrays.toString(a);
            Assert.AreEqual("[3.0, 2.0, 8.0, 7.0, 6.0]", b);
        }

        /// <summary>
        /// Tests the toString method with array of ints.
        /// </summary>
        [TestMethod]
        public void toStringTest6()
        {
            int[] a;
            String b;
            a = new int[] { };
            b = Arrays.toString(a);
            Assert.AreEqual("[]", b);
            a = new int[] { 3 };
            b = Arrays.toString(a);
            Assert.AreEqual("[3]", b);
            a = new int[] { 3, 2, 8, 7, 6 };
            b = Arrays.toString(a);
            Assert.AreEqual("[3, 2, 8, 7, 6]", b);
        }

        /// <summary>
        /// Tests the toString method with array of longs.
        /// </summary>
        [TestMethod]
        public void toStringTest7()
        {
            long[] a;
            String b;
            a = new long[] { };
            b = Arrays.toString(a);
            Assert.AreEqual("[]", b);
            a = new long[] { 3L };
            b = Arrays.toString(a);
            Assert.AreEqual("[3]", b);
            a = new long[] { 3L, 2L, 8L, 7L, 6L };
            b = Arrays.toString(a);
            Assert.AreEqual("[3, 2, 8, 7, 6]", b);
        }

        /// <summary>
        /// Tests the toString method with array of objects.
        /// </summary>
        [TestMethod]
        public void toStringTest8()
        {
            TestObject[] a;
            String b;
            a = new TestObject[] { };
            b = Arrays.toString(a);
            Assert.AreEqual("[]", b);
            a = new TestObject[] { new TestObject("first", 1) };
            b = Arrays.toString(a);
            Assert.AreEqual("[TestObject [str=first, i=1]]", b);
            a = new TestObject[] { null };
            b = Arrays.toString(a);
            Assert.AreEqual("[null]", b);
            a = new TestObject[] { new TestObject("first", 1), new TestObject("second", 2), new TestObject("third", 3) };
            b = Arrays.toString(a);
            Assert.AreEqual("[TestObject [str=first, i=1], TestObject [str=second, i=2], TestObject [str=third, i=3]]", b);
            a = new TestObject[] { new TestObject("first", 1), null, new TestObject("third", 3) };
            b = Arrays.toString(a);
            Assert.AreEqual("[TestObject [str=first, i=1], null, TestObject [str=third, i=3]]", b);
            a = new TestObject[] { null, null, null };
            b = Arrays.toString(a);
            Assert.AreEqual("[null, null, null]", b);
        }

        /// <summary>
        /// Tests the toString method with array of shorts.
        /// </summary>
        [TestMethod]
        public void toStringTest9()
        {
            short[] a;
            String b;
            a = new short[] { };
            b = Arrays.toString(a);
            Assert.AreEqual("[]", b);
            a = new short[] { (short)3 };
            b = Arrays.toString(a);
            Assert.AreEqual("[3]", b);
            a = new short[] { (short)3, (short)2, (short)8, (short)7, (short)6 };
            b = Arrays.toString(a);
            Assert.AreEqual("[3, 2, 8, 7, 6]", b);
        }

    }

}