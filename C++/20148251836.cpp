#include <iostream>
using namespace std;
int f(int m,int n)
{
    if (n==1||m==0||m==1)
        return 1;
    if (m<n)
        n=m;
    return f(m,n-1)+f(m-n,n);
}
int main()
{
    int n;
    while (cin>>n)
        cout<<f(n,n)-1<<endl;
    return 0;
}
