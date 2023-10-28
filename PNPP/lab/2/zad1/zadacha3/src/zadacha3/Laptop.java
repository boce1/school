package zadacha3;

public class Laptop extends ElectricalDevice{
	private int ram;
	private int hdd;
	
	public Laptop(String cpu, double volt, int ram, int hdd)
	{
		super(cpu, volt);
		this.ram = ram;
		this.hdd = hdd;
	}
	
	public int getRam()
	{
		return this.ram;
	}
	
	public void setRam(int r)
	{
		this.ram = r;
	}
	
	public int getHdd()
	{
		return this.hdd;
	}
	
	public void setHdd(int h)
	{
		this.hdd = h;
	}
	
	public boolean isBetter(Laptop lt)
	{
		if(this.ram > lt.ram && this.hdd > lt.hdd)
		{
			return true;
		}
		return false;
	}
	
	public String toString()
	{
		return this.getCpu() + " " + this.getVoltage() + " " + this.getRam() + " " + this.getHdd();
	}
}
