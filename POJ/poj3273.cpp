#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[100000+5];
int n,m;
bool check(int k){
	int count=0;
	
	int sum=0;
	for (int i=0;i<n;i++){
		cout<<sum<<" ";
		sum+=a[i];
		if (sum>k){
			sum=0;
			i--;
			count++;
		}
	}
	if (sum>0 && sum<=k)
		count++;
	if (count==m)
		return true;
	return false;
}
int main(){
	while (~scanf("%d%d",&n,&m)){
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int l=1,r=1000000000;
		while (l<r){
			int mid=(l+r)>>1;
			if (check(mid)==true)
				r=mid-1;
			else
				l=mid+1;
		}
		cout<<l<<" "<<r<<endl;
		
		cout<<check(500)<<endl;
	}
	return 0;
}