package zadacha1;

public class Teacher extends Person{
	private Course course;
	
	public Teacher(String name, String egn, Course course)
	{
		super(name, egn);
		this.course = course;
	}
	
	public Course getCourse()
	{
		return this.course;
	}
	
	public void setCourse(Course c)
	{
		this.course = c;
	}
}
