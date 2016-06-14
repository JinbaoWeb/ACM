#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[250000+10];
int main(){
	int n;
	while (~scanf("%d",&n)){
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		if (n%2==0){
			printf("%.1f\n",(1.0*a[n/2]+1.0*a[n/2-1])/2 );
		}
		else
			printf("%.1f\n",1.0*a[n/2] );
	}

	return 0;
}