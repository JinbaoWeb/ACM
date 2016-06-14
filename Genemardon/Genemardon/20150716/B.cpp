#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int cnt,flag,n,m;
int dir[20]={2,3,4,5,5,5,6,6,6,7};
int num[20]={1,7,4,5,3,2,9,6,0,8};
char str[200],ans[200],save[200];
void dfs(int l,int re,int M)
{
	if (re/2+l-1<flag) return;
	for (int i=0;i<10;i++) if (re>=dir[i])
	{
		if (i==8 && re==n) continue;
		str[l-1]=('0'+num[i]);
		dfs(l+1,re-dir[i],(M*10+num[i])%m);
		// if (flag)
		// 	{ 

		// 		//printf("%d",num[i] );
		// 		save[l]=num[i];
		// 		return;
		// 	}
	}
	else break;
	str[l-1]=0;
	//printf("%s\n",str );
	if (M==0 && l>flag)
	{
		flag=l-1;
		for (int i=0;i<l-1;i++) save[i+1]=str[i]-'0';
	}
}
int main(int argc, char const *argv[])
{
	int t=0;
	while (scanf("%d",&n) && n)
	{
		scanf("%d",&m);
		t++;
		flag=0;
		dfs(1,n,0);
		printf("Case %d: ",t );
		if (flag)
			{
				for (int i=1;i<=flag;i++) printf("%d",save[i] );
					printf("\n");
			}
		else printf("-1\n");
	}
	return 0;
}