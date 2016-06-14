#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
	int head, end;
	__int64 len;
	void pr(){
		printf("%d %d %d\n", head, end, len);
	}
}p, q;
int a[100005];
void clear()
{
	p.len = p.end = p.head = 1;
	q.len = q.end = q.head = 1;
}
int main()
{
	int n, d1, d2;
	while(~scanf("%d%d%d", &n, &d1, &d2))
	{
		clear();
		__int64 ans = n;
		scanf("%d", &a[1]);
		for(int i = 2;i <= n;i++)
		{
			scanf("%d", &a[i]);
			if(a[i]-a[i-1] == d1)
			{
				if(p.end == i-1)
				{
					p.end = i;
					p.len++;
				}
				else
				{
					if(q.head == p.end)
						ans += (p.len-1)*(q.len-1);
					ans += (p.len-1)*p.len/2;
					p.end = i;
					p.len = 2;
				}
			}
			else if(a[i]-a[i-1] == d2)
			{
				if(q.end == i-1)
				{
					q.end = i;
					q.len++;
				}
				else
				{
					if(q.head == p.end)
						ans += (p.len-1)*(q.len-1);
					ans += (q.len-1)*q.len/2;
					q.end = i;
					q.head = i-1;
					q.len = 2;
				}
			}
			//p.pr();
			//q.pr();
			//printf("%I64d\n", ans);

		}
		ans += (p.len-1)*p.len/2;
		//printf("%I64d\n", ans);

		ans += (q.len-1)*q.len/2;
		//printf("%I64d\n", ans);

		if(q.head == p.end)
			ans += (p.len-1)*(q.len-1);
		printf("%I64d\n", ans);

	}
	return 0;
}