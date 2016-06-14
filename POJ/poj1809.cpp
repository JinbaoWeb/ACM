#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long num[4];
int main(){
	int t,n,x,y;
	scanf("%d",&t);
	for (int c=1;c<=t;c++){
		
		scanf("%d",&n);
		memset(num,0,sizeof(num));
		while (n--){
			scanf("%d%d",&x,&y);
			num[((x & 1) << 1) + (y & 1)]++;
		}
		long long ans=0;
		for (int i=0;i<4;i++){
			for (int j=0;j<4;j++){
				for (int k=0;k<4;k++){
					int x1=(i>>1),y1=(i&1),x2=(j>>1),y2=(j&1),x3=(k>>1),y3=(k&1);
					if (!((x1 * y2 - y1 * x2 + x2 * y3 - x3 *y2 + x3 * y1 - x1 * y3) & 1)){
						if (i==j && j==k)
							ans+=num[i]*(num[i]-1)*(num[i]-2)/6;
						else if (i==j)
							ans+=num[i]*(num[i]-1)*num[k]/2;
						else if (j==k)
							ans+=num[i]*(num[j]-1)*num[j]/2;
						else 
							ans+=num[i]*num[j]*num[k];
					}
					
				}
			}
		}
		printf("Scenario #%d:\n",c);
		printf("%lld\n\n",ans );
	}
	return 0;
}