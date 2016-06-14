#include <stdio.h>
#define MAX 100000+1
int MaxSubseqSum(int a[],int n){
	int thissum=0,maxsum=-0xffffff;
	int i,j;
	for (i=0;i<n;i++){
		thissum=0;
		for (j=i;j<n;j++){
			thissum+=a[j];
			if (thissum>maxsum)
				maxsum=thissum;
		}
	}
	return maxsum;
}

int main(){
	int n,a[MAX];
	while (~(scanf("%d",&n))){
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",MaxSubseqSum(a,n));
	}
	return 0;
}