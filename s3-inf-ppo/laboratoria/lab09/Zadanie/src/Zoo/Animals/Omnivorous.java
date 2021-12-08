package Zoo.Animals;

import Zoo.Food.Food;

public abstract class Omnivorous extends Animal {
	
	Omnivorous(String name, Food food)
	{
		super(name, food);
	}

	Omnivorous(String name, Food food, Food food2) {
        super(name, food, food2);
    }
    
	Omnivorous(String name, Food food, Food food2, Food food3) {
        super(name, food, food2, food3);
    }
    
	Omnivorous(String name, Food food, Food food2, Food food3, Food food4) {
    	super(name, food, food2, food3, food4);
    }
	
}
