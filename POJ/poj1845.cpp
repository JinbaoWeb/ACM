#include <iostream>
#include <stdio.h>
#include <string.h>
typedef long long ll;
using namespace std;
#define m 9901
ll mod_pow(ll a,ll b){	//快速幂
	ll ans=1;
	while (b>0){
		if (b&1)
			ans=ans*a%m;
		a=a*a%m;
		b>>=1;
	}
	return ans;
} 
ll sum(ll p,ll n)  //递归二分求 (1 + p + p^2 + p^3 +...+ p^n)%mod  
{                          //奇数二分式 (1 + p + p^2 +...+ p^(n/2)) * (1 + p^(n/2+1))  
    if(n==0)               //偶数二分式 (1 + p + p^2 +...+ p^(n/2-1)) * (1+p^(n/2+1)) + p^(n/2)  
        return 1;  
    if(n%2)  //n为奇数,  
        return (sum(p,n/2)*(1+mod_pow(p,n/2+1)))%m;  
    else     //n为偶数  
        return (sum(p,n/2-1)*(1+mod_pow(p,n/2+1))+mod_pow(p,n/2))%m;  
} 
/* 
ll sum(ll a,ll b){	//求 1+a^1+a^2+...+a^b的值
	ll ans=mod_pow(a,b+1);
	return (ans-1)/(a-1);
}
*/
int main(){
	int a,b;
	int p[10000],n[10000];	
	while (cin>>a>>b){
		int k=0;
		memset(n,0,sizeof(n));
		for (int i=2;i<=a;i++){	//将a转换为(p[0]^n[0])*(p[1]^n[1])*(p[2]^n[2])*...*(p[k]^n[k])
			if (a%i==0){
				p[k]=i;
				while (a%i==0){
					n[k]++;
					a/=i;
				}
				k++;
			}
		}
		ll ans=1;
		for (int i=0;i<k;i++){
			ans=ans*sum(p[i],b*n[i])%m;
		}
		cout<<ans<<endl;
	}
	return 0;
}