#Codeforces 583C GCD Table 模拟 map
标签：解题报告 map 模拟
***
##原题见[CF 583C](http://codeforces.com/contest/583/problem/C)
对于一个数组a[n],定义一个n*n的gcd矩阵，b[i][j]=gcd(a[i], a[j]).现在乱序给出矩阵内的全部元素，求原数组a[n].

如果已知原数组得到gcd矩阵，则可得到对角线上的数字就是原数组里的数。且gcd矩阵有一个性质：一行里的最大值在与对角线的交点上，一列同理。

于是可以先找到n*n个数里找到最大值，必定是a[n]里的一个值。
用归纳的办法，已经被挑选的数字ans[]之间的gcd均在b[n][n]数组里删去。然后在剩余的b数组内找到最大值，放入ans[]，再去掉ans[]内各个数的gcd.如图，每次选取对角线上的数，再将左上方的数去掉，再找到下一个对角线上的数，依此类推。
一边删，一边取，最后取完n个数即可。

##代码解释
第一次用了`map`，因为有$10^9$个数，这样找数会非常方便。
`map <int, int> mp`其中第一维存关键字，第二维统计出现的次数。
`a[n]`存所有的关键字，去重后排序
`ans[n]`存答案
`get()`返回新的正方形中对角线上的最大数
`solve()`将新的数字添加到答案，并删掉相应的gcd

##附code
```cpp
/*--------------------------------------------
 * File Name: CF 583 C
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-04 01:33:09
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
#define N 251000
map <int, int> mp;
map <int, int>::iterator iter;

int a[N], top, ans[N], si, n, p;
int cmp(int x, int y)
{
	return x > y;
}
int gcd(int x, int y)
{
	return y == 0?x:gcd(y, x%y);
}
int get()
{
	iter = mp.find(a[p]);
	if(iter->second > 0)
	{
		iter->second--;
		return a[p];
	}
	p++;
	return get();
}
void solve()
{
	while(si != n)
	{
		ans[si++] = get();
		for(int i = 0;i < si-1;i++)
		{
			int g = gcd(ans[i], ans[si-1]);
			iter = mp.find(g);
			iter->second -= 2;
		}
	}
	for(int i = 0;i < si;i++)
		printf("%d%c", ans[i], " \n"[i==si-1]);
}
int main()
{
	while(~scanf("%d", &n))
	{
		mp.clear();
		memset(a, 0, sizeof(a));
		top = si = p = 0;
		for(int i = 0;i < n*n;i++)
		{
			int t;
			scanf("%d", &t);
			iter = mp.find(t);
			if(iter == mp.end())
			{
				a[top++] = t;
				mp[t] = 1;
			}
			else
				mp[t]++;
		}
		sort(a, a+top, cmp);
		solve();
	}
	return 0;
}
```