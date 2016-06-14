#inlcude <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	int a[1000];
	cin>>n;
	int ans=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]==1)
			ans++;
	}
	for (int i=1;i<n-1;i++){
		if (a[i]==0 && a[i-1]==1 && a[i+1]==1)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}