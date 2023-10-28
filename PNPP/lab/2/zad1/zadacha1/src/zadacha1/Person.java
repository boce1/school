package zadacha1;

public class Person {
	private String name;
	private String egn;
	
	public Person(String name, String egn)
	{
		this.name = name;
		this.egn = egn;
	}
	
	public String getName()
	{
		return this.name;
	}
	
	public void setName(String name)
	{
		this.name = name;
	}
	
	public String getEgn()
	{
		return this.egn;
	}
	
	public void setEgn(String egn)
	{
		this.egn = egn;
	}
}
