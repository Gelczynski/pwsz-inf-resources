package Zoo.Animals;

import Zoo.Food.Food;

public abstract class Herbivorous extends Animal {

	Herbivorous(String name, Food food, Food food2) {
        super(name, food, food2);
    }
    
	Herbivorous(String name, Food food, Food food2, Food food3) {
        super(name, food, food2, food3);
    }
    
	Herbivorous(String name, Food food, Food food2, Food food3, Food food4) {
    	super(name, food, food2, food3, food4);
    }
	
}
