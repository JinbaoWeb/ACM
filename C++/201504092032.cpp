#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
int fact[10000];
int solve(ll n){
	int k=0;
	for (ll i=2;i*i<=n;i++){
		if (n%i==0){
			fact[k++]=i;
			n/=i;
			while (n%i==0){
				fact[k++]=i;
				n/=i;
			}
				
		}
	}
	if (n>1)
		fact[k++]=n;
	return k;
}
int main(){
	int t;
	ll n;
	scanf("%d",&t);
	//cin>>t;
	while (t--){
		scanf("%d",&n);
		//cin>>n;
		int k=solve(n);
		printf("%d = ",n);
		//cout<<n<<" = ";
		printf("%d",fact[0]);
		//cout<<fact[0];
		for (int i=1;i<k;i++)
			printf(" * %d",fact[i]);
			//cout<<" * "<<fact[i];
		printf("\n");
		//cout<<endl;
			
	}
	return 0;
}
