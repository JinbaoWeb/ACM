#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100000+5;
bool good[MAXN]; //a[i]包含素数的次数小于等于1是否成立
int deg[MAXN];	//a[i]有多少个素数组成
int cnt[MAXN];	//a[i]在a[1-n]中有多少个数与i互质
int a[MAXN];
typedef long long ll;
int t,n;
long long solve() {
	memset (good, 1, sizeof (good);
	memset (deg, 0, sizeof (deg));
	memset (cnt, 0, sizeof (cnt);
	long long ans_bad = 0;
	for (int i=1;i<=n;i++){
		if (good[i]==false) continue;

	}
	for (int i=2; i<=n; ++i) {
		if (!good[i]) continue;
		if (deg[i] == 0) deg[i] = 1;
		for (int j=1; i*j<=n; ++j) {
			if (j > 1 && deg[i] == 1)
				if (j % i == 0)
					good[i*j] = false;
				else
					++deg[i*j];
			cnt[i*j] += (n / i) * (deg[i]%2==1 ? +1 : -1);
		}
		ans_bad += (cnt[i] - 1) * 1ll * (n - cnt[i] - 1);
	}
	return (n-1) * 1ll * (n-2) * (n-3) / 6 - ans_bad / 2;
}
int main(){
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>a[i];

	}
	return 0;
}