package Zoo.Animals;

import Zoo.Food.Food;

public abstract class Carnivorous extends Animal {
	
	Carnivorous(String name, Food food) {
        super(name, food);
    }
	
	Carnivorous(String name, Food food, Food food2) {
        super(name, food, food2);
    }
    
    Carnivorous(String name, Food food, Food food2, Food food3) {
        super(name, food, food2, food3);
    }
    
    Carnivorous(String name, Food food, Food food2, Food food3, Food food4) {
    	super(name, food, food2, food3, food4);
    }
	
}
