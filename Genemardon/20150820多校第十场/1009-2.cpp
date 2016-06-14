#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[100010],t[100010];
int main(int argc, char const *argv[])
{
	int n,sl,tl;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%s",s,t);
		//printf("%s\n%s\n", s,t);
		int sl = strlen(s),tl = strlen(t);
		int i, j;
		i = j = 0;
		while(i < sl && j < tl)
		{
			//printf("%d %d\n", i, j);
			if (s[i]==t[j])
			{
				if (j<tl-1 && t[j]==t[j+1] && s[i]!=s[i+1])
				{
					if(j == 0) break;
					j++;
				}
				else{ i++;j++; }
			}
			else j++;
		}
		if (i<sl)
		{
			printf("No\n");
			continue;
		}
		int len=1;
		for (int i=1;i<tl;i++)
			if (t[i]==t[i-1])
			{
				t[len]=t[i];
				len++;
			}
		i=j=0;
		while(i<sl && j<len)
		{
			if (s[i]==t[j])
			{
				if (t[j]==t[j+1] && s[i]==s[i+1])
				{
					i++;j++;
				}
				else i++;
			}
			else i++;
		}
		if (j<len)
			printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}