import java.util.Scanner;
class TestInput{
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		while (input.hasNext()){
			int a = input.nextInt();
			double b = input.nextDouble();
			float c = input.nextFloat();
			
			String e = input.next();
			System.out.println("a = " + a);
			System.out.println("b = " + b);
			System.out.println("c = " + c);
			
			System.out.println("e = " + e);

		}
	}

}