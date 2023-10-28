package zad2;

public class Main {

	public static void main(String[] args) {
		Patient p1 = new SickPatient("Fyodor", "Sankpeterburg", "123222004", "depression", true, 50);
		
		p1.cure("pain killers", 2.7);
	}

}
