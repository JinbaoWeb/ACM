import java.util.Scanner;
class Months{	
	public static void IsSeaon_1(int month){

		if (month==12||month== 1||month== 2)
			System.out.println("Winter!");
		if (month== 3||month== 4||month== 5)
			System.out.println("Spring!");
		if (month== 6||month== 7||month== 8)
			System.out.println("Summer!");
		if (month== 9||month==10||month==11)
			System.out.println("Autumn!");

	}
	public static void IsSeaon_2(int month){
		switch(month){
			case 12:
			case  1:
			case  2:
				System.out.println("Winter!");
				break;
			case  3:
			case  4:
			case  5:
				System.out.println("Spring!");
				break;
			case  6:
			case  7:
			case  8:
				System.out.println("Summer!");
				break;
			case  9:
			case 10:
			case 11:
				System.out.println("Autumn!");
				break;
		}
	}
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		while (input.hasNext()){
			int month = input.nextInt();
			if (month > 13 || month < 0){
				System.out.println("Input Error!");
				continue;
			}
			System.out.printf("Using if to judge %d is: ",month);
			IsSeaon_1(month);
			System.out.printf("Using switch to judge %d is: ",month);
			IsSeaon_2(month);
		}
	}
}