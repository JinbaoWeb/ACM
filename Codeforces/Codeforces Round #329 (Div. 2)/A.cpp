#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[102][1002];
int a[102][30];
bool used[102];
int main(){
	int n;
	cin>>n;
	memset(a,0,sizeof(a));
	for (int i=0;i<n;i++){
		cin>>s[i];
		int len=strlen(s[i]);
		for (int j=0;j<len;j++)
			a[i][s[i][j]-'a']++;
		used[i]=false;
		int flag=0;
		for (int j=0;j<26;j++){
			if (a[i][j]>0)
				flag++;
		}
		if (flag>2)
			used[i]=false;
		else
			used[i]=true;
	}
	int ans=0;
	for (int i=0;i<26;i++){
		for (int j=i+1;j<26;j++){
			int sum=0;
			for (int k=0;k<n;k++){
				if (used[k]==false)
					continue;
				int flag=0;
				for (int m=0;m<26;m++){
					if (m!=i && m!=j && a[k][m]>0){
						flag=1;
						break;
					}
				}
				if (flag)
					continue;
				sum+=strlen(s[k]);
			}
			ans=max(ans,sum);
		}
	}
	cout<<ans<<endl;
	return 0;
}