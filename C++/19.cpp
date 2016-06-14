/*#include <iostream>
using namespace std;
int main()
{
    float c;
    while (cin>>c&&c)
    {
        int i=2;
        float sum=0;
        while (sum<c)
        {
            sum+=1.00/i;
            i++;
        }
        cout<<i-2<<" card(s)"<<endl;
    }
    return 0;
}*/
#include <stdio.h>
#include <cmath>
int main()
{
	int a[32],count,n;
	for (int j=0;j<32;j++)
		a[j]=pow(3,j);
	while (scanf("%d",&n))
	{
		count=0;
		while (n)
		{
			for (int i=0;i<32;i++)
				if (a[i]<=n&&a[i+1]>n)
				{
					n-=a[i];
					count++;
				}
		}
		printf("%d\n",&count);
	}
	return 0;
}
