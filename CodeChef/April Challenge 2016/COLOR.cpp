#include <bits/stdc++.h>
using namespace std;
char str[100005];
int r,g,b;
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		r=g=b=0;
		cin>>str;
		for (int i=0;i<n;i++){
			if (str[i]=='R') r++;
			if (str[i]=='G') g++;
			if (str[i]=='B') b++;
		}
		int ans=max(r,max(g,b));
		cout<<n-ans<<endl;
	}
	return 0;
}