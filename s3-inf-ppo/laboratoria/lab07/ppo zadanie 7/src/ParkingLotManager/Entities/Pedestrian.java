package ParkingLotManager.Entities;

import ParkingLotManager.Interfaces.EntityInterface;

public class Pedestrian implements EntityInterface {

    private String name = "";

    public Pedestrian() {}

    public Pedestrian(String name) {
        this.name = name;
    }

    public String identify() {
        return !name.isEmpty() ? name : "Unknown pedestrian";
    }

    public boolean canEnter() {
        return true;
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