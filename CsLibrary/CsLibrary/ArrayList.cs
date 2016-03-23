using JavaClasses;
using System.Collections.Generic;

namespace JavaClasses
{

    /// <summary>
    /// Resizable-array implementation of the List interface.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class ArrayList<E>
    {

        public List<E> l { get; private set; }

        /// <summary>
        /// Constructs an empty list with an initial capacity of ten.
        /// </summary>
        public ArrayList()
        {
            l = new List<E>(10);
        }

        /// <summary>
        /// Constructs a list containing the elements of the specified collection, in
        /// the order they are returned by the collection's iterator.
        /// </summary>
        /// <param name="c">the collection whose elements are to be placed into this list
        /// </param>
        public ArrayList(ArrayList<E> c)
        {
            l = new List<E>(c.l);
        }

        /// <summary>
        /// Appends the specified element to the end of this list.
        /// </summary>
        /// <param name="e">element to be appended to this list
        /// </param><returns>true (as specified by Collection.add(E))
        /// </returns>
        public bool add(E e)
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
        public void add(int index, E element)
        {
            l.Insert(index, element);
        }

        /// <summary>
        /// Compares the specified object with this list for equality.
        /// </summary>
        /// 
        /// <param name="o">the object to be compared for equality with this list</param>
        /// <returns>true if the specified object is equal to this list</returns>
        public bool equals(ArrayList<E> o)
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

            int length = size();

            // comparing the list sizes
            if (o.size() != length)
            {
                return false;
            }

            // comparing corresponding elements of lists
            for (int i = 0; i < length; i++)
            {
                E o1 = get(i);
                E o2 = o.get(i);
                bool equals = o1 == null ? o2 == null : o1.Equals(o2);

                if (!equals)
                {
                    return false;
                }
            }

            return true;
        }

        /// <summary>
        /// Returns the element at the specified position in this list.
        /// </summary>
        /// <param name="index">index of the element to return
        /// </param><returns>the element at the specified position in this list
        /// </returns>
        public E get(int index)
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
        public E set(int index, E element)
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
        public E remove(int index)
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
        public int size()
        {
            return l.Count;
        }

        /// <summary>
        /// Returns true if this list contains no elements.
        /// </summary>
        /// <returns>true if this list contains no elements
        /// </returns>
        public bool isEmpty()
        {
            return l.Count == 0;
        }

        /// <summary>
        /// Removes all of the elements from this list.
        public void clear()
        {
            l.Clear();
        }

        /// <summary>
        /// Returns a string representation of the object.
        /// </summary>
        /// <returns>a string representation of the object.
        /// </returns>
        public String toString()
        {
            StringBuilder sb = new StringBuilder();
            sb.append("[");

            if (l.Count > 0)
            {
                sb.append(l[0].ToString());
            }

            for (int i = 1; i < l.Count; i++)
            {
                sb.append(", ").append(l[i].ToString());
            }

            return sb.append("]").toString();
        }

        public override bool Equals(object obj)
        {
            return equals(obj as ArrayList<E>);
        }

        public override string ToString()
        {
            return toString();
        }

    }

}
