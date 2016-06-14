#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
	int t,a,b,c,d;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		double ans=sqrt((a-c)*(a-c)+(b-d)*(b-d));
		printf("%.1lf\n", ans);
	}

	return 0;
}