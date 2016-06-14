#Codeforces 581D Three Logos 模拟 枚举
标签： 解题报告 模拟
***
原题见[CF 518D](http://codeforces.com/contest/581/problem/D)
给出三个矩形的长、宽。问你怎么才能拼成一个完整的**正方形**。按照输入的先后顺序分别标A,B,C,把这个正方形的边长和形状输出。如果做不到的就输出-1.

当时竟然把正方形看成了矩形。莫怪我呀，然后枚举了n多情况写不下去了只好罢手。其实如果是正方形的话，很显然只有这两种形状的正方形：
$AAAAA~~~~~~~~~~~~~~BBBBBB$
$BBBBB~~~~~~~~~~~~~~BBBBBB$
$BBBBB~~~~~~~~~~~~~~AAAACC$
$CCCCC~~~~~~~~~~~~~~AAAACC$
$CCCCC~~~~~~~~~~~~~~AAAACC$
那么我只要先把边长最长的矩形找出来先放在最上面，然后分类枚举，答案就可以搞出来了！

- 对长和宽预处理，把大的边放前面。
- 将最长的矩形放在最前面，p[i].z保留初始的编号。
- 判断p[0].x为边长的正方形的面积是否为总面积。否则输出-1.
- rec(x,y,a,b,z)是将长宽为a,b的矩形左上角的坐标为(x,y)的矩形填到mp[][]当中，填入其中的是矩形的编号。
- pr(a)直接把这个大正方形输出即可。

Too young! Too simple! Sometimes naive!

附code:
```cpp
/*--------------------------------------------
 * File Name: CF 518 D
 * Author: Danliwoo
 * Mail: Danliwoo@live.com
 * Created Time: 2015-09-29 16:42:25
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int mp[300][300];
struct node
{
	int x, y, z;
}p[3];
int cmp(node a, node b)
{
	return a.x > b.x || (a.x == b.x && a.y > b.y);
}
void rec(int x, int y, int a, int b, int z)
{
	for(int i = x;i <= x+a;i++)
		for(int j = y;j <= y+b;j++)
			mp[i][j] = z;
}
void pr(int x)
{
	for(int i = 0;i < x;i++)
	{
		for(int j = 0;j < x;j++)
			printf("%c", mp[j][i]+'A');
		printf("\n");
	}
}
int solve(int a, int b, int c, int d, int e, int f, int x, int y, int z)
{
	if(a*a != a*b+c*d+e*f)
		return 1;
	if(a == c && c == e && b+d+f == a)
	{
		rec(0, b, c, d, y);
		rec(0, b+d, e, f, z);
		return 0;
	}
	if(c == e && d+f == a && b+c == a)
	{
		rec(0, b, f, e, z);
		rec(f, b, d, c, y);
		return 0;
	}
	if(c == f && d+e == a && b+c == a)
	{
		rec(0, b, e, f, z);
		rec(e, b, d, c, y);
		return 0;
	}
	if(d == e && c+f == a && b+d == a)
	{
		rec(0, b, f, e, z);
		rec(f, b, c, d, y);
		return 0;
	}
	if(d == f && c+e == a && b+d == a)
	{
		rec(0, b, e, f, z);
		rec(e, b, c, d, y);
		return 0;
	}
	return 1;
}
int main()
{
	while(~scanf("%d%d%d%d%d%d", &p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y))
	{
		for(int i = 0;i < 3;i++)
		{
			p[i].z = i;
			if(p[i].x < p[i].y)
				swap(p[i].x, p[i].y);
		}
		sort(p, p+3, cmp);
		rec(0, 0, p[0].x, p[0].y, p[0].z);
		if(solve(p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y, p[0].z, p[1].z, p[2].z))
			printf("-1\n");
		else
		{
			printf("%d\n", p[0].x);
			pr(p[0].x);
		}
	}
	return 0;
}
```

