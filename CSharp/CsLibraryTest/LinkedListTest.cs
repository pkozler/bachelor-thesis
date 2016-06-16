using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{

    /// <summary>
    /// A LinkedList class test suite.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
	[TestClass]
	public class LinkedListTest
	{
        
        /*
            Creates the array list from array.
        */
        private static LinkedList<TestObject> toList(TestObject[] array)
        {
            LinkedList<TestObject> list = new LinkedList<TestObject>();

            foreach (TestObject o in array)
            {
                list.add(o);
            }

            return list;
        }
        
        /// <summary>
        /// Tests the constructor.
        /// </summary>
        [TestMethod]
		public void linkedListTest()
        {
            LinkedList<TestObject> a;
            bool b;
            a = new LinkedList<TestObject>();
            b = a.equals(toList(new TestObject[] {}));
            Assert.AreEqual(true, b);
        }

        /// <summary>
        /// Tests the constructor with LinkedList as a parameter.
        /// </summary>
        [TestMethod]
		public void linkedListTest2()
        {
            LinkedList<TestObject> a, b;
            TestObject c;
            bool d;
            a = new LinkedList<TestObject>();
            b = new LinkedList<TestObject>(a);
            d = b.equals(toList(new TestObject[] {}));
            Assert.AreEqual(true, d);
            a = new LinkedList<TestObject>();
            c = new TestObject("first", 1);
            a.add(c);
            b = new LinkedList<TestObject>(a);
            d = b.equals(toList(new TestObject[] {new TestObject("first", 1)}));
            Assert.AreEqual(true, d);
            a = new LinkedList<TestObject>();
            c = new TestObject("first", 1);
            a.add(c);
            c = new TestObject("second", 2);
            a.add(c);
            c = new TestObject("third", 3);
            a.add(c);
            b = new LinkedList<TestObject>(a);
            d = b.equals(toList(new TestObject[] {new TestObject("first", 1), new TestObject("second", 2), new TestObject("third", 3)}));
            Assert.AreEqual(true, d);
        }

        /// <summary>
        /// Tests the add method.
        /// </summary>
        [TestMethod]
		public void addTest()
        {
            LinkedList<TestObject> a;
            TestObject b;
            bool c;
            a = new LinkedList<TestObject>();
            b = new TestObject("first", 1);
            a.add(b);
            c = a.equals(toList(new TestObject[] {new TestObject("first", 1)}));
            Assert.AreEqual(true, c);
            b = new TestObject("second", 2);
            a.add(b);
            c = a.equals(toList(new TestObject[] {new TestObject("first", 1), new TestObject("second", 2)}));
            Assert.AreEqual(true, c);
            b = new TestObject("first", 2);
            a.add(b);
            c = a.equals(toList(new TestObject[] {new TestObject("first", 1), new TestObject("second", 2), new TestObject("first", 2)}));
            Assert.AreEqual(true, c);
            b = new TestObject("second", 1);
            a.add(b);
            c = a.equals(toList(new TestObject[] {new TestObject("first", 1), new TestObject("second", 2), new TestObject("first", 2), new TestObject("second", 1)}));
            Assert.AreEqual(true, c);
            b = new TestObject("first", 1);
            a.add(b);
            c = a.equals(toList(new TestObject[] {new TestObject("first", 1), new TestObject("second", 2), new TestObject("first", 2), new TestObject("second", 1), new TestObject("first", 1)}));
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the add method with index as a parameter.
        /// </summary>
        [TestMethod]
		public void addTest2()
        {
            LinkedList<TestObject> a;
            TestObject b;
            bool c;
            a = new LinkedList<TestObject>();
            b = new TestObject("first", 1);
            a.add(0, b);
            c = a.equals(toList(new TestObject[] {new TestObject("first", 1)}));
            Assert.AreEqual(true, c);
            b = new TestObject("second", 2);
            a.add(1, b);
            c = a.equals(toList(new TestObject[] {new TestObject("first", 1), new TestObject("second", 2)}));
            Assert.AreEqual(true, c);
            b = new TestObject("third", 3);
            a.add(0, b);
            c = a.equals(toList(new TestObject[] {new TestObject("third", 3), new TestObject("first", 1), new TestObject("second", 2)}));
            Assert.AreEqual(true, c);
            b = new TestObject("fourth", 4);
            a.add(1, b);
            c = a.equals(toList(new TestObject[] {new TestObject("third", 3), new TestObject("fourth", 4), new TestObject("first", 1), new TestObject("second", 2)}));
            Assert.AreEqual(true, c);
            b = new TestObject("fifth", 5);
            a.add(2, b);
            c = a.equals(toList(new TestObject[] {new TestObject("third", 3), new TestObject("fourth", 4), new TestObject("fifth", 5), new TestObject("first", 1), new TestObject("second", 2)}));
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the equals method.
        /// </summary>
        [TestMethod]
        public void equalsTest()
        {
            LinkedList<TestObject> a, b;
            bool c;
            a = toList(new TestObject[]{
                new TestObject("first", 3),
                new TestObject("second", 2),
                new TestObject("third", 8),
                new TestObject("fourth", 7),
                new TestObject("fifth", 6),
            });
            b = null;
            c = a.equals(b);
            Assert.AreEqual(false, c);
            b = toList(new TestObject[]{
                new TestObject("first", 3)
            });
            c = a.equals(b);
            Assert.AreEqual(false, c);
            b = toList(new TestObject[]{
                new TestObject("first", 3),
                new TestObject("second", 2),
                new TestObject("third", 8),
                new TestObject("fourth", 7),
                new TestObject("fifth", 3)
            });
            c = a.equals(b);
            Assert.AreEqual(false, c);
            b = toList(new TestObject[]{
                new TestObject("sixth", 3),
                new TestObject("seventh", 2),
                new TestObject("eighth", 8),
                new TestObject("nineth", 7),
                new TestObject("tenth", 6)
            });
            c = a.equals(b);
            Assert.AreEqual(true, c);
            b = a;
            c = a.equals(b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the get method.
        /// </summary>
        [TestMethod]
		public void getTest()
        {
            LinkedList<TestObject> a;
            TestObject b;
            bool c;
            a = new LinkedList<TestObject>();
            b = new TestObject("first", 1);
            a.add(b);
            b = a.get(0);
            c = b.equals(new TestObject("first", 1));
            Assert.AreEqual(true, c);
            b = new TestObject("second", 2);
            a.add(b);
            b = a.get(0);
            c = b.equals(new TestObject("first", 1));
            Assert.AreEqual(true, c);
            b = a.get(1);
            c = b.equals(new TestObject("second", 2));
            Assert.AreEqual(true, c);
            b = new TestObject("third", 3);
            a.add(b);
            b = new TestObject("fourth", 4);
            a.add(b);
            b = new TestObject("fifth", 5);
            a.add(b);
            b = a.get(0);
            c = b.equals(new TestObject("first", 1));
            Assert.AreEqual(true, c);
            b = a.get(4);
            c = b.equals(new TestObject("fifth", 5));
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the set method.
        /// </summary>
        [TestMethod]
		public void setTest()
        {
            LinkedList<TestObject> a;
            TestObject b;
            bool c;
            a = new LinkedList<TestObject>();
            b = new TestObject("first", 1);
            a.add(b);
            b = new TestObject("second", 2);
            a.add(b);
            b = new TestObject("third", 3);
            a.add(b);
            b = new TestObject("fourth", 4);
            a.add(b);
            b = new TestObject("fifth", 5);
            a.add(b);
            b = new TestObject("sixth", 6);
            a.set(0, b);
            c = a.equals(toList(new TestObject[] {new TestObject("sixth", 6), new TestObject("second", 2), new TestObject("third", 3), new TestObject("fourth", 4), new TestObject("fifth", 5)}));
            Assert.AreEqual(true, c);
            b = new TestObject("seventh", 7);
            a.set(2, b);
            c = a.equals(toList(new TestObject[] {new TestObject("sixth", 6), new TestObject("second", 2), new TestObject("seventh", 7), new TestObject("fourth", 4), new TestObject("fifth", 5)}));
            Assert.AreEqual(true, c);
            b = new TestObject("eighth", 8);
            a.set(4, b);
            c = a.equals(toList(new TestObject[] {new TestObject("sixth", 6), new TestObject("second", 2), new TestObject("seventh", 7), new TestObject("fourth", 4), new TestObject("eighth", 8)}));
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the remove method.
        /// </summary>
        [TestMethod]
		public void removeTest()
        {
            LinkedList<TestObject> a;
            TestObject b;
            bool c;
            a = new LinkedList<TestObject>();
            b = new TestObject("first", 1);
            a.add(b);
            b = new TestObject("second", 2);
            a.add(b);
            b = new TestObject("third", 3);
            a.add(b);
            b = new TestObject("fourth", 4);
            a.add(b);
            b = new TestObject("fifth", 5);
            a.add(b);
            a.remove(0);
            c = a.equals(toList(new TestObject[] {new TestObject("second", 2), new TestObject("third", 3), new TestObject("fourth", 4), new TestObject("fifth", 5)}));
            Assert.AreEqual(true, c);
            a.remove(1);
            c = a.equals(toList(new TestObject[] {new TestObject("second", 2), new TestObject("fourth", 4), new TestObject("fifth", 5)}));
            Assert.AreEqual(true, c);
            a.remove(2);
            c = a.equals(toList(new TestObject[] {new TestObject("second", 2), new TestObject("fourth", 4)}));
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the size method.
        /// </summary>
        [TestMethod]
		public void sizeTest()
        {
            LinkedList<TestObject> a;
            TestObject b;
            int c;
            a = new LinkedList<TestObject>();
            c = a.size();
            Assert.AreEqual(0, c);
            b = new TestObject("first", 1);
            a.add(b);
            c = a.size();
            Assert.AreEqual(1, c);
            b = new TestObject("second", 2);
            a.add(b);
            b = new TestObject("third", 3);
            a.add(b);
            c = a.size();
            Assert.AreEqual(3, c);
            a.remove(0);
            c = a.size();
            Assert.AreEqual(2, c);
            a.remove(0);
            a.remove(0);
            c = a.size();
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the isEmpty method.
        /// </summary>
        [TestMethod]
		public void isEmptyTest()
        {
            LinkedList<TestObject> a;
            TestObject b;
            bool c;
            a = new LinkedList<TestObject>();
            c = a.isEmpty();
            Assert.AreEqual(true, c);
            b = new TestObject("first", 1);
            a.add(b);
            c = a.isEmpty();
            Assert.AreEqual(false, c);
            b = new TestObject("second", 2);
            a.add(b);
            b = new TestObject("third", 3);
            a.add(b);
            c = a.isEmpty();
            Assert.AreEqual(false, c);
            a.remove(0);
            c = a.isEmpty();
            Assert.AreEqual(false, c);
            a.remove(0);
            a.remove(0);
            c = a.isEmpty();
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the clear method.
        /// </summary>
        [TestMethod]
		public void clearTest()
        {
            LinkedList<TestObject> a;
            TestObject b;
            bool c;
            a = new LinkedList<TestObject>();
            a.clear();
            c = a.equals(toList(new TestObject[] {}));
            Assert.AreEqual(true, c);
            b = new TestObject("first", 1);
            a.add(b);
            a.clear();
            c = a.equals(toList(new TestObject[] {}));
            Assert.AreEqual(true, c);
            b = new TestObject("first", 1);
            a.add(b);
            b = new TestObject("second", 2);
            a.add(b);
            b = new TestObject("third", 3);
            a.add(b);
            a.clear();
            c = a.equals(toList(new TestObject[] {}));
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest()
        {
            LinkedList<TestObject> a;
            TestObject b;
            String c;
            a = new LinkedList<TestObject>();
            c = a.toString();
            Assert.AreEqual("[]", c);
            a = new LinkedList<TestObject>();
            b = new TestObject("first", 1);
            a.add(b);
            c = a.toString();
            Assert.AreEqual("[TestObject [str=first, i=1]]", c);
            a = new LinkedList<TestObject>();
            b = new TestObject("first", 1);
            a.add(b);
            b = new TestObject("second", 2);
            a.add(b);
            b = new TestObject("third", 3);
            a.add(b);
            c = a.toString();
            Assert.AreEqual("[TestObject [str=first, i=1], TestObject [str=second, i=2], TestObject [str=third, i=3]]", c);
        }

    }
}

