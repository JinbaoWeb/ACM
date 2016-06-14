#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 100005
int main(){
	int a[MAX],n,b[MAX];
	while(scanf("%d",&n)!=EOF){
		if (n==0)
			break;
		int k=1,index;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			b[a[i]]=k++;
		}
		int flag=0;
		for (int i=1;i<=n;i++){
			if (a[i]!=b[i]){
				flag=1;
				break;
			}
		}
		if (flag==0)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
	}
	return 0;
}