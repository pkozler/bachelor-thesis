using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class CollectionsTest
	{

        /// <summary>
        /// Tests the binarySearch method.
        /// </summary>
        [TestMethod]
		public void binarySearchTest()
        {
            ArrayList<TestObject> a;
            int b;
            a = new ArrayList<TestObject>();
            a.add(new TestObject("first", 3));
            a.add(new TestObject("second", 2));
            a.add(new TestObject("third", 8));
            a.add(new TestObject("fourth", 7));
            a.add(new TestObject("fifth", 6));
            a.add(new TestObject("sixth", 3));
            a.add(new TestObject("seventh", 2));
            a.add(new TestObject("eighth", 8));
            a.add(new TestObject("nineth", 7));
            a.add(new TestObject("tenth", 6));
            Collections.sort(a);
            b = Collections.binarySearch(a, new TestObject("sixth", 6));
            Assert.AreEqual(4, b);
            b = Collections.binarySearch(a, new TestObject("sixth", 4));
            Assert.AreEqual(-5, b);
        }

        /// <summary>
        /// Tests the binarySearch method with comparator as a parameter.
        /// </summary>
        [TestMethod]
		public void binarySearchTest2()
        {
            ArrayList<TestObject> a;
            int b;
            TestObjectComparator c;
            a = new ArrayList<TestObject>();
            a.add(new TestObject("first", 3));
            a.add(new TestObject("second", 2));
            a.add(new TestObject("third", 8));
            a.add(new TestObject("fourth", 7));
            a.add(new TestObject("fifth", 6));
            a.add(new TestObject("sixth", 3));
            a.add(new TestObject("seventh", 2));
            a.add(new TestObject("eighth", 8));
            a.add(new TestObject("nineth", 7));
            a.add(new TestObject("tenth", 6));
            c = new TestObjectComparator();
            Collections.sort(a);
            b = Collections.binarySearch(a, new TestObject("sixth", 6), c);
            Assert.AreEqual(4, b);
            b = Collections.binarySearch(a, new TestObject("sixth", 4), c);
            Assert.AreEqual(-5, b);
        }

        /// <summary>
        /// Tests the copy method.
        /// </summary>
        [TestMethod]
		public void copyTest()
        {
            ArrayList<TestObject> a, b, c;
            bool d;
            // source list
            a = new ArrayList<TestObject>();
            a.add(new TestObject("first", 3));
            a.add(new TestObject("second", 2));
            a.add(new TestObject("third", 8));
            a.add(new TestObject("fourth", 7));
            a.add(new TestObject("fifth", 6));
            // destination list
            b = new ArrayList<TestObject>();
            b.add(new TestObject("zeroth", 0));
            b.add(new TestObject("zeroth", 0));
            b.add(new TestObject("zeroth", 0));
            b.add(new TestObject("zeroth", 0));
            b.add(new TestObject("zeroth", 0));
            b.add(new TestObject("zeroth", 0));
            Collections.copy(b, a);
            c = new ArrayList<TestObject>();
            c.add(new TestObject("first", 3));
            c.add(new TestObject("second", 2));
            c.add(new TestObject("third", 8));
            c.add(new TestObject("fourth", 7));
            c.add(new TestObject("fifth", 6));
            c.add(new TestObject("zeroth", 0));
            d = c.equals(b);
            Assert.AreEqual(true, d);
        }

        /// <summary>
        /// Tests the fill method.
        /// </summary>
        [TestMethod]
		public void fillTest()
        {
            ArrayList<TestObject> a, b;
            bool d;
            a = new ArrayList<TestObject>();
            a.add(new TestObject("first", 3));
            a.add(new TestObject("second", 2));
            a.add(new TestObject("third", 8));
            a.add(new TestObject("fourth", 7));
            a.add(new TestObject("fifth", 6));
            Collections.fill(a, new TestObject("sixth", 6));
            b = new ArrayList<TestObject>();
            b.add(new TestObject("sixth", 6));
            b.add(new TestObject("sixth", 6));
            b.add(new TestObject("sixth", 6));
            b.add(new TestObject("sixth", 6));
            b.add(new TestObject("sixth", 6));
            d = b.equals(a);
            Assert.AreEqual(true, d);
        }

        /// <summary>
        /// Tests the sort method.
        /// </summary>
        [TestMethod]
		public void sortTest()
        {
            ArrayList<TestObject> a, b;
            bool d;
            a = new ArrayList<TestObject>();
            a.add(new TestObject("first", 3));
            a.add(new TestObject("second", 2));
            a.add(new TestObject("third", 8));
            a.add(new TestObject("fourth", 7));
            a.add(new TestObject("fifth", 6));
            a.add(new TestObject("sixth", 3));
            a.add(new TestObject("seventh", 2));
            a.add(new TestObject("eighth", 8));
            a.add(new TestObject("nineth", 7));
            a.add(new TestObject("tenth", 6));
            Collections.sort(a);
            b = new ArrayList<TestObject>();
            b.add(new TestObject("second", 2));
            b.add(new TestObject("seventh", 2));
            b.add(new TestObject("first", 3));
            b.add(new TestObject("sixth", 3));
            b.add(new TestObject("fifth", 6));
            b.add(new TestObject("tenth", 6));
            b.add(new TestObject("fourth", 7));
            b.add(new TestObject("nineth", 7));
            b.add(new TestObject("third", 8));
            b.add(new TestObject("eighth", 8));
            d = b.equals(a);
            Assert.AreEqual(true, d);
        }

        /// <summary>
        /// Tests the sort method with comparator as a parameter.
        /// </summary>
        [TestMethod]
		public void sortTest2()
        {
            ArrayList<TestObject> a, b;
            TestObjectComparator c;
            bool d;
            a = new ArrayList<TestObject>();
            a.add(new TestObject("first", 3));
            a.add(new TestObject("second", 2));
            a.add(new TestObject("third", 8));
            a.add(new TestObject("fourth", 7));
            a.add(new TestObject("fifth", 6));
            a.add(new TestObject("sixth", 3));
            a.add(new TestObject("seventh", 2));
            a.add(new TestObject("eighth", 8));
            a.add(new TestObject("nineth", 7));
            a.add(new TestObject("tenth", 6));
            c = new TestObjectComparator();
            Collections.sort(a, c);
            b = new ArrayList<TestObject>();
            b.add(new TestObject("second", 2));
            b.add(new TestObject("seventh", 2));
            b.add(new TestObject("first", 3));
            b.add(new TestObject("sixth", 3));
            b.add(new TestObject("fifth", 6));
            b.add(new TestObject("tenth", 6));
            b.add(new TestObject("fourth", 7));
            b.add(new TestObject("nineth", 7));
            b.add(new TestObject("third", 8));
            b.add(new TestObject("eighth", 8));
            d = b.equals(a);
            Assert.AreEqual(true, d);
        }

    }
}

