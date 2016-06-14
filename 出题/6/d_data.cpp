#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,m,x;
	t=rand()%1000;
	cout<<t<<endl;
	while (t--){
		n=rand()%98+1;
		m=rand()%98+1;
		cout<<n<<" "<<m<<endl;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				x=rand()%1000;
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}