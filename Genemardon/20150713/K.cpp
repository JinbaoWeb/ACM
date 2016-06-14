#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define N 512010
char A[300], B[N];
int pre[300], l;
int la, lb, sb[N], flag[N];
int L[N];
void set()
{
	la = strlen(A);
	memset(pre, 0, sizeof(pre));
	pre[0] = -1;
	for(int i = 1;i < la;i++)
	{
		int j = pre[i-1];
		while(j >= 0 && A[j+1] != A[i])
			j = pre[j];
		pre[i] = A[j+1] == A[i] ? j+1:-1;
	}
}
int main()
{
	//freopen("in", "r", stdin);
	while(~scanf("%s%s", A, B))
	{
		set();
		memset(flag, 0, sizeof(flag));
		lb = strlen(B);
		int j = -1, r = 0;
		l = 0;
		for(int i = 0;i < lb;i++)
		{
			L[l++] = i;
			while(j >= 0 && B[i] != A[j+1])
				j = pre[j];
			if(B[i] == A[j+1])
				j++;
			if(j == la-1)
			{
				r++;
				l -= la;
				j = sb[L[l-1]];
			}
			sb[i] = j;
			//printf("l----%d\n", l);
		}
		printf("%d\n", r);
	}
	return 0;
}