package Zoo.Animals;

import Zoo.Food.Food;

public class Lion extends Carnivorous {
	
	public Lion(String name, Food food, Food food2, Food food3) {
        super(name, food, food2, food3);
    }
	
	public int[] StartingSleep()
	{
		hour = 6;
		minute = 30;
		time[0] = hour;
		time[1] = minute;
		return time;
	}
	
	public int[] EndingSleep()
	{
		hour = 18;
		minute = 30;
		time[0] = hour;
		time[1] = minute;
		return time;
	}

}