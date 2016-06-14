#include <iostream>
#include <stdio.h>
using namespace std;
int a[50000+5]
int main(){
	int t,n;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		long long ans=0;
		for (int k=1;k<n-1;k++){
			int counta=0,countb=0;
			for (int i=0;i<k;i++){
				for (int j=i+1;j<k;j++){
					if (a[i]<a[j])
						counta++;
				}
			}
			for (int i=k+1;i<n-1;i++){
				for (int j=i+1;j<n;j++){
					if (a[i]<a[j])
						countb++;
				}
			}
			ans+=counta*countb;
		}
		printf("%lld\n",ans);
	}
	return 0;
}