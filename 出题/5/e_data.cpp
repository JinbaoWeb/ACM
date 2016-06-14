#include <bits/stdc++.h>
using namespace std;
int main(){
	ofstream cout("e.in");
	int x;
	cout<<1<<endl;
	for (int i=0;i<1;i++){
		cout<<10000<<endl;
		for (int j=0;j<10000-1;j++){
			x=rand()%1000;
			cout<<x<<" ";
		}
		x=rand()%1000;
		cout<<x<<endl;
	}
	return 0;
}