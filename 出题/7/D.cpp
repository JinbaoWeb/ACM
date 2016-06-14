#include <iostream>
using namespace std;
int Change(int n,int k){
	int a[10];
	int cnt=0;
	while (n){
		a[cnt++]=n%10;
		n/=10;
	}
	int ans=0;
	while (cnt--){
		ans=ans*k+a[cnt];
	}
	return ans;
}
int main(){
	int a,p,b,q,t;
	cin>>t;
	while (t--){
		cin>>a>>p>>b>>q;
		int x=Change(a,p),y=Change(b,q);
		int ans=x+y;
		cout<<ans<<endl;
	}
	return 0;
}