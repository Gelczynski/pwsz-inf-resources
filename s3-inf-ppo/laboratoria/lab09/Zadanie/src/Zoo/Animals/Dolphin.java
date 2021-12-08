package Zoo.Animals;

import Zoo.Food.Food;

public class Dolphin extends Carnivorous {
	
	public Dolphin(String name, Food food) {
        super(name, food);
	}
	
	public int[] StartingSleep()
	{
		hour = 18;
		minute = 30;
		time[0] = hour;
		time[1] = minute;
		return time;
	}
	
	public int[] EndingSleep()
	{
		hour = 6;
		minute = 30;
		time[0] = hour;
		time[1] = minute;
		return time;
	}

}
