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
bool map[10][10];
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
			if (p.x+a[i]<0 || p.x+a[i]>7 || p.y+b[i]<0 || p.y+b[i]>7 || map[p.x+a[i]][p.y+b[i]]==true)
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
	return -1;
}
int main(){
	char start[3],end[3];
	while (cin>>start>>end){	//~scanf("%c%c",start,end)){	
		memset(map,false,sizeof(map));
		point starts,ends;
		starts.x=start[0]-'a';
		starts.y=start[1]-'1';
		ends.x=end[0]-'a';
		ends.y=end[1]-'1';
		//printf("To get from %c to %c takes %d knight moves.\n",start,end,bfs(starts,ends));
		cout<<"To get from "<<start<<" to "<<end<<" takes "<<bfs(starts,ends)<<" knight moves."<<endl;
	}
	return 0;
}