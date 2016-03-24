namespace JavaClasses
{
    
    /**
     * The {@code TestObject} class represents a simple object that serves
     * for demonstration the functionality of libraries working with objects.
     *
     * @author Petr Kozler
     */
    public class TestObject : Comparable<TestObject>
    {
        private String str;
        private int i;

        /**
         * Creates a new object.
         *
         * @param str string value
         * @param i integer value
         */
        public TestObject(String str, int i)
        {
            this.str = str;
            this.i = i;
        }

        /**
         * Returns a value of the string field.
         *
         * @return string value
         */
        public String getStr()
        {
            return str;
        }

        /**
         * Changes a value of the string field.
         *
         * @param str string value
         */
        public void setStr(String str)
        {
            this.str = str;
        }

        /**
         * Returns a value of the integer field.
         *
         * @return integer value
         */
        public int getI()
        {
            return i;
        }

        /**
         * Changes a value of the integer field.
         *
         * @param i integer value
         */
        public void setI(int i)
        {
            this.i = i;
        }
        
        /**
         * Indicates whether some other object is equal to this one.
         *
         * @param obj another object
         * @return TRUE if objects are equal, FALSE otherwise
         */
        public override bool equals(Object obj)
        {
            if (obj == null)
            {
                return false;
            }

            if (GetType() != obj.GetType())
            {
                return false;
            }

            TestObject other = (TestObject)obj;

            return i == other.i;
        }

        /**
         * Returns a string representation of the object.
         *
         * @return string representation
         */
        public override String toString()
        {
            return new String("TestObject [str=" + str.s + ", i=" + i + "]");
        }
        
        /**
         * Compares this object with the specified object for order.
         *
         * @param o another object
         * @return comparison result
         */
        public override int compareTo(TestObject o)
        {
            return i - o.i;
        }
        
    }

}
