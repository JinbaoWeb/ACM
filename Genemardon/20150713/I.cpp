#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
struct node
{
	char name[20];
	int fa,ninfo;
	vector<int>info;
};
std::map<string, int> MM;
node man[100010];
int n,cnt,m;
char str[10],nn[20];
int num[11];
int find(int x)
{
	if (man[x].fa!=x)
		man[x].fa=find(man[x].fa);
	return man[x].fa;
}
// void debug()
// {
// 	for (int i=1;i<=cnt;i++)
// 	{
// 		printf("------------\n");
// 		printf("%s\n",man[i].name );
// 		printf("%d %d\n",man[i].fa,man[i].ninfo );
// 		for (int j=0;j<)
// 	}
// }
void merge(int x,int y)
{
	int save[1010];
	int l=man[x].ninfo,r=man[y].ninfo;
	int i=0,j=0,len=0;
	while (i<l && j<r)
	{
		if (man[x].info[i]==man[y].info[j]) j++;
		else if (man[x].info[i]<man[y].info[j])
		{
			len++;
			save[len]=man[x].info[i];
			i++;
		}
		else
		{
			len++;
			save[len]=man[y].info[j];
			j++;
		}
	}
	while (i<l)
	{
		len++;
		save[len]=man[x].info[i];
		i++;
	}
	while (j<r)
	{
		len++;
		save[len]=man[y].info[j];
		j++;
	}
	man[y].info.clear();
	for (int k=1;k<=len;k++) 
			man[y].info.push_back(save[k]);
	man[y].ninfo=man[y].info.size();
}
int main(int argc, char const *argv[])
{
	while (scanf("%d",&n) != EOF)
	{
		MM.clear();
		cnt=0;
		for (int i=0;i<n;i++)
		{
			scanf("%s",str);
			if (strcmp(str,"arrive")==0)
			{
				cnt++;
				man[cnt].info.clear();
				scanf("%s%d",man[cnt].name,&man[cnt].ninfo);
				MM[man[cnt].name]=cnt;
				//printf("%d\n",MM[man[cnt].name] );
				man[cnt].fa=cnt;
				for (int j=0;j<man[cnt].ninfo;j++) scanf("%d",&num[j]);
				sort(num,num+man[cnt].ninfo);
				for (int j=0;j<man[cnt].ninfo;j++) man[cnt].info.push_back(num[j]);
			}
			else if (strcmp(str,"share")==0)
			{
				char a[20],b[20];
				int pa=0,pb=0;
				scanf("%s%s",a,b);
				pa=MM[a];pb=MM[b];
				int A=find(pa),B=find(pb);
				merge(A,B);
				man[A].fa=B;
			}
			else
			{
				char a[20];
				scanf("%s",a);
				int A=find(MM[a]);
				printf("%d\n",man[A].info.size() );
			}
		}
	}
	return 0;
}
