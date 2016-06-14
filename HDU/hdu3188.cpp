#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int t,x,y,z;
	cin>>t;
	while (cin>>x>>y>>z){
		if (x==y || y==z || x==z)
			cout<<"perfect"<<endl;
		else if (x*x+y*y==z*z || x*x+z*z==y*y || y*y+z*z==x*x)
			cout<<"good"<<endl;
		else
			cout<<"just a triangle"<<endl;
	}

	return 0;
}