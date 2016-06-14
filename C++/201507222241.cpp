#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll f(ll n){
	return n*n;
}
int main(){
	ll s[6];
	for (int i=0;i<6;i++)
		cin>>s[i];
	
	ll a=s[0],b=s[1],c=s[2],d=s[3],x=s[4],y=s[5];
	ll ans=(a+b)*(b+c)*2-b*b-x*x;
	cout<<ans<<endl;

	return 0;
}