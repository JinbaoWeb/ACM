#include <iostream>
#include <string.h>
using namespace std;
void add(char *a)
{
	int len=strlen(a);
	for (int i=len;i>=0;i--)
		a[i+1]=a[i];
	a[0]='0';
	len=strlen(a);
	int b[105];
	for (int i=0;i<len;i++)
		b[i]=a[i]-'0';
	b[len-1]++;
	int set=0;
	for (int i=len-1;i>=0;i--)
	{
		b[i]+=set;
		set=b[i]/10;
		b[i]%=10;
		a[i]=b[i]+'0';
	}
	if (a[0]=='0')
		for (int i=1;i<=len;i++)
			a[i-1]=a[i];
}
int g(char *a)
{
	int len=strlen(a);
	int sum=0;
	for (int i=0;i<len;i++)
	{
		if (i%2==0)
			sum+=a[i]-'0';
		else
			sum-=a[i]-'0';
	}
	return sum;
}
int f(int a)
{
	int answer;
	if (a<0)
	{
		a=a%9;
		a+=9;
		answer=a;
	}
	else
	{
		int sum=0;
		while (a>0)
		{
			sum+=a%10;
			a/=10;
		}
		answer=sum;
	}
	if (answer>=0&&answer<=9)
		return answer;
	else
		f(answer);
	
}
int main()
{
	int t;
	char a[105],b[108];
	cin>>t;
	for (int c=1;c<=t;c++)
	{
		cin>>a>>b;
		int result=0;
		while (strcmp(a,b)!=0)
		{
			add(a);
			result+=g(a);
		}
		if (result==0)
			cout<<"Error!"<<endl;
		else
			cout<<result%f(result)<<endl;
	}
	return 0;
}
