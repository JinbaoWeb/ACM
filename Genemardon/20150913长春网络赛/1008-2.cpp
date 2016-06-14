#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int num[1005];
string ans[1005];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		//memset(ans, 0, sizeof(ans));
		int n;
		scanf("%d%d", &n, &num[0]);
		ans[num[0]] = "";
		for(int i = 1;i < n;i++)
			scanf("%d", &num[i]);
		int p = n-1;
		for(int i = 1;i < n;i++)
			if(num[i] > num[0])
			{
				p = i-1;
				break;
			}
		//printf("p---%d\n", p);
		for(int i = 1;i <= p;i++)
		{
			if(num[i] < num[i-1])
				ans[num[i]] = ans[num[i-1]]+"E";
			else
				ans[num[i]] = ans[num[i-1]]+"W";
			//cout << num[i] << " " << ans[i] << endl;
			
		}
		ans[num[p+1]] = "W";
		for(int i = p+2;i < n;i++)
		{
			if(num[i] < num[i-1])
				ans[num[i]] = ans[num[i-1]]+"E";
			else
				ans[num[i]] = ans[num[i-1]]+"W";
			//cout << num[i] << " " << ans[i] << endl;
		}
		int m;
		scanf("%d", &m);
		while(m--)
		{
			int i;
			scanf("%d", &i);
			cout << ans[i] << endl;
		}
		//cout << endl;
	}
	return 0;
}
