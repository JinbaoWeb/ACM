#include <iostream>
#include <stdio.h>
using namespace std;
int a[40000+5];
int sum[40000+5];
int num[80000+5];
int main(){
	int n,m,x;
	while (~scanf("%d%d",&n,&m)){
		int index=-1;
		memset(sum,0,sizeof(sum));
		memset(num,0,sizeof(num));
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			if (x==m)
				index=i;
			if (x>m)
				a[i]=1;
			if (x<m)
				a[i]=-1;
			if (x==m)
				a[i]=0;
		}
		sum[0]=0;
		int ans=0;
		num[0]=1;
		for (int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
			if (i>=index){
				if (sum[i]<0)
					ans+=num[sum[i]+40000];
				else
					ans+=num[sum[i]];
			}
			else{
				if (sum[i]<0)
					num[sum[i]+40000]++;
				else
					num[sum[i]]++;
			}
		}
		/*
		for (int i=0;i<=n;i++)
			cout<<sum[i]<<" ";
		cout<<endl;
		for (int i=0;i<4;i++)
			cout<<num[i]<<" ";
		cout<<endl;
		*/
		/*

		sum[index]=0;
		num[0]=1;
		for (int i=index-1;i>0;i--){
			sum[i]=sum[i+1]+a[i];
			if (sum[i]<0)
				num[sum[i]+40000]++;
			else
				num[sum[i]]++;
		}
		int ans=num[0];
		for (int i=index+1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
			if (sum[i]<=0)
				ans+=num[-sum[i]];
			else
				ans+=num[sum[i]+40000];
		}
		*/
		cout<<ans<<endl;
	}
	return 0;
}