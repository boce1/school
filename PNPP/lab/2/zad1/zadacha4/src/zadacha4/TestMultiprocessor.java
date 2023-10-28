package zadacha4;

public class TestMultiprocessor {

	public static void main(String[] args) {
		Multiprocessor m1 = new Multiprocessor(4, 4, 3.7);
		System.out.println(m1.toString());
		System.out.println(m1.time(20));
	}

}
