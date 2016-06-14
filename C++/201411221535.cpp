#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;
struct point{
	int x,y;
	int step;
};
int a[]={-1, 1,-2, 2,-2, 2,-1, 1};
int b[]={-2,-2,-1,-1, 1, 1, 2, 2};
bool map[12][12];
int bfs(point start,point end){
	queue<point> q;
	start.step=0;
	q.push(start);
	while (q.size()){
		point p=q.front();
		if (p.x==end.x && p.y==end.y){
			return p.step;
		}
		for (int i=0;i<8;i++){	
			if (p.x+a[i]<0 || p.x+a[i]>9 || p.y+b[i]<0 || p.y+b[i]>8 || map[p.x+a[i]][p.y+b[i]]==true)
				continue;	
			point s;
			s.x=p.x+a[i];
			s.y=p.y+b[i];
			s.step=p.step+1;
			q.push(s);
		}
		map[p.x][p.y]=true;
		q.pop();
	}
	return 0xffffff;
}
int main(){
	point start1,start2,end;
	while (cin>>start1.x>>start1.y>>start2.x>>start2.y>>end.x>>end.y){
		start1.x-=1;
		start1.y-=1;
		start2.x-=1;
		start2.y-=1;	
		end.x-=1;
		end.y-=1;	
		memset(map,false,sizeof(map));
		int k1=bfs(start1,end);
		memset(map,false,sizeof(map));
		int k2=bfs(start2,end);
		if (k1<=k2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
	}
	return 0;
}