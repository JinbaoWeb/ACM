#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
int a[100000+10];

int main(){
	ll n;
	while (cin>>n){
		for (ll i=0;i<n;i++)
			cin>>a[i];
		int Min=a[1]-a[0];
	    int Max=a[n-1]-a[0];
		cout<<Min<<" "<<Max<<endl;
		for (ll i=1;i<n-1;i++){
			Min=min(a[i]-a[i-1],a[i+1]-a[i]);
			Max=max(a[i]-a[0],a[n-1]-a[i]);
			cout<<Min<<" "<<Max<<endl;
		}
		Min=a[n-1]-a[n-2];
		Max=a[n-1]-a[0];
		cout<<Min<<" "<<Max<<endl;
	}

	return 0;
}