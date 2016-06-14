#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct note
{
	int l,r,id;
	note () {}
	note (int l,int r,int id) : l(l),r(r),id(id) {}
}p[100010];
struct node
{
	int l,r,id;
	node () {}
	node (int l,int r,int id) : l(l),r(r),id(id) {}
	bool operator<(const node &a)const
	{
		return r>a.r;
	}
};
int n;
int ans[100010],up[100010],down[100010],flag[100010];
priority_queue<node>q;
int cmp1(note a,note b)
{
	return a.l<b.l;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(flag,0,sizeof(flag));
		while(!q.empty()) q.pop();
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&up[i]);
		for (int i=0;i<n;i++) scanf("%d",&down[i]);
		for (int i=0;i<n;i++)
		{
			p[i]=note(up[i],down[i],i+1);
		}
		sort(p,p+n,cmp1);
		//for (int i=0;i<n;i++) printf("%d %d\n",p[i].l,p[i].r );
		int cnt=0,cur=0;
		for (int i=0;i<n;i++)
		{
			while (cur<n && p[cur].l==i)
			{
				q.push(node(p[cur].l,p[cur].r,p[cur].id));
				cur++;
			}
			//printf("top:%d %d\n", q.top().l,q.top().r);
			while (!q.empty() && q.top().r<i) q.pop();
			if (q.empty())
			{
				break;
			}
			cnt++;
			flag[q.top().id]=1;
			ans[i]=q.top().id;
			q.pop();
		}
		printf("%d\n",cnt );
		if (cnt>0) printf("%d",ans[0] );
		for (int i=1;i<cnt;i++) printf(" %d", ans[i]);
		for (int i=1;i<=n;i++) if (flag[i]==0)
		{
			if (cnt==0)
			{
				printf("%d",i );
				cnt++;
			}
			else printf(" %d", i);
		}
		printf("\n");
	}
	return 0;
}