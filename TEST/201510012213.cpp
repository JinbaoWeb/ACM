#include <iostream>
#include <cstdio>
#include <cstring> 
#include <fstream>
#define N1 20010
#define N2 100010
using namespace std;

int n,a[N1],MAX;
int C[N2];
int S1[N1],S2[N1];		

int lowbit(int x)
{
	return x&(-x);
}

int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=C[x];
		x-=lowbit(x);
	}
	return ans;
}

void update(int x,int d)
{
	while(x<=MAX)
	{
		C[x]+=d;
		x+=lowbit(x);
	}
}

int main()
{
	ifstream cin("0.in");
	ofstream cout("0.out");
	int t;
	cin>>t;
	while(t--)
	{
		cin >> n;
		MAX = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			MAX=a[i]>MAX?a[i]:MAX;
		}
		memset(C,0,sizeof(C));
		for(int i=1;i<=n;i++)
		{
			update(a[i],1);
			S1[i]=sum(a[i]-1);
		}
		memset(C,0,sizeof(C));
		for(int i=n;i>=1;i--)
		{
			update(a[i],1);
			S2[i]=sum(a[i]-1);
		}
		long long ans = 0;
		for(int i=1;i<=n;i++)
			ans+=S1[i]*(n-i-S2[i])+(i-1-S1[i])*S2[i];
		cout<<ans<<endl;
	}
	return 0;
}
