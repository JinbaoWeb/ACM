#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int n = 1000000007;
	for(int i = 2;i <= sqrt(n);i++)
		if(n % i == 0)
			printf("%d\n", i);
	return 0;
}