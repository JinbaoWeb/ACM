#include <iostream>
using namespace std;
string str;
int a[200000],b[200000];
#define MOD 1000000007
int main()
{
	cin>>str;
	if (str[0]=='P') a[0]=1;
	else a[0]=0;
	for (int i=1;i<str.size();i++)
	{
		if (str[i]=='P') a[i]=a[i-1]+1;
		else a[i]=a[i-1];
	}
	if (str[str.size()-1]=='T') b[str.size()-1]=1;
	else b[str.size()-1]=0;
	for (int i=str.size()-2;i>=0;i--)
	{
		if (str[i]=='T') b[i]=b[i+1]+1;
		else b[i]=b[i+1];
	}
	long long ans=0;
	for (int i=1;i<str.size();i++)
	{
		if (str[i]=='A')
		{
			ans=(ans+1LL*a[i]*b[i])%MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}