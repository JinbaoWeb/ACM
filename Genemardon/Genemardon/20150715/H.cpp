#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int ex[520010][2],put[40010];
char str[5];
int x;
int main(int argc, char const *argv[])
{
	//freopen("in", "r", stdin);
	int t,TT=0,tail=0;
	while (scanf("%d",&t) && t)
	{
		TT++;tail=0;
		if (TT>1) printf("\n");
		printf("Case %d: \n",TT );
		memset(ex,-1,sizeof(ex));
		for (int j=1;j<=t;j++)
		{
			scanf("%s%d",str,&x);
			if (str[0]=='A')
			{
				if (tail==0)
				{
					printf("-1\n");
					continue;
				}
				if (ex[x][0]!=-1)
				{
					int M=ex[x][1],pos=ex[x][0];
					for (int i=ex[x][0]+1;i<=tail;i++) if (M>=(put[i]%x))
					{
						pos=i;
						M=put[i]%x;
						ex[x][0]=i;
						ex[x][1]=put[i];
					}
					printf("%d\n",pos );
				}
				else
				{
					int M=x,pos;
					for (int i=tail;i>0;i--) if (M>(put[i]%x))
					{
						pos=i;
						M=put[i]%x;
						ex[x][0]=i;
						ex[x][1]=put[i];
					}
					printf("%d\n",pos );
				}
			}
			else
			{
				tail++;
				put[tail]=x;
			}
		}
	}
	return 0;
}