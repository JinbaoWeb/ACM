#HDU 5492 Find a path DP —— 2015 ACM/ICPC Asia Regional Hefei Online

标签：解题报告 DP

---

###原题见[HDU 5492](http://acm.hdu.edu.cn/showproblem.php?pid=5492)
给一个N*M的矩阵，从(1,1)到(N,M)经过的格点分值分别为$A_i$，(路径只能向右或向下走,共N+M-1步)。求各种路径中最大的$(N+M−1)\sum_{i=1}^{N+M−1}(A_i−A_{avg})^2$.其中$A_{avg}为A_i的均值$
N，M分别为1~30的整数，$A_i$为不超过30的整数。

首先对表达式进行化简：$\sum_{i=1}^{N+M−1}$先记为$\sum$
$$(N+M−1)\sum(A_i−A_{avg})^2$$$$=(N+M−1)\sum(A_i^2+A_{avg}^2-2A_iA_{avg})$$
其中$A_{avg}={1\over {N+M-1}}\sum A_i$,则$\sum 2A_iA_{avg}=2(N+M-1)A_{avg}^2$
$$原式=(N+M−1)[(\sum A_i^2)-(N+M-1)A_{avg}^2]$$$$=(N+M−1)\sum A_i^2-(\sum A_i)^2$$设$a=\sum A_i^2,b=\sum A_i$则只要在图上的格点p[i][j]存下每个b对应的最大的a值并向右下角DP即可。其中b为不超过30*(30+30)=1800的数，故在p[i][j]上开一个大小为2000的数组c[2000]即足够存下所有状态b.使得c[b]=max{a}.

###附code：
```cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int v, a, b, c[2000];
}p[50][50];
int fac(int x)
{
	return x*x;
}
int main()
{
	int T, o = 0;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(p, 0, sizeof(p));
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				scanf("%d", &p[i][j].v);
		p[1][1].a = fac(p[1][1].v);
		p[1][1].b = p[1][1].v;
		p[1][1].c[p[1][1].v] = fac(p[1][1].v);
		for(int j = 2;j <= m;j++)
		{
			p[1][j].a = p[1][j-1].a+fac(p[1][j].v);
			p[1][j].b = p[1][j-1].b+p[1][j].v;
			p[1][j].c[p[1][j].b] = p[1][j].a;
		}
		for(int i = 2;i <= n;i++)
		{
			p[i][1].a = p[i-1][1].a+fac(p[i][1].v);
			p[i][1].b = p[i-1][1].b+p[i][1].v;
			p[i][1].c[p[i][1].b] = p[i][1].a;
		}
		for(int i = 2;i <= n;i++)
			for(int j = 2;j <= m;j++)
				for(int k = 0;k < 2000;k++)
				{
					if(p[i][j-1].c[k])
					{
						int f = k+p[i][j].v;
						if(p[i][j].c[f])
							p[i][j].c[f] = min(p[i][j].c[f], p[i][j-1].c[k]+fac(p[i][j].v));
						else
							p[i][j].c[f] = p[i][j-1].c[k]+fac(p[i][j].v);
					}
					if(p[i-1][j].c[k])
					{
						int f = k+p[i][j].v;
						if(p[i][j].c[f])
							p[i][j].c[f] = min(p[i][j].c[f], p[i-1][j].c[k]+fac(p[i][j].v));
						else
							p[i][j].c[f] = p[i-1][j].c[k]+fac(p[i][j].v);
					}
				}
		int ans = 1000000000;
		for(int i = 0;i < 2000;i++)
			if(p[n][m].c[i])
				ans = min(ans, (n+m-1)*p[n][m].c[i]-fac(i));
		printf("Case #%d: %d\n", ++o, ans);
	}
	return 0;
}
```