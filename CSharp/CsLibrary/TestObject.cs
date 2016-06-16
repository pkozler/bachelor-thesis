namespace JavaClasses
{

    /// <summary>
    /// The TestObject class represents a simple object that serves
    /// for demonstration the functionality of libraries working with objects.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class TestObject : Comparable
    {
        // string value
        private String str;
        // integer value
        private int i;
        
        /// <summary>
        /// Creates a new object.
        /// </summary>
        /// <param name="str">string value</param>
        /// <param name="i">integer value</param>
        public TestObject(String str, int i)
        {
            this.str = str;
            this.i = i;
        }
        
        /// <summary>
        /// Returns a value of the string field.
        /// </summary>
        /// <returns>string value</returns>
        public String getStr()
        {
            return str;
        }
        
        /// <summary>
        /// Changes a value of the string field.
        /// </summary>
        /// <param name="str">string value</param>
        public void setStr(String str)
        {
            this.str = str;
        }
        
        /// <summary>
        /// Returns a value of the integer field.
        /// </summary>
        /// <returns>integer value</returns>
        public int getI()
        {
            return i;
        }
        
        /// <summary>
        /// Changes a value of the integer field.
        /// </summary>
        /// <param name="i">integer value</param>
        public void setI(int i)
        {
            this.i = i;
        }
        
        /// <summary>
        /// Indicates whether some other object is equal to this one.
        /// </summary>
        /// <param name="obj">another object</param>
        /// <returns>TRUE if objects are equal, FALSE otherwise</returns>
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

            TestObject other = obj as TestObject;

            return i == other.i;
        }
        
        /// <summary>
        /// Returns a string representation of the object.
        /// </summary>
        /// <returns>string representation</returns>
        public override String toString()
        {
            return new String("TestObject [str=" + str.s + ", i=" + i + "]");
        }
        
        /// <summary>
        /// Compares this object with the specified object for order.
        /// </summary>
        /// <param name="o">another object</param>
        /// <returns>comparison result</returns>
        public override int compareTo(Object o)
        {
            return i - (o as TestObject).i;
        }
        
    }

}
