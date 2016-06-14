#include <iostream>
using namespace std;
#define M 100
void f(int *a)
{
    a[0]=0;
    int i=1,mul=1;
    for (;i<M;i++)
    {
       while (i>0)
       {
           int s=i%10;
           mul*=s;
           i/=10;
       }
       a[i]=mul;
    }
}
int main()
{
    int x[M];
    f(x);
    int n;
    while (cin>>n)
    {
        for (int j=1;;j++)
            if (n==x[j])
                cout<<j<<endl;
            else
                cout<<-1<<endl;
    }
    return 0;
}
