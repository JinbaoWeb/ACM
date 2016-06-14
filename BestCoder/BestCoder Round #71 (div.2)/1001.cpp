#include <stdio.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	ll n;
	scanf("%d",&t);
	while (t--){
		scanf("%I64d",&n);
		int ans=0;
		while (n){
			n/=2;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
