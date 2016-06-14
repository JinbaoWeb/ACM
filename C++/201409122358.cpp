#include <iostream>
using namespace std;
int main()
{
    long long n,a,b;
    while (cin>>n>>a>>b)
    {
        if (6*n<=a*b)
        {
            cout<<a*b<<endl;
            cout<<a<<" "<<b<<endl;
        }
        else
        {
            long long small=1e18,x1=0,y1=0;
            n=6*n;
            for (long long i=a;i<=n;i++)
            {
            	long long j=n/i;
            	if (n%i!=0)
            		j++;
            	if (small>i*j)
            	{
            		small=i*j;
            		x1=i;
            		y1=j;
            	}	
            }
            cout<<small<<endl;
            cout<<x1<<" "<<y1<<endl;
        }
    }
    return 0;
}
