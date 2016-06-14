#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,a,b,c;
	ofstream cout("a.in");
	cout<<999<<endl;
	for (int i=1;i<1000;i++){
		a=rand()%1000+1;
		b=rand()%1000+1;
		c=rand()%1000+1;
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}