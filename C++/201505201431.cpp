#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define N 1001000
typedef long long ll;
#define mod 1000000007

int b[N],p[N],a[N],d[N];
int t;

ll Pow(ll a,int b)
{
  ll c=1;
  for (int i=1;i<=b;i++)
  c*=a;
  return c;
}

void prim()
{
     for (int i=2;i<N;i++)
     if (b[i]==0)
     for (int j=i+i;j<N;j+=i)
     b[j]=1;

     for (int i=2;i<N;i++)
     if (b[i]==0) p[++t]=i;
}

int main()
{
   int n;
   int T;
   scanf("%d",&T);
   prim();

   while (T--)
   {
     scanf("%d",&n);
     ll ans=1;

     for (int i=1;i<=t&&p[i]<=n;i++)
     {
        int tmp=log(n)/log(p[i]);
        int c=1;
        for (int j=tmp;j<=tmp+2;j++)
        { c*=p[i];
            if(c>n)
            {
                a[i]=j-1;
                break;
            }
        }
     }

     for (int i=1;i<=t&&p[i]<=n;i++)
     {
         while (n%p[i]==0)
         {
           n/=p[i];
           a[i]--;
         }
     }

     for (int i=1;i<=t;i++)
     for (int j=1;j<=a[i];j++)
     ans=ans*p[i]%mod;

     printf("%lld\n",ans);
   }
   return 0;

}