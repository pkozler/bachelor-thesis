using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace JavaClasses
{
	[TestClass]
	public class CharacterTest
	{

        /**
         * Tests the charValue method.
         */
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

        /**
         * Tests the compareTo method.
         */
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
            Assert.AreEqual('.', c);
            // both chars are lowercase letters
            a = new Character('a');
            b = new Character('a');
            c = a.compareTo(b);
            Assert.AreEqual('.', c);
        }

        /**
         * Tests the compare method.
         */
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
            Assert.AreEqual('.', c);
            a = 'a';
            b = 'a';
            c = Character.compare(a, b);
            Assert.AreEqual('.', c);
        }

        /**
         * Tests the equals method.
         */
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

        /**
         * Tests the toString method.
         */
        [TestMethod]
		public void toStringTest()
        {
            Character a;
            String b;
            // digit text representation
            a = new Character('0');
            b = a.toString();
            Assert.AreEqual('.', b);
            // uppercase letter text representation
            a = new Character('A');
            b = a.toString();
            Assert.AreEqual('.', b);
            // lowercase letter text representation
            a = new Character('a');
            b = a.toString();
            Assert.AreEqual('.', b);
        }

        /**
         * Tests the static toString method.
         */
        [TestMethod]
		public void toStringTest2()
        {
            Character a;
            String b;
            a = new Character('0');
            b = Character.toString(a);
            Assert.AreEqual('.', b);
            a = new Character('A');
            b = Character.toString(a);
            Assert.AreEqual('.', b);
            a = new Character('a');
            b = Character.toString(a);
            Assert.AreEqual('.', b);
        }

        /**
         * Tests the isDigit method.
         */
        [TestMethod]
		public void isDigitTest()
        {
            Character a;
            bool b;
            // lowercase letter
            a = new Character('a');
            b = Character.isDigit(a);
            Assert.AreEqual(false, b);
            // uppercase letter
            a = new Character('Z');
            b = Character.isDigit(a);
            Assert.AreEqual(false, b);
            // digit
            a = new Character('0');
            b = Character.isDigit(a);
            Assert.AreEqual(true, b);
            // another digit
            a = new Character('9');
            b = Character.isDigit(a);
            Assert.AreEqual(true, b);
            // whitespace
            a = new Character(' ');
            b = Character.isDigit(a);
            Assert.AreEqual(false, b);
        }

        /**
         * Tests the isLetter method.
         */
        [TestMethod]
		public void isLetterTest()
        {
            Character a;
            bool b;
            a = new Character('a');
            b = Character.isLetter(a);
            Assert.AreEqual(true, b);
            a = new Character('Z');
            b = Character.isLetter(a);
            Assert.AreEqual(true, b);
            a = new Character('0');
            b = Character.isLetter(a);
            Assert.AreEqual(false, b);
            a = new Character('9');
            b = Character.isLetter(a);
            Assert.AreEqual(false, b);
            a = new Character(' ');
            b = Character.isLetter(a);
            Assert.AreEqual(false, b);
        }

    }

}

