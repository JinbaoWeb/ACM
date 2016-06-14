#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
struct point
{
    int h;
    int w;
    int g;
    int id;
}a[1000000];
int cmp(point x,point y)
{
    if(x.h == y.h)
    {
        if(x.w == y.w)
        {
            if(x.g == y.g)
                return x.id < y.id;
            return x.g > y.g;
        }
        return x.w < y.w;
    }
     return x.h > y.h;
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0 ; i< n; i++)
    {
        scanf("%d %d %d",&a[i].h,&a[i].w,&a[i].g);
        a[i].id = i+1;
    }
    sort(a,a+n,cmp);
    for(int i = 0 ; i< n; i++)
    {
        printf("%d\n",a[i].id);
    }
    return 0;
}
