import ParkingLotManager.Interfaces.EntityInterface;
import ParkingLotManager.Log;
import ParkingLotManager.ParkingLot;
import ParkingLotManager.QueueGenerator;
import ParkingLotManager.BlackList;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
    	QueueGenerator.SetParameters();
    	BlackList.SetList();
        ArrayList<EntityInterface> queue = QueueGenerator.generate();
        ParkingLot parking = new ParkingLot();

        Log.info("There's " + parking.countCars() + " cars in the parking lot");
        Log.info();

        for (EntityInterface entity : queue) {
            if(parking.checkIfCanEnter(entity)) {
                parking.letIn(entity);
            }
        }

        Log.info();
        Log.info("There's " + parking.countCars() + " cars in the parking lot");
        Log.info("Cash: " + parking.getCash());
    }
}