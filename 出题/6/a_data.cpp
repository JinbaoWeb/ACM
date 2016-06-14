#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	ofstream cout("a.in");
	int a,b,c,d,e,t;
	t=rand()%1000+1;
	cout<<t<<endl;
	for (int i=0;i<t;i++){
		a=rand()%5+1;
		b=rand()%5+1;
		c=rand()%5+1;
		d=rand()%5+1;
		e=rand()%5+1;
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
	}
	return 0;
}