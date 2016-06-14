#include <iostream>
#include <stack>
#define MAXN 1010
using namespace std;
int main()
{
	int n,target[MAXN];
	while(cin>>n)
	{
		stack<int> s;
		int a=1,b=1;
		for(int i=1;i<=n;i++)
		{
			cin>>target[i];
		}
		int ok=1;
		while(b<=n)
		{
			if(a==target[b]) a++,b++;
			else if(!s.empty()&&s.top()==target[b]) s.pop(),b++;
			else if(a<=n) s.push(a++);
			else 
			{
			ok=0;
			break;
		    }
		}
		if(ok) cout<<"Yes\n";
		else cout<<"No\n"; 
	}
	return 0;
}
