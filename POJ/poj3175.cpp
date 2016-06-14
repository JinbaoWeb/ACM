#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
#define MAX 100000000
int main(){
	int n;
	ll x;
	while (cin>>n>>x){
		for (double i=1;i<MAX;i++){
			double ans=sqrt(i);
			ans-=(int)ans;
			for (int k=0;k<n;k++)
				ans*=10;
			ll a=ans;
			if (a==x){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}