#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
long long euler(long long x){
    long long i, res = x;
    for(i=2;i<(long long)sqrt(x*10)+1;i++){//
        if(x%i==0){
            res = res /i *(i-1);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) res = res/x*(x-1);
    return res;
}
long long quickpow(long long m,long long n,long long k){
    long long b = 1;
    while(n>0){
        if(n&1){
            b = ((b%k)*(m%k))%k;
        }
        n = (n>>1);
        m = ((m%k)*(m%k))%k;
    }
    return b;
}
int main()
{
	unsigned long long n,m;
	while (cin>>n>>m)
	{
		long long k=n/2+n%2;
		long long b=1,a=4;
		 while(k>=1)
		 {
       		 if(k%2==1)
			 {
           	 	b=a*b%m;  //此处未能明白
       		 }
        	a=(a%m)*(a%m)%m;  //反复平方法，因为a*b % n= ( (a%n)*(b%n) )%n;
        	k/=2;
    	}
    	long long answer=b;
		
		if (n%2==0)
			cout<<2*(answer-1)/3<<endl;
		else
			cout<<(answer-1)/3<<endl; 
	}
	return 0;
} 
