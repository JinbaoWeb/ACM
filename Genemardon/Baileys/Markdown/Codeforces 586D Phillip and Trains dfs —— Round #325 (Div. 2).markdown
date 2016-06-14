#Codeforces 586D Phillip and Trains dfs —— Round #325 (Div. 2) 
标签：解题报告
***
##原题见[CF 586D](http://codeforces.com/contest/586/problem/D)
给一个3*n的地图，人s从最左边一列的某个位置出发，每次先向右走一步，再选择上、下、不动。接着连续的字母表示火车，均向左走两步。如此循环，人和火车不能相撞。问人是否能走到地图的最右边。

人相对火车的水平距离其实是每次走了三步，火车可以不用动。
只要人走到当前地图的最右边，之后就不会再出现火车，输出YES即可。
所以先扩展一下地图，让之后n+10列均为'.'，然后dfs跑完即可。

搜索过的点要做个已经搜索的标记，否则会T.
昨天改完以后最后15秒的时候交的，超刺激！

##附code
```cpp
/*--------------------------------------------
 * File Name: CF 586 D
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
int n, k, ans;
char str[3][150];
int mp[3][150];
int dfs(int x, int y)
{
	mp[x][y] = 1;
	if(y >= n-1)
		return 1;
	if(str[x][y+1] != '.')		
		return 0;
	for(int i = 0;i < 3;i++)
	{
		if(abs(i-x) > 1) continue;
		int v = 0;
		for(int j = 1;j < 4;j++)
		{
			if(str[i][y+j] != '.')
			{
				v = 1;
				break;
			}
		}
		if(v) continue;
		if(!mp[i][y+3])
		{
			int v = dfs(i, y+3);
			if(v) return 1;
		}
	}
	return 0;
}
int main()
{
	int T;
	while(~scanf("%d", &T))
	{
		while(T--)
		{
			memset(mp, 0, sizeof(mp));
			ans = 0;
			scanf("%d%d", &n, &k);
			for(int i = 0;i < 3;i++)
			{
				scanf("%s", str[i]);
				for(int j = 0;j < 10;j++)
					str[i][n+j] = '.';
				str[i][n+10] = '\0';	
	 		}
			for(int i = 0;i < 3;i++)
			{
				if(str[i][0] == 's')
				{
					int ans = dfs(i, 0);
					if(ans)
						printf("YES\n");
					else
						printf("NO\n");
					break;
				}
			}
		}
	}
	return 0;
}
```