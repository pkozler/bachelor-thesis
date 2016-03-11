using System.Collections.Generic;

namespace JavaClasses {

    /**
     * Doubly-linked list implementation of the List and Deque interfaces.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class LinkedList<E> {

        public System.Collections.Generic.LinkedList<E> l { get; private set; }

        /**
         * Constructs an empty list.
         */
        public LinkedList() {
            l = new System.Collections.Generic.LinkedList<E>();
        }

        /**
         * Constructs a list containing the elements of the specified collection, in
         * the order they are returned by the collection's iterator.
         *
         * @param c the collection whose elements are to be placed into this list
         */
        public LinkedList(LinkedList<E> c) {
            l = new System.Collections.Generic.LinkedList<E>(c.l);
        }

        /**
         * Appends the specified element to the end of this list.
         *
         * @param e element to be appended to this list
         * @return true (as specified by Collection.add(E))
         */
        public bool add(E e) {
            l.AddLast(e);
            return true;
        }

        /**
         * Inserts the specified element at the specified position in this list.
         *
         * @param index index at which the specified element is to be inserted
         * @param element element to be inserted
         */
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

        /**
         * Returns the element at the specified position in this list.
         *
         * @param index index of the element to return
         * @return the element at the specified position in this list
         */
        public E get(int index) {
            LinkedListNode<E> node = l.First;

            // iterating to the node at the specified position in the list
            for (int i = 0; i < index; i++) {
                node = node.Next;
            }

            // returning the value of the node
            return node.Value;
        }

        /**
         * Replaces the element at the specified position in this list with the
         * specified element.
         *
         * @param index index of the element to replace
         * @param element element to be stored at the specified position
         * @return the element previously at the specified position
         */
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

        /**
         * Removes the element at the specified position in this list.
         *
         * @param index the index of the element to be removed
         * @return the element previously at the specified position
         */
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

        /**
         * Returns the number of elements in this list.
         *
         * @return the number of elements in this list
         */
        public int size() {
            return l.Count;
        }

        /**
         * Returns true if this list contains no elements.
         *
         * @return true if this list contains no elements
         */
        public bool isEmpty() {
            return l.Count == 0;
        }

        /**
         * Removes all of the elements from this list.
         */
        public void clear() {
            l.Clear();
        }

        /**
         * Returns a string representation of the object.
         *
         * @return a string representation of the object.
         */
        public String toString() {
            return new String(ToString());
        }

    }

}

