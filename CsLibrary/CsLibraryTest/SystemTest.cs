namespace JavaClasses
{
    
    public class SystemTest
    {
        
        /// <summary>
        /// Tests the print method with a bool value.
        /// </summary>
        public void printTest()
        {
            bool a;
            // print of bool values
            a = true;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = false;
            System_.out_.print(a);
            System_.out_.print("\n");
        }
        
        /// <summary>
        /// Tests the print method with a char value.
        /// </summary>
        public void printTest2()
        {
            char a;
            // print of lowercase letters
            a = 'a';
            System_.out_.print(a);
            System_.out_.print("\n");
            a = 'z';
            System_.out_.print(a);
            System_.out_.print("\n");
            // print of uppercase letters
            a = 'A';
            System_.out_.print(a);
            System_.out_.print("\n");
            a = 'Z';
            System_.out_.print(a);
            System_.out_.print("\n");
            // print of digits
            a = '0';
            System_.out_.print(a);
            System_.out_.print("\n");
            a = '9';
            System_.out_.print(a);
            System_.out_.print("\n");
        }

        /// <summary>
        /// Tests the print method with array of chars.
        /// </summary>
        public void printTest3()
        {
            char[] a;
            // empty char array
            a = new char[] { };
            System_.out_.print(a);
            System_.out_.print("\n");
            // char array with one char
            a = new char[] { 'a' };
            System_.out_.print(a);
            System_.out_.print("\n");
            // char array with some chars
            a = new char[] { 'a', 'z', 'A', 'Z', '0', '9' };
            System_.out_.print(a);
            System_.out_.print("\n");
        }

        /// <summary>
        /// Tests the print method with a double value.
        /// </summary>
        public void printTest4()
        {
            double a;
            // zeros with and without sign
            a = 0;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = -0;
            System_.out_.print(a);
            System_.out_.print("\n");
            // ones with and without sign
            a = 1;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = -1;
            System_.out_.print(a);
            System_.out_.print("\n");
            // maximal absolute value with and without sign
            a = Double.MAX_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = -Double.MAX_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
            // minimal absolute value with and without sign
            a = Double.MIN_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = -Double.MIN_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
        }

        /// <summary>
        /// Tests the print method with a float value.
        /// </summary>
        public void printTest5()
        {
            float a;
            a = 0;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = -0;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = 1;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = -1;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = Float.MAX_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = -Float.MAX_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = Float.MIN_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = -Float.MIN_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
        }

        /// <summary>
        /// Tests the print method with an int value.
        /// </summary>
        public void printTest6()
        {
            int a;
            // zero
            a = 0;
            System_.out_.print(a);
            System_.out_.print("\n");
            // ones with and without sign
            a = 1;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = -1;
            System_.out_.print(a);
            System_.out_.print("\n");
            // maximal and minimal value
            a = Integer.MAX_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = Integer.MIN_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
        }

        /// <summary>
        /// Tests the print method with a long value.
        /// </summary>
        public void printTest7()
        {
            long a;
            a = 0;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = 1;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = -1;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = Long.MAX_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
            a = Long.MIN_VALUE;
            System_.out_.print(a);
            System_.out_.print("\n");
        }

        /// <summary>
        /// Tests the print method with an object.
        /// </summary>
        public void printTest8()
        {
            TestObject a;
            // object with an empty string
            a = new TestObject("", 0);
            System_.out_.print(a);
            System_.out_.print("\n");
            // object with digits
            a = new TestObject("0", 1);
            System_.out_.print(a);
            System_.out_.print("\n");
            a = new TestObject("9", -1);
            System_.out_.print(a);
            System_.out_.print("\n");
            // object with letters
            a = new TestObject("Aa", Integer.MAX_VALUE);
            System_.out_.print(a);
            System_.out_.print("\n");
            a = new TestObject("Zz", Integer.MIN_VALUE);
            System_.out_.print(a);
            System_.out_.print("\n");
        }

        /// <summary>
        /// Tests the print method with a string.
        /// </summary>
        public void printTest9()
        {
            String a;
            // empty string
            a = "";
            System_.out_.print(a);
            System_.out_.print("\n");
            // string with one char
            a = "a";
            System_.out_.print(a);
            System_.out_.print("\n");
            // string with some chars
            a = "azAZ09";
            System_.out_.print(a);
            System_.out_.print("\n");
        }

        /// <summary>
        /// Tests the println method.
        /// </summary>
        public void printlnTest()
        {
            // print of an empty line 
            String a = "";
            System_.out_.println();
        }

        /// <summary>
        /// Tests the println method with a bool value.
        /// </summary>
        public void printlnTest2()
        {
            bool a;
            a = true;
            System_.out_.println(a);
            a = false;
            System_.out_.println(a);
        }

        /// <summary>
        /// Tests the println method with a char value.
        /// </summary>
        public void printlnTest3()
        {
            char a;
            a = 'a';
            System_.out_.println(a);
            a = 'z';
            System_.out_.println(a);
            a = 'A';
            System_.out_.println(a);
            a = 'Z';
            System_.out_.println(a);
            a = '0';
            System_.out_.println(a);
            a = '9';
            System_.out_.println(a);
        }

        /// <summary>
        /// Tests the println method with array of chars.
        /// </summary>
        public void printlnTest4()
        {
            char[] a;
            a = new char[] { };
            System_.out_.println(a);
            a = new char[] { 'a' };
            System_.out_.println(a);
            a = new char[] { 'a', 'z', 'A', 'Z', '0', '9' };
            System_.out_.println(a);
        }

        /// <summary>
        /// Tests the println method with a double value.
        /// </summary>
        public void printlnTest5()
        {
            double a;
            a = 0;
            System_.out_.println(a);
            a = -0;
            System_.out_.println(a);
            a = 1;
            System_.out_.println(a);
            a = -1;
            System_.out_.println(a);
            a = Double.MAX_VALUE;
            System_.out_.println(a);
            a = -Double.MAX_VALUE;
            System_.out_.println(a);
            a = Double.MIN_VALUE;
            System_.out_.println(a);
            a = -Double.MIN_VALUE;
            System_.out_.println(a);
        }

        /// <summary>
        /// Tests the println method with a float value.
        /// </summary>
        public void printlnTest6()
        {
            float a;
            a = 0;
            System_.out_.println(a);
            a = -0;
            System_.out_.println(a);
            a = 1;
            System_.out_.println(a);
            a = -1;
            System_.out_.println(a);
            a = Float.MAX_VALUE;
            System_.out_.println(a);
            a = -Float.MAX_VALUE;
            System_.out_.println(a);
            a = Float.MIN_VALUE;
            System_.out_.println(a);
            a = -Float.MIN_VALUE;
            System_.out_.println(a);
        }

        /// <summary>
        /// Tests the println method with an int value.
        /// </summary>
        public void printlnTest7()
        {
            int a;
            a = 0;
            System_.out_.println(a);
            a = 1;
            System_.out_.println(a);
            a = -1;
            System_.out_.println(a);
            a = Integer.MAX_VALUE;
            System_.out_.println(a);
            a = Integer.MIN_VALUE;
            System_.out_.println(a);
        }

        /// <summary>
        /// Tests the println method with a long value.
        /// </summary>
        public void printlnTest8()
        {
            long a;
            a = 0;
            System_.out_.println(a);
            a = 1;
            System_.out_.println(a);
            a = -1;
            System_.out_.println(a);
            a = Long.MAX_VALUE;
            System_.out_.println(a);
            a = Long.MIN_VALUE;
            System_.out_.println(a);
        }

        /// <summary>
        /// Tests the println method with an object.
        /// </summary>
        public void printlnTest9()
        {
            TestObject a;
            a = new TestObject("", 0);
            System_.out_.println(a);
            a = new TestObject("0", 1);
            System_.out_.println(a);
            a = new TestObject("9", -1);
            System_.out_.println(a);
            a = new TestObject("Aa", Integer.MAX_VALUE);
            System_.out_.println(a);
            a = new TestObject("Zz", Integer.MIN_VALUE);
            System_.out_.println(a);
        }

        /// <summary>
        /// Tests the println method with a string.
        /// </summary>
        public void printlnTest10()
        {
            String a;
            a = "";
            System_.out_.println(a);
            a = "a";
            System_.out_.println(a);
            a = "azAZ09";
            System_.out_.println(a);
        }

    }

}