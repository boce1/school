package zad1;

public class HoverCraft extends Vehicle implements isLandVehicle, isSeaVessel{
	public int passengers;
	public HoverCraft(int maxSpeed, String model, double price, int passengers)
	{
		super(maxSpeed, model, price);
		this.passengers = passengers;
	}
	
	public double checkPromo()
	{
		return (3 / 100) * this.getPrice();
	}
	
	public void enterLand()
	{
		System.out.println("Hovercraft going on the land");
	}
	
	public void enterSea()
	{
		System.out.println("Hovercraft going on the sea");
	}
	
}
