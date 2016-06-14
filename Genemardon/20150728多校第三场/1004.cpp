#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
char mp[55][55];
int main()
{
	//freopen("4in", "r", stdin);
	int T, n, m;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%s", mp[i]);
		int i, j, ans = 0, m = strlen(mp[0]);
		for(int k = 0;k < m;k++)
		{
			i = 0;
			j = k;
			while(i < n && j < m && i>= 0 && j>=0)
			{
				int v = 0;
				while(i < n && j < m && i>= 0 && j>=0 && (mp[i][j] == 'R' || mp[i][j] == 'G'))
				{
					v = 1;
					i++; j++;
				}
				if(v && (mp[i-1][j-1] == 'R' || mp[i-1][j-1] == 'G'))
					ans++;
				if(!v)
				{
					i++; j++;
				}
			}
		}
		printf("%d\n", ans);
		for(int k = 1;k < n;k++)
		{
			i = k;
			j = 0;
			while(i < n && j < m && i>= 0 && j>=0)
			{
				int v = 0;
				while(i < n && j < m && i>= 0 && j>=0 && (mp[i][j] == 'R' || mp[i][j] == 'G'))
				{
					v = 1;
					i++; j++;
				}
				if(v && (mp[i-1][j-1] == 'R' || mp[i-1][j-1] == 'G'))
					ans++;
				if(!v)
				{
					i++; j++;
				}
			}
		}
		printf("%d\n", ans);
		for(int k = 0;k < m;k++)
		{
			i = 0;
			j = k;
			while(i < n && j < m && i>= 0 && j>=0)
			{
				int v = 0;
				while(i < n && j < m && i>= 0 && j>=0 && (mp[i][j] == 'B' || mp[i][j] == 'G'))
				{
					v = 1;
					i++; j--;
				}
				if(v && (mp[i-1][j+1] == 'B' || mp[i-1][j+1] == 'G'))
					ans++;
				if(!v)
				{
					i++; j--;
				}
			}
		}
		printf("%d\n", ans);
		for(int k = 1;k < n;k++)
		{
			i = k;
			j = m-1;
			while(i < n && j < m && i>= 0 && j>=0)
			{
				int v = 0;
				while(i < n && j < m && i>= 0 && j>=0 && (mp[i][j] == 'B' || mp[i][j] == 'G'))
				{
					v = 1;
					i++; j--;
				}
				if(v && (mp[i-1][j+1] == 'B' || mp[i-1][j+1] == 'G'))
					ans++;
				if(!v)
				{
					i++; j--;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}