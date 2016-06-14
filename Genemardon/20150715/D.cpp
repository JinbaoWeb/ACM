#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
struct node
{
	int x,y;
};
node p[200];
int MAP[110][110];
int cnt1[110][110][110],cnt2[110][110][110];
std::map<int, int> M1,M2;
int n,c1,c2;
int cmp1(node x,node y)
{
	return x.x<y.x;
}
int cmp2(node x,node y)
{
	return (x.y<y.y);
}
int main(int argc, char const *argv[])
{
	int t=0;
	while (scanf("%d",&n) && n)
	{
		memset(MAP,0,sizeof(MAP));
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		t++;
		M1.clear();c1=1;M2.clear();c2=1;
		int MM=0;
		for (int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
		sort(p,p+n,cmp1);
		M1[p[0].x]=1;
		for (int i=1;i<n;i++) if (p[i].x!=p[i-1].x)
		{
			c1++;M1[p[i].x]=c1;
		}
		//for (int i=0;i<n;i++) printf("%d %d ||",p[i].x,M1[p[i].x] );printf("\n");
		sort(p,p+n,cmp2);
		M2[p[0].y]=1;
		for (int i=1;i<n;i++) if (p[i].y!=p[i-1].y)
		{
			c2++;M2[p[i].y]=c2;
		}
		for (int i=0;i<n;i++) MAP[M1[p[i].x]][M2[p[i].y]]=1;
		for (int i=0;i<n;i++)
		{
			for (int j=1;j<=M2[p[i].y];j++)
				for (int k=M2[p[i].y];k<=c2;k++) cnt1[M1[p[i].x]][j][k]++;
		}
		for (int i=0;i<n;i++)
		{
			for (int j=1;j<=M1[p[i].x];j++)
				for (int k=M1[p[i].x];k<=c1;k++) cnt2[M2[p[i].y]][j][k]++;
		}
		for (int i=1;i<c1;i++)
			for (int j=i+1;j<=c1;j++)
				for (int k=1;k<c2;k++)
					for (int p=k+1;p<=c2;p++)
					{
						int ans=cnt1[i][k][p]+cnt1[j][k][p]+cnt2[k][i][j]+cnt2[p][i][j];
						ans=ans-MAP[i][k]-MAP[i][p]-MAP[j][k]-MAP[j][p];
						if (ans>MM) MM=ans;
					}
		for (int i=1;i<=c1;i++) MM=max(MM,cnt1[i][1][c2]);
		for (int i=1;i<=c2;i++) MM=max(MM,cnt2[i][1][c1]);
		printf("Case %d: %d\n",t,MM );
	}
	return 0;
}