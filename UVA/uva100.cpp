#include <stdio.h>
typedef long long ll;
int main(){
	ll i,j;
	while (~scanf("%lld%lld",&i,&j)){
		ll ii=i,jj=j;
		int max=0;
		if (i>j){
			ll temp=j;
			j=i;
			i=temp;
		}
		for (ll y=i;y<=j;y++){
			ll x=y;
			int count=1;
		//	printf("%lld ",x);
			while (x!=1){
				count++;
				if (x%2!=0)
					x=3*x+1;
				else
					x=x/2;
			//	printf("%lld ",x);
			}
		//	printf("\n");
			if (max<count)
				max=count;
		}
		printf("%lld %lld %d\n",ii,jj,max);
	}
	return 0;
}
