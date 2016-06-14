#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	ll n,m;
	cin>>t;
	while (t--){
		cin>>n>>m;
		if (n==1){
			if (m==2)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		else if (m==1){
			if (n==2)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		else if (n%2==0 || m%2==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}