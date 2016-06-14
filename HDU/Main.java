import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
            public static void main(String args[]) throws Exception
            {
                    Scanner cin=new Scanner(System.in);
                    BigInteger n,m,p,k,three=BigInteger.valueOf(3);
                    while (cin.hasNext()){
                    	n=cin.nextBigInteger();
                    	m=cin.nextBigInteger();
                    	p=cin.nextBigInteger();
                    	k=(n.subtract(m)).abs();
                    	if (n.compareTo(m)<=0){
                    		if (k.compareTo(p)<=0)
                    			System.out.println("YES");
                    		else
                    			System.out.println("NO");
                    	}
                    	else{
                    		if (m.compareTo(three)<0){
                    			System.out.println("NO");
                    		}
                    		else{
                    			System.out.println("YES");
                    		}
                    	}
                    }
            }
}