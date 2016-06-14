#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>
#define inf 101
using namespace std;
struct node
{
	int state;
	vector<int>online;
	priority_queue<int,vector<int>,greater<int> >pre,post;
};
struct train
{
	int o,t,l,e,now,dir,arr,in;
};
int n,m,s,cnt;
node sec[20];
train tr[20];
void init()
{
	cnt=0;
	for (int i=0;i<n;i++)
	{
		sec[i].state=0;
		sec[i].online.clear();
		while (!sec[i].pre.empty()) sec[i].pre.pop();
		while (!sec[i].post.empty()) sec[i].post.pop();
	}
	return;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&m,&s);
		init();
		for (int i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&tr[i].o,&tr[i].t,&tr[i].e,&tr[i].l);
			if (tr[i].o>tr[i].t) tr[i].dir=-1;else tr[i].dir=1;
			tr[i].now=0;
			tr[i].arr=0;
		}
		for (int i=0;cnt<m;i++)
		{
			//for (int j=0;j<m;j++) printf("%d  ",tr[j].now );printf("\n");
			for (int j=0;j<m;j++) if (tr[j].e==i)
				if (tr[j].dir==1)
					sec[tr[j].o].pre.push(j);
				else
					sec[tr[j].o-1].post.push(j);
			for (int j=0;j<n;j++)
			{
				int l=inf,r=inf;
				if (!sec[j].pre.empty()) l=sec[j].pre.top();
				if (!sec[j].post.empty()) r=sec[j].post.top();
				if (l==j && l==inf) continue;
				else if (l<r && sec[j].state!=-1)
				{
					sec[j].state=1;
					while (!sec[j].pre.empty() && sec[j].pre.top()<r)
					{
						int tmp=sec[j].pre.top();
						sec[j].pre.pop();
						sec[j].online.push_back(tmp);
						tr[tmp].in=i;
					}
				}
				else if ((l>r) && sec[j].state!=1)
				{
					sec[j].state=-1;
					while (!sec[j].post.empty() && sec[j].post.top()<l)
					{
						int tmp=sec[j].post.top();
						sec[j].post.pop();
						sec[j].online.push_back(tmp);
						tr[tmp].in=i;
					}
				}
			}
			for (int j=0;j<n;j++) if (sec[j].online.size())
			{
				 
			}
		}
		for (int i=0;i<m;i++) printf("%d\n",tr[i].arr );
	}
	return 0;
}