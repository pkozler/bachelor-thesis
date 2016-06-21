using System.Collections.Generic;

namespace JavaClasses
{

    /// <summary>
    /// Doubly-linked list implementation of the List abstract class.
    /// </summary>
    /// <typeparam name="E">the type of elements held in this collection</typeparam>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class LinkedList<E> : List<E> where E : Object
    {

        // an inner list
        public System.Collections.Generic.LinkedList<E> l { get; private set; }

        /// <summary>
        /// Constructs an empty list.
        /// </summary>
        public LinkedList()
        {
            l = new System.Collections.Generic.LinkedList<E>();
        }

        /// <summary>
        /// Constructs a list containing the elements of the specified collection, in
        /// the order they are returned by the collection's iterator.
        /// </summary>
        /// <param name="c">the collection whose elements are to be placed into this list
        /// </param>
        public LinkedList(LinkedList<E> c)
        {
            l = new System.Collections.Generic.LinkedList<E>(c.l);
        }

        /// <summary>
        /// Appends the specified element to the end of this list.
        /// </summary>
        /// <param name="e">element to be appended to this list
        /// </param><returns>true
        /// </returns>
        public override bool add(E e)
        {
            l.AddLast(e);
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
            // creating the first node, if the list is empty
            if (l.Count < 1)
            {
                l.AddFirst(element);
                return;
            }

            LinkedListNode<E> node = l.First;

            // inserting the new element before the first node if index is 0
            if (index < 1)
            {
                l.AddBefore(node, element);
                return;
            }

            // iterating to the node at the specified position in the list
            for (int i = 1; i < index; i++)
            {
                node = node.Next;
            }

            // inserting the new element after the node
            l.AddAfter(node, element);
        }
        
        /// <summary>
        /// Returns the element at the specified position in this list.
        /// </summary>
        /// <param name="index">index of the element to return
        /// </param><returns>the element at the specified position in this list
        /// </returns>
        public override E get(int index)
        {
            LinkedListNode<E> node = l.First;

            // iterating to the node at the specified position in the list
            for (int i = 0; i < index; i++)
            {
                node = node.Next;
            }

            // returning the value of the node
            return node.Value;
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
            E original;

            // replacing the value of node at the beginning if the index is zero
            if (index < 1)
            {
                original = l.First.Value;
                l.First.Value = element;
                return original;
            }

            LinkedListNode<E> node = l.First;

            // iterating to the node at the specified position in the list
            for (int i = 0; i < index; i++)
            {
                node = node.Next;
            }

            // replacing the value of the node in the list and returning the original value
            original = node.Value;
            node.Value = element;
            return original;
        }

        /// <summary>
        /// Removes the element at the specified position in this list.
        /// </summary>
        /// <param name="index">the index of the element to be removed
        /// </param><returns>the element previously at the specified position
        /// </returns>
        public override E remove(int index)
        {
            E removed;

            // removing the node at the beginning if the index is zero
            if (index < 1)
            {
                removed = l.First.Value;
                l.RemoveFirst();
                return removed;
            }

            LinkedListNode<E> node = l.First;

            // iterating to the node at the specified position in the list
            for (int i = 0; i < index; i++)
            {
                node = node.Next;
            }

            // removing the node in the list and returning its value
            removed = node.Value;
            l.Remove(node);
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
        /// </summary>
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

            LinkedListNode<E> node = l.First;

            // append the first element string representation
            if (node != null)
            {
                sb.Append(node.Value == null ? "null" : node.Value.ToString());
                node = node.Next;
            }

            // append another elements string representation
            for (int i = 1; i < l.Count; i++)
            {
                sb.Append(", ").Append(node.Value == null ? "null" : node.Value.ToString());
                node = node.Next;
            }

            // create Java-like string
            return new String(sb.Append("]").ToString());
        }
        
    }

}

