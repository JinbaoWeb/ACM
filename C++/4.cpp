#include <iostream>
#include <fstream>
using namespace std;
#define M 1000
int lookfor(int a[],int n)  //找出数组中值最小的下标
{
    int temp=a[1],index=1;
    for (int i=1;i<=n;i++)
    {
        if (temp>a[i])
        {
            temp=a[i];
            index=i;
        }
    }
    return index;
}
int main()
{
    ifstream cin("4.txt");
    int n,x[M];
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>x[i];
    int min=lookfor(x,n);
    //cout<<min<<endl;
    int m;
    cin>>m;
    int a,b;
    while (m--)
    {
        cin>>a>>b;
        if (a==0)
            x[min]+=b;
        else
            x[a]+=b;
    }
    for (int t=1;t<=n;t++)
        cout<<x[t]<<'\t';
    cout<<endl;
    int ss=x[1],dd=1;
    for (int s=2;s<=n;s++)
    {
        if (ss>x[s])
        {
            ss=x[s];
            dd=s;
        }
    }
    cout<<ss<<" "<<dd<<endl;
    return 0;
}
