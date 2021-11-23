package ParkingLotManager.Entities;

import ParkingLotManager.Interfaces.EntityInterface;

public class Bicycle implements EntityInterface {

    public String identify()
    {
        return "Unknown bicycle";
    }

    public boolean canEnter()
    {
        return true;
    }
    
    public boolean haveToPay()
    {
    	return false;
    }
    
    public double pay()
    {
    	return 2.0;
    }
    
    public boolean canIgnoreCapacity()
	{
		return false;
	}

}