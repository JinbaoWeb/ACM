#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
	int u,v,fix;
	node () {}
	node (int u,int v,int fix) :u(u),v(v),fix(fix) {}
};
int n,com,cp,cn,ave,flag,cnt;
int a[1000010];
int list[1000010],ocu[1000010],pre[1000010],dir[1000010],to[1000010],two[1000010],command[1000010][2];
long long ABS(long long x)
{
	if (x>0) return x;
	else return -x;
}
bool findright(int p)
{
	int pos=p+1;
	if (pos==cnt) pos=0;
	if  (a[list[pos]]<ave && !ocu[pos])
	{
		ocu[pos]=1;
		pre[pos]=p;
		dir[pos]=1;
		return true;
	}
	return false;
}
bool findleft(int p)
{
	int pos=p-1;
	if (pos<0) pos=cnt-1;
	if (a[list[pos]]<ave && !ocu[pos])
	{
		pre[pos]=p;
		ocu[pos]=1;
		dir[pos]=-1;
		return true;
	}
	else if (a[list[pos]]<ave)
	{
		if (a[list[pre[pos]]]-ave==2) return false;
		int tmp=pre[pos];
		pre[pos]=p;
		dir[pos]=-1;
		return findleft(tmp);
	}
	return false;
}
void add(int st,int end,int dir)
{
	int p1=st,p2=st+dir;
	if (p2>n) p2=1;
	if (p2==0) p2=n;
	while (p1!=end)
	{
		command[cn][0]=p1;command[cn][1]=p2;
		cn++;
		p1=p2;
		p2+=dir;if (p2>n) p2=1;
		if (p2==0) p2=n;
	}
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		long long sum=0;com=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if (n==1)
		{
			printf("YES\n");
			printf("0\n");
			continue;
		}
		if (sum%n!=0)
		{
			printf("NO\n");
			continue;
		}
		ave=int(sum/n);
		flag=1;
		for (int i=1;i<=n;i++) if (ABS(ave-a[i])>2)
		{
			flag=0;break;
		}
		if (flag==0)
		{
			printf("NO\n");
			continue;
		}
		cnt=0;
		for (int i=1;i<=n;i++) if (a[i]!=ave)
		{
			list[cnt]=i;
			cnt++;
			if (a[i]==ave-2)
			{
				list[cnt]=i;
				cnt++;
			}
		}
		if (cnt==1)
		{
			printf("NO\n");
			continue;
		}
		memset(ocu,0,sizeof(ocu));
		for (int i=0;i<cnt;i++) if (a[list[i]]>ave)
		{
			if (a[list[i]]==ave+1)
			{
				if (!findright(i) && !findleft(i))
				{
					flag=0;
					break;
				}
			}
			else
				if (!findright(i) || !findleft(i))
				{
					flag=0;
					break;
				}
		}
		cn=0;
		if (flag==0)
		{
			printf("NO\n");
			continue;
		}
		for (int i=0;i<cnt;i++) if (ocu[i])
		{
			add(list[pre[i]],list[i],dir[i]);
		}
		printf("YES\n");
		printf("%d\n",cn );
		for (int i=0;i<cn;i++) printf("%d %d\n",command[i][0],command[i][1] );
	}
	return 0;
}