#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define range 46350
#define MAXN 2
#define LL __int64
int ans[range], Mod;
int biao[range];
struct Matrix{
	int n, m;
	int a[MAXN][MAXN];
	void clear(){
		n = m = 0;
		memset(a, 0, sizeof(a));
	}
	void pr()
	{
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				printf("%d%c", a[i][j], " \n"[j==m-1]);
		printf("\n");
	}
	void set(int p[2][2], int x, int y)
	{
		n = x, m = y;
		memcpy(a, p, sizeof(a));
	}
	Matrix operator * (const Matrix &b) const{
		Matrix tmp;
		tmp.clear();
		tmp.n = n; tmp.m = b.m; //where is n, m, a[i][j] from?
		for(int i = 0;i < n;i++)
			for(int j = 0;j < b.m;j++)
				for(int k = 0;k < m;k++)
				{
					tmp.a[i][j] += a[i][k] * b.a[k][j]%Mod;
					tmp.a[i][j] %= Mod;
				}
		return tmp;
	}
};
int a[2][2] = {5,12,2,5};
int e[2][2] = {1, 0, 0, 1};
Matrix A, B, I;
LL po(int a, LL k, int m)
{
	if(k == 0)
		return 1;
	if(k == 1)
		return 1LL*a;
	LL t = po(a, k/2, m);
	t = t*t%m;
	if(k & 1LL)
		t *= a;
	return t%m;
}
Matrix po(Matrix a, int k)
{
	if(k == 0) return I;
	if(k == 1) return a;
	Matrix t = po(a, k/2);
	t = t*t;
	if(k&1LL)
		t = t*a;
	return t;
}
int main()
{
	int T, o = 0;
	A.set(a, 2, 2);
	scanf("%d", &T);
	memset(biao, 0, sizeof(biao));
	while(T--)
	{
		LL n;
		scanf("%I64d%d", &n, &Mod);

			B = A;
			int p;
			ans[0] = 1; ans[1] = 5;
			for(int i = 2;i < Mod+10;i++)
			{
				B = B*A;
				ans[i] = B.a[0][0];
				//printf("%d %d %d %d\n", i, ans[i], 2*ans[i]-1, (2*ans[i]-1)%Mod);
				if(i && ans[i] == ans[0])
				{
					biao[Mod] = p = i;
					break;
				}
			}
			LL s = po(2, n, p);
			n = (s+1)%p;
			printf("p %d\n", p);
			printf("Case #%d: %d\n", ++o, (2*ans[n]-1)%Mod);
		
	}
	return 0;
}