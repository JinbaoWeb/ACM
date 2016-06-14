#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int hp[100], n, att;
void pr()
{
	for(int i = 0;i < n;i++)
		printf("%d ", hp[i]);
	printf("%d\n", att);
}
int main()
{
	int T, c;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &c);
		for(int i = 0;i < n;i++)
			scanf("%d", &hp[i]);
		int size = n, dir = 1, k = 0;
		att = 0;
		while(size > 1 && att <= n+5)
		{
			if(hp[k] <= 0)
			{
				k = ((k+dir)%n+n)%n;
				//pr();
				continue;
			}
			hp[k] -= c;
			att++;
			if(att == n+5)
				break;
			if(hp[k] <= 0)
			{
				dir *= -1;
				size--;
				hp[k] = 0;
			}
			k = ((k+dir)%n+n)%n;
			//pr();
		}
		if(size > 1)
			printf("%d\n", k+1);
		else for(int i = 0;i < n;i++)
			if(hp[i] > 0)
				printf("%d\n", i+1);
	}
	return 0;
}