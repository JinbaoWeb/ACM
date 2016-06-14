#define ms(x, y) memset(x, y, sizeof(x))
#define mc(x, y) memcpy(x, y, sizeof(x))
#define ls o << 1
#define rs o << 1 | 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#include<list>
#include<set>
#include<algorithm>
using namespace std;
const int N = 1e5 + 100;
const double PI = acos(-1.0);
typedef long long LL;
const LL Z = 1e9 + 7;

LL n, i, j, k, l, a[110], f[110][110];
char b[110];

LL calc(LL x, LL y, char ch)
{
	if(ch == '+') return (x + y) % Z;
	if(ch == '-') return (Z + x - y) % Z;
	if(ch == '*') return (x * y) % Z;
}
int main()
{
	while(~ scanf("%d", &n)){
		ms(f, 0);
		for(i = 1; i <= n; i ++){
			scanf("%d", &a[i]);
		}
		getchar();
		for(i = 1; i < n; i ++){
			scanf("%c", &b[i]);
		}
		for(i = 1; i <= n; i ++){
			f[i][i] = a[i];
		}
		for(l = 2; l <= n; l ++){
			for(i = 1; i <= n; i ++){
				j = min(n, i + l - 1);
				for(k = i; k < j; k ++){
					f[i][j] = (f[i][j] + calc(f[i][k], f[k + 1][j], b[k]) ) % Z;
				}
			}
		}
		printf("%lld\n", f[1][n]);
	}
	return 0;
}