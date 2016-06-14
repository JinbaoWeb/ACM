import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
            public static void main(String args[]) throws Exception
            {
                    Scanner cin=new Scanner(System.in);
                    int t;
                    BigInteger M = new BigInteger("10");
                    BigInteger MOD = new BigInteger("1");
                    for (int i=0;i<100;i++){
                    	MOD=MOD.multiply(M);
                    }
                 
                        BigInteger[] array1 = new BigInteger[10010];
                        BigInteger[] array2 = new BigInteger[10010];
                        array1[0]=BigInteger.ONE;
                        for (int i=1;i<10010;i++){
                        	array1[i]=BigInteger.ZERO;
                        }
                        
                        for (int i=0;i<10000;i++){
                            for (int j=0;j<10010;j++){
                            	if (j==0)
                            		array2[j]=array1[j].add(array1[j+1]);
                            	else if (j==10009)
                            		array2[j]=array1[j].add(array1[j-1]);
                            	else
                            		array2[j]=array1[j-1].add(array1[j].add(array1[j+1]));
                            }
                            for (int j=0;j<10010;j++){
                            	array1[j]=array2[j];
                            }
                            BigInteger ans=array1[0].mod(MOD);
                        	System.out.println(ans);
                        }
            


            }
}