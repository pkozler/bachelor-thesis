namespace JavaClasses
{
    class Object
    {
        public bool equals(Object obj)
        {
            return this == obj;
        }

        public String toString()
        {
            return "";
        }

        public override bool Equals(object obj)
        {
            return equals(obj as Object);
        }

        public override string ToString()
        {
            return toString();
        }
    }
}
