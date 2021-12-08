package Zoo.Animals;

import Zoo.Food.Food;

public class Ant_eater extends Omnivorous {
	
	
	
	public Ant_eater(String name, Food food, Food food2) {
        super(name, food, food2);
    }
	
	public int[] StartingSleep()
	{
		hour = 19;
		minute = 30;
		time[0] = hour;
		time[1] = minute;
		return time;
	}
	
	public int[] EndingSleep()
	{
		hour = 7;
		minute = 30;
		time[0] = hour;
		time[1] = minute;
		return time;
	}

}
