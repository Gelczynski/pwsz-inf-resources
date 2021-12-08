package Zoo.Animals;

import Zoo.Log;
import Zoo.Food.Food;

import java.util.Arrays;
import java.util.ArrayList;

abstract public class Animal {

    private String name;
    private boolean hungry = true;
    protected int hour, minute;
    protected int[] time = new int[2];

    protected ArrayList<Food> foods = new ArrayList<>();
    
    Animal(String name, Food food) {
        this.name = name;
        this.foods.add(food);
    }
    
    Animal(String name, Food food, Food food2) {
        this.name = name;
        this.foods.add(food);
        this.foods.add(food2);
    }
    
    Animal(String name, Food food, Food food2, Food food3) {
        this.name = name;
        this.foods.add(food);
        this.foods.add(food2);
        this.foods.add(food3);
    }
    
    Animal(String name, Food food, Food food2, Food food3, Food food4) {
        this.name = name;
        this.foods.add(food);
        this.foods.add(food2);
        this.foods.add(food3);
        this.foods.add(food4);
    }
    
    public void feed(Food food, int[] time) throws Exception {
    	
    	if(time[0] >= StartingSleep()[0])
    	{
    		if(time[0] == StartingSleep()[0] && time[1] >= StartingSleep()[1])
    		{
    			throw new Exception(getName() + " is sleeping and he can't eat now.");
    		}
    		if(time[0] <= EndingSleep()[0])
    		{
    			if(time[0] == EndingSleep()[0] && time[1] < EndingSleep()[1])
    			{
    				throw new Exception(getName() + " is sleeping and he can't eat now.");
    			}
    			if(time[0] < EndingSleep()[0])
    			{
    				throw new Exception(getName() + " is sleeping and he can't eat now.");
    			}
    		}
    	}
    	
    	if(hungry == false)
    	{
    		throw new Exception(getName() + " isn't hungry and he can't eat now.");
    	}
    	
    	String[] foods2 = new String[foods.size()];
    	int i = 0;
    	
    	for(Food food2 : foods)
    	{
    		foods2[i] = food2.GetFood();
    		i++;
    	}
    	
    	if(!Arrays.asList(foods2).contains(food.GetFood()))
    	{
            throw new Exception(getName() + " doesn't eat " + food.GetFood() + ".");
        }
        
        hungry = false;
        Log.info(getName() + " fed.");
    }
    
    abstract public int[] StartingSleep();
    
    abstract public int[] EndingSleep();

    public String getName() {
        return getSpecies() + " " + name;
    }

    private String getSpecies() {
        return getClass().getSimpleName();
    }

}
