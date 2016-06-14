#include <iostream>
using namespace std;
typedef long long ll;
ll mod(ll a,ll k,ll b){	//a^k%b
	ll temp=a,ans=1;
	while (k!=0){
		if (k%2==1)
			ans=ans*temp%b;
		temp=temp*temp%b;
		k/=2;
	}
	return ans;
}
int main(){
	long long a,n,ans,b=1000000007;
	while (cin>>a>>n){
		ans=mod(10,n+1,b);
		ans=ans-(9*n+10)%b;
		cout<<(a*(ans+b)/81)%b<<endl;
	}
	return 0;
}