#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
bool isprime(int x)
{
	if (x<2) return false;
	if (x==3 || x==2 || x==7 || x==5)
		return true;
	for (int i=2;i*i<=x;i++)
		if (x%i==0)
			return false;
	return true;
}
bool f(int i,int j)
{
	if (i==0&&j!=0)
	{
		if (j<0) j=(-j);
		if (j%4==3 && isprime(j)==true)
			return true;
		return false;
	}
	else if (i!=0&&j==0)
	{
		if (i<0) i=(-i);
		if (i%4==3 && isprime(i)==true)
			return true;
		return false;
	}
	else
	{
		if (i!=0 && j!=0)
		{
			if (isprime(i*i+j*j)==true)
				return true;
			return false;
		}
		return false;
	}
}
int main()
{
	int t,x1,x2,y1,y2;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
		int k=0,ans=0;
		for (int i=x1;i<=x2;i++)
		{
			for (int j=y1;j<=y2;j++)
			{
				k++;
				if (f(i,j)==true)
					ans++;
			}
		}
		int cnt=gcd(k,ans);
		k/=cnt;
		ans/=cnt;
		cout<<ans<<"/"<<k<<endl;
	}
	return 0;
}