#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000+10;
int a[MAXN];
int main(){
	int t,n;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int flag=0;
		for (int i=0;i<n-1;i++){
			if (a[i+1]==0 && a[i]==0)
				continue;
			if (a[i+1]==0 || a[i+1]<a[i]){
				flag=1;
				break;
			}
			a[i+1]-=a[i];
		}
		if (flag==0 && a[n-1]!=0){
			flag=1;
		}
		if (flag==1){
			printf("I will never go out T_T\n");
		}
		else{
			printf("yeah~ I escaped ^_^\n");
		}
	}

	return 0;
}