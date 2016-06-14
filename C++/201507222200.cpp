#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int x,y;
bool check(int a,int b){
	if ((a<=x&&b<=y)||(a<=y&&b<=x))
		return true;
	return false;
}
int main(){
	int x1,x2,y1,y2;
	cin>>x>>y>>x1>>y1>>x2>>y2;
	int a1=(x1+x2),b1=max(y1,y2);
	int a2=(x1+y2),b2=max(y1,x2);
	int a3=(y1+x2),b3=max(x1,y2);
	int a4=(y1+y2),b4=max(x1,x2);
	if ((check(a1,b1)==true)||(check(a2,b2)==true)||(check(a3,b3)==true)||(check(a4,b4)==true))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}