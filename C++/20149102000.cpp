#include<iostream>
#include <string.h>
using namespace std;
int h,t,r;
void eq(int q[],int d)//入队操作
{
	q[h++]=d;
	if (h>200) h=1;
}
int dq(int q[])//出队操作
{
	r=q[++t];
	q[t]=0;
	return r;
}
int BFS(int g[65][65],int s1,int s2)//宽搜
{
	int k=1,s[65],i,color[65],d[65],q[2000],u;
	for (i=1;i<=64;++i)
	{
		color[i]=0;
		d[i]=50;
	}
	color[s1]=1;
	d[s1]=0;
	h=1;
	t=0;
	memset(q,0,sizeof(q));
	eq(q,s1);
	while (h-t!=1)
	{
		u=dq(q);
		for (i=1;i<=64;++i)
		if (g[u][i]==1)
		{
			if (color[i]==0) 
			{
				color[i]=1;
			    d[i]=d[u]+1;
			    if (i==s2) return d[i];
			    eq(q,i);
			}
		}
		color[u]=2;
	}
}
int main()
{
	int g[65][65],i,j,x1,x2,y1,y2,s1,s2;char a[6];
	memset(g,0,sizeof(g));
	for(j=1;j<=8;++j)//建立图
		for (i=1;i<=8;++i)
		{
			if ((i+1<=8)&&(j+2<=8)) g[8*(i-1)+j][8*i+j+2]=1;
			if ((i+2<=8)&&(j+1<=8)) g[8*(i-1)+j][8*(i+1)+j+1]=1;
			if ((i+2<=8)&&(j-1>0)) g[8*(i-1)+j][8*(i+1)+j-1]=1;
			if ((i+1<=8)&&(j-2>0)) g[8*(i-1)+j][8*i+j-2]=1;
			if ((i-1>0)&&(j-2>0)) g[8*(i-1)+j][8*(i-2)+j-2]=1;
			if ((i-2>0)&&(j-1>0)) g[8*(i-1)+j][8*(i-3)+j-1]=1;
			if ((i-2>0)&&(j+1<=8)) g[8*(i-1)+j][8*(i-3)+j+1]=1;
			if ((i-1>0)&&(j+2<=8)) g[8*(i-1)+j][8*(i-2)+j+2]=1;
		}
	int t,n;
	cin>>t;
	while (cin>>n){
	while (gets(a)!=NULL)
	{
		x1=a[0]-'0'+1;
		y1=a[1]-'0';
		x2=a[3]-'0'+1;
		y2=a[4]-'0';
	    s1=8*(x1-1)+y1;
		s2=8*(x2-1)+y2;
		if (s1==s2) printf("0\n");
		else
		printf("%d\n",BFS(g,s1,s2));
	}
	}
	return 0;
}

