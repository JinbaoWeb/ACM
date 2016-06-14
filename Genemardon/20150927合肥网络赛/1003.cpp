#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define MOD 1000000
#define LL int
vector <int>a[1000000], b[1000000];
int hs[MOD],head[MOD],nxt[MOD],id[MOD],top,flag[MOD],stk;
void insert(LL x, int y, int z)
{
    int k = (x%MOD+MOD)%MOD;
    hs[top] = x, id[top] = y, nxt[top] = head[k], head[k] = top++;
    flag[stk++] = z;
}
int find(LL x)
{
    int k = x%MOD;
    for(int i = head[k]; i != -1; i = nxt[i])
        if(hs[i] == x)
            return id[i];
    return -1;
}
void del(int x)
{
	if(flag[x] == -1)
		return;
	flag[x] = -1;
	for(int i = 0;i < a[x].size();i++)
	{
		int v = a[x][i];
		int j = find(v);
		del(j);
	}
}
void pr()
{
	printf("vet stk=%d\n", stk);
	for(int i = 0;i < stk;i++)
	{
		printf("[%d]\n", i);
		for(int j = 0;j < a[i].size();i++)
			printf("%d%c", a[i][j], " \n"[j==a[i].size()-1]);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		stk = top = 0;
		memset(a, 0, sizeof(a));
		for(int i = 0;i < MOD;i++)
			nxt[i] = -1;
		LL x, y;
		while(n--)
		{
			scanf("%d%d", &x, &y);
			int i = find(x), j = find(y);
			printf("%d %d %d %d\n", x, y, i, j);

			if(i == -1 && j == -1)
			{
				a[stk].push_back(y);
				insert(x, stk, 0);
				a[stk].push_back(x);
				insert(y, stk, 1);
			}
			else if(i == -1)
			{
				a[stk].push_back(y);
				insert(x, stk, 0);
				a[j].push_back(x);
			}
			else if(j == -1)
			{
				a[stk].push_back(x);
				insert(y, stk, 0);
				a[i].push_back(y);
			}
			else
			{
				int k;
				for(k = 0;k < a[i].size();k++)
					if(a[i][k] == y)
						break;
				if(k == a[i].size())
				{
					a[i].push_back(y);
					a[j].push_back(x);
				}
			}
			pr();
		}
		printf("--------\n");
		pr();
		for(int i = 0;i < MOD;i++) if(flag[i] != -1 && a[i].size() > 1)
		{
			for(int j = 0;j < a[i].size();i++)
			{
				int v = a[i][j];
				int k = find(v);
				if(a[k].size() > 1)
					del(k);
			}
		}
		pr();
		int as, bs, cs;
		for(int i = 0;i < MOD;i++)
			if(a[i].size() && flag[i] != -1)
			{
				if(a[i].size() == 1)
					cs++;
				else if(flag[i] == 0)
					as++;
				else if(flag[i] == 1)
					bs++;
			}
		cs /= 2;
		printf("%d %d %d\n", as, bs, cs);
	}
	return 0;
}