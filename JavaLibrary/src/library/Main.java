package library;

import java.util.Arrays;

public class Main {

	private static class TestObject implements Comparable<TestObject>
	{
		private String str;
		private int i;

		public TestObject(String str, int i)
		{
			this.str = str;
			this.i = i;
		}

		@Override
		public String toString ()
		{
			return "TestObject [str=" + str + ", i=" + i + "]";
		}

		@Override
		public int compareTo(TestObject o) {
			return this.i - o.i;
		}
		
	}
	
	public static void main(String[] args) {
		/*ArrayList<String> arrayList = new ArrayList<String> ();
		arrayList.add (0, "first");
		System.out.println(arrayList);
		arrayList.add (1, "second");
		System.out.println(arrayList);
		arrayList.add (0, "third");
		System.out.println(arrayList);*/
		
		/*int[] array = new int[]{3, 2, 8, 7, 6};
		Arrays.sort (array);
		System.out.println(Arrays.toString(array));
		array = new int[]{3, 2, 8, 7, 6};
		Arrays.sort (array, 1, 4);
		System.out.println(Arrays.toString(array));*/
		
		/*TestObject[] array2 = new TestObject[]{
				new TestObject("first", 3),
				new TestObject("second", 2),
				new TestObject("third", 8),
				new TestObject("fourth", 7),
				new TestObject("fifth", 6),
				new TestObject("sixth", 3),
				new TestObject("seventh", 2),
				new TestObject("eighth", 8),
				new TestObject("nineth", 7),
				new TestObject("tenth", 6),
				};
		Arrays.sort (array2);
		System.out.println(Arrays.toString(array2));
		
		array2 = new TestObject[]{
				new TestObject("first", 3),
				new TestObject("second", 2),
				new TestObject("third", 7),
				new TestObject("fourth", 8),
				new TestObject("fifth", 6),
				};
		Arrays.sort (array2, 2, 8);
		System.out.println(Arrays.toString(array2));*/
		
		/*int[] array = new int[]{3, 2, 8, 7, 6};
		System.out.println(Arrays.toString(array));
		double[] array2 = new double[]{3, 2, 8, 7, 6};
		System.out.println(Arrays.toString(array2));
		char[] array3 = new char[]{'c', 'b', 'h', 'g', 'f'};
		System.out.println(Arrays.toString(array3));
		boolean[] array4 = new boolean[]{true, true, false, true, false, false};
		System.out.println(Arrays.toString(array4));*/
	}

}
