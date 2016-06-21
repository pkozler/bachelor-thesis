namespace JavaClasses
{

    /// <summary>
    /// An ordered collection (also known as a sequence).
    /// </summary>
    /// <typeparam name="E">the type of elements in this list</typeparam>
    /// <author>Petr Kozler (A13B0359P)</author>
    public abstract class List<E> : Object where E : Object
    {
        
        public abstract bool add(E e);
        
        public abstract void add(int index, E element);

        /// <summary>
        /// Compares the specified object with this list for equality.
        /// </summary>
        /// <param name="o">the object to be compared for equality with this list</param>
        /// <returns>true if the specified object is equal to this list</returns>
        public override bool equals(Object o)
        {
            // comparing references
            if (this == o)
            {
                return true;
            }

            // testing the references for a NULL value
            if (o == null)
            {
                return false;
            }

            List<E> other = o as List<E>;
            int length = size();

            // comparing the list sizes
            if (other.size() != length)
            {
                return false;
            }

            // comparing the corresponding elements of the lists
            for (int i = 0; i < length; i++)
            {
                E o1 = get(i);
                E o2 = other.get(i);
                bool equals = o1 == null ? o2 == null : o1.Equals(o2);

                if (!equals)
                {
                    return false;
                }
            }

            return true;
        }
        
        public abstract E get(int index);
        
        public abstract E set(int index, E element);
        
        public abstract E remove(int index);
        
        public abstract int size();

        /// <summary>
        /// Returns true if this list contains no elements.
        /// </summary>
        /// <returns>true if this list contains no elements
        /// </returns>
        public virtual bool isEmpty()
        {
            return size() == 0;
        }
        
        public abstract void clear();

    }

}
