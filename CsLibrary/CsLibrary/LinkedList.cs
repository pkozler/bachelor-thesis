using System.Collections.Generic;

namespace JavaClasses {

    /// <summary>
    /// Doubly-linked list implementation of the List and Deque interfaces.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class LinkedList<E> {

        public System.Collections.Generic.LinkedList<E> l { get; private set; }

        /// <summary>
        /// Constructs an empty list.
        /// </summary>
        public LinkedList() {
            l = new System.Collections.Generic.LinkedList<E>();
        }

        /// <summary>
        /// Constructs a list containing the elements of the specified collection, in
        /// the order they are returned by the collection's iterator.
        /// </summary>
        /// <param name="c">the collection whose elements are to be placed into this list
        /// </param>
        public LinkedList(LinkedList<E> c) {
            l = new System.Collections.Generic.LinkedList<E>(c.l);
        }

        /// <summary>
        /// Appends the specified element to the end of this list.
        /// </summary>
        /// <param name="e">element to be appended to this list
        /// </param><returns>true (as specified by Collection.add(E))
        /// </returns>
        public bool add(E e) {
            l.AddLast(e);
            return true;
        }

        /// <summary>
        /// Inserts the specified element at the specified position in this list.
        /// </summary>
        /// <param name="index">index at which the specified element is to be inserted
        /// </param><param name="element">element to be inserted
        /// </param>
        public void add(int index, E element) {
            // creating the first node, if the list is empty
            if (index < 1) {
                l.AddFirst(element);
                return;
            }

            LinkedListNode<E> node = l.First;

            // iterating to the node at the specified position in the list
            for (int i = 0; i < index; i++) {
                node = node.Next;
            }

            // inserting the new element before the node
            l.AddBefore(node, element);
        }

        /// <summary>
        /// Returns the element at the specified position in this list.
        /// </summary>
        /// <param name="index">index of the element to return
        /// </param><returns>the element at the specified position in this list
        /// </returns>
        public E get(int index) {
            LinkedListNode<E> node = l.First;

            // iterating to the node at the specified position in the list
            for (int i = 0; i < index; i++) {
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
        public E set(int index, E element) {
            E original;

            // replacing the value of node at the beginning if the index is zero
            if (index < 1) {
                original = l.First.Value;
                l.First.Value = element;
                return original;
            }

            LinkedListNode<E> node = l.First;

            // iterating to the node at the specified position in the list
            for (int i = 0; i < index; i++) {
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
        public E remove(int index) {
            E removed;

            // removing the node at the beginning if the index is zero
            if (index < 1) {
                removed = l.First.Value;
                l.RemoveFirst();
                return removed;
            }

            LinkedListNode<E> node = l.First;

            // iterating to the node at the specified position in the list
            for (int i = 0; i < index; i++) {
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
        public int size() {
            return l.Count;
        }

        /// <summary>
        /// Returns true if this list contains no elements.
        /// </summary>
        /// <returns>true if this list contains no elements
        /// </returns>
        public bool isEmpty() {
            return l.Count == 0;
        }

        /// <summary>
        /// Removes all of the elements from this list.
        /// </summary>
        public void clear() {
            l.Clear();
        }

        /// <summary>
        /// Returns a string representation of the object.
        /// </summary>
        /// <returns>a string representation of the object.
        /// </returns>
        public String toString() {
            return new String(ToString());
        }

    }

}

