#include<iostream>
#include<stdio.h>
using namespace std;
int up[30005],father[30005],count[30005];
int find_ant(int x)
{
	int fa=father[x];
	if(fa==x)
		return x;
	father[x]=find_ant(father[x]);
	up[x]+=up[fa];//x以前的祖先是fa,当然这个地方是加up[fa]，要问为什么不是1，因为这是递归
	return father[x];
}
void unin(int x,int y)
{
	int x_x,y_y;
	x_x=find_ant(x);
	y_y=find_ant(y);
	if(x_x==y_y)
		return ;
	father[y_y]=x_x;//题目要求这个x_x必然在上面，所以
	up[y_y]=count[x_x];//在y_y上面的有count[x_x]个，这个数组就是常见的并查集查这个集合多少元素的那个。
	count[x_x]+=count[y_y];//不解释
}
int main()
{
	int p,i,a,b,t;
	char c;
	cin>>p;
	//初始化
	for(i=1;i<=30000;i++)
	{
		father[i]=i;
		up[i]=0;
		count[i]=1;
	}
	while(p--)
	{
		cin>>c;
		if(c=='M')
		{
			scanf("%d%d",&a,&b);
			unin(a,b);
		}
		if(c=='C')
		{
			scanf("%d",&a);
			t=find_ant(a);
			cout<<count[t]-up[a]-1<<endl;//自己不能算进去。
		}
	}
	return 0;
}
