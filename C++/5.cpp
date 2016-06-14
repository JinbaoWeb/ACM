#include <iostream>
using namespace std;
int f1(int n)
{
    if (n<2)
        return n;
    return f1(n-1)+f1(n-2);
}
int f2(int n)
{
    C:
    int sum=0;
    while (n>0)
    {
        sum+=sum%10;
        n/=10;
    }
    if (sum>10)
    {
        n=sum;
        goto C;
    }
    else
        return sum;
}
int main()
{
    int n,t;
    cin>>t;
    while (cin>>n)
    {
        cout<<f1(f2(n))<<endl;
    }
    return 0;
}
