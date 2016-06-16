using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{

    /// <summary>
    /// A StringBuilder class test suite.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    [TestClass]
    public class StringBuilderTest
    {

        /// <summary>
        /// Tests the constructor.
        /// </summary>
        [TestMethod]
		public void stringBuilderTest()
        {
            StringBuilder a;
            String b;
            // new empty stringbuilder
            a = new StringBuilder();
            b = a.toString();
            Assert.AreEqual("", b);
        }

        /// <summary>
        /// Tests the append method.
        /// </summary>
        [TestMethod]
		public void appendTest()
        {
            StringBuilder a;
            String b;
            // appending of empty string
            a = new StringBuilder();
            a.append("");
            b = a.toString();
            Assert.AreEqual("", b);
            // appending of one char
            a = new StringBuilder();
            a.append(".");
            b = a.toString();
            Assert.AreEqual(".", b);
            // appending of more chars
            a = new StringBuilder();
            a.append("test");
            b = a.toString();
            Assert.AreEqual("test", b);
            // multiple appendings (empty string at the beginning)
            a = new StringBuilder();
            a.append("test");
            a.append(".");
            a.append("");
            b = a.toString();
            Assert.AreEqual("test.", b);
            // multiple appendings (empty string in the middle)
            a = new StringBuilder();
            a.append(".");
            a.append("");
            a.append("test");
            b = a.toString();
            Assert.AreEqual(".test", b);
            // multiple appendings (empty string at the end)
            a = new StringBuilder();
            a.append("");
            a.append("test");
            a.append(".");
            b = a.toString();
            Assert.AreEqual("test.", b);
        }

        /// <summary>
        /// Tests the toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest()
        {
            StringBuilder a;
            String b;
            // appending a string at once
            a = new StringBuilder();
            a.append("This is a test");
            b = a.toString();
            Assert.AreEqual("This is a test", b);
            // appending a string piecewise
            a = new StringBuilder();
            a.append("This").append(" is").append(" a").append(" test.");
            b = a.toString();
            Assert.AreEqual("This is a test.", b);
            // appending a string piecewise (more pieces)
            a = new StringBuilder();
            a.append("This").append(" ").append("is").append(" ").append("a").append(" ").append("test").append(".");
            b = a.toString();
            Assert.AreEqual("This is a test.", b);
        }

    }
}
