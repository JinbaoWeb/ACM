#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL __int64
LL num[100010];
LL extend_Euclid(LL a, LL b, LL &x, LL &y){
	if(b==0){
	x = 1; y = 0;
	return a;
	}
	LL r = extend_Euclid(b, a%b, y, x);
	y -= a/b*x;
	return r;
}
LL anti(LL a, LL M)
{
	LL x, y;
	extend_Euclid(a, M, x, y);
	return (x%M+M)%M;
}
int main()
{
	int T, o = 0;
	scanf("%d", &T);
	while(T--)
	{
		printf("Case #%d:\n", ++o);
		int n, op;
		LL x, ans = 1, M;
		scanf("%d%lld", &n, &M);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%lld", &op, &x);
			num[i] = x;
			if(op == 1)
			{
				ans *= x;
			}
			else if(op == 2)
			{
				//LL tmp = anti(num[x], M);
				//ans = (ans*tmp)%M;
				ans /= num[x];
			}
			printf("%I64d\n", ans%M);
		}
	}
	return 0;
}