#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int k,m,quest;
int ans[160000];
char name[160000][205];
struct node
{
	int num,val;
	bool operator<(const node &a)const
	{
		if (a.val<val)
			return false;
		else if (a.val>val)
			return true;
		else if (a.num>num)
			return false;
		else 
			return true;
	}
}p[150010];
struct note
{
	int turn,goin;
	bool operator<(const note &a)const{
		return turn<a.turn;
	}
}qry[160000];
void solve()
{
	priority_queue<node>q;
	for (int i=1;i<=k;i++)
		scanf("%s%d",name[i],&p[i].val);
	for (int i=0;i<m;i++)
		scanf("%d%d",&qry[i].turn,&qry[i].goin);
	sort(qry,qry+m);
	int cur=1,cnt=0;
	for (int i=0;i<m;i++)
	{
		while(cur<=k && cur<=qry[i].turn)
		{
			node per;
			per.num=cur;
			per.val=p[cur].val;
			q.push(per);
			cur++;
		}
		for (int j=0;j<qry[i].goin;j++)
		{
			if (q.empty()) break;
			else
			{
				cnt++;
				node tmp=q.top();q.pop();
				//printf("%d : %d\n",cnt,tmp.num );
				ans[cnt]=tmp.num;
			}
		}
	}
	while(cur<=k)
	{
		node per;
			per.num=cur;
			per.val=p[cur].val;
			q.push(per);
			cur++;
	}
	while(!q.empty())
	{
		cnt++;
		node tmp=q.top();q.pop();
		//printf("%d : %d\n",cnt,tmp.num );
		ans[cnt]=tmp.num;
	}
	for (int i=0;i<quest;i++)
	{
		int x;
		if (i!=0) printf(" ");
		scanf("%d",&x);
		printf("%s",name[ans[x]] );
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&k,&m,&quest);
		solve();
	}
	return 0;
}