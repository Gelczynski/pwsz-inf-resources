package Zoo.Animals;

import Zoo.Food.Food;

public class Piranha extends Carnivorous {
	
	public Piranha(String name, Food food) {
        super(name, food);
    }
	
	public int[] StartingSleep()
	{
		hour = 21;
		minute = 0;
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
