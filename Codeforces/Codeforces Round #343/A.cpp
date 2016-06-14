#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[200][200];

int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		cin>>a[i];
	ll ans=0;
	for (int i=0;i<n;i++){
		int num=0;
		for (int j=0;j<n;j++){
			if (a[i][j]=='C')
				num++;
		}
		ans+=(num*(num-1)/2);
	}
	for (int i=0;i<n;i++){
		int num=0;
		for (int j=0;j<n;j++){
			if (a[j][i]=='C')
				num++;
		}
		ans+=(num*(num-1)/2);
	}
	cout<<ans<<endl;
	return 0;
}