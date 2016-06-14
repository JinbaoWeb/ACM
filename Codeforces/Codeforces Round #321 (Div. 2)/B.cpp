#include <bits/stdc++.h>
using namespace std;
//algo: segTree;
//inline void inp(int &a){register int c;a = 0;do c = getchar_unlocked(); while(c < '0');do{a = (a << 1) + (a << 3) + c - '0';c = getchar_unlocked();}while(c >= '0');}
//inline void print(long long int int a){char s[11];int t = -1;do{s[++t] = a % 10 + '0';a /= 10;}while(a > 0);while(t >= 0)putchar_unlocked(s[t--]);putchar_unlocked('\n');}

const int M = 100009;
long long int TREE[M*5],ar[M];
void build(int node,int b,int e)
{
    if(b==e)
    {
        TREE[node]=ar[b];
        return;
    }
    int l = node << 1 , r = l + 1 , mid = (b+e)>>1;
    build(l,b,mid);
    build(r,mid+1,e);
    TREE[node] = TREE[l] + TREE[r];
    return;
}
long long int query(int node,int b,int e,int i,int j)
{
    if(i>e or j<b)return 0;
    if(b>=i and e<=j)return TREE[node];
    int l = node << 1 , r = l + 1 , mid = (b+e)>>1;
    return query(l,b,mid,i,j) + query(r,mid+1,e,i,j);
}
void update(int node,int b,int e,int i,int j)
{
    long long int XX = b-e+1;  //this line caused TLE
    if(TREE[node]== XX)return;
    if(i>e or j<b)return;
    if(b==e)
    {
        TREE[node] = sqrt(double(TREE[node]));
        return;
    }
    int l = node << 1 , r = l + 1 , mid = (b+e)>>1;
    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);
    TREE[node] = TREE[l] + TREE[r];
    return;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,cas=1;
    while(cin>>n)
    {
        for(int i=1; i<=n; i++)
        cin>>ar[i];//scanf("%lld",&ar[i]);

        //memset(TREE,0,sizeof(TREE));
        build(1,1,n);
        int Q;
        scanf("%d",&Q);
        printf("Case #%d:\n",cas++);
        while(Q--)
        {
            int cmd,x,y;
            scanf("%d %d %d",&cmd,&x,&y);
            if(x>y)x^=y^=x^=y;
            if(cmd)cout<<query(1,1,n,x,y)<<endl;
            else update(1,1,n,x,y);
        }
    }
    return 0;
}