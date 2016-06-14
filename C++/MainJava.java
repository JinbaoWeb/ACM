import java.util.*;
import java.util.Scanner;
class MainJava{
	public static void main(String []args){
		Scanner input = new Scanner(System.in);
		int n,first,second,third,count;
		while (input.hasNext()){
			n = input.nextInt();
			count = 0;
			if (n==1){
				first = input.nextInt();
				System.out.println(0);
			}
			else if (n==2){
				first = input.nextInt();
				second = input.nextInt();
				if (first>second)
					System.out.println(1);
				else
					System.out.println(0);
			}
			else{
				first = input.nextInt();
				second = input.nextInt();
				for (int i=2;i<n;i++){
					third = input.nextInt();
					if (~(first<=second&&second<=third)){
						count++;
						
					}
				}
			}
			
		}

	}
}