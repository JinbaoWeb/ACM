#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int a[50];
int main(){
	int t,n,m;
	scanf("%d",&t);
	for (int cas=1;cas<=t;cas++){
		scanf("%d%d",&n,&m);
		int ans=0;
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (int msk=1; msk<(1<<n); ++msk) {
			int mult = 0;
			for (int i=0; i<n; ++i)
				if (msk & (1<<i)) {
					mult ^= a[i];
				}
			//cout<<mult<<endl;
			if (mult>=m)
				ans++;
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}

	return 0;
}