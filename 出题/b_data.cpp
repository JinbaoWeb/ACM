#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	ofstream cout("b.in");
	cout<<1000<<endl;
	int cnt=0;
		for (int a=0;a<10;a++){
			for (int b=a+1;b<=a+100;b++){
				cnt++;
				cout<<a+100<<" "<<b+100<<endl;
			}
		}
	//cout<<cnt<<endl;
	return 0;
}