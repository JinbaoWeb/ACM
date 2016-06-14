#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define LL int
struct node
{
	LL l, r;
	node(){}
	node(LL a, LL b){
		l = a, r = b;
	}
	void pr(){
		printf("%d %d\n", l, r);
	}
}F;
queue <node> Q;
const LL _Max = 2100000000;
int ok(int x, int y)
{
	if(y-x > x-1)
		return 0;
	if(x == y)
		return -1;
	return 1;
}
int main()
{
	LL L, R;
	while(~scanf("%d%d", &L, &R))
	{
		while(!Q.empty())
			Q.pop();
		LL ans = _Max;
		if(L == 0 || L == R)
			ans = R;
		if(ok(L, R) == 1)
			Q.push(node(L, R));
		while(!Q.empty())
		{
			F = Q.front();
			Q.pop();
			//F.pr();
			/*if(F.r-F.l > F.l-1)
				continue;
			else */
			if(F.r - F.l == F.l-1 || F.r - F.l == F.l-2)
			{
				ans = min(F.r, ans);
				continue;
			}
			if(2*F.l-F.r-1 == 0 || 2*F.l-F.r-2 == 0)
				ans = min(F.r, ans);
			if(F.l == 0)
				ans = min(2*F.r-F.l, ans);
			if(ok(2*F.l-F.r-1, F.r) == 1)
				Q.push(node(2*F.l-F.r-1, F.r));
			if(ok(2*F.l-F.r-2, F.r) == 1)
				Q.push(node(2*F.l-F.r-2, F.r));
			if(ok(F.l, 2*F.r-F.l+1) == 1)
				Q.push(node(F.l, 2*F.r-F.l+1));
			if(ok(F.l, 2*F.r-F.l) == 1)
				Q.push(node(F.l, 2*F.r-F.l));
		}
		if(ans == _Max)
			ans = -1;
		printf("%d\n", ans);
		//printf("\n");
	}
	return 0;
}