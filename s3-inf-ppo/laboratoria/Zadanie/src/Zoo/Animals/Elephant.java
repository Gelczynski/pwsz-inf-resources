package Zoo.Animals;

import Zoo.Food.Food;

public class Elephant extends Herbivorous {
    
	public Elephant(String name, Food food, Food food2, Food food3) {
        super(name, food, food2, food3);
    }
	
	public int[] StartingSleep()
	{
		hour = 20;
		minute = 30;
		time[0] = hour;
		time[1] = minute;
		return time;
	}
	
	public int[] EndingSleep()
	{
		hour = 7;
		minute = 0;
		time[0] = hour;
		time[1] = minute;
		return time;
	}

}