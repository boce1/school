package zadacha2;

public class Human {
	private String firstName;
	private String lastName;
	private String birthDate;
	
	public Human(String fName, String lName, String bDate)
	{
		this.firstName = fName;
		this.lastName = lName;
		this.birthDate = bDate;
	}
	
	public String getFirstName()
	{
		return this.firstName;
	}
	
	public void setFirstName(String lName)
	{
		this.firstName = lName;
	}
	
	public String getLastName()
	{
		return this.lastName;
	}
	
	public void setLastName(String lName)
	{
		this.lastName = lName;
	}
	
	public String getBirthDate()
	{
		return this.birthDate;
	}
	
	public void setBirthDate(String date)
	{
		this.birthDate = date;
	}
}
