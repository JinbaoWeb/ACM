#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 500001
int flag[N];
int main()
{
	freopen("in", "w", stdout);
	srand((unsigned)time(NULL));
	memset(flag, 0, sizeof(flag));
	int t = rand()%40000+1;
	printf("%d\n", t);
	for(int i = 1;i <= t;i++)
	{
		char s = rand()%2 + 'A';
		int n = 100*(rand()%1000+1)+rand()%1000+1;
		if(s == 'A')
		{
			if(!flag[n])
				flag[n] = 1;
			else
			{
				i--;
				continue;
			}
		}
		printf("%c %d\n", s, n);
	}
	printf("0\n");
	return 0;
}