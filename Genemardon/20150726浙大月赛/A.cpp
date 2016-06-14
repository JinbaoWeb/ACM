#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int tot, an[10000], bn[20];
int phi[100]={0,1, 1, 2, 2, 4, 2, 6, 4, 6, 4, 10, 4, 12, 6, 8, 8, 16, 6, 18, 8, 12, 10, 22, 8, 20, 12, 18, 12, 28, 8, 30, 16, 20, 16, 24, 12, 36, 18, 24, 16, 40, 12, 42, 20, 24, 22, 46, 16, 42, 20, 32, 24, 52, 18, 40, 24, 36, 28, 58, 16, 60, 30, 36, 32, 48, 20, 66, 32, 44};
int rad[100]={0,1, 2, 3, 2, 5, 6, 7, 2, 3, 10, 11, 6, 13, 14, 15, 2, 17, 6, 19, 10, 21, 22, 23, 6, 5, 26, 3, 14, 29, 30, 31, 2, 33, 34, 35, 6, 37, 38, 39, 10, 41, 42, 43, 22, 15, 46, 47, 6, 7, 10, 51, 26, 53, 6, 55, 14, 57, 58, 59, 30, 61, 62, 21, 2, 65, 66, 67, 34, 69, 70, 71, 6, 73, 74, 15, 38, 77, 78};
void factor(int n, int a[], int b[], int &tot)
{
	int temp, i, now;
	temp = (int ) ((double) sqrt(n)+1);
	tot = 0;
	now = n;
	for(i = 2;i < temp;++i) if(now % i == 0)
	{
		a[++tot] = i;
		b[tot] = 0;
		while(now % i == 0)
		{
			++b[tot];
			now /= i;
		} 
	}
	if(now != 1)
	{
		a[++tot] = now;
		b[tot] = 1;
	}
}
/*int rad(int d)
{
	factor(d, a, b, tot);
	int sum = 1;
	for(int i = 1;i <= tot;i++)
		sum *= a[i];
	return sum;
}*/

int f[100];
void set()
{
	for(int i = 1;i < 60;i++)
	{
		f[i] = rad[i]*phi[i/rad[i]];
		printf("f[%d] = %2d * %2d = %2d\n",i, rad[i], phi[i/rad[i]],f[i]);
	}
}
int main()
{
	set();
	int sum = 0;
	
	return 0;
}