#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10005],b[10005];
int ans[1005][1005];
int ans2[1005][1005];
int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		ans[i][i]=a[i];
	}
	for (int i=0;i<n;i++){
		cin>>b[i];
		ans2[i][i]=b[i];
	}
	ll Max=-1;
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			ans[i][j]=ans[i][j-1]|a[j];
		}
	}
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			ans2[i][j]=ans2[i][j-1]|b[j];
		}
	}

	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			Max=max(Max,1LL+ans[i][j]+ans2[i][j]);
		}
	}
/*
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			cout<<ans2[i][j]<<" ";
		}
		cout<<endl;
	}

	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			cout<<ans[i][j]+ans2[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	cout<<Max-1<<endl;
	return 0;
}