#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100000+5];
int b[100000+5];
int main(){
	int n,m,t;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (int i=0;i<m;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		long long sum=0;
		for (int j=n-1,k=0;j>=0&&k<m;j--,k++){
			if (a[j]<b[k])
				break;
			sum+=a[j]-b[k];
		}
		cout<<sum<<endl;
	}
	return 0;
}