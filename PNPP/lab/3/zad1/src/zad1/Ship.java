package zad1;

public class Ship extends Vehicle implements isSeaVessel{
	public int deadweight;
	public Ship(int maxSpeed, String model, double price, int deadweight)
	{
		super(maxSpeed, model, price);
		this.deadweight = deadweight;
	}
	
	public double checkPromo()
	{
		return (0.3 / 100) * this.getPrice();
	}
	
	public void enterSea()
	{
		System.out.println("Ship goiing on the sea");
	}
	
}
