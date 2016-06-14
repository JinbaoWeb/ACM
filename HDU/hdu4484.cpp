#include <stdio.h>
int main(){
	int t,k,n;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&k,&n);
		int ans=n;
		while (n!=1){
			if (n%2==0)
				n/=2;
			else
				n=n*3+1;
			if (ans<n)
				ans=n;
		}
		printf("%d %d\n",k,ans);
	}

	return 0;
}