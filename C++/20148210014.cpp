#include <iostream>
#include <algorithm>
using namespace std;
#define M 1000000000 
#define N 100000
int sumdigit(long long a)
{
    int sum=0;
    while (a>0)
    {
        sum+=a%10;
        a/=10;
    }
    return sum;
}
long long pow(long long a,long long b)
{
    if (b==0)
        return 1;
    int mul=1;
    while (b)
    {
        mul*=a;
        b--;
    }
    return mul;
}
int main()
{
    long long a,b,c,num[N];
    while (cin>>a>>b>>c)
    {
        int count=0,k=0;
        for (long long s=0;s<82;s++)
        {
            long long x=b*pow(s,a)+c;
            if (sumdigit(x)==s&&x<M&&x>0)
            {
                count++;
                num[k++]=x;
            }
        }
        sort(num,num+k);
        cout<<count<<endl;
        if (count>0)
        {
            for (int i=0;i<k-1;i++)
                cout<<num[i]<<" ";
            cout<<num[k-1]<<endl;
        }
        
    }
    return 0;
} 
