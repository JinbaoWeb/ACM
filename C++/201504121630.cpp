#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[10];
int t,n;
bool used[10];
int ans[370000][10];
bool check(int a[]){
	memset(used,false,sizeof(used));
	for (int i=1;i<n;i++){
		if (used[a[i]]==true){
			return false;
		}
		if ((a[i-1]==1 &&a [i]==3)||(a[i-1]==3 &&a[i]==1))
			used[2]=true;
		if ((a[i-1]==1 && a[i]==7)||(a[i-1]==7 &&a[i]==1))
			used[4]=true;
		if ((a[i-1]==1 && a[i]==9)||(a[i-1]==9 &&a[i]==1))
			used[5]=true;
		if ((a[i-1]==2 && a[i]==8)||(a[i-1]==8 &&a[i]==2))
			used[5]=true;
		if ((a[i-1]==3 && a[i]==9)||(a[i-1]==9 &&a[i]==3))
			used[6]=true;
		if ((a[i-1]==3 && a[i]==7)||(a[i-1]==7 &&a[i]==3))
			used[5]=true;
		if ((a[i-1]==4 && a[i]==6)||(a[i-1]==6 &&a[i]==4))
			used[5]=true;
		if ((a[i-1]==7 && a[i]==9)||(a[i-1]==9 &&a[i]==7))
			used[8]=true;
	}
	return true;
}
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int k=0;
		if (check(a)==true){
			for (int i=0;i<n;i++)
				ans[k][i]=a[i];
			k++;
		}
		while (next_permutation(a,a+n)){
			if (check(a)==true){
				for (int i=0;i<n;i++)
					ans[k][i]=a[i];
				k++;
			}
		}
		printf("%d\n",k);
		for (int i=0;i<k;i++){
			for (int j=0;j<n-1;j++)
				printf("%d ",ans[i][j]);
			printf("%d\n",ans[i][n-1]);
		}
	}

	return 0;
}
