#Codeforces 584C Marina and Vasya
标签：解题报告
***
##原题见[CF 584C](一个字符串)
给1~$10^5$范围内的整数n，t，满足t<=n.再给两个长为n的字符串，求与前两个字符串不同字符个数为t的一个字符串。

范围并不大，可以当作模拟题啊。
先统计字符相同的子串s，长为slen，将其存在一个结构体里。剩下的是不同的子串d1，d2，长为dlen。
可以得到t的范围在${dlen+1\over 2}\leq t\leq n$


如图，颜色相同的地方表示字符相同。于是可以照着如图的拼法得到相应的元素，并将其对应到原位置。

当时错在了产生一个和两个字符均不同的字符，用了较大者加一。反例即(a,z)->a.哎，好惨~~

##附code：
```cpp
/*--------------------------------------------
 * File Name: CF 584 C
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-07 01:11:20
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1000010
struct node
{
	int x;
	char y;
	node(){}
	node(int a, char b){
		x = a, y = b;
	}
}d[2][N], s[N];
char str1[N], str0[N], ans[N];
int dlen, slen;
char get(char x, char y)
{
	if(x != 'a' && y != 'a')
		return 'a';
	if(x != 'b' && y != 'b')
		return 'b';
	if(x != 'c' && y != 'c')
		return 'c';
}
int main()
{
	int n, t;
	while(~scanf("%d%d", &n, &t))
	{
		scanf("%s%s", str0, str1);
		dlen = slen = 0;
		for(int i = 0;i < n;i++)
		{
			if(str0[i] == str1[i])
				s[slen++] = node(i, str1[i]);
			else
			{
				d[0][dlen] = node(i, str0[i]);
				d[1][dlen++] = node(i, str1[i]);
			}
		}
		if(t < (dlen+1)/2 || t > n)
		{
			printf("-1\n");
			continue;
		}
		int q = min(t, dlen);
		for(int i = 0;i < q;i++)
			ans[d[0][i].x] = d[0][i].y;
		for(int i = q;i < dlen-q;i++)
			ans[d[1][i].x] = d[1][i].y;
		for(int i = dlen-q;i < dlen;i++)
			ans[d[0][i].x] = get(d[0][i].y, d[1][i].y);
		int p = max(t-dlen, 0);
		for(int i = 0;i < p;i++)
			ans[s[i].x] = (s[i].y-'a'+1)%26+'a';
		for(int i = p;i < slen;i++)
			ans[s[i].x] = s[i].y;
		ans[n] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}

```


