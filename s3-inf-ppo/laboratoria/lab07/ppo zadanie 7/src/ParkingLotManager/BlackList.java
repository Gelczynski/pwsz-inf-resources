package ParkingLotManager;

import ParkingLotManager.Interfaces.EntityInterface;
import ParkingLotManager.QueueGenerator;

import java.util.ArrayList;

public class BlackList {
	
	private static ArrayList<EntityInterface> entities = new ArrayList<>();
	
	public static void SetList()
	{
		entities = QueueGenerator.generate();
		System.out.println("Black list:");
		
		for(EntityInterface c : entities)
		{
			System.out.println(c.identify());
		}
	}
	
	public static boolean checkIfIsBlack(EntityInterface entity)
	{
		for(EntityInterface IsBlack : entities)
		{
			
			if(IsBlack.identify() == entity.identify())
			{
				return true;
			}
			
		}
			
		return false;
		
	}
}
