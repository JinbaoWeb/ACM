#include <iostream>
using namespace std;
#include <string.h>
#define M 106
int t;
int LCS(const char *s1, const char *s2)
{// s1:0...m, s2:0...n
	int m = strlen(s1), n = strlen(s2);
	int i, j,a[205][205];
	a[0][0] = 0;
	for( i=1; i <= m; ++i ) a[i][0] = 0;
	for( i=1; i <= n; ++i ) a[0][i] = 0;
	for( i=1; i <= m; ++i )
		for( j=1; j <= n; ++j ){
			if(s1[i-1]==s2[j-1]) a[i][j] = a[i-1][j-1]+1;
			else if(a[i-1][j]>a[i][j-1])a[i][j]= a[i-1][j];
			else a[i][j] = a[i][j-1];
		}
	return a[m][n];
}
int main()
{
	char s1[M][205],s2[M][205];
	cin>>t;
	for (int i=0;i<t;i++)
		cin>>s1[i]>>s2[i];
	int i;
	for (i=0;i<t;i++)
	{
		int m = strlen(s1[i]), n = strlen(s2[i]);
		int len=m>n?m:n;
		
		char s3[205];
		for (int j=0;j<m;j++)
			s3[j]=s3[m-1-j];
		s3[m]=0;
		if (LCS(s1[i],s2[i])>=len/2)
		{
			cout<<"I love you!"<<endl;
			break;
		}
		else
			cout<<"I hate you for "<<i+1<<" times!"<<endl;
	}
	cout<<"I hate you for "<<i+1<<" times!"<<endl;
}
