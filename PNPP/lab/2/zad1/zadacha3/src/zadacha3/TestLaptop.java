package zadacha3;

public class TestLaptop {

	public static void main(String[] args) {
		Laptop l1 = new Laptop("Ryzen 5", 6.4, 8, 128);
		Laptop l2 = new Laptop("Ryzen 3", 6.4, 4, 64);
		
		System.out.println(l1.toString());
		System.out.println(l1.isBetter(l2));
	}

}
