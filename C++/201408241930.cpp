#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,k;
    while (cin>>n>>k)
    {
        if (k*(k+1)<=2*n)
        {
            int s=sqrt(n),flag=0;
            while (s)
            {
                if (k*(k-1)<=(n-s*s)*2)
                {
                    cout<<"YES"<<endl;
                    flag=1;
                    break;
                }
                s--;
            }
            if (flag==0)
                cout<<"NO"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
