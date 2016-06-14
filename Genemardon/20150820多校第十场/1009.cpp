#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define N 100005
char s[N], t[N];
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s%s", s, t);
		int sl = strlen(s), tl = strlen(t),pos=tl;
		for (int i=1;i<tl;i++)
			if (t[i]!=t[i-1])
			{
				pos=i;
				break;
			}
		if (pos>sl)
		{
			printf("No\n");
			continue;
		}
		for (int i=0;i<pos;i++)
			if (s[i]!=t[i])
			{
				pos=-1;
				break;
			}
		if (pos==-1)
		{
			printf("No\n");
			continue;
		}
		if(s[0] != t[0] || sl > tl)
		{
			printf("No\n");
			continue;
		}
		int i, j;
		i = j = 0;

		while(i < sl && j < tl)
		{
			//printf("%d %d\n", i, j);
			if (s[i]==t[j])
			{
				// if (j<tl-1 && t[j]==t[j+1] && s[i]!=s[i+1])
				// {
				// 	if(j == 0) break;
				// 	j++;
				// }
				// else{ i++;j++; }
				i++;j++;
			}
			else j++;
		}
		if(i == sl)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}