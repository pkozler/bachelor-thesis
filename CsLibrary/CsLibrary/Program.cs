namespace JavaClasses {

    class Program {
        /**
         * @author Petr Kozler (A13B0359P)
         */
        static void Main(string[] args) {
            Scanner sc = new Scanner (System_.in_);
			/*int i = sc.nextInt();
			System_.@out.println (i);*/

            ArrayList<String> arrayList = new ArrayList<String>();
            arrayList.add(0, "first");
            System_.out_.println(arrayList.toString());

            sc.nextLine();
        }
    }
}
