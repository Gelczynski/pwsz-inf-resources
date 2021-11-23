package ParkingLotManager.Entities;

public class TeacherCar extends Car {

	private String plate;
	
    public TeacherCar(String plate) {
        super(plate);
        this.plate = plate;
    }
    
    public String identify()
	{
		return "Teacher car with plate number " + this.plate;
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