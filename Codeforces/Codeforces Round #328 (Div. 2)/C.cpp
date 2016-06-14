import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
            public static void main(String args[]) throws Exception
            {
                    Scanner cin=new Scanner(System.in);
                    BigInteger t,w,b,ans,k,k2;
                    BigInteger one = BigInteger.ONE;
                    t=cin.nextBigInteger();
                    w=cin.nextBigInteger();
                    b=cin.nextBigInteger();
                    k=w.gcd(b);
                    k2=(w.multiply(b)).divide(k);
                    ans=ans.add((t.divide(k2)).multiply(w.min(b)));
                    ans=ans.add(w.min(b).subtract(one));
                    System.out.println(ans);
            }
}