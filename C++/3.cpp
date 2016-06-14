#include <iostream>
#include <fstream>
using namespace std;
#define MAX 1000
int main()
{
    ifstream cin("4.txt");
    int n,x[MAX];
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>x[i];
    int dex;
    for (int j=2;j<=n;j++)
    {
        x[0]=x[1];
        dex=1;
        if (x[0]>x[j])
        {
            x[0]=x[j];
            dex=j;
        }
    }
    int m,a,b;
    cin>>m;
    while (m-->0)
    {
        cin>>a>>b;
        x[a]+=b;
    }
    x[dex]=x[0];
    int temp=x[1],index=0;
    for (int s=2;s<=n;s++)
    {
        if (temp>x[s])
        {
            temp=x[s];
            index=s;
        }
    }
    cout<<index<<" "<<temp<<endl;
    return 0;
}
