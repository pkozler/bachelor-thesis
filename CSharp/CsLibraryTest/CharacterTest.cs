using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class CharacterTest
	{

        /// <summary>
        /// Tests the charValue method.
        /// </summary>
        [TestMethod]
		public void charValueTest()
        {
            Character a;
            char b;
            // uppercase letter
            a = new Character('A');
            b = a.charValue();
            Assert.AreEqual('.', b);
            // lowercase letter
            a = new Character('a');
            b = a.charValue();
            Assert.AreEqual('.', b);
            // digit
            a = new Character('0');
            b = a.charValue();
            Assert.AreEqual('.', b);
        }

        /// <summary>
        /// Tests the compareTo method.
        /// </summary>
        [TestMethod]
		public void compareToTest()
        {
            Character a, b;
            int c;
            // digit and uppercase letter
            a = new Character('9');
            b = new Character('Z');
            c = a.compareTo(b);
            Assert.AreEqual(-33, c);
            // lowercase letter and digit
            a = new Character('z');
            b = new Character('9');
            c = a.compareTo(b);
            Assert.AreEqual(65, c);
            // lowercase and uppercase letters
            a = new Character('z');
            b = new Character('A');
            c = a.compareTo(b);
            Assert.AreEqual(57, c);
            // uppercase and lowercase letters
            a = new Character('Z');
            b = new Character('a');
            c = a.compareTo(b);
            Assert.AreEqual(-7, c);
            // both chars are uppercase letters
            a = new Character('Z');
            b = new Character('Z');
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
            // both chars are lowercase letters
            a = new Character('a');
            b = new Character('a');
            c = a.compareTo(b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the compare method.
        /// </summary>
        [TestMethod]
		public void compareTest()
        {
            char a, b;
            int c;
            a = '9';
            b = 'Z';
            c = Character.compare(a, b);
            Assert.AreEqual(-33, c);
            a = 'z';
            b = '9';
            c = Character.compare(a, b);
            Assert.AreEqual(65, c);
            a = 'z';
            b = 'A';
            c = Character.compare(a, b);
            Assert.AreEqual(57, c);
            a = 'Z';
            b = 'a';
            c = Character.compare(a, b);
            Assert.AreEqual(-7, c);
            a = 'Z';
            b = 'Z';
            c = Character.compare(a, b);
            Assert.AreEqual(0, c);
            a = 'a';
            b = 'a';
            c = Character.compare(a, b);
            Assert.AreEqual(0, c);
        }

        /// <summary>
        /// Tests the equals method.
        /// </summary>
        [TestMethod]
		public void equalsTest()
        {
            Character a, b;
            bool c;
            a = new Character('9');
            b = new Character('Z');
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Character('z');
            b = new Character('9');
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Character('z');
            b = new Character('A');
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Character('Z');
            b = new Character('a');
            c = a.equals(b);
            Assert.AreEqual(false, c);
            a = new Character('Z');
            b = new Character('Z');
            c = a.equals(b);
            Assert.AreEqual(true, c);
            a = new Character('a');
            b = new Character('a');
            c = a.equals(b);
            Assert.AreEqual(true, c);
        }

        /// <summary>
        /// Tests the toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest()
        {
            Character a;
            String b;
            // digit text representation
            a = new Character('0');
            b = a.toString();
            Assert.AreEqual("0", b);
            // uppercase letter text representation
            a = new Character('A');
            b = a.toString();
            Assert.AreEqual("A", b);
            // lowercase letter text representation
            a = new Character('a');
            b = a.toString();
            Assert.AreEqual("a", b);
        }

        /// <summary>
        /// Tests the static toString method.
        /// </summary>
        [TestMethod]
		public void toStringTest2()
        {
            char a;
            String b;
            a = '0';
            b = Character.toString(a);
            Assert.AreEqual("0", b);
            a = 'A';
            b = Character.toString(a);
            Assert.AreEqual("A", b);
            a = 'a';
            b = Character.toString(a);
            Assert.AreEqual("a", b);
        }

        /// <summary>
        /// Tests the isDigit method.
        /// </summary>
        [TestMethod]
		public void isDigitTest()
        {
            char a;
            bool b;
            // lowercase letter
            a = 'a';
            b = Character.isDigit(a);
            Assert.AreEqual(false, b);
            // uppercase letter
            a = 'Z';
            b = Character.isDigit(a);
            Assert.AreEqual(false, b);
            // digit
            a = '0';
            b = Character.isDigit(a);
            Assert.AreEqual(true, b);
            // another digit
            a = '9';
            b = Character.isDigit(a);
            Assert.AreEqual(true, b);
            // whitespace
            a = ' ';
            b = Character.isDigit(a);
            Assert.AreEqual(false, b);
        }

        /// <summary>
        /// Tests the isLetter method.
        /// </summary>
        [TestMethod]
		public void isLetterTest()
        {
            char a;
            bool b;
            a = 'a';
            b = Character.isLetter(a);
            Assert.AreEqual(true, b);
            a = 'Z';
            b = Character.isLetter(a);
            Assert.AreEqual(true, b);
            a = '0';
            b = Character.isLetter(a);
            Assert.AreEqual(false, b);
            a = '9';
            b = Character.isLetter(a);
            Assert.AreEqual(false, b);
            a = ' ';
            b = Character.isLetter(a);
            Assert.AreEqual(false, b);
        }

    }

}

