#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,x,y,z;
	cin>>a>>b>>c>>x>>y>>z;
	int need=0,left=0;
	if (a>x)
		left+=(a-x)/2;
	else
		need+=x-a;
	if (b>y)
		left+=(b-y)/2;
	else
		need+=y-b;
	if (c>z)
		left+=(c-z)/2;
	else
		need+=z-c;
	if (left>=need)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}