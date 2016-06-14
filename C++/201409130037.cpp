#include <iostream>
using namespace std;
#define M 50005
int main()
{
    int n,a;
    long long sum[M];
    while (cin>>n&&n>0)
    {
        long long sum1=0;
        for (int i=0;i<n;i++)
        {
            cin>>a;
            sum1+=a;
            sum[i]=sum1;
        }
        if (sum1%3)
        {
            cout<<0<<endl;
            continue;
        }
        long long num1=0,num2=0,num3=0;
        long long s=sum1/3,count=0;
        for (int i=0;i<n-2;i++)
        {
            if (sum[i]==s)
            {
            	int flag=0;
                for (int j=i+1;j<n-1;j++)
                {
                    if (sum[j]==sum[i]+s)
                        count++;
                    if (sum[j]==s&&flag==0&&j<n-2)
                    {
                    	flag=1;
                    	i=j;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
