import java.util.Scanner;
import java.math.BigInteger;
import java.util.*;
class local172{
	public static void main(String[] args)throws Exception{
		Scanner input = new Scanner(System.in);
		while (input.hasNext()){
			BigInteger a = input.nextBigInteger();
			System.out.println(a.add(BigInteger.valueOf(1)));
		}
	}
}

/*import java.io.*;
import java.util.*;
import java.math.BigInteger;
import java.util.Scanner;
public class Main {
	public static synchronized BigInteger bigNumber(BigInteger num){
		return num.add(BigInteger.valueOf(1));		
	}
	public static void main(String[] args)throws Exception{
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while (t-- >= 0 ){
			BigInteger a = input.nextBigInteger();
			System.out.println(bigNumber(a));
		}
	}
}*/