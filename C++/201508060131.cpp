#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
map<ll,ll> d[4];
map<ll,ll>::iterator it;
int main() {
	ll n,k,x;
	ll ans = 0;
	cin>>n>>k;
	while(n--) {
		cin>>x;
		if(k == 1) {
			if(x % k == 0) {
				d[3][x] += d[2][x];
				d[2][x] += d[1][x];
				d[1][x]++;
			}
		}
		else {
			d[1][x]++;
			if(x % k == 0) {
				d[2][x] += d[1][x / k];
				d[3][x] += d[2][x / k];
			}
		}
	}
	for(it = d[3].begin(); it != d[3].end(); it++){
		ans += it->second;
	}
	cout<<ans<<endl;
	return 0;
}