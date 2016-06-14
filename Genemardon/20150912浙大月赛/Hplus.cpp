#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define Mod 880803841
#define N 100
#define LL long long
LL anti[N] = {1, 1};
LL extend_Euclid(LL a, LL b, LL &x, LL &y){
	if(b==0){
	x = 1; y = 0;
	return a;
	}
	LL r = extend_Euclid(b, a%b, y, x);
	y -= a/b*x;
	return r;
}
LL equation(LL a, LL b, LL c)
{
    LL x, y;
    LL g = extend_Euclid(a, b, x, y);
    if(c % g)
        return 0;    //表示无解
    LL ran = b/g;
        //只需存最小整数解
    return (c/g*x%ran+ran)%ran;
}
void set()
{
	for(int i = 2;i < N;i++)
	{
		LL t = equation(i, Mod, 1);
		anti[i] = anti[i-1]*t%Mod;
		printf("%d ", anti[i]);
	}
}
int main()
{
	set();
	return 0;
}