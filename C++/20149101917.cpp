#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 100000
using namespace std;
int main()
{
	int t,n;
	char s[10];
	scanf("d",&t);
	//cin>>t;
	while (scanf("%d",&n)!=EOF)//cin>>n
	{
		//cin>>s;
		scanf("%s",&s);
		sort(s,s+n);
		int k=0;
		while (next_permutation(s,s+n))
			printf("%s\n",s);
		//	cout<<s<<endl;
	}
	return 0;
}
