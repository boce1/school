package zadacha1;

public class Test {

	public static void main(String[] args) {
		Course c = new Course("Math");
		Teacher t1 = new Teacher("Fyodor", "123222004", c);
		
		System.out.println(t1.getName());
		System.out.println(t1.getEgn());
		System.out.println(t1.getCourse().getCourseName());
		
		t1.setName("Fibonacci");
		System.out.println(t1.getName());
		System.out.println(t1.getEgn());
		System.out.println(t1.getCourse().getCourseName());
	}

}
