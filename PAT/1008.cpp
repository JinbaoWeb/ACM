#include <iostream>
using namespace std;
int f(char A,char B)
{
	if (A==B) return 0;
	if (A=='J' && B=='B') return 1;
	if (A=='B' && B=='C') return 1;
	if (A=='C' && B=='J') return 1;
	return -1;
}
int main()
{
	int n;
	char x,y;

	while (cin>>n)
	{
		int x_J=0,x_B=0,x_C=0,y_J=0,y_B=0,y_C=0;
		int a=0,b=0,c=0;
		while (n--)
		{
			cin>>x>>y;
			if (f(x,y)==1)
			{
				a++;
				if (x=='J') x_J++;
				if (x=='B') x_B++;
				if (x=='C') x_C++;
			}
			else if (f(x,y)==-1)
			{
				c++;
				if (y=='J') y_J++;
				if (y=='B') y_B++;
				if (y=='C') y_C++;
			}
			else b++;
		}
		cout<<a<<" "<<b<<" "<<c<<endl;
		cout<<c<<" "<<b<<" "<<a<<endl;
		//cout<<x_J<<" "<<x_B<<" "<<x_C<<endl;
		//cout<<y_J<<" "<<y_B<<" "<<y_C<<endl;
		char ans_x,ans_y;
		if (x_J>x_B && x_J>x_C) ans_x='J';
		if (x_B>=x_J && x_B>=x_C) ans_x='B';
		if (x_C>=x_J && x_C>x_B) ans_x='C';
		if (y_J>y_B && y_J>y_C) ans_y='J';
		if (y_B>=y_J && y_B>=y_C) ans_y='B';
		if (y_C>=y_J && y_C>y_B) ans_y='C';		
		cout<<ans_x<<" "<<ans_y<<endl;
	}
}