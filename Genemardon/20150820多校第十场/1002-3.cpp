#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int ans[1000001]={0,};
int main
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", ans[x]);
	}
	return 0;
}