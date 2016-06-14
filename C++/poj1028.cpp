#include <iostream>
using namespace std;
#include <string.h>
#include <stack>
#include <queue>

int main()
{
	string str,s1,s2;
	str="http://www.acm.org/";
	char b[15];
	queue<string> q;
	stack<string> s;
	s.push(str);
	while (cin>>b)
	{
		int flag=0;
		if (strcmp(b,"QUIT")==0)
			break;
		if (strcmp(b,"VISIT")==0)
		{
			flag=1;
			cin>>s1;
			s.push(s1);
			cout<<s1<<endl;
		}
		if (strcmp(b,"BACK")==0)
		{
			
			if (!s.empty())
			{
				if (flag==1)
				{
					cout<<"--"<<endl;
					s.pop();
					s.pop();
				}	
				q.push(s.top());
				cout<<s.top()<<endl;
				s.pop();
			}
			else
				cout<<"Ignored"<<endl;
		}
		if (strcmp(b,"FORWARD")==0)
		{
			if (!q.empty())
			{
				cout<<q.front()<<endl;
				q.pop();
			}
			else
				cout<<"Ignored"<<endl; 
		}
	}
	return 0;
}
