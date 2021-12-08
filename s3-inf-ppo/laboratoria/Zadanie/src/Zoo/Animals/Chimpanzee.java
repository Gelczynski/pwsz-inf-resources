package Zoo.Animals;

import Zoo.Food.Food;

public class Chimpanzee extends Omnivorous {
	
	public Chimpanzee(String name, Food food, Food food2, Food food3, Food food4) {
        super(name, food, food2, food3, food4);
    }
	
	public int[] StartingSleep()
	{
		hour = 19;
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