#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main(){
	ofstream cout("e.in");
	cout<<1000<<endl;
	int cnt=0;
	for (int i=1;i<1000;i++){
		for (int j=1;j<1000;j++){
			for (int k=1;k<1000;k++){
				if (i*i+j*j==k*k){
					cout<<i<<" "<<k<<endl;
					cnt++;
				}
			}
		}
	}
	for (int i=cnt;i<1000;i++){
		int a,b;
		a=rand()%1000+1;
		b=rand()%1000+1;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}