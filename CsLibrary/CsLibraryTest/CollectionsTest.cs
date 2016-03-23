using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class CollectionsTest
	{
        /**
         * Tests the binarySearch method.
         */
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

        /**
         * Tests the binarySearch method with comparator as a parameter.
         */
        [TestMethod]
		public void binarySearchTest2()
        {
            ArrayList<TestObject> a;
            int b;
            TestObjectComparer c;
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
            c = new TestObjectComparer();
            Collections.sort(a);
            b = Collections.binarySearch(a, new TestObject("sixth", 6), c);
            Assert.AreEqual(4, b);
            b = Collections.binarySearch(a, new TestObject("sixth", 4), c);
            Assert.AreEqual(-5, b);
        }

        /**
         * Tests the copy method.
         */
        [TestMethod]
		public void copyTest()
        {
            ArrayList<TestObject> a, b;
            String c;
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
            c = b.toString();
            Assert.AreEqual("[TestObject [str=first, i=3], TestObject [str=second, i=2], TestObject [str=third, i=8], TestObject [str=fourth, i=7], TestObject [str=fifth, i=6], TestObject [str=zeroth, i=0]]", c);
        }

        /**
         * Tests the fill method.
         */
        [TestMethod]
		public void fillTest()
        {
            ArrayList<TestObject> a;
            String b;
            a = new ArrayList<TestObject>();
            a.add(new TestObject("first", 3));
            a.add(new TestObject("second", 2));
            a.add(new TestObject("third", 8));
            a.add(new TestObject("fourth", 7));
            a.add(new TestObject("fifth", 6));
            Collections.fill(a, new TestObject("sixth", 6));
            b = a.toString();
            Assert.AreEqual("[TestObject [str=sixth, i=6], TestObject [str=sixth, i=6], TestObject [str=sixth, i=6], TestObject [str=sixth, i=6], TestObject [str=sixth, i=6]]", b);
        }

        /**
         * Tests the sort method.
         */
        [TestMethod]
		public void sortTest()
        {
            ArrayList<TestObject> a;
            String b;
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
            b = a.toString();
            Assert.AreEqual("[TestObject [str=second, i=2], TestObject [str=seventh, i=2], TestObject [str=first, i=3], TestObject [str=sixth, i=3], TestObject [str=fifth, i=6], TestObject [str=tenth, i=6], TestObject [str=fourth, i=7], TestObject [str=nineth, i=7], TestObject [str=third, i=8], TestObject [str=eighth, i=8]]", b);
        }

        /**
         * Tests the sort method with comparator as a parameter.
         */
        [TestMethod]
		public void sortTest2()
        {
            ArrayList<TestObject> a;
            String b;
            TestObjectComparer c;
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
            c = new TestObjectComparer();
            Collections.sort(a, c);
            b = a.toString();
            Assert.AreEqual("[TestObject [str=second, i=2], TestObject [str=seventh, i=2], TestObject [str=first, i=3], TestObject [str=sixth, i=3], TestObject [str=fifth, i=6], TestObject [str=tenth, i=6], TestObject [str=fourth, i=7], TestObject [str=nineth, i=7], TestObject [str=third, i=8], TestObject [str=eighth, i=8]]", b);
        }
    }
}

