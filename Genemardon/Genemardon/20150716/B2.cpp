#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
using namespace std;
struct node
{
	char num[62];
	int len;
	void print(int tt){
		printf("Case %d: ",tt);
		if (len==0)
		{
			printf("-1\n");
			return;
		}
		printf("%s\n",num );
	}
};
node dp[111][3110];
int dir[20]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n,m;
node tmp;
void MAX(node &a,node b)
{
	if (a.len>b.len) return;
	else if (a.len<b.len)
	{
		for (int i=0;i<b.len;i++) a.num[i]=b.num[i];
		a.num[b.len]=0;
		a.len=b.len;
	}
	else
	{
		int flag=0;
		for (int i=0;i<b.len;i++) if (a.num[i]==b.num[i]) continue;
			else 
			{
				if (a.num[i]<b.num[i]) flag=2;
				else flag=1;
				break;
			}
		if (flag==1) return;
		else 
		{
			for (int i=0;i<b.len;i++) a.num[i]=b.num[i];
			a.num[b.len]=0;
		}
	}
}
int main(int argc, char const *argv[])
{
	int t=0;
	while (scanf("%d",&n) && n)
	{
		t++;
		scanf("%d",&m);
		for (int i=0;i<=n;i++)
			for (int j=0;j<m;j++) dp[i][j].len=0;
		for (int i=0;i<10;i++)
		{
			tmp.len=1;tmp.num[0]='0'+i;tmp.num[1]=0;
			MAX(dp[dir[i]][i%m],tmp);
		}
		for (int i=0;i<=n;i++)
			for (int j=0;j<m;j++) if (dp[i][j].len>0)
			{
				for (int k=0;k<10;k++) 
				{
					tmp.len=dp[i][j].len+1;tmp.num[tmp.len-1]='0'+k;
					for(int p=0;p<tmp.len-1;p++) tmp.num[p]=dp[i][j].num[p];
					MAX(dp[i+dir[k]][(j*10%m+k)%m],tmp);
				}
			}
		node ans;
		ans.len=0;
		for (int i=1;i<=n;i++) MAX(ans,dp[i][0]);
		ans.print(t);
	}
	return 0;
}