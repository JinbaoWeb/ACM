#include <bits/stdc++.h>
using namespace std;
int f(int x){
	int flag=0;
	if (x<0){
		x=-x;
		flag=1;
	}
	int ans=0;
	while (x){
		ans=ans*10+x%10;
		x/=10;
	}
	if (flag)
		ans=-ans;
	return ans;
}
int main(){
	int t,a,b,x,y;
	cin>>t;
	while (t--){
		cin>>x>>y;
		a=(x+y)/2;
		b=x-a;
		a=f(a),b=f(b);
		cout<<a+b<<" "<<a-b<<endl;
	}
	return 0;
}