#include <iostream>
#include <string.h>
using namespace std;
#define M 100000
int aa[26],bb[26];
bool f(char *a,char *b)
{
	memset(aa,0,sizeof(aa));
	memset(bb,0,sizeof(bb));
	int s=strlen(a),flag=2;
	for (int i=0;i<s;i++)
	{
		aa[a[i]-'a']+=1;
		bb[b[i]-'a']+=1;
	}
	for (int i=0;i<26;i++)
	{
		if (aa[i]>=1&&bb[i]>=1)
			flag+=(aa[i]>bb[i]?bb[i]:aa[i]);	
	}	
	cout<<flag<<"--"<<endl;
	if (flag>=s)
		return true;
	return false;
}
int main()
{
	int t,len_a,len_b;
	char a[M],b[M],c[M];
	cin>>t;
	for (int cc=1;cc<=t;cc++)
	{
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		cin>>a>>b;
		len_a=strlen(a);
		len_b=strlen(b);
		int s=len_a-len_b,index=-1;
		for (int i=0;i<=s;i++)
		{
			int j;
			for (j=i;j<len_b+i;j++)
				c[j-i]=a[j];
			c[j-i]=0;
			cout<<"-----"<<c<<"-----"<<endl;
			if (f(b,c)==true)
				index=i;
		}
		cout<<index<<endl;
	}
	return 0;
}
