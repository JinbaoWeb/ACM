import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class poj2756
{
            public static void main(String args[]) throws Exception
            {
                    Scanner cin=new Scanner(System.in);
					int t = cin.nextInt();
					while (t!=0){
						t--;
						BigInteger a = cin.nextBigInteger(), b = cin.nextBigInteger();
						System.out.println(a.add(b));
					}
            }
}
