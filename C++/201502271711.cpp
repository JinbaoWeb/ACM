#include <iostream>
#include <string.h>
using namespace std;
#define MAX_N 10000+5
#define MAX_FACTOR 16
typedef long long ll;
int n,f[MAX_N],count[MAX_N],factor[MAX_FACTOR],factor_num[MAX_N];
void solve(int a){
	int k=0;
	for (int i=2;i*i<=a;i++){	//质因数分解
		if (a%i==0){
			factor[k++]=i;
			while (a%i==0)
				a/=i;
		}
	}
	if (a>1)
		factor[k++]=a;
	for (int i=1;i<(1<<k);i++){	//2^k算法
		int mul=1,bits=0;
		for (int j=0;j<k;j++){
			if (i&(1<<j)){
				bits++;
				mul*=factor[j];
			}
		}
		count[mul]++;
		factor_num[mul]=bits;
	}
}
ll cal(ll a){
	return a*(a-1)*(a-2)*(a-3)/24;
}
int main(){
	while (cin>>n){
		for (int i=0;i<n;i++)
			cin>>f[i];
		memset(count,0,sizeof(count));
		memset(factor_num,0,sizeof(factor_num));
		for (int i=0;i<n;i++)
			solve(f[i]);
		ll ans=cal(n);
		for (int i=2;i<=10000;i++){
			if (factor_num[i]&1==0){
				ans+=cal(count[i]);
			}
			else{
				ans-=cal(count[i]);
			}
		}
		cout<<ans<<endl;
	}
		
	return 0;
}