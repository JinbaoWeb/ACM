#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	ofstream cout("a.in");
	int t,a,b,c;
	t=1000;
	cout<<t<<endl;
	while (t--){
		a=rand()%1000+1;
		b=rand()%1000+1;
		c=rand()%1000+1;
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	
	return 0;
}