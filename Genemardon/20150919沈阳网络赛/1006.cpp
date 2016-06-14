#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1000010
char str[N];
int stack[N];
int main()
{
	int T, o = 0, num;
	scanf("%d", &T);
	while(T--)
	{
		int top = 0;
		scanf("%s", str);
		printf("Case #%d: ", ++o);
		int len = strlen(str), ans = 0, v = 0;
		for(int i = 0;i < len;i++)
		{
			//printf("%d %d\n", i, ans);
			if(!(str[i] == 'c' || str[i] == 'f'))
			{
				printf("-1\n");
				v = 1;
				break;
			}
			if(str[i] == 'c')
			{
				stack[top++] = i;
				ans++;
				num = 0;
				for(int j = i+1;j < len;j++)
				{
					if(str[j] == 'c')
					{
						printf("-1\n");
						v = 1;
						break;
					}
					if(str[j] == 'f')
						num++;
					if(num >= 2)
					{
						i = j;
						break;
					}
				}
			}
			if(v)
				break;
		}
		if(v)
			continue;
		int plus = 0;
		for(int i = 0;i < len;i++)
			if(str[i] == 'c')
			{
				plus = i;
				//printf("plus  %d\n", plus);
				break;
			}
		if(top && len-stack[top-1] <= 2 && plus+num < 2)
		{
			printf("-1\n");
			continue;
		}
		if(top == 0)
			ans = len/2+len%2;
		printf("%d\n", ans);
	}
	return 0;
}