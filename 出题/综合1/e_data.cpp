#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,m;
	t=rand()%100;
	cout<<t<<endl;
	while (t--){
		n=rand()%48+2,m=rand()%49+2;
		cout<<n<<" "<<m<<endl;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				int x=rand()%1000;
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}