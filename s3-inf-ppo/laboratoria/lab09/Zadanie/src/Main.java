import Zoo.Animals.Elephant;
import Zoo.Animals.Lion;
import Zoo.Animals.Tiger;
import Zoo.Animals.Dolphin;
import Zoo.Animals.Penguin;
import Zoo.Animals.Piranha;
import Zoo.Animals.Shark;
import Zoo.Animals.Giraffe;
import Zoo.Animals.Porcupine;
import Zoo.Animals.Chimpanzee;
import Zoo.Animals.Rhesus;
import Zoo.Animals.Gecko;
import Zoo.Animals.Ant_eater;
import Zoo.Animals.Vampire_bat;
import Zoo.Animals.Carnivorous;
import Zoo.Animals.Herbivorous;
import Zoo.Animals.Omnivorous;
import Zoo.Zoo;
import Zoo.Food.Meat;
import Zoo.Food.Water;
import Zoo.Food.Milk;
import Zoo.Food.Fruits;
import Zoo.Food.Vegetables;
import Zoo.Food.Ants;
import Zoo.Food.Blood;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        Zoo zoo = new Zoo("Zoo Legnica");
        
        Meat meat = new Meat();
        Water water = new Water();
        Milk milk = new Milk();
        Vegetables vegetables = new Vegetables();
        Fruits fruits = new Fruits();
        Ants ants = new Ants();
        Blood blood = new Blood();
        int[] time = new int[2];
        
        ArrayList<Carnivorous> carnivorouses = new ArrayList<>();
        ArrayList<Herbivorous> herbivorouses = new ArrayList<>();
        ArrayList<Omnivorous> omnivorouses = new ArrayList<>();
        
        carnivorouses.add(new Lion("Simba", meat, water, milk));
        carnivorouses.add(new Lion("Mufasa", meat, water, milk));
        carnivorouses.add(new Tiger("Diego", meat, water, milk));
        carnivorouses.add(new Tiger("Killer", meat, water, milk));
        carnivorouses.add(new Dolphin("John", meat));
        carnivorouses.add(new Dolphin("Joe", meat));
        carnivorouses.add(new Penguin("Kowalski", meat));
        carnivorouses.add(new Penguin("Skipper", meat));
        carnivorouses.add(new Piranha("Danger", meat));
        carnivorouses.add(new Piranha("Hazard", meat));
        carnivorouses.add(new Shark("Megalodon", meat));
        carnivorouses.add(new Shark("SharkNado", meat));
        herbivorouses.add(new Elephant("Dumbo", fruits, vegetables, water));
        herbivorouses.add(new Elephant("Jumbo", fruits, vegetables, water));
        herbivorouses.add(new Giraffe("BigBen", fruits, vegetables, water));
        herbivorouses.add(new Giraffe("EiffelTower", fruits, vegetables, water));
        herbivorouses.add(new Porcupine("Spiny", fruits, vegetables, water));
        herbivorouses.add(new Porcupine("Sonic", fruits, vegetables, water));
        omnivorouses.add(new Chimpanzee("Cesar", fruits, vegetables, water, meat));
        omnivorouses.add(new Chimpanzee("Koba", fruits, vegetables, water, meat));
        omnivorouses.add(new Rhesus("Herbert", fruits, vegetables, water, meat));
        omnivorouses.add(new Rhesus("Albert", fruits, vegetables, water, meat));
        omnivorouses.add(new Gecko("Leon", fruits, vegetables, water, meat ));
        omnivorouses.add(new Gecko("Camouflage", fruits, vegetables, water, meat));
        omnivorouses.add(new Ant_eater("AntKiller", ants, water));
        omnivorouses.add(new Ant_eater("AntVacuum", ants, water));
        omnivorouses.add(new Vampire_bat("Dracula", blood));
        omnivorouses.add(new Vampire_bat("BloodSucker", blood));
        
        
        zoo.addAnimal(carnivorouses.get(0))
            .addAnimal(carnivorouses.get(1))
            .addAnimal(carnivorouses.get(2))
            .addAnimal(carnivorouses.get(3))
            .addAnimal(carnivorouses.get(4))
            .addAnimal(carnivorouses.get(5))
            .addAnimal(carnivorouses.get(6))
            .addAnimal(carnivorouses.get(7))
            .addAnimal(carnivorouses.get(8))
            .addAnimal(carnivorouses.get(9))
            .addAnimal(carnivorouses.get(10))
            .addAnimal(carnivorouses.get(11))
            .addAnimal(herbivorouses.get(0))
            .addAnimal(herbivorouses.get(1))
            .addAnimal(herbivorouses.get(2))
            .addAnimal(herbivorouses.get(3))
            .addAnimal(herbivorouses.get(4))
            .addAnimal(herbivorouses.get(5))
            .addAnimal(omnivorouses.get(0))
            .addAnimal(omnivorouses.get(1))
        	.addAnimal(omnivorouses.get(2))
        	.addAnimal(omnivorouses.get(3))
        	.addAnimal(omnivorouses.get(4))
        	.addAnimal(omnivorouses.get(5))
        	.addAnimal(omnivorouses.get(6))
        	.addAnimal(omnivorouses.get(7))
        	.addAnimal(omnivorouses.get(8))
        	.addAnimal(omnivorouses.get(9));

        time[0] = 8;
        time[1] = 0;
        
        zoo.feedAnimals(meat, time);
        
        time[0] = 9;
        time[1] = 0;
        
        zoo.feedAnimals(vegetables, time);
        
        time[0] = 9;
        time[1] = 30;
        
        zoo.feedAnimals(ants, time);
        
        time[0] = 19;
        time[1] = 0;
        
        zoo.feedAnimals(fruits, time);
        
        time[0] = 20;
        time[1] = 0;
        
        zoo.feedAnimals(meat, time);
        
        time[0] = 21;
        time[1] = 0;
        
        zoo.feedAnimals(blood, time);
    }
}