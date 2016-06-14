#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int cnum[1010];
int MAX[200];
char str[1010][200][85],ss[200];
int len,cnt,head,tail;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d\n",&t);
	while (t--)
	{
		cnt=0;
		memset(MAX,0,sizeof(MAX));
		memset(cnum,0,sizeof(cnum));
		while (1)
		{
			gets(ss);
			if (strcmp(ss,"@")==0) break;
			cnt++;
			len=strlen(ss);cnum[cnt]=0;head=0;
			while (1)
			{
				while (head<len && ss[head]==' ') head++;
				if (head>=len) break;
				tail=head;
				while (tail<len && ss[tail]!=' ') tail++;
				cnum[cnt]++;
				for (int i=head;i<tail;i++) str[cnt][cnum[cnt]][i-head]=ss[i];
				MAX[cnum[cnt]]=max(MAX[cnum[cnt]],tail-head);
				str[cnt][cnum[cnt]][tail-head]=0;
				head=tail+1;
			}
		}
		for (int i=1;i<=cnt;i++)
		{
			for (int j=1;j<cnum[i];j++)
			{
				printf("%s",str[i][j] );
				int d=MAX[j]-strlen(str[i][j]);
				for (int j=0;j<=d;j++) printf(" ");
			}
		 	printf("%s\n",str[i][cnum[i]] );
		}
	}
	return 0;
}