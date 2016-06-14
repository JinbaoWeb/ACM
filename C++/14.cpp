#include <iostream>
using namespace std;
int n,m,x[10000];
int f(int m,int n)
{
    if (m<=n)
        return x[m];
    return f(m-n-1,n)+f(m-n+1,n);
}
int main()
{
    while (cin>>n>>m)
    {
        x[0]=0;
        for (int i=1;i<=n;i++)
            cin>>x[i];
        cout<<f(m,n)<<endl;
    }
    return 0;
}
