#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,m,q;
struct note
{
	int u,v,w;
	bool operator<(const note &a)const{
		return w<a.w;
	}
}p[200000];
int qry[10000],save[10000],ans[100010],fa[40000],ra[40000];
int find(int x)
{
	if (fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(ans,0,sizeof(ans));
		scanf("%d%d%d",&n,&m,&q);
		for (int i=0;i<=n;i++)
		{
			fa[i]=i;
			ra[i]=1;
		}
		for (int i=0;i<m;i++)
			scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w);
		sort(p,p+m);
		for (int i=0;i<q;i++)
		{
			scanf("%d",&qry[i]);
			save[i]=qry[i];
		}
		sort(qry,qry+q);
		int cur=0,cnt=0;
		for (int i=0;i<q;i++)
		{
			while(cur<m && p[cur].w<=qry[i])
			{
				int A=find(p[cur].u),B=find(p[cur].v);
				if (A==B) 
				{
					cur++;
					continue;
				}
				cnt=cnt-ra[A]*(ra[A]-1)-ra[B]*(ra[B]-1)+(ra[A]+ra[B])*(ra[A]+ra[B]-1);
				fa[A]=B;
				ra[B]=ra[B]+ra[A];
				cur++;
			}
			ans[qry[i]]=cnt;
		}
		for (int i=0;i<q;i++)
			printf("%d\n",ans[save[i]] );
	}
	return 0;
}