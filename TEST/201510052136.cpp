#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;
int main()
{
	ifstream cin("0.in");
	ofstream cout("0.out");
	string a;
	cin>>a;
	int len = a.length();
	bool pd = 0;//ÅÐ¶¨ÊÇ·ñÑ¡¶¨ÑÕÉ«
	bool player = 0;// 0 ÎªA»÷Çò
	int aa = 0;
	int bb = 0;
	char cl;//a»÷µÄÇòÉ«0ÎªÈ«É«
	for(int i = 0 ; i < len; i++)
	{
		if(pd == 0)
		{
			if(a[i] == 'b')
			{
				if(player == 0)
				{
					cout<<"B"<<endl;
					break;
				}
				else
				{
					cout<<"A"<<endl;
					break;
				}
			}
			else if(a[i] == 'a')
			{
				pd = 1;
				if(player == 0)
				{
					cl = 'a';
					aa = 1;
					continue;
				}
				else
				{
					cl = 'h';
					bb = 1;
					continue;
				}
			}
			else if(a[i] == 'h')
			{
				pd = 1;
				if(player == 0)
				{
					cl = 'h';
					aa = 1;
					continue;
				}
				else
				{
					cl = 'a';
					bb = 1;
					continue;
				}
			}
			else
			{
				player = !player;
				continue;
			}
		}
		else
		{
			if(a[i] == 'n' || a[i] == 'w')
			{
				player = !player;
				continue;
			}
			else if (a[i] == 'b')
			{
				if(player == 0)	
				{
					if(aa == 7)
					{
						cout<<"A"<<endl;
						break;
					}
					else
					{
						cout<<"B"<<endl;
						break;
					}
				}
				else
				{
					if(bb == 7)
					{
						cout<<"B"<<endl;
						break;
					}
					else
					{
						cout<<"A"<<endl;
						break;
					}
				}
			}
			else if(a[i] == 'a')
			{
				if(player == 0)
				{
					if(cl == 'a')
					{
						aa++;
						continue;
					}
					else
					{
						bb++;
						player = !player;
						continue;
					}
				}
				else
				{
					if(cl == 'a')
					{
						aa++;
						player = !player;
						continue;
					}
					else
					{
						bb++;
						continue;
					}
				}
			}
			else if(a[i] == 'h')
			{
				if(player == 0)
				{
					if(cl == 'h')
					{
						aa++;
						continue;
					}
					else
					{
						bb++;
						player = !player;
						continue;
					}
				}
				else
				{
					if(cl == 'h')
					{
						aa++;
						player = !player;
						continue;
					}
					else
					{
						bb++;
						continue;
					}
				}
			}	
		}	
	}
	return 0;
}