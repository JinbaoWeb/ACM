#Codeforces 586C Gennady the Dentist 模拟
标签：解题报告
***
##原题见[CF 586C](http://codeforces.com/contest/586/problem/C)
听说有人跪了，特来写一发题解。
有n个排队小屁孩看病，各自有三个值v,d,p，分别表示进门后对门外小孩的杀伤力、在门外时的杀伤力、自己的基本分。其中v是一个随着距离增大1而减小作用1的值。
进门了的小孩发挥v的作用，在门外p<0的小孩对后面排队的小孩发挥d的作用。同时p<0的小孩被吓哭都跑了。
现在问的是多少个小孩能顺利进门看病。也就是没有跑路的。

模拟一下吓哭和杀伤的过程即可。

Hack点在于，如果不加判断一直减d，在极端条件下($4\times 10^3\times 10^6$)会使得p值作为一个负数int溢出变成正的，造成错误。所以需要特判负数不必再减d.

##附code
```cpp
/*--------------------------------------------
 * File Name: CF 586 C
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-12 17:44:58
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 4010
int n, ans[N], top;
struct node
{
	int v, d, p, here;
	void scan(int i){
		scanf("%d%d%d", &v, &d, &p);
		here = 1;
	}
}kid[N];
void test(int j)
{
	kid[j].here = 0;
	for(int k = j+1;k <= n;k++)
	{
		if(!kid[k].here) continue;
		if(kid[k].p < 0) continue;
		kid[k].p -= kid[j].d;
	}
	for(int k = j+1;k <= n;k++)
	{
		if(kid[k].here && kid[k].p < 0)
			test(k);
	}
}
int main()
{
	while(~scanf("%d", &n))
	{
		top = 0;
		for(int i = 1;i <= n;i++)
			kid[i].scan(i);
		for(int i = 1;i <= n;i++)
		{
			if(!kid[i].here) continue;
			ans[top++] = i;
			for(int j = i+1;j <= n;j++)
			{
				if(kid[i].v <= 0) break;
				if(!kid[j].here) continue;
				kid[j].p -= kid[i].v--;
			}
			for(int j = i+1;j <= n;j++)
			{
				if(kid[j].here && kid[j].p < 0)
					test(j);
			}
		}
		printf("%d\n", top);
		for(int i = 0;i < top;i++)
			printf("%d%c", ans[i], " \n"[i==top-1]);
	}
	return 0;
}
```


