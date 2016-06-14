#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
	int x,y,sum1,sum2,val;
	node() {}
	node (int x,int y,int sum1,int sum2) : x(x),y(y),sum1(sum1),sum2(sum2),val((x+y+1)*sum2-sum1*sum1) {}
	bool operator<(const node &a)const{
		return val>a.val;
	}
};
int tab[50][50];
int best1[50][50],best2[50][50];
int n,m,cnt;
int bfs()
{
	priority_queue<node>q;
	q.push(node(0,0,tab[0][0],tab[0][0]*tab[0][0]));
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
		if (tmp.x==n-1 && tmp.y==m-1)
			return tmp.val;
		if (tmp.x<n-1)
		{
			int x=tmp.x+1,y=tmp.y,s1=tmp.sum1+tab[tmp.x+1][tmp.y],s2=tmp.sum2+tab[tmp.x+1][tmp.y]*tab[tmp.x+1][tmp.y];
			if (s1<best1[x][y] || s2>best2[x][y])
			{
				cnt++;
				q.push(node(x,y,s1,s2));
				if (s1<best1[x][y] && s2>best2[x][y])
				{
					s1=best1[x][y];
					s2=best2[x][y];
				}
			}
		}
		if (tmp.y<m-1)
		{
			int x=tmp.x,y=tmp.y+1,s1=tmp.sum1+tab[tmp.x][tmp.y+1],s2=tmp.sum2+tab[tmp.x][tmp.y+1]*tab[tmp.x][tmp.y+1];
			if (s1<=best1[x][y] || s2>=best2[x][y])
			{
				q.push(node(x,y,s1,s2));
				cnt++;
				if (s1<best1[x][y] && s2>best2[x][y])
				{
					s1=best1[x][y];
					s2=best2[x][y];
				}
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++)
	{
		cnt=0;
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
			{
				scanf("%d",&tab[i][j]);
				best1[i][j]=100000009;
				best2[i][j]=0;
			}
		printf("Case #%d: %d\n",TT,bfs());
		printf("%d\n",cnt );
	}
	return 0;
}