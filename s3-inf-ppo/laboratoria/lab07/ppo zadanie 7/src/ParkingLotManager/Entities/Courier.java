package ParkingLotManager.Entities;

public class Courier extends Car {

	private String plate;
	
    public Courier(String plate) {
    	super(plate);
        this.plate = plate;
    }
	
	public boolean canEnter()
	{
		return true;
	}
	
	public String identify()
	{
		return "Courier with plate number " + this.plate;
	}
	
	public boolean canIgnoreCapacity()
	{
		return true;
	}
	
	public boolean haveToPay()
    {
    	return false;
    }
    
    public double pay()
    {
    	return 0.0;
    }
	
}
