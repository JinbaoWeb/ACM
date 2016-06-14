#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 105
using namespace std;

int cube[MAXN][MAXN][MAXN];
int N,M;

int low_bit(int x)
{
    return x & (-x);
}
//更新三维树状数组
void update(int x,int y,int z)
{
    for(int i = x; i <= N; i += low_bit(i))
    for(int j = y; j <= N; j += low_bit(j))
    for(int k = z; k <= N; k += low_bit(k))
    cube[i][j][k]++;
}

int sum(int x,int y,int z)
{
    int ans=0;
    for(int i = x; i > 0; i -= low_bit(i))
    for(int j = y; j > 0; j -= low_bit(j))
    for(int k = z; k > 0; k -= low_bit(k))
    ans += cube[i][j][k];
    return ans;
}

int main()
{
    int oper;
    int x1,y1,z1,x2,y2,z2;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        memset(cube,0,sizeof(cube));
        for(int i = 0; i < M; i++)
        {
            scanf("%d",&oper);
            if(oper==1)
            {
                scanf("%d%d%d %d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
                //三维树状数组更新，容斥原理
                update(x1,y1,z1);
                update(x1,y1,z2+1);
                update(x1,y2+1,z1);
                update(x1,y2+1,z2+1);
                update(x2+1,y1,z1);
                update(x2+1,y1,z2+1);
                update(x2+1,y2+1,z1);
                update(x2+1,y2+1,z2+1);
            }
            else if(oper == 0)
            {
                 scanf("%d%d%d",&x1,&y1,&z1);
                 printf("%d\n",sum(x1,y1,z1)&1);
            }

        }
    }

    return 0;
}