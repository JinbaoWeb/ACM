#include <bits/stdc++.h>
using namespace std;
int main(){
	ofstream cout("b.in");
	cout<<1000<<endl;
	for (int i=0;i<1000;i++){
		int n,x;
		n=rand()%1000+1;
		cout<<n<<endl;
		for (int j=0;j<n-1;j++){
			x=rand()%1000+1;
			cout<<x<<" ";
		}
		x=rand()%1000+1;
		cout<<x<<endl;
	}
	return 0;
}