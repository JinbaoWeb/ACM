#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int a[MAXN],ans[MAXN];
bool used[MAXN];
int main(){
	int n,m;
	memset(used,false,sizeof(used));
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	ans[n]=0;
	for (int i=n-1;i>=0;i--){
		if (used[a[i]]==false){
			used[a[i]]=true;
			ans[i]=ans[i+1]+1;
		}
		else{
			ans[i]=ans[i+1];
		}
	}
	for (int i=0;i<m;i++){
		int x;
		cin>>x;
		cout<<ans[x-1]<<endl;
	}
	return 0;
}