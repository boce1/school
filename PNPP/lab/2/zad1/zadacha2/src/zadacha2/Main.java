package zadacha2;

public class Main {

	public static void main(String[] args) {
		Student s1 = new Student("Boyan", "Zarev", "19.01", "123222004", 6,6,6);
		
		System.out.println(s1.getFirstName());
		System.out.println(s1.getLastName());
		System.out.println(s1.getBirthDate());
		System.out.println(s1.getFNum());
		System.out.println(s1.getPIKgrade());
		System.out.println(s1.getTEgrade());
		System.out.println(s1.getPPEgrade());
	}

}
