/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-01 09:53
 * Filename :        301C.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#define inf 10000
char map[505][505];
int d[505][505];
int dir_x[]={ 0, 1,0,-1};
int dir_y[]={-1, 0,1, 0};
int n,m;
struct point{
    int x,y;
}start,end;
bool same(point a,point b){
    if (a.x==b.x && a.y==b.y)
        return true;
    else
        return false;
}
bool bfs(){
    queue<point> q;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            d[i][j]=inf;
        }
    }
    q.push(start);
    d[start.x][start.y]=0;
    while (q.size()){
        point p = q.front();
        q.pop();
        if (same(p,end)==true){
            int count=0;
            for (int i=0;i<4;i++){
                 point temp;
                temp.x=p.x+dir_x[i];
                temp.y=p.y+dir_y[i];
                if (temp.x<=n && temp.x>=1 && temp.y>=1 && temp.y<=m && map[p.x+dir_x[i]][p.y+dir_y[i]]=='.'){
                     if (d[temp.x][temp.y]>d[p.x][p.y])
                        return true;
                    count++;
                }
            }
            if (count>1)
                return true;
            return false;
        }
        for (int i=0;i<4;i++){
            point temp;
            temp.x=p.x+dir_x[i];
            temp.y=p.y+dir_y[i];
        //  cout<<temp.x<<" "<<temp.y<<endl;
            if (same(temp,end)==true && map[p.x+dir_x[i]][p.y+dir_y[i]]=='X'){
                return true;
            }
            if (temp.x<=n && temp.x>=1 && temp.y>=1 && temp.y<=m && map[p.x+dir_x[i]][p.y+dir_y[i]]=='.' && d[temp.x][temp.y]==inf){
                 q.push(temp);
                d[temp.x][temp.y]=d[p.x][p.y]+1;
            }
        }
    }
    return false;
}
int main(){
        while (~scanf("%d%d",&n,&m)){
            for (int i=1;i<=n;i++)
                 for (int j=1;j<=m;j++)
                    scanf("\n%c",&map[i][j]);
            scanf("%d%d%d%d",&start.x,&start.y,&end.x,&end.y);
            if (bfs()==true)
                printf("YES\n");
            else
                printf("NO\n");
        }

    return 0;
}
