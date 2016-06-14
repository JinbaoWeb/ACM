#include <iostream>
using namespace std;
typedef long long ll;
int f(ll k){
	while (k%10==0)
		k/=10;
	return k%10;
}
int main(){
	int n;
	while (cin>>n){
		ll x;
		for (int i=0;i<n;i++){
			cin>>x;
			ll y=x;

			while (f(y)==5){
				y*=4;
			}
			cout<<y<<endl;
		}
	}
	return 0;
} 