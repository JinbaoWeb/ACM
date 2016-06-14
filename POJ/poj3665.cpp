#include <iostream>
using namespace std;
int r[1234];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        for(int i=1;i<=n;i++) scanf("%d",&r[i]);
        if(n==1)
        {
            while(m--) puts("1");
            continue;
        }
        while(m--)
        {
            int Max=-1,Maxi=1;
            for(int i=1;i<=n;i++)
            {
                if(r[i]>Max)
                {
                    Maxi=i;
                    Max=r[i];
                }
            }
            printf("%d\n",Maxi);
            int k=r[Maxi]/(n-1),kx=r[Maxi]%(n-1),tt=0;
            r[Maxi]=0;
            for(int i=1;i<=n;i++)
            {
                if(i==Maxi) continue;
                if(tt!=kx)
                {
                    r[i]++;
                    tt++;
                }
                r[i]+=k;
            }
        }
    }
    return 0;
}