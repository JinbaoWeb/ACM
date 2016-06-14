#include <iostream>
using namespace std;
typedef long long ll;
ll C(int n,int m){
	ll ans=1;
	for (int i=0;i<m;i++){
		ans=ans*(n-i)/(i+1);
	}
	return ans;
}
int main(){
	int t,n,m;
	cin>>t;
	while (t--){
		cin>>n>>m;
		if (m==0)
			cout<<1<<endl;
		else if (m>n)
			cout<<0<<endl;
		else
			cout<<C(n,m)<<endl;
	}


	return 0;
}