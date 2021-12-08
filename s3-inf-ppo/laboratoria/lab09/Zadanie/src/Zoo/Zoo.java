package Zoo;

import Zoo.Animals.Animal;
import Zoo.Food.Food;

import java.util.ArrayList;

public final class Zoo {

    private ArrayList<Animal> animals = new ArrayList<>();
    private String name;

    public Zoo(String name) {
        this.name = name;
        Log.info(this.name + " created.");
    }

    public Zoo addAnimal(Animal animal) {
        animals.add(animal);
        Log.info(animal.getName() + " added to zoo.");
        return this;
    }

    public void feedAnimals(Food food, int[] time) {
        Log.info();
        Log.info("Feeding started at " + time[0] + ":" + time[1] + ".");

        for(Animal animal : animals) {
            try {
                animal.feed(food, time);
            } catch (Exception e) {
                Log.warning(e.getMessage());
            }
        }
    }

}