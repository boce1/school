package zadacha3;

public class ElectricalDevice {
	private double voltage;
	private String cpu;
	
	public ElectricalDevice(String cpu, double volt)
	{
		this.voltage = volt;
		this.cpu = cpu;
	}
	
	public void turnOn()
	{
		System.out.println("Device is turned ON");
	}
	
	public void turnOff()
	{
		System.out.println("Device is turned OFF");
	}
	
	public String getCpu()
	{
		return this.cpu;
	}
	
	public void setCpu(String cpu)
	{
		this.cpu = cpu;
	}
	
	public double getVoltage()
	{
		return this.voltage;
	}
	
	public void setCpu(double v)
	{
		this.voltage = v;
	}
}
