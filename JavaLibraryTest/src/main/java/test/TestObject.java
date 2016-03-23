package test;

/**
 * The {@code TestObject} class represents a simple object that serves
 * for demonstration the functionality of libraries working with objects.
 *
 * @author Petr Kozler
 */
public class TestObject implements Comparable<TestObject> {

    private String str;
    private int i;

    /**
     * Creates a new object.
     *
     * @param str string value
     * @param i integer value
     */
    public TestObject(String str, int i) {
        this.str = str;
        this.i = i;
    }

    /**
     * Returns a value of the string field.
     *
     * @return string value
     */
    public String getStr() {
        return str;
    }

    /**
     * Changes a value of the string field.
     *
     * @param str string value
     */
    public void setStr(String str) {
        this.str = str;
    }

    /**
     * Returns a value of the integer field.
     *
     * @return integer value
     */
    public int getI() {
        return i;
    }

    /**
     * Changes a value of the integer field.
     *
     * @param i integer value
     */
    public void setI(int i) {
        this.i = i;
    }

    /**
     * Returns a hash code value for the object.
     *
     * @return objects hashcode
     */
    @Override
    public int hashCode() {
        int hash = 7;
        hash = 31 * hash + this.i;

        return hash;
    }

    /**
     * Indicates whether some other object is equal to this one.
     *
     * @param obj another object
     * @return TRUE if objects are equal, FALSE otherwise
     */
    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }

        if (getClass() != obj.getClass()) {
            return false;
        }

        final TestObject other = (TestObject) obj;

        return this.i == other.i;
    }

    /**
     * Returns a string representation of the object.
     *
     * @return string representation
     */
    @Override
    public String toString() {
        return "TestObject [str=" + str + ", i=" + i + "]";
    }

    /**
     * Compares this object with the specified object for order.
     *
     * @param o another object
     * @return comparison result
     */
    @Override
    public int compareTo(TestObject o) {
        return this.i - o.i;
    }

}
