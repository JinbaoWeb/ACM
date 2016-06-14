#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5002;
struct Node
{
	int v,d,p;
	int fg;
}s[MAXN];

int ans[MAXN],cnt;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].v>>s[i].d>>s[i].p;
		s[i].fg=1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(s[i].fg!=-1)
	{
		ans[cnt++]=i;
		int sum=0,temp=s[i].v;
		for(int j=i+1;j<=n;j++) if(s[j].fg!=-1)
		{
			s[j].p-=sum;
			if(temp>0)
			{
				s[j].p-=temp;
				temp--;
			}			
			if(s[j].p<0)
			{
				sum+=s[j].d;
				s[j].fg=-1;
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++)
		cout<<ans[i]<<" ";
	cout<<endl;;
	return 0;
}