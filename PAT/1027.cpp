#include <iostream>
using namespace std;
int main()
{
	long long a,b,c,P,A,B;
	char s;
	cin>>a>>s>>b>>s>>c;
	P=a*29*17+b*29+c;
	cin>>a>>s>>b>>s>>c;
	A=a*29*17+b*29+c;
	if (A>P)
		B=A-P;
	else
	{
		B=P-A;
		cout<<"-";
	}
	cout<<B/(17*29)<<".";
	B%=(17*29);
	cout<<B/29<<".";
	B%=29;
	cout<<B<<endl;
	return 0;
}