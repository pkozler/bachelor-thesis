namespace JavaClasses {

    /// <summary>
    /// A mutable sequence of characters.
    /// </summary>
    /// <author>Petr Kozler (A13B0359P)</author>
    public class StringBuilder {

        private System.Text.StringBuilder sb;

        /// <summary>
        /// Constructs a string builder with no characters in it and an initial
        /// capacity of 16 characters.
        /// </summary>
        public StringBuilder() {
            sb = new System.Text.StringBuilder();
        }

        /// <summary>
        /// Appends the specified string to this character sequence.
        /// </summary>
        /// <param name="str">a string.
        /// </param><returns>a reference to this object.
        /// </returns>
        StringBuilder append(String str) {
            sb.Append(str.ToString());

            return this;
        }

        public override string ToString() {
            return toString().ToString();
        }

        /// <summary>
        /// Returns a string representing the data in this sequence.
        /// </summary>
        /// <returns>a string representation of this sequence of characters.
        /// </returns>
        public String toString() {
            return sb.ToString();
        }

    }

}
