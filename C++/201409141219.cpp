#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
using namespace std;
int main()
{
	char s[100];
	char a[]={"Apple"};
	char b[]={"iPhone"};
	char c[]={"iPod"};
	char d[]={"iPad"};
	char e[]={"Sony"}
	while (cin>>s)
	{
		int len=strlen(s);
		for (int i=0;i<len;i++)
		{
			if (s[i]=='A')
			{
				int k=1,flag=0;
				for (int j=i+1;k<5;k++,j++)
					if (s[j]!=a[k])
					{
						flag=1;
						break;
					}
				if (flag=0)
				{
					cout<<"MAI MAI MAI!"<<endl;
					i=i+k-1;
				}		
			}
			if (s[i]=='i')
			{
				int k=1,flag=0;
				for (int j=i+1;k<6;j++,k++)
					if (s[j]!=b[k])
					{
						flag=1;
						break;
					}
				if (flag==0)
				{
					cout<<"MAI MAI MAI!"<<endl;
					i=i+k-1;
				}
			}
			if (s[i]=='i')
			{
				int k=1,flag=0;
				for (int j=i+1;k<4;j++,k++)
					if (s[j]!=c[k])
					{
						flag=1;
						break;
					}
				if (flag==0)
				{
					cout<<"MAI MAI MAI!"<<endl;
					i=i+k-1;
				}
			}
			if (s[i]=='i')
			{
				int k=1,flag=0;
				for (int j=i+1;k<4;j++,k++)
					if (s[j]!=d[k])
					{
						flag=1;
						break;
					}
				if (flag==0)
				{
					cout<<"MAI MAI MAI!"<<endl;
					i=i+k-1;
				}
			}
			if (s[i]=='S')
			{
				int k=1,flag=0;
				for (int j=i+1;k<4;j++,k++)
					if (s[j]!=e[k])
					{
						flag=1;
						break;
					}
				if (flag==0)
				{
					cout<<"SONY DAFA IS GOOD!"<<endl;
					i=i+k-1;
				}
			}
		}
	} 
	return 0;
} 
