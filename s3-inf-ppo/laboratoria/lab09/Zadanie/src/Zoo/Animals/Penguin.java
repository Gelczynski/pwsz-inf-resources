package Zoo.Animals;

import Zoo.Food.Food;

public class Penguin extends Carnivorous {
	
	public Penguin(String name, Food food) {
        super(name, food);
    }
	
	public int[] StartingSleep()
	{
		hour = 17;
		minute = 30;
		time[0] = hour;
		time[1] = minute;
		return time;
	}
	
	public int[] EndingSleep()
	{
		hour = 5;
		minute = 30;
		time[0] = hour;
		time[1] = minute;
		return time;
	}

}
