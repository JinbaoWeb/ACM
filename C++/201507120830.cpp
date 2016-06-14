#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin>>t;
	int n,m;
	int a[3000];
	for (int i=1;i<=t;i++){
		cin>>n>>m;
		int sum=0;
		for (int j=0;j<m;j++){
			cin>>a[j];
			sum+=a[j];
		}
		printf("Case #%d:\n", i);
		for (int j=0;j<m;j++)
			printf("%.6f\n",a[j]*1.0/sum*n );
	}

	return 0;
}