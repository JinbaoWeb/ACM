#include"iostream"
#include"cstdio"
#include"cstring"
#include"queue"
#include"algorithm"
using namespace std;
const int ms=1e5+5;
struct node
{
	int a,b;
}a[ms];
bool cmp(const node &a1,const node &a2)
{
	return a1.a<a2.a;
}
int n,l,p;
void input()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].a,&a[i].b);
	}
	scanf("%d%d",&l,&p);
	for(int i=0;i<n;i++)
		a[i].a=l-a[i].a;
	a[n].a=l;
	a[n].b=0;
	n++;
	sort(a,a+n,cmp);
}
void solve()
{
	int i,d,pos=0,tank=p,ans=0;
	priority_queue<int> q;
	for(i=0;i<n;i++)
	{
		d=a[i].a-pos;
		while(tank<d)
		{
			if(q.empty())
			{
				puts("-1");
				return ;
			}
			tank+=q.top();
			q.pop();
			ans++;
		}
		tank-=d;
		pos=a[i].a;
		q.push(a[i].b);
	}
	cout<<ans<<endl;
	return ;
}
int main()
{
	input();
	solve();
	return 0;
}
