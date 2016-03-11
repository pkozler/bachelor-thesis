using System.Collections.Generic;

namespace JavaClasses {

    /**
     * Resizable-array implementation of the List interface.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class ArrayList<E> {

        public List<E> l { get; private set; }

        /**
         * Constructs an empty list with an initial capacity of ten.
         */
        public ArrayList() {
            l = new List<E>(10);
        }

        /**
         * Constructs a list containing the elements of the specified collection, in
         * the order they are returned by the collection's iterator.
         *
         * @param c the collection whose elements are to be placed into this list
         */
        public ArrayList(ArrayList<E> c) {
            l = new List<E>(c.l);
        }
        
        /**
         * Appends the specified element to the end of this list.
         *
         * @param e element to be appended to this list
         * @return true (as specified by Collection.add(E))
         */
        public bool add(E e) {
            l.Add(e);
            return true;
        }

        /**
         * Inserts the specified element at the specified position in this list.
         *
         * @param index index at which the specified element is to be inserted
         * @param element element to be inserted
         */
        public void add(int index, E element) {
            l.Insert(index, element);
        }

        /**
         * Returns the element at the specified position in this list.
         *
         * @param index index of the element to return
         * @return the element at the specified position in this list
         */
        public E get(int index) {
            return l[index];
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
            // replacing the element on the specified index and returning its original value
            E original = l[index];
            l[index] = element;
            return original;
        }

        /**
         * Removes the element at the specified position in this list.
         *
         * @param index the index of the element to be removed
         * @return the element that was removed from the list
         */
        public E remove(int index) {
            // removing the element on the specified index and returning its value
            E removed = l[index];
            l.RemoveAt(index);
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
