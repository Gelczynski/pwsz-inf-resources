package ParkingLotManager;

import ParkingLotManager.Entities.Car;
import ParkingLotManager.Entities.Bicycle;
import ParkingLotManager.Interfaces.EntityInterface;
import ParkingLotManager.Clock;
import ParkingLotManager.Entry;
import ParkingLotManager.BlackList;

import java.util.ArrayList;

final public class ParkingLot {

    private final int MAX_CARS = 150;
	private final int MAX_BICYCLES = 30;
	
    private ArrayList<EntityInterface> entitiesOnProperty = new ArrayList<>();
    
    private int carsOnProperty = 0;
    private int bicyclesOnProperty = 0;
    private double cash = 0.0;

    public boolean checkIfCanEnter(EntityInterface entity) {
    	if(carsOnProperty >= MAX_CARS && entity instanceof Car && !entity.canIgnoreCapacity())
    	{
    		Log.info("No free place at parking");
    		Log.info(entity.identify() + " can't let in");
    		return false;
    	}
    	if(entity instanceof Car && BlackList.checkIfIsBlack(entity))
    	{
    		Log.info("This car is on black list");
    		Log.info(entity.identify() + " can't let in");
    		return false;
    	}
    	if(bicyclesOnProperty >= MAX_BICYCLES && entity instanceof Bicycle)
    	{
    		Log.info("No free place at bike rack");
    		Log.info(entity.identify() + " can let in only with fee");
    	}
    	if(!entity.canEnter())
    	{
    		Log.info(entity.identify() + " can't let in");
    	}
        return entity.canEnter();
    }
    
    public double getCash()
    {
    	return this.cash;
    }
    
    public void letIn(EntityInterface entity)
    {
    	entitiesOnProperty.add(entity);

        if(entity instanceof Car && !entity.canIgnoreCapacity())
        {
            carsOnProperty++;
            if(entity.haveToPay())
            {
            	cash += entity.pay();
            	System.out.println("Fee is required! " + entity.identify() + " pays " + entity.pay());
            }
        }
        if(entity instanceof Bicycle)
        {
        	bicyclesOnProperty++;
        	if(bicyclesOnProperty > MAX_BICYCLES)
        	{
        		System.out.println("Capacity of parking is now exceeded! Fee is required!"
        				+ entity.identify() + " pays " + entity.pay());
        		cash += entity.pay();
        	}
        }
        
        Log.info(entity.identify() + " let in.");
    }

    public int countCars() {
        return carsOnProperty;
    }

}
