#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int a[100010],sign[100010],pos[100010],post[100010],pre[100010],exist[100010];
inline void read(int &x){
    char c=0;
    for(;c<'0'||c>'9';c=getchar());
    for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
}
int main(int argc, char const *argv[])
{
	int t,cur;
	read(t);
	while (t--)
	{
		read(n);
		int MM=-1,PP;
		for (int i=1;i<=n;i++)
		{
			exist[i]=1;
			read(a[i]);
			if (MM<a[i])
			{
				MM=a[i];
				PP=i;
			}
			pre[a[i]]=PP;
			pos[a[i]]=i;
			post[i]=i;
			sign[i]=-1;
		}
		sign[n+1]=1;a[n+1]=-1;
		cur=n;
		for (int i=1;i<=n;i++) if (sign[pos[i]]==-1)
		{
			while (cur && !exist[cur]) cur--;
			//for (int j=1;j<=n;j++) printf("%d ",sign[j] );printf("\n");
			int MAX=i;
			int pp=pos[i];
			for (int j=pp-1;j>=pre[i];j--) if (sign[j]==1) break;
				else if (sign[j]==-1)
				{
					if (MAX<a[j])
					{
						MAX=a[j];
						pp=j;
					}
				}
				else if (sign[j]==0)
				{
					if (MAX<post[a[j]])
					{
						pp=j;
						MAX=post[a[j]];
						break;
					}
				}
			if (sign[pos[i]+1]!=1 && MAX<a[pos[i]+1])
			{
				post[a[pos[i]+1]]=i;
				post[i]=a[pos[i]+1];
				sign[pos[i]]=1;
				sign[pos[i]+1]=0;
			}
			else
			{
				post[i]=post[a[pp]];
				for (int j=pos[i];j>=pp;j--) sign[j]=1;
				for (int j=pos[i]-1;j>=pp;j--) post[a[j]]=a[j+1];
			}
		}
		else if (sign[pos[i]]==0)
		{
			if (i<a[pos[i]+1] && sign[pos[i]+1]==-1)
			{
				post[a[pos[i]+1]]=post[i];
				post[i]=a[pos[i]+1];
				sign[pos[i]]=1;
				sign[pos[i]+1]=0;
			}
		}
		printf("%d",post[1] );
		for (int i=2;i<=n;i++) printf(" %d", post[i]);
		printf("\n");
	}
	return 0;
}