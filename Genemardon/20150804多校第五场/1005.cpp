#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int u,v;
void gao(int com,int flag)
{
	int res=com^flag;
	//printf("%d %d %d\n",com,flag,res );
	if (res==1) printf("FIRST BIGGER\n");
	else
		printf("SECOND BIGGER\n");
}
int main(int argc, char const *argv[])
{
	while (scanf("%d%d",&u,&v) != EOF)
	{
		int flag=0;
		if (u>v)
		{
			swap(u,v);
			flag=1;
		}
		if (u==1 && v==2) gao(0,flag);
		else
			if (u==1 || u==2) gao(1,flag);
		else 
			if (u+8==v) gao(1,flag);
		else
			if ((u-2)%8==2 && (v==u+1)) gao(1,flag);
		else
			if ((u-2)%8==5 && (v==u+1)) gao(1,flag);
		else
			gao(0,flag);
	}
	return 0;
}