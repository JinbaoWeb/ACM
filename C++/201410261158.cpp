#include <iostream>
#include <stdio.h>
using namespace std;
long long mod(long long a,long long b){
	long long k=a/b;
	return a-k*b;
}
int main(){
	int t;
	long long m,n;
	//short a[1000000];
	scanf("%lld",&t);
	//cin>>t;
	while (t--){
		scanf("%lld%lld",&n,&m);
		//cin>>n>>m;
		long long sum=0;
		for (int i=1;i<=n;i++){
			
			long long k=mod(i,m);
			
			long long kk=mod(k*k,m);
			
			long long kkk=mod((mod(kk*kk,m)  * (mod(n/i,m))),m);
			
			sum=mod(sum+kkk,m);
			//cout<<sum<<endl;
		}
		printf("%lld\n",sum);
		//cout<<sum<<endl;
	}
	return 0;
} 
//ÅÅÁÐ×éºÏ 
