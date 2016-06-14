#include <iostream>
#include <string.h> 
using namespace std;
bool sub(char *a,char *b)
{
	int len_a=strlen(a),len_b=strlen(b);
	if (len_a<len_b)
		return false;
	int i,j=0;
	for (i=0;i<len_a;i++)
		if (b[j]==a[i])
		{
			j++;
		}	
	if (j==len_b)
		return true;
	else
		return false; 
}
int main()
{
	char a[110],b[110],c[110];
	int t;
	cin>>t;
	while (cin>>a>>b)
	{
		int s_b=strlen(b);
		int k=0;
		for (k=0;k<s_b;k++)
			c[k]=b[s_b-1-k];
		c[k]=0;
		if (sub(a,b)==true || sub(a,c)==true)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
