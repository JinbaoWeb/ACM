#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
struct note
{
    int u,v,num;
    note () {}
    note (int u,int v,int num) : u(u),v(v),num(num) {}
}p[1000000];
struct node
{
    int u,dir,cur;
    node () {}
    node(int u,int dir,int cur) : u(u),dir(dir),cur(cur) {}
}stack[2000000];
int e,n,m;
int head[100010],ne[1000000],ex[1000000],ans[500000];
inline void read(int &x){
    char c=0;
    for(;c<'0'||c>'9';c=getchar());
    for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
}
void init ()
{
    e=0;
    memset(head,-1,sizeof(head));
}
void addnote(int u,int v,int num)
{
    p[e]=note(u,v,num);
    ex[e]=0;
    ne[e]=head[u];head[u]=e++;
}
void dfs(int start)
{
    int top=1;
    stack[1]=node(start,0,head[start]);
    while(top)
    {
    	stack[top].cur=head[stack[top].u];
        while(ex[stack[top].cur]==1)
        {
            stack[top].cur=ne[stack[top].cur];
            
        }
        head[stack[top].u]=stack[top].cur;
        if (stack[top].cur==-1)
        {
            top--;
            continue;
        }
        int edge=stack[top].cur;
        //printf("%d %d %d\n",p[edge].u,p[edge].v,stack[top].dir );
        ans[p[edge].num]=stack[top].dir ^ (edge & 1);
        stack[top+1]=node(p[edge].v,stack[top].dir,head[p[edge].v]);
        ex[edge]=1;
        ex[edge^1]=1;
        stack[top].cur=ne[edge];
        stack[top].dir=!stack[top].dir;
        head[stack[top].u]=ne[edge];
        top++;
    }
}
int main(int argc, char const *argv[])
{
    int t;
    read(t);
    while (t--)
    {
        init();
        read(n);read(m);
        for (int i=0;i<m;i++)
        {
            int u,v;
            read(u);read(v);
            addnote(u,v,i);
            addnote(v,u,i);
        }
        for (int i=1;i<=n;i++) if (head[i]!=-1)
        {
            //printf("---------------\n");
            dfs(i);
        }
        for (int i=0;i<m;i++) printf("%d\n",ans[i] );
    }
    return 0;
}