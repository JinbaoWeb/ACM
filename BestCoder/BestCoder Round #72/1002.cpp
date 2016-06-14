#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
int n;
long long seed,x,y;
inline long long rand(long long l, long long r) {
	static long long mo=1e9+7, g=78125;
	return l+((seed*=g)%=mo)%(r-l+1);
}
void solve(){
	cin >> n >> seed;
	long long max_X = -1e17, max_Y = -1e17;
    long long min_X = 1e17,min_Y = 1e17;
	for (int i = 0; i < n; i++){
		x = rand(-1000000000, 1000000000);
		y = rand(-1000000000, 1000000000);
		max_X = max(max_X , x + y);
        max_Y = max(max_Y , x - y);
        min_X = min(min_X , x + y);
        min_Y = min(min_Y , x - y);
	}
	cout<<max(max_X - min_X, max_Y - min_Y)<<endl;
}
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		solve();
	}
	return 0;
}