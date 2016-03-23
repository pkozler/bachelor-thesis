using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
    [TestClass]
    public class ArrayListTest
    {

        /*
            Creates the array list from array.
        */
        private static ArrayList<TestObject> toList(TestObject[] array)
        {
            ArrayList<TestObject> list = new ArrayList<TestObject>();

            foreach (TestObject o in array)
            {
                list.add(o);
            }

            return list;
        }

        /**
         * Tests the constructor.
         */
        [TestMethod]
        public void arrayListTest()
        {
            ArrayList<TestObject> a;
            bool b;
            // empty list
            a = new ArrayList<TestObject>();
            b = a.equals(toList(new TestObject[] { }));
            Assert.AreEqual(true, b);
        }

        /**
         * Tests the constructor with ArrayList as a parameter.
         */
        [TestMethod]
        public void arrayListTest2()
        {
            ArrayList<TestObject> a, b;
            TestObject c;
            bool d;
            // creating the list from an empty list
            a = new ArrayList<TestObject>();
            b = new ArrayList<TestObject>(a);
            d = b.equals(toList(new TestObject[] { }));
            Assert.AreEqual(true, d);
            // creating the list from a list with one element
            a = new ArrayList<TestObject>();
            c = new TestObject("first", 1);
            a.add(c);
            b = new ArrayList<TestObject>(a);
            d = b.equals(toList(new TestObject[] { new TestObject("first", 1) }));
            Assert.AreEqual(true, d);
            // creating the list from a list with some elements
            a = new ArrayList<TestObject>();
            c = new TestObject("first", 1);
            a.add(c);
            c = new TestObject("second", 2);
            a.add(c);
            c = new TestObject("third", 3);
            a.add(c);
            b = new ArrayList<TestObject>(a);
            d = b.equals(toList(new TestObject[] { new TestObject("first", 1), new TestObject("second", 2), new TestObject("third", 3) }));
            Assert.AreEqual(true, d);
        }

        /**
         * Tests the add method.
         */
        [TestMethod]
        public void addTest()
        {
            ArrayList<TestObject> a;
            TestObject b;
            bool c;
            // adding some elements at the end of the list
            a = new ArrayList<TestObject>();
            b = new TestObject("first", 1);
            a.add(b);
            c = a.equals(toList(new TestObject[] { new TestObject("first", 1) }));
            Assert.AreEqual(true, c);
            b = new TestObject("second", 2);
            a.add(b);
            c = a.equals(toList(new TestObject[] { new TestObject("first", 1), new TestObject("second", 2) }));
            Assert.AreEqual(true, c);
            b = new TestObject("first", 2);
            a.add(b);
            c = a.equals(toList(new TestObject[] { new TestObject("first", 1), new TestObject("second", 2), new TestObject("first", 2) }));
            Assert.AreEqual(true, c);
            b = new TestObject("second", 1);
            a.add(b);
            c = a.equals(toList(new TestObject[] { new TestObject("first", 1), new TestObject("second", 2), new TestObject("first", 2), new TestObject("second", 1) }));
            Assert.AreEqual(true, c);
            b = new TestObject("first", 1);
            a.add(b);
            c = a.equals(toList(new TestObject[] { new TestObject("first", 1), new TestObject("second", 2), new TestObject("first", 2), new TestObject("second", 1), new TestObject("first", 1) }));
            Assert.AreEqual(true, c);
        }

        /**
         * Tests the add method with index as a parameter.
         */
        [TestMethod]
        public void addTest2()
        {
            ArrayList<TestObject> a;
            TestObject b;
            bool c;
            a = new ArrayList<TestObject>();
            // adding an element at the beginning
            b = new TestObject("first", 1);
            a.add(0, b);
            c = a.equals(toList(new TestObject[] { new TestObject("first", 1) }));
            Assert.AreEqual(true, c);
            // adding an element at the end
            b = new TestObject("second", 2);
            a.add(1, b);
            c = a.equals(toList(new TestObject[] { new TestObject("first", 1), new TestObject("second", 2) }));
            Assert.AreEqual(true, c);
            // adding an element at the beginning
            b = new TestObject("third", 3);
            a.add(0, b);
            c = a.equals(toList(new TestObject[] { new TestObject("third", 3), new TestObject("first", 1), new TestObject("second", 2) }));
            Assert.AreEqual(true, c);
            // adding an element in the middle
            b = new TestObject("fourth", 4);
            a.add(1, b);
            c = a.equals(toList(new TestObject[] { new TestObject("third", 3), new TestObject("fourth", 4), new TestObject("first", 1), new TestObject("second", 2) }));
            Assert.AreEqual(true, c);
            // adding an element in the middle
            b = new TestObject("fifth", 5);
            a.add(2, b);
            c = a.equals(toList(new TestObject[] { new TestObject("third", 3), new TestObject("fourth", 4), new TestObject("fifth", 5), new TestObject("first", 1), new TestObject("second", 2) }));
            Assert.AreEqual(true, c);
        }

        /**
         * Tests the equals method.
         */
        [TestMethod]
        public void equalsTest()
        {
            ArrayList<TestObject> a, b;
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
            a = toList(new TestObject[]{
                new TestObject("first", 3)
            });
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = toList(new TestObject[]{
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
            Assert.AreEqual(false, c);
            b = a;
            c = a.equals(b);
            Assert.AreEqual(true, c);
        }

        /**
         * Tests the get method.
         */
        [TestMethod]
        public void getTest()
        {
            ArrayList<TestObject> a;
            TestObject b;
            bool c;
            a = new ArrayList<TestObject>();
            // getting an element from the beginning
            b = new TestObject("first", 1);
            a.add(b);
            b = a.get(0);
            c = b.equals(new TestObject("first", 1));
            Assert.AreEqual(true, c);
            // getting an element from the beginning (more elements in the list)
            b = new TestObject("second", 2);
            a.add(b);
            b = a.get(0);
            c = b.equals(new TestObject("first", 1));
            Assert.AreEqual(true, c);
            // getting an element from the end
            b = a.get(1);
            c = b.equals(new TestObject("second", 2));
            Assert.AreEqual(true, c);
            b = new TestObject("third", 3);
            a.add(b);
            b = new TestObject("fourth", 4);
            a.add(b);
            b = new TestObject("fifth", 5);
            a.add(b);
            // getting an element from the beginning
            b = a.get(0);
            c = b.equals(new TestObject("first", 1));
            Assert.AreEqual(true, c);
            // getting an element from the end
            b = a.get(4);
            c = b.equals(new TestObject("fifth", 5));
            Assert.AreEqual(true, c);
        }

        /**
         * Tests the set method.
         */
        [TestMethod]
        public void setTest()
        {
            ArrayList<TestObject> a;
            TestObject b;
            bool c;
            a = new ArrayList<TestObject>();
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
            // replacing an element at the beginning
            a.set(0, b);
            c = a.equals(toList(new TestObject[] { new TestObject("sixth", 6), new TestObject("second", 2), new TestObject("third", 3), new TestObject("fourth", 4), new TestObject("fifth", 5) }));
            Assert.AreEqual(true, c);
            // replacing an element in the middle
            b = new TestObject("seventh", 7);
            a.set(2, b);
            c = a.equals(toList(new TestObject[] { new TestObject("sixth", 6), new TestObject("second", 2), new TestObject("seventh", 7), new TestObject("fourth", 4), new TestObject("fifth", 5) }));
            Assert.AreEqual(true, c);
            // replacing an element at the end
            b = new TestObject("eighth", 8);
            a.set(4, b);
            c = a.equals(toList(new TestObject[] { new TestObject("sixth", 6), new TestObject("second", 2), new TestObject("seventh", 7), new TestObject("fourth", 4), new TestObject("eighth", 8) }));
            Assert.AreEqual(true, c);
        }

        /**
         * Tests the remove method.
         */
        [TestMethod]
        public void removeTest()
        {
            ArrayList<TestObject> a;
            TestObject b;
            bool c;
            a = new ArrayList<TestObject>();
            b = new TestObject("first", 1);
            a.add(b);
            b = new TestObject("second", 2);
            a.add(b);
            b = new TestObject("third", 3);
            a.add(b);
            b = new TestObject("fourth", 4);
            a.add(b);
            b = new TestObject("fifth", 5);
            // removing an element from the beginning
            a.add(b);
            a.remove(0);
            c = a.equals(toList(new TestObject[] { new TestObject("second", 2), new TestObject("third", 3), new TestObject("fourth", 4), new TestObject("fifth", 5) }));
            Assert.AreEqual(true, c);
            // removing the element from the middle
            a.remove(1);
            c = a.equals(toList(new TestObject[] { new TestObject("second", 2), new TestObject("fourth", 4), new TestObject("fifth", 5) }));
            Assert.AreEqual(true, c);
            // removing an element from the end
            a.remove(2);
            c = a.equals(toList(new TestObject[] { new TestObject("second", 2), new TestObject("fourth", 4) }));
            Assert.AreEqual(true, c);
        }

        /**
         * Tests the size method.
         */
        [TestMethod]
        public void sizeTest()
        {
            ArrayList<TestObject> a;
            TestObject b;
            int c;
            a = new ArrayList<TestObject>();
            // size in the beginning
            c = a.size();
            Assert.AreEqual(0, c);
            b = new TestObject("first", 1);
            // size after adding one element
            a.add(b);
            c = a.size();
            Assert.AreEqual(1, c);
            // size after adding more elements
            b = new TestObject("second", 2);
            a.add(b);
            b = new TestObject("third", 3);
            a.add(b);
            c = a.size();
            Assert.AreEqual(3, c);
            // size after removing one element
            a.remove(0);
            c = a.size();
            Assert.AreEqual(2, c);
            // size after removing more elements
            a.remove(0);
            a.remove(0);
            c = a.size();
            Assert.AreEqual(0, c);
        }

        /**
         * Tests the isEmpty method.
         */
        [TestMethod]
        public void isEmptyTest()
        {
            ArrayList<TestObject> a;
            TestObject b;
            bool c;
            a = new ArrayList<TestObject>();
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

        /**
         * Tests the clear method.
         */
        [TestMethod]
        public void clearTest()
        {
            ArrayList<TestObject> a;
            TestObject b;
            bool c;
            a = new ArrayList<TestObject>();
            // clear in the beginning
            a.clear();
            c = a.equals(toList(new TestObject[] { }));
            Assert.AreEqual(true, c);
            // clear after adding one element
            b = new TestObject("first", 1);
            a.add(b);
            a.clear();
            c = a.equals(toList(new TestObject[] { }));
            Assert.AreEqual(true, c);
            // clear after adding more elements
            b = new TestObject("first", 1);
            a.add(b);
            b = new TestObject("second", 2);
            a.add(b);
            b = new TestObject("third", 3);
            a.add(b);
            a.clear();
            c = a.equals(toList(new TestObject[] { }));
            Assert.AreEqual(true, c);
        }

        /**
         * Tests the toString method.
         */
        [TestMethod]
        public void toStringTest()
        {
            ArrayList<TestObject> a;
            TestObject b;
            String c;
            // the text representation of an empty list
            a = new ArrayList<TestObject>();
            c = a.toString();
            Assert.AreEqual("[]", c);
            // the text representation of a list with one element
            b = new TestObject("first", 1);
            a.add(b);
            c = a.toString();
            Assert.AreEqual("[TestObject [str=first, i=1]]", c);
            // the text representation of a list with some elements
            b = new TestObject("second", 2);
            a.add(b);
            b = new TestObject("third", 3);
            a.add(b);
            c = a.toString();
            Assert.AreEqual("[TestObject [str=first, i=1], TestObject [str=second, i=2], TestObject [str=third, i=3]]", c);
        }
    }
}
