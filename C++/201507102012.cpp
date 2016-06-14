#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	int n;
	while (cin>>n){
		ll x;
		for (int i=0;i<n;i++){
			cin>>x;
			ll y=x;
			while (y%10==0){
				y/=10;
			}
			if (y%10==5)
				cout<<4*x<<endl;
			else
				cout<<x<<endl;
		}
	}
	return 0;
} 