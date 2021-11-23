package ParkingLotManager.Entities;

import ParkingLotManager.Interfaces.EntityInterface;

public class Tank implements EntityInterface {
	
	public boolean canEnter()
	{
		return false;
	}
	
	public String identify()
	{
		return "Unknown tank";
	}
	
	public boolean canIgnoreCapacity()
	{
		return false;
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