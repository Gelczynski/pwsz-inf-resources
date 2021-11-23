package ParkingLotManager;

import ParkingLotManager.Entities.Bicycle;
import ParkingLotManager.Entities.Car;
import ParkingLotManager.Entities.Pedestrian;
import ParkingLotManager.Entities.TeacherCar;
import ParkingLotManager.Entities.Tank;
import ParkingLotManager.Entities.Courier;
import ParkingLotManager.Entities.PrivilegedVehicle;
import ParkingLotManager.Interfaces.EntityInterface;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;

public class QueueGenerator {
	private static int ANONYMOUS_PEDESTRIANS_COUNT;
	private static int PEDESTRIANS_COUNT;
	private static int CARS_COUNT;
	private static int TEACHER_CARS_COUNT;
	private static int BICYCLES_COUNT;
	private static int TANKS_COUNT;
	private static int couriers_count;
	private static int privilegedVehicles_count;
	private static int hours;
	private static int minutes;
	
	public static void SetParameters() {
		Scanner skan = new Scanner(System.in);
		Log.info("Please type a numbers for parameters:");
		Log.info("Anonymous pedestrians: ");
		ANONYMOUS_PEDESTRIANS_COUNT = skan.nextInt();
		Log.info("pedestrians: ");
		PEDESTRIANS_COUNT = skan.nextInt();
		Log.info("cars: ");
		CARS_COUNT = skan.nextInt();
		Log.info("teacher's cars: ");
		TEACHER_CARS_COUNT = skan.nextInt();
		Log.info("bicycles: ");
		BICYCLES_COUNT = skan.nextInt();
		Log.info("tanks: ");
		TANKS_COUNT = skan.nextInt();
		Log.info("couriers: ");
		couriers_count = skan.nextInt();
		Log.info("privileged vehicles: ");
		privilegedVehicles_count = skan.nextInt();
		skan.close();
	}
	
    public static ArrayList<EntityInterface> generate() {
        ArrayList<EntityInterface> queue = new ArrayList<>();
        for (int i = 0; i < ANONYMOUS_PEDESTRIANS_COUNT; i++) {
            queue.add(new Pedestrian());
        }

        for (int i = 0; i < PEDESTRIANS_COUNT; i++) {
            queue.add(new Pedestrian(getRandomName()));
        }

        for (int i = 0; i < CARS_COUNT; i++) {
            queue.add(new Car(getRandomPlateNumber()));
        }

        for (int i = 0; i < TEACHER_CARS_COUNT; i++) {
            queue.add(new TeacherCar(getRandomPlateNumber()));
        }

        for (int i = 0; i < BICYCLES_COUNT; i++) {
            queue.add(new Bicycle());
        }
        
        for (int i = 0; i < TANKS_COUNT; i++)
        {
        	queue.add(new Tank());
        }
        
        for (int i = 0; i < couriers_count; i++)
        {
        	queue.add(new Courier(getRandomPlateNumber()));
        }
        
        for (int i = 0; i < privilegedVehicles_count; i++)
        {
        	queue.add(new PrivilegedVehicle(getRandomPlateNumber()));
        }

        Collections.shuffle(queue);

        return queue;
    }

    private static String getRandomPlateNumber() {
        Random generator = new Random();
        return "DLX " + (generator.nextInt(89999) + 10000);
    }

    private static String getRandomName() {
        String[] names = {"John", "Jack", "James", "George", "Joe", "Jim", "Michael", "Anna", "Mia", "Megan", "Rebecca"};
        return names[(int) (Math.random() * names.length)];
    }

}