#include <iostream>
#include <string.h>
using namespace std;
void transform(char *a,int *x)
{
	int n=strlen(a);
	for (int i=0;i<n;i++)
		x[i]=a[n-1-i]-'0';
}
int main()
{
	char a[11],b[11];
	int x[11],y[11];
	while (cin>>a>>b)
	{
		if (strcmp(a,"0")==0&&strcmp(b,"0")==0)
			break;
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		int count=0;
		int len_a=strlen(a);
		int len_b=strlen(b);
		transform(a,x);
		transform(b,y);
		int maxlen=len_a>len_b?len_a:len_b;
		int flag=0;
		for (int i=0;i<=maxlen;i++)
		{
			int kk;
			kk=x[i]+y[i]+flag;
			if (kk>=10)
				count++;
			flag=kk/10;
		}
		if (count==0)
			cout<<"No carry operation."<<endl;
		else
			cout<<count<<" carry operations."<<endl;
	}
	return 0;
} 
