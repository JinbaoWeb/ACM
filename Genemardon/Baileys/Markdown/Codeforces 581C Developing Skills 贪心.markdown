#Codeforces 581C Developing Skills 贪心

标签： 解题报告 贪心

---

原题见[CF 581C](http://codeforces.com/contest/581/problem/C)
给一个大小为n(1~$10^5$)的数组a[n]，数值在0~100。再给一个附加值k，可以分成几个部分随意地加到$a_i$上，但最多把$a_i$加到100.求$max\sum_{i=1}^n ⌊{a_i\over 10}⌋$

1. 把所有的$a_i/10$到ans。
2. 可以先把$a_i\%10$的值存下来，从9到1开始填，这样贪心可以保证花了最少的附加值把其补充到10.每次多一个10就让ans++
3. 把零头填完以后再看是否有多余的附加值。如果还有多余的，那么把剩下所有的坑填满直到100，则完成。剩下所有可能的坑能产生的分数为10n-ans，和k/10比比哪个更小即可。

```cpp
/*--------------------------------------------
 * File Name: CF 581 C
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-28 17:21:52
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int a[100010], b[10];
int main()
{
	int n, k;
	while(~scanf("%d%d", &n, &k))
	{
		int ans = 0;
		memset(b, 0, sizeof(b));
		for(int i = 0;i < n;i++)
		{
			scanf("%d", &a[i]);
			ans += a[i]/10;
			b[a[i]%10]++;
		}
		for(int i = 1;i < 10;i++)
		{
			int s = min(b[10-i], k/i);
			k -= i*s;
			ans += s;
			if(s != b[10-i])
				break;
		}
		ans += min(10*n-ans, k/10);
		printf("%d\n", ans);
	}
	return 0;
}
```



