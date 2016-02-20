using Microsoft.VisualStudio.TestTools.UnitTesting;
using JavaClasses;
using System.Collections.Generic;

namespace CsLibraryTest
{
	[TestClass]
	public class ArraysTest
	{
		private class TestObject : System.IComparable
        {
			public String str { get; private set; }
			public int i { get; private set; }

			public TestObject(String str, int i)
			{
				this.str = str;
				this.i = i;
			}

			public int CompareTo(object o)
			{
				return this.i - ((TestObject)o).i;
			}

			public override string ToString ()
			{
				return "TestObject [str=" + str.ToString() + ", i=" + i.ToString() + "]";
			}

			public override bool Equals(object o)
			{
				if (o == null)
				{
					return false;
				}

				return (this.str.Equals(((TestObject)o).str)) && (this.i == ((TestObject)o).i);
			}

			public override int GetHashCode()
			{
				return str.GetHashCode() ^ i.GetHashCode();
			}
		}

		private class TestObjectComparer : Comparer<TestObject>
		{
			public override int Compare(TestObject o1, TestObject o2)
			{
				return o1.i - o2.i;
			}
		}

		[TestMethod]
		public void sortTestCase1 ()
		{
			sbyte[] array = new sbyte[]{(sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6};
			Arrays.sort (array);
			Assert.AreEqual (new sbyte[] {(sbyte)2, (sbyte)3, (sbyte)6, (sbyte)7, (sbyte)8}, array);
		}

		[TestMethod]
		public void sortTestCase2 ()
		{
			sbyte[] array = new sbyte[]{(sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6};
			Arrays.sort (array, 1, 4);
			Assert.AreEqual (new sbyte[] {(sbyte)3, (sbyte)2, (sbyte)7, (sbyte)8, (sbyte)6}, array);
		}

		[TestMethod]
		public void sortTestCase3 ()
		{
			char[] array = new char[]{'c', 'b', 'h', 'g', 'f'};
			Arrays.sort (array);
			Assert.AreEqual (new char[] {'b', 'c', 'f', 'g', 'h'}, array);
		}

		[TestMethod]
		public void sortTestCase4 ()
		{
			char[] array = new char[]{'c', 'b', 'h', 'g', 'f'};
			Arrays.sort (array, 1, 4);
			Assert.AreEqual (new char[] {'c', 'b', 'g', 'h', 'f'}, array);
		}

		[TestMethod]
		public void sortTestCase5 ()
		{
			double[] array = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
			Arrays.sort (array);
			Assert.AreEqual (new double[] {2.0, 3.0, 6.0, 7.0, 8.0}, array);
		}

		[TestMethod]
		public void sortTestCase6 ()
		{
			double[] array = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
			Arrays.sort (array, 1, 4);
			Assert.AreEqual (new double[] {3.0, 2.0, 7.0, 8.0, 6.0}, array);
		}

		[TestMethod]
		public void sortTestCase7 ()
		{
			float[] array = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
			Arrays.sort (array);
			Assert.AreEqual (new float[] {2.0F, 3.0F, 6.0F, 7.0F, 8.0F}, array);
		}

		[TestMethod]
		public void sortTestCase8 ()
		{
			float[] array = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
			Arrays.sort (array, 1, 4);
			Assert.AreEqual (new float[] {3.0F, 2.0F, 7.0F, 8.0F, 6.0F}, array);
		}

		[TestMethod]
		public void sortTestCase9 ()
		{
			int[] array = new int[]{3, 2, 8, 7, 6};
			Arrays.sort (array);
			Assert.AreEqual (new int[] {2, 3, 6, 7, 8}, array);
		}

		[TestMethod]
		public void sortTestCase10 ()
		{
			int[] array = new int[]{3, 2, 8, 7, 6};
			Arrays.sort (array, 1, 4);
			Assert.AreEqual (new int[] {3, 2, 7, 8, 6}, array);
		}

		[TestMethod]
		public void sortTestCase11 ()
		{
			long[] array = new long[]{3L, 2L, 8L, 7L, 6L};
			Arrays.sort (array);
			Assert.AreEqual (new long[] {2L, 3L, 6L, 7L, 8L}, array);
		}

		[TestMethod]
		public void sortTestCase12 ()
		{
			long[] array = new long[]{3L, 2L, 8L, 7L, 6L};
			Arrays.sort (array, 1, 4);
			Assert.AreEqual (new long[] {3L, 2L, 7L, 8L, 6L}, array);
		}

		[TestMethod]
		public void sortTestCase13 ()
		{
			TestObject[] array = new TestObject[]
			{
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
			Arrays.sort(array);
			Assert.AreEqual (new TestObject[] 
				{
					new TestObject("second", 2),
					new TestObject("seventh", 2),
					new TestObject("first", 3),
					new TestObject("sixth", 3),
					new TestObject("fifth", 6),
					new TestObject("tenth", 6),
					new TestObject("fourth", 7),
					new TestObject("nineth", 7),
					new TestObject("third", 8),
					new TestObject("eighth", 8)
				}, array);
		}

		[TestMethod]
		public void sortTestCase14 ()
		{
			TestObject[] array = new TestObject[]
			{
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
			Arrays.sort(array, 2, 8);
			Assert.AreEqual (new TestObject[] 
				{
					new TestObject("first", 3),
					new TestObject("second", 2),
					new TestObject("seventh", 2),
					new TestObject("sixth", 3),
					new TestObject("fifth", 6),
					new TestObject("fourth", 7),
					new TestObject("third", 8),
					new TestObject("eighth", 8),
					new TestObject("nineth", 7),
					new TestObject("tenth", 6)
				}, array);
		}

		[TestMethod]
		public void sortTestCase15 ()
		{
			short[] array = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
			Arrays.sort (array);
			Assert.AreEqual (new short[] {(short)2, (short)3, (short)6, (short)7, (short)8}, array);
		}

		[TestMethod]
		public void sortTestCase16 ()
		{
			short[] array = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
			Arrays.sort (array, 1, 4);
			Assert.AreEqual (new short[] {(short)3, (short)2, (short)7, (short)8, (short)6}, array);
		}

		[TestMethod]
		public void sortTestCase17 ()
		{
			TestObject[] array = new TestObject[]
			{
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
			Arrays.sort(array, new TestObjectComparer());
			Assert.AreEqual (new TestObject[] 
				{
					new TestObject("second", 2),
					new TestObject("seventh", 2),
					new TestObject("first", 3),
					new TestObject("sixth", 3),
					new TestObject("fifth", 6),
					new TestObject("tenth", 6),
					new TestObject("fourth", 7),
					new TestObject("nineth", 7),
					new TestObject("third", 8),
					new TestObject("eighth", 8)
				}, array);
		}

		[TestMethod]
		public void sortTestCase18 ()
		{
			TestObject[] array = new TestObject[]
			{
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
			Arrays.sort(array, 2, 8, new TestObjectComparer());
			Assert.AreEqual (new TestObject[] 
				{
					new TestObject("first", 3),
					new TestObject("second", 2),
					new TestObject("seventh", 2),
					new TestObject("sixth", 3),
					new TestObject("fifth", 6),
					new TestObject("fourth", 7),
					new TestObject("third", 8),
					new TestObject("eighth", 8),
					new TestObject("nineth", 7),
					new TestObject("tenth", 6)
				}, array);
		}

        /*NumberFormatInfo nfi = new CultureInfo("en-US", false).NumberFormat;
        nfi.NumberDecimalDigits = 1;
        StringBuilder sb = new StringBuilder("[");

        if (a.Length > 0) {
            sb.Append(a[0].ToString("F", nfi));
        }

        for (int i = 1; i < a.Length; i++) {
            sb.Append(", ").Append(a[i].ToString("F", nfi));
        }

        sb.Append("]");

        return sb.ToString();*/

        [TestMethod]
		public void toStringTestCase1 ()
		{
			bool[] array = new bool[]{true, true, false, true, false, false};
			String s = Arrays.toString (array);
			Assert.AreEqual ("[true, true, false, true, false, false]", s.ToString());
		}

		[TestMethod]
		public void toStringTestCase2 ()
		{
			sbyte[] array = new sbyte[]{(sbyte)3, (sbyte)2, (sbyte)8, (sbyte)7, (sbyte)6};
			String s = Arrays.toString (array);
			Assert.AreEqual ("[3, 2, 8, 7, 6]", s.ToString());
		}

		[TestMethod]
		public void toStringTestCase3 ()
		{
			char[] array = new char[]{'c', 'b', 'h', 'g', 'f'};
			String s = Arrays.toString (array);
			Assert.AreEqual ("[c, b, h, g, f]", s.ToString());
		}

		[TestMethod]
		public void toStringTestCase4 ()
		{
			double[] array = new double[]{3.0, 2.0, 8.0, 7.0, 6.0};
			String s = Arrays.toString (array);
			Assert.AreEqual ("[3.0, 2.0, 8.0, 7.0, 6.0]", s.ToString());
		}

		[TestMethod]
		public void toStringTestCase5 ()
		{
			float[] array = new float[]{3.0F, 2.0F, 8.0F, 7.0F, 6.0F};
			String s = Arrays.toString (array);
			Assert.AreEqual ("[3.0, 2.0, 8.0, 7.0, 6.0]", s.ToString());
		}

		[TestMethod]
		public void toStringTestCase6 ()
		{
			int[] array = new int[]{3, 2, 8, 7, 6};
			String s = Arrays.toString (array);
			Assert.AreEqual ("[3, 2, 8, 7, 6]", s.ToString());
		}

		[TestMethod]
		public void toStringTestCase7 ()
		{
			long[] array = new long[]{3L, 2L, 8L, 7L, 6L};
			String s = Arrays.toString (array);
			Assert.AreEqual ("[3, 2, 8, 7, 6]", s.ToString());
		}

		[TestMethod]
		public void toStringTestCase8 ()
		{
			TestObject[] array = new TestObject[]
			{
				new TestObject("first", 1),
				new TestObject("second", 2),
				new TestObject("third", 3)
			};

			String s = Arrays.toString(array);
			Assert.AreEqual ("[TestObject [str=first, i=1], " +
				"TestObject [str=second, i=2], " +
				"TestObject [str=third, i=3]]", s.ToString());
		}

		[TestMethod]
		public void toStringTestCase9 ()
		{
			short[] array = new short[]{(short)3, (short)2, (short)8, (short)7, (short)6};
			String s = Arrays.toString (array);
			Assert.AreEqual ("[3, 2, 8, 7, 6]", s.ToString());
		}
	}
}

