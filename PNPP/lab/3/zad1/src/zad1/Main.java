package zad1;

public class Main {

	public static void main(String[] args) {
		Car c1 = new Car(50, "Mercedes", 50.6, 220);
		HoverCraft h1 = new HoverCraft(50, "Mercedes", 50.6, 20);
		Ship s1 = new Ship(50, "Mercedes", 50.6, 1000);
		
		c1.enterLand();
		h1.enterLand();
		h1.enterSea();
		s1.enterSea();
	}

}
