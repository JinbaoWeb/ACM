#include <bits/stdc++.h>
using namespace std;
char s[105][30];
char str[105][30];
int main(){
	int n,k,x;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>s[i];
	cin>>k;
	while (k--){
		cin>>x;
		for (int i=0;i<x;i++)
			cin>>str[i];
		int ans=0;
		for (int i=0;i<x;i++){
			for (int j=0;j<n;j++){
				if (strcmp(str[i],s[j])==0)
					ans++;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}