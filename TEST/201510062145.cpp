#include <iostream> 
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>
char a[500000+100];

using namespace std; 
int main()
{
	ifstream cin("9.in");
	ofstream cout("9.out");
	stack <char> b;
	int len;
	cin>>a;
	len =strlen(a);

	for(int i = 0 ;i < len; i ++)
	{
		if( a[i] == 'G')
		{
			cout<<b.size()<<endl;
		}
		if( a[i] == 'a')
			b.push(a[i]);
		else if(a[i] == 'A')
			b.pop();
	}
	return 0;
}