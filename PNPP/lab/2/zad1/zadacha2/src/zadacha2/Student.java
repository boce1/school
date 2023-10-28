package zadacha2;

public class Student extends Human{
	private String fNum;
	private int PIKgrade;
	private int TEgrade;
	private int PPEgrade;
	
	public Student(String fName, String lName, String bDate, String fnum, int pik, int te, int ppe)
	{
		super(fName, lName, bDate);
		this.fNum = fnum;
		this.PIKgrade = pik;
		this.TEgrade = te;
		this.PPEgrade = ppe;
	}
	
	public String getFNum()
	{
		return this.fNum;
	}
	
	public void setFNum(String num)
	{
		this.fNum = num;
	}
	
	
	public int getPIKgrade()
	{
		return this.PIKgrade;
	}
	
	public void setPIKgrade(int grade)
	{
		this.PIKgrade = grade;
	}
	
	public int getTEgrade()
	{
		return this.TEgrade;
	}
	
	public void setTEgrade(int grade)
	{
		this.TEgrade = grade;
	}
	
	public int getPPEgrade()
	{
		return this.PPEgrade;
	}
	
	public void setPPEgrade(int grade)
	{
		this.PPEgrade = grade;
	}
	
}
