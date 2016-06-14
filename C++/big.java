import java.util.Scanner;
import java.math.BigInteger;
import java.util.*;
class big{
	public static void main(String[] args)throws Exception{
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while ((t--)>=0){
			BigInteger a = input.nextBigInteger();
			System.out.println(a.add(BigInteger.valueOf(1)));
		}
	}
}