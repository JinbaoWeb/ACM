#include <iostream> 
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
char a[500000+100];

using namespace std; 
int main()
{
	stack <char> b;
	int len;
	cin>>a;
	len =strlen(a);

	for(int i = 0 ;i < len; i ++)
	{
		if( a[i] == 'G')
		{
			printf("%d\n",b.size());
		}
		if( a[i] == 'a')
			b.push(a[i]);
		else if(a[i] == 'A')
			b.pop();
	}
	return 0;
}