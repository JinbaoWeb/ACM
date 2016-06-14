#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	t=rand()%100;
	cout<<t<<endl;
	while (t--){
		n=rand()%1000;
		cout<<n<<endl;
		int x;
		for (int i=0;i<n;i++){
			x=rand()%1000;
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}