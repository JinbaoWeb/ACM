#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 11
int s[1<<MAXN],c[1<<MAXN];
ll dp[MAXN][1<<MAXN][MAXN*MAXN];
int n,k,cnt;
void DFS(int r,int st,int v)
{
	if (r==n)
	{
		s[++cnt]=st;
		c[cnt]=v;
		return;
	}
	DFS(r+1,st<<1,v);
	if (!(st&1))
		DFS(r+1,st<<1|1,v+1);
}
bool check(int s1,int s2)
{
	if ((s1&s2) || (s1&(s2<<1)) || (s1&(s2>>1))) 
		return false;
	return true;
}
int main()
{
	while (~scanf("%d%d",&n,&k))
	{
		memset(dp,0,sizeof(dp));
		cnt=0;
		DFS(0,0,0);
		dp[0][1][0]=1;
		for (int r=1;r<=n;r++)
			for (int i=1;i<=cnt;i++)
				for (int j=1;j<=cnt;j++)
					for (int q=0;q<=k;q++)
						if ((q-c[i]>=0) && check(s[i],s[j]))
							dp[r][i][q]+=dp[r-1][j][q-c[i]];
		ll ans=0;
		for (int i=1;i<=cnt;i++)
			ans+=dp[n][i][k];
		cout<<ans<<endl;
	}
	return 0;
}