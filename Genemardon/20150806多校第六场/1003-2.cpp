/*--------------------------------------------
 * File Name: M6 1003
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-08-06 12:28:02
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define LL __int64
#define N 100005
int flag[N], n, m;
int dfs(int k)
{
	if(k == m)
		return 0;
	
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(flag, 0, sizeof(flag));
		scanf("%d%d", &n, &m);
		LL sum = (LL)(n+1)*(LL)n/2;
		printf("%I64d\n", sum);
		if(sum%m || sum/m<n)
		{
			printf("NO\n");
			continue;
		}
		LL part = sum/m;
		dfs(0);
	}
	return 0;
}