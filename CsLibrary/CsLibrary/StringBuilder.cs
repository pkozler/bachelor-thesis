namespace JavaClasses
{

    /**
     * A mutable sequence of characters.
     *
     * @author Petr Kozler (A13B0359P)
     */
    public class StringBuilder
    {

        private System.Text.StringBuilder sb;

        /**
         * Constructs a string builder with no characters in it and an initial
         * capacity of 16 characters.
         */
        public StringBuilder() {
            sb = new System.Text.StringBuilder();
        }

        /**
         * Appends the specified string to this character sequence.
         *
         * @param str a string.
         * @return a reference to this object.
         */
        StringBuilder append(String str) {
            sb.Append(str.ToString());

            return this;
        }

        public override string ToString() {
            return toString().ToString();
        }

        /**
         * Returns a string representing the data in this sequence.
         *
         * @return a string representation of this sequence of characters.
         */
        public String toString() {
            return sb.ToString();
        }

    }

}
