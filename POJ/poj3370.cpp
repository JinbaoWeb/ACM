#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 100000+5
int main(){
    int n,m;
    int a[MAX];
    int sum[MAX];
    int index[MAX];
    while (~scanf("%d%d",&n,&m)){
	if (n==0&&m==0)
	    break;
	sum[0]=a[0]=0;
	for (int i=1;i<=m;i++){
	    scanf("%d",&a[i]);
	    sum[i]=(a[i]+sum[i-1])%n;
	}
	memset(index,-1,sizeof(index));
	index[0]=0;
	int flag=0;
	for (int i=1;i<=m;i++){
	    if (index[sum[i]]==-1)
		index[sum[i]]=i;
	    else{
		for (int j=index[sum[i]]+1;j<=i;j++){
		    flag=1;
		    if (index[sum[i]]+1==j)
			printf("%d",j);
		    else
			printf(" %d",j);
		}
		break;
	    }
	}
	if (flag==0)
	    cout<<"no sweets";
	cout<<endl;
    }
    return 0;
}
