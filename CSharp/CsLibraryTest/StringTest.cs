using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
    [TestClass]
	public class StringTest
	{
        /**
         * Tests the constructor with standard string as a parameter.
         */
        [TestMethod]
		public void stringTest()
        {
            String a;
            // a string with whitespaces
            a = "This is a test.";
            Assert.AreEqual("This is a test.", a);
            // letters
            a = "test";
            Assert.AreEqual("test", a);
            // digits
            a = "1234";
            Assert.AreEqual("1234", a);
            // one char
            a = "a";
            Assert.AreEqual("a", a);
            // empty string
            a = "";
            Assert.AreEqual("", a);
        }

        /**
         * Tests the constructor with array of bytes as a parameter.
         */
        [TestMethod]
		public void stringTest2()
        {
            sbyte[] a;
            String b;
            // array with some whitespaces
            a = new sbyte[] { (sbyte) 'T', (sbyte) 'h', (sbyte) 'i', (sbyte) 's', (sbyte) ' ', (sbyte) 'i', (sbyte) 's', (sbyte) ' ', (sbyte) 'a', (sbyte) ' ', (sbyte) 't', (sbyte) 'e', (sbyte) 's', (sbyte) 't', (sbyte) '.' };
            b = new String(a);
            Assert.AreEqual("This is a test.", b);
            // array without whitespaces
            a = new sbyte[] { (sbyte) '1', (sbyte) '2', (sbyte) '3', (sbyte) '4' };
            b = new String(a);
            Assert.AreEqual("1234", b);
            // empty array
            a = new sbyte[] { };
            b = new String(a);
            Assert.AreEqual("", b);
        }

        /**
         * Tests the constructor with array of bytes and indexes as parameters.
         */
        [TestMethod]
		public void stringTest3()
        {
            sbyte[] a;
            String b;
            // choosing a part of array with some chars
            a = new sbyte[] { (sbyte) 'T', (sbyte) 'h', (sbyte) 'i', (sbyte) 's', (sbyte) ' ', (sbyte) 'i', (sbyte) 's', (sbyte) ' ', (sbyte) 'a', (sbyte) ' ', (sbyte) 't', (sbyte) 'e', (sbyte) 's', (sbyte) 't', (sbyte) '.' };
            b = new String(a, 10, 4);
            Assert.AreEqual("test", b);
        }

        /**
         * Tests the compareTo method.
         */
        [TestMethod]
		public void compareToTest()
        {
            String a, b;
            int c;
            // differens strings at the beginning
            a = "aaa";
            b = "bbb";
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            // different strings at the end
            a = "aaaa";
            b = "aaab";
            c = a.compareTo(b);
            Assert.AreEqual(-1, c);
            // differens strings at the beginning (swapped)
            a = "bbb";
            b = "aaa";
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            // different strings at the end (swapped)
            a = "aaab";
            b = "aaaa";
            c = a.compareTo(b);
            Assert.AreEqual(1, c);
            // equal strings
            a = "aaa";
            b = "aaa";
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
        }

        /**
         * Tests the equals method.
         */
        [TestMethod]
		public void equalsTest()
        {
            String a, b;
            bool c;
            a = "aaa";
            b = "bbb";
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = "aaaa";
            b = "aaab";
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = "bbb";
            b = "aaa";
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = "aaab";
            b = "aaaa";
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = "aaa";
            b = "aaa";
            c = a.equals(b);
            Assert.AreEqual(true, c);
        }

        /**
         * Tests the substring method.
         */
        [TestMethod]
		public void substringTest()
        {
            String a, b;
            a = "This is a test.";
            // string from the beginning
            b = a.substring(0);
            Assert.AreEqual("This is a test.", b);
            // string from some other position
            b = a.substring(10);
            Assert.AreEqual("test.", b);
        }

        /**
         * Tests the substring method with end index as a parameter.
         */
        [TestMethod]
		public void substringTest2()
        {
            String a, b;
            a = "This is a test.";
            // string from the beginning to the position near the beginning
            b = a.substring(0, 4);
            Assert.AreEqual("This", b);
            // string from the beginning to the position far from the beginning
            b = a.substring(10, 14);
            Assert.AreEqual("test", b);
            // string from the end
            b = a.substring(14, 15);
            Assert.AreEqual(".", b);
            // equal indexes
            b = a.substring(10, 10);
            Assert.AreEqual("", b);
        }

        /**
         * Tests the indexOf method with a char value.
         */
        [TestMethod]
		public void indexOfTest()
        {
            String a;
            int b;
            a = "This is a test.";
            // char occurring once
            b = a.indexOf('a');
            Assert.AreEqual(8, b);
            // char occuring more times
            b = a.indexOf('t');
            Assert.AreEqual(10, b);
            // char occurring once (at the beginning)
            b = a.indexOf('T');
            Assert.AreEqual(0, b);
            // char occurring once (at the end)
            b = a.indexOf('.');
            Assert.AreEqual(14, b);
            // char not occurring
            b = a.indexOf('_');
            Assert.AreEqual(-1, b);
        }

        /**
         * Tests the indexOf method with a char value and end index as a parameter.
         */
        [TestMethod]
		public void indexOfTest2()
        {
            String a;
            int b;
            a = "This is a test.";
            b = a.indexOf('a', 10);
            Assert.AreEqual(-1, b);
            b = a.indexOf('t', 10);
            Assert.AreEqual(10, b);
            b = a.indexOf('i', 0);
            Assert.AreEqual(2, b);
            b = a.indexOf('i', 4);
            Assert.AreEqual(5, b);
            b = a.indexOf('i', 10);
            Assert.AreEqual(-1, b);
        }

        /**
         * Tests the indexOf method with a string.
         */
        [TestMethod]
		public void indexOfTest3()
        {
            String a;
            int b;
            a = "This is a test.";
            // occurring string (at the beginning)
            b = a.indexOf("This");
            Assert.AreEqual(0, b);
            // occurring string (at the end)
            b = a.indexOf("test");
            Assert.AreEqual(10, b);
            // non-occurring string
            b = a.indexOf("aaa");
            Assert.AreEqual(-1, b);
        }

        /**
         * Tests the indexOf method with a string and end index as a parameter.
         */
        [TestMethod]
		public void indexOfTest4()
        {
            String a;
            int b;
            a = "This is a test.";
            b = a.indexOf("This", 0);
            Assert.AreEqual(0, b);
            b = a.indexOf("test", 4);
            Assert.AreEqual(10, b);
            b = a.indexOf("This", 10);
            Assert.AreEqual(-1, b);
        }

        /**
         * Tests the length method.
         */
        [TestMethod]
		public void lengthTest()
        {
            String a;
            int b;
            // string with multiple chars
            a = "This is a test.";
            b = a.length();
            Assert.AreEqual(15, b);
            // string with one char
            a = ".";
            b = a.length();
            Assert.AreEqual(1, b);
            // empty string
            a = "";
            b = a.length();
            Assert.AreEqual(0, b);
        }

        /**
         * Tests the trim method.
         */
        [TestMethod]
		public void trimTest()
        {
            String a, b;
            // string without whitespaces
            a = "test";
            b = a.trim();
            Assert.AreEqual("test", b);
            // whitespaces on the left side
            a = "   test";
            b = a.trim();
            Assert.AreEqual("test", b);
            // whitespaces on the right side
            a = "test   ";
            b = a.trim();
            Assert.AreEqual("test", b);
            // whitespaces on bots sides
            a = " test ";
            b = a.trim();
            Assert.AreEqual("test", b);
            // whitespaces inside
            a = "t e s t";
            b = a.trim();
            Assert.AreEqual("t e s t", b);
        }

        /**
         * Tests the toLower method.
         */
        [TestMethod]
		public void toLowerCaseTest()
        {
            String a, b;
            // all letters lowercase
            a = "test";
            b = a.toLowerCase();
            Assert.AreEqual("test", b);
            // all letters uppercase
            a = "TEST";
            b = a.toLowerCase();
            Assert.AreEqual("test", b);
            // different cases
            a = "TesT";
            b = a.toLowerCase();
            Assert.AreEqual("test", b);
        }

        /**
         * Tests the toUpper method.
         */
        [TestMethod]
		public void toUpperCaseTest()
        {
            String a, b;
            a = "test";
            b = a.toUpperCase();
            Assert.AreEqual("TEST", b);
            a = "TEST";
            b = a.toUpperCase();
            Assert.AreEqual("TEST", b);
            a = "TesT";
            b = a.toUpperCase();
            Assert.AreEqual("TEST", b);
        }

        /**
         * Tests the charAt method.
         */
        [TestMethod]
		public void charAtTest()
        {
            String a;
            char b;
            a = "This is a test.";
            // at the beginning
            b = a.charAt(0);
            Assert.AreEqual('T', b);
            // in the middle
            b = a.charAt(10);
            Assert.AreEqual('t', b);
            // at the end
            b = a.charAt(14);
            Assert.AreEqual('.', b);
        }

        /**
         * Tests the replace method.
         */
        [TestMethod]
		public void replaceTest()
        {
            String a, b;
            a = "This is a test.";
            // replacing chars inside the string
            b = a.replace(' ', '_');
            Assert.AreEqual("This_is_a_test.", b);
            // replacing chars in the beginning of the string
            b = a.replace('T', 't');
            Assert.AreEqual("this is a test.", b);
            // replacing chars in the end of the string
            b = a.replace('.', '!');
            Assert.AreEqual("This is a test!", b);
            // replacing of the non-existent chars
            b = a.replace('?', ':');
            Assert.AreEqual("This is a test.", b);
        }

        /**
         * Tests the startsWith method.
         */
        [TestMethod]
		public void startsWithTest()
        {
            String a, b;
            bool c;
            a = "This is a test.";
            // string at the beginning
            b = "This ";
            c = a.startsWith(b);
            Assert.AreEqual(true, c);
            // string inside
            b = "is";
            c = a.startsWith(b);
            Assert.AreEqual(false, c);
            // string at the end
            b = "test.";
            c = a.startsWith(b);
            Assert.AreEqual(false, c);
        }

        /**
         * Tests the endsWith method.
         */
        [TestMethod]
		public void endsWithTest()
        {
            String a, b;
            bool c;
            a = "This is a test.";
            b = "This ";
            c = a.endsWith(b);
            Assert.AreEqual(false, c);
            b = "is";
            c = a.endsWith(b);
            Assert.AreEqual(false, c);
            b = "test.";
            c = a.endsWith(b);
            Assert.AreEqual(true, c);
        }

        /**
         * Tests the isEmpty method.
         */
        [TestMethod]
		public void isEmptyTest()
        {
            String a;
            bool b;
            // non-empty string
            a = "This is a test.";
            b = a.isEmpty();
            Assert.AreEqual(false, b);
            // non-empty string with a single char
            a = ".";
            b = a.isEmpty();
            Assert.AreEqual(false, b);
            // empty string
            a = "";
            b = a.isEmpty();
            Assert.AreEqual(true, b);
        }
        
    }

}

