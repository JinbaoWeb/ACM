#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
ll mp[500][500];
ll mp2[500][500];
int main(){
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			mp[i][j]=INF;
			mp2[i][j]=1;
		}
	int x,y;
	for (int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		mp[x][y]=mp[y][x]=1;
		mp2[x][y]=mp2[y][x]=INF;
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (mp[i][j]>mp[i][k]+mp[k][j])
					mp[i][j]=mp[i][k]+mp[k][j]; 
			}
		}
	}
	ll k1=mp[1][n];
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (mp2[i][j]>mp2[i][k]+mp2[k][j])
					mp2[i][j]=mp2[i][k]+mp2[k][j]; 
			}
		}
	}
	ll k2=mp2[1][n];
	cout<<INF<<endl;
	cout<<k1<<" "<<k2<<endl;
	if (k1==INF || k2==INF)
		cout<<-1<<endl;
	else
		cout<<max(k1,k2)<<endl;
	return 0;
}