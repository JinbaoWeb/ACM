#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct node
{
	int x;
	int y;
	int count;
};
int vis[305][305];
node start,stop;
node queue[1000000];
int lenth;
int ax[8]={-2,-1,1,2,2,1,-1,-2};
int bx[8]={1,2,2,1,-1,-2,-2,-1};
int bfs(int row,int column)
{
	int i;
	int xx,yy;
	int head=0,tail=1;
	queue[head].x=row;
	queue[head].y=column;
	queue[head].count=0;
	while(head<tail){
		for(i=0;i<8;i++){
			xx=queue[head].x+ax[i];
			yy=queue[head].y+bx[i];
			if(xx<0||xx>=lenth||yy<0||yy>=lenth||vis[xx][yy])
				continue;
			vis[xx][yy]=1;
			queue[tail].x=xx;
			queue[tail].y=yy;
			queue[tail].count=queue[head].count+1;
			if(xx==stop.x&&yy==stop.y){
				return queue[tail].count;
			}
			tail++;
		}
		head++;
	}
}
int main()
{
	int cases;
	int ans;
	cin>>cases;
	while(cases--){
		cin>>lenth;
		cin>>start.x>>start.y;
		cin>>stop.x>>stop.y;
		memset(vis,0,sizeof(vis));
		if(start.x==stop.x&&start.y==stop.y){
			printf("0\n");
			continue;
		}
		vis[start.x][start.y]=1;
		ans=bfs(start.x,start.y);
		printf("%d\n",ans);
	}

	return 0;
}

