#include <bits/stdc++.h>
using namespace std;
int a[100100];
int b[100100];
int main(){
	int n,k;
	cin>>n>>k;
	int x=2*n-2*k;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	if (n<k){
		int ans=0;
		for (int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	int cnt =0;
	for (int i=0;i<x;i+=2){
		b[cnt++]=a[i]+a[i+1];
	}
	int ans=0;
	for (int i=x;i<n;i++)
		b[cnt++]=a[i];
	for (int i=0;i<cnt;i++)
		ans=max(ans,b[i]);
	cout<<ans<<endl;
	return 0;
}