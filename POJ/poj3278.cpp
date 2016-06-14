#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int map[300010];
bool used[300010];
int flag=0;
struct point
{
	int value,step;
};
bool isvivld(int a)
{
	if (a>=0&&used[a]==false)
		return true;
	return false;
}
int bfs(point a,int b)
{
	int p;
	flag=0;
	queue<int> q;
	q.push(a.value);
	while (!q.empty())
	{
		p=q.front();
		used[p]=true;
		q.pop();
		for (int i=1;i<=3;i++)
		{
			int flagflag=0;
			if (p>=100000)
			{
				flagflag=1;
				i=1;
			}		
			int s;
			switch(i)
			{
				case 1:
					s=p-1;
					break;
				case 2:
					s=p+1;
					break;
				case 3:
					s=p*2;
					break;
			}
			if (isvivld(s)==true)
			{
				used[s]=true;
				q.push(s);
				if (s==b)
					return true;
			}
			if (flagflag==1)
				break;		
		}
	}
}
int main()
{
	int n,k;
	while (cin>>n>>k)
	{
		ffff=0;
		flag=0;
		memset(used,false,sizeof(used));
		if (n==k)
			cout<<0<<'\n'<<ffff<<endl;
		else	
			if (bfs(n,k)==true)
			{
				int i,j,count=0;
				for (i=flag-1;i>=0;i--)
					for (j=0;j<=i;j++)
						if ((map[i]==map[j]-1)||(map[i]==map[j]+1)||(map[i]==map[j]*2))
						{
							count++;
							i=j+1;
							break;
						}
				cout<<count<<endl;
				cout<<ffff<<endl;
			}	
	}
	return 0;
} 
