#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define N 500010
int w[N], in[N], out[N], ans[N];
vector<int> node[N];
int topo(int n)
{
	queue <int> Q;
	for(int i = 1;i <= n;i++)
	{
		ans[i] = 1;
		if(in[i] == 0)
			Q.push(i);
	}
	int r = ans[1];
	while(!Q.empty())
	{
		int y = Q.front();
		Q.pop();
		//printf("yyyy %d %d\n", y, ans[y]);
		for(int j = 0;j < node[y].size();j++)
		{
			int t = node[y][j];
			in[t]--;
			if(in[t] == 0)
				Q.push(t);
			ans[t] += ans[y];
			if(out[t] == 0)
				r = max(r, ans[t]);
			//printf("%d %d %d\n", y, t, ans[t]);
		}
	}
	return r;
}
void init()
{
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	//memset(node, 0, sizeof(node));
	memset(ans, 0, sizeof(ans));
	for(int i = 0;i < N;i++)
		node[i].clear();
}
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		init();
		for(int i = 1;i <= n;i++)
			scanf("%d", &w[i]);
		for(int i = 0;i < n-1;i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			if(w[u] < w[v])
				swap(u, v);
			node[u].push_back(v);
			in[v]++;
			out[u]++;
		}
		printf("%d\n", topo(n));
	}
	return 0;
}