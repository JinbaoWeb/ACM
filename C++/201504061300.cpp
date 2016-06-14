#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int a[200000+5];
int main(){
	int n;
	while (~scanf("%d",&n)){
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int max=0,flag=0;
		for (int i=n-2;i>=0;i--){
			for (int j=n-1;j>i;j--){
				int k=a[j]%a[i];
				if (k>max)
					max=k;
				if (i>0&&max>=a[i-1]){
					flag=1;
					break;
				}
			}
			if (flag==1)
				break;
		}
		printf("%d\n",max);
	}

	return 0;
}
