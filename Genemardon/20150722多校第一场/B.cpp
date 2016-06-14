#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int a[100010];
int k,m1,m2,p1,p2,last;
int n;
inline void read(int &x){
    char c=0;
    for(;c<'0'||c>'9';c=getchar());
    for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
}
struct node
{
	int x,num;
	bool operator<(const node &a)const
	{
		return num>a.num;
	}
};
priority_queue<node>q1;
int main(int argc, char const *argv[])
{
	int t;
	long long ans=0;
	scanf("%d",&t);
	while (t--) //m1=MIN m2=MAX
	{
		scanf("%d%d",&n,&k);
		ans=0;
		for (int i=1;i<=n;i++) read(a[i]);
		m1=a[1];m2=a[1];p1=1;p2=1;last=1;
		for (int i=2;i<=n;i++) if (a[i]>=m1+k)
		{
			int pos=p1;
			for (int j=p1+1;j<=i;j++)if (a[j]<=a[i]-k)
				pos=j;
			long long
			ans=ans+(pos-last+1)*(pos-last+2)/2+(pos-last+1)*(i-pos-1);
			last=pos+1;m2=a[i];p2=i;
			m1=a[i];p1=i;
			for (int j=last;j<=i;j++) if (a[j]<=m1)
			{
				m1=a[j];
				p1=j;
			}
		}
		else if (a[i]<=m2-k)
		{
			int pos=p2;
			for (int j=p2+1;j<=i;j++) if (a[j]>=a[i]+k)
				pos=j;
			ans=ans+(pos-last+1)*(pos-last+2)/2+(pos-last+1)*(i-pos-1);
			last=pos+1;m1=a[i];p1=i;
			m2=a[i];p2=i;
			for (int j=last;j<=i;j++) if (a[j]>=m2)
			{
				m2=a[j];
				p2=j;
			}
		}
		else if (a[i]==m1) p1=i;
		else if (a[i]==m2) p2=i;
		else if (a[i]<m1)
		{
			m1=a[i];p1=i;
		}
		else if (a[i]>m2)
		{
			m2=a[i];p2=i;
		}
		ans=ans+(n-last+1)*(n-last+2)/2;
		printf("%d\n",ans );
	}
	return 0;
}