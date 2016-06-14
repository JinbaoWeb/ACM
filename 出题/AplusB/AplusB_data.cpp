#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	ofstream cout("AplusB.in");
	int a,b;
	for (int i=0;i<20;i++){
		a=rand()%100000;
		b=rand()%100000;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}