#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n,N,cnt;
int list[400010],fa[200010];;
int query[200010][2];
int bit[2][400010];
int find(int x)
{
	int head=1,tail=cnt,mid;
	while(1)
	{
		mid=(head+tail)/2;
		if (list[mid]==x) return mid;
		if (list[mid]<x) head=mid+1;
		else tail=mid-1;
	}
}
int lowbit(int x)
{
	return x & ( x ^ (x-1));
}
void addup(int group,int d,int x)
{
	while(x<=cnt)
	{
		bit[group][x]+=d;
		x+=lowbit(x);
	}
}
int getsum(int group,int x)
{
	int res=0;
	while (x)
	{
		res=res+bit[group][x];
		x-=lowbit(x);
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int t=0;
	while (scanf("%d",&n) != EOF)
	{
		t++;
		printf("Case #%d:\n",t );
		N=1;
		memset(bit,0,sizeof(bit));
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&query[i][0],&query[i][1]);
			if (query[i][0]==0)
			{
				list[N++]=query[i][1];
				list[N++]=query[i][1]+N/2;
				fa[N/2]=i;
				//printf("%d %d\n",list[N-2],list[N-1] );
			}
		}
		sort(list+1,list+N+1);cnt=1;
		for (int i=2;i<=N;i++) if (list[i]!=list[i-1])
		{
			cnt++;
			list[cnt]=list[i];
		}
		//for (int i=1;i<=cnt;i++) printf("%d ",list[i] ); printf("\n");
		N=0;
		for (int i=1;i<=n;i++)
		{
			if (query[i][0]==0)
			{
				N++;
				int L=find(query[i][1])-1,R=find(query[i][1]+N);
				//printf("%d %d\n",L,R );
				int l=getsum(0,L),r=getsum(1,R);
				printf("%d\n", r-l);
				addup(0,1,L+1);
				addup(1,1,R);
			}
			else
			{
				int pos=fa[query[i][1]];
				addup(0,-1,find(query[pos][1]));
				addup(1,-1,find(query[pos][1]+query[i][1]));
			}
			//for (int i=1;i<=cnt;i++) printf("%d ",bit[0][i] );printf("\n");
			//for (int i=1;i<=cnt;i++) printf("%d ",bit[1][i] );printf("\n");
		}
	}
	return 0;
}