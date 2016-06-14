#include <iostream>
using namespace std;
#define M 100005
int sub(char *a,int n)
{
	int m;
	m=0;
	for(int i=0;a[i]!='\0';i++)
		m=((m*10)%n+(a[i]-'0')%n)%n;
	return m;
}
int main()
{
	char a[M];
	while (cin>>a)
	{
		if (sub(a,4)==0)
			cout<<"4"<<endl;
		else
			cout<<"0"<<endl;
	}
	return 0;
}
