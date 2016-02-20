using Microsoft.VisualStudio.TestTools.UnitTesting;
using JavaClasses;

namespace CsLibraryTest
{
    [TestClass]
    public class ArrayListTest
    {

        [TestMethod]
        public void addTestCase1()
        {
            ArrayList<String> arrayList = new ArrayList<String>();
            arrayList.add("first");
            Assert.AreEqual("[first]", arrayList.ToString());
            arrayList.add("second");
            Assert.AreEqual("[first, second]", arrayList.ToString());
            arrayList.add("third");
            Assert.AreEqual("[first, second, third]", arrayList.ToString());
        }

        [TestMethod]
        public void addTestCase2()
        {
            ArrayList<String> arrayList = new ArrayList<String>();
            arrayList.add(0, "first");
            Assert.AreEqual("[first]", arrayList.ToString());
            arrayList.add(1, "second");
            Assert.AreEqual("[first, second]", arrayList.ToString());
            arrayList.add(0, "third");
            Assert.AreEqual("[third, first, second]", arrayList.ToString());
        }

        [TestMethod]
        public void getTestCase()
        {
            ArrayList<String> arrayList = new ArrayList<String>();
            arrayList.add("first");
            arrayList.add("second");
            arrayList.add("third");
            Assert.AreEqual("first", arrayList.get(0).ToString());
            Assert.AreEqual("second", arrayList.get(1).ToString());
            Assert.AreEqual("third", arrayList.get(2).ToString());
        }

        [TestMethod]
        public void sizeTestCase()
        {
            ArrayList<String> arrayList = new ArrayList<String>();
            Assert.AreEqual(0, arrayList.size());
            arrayList.add("first");
            Assert.AreEqual(1, arrayList.size());
            arrayList.add("second");
            Assert.AreEqual(2, arrayList.size());
        }

        [TestMethod]
        public void isEmptyTestCase()
        {
            ArrayList<String> arrayList = new ArrayList<String>();
            Assert.IsTrue(arrayList.isEmpty());
            arrayList.add("first");
            Assert.IsFalse(arrayList.isEmpty());
            arrayList.add("second");
            Assert.IsFalse(arrayList.isEmpty());
        }

        [TestMethod]
        public void clearTestCase()
        {
            ArrayList<String> arrayList = new ArrayList<String>();
            arrayList.add("first");
            arrayList.add("second");
            arrayList.add("third");
            arrayList.clear();
            Assert.AreEqual("[]", arrayList.ToString());
            Assert.AreEqual(0, arrayList.size());
            Assert.IsTrue(arrayList.isEmpty());
        }

        [TestMethod]
        public void toStringTestCase()
        {
            ArrayList<String> arrayList = new ArrayList<String>();
            Assert.AreEqual(new String("[]").ToString(), arrayList.toString().ToString());
        }
    }
}
