package Zoo.Animals;

import Zoo.Food.Food;

public class Tiger extends Carnivorous {
	
	public Tiger(String name, Food food, Food food2, Food food3) {
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
		hour = 20;
		minute = 0;
		time[0] = hour;
		time[1] = minute;
		return time;
	}

}