package zad1;

public abstract class Vehicle {
	private int maxSpeed;
	private String model;
	private double price;
	
	Vehicle(int maxSpeed, String model, double price)
	{
		this.maxSpeed = maxSpeed;
		this.model = model;
		this.price = price;
	}
	
	public int getMaxSpeed()
	{
		return this.maxSpeed;
	}
	
	public void setMaxSpeed(int speed)
	{
		this.maxSpeed = speed;
	}
	
	public String getModel()
	{
		return this.model;
	}
	
	public void setModel(String n)
	{
		this.model = n;
	}
	
	public double getPrice()
	{
		return this.price;
	}
	
	public void setPrice(double p)
	{
		this.price = p;
	}

	public abstract double checkPromo();
	
}
