namespace JavaClasses
{

    /// <summary>
    /// Resizable-array implementation of the List abstract class.
    /// </summary>
    /// <typeparam name="E">the type of elements in this list</typeparam>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class ArrayList<E> : List<E> where E : Object
    {

        // an inner list
        public System.Collections.Generic.List<E> l { get; private set; }

        /// <summary>
        /// Constructs an empty list with an initial capacity of ten.
        /// </summary>
        public ArrayList()
        {
            l = new System.Collections.Generic.List<E>(10);
        }

        /// <summary>
        /// Constructs a list containing the elements of the specified collection, in
        /// the order they are returned by the collection's iterator.
        /// </summary>
        /// <param name="c">the collection whose elements are to be placed into this list
        /// </param>
        public ArrayList(ArrayList<E> c)
        {
            l = new System.Collections.Generic.List<E>(c.l);
        }

        /// <summary>
        /// Appends the specified element to the end of this list.
        /// </summary>
        /// <param name="e">element to be appended to this list
        /// </param><returns>true
        /// </returns>
        public override bool add(E e)
        {
            l.Add(e);
            return true;
        }

        /// <summary>
        /// Inserts the specified element at the specified position in this list.
        /// </summary>
        /// <param name="index">index at which the specified element is to be inserted
        /// </param><param name="element">element to be inserted
        /// </param>
        public override void add(int index, E element)
        {
            l.Insert(index, element);
        }

        /// <summary>
        /// Returns the element at the specified position in this list.
        /// </summary>
        /// <param name="index">index of the element to return
        /// </param><returns>the element at the specified position in this list
        /// </returns>
        public override E get(int index)
        {
            return l[index];
        }

        /// <summary>
        /// Replaces the element at the specified position in this list with the
        /// specified element.
        /// </summary>
        /// <param name="index">index of the element to replace
        /// </param><param name="element">element to be stored at the specified position
        /// </param><returns>the element previously at the specified position
        /// </returns>
        public override E set(int index, E element)
        {
            // replacing the element on the specified index and returning its original value
            E original = l[index];
            l[index] = element;
            return original;
        }

        /// <summary>
        /// Removes the element at the specified position in this list.
        /// </summary>
        /// <param name="index">the index of the element to be removed
        /// </param><returns>the element that was removed from the list
        /// </returns>
        public override E remove(int index)
        {
            // removing the element on the specified index and returning its value
            E removed = l[index];
            l.RemoveAt(index);
            return removed;
        }

        /// <summary>
        /// Returns the number of elements in this list.
        /// </summary>
        /// <returns>the number of elements in this list
        /// </returns>
        public override int size()
        {
            return l.Count;
        }

        /// <summary>
        /// Removes all of the elements from this list.
        public override void clear()
        {
            l.Clear();
        }

        /// <summary>
        /// Returns a string representation of the object.
        /// </summary>
        /// <returns>a string representation of the object.
        /// </returns>
        public override String toString()
        {
            // create StringBuilder for appending the text
            System.Text.StringBuilder sb = new System.Text.StringBuilder();
            sb.Append("[");

            // append the first element string representation
            if (l.Count > 0)
            {
                sb.Append(l[0] == null ? "null" : l[0].ToString());
            }

            // append another elements string representation
            for (int i = 1; i < l.Count; i++)
            {
                sb.Append(", ").Append(l[i] == null ? "null" : l[i].ToString());
            }

            // create Java-like string
            return new String(sb.Append("]").ToString());
        }
        
    }

}
