package Zoo.Animals;

import Zoo.Food.Food;

public class Vampire_bat extends Omnivorous {
	
	public Vampire_bat(String name, Food food)
	{
        super(name, food);
	}
	
	public int[] StartingSleep()
	{
		hour = 8;
		minute = 0;
		time[0] = hour;
		time[1] = minute;
		return time;
	}
	
	public int[] EndingSleep()
	{
		hour = 21;
		minute = 0;
		time[0] = hour;
		time[1] = minute;
		return time;
	}
	
}
