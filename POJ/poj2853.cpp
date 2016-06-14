#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n,c,m;
    while (cin>>n)
    {
        for (int i=1;i<=n;i++)
        {
            cin>>c>>m;
            int k=(int)sqrt((double)m),count=0;
            k*=2;
            for (int j=2;j<=k;j++)
                if(2*m%j==0&&m*2/j+1-j>0&&(m*2/j+1-j)%2==0)
                    count++;
            cout<<c<<" "<<count<<endl;
        }
    }
    return 0;
}

