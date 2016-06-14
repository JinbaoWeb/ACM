import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static BigInteger p = new BigInteger("33232930569601");
    public static BigInteger one = new BigInteger("1");
    public static BigInteger zero = new BigInteger("0");
    public static BigInteger M = new BigInteger("258280327");

    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));   
        BigInteger fi[] = new BigInteger[1001];
        fi[0] = zero; fi[1]=one;
        for(int i = 2;i < 1001;i++)
            fi[i] = fi[i-1].add(fi[i-2]);
        int T = cin.nextInt();
        while(T-- != 0)
        {
            int n = cin.nextInt();
            BigInteger m = cin.nextBigInteger();
            int k;
            for(k = 0;k < 1001;k++)
                if(m.compareTo(fi[k]) <= 0)
                    break;
            System.out.println(m.subtract(fi[k-2]).mod(M));
        }
    }
}