#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include <fstream>
using namespace std;

const int maxn=100020;
int n,k,m;
bool vis[maxn];
struct node
{
    int pos,step;
};

int bfs()
{
    memset(vis,0,sizeof(vis));
    queue<node> q;
    node bgn;
    bgn.pos = n;
    bgn.step = 0;
    q.push(bgn);
    vis[n]=1;
    while(!q.empty())
    {
        node now=q.front();
        q.pop();
        if(now.pos==m) return now.step;
        node next;
        
        next.pos=now.pos-1;
        if(next.pos>=0&&next.pos<maxn&&!vis[next.pos])
        {
        	next.step = now.step +1;
            q.push(next);
            vis[next.pos]=1;
        }
     
        next.pos=now.pos+1;
        if(next.pos<maxn&&!vis[next.pos])
        {
        	next.step = now.step +1;
            q.push(next);
            vis[next.pos]=1;
        }
       
        next.pos=now.pos*k;
        if(next.pos<maxn&&!vis[next.pos]&&next.pos!=0)
        {
            next.step = now.step +1;
            q.push(next);
            vis[next.pos]=1;
        }
    }
    return false;
}

int main()
{
    ifstream cin("9.in");
    ofstream cout("9.out");
    while(cin>>n>>m>>k){
        cout<<bfs()<<endl;
    }
    return 0;
}