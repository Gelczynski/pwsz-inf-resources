package ParkingLotManager.Interfaces;

public interface EntityInterface {

    String identify();
    boolean canEnter();
    boolean canIgnoreCapacity();
    boolean haveToPay();
    double pay();

}