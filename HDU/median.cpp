#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
double a[500000+2];
int main(){
	int n;
 	FILE *f;

 	f=fopen("median.in","r");
 	fscanf(f,"%d",&n);
 	fclose(f);

  	f=fopen("aplusb.out","wb");
  	for (int i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	sort(a,a+n);
	fprintf(f,"%0.lf",a[(n-1)/2],"\n");
  	fclose(f);
	return 0;
}