#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int t,w,b;
	cin>>t>>w>>b;
	int ans=min(w-1,b-1);
	ans+=(t/w)/b*(min(w,b));
	int del=(min(w,b)-t%(w*b))-1;
	ans-=del>0?del:0;
	int g=gcd(ans,t);
	cout<<ans/g<<"/"<<t/g<<endl;
	return 0;
}