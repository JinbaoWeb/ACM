#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000+10;
char str1[MAXN],str2[MAXN];
int a[MAXN];
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		cin>>str1>>str2;
		for (int i=0;i<=n;i++)
			cin>>a[i];
		int num=0;
		for (int i=0;i<n;i++){
			if (str1[i]==str2[i])
				num++;
		}
		if (num==n){
			cout<<a[n]<<endl;
			continue;
		}
		int ans=0;
		for (int i=0;i<=num;i++){
			if (ans<a[i])
				ans=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}