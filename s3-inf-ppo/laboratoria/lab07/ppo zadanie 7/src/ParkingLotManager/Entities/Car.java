package ParkingLotManager.Entities;

import ParkingLotManager.Interfaces.EntityInterface;

public class Car implements EntityInterface {

    private String plate;

    public Car(String plate) {
        this.plate = plate;
    }

    public String identify() {
        return "Car with plate number " + plate;
    }

    public boolean canEnter() {
        return true;
    }
    
    public boolean haveToPay()
    {
    	return true;
    }
    
    public double pay()
    {
    	return 3.5;
    }
    
    public boolean canIgnoreCapacity()
	{
		return false;
	}

}
