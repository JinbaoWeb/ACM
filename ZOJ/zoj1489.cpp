#include <stdio.h>
int main(){
	int n;
	while (~scanf("%d",&n)){
		if (n&1==0 || n<3)
			printf("2^? mod %d = 1\n",n);
		else{
			int ans=1;
			for (int i=1;;i++){
				ans<<=1;
				//printf("%d\n",ans);
				if (ans%n==1){
					printf("2^%d mod %d = 1\n",i,n);
					break;
				}
				ans%=n;	
			}
		}
	}
	return 0;
}
