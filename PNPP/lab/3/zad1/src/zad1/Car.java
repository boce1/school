package zad1;

public class Car extends Vehicle implements isLandVehicle{
	public float powerEngine;
	public Car(int maxSpeed, String model, double price, float powerEngine)
	{
		super(maxSpeed,model, price);
		this.powerEngine = powerEngine;
	}
	
	public double checkPromo()
	{
		return (20 / 100) * this.getPrice();
	}
	
	public void enterLand()
	{
		System.out.println("Car goes vroom");
	}
}
