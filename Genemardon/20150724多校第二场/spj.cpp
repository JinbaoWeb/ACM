#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int num[100005];
int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int n;
	while(~scanf("%d", &n))
	{
		memset(num, 0, sizeof(num));
		for(int i = 1;i <= n;i++)
			num[i] = n;
		int a, c;
		char b;
		for(int i = 0;i < n-1;i++)
		{
			scanf("%d %c %d", &a, &b, &c);
			switch(b)
			{
				case '+':num[n+1+i] = num[a]+num[c];break;
				case '-':num[n+1+i] = num[a]-num[c];break;
				case '*':num[n+1+i] = num[a]*num[c];break;
				case '/':num[n+1+i] = num[a]/num[c];break;
			}
			//printf("%d\n", num[n+1+i]);
		}
		printf("%d\n", num[2*n-1]);
	}
	return 0;
}