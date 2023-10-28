package zadacha4;

public class Multiprocessor {
	private int proccesorNum;
	private int coreNum;
	private double frequency;
	
	public Multiprocessor(int cpuNum, int coreNum, double frq)
	{
		this.proccesorNum = cpuNum;
		this.coreNum = coreNum;
		this.frequency = frq;
	}
	
	public int getCpuNum()
	{
		return this.proccesorNum;
	}
	
	public void setCpuNum(int c)
	{
		this.proccesorNum = c;
	}
	
	public int getCoreNum()
	{
		return this.coreNum;
	}
	
	public void setCoreNum(int c)
	{
		this.coreNum = c;
	}
	
	public double getFrequency()
	{
		return this.frequency;
	}
	
	public void setFrequency(double f)
	{
		this.frequency = f;
	}
	
	public double frequencyOneProcessor()
	{
		if(this.coreNum > 1 && this.proccesorNum > 1)
		{
			return (0.7*this.coreNum)*(0.8*this.proccesorNum)*this.frequency;
		}
		return 0.7*0.8*this.frequency;
	}
	
	public double time(double t)
	{
		return t * this.frequency / this.coreNum;
	}
	
	public String toString()
	{
		return this.proccesorNum + " " + this.coreNum + " " + this.frequency;
	}
}
