package ParkingLotManager.Entities;

public class PrivilegedVehicle extends Car {

	private String plate;
	
    public PrivilegedVehicle(String plate) {
        super(plate);
        this.plate = plate;
    }
	
	public String identify()
	{
		return "Privileged vehicle with plate number " + this.plate;
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