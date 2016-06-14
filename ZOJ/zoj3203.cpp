#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    double H,h,D;
    cin>>T;
    while(T--)
    {
        cin>>H>>h>>D;
        double temp=sqrt((H-h)*D);
        double temp2=(H-h)*D/H;
        double ans=0;
        if(temp>=D)
            ans=h;
        else if(temp<temp2)
            ans=h*D/H;
        else
            ans=D+H-temp-(H-h)*D/temp;
        printf("%.3lf\n",ans);
    }
    return 0;
}