#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
const int  MAX = 200007;
using namespace std;
typedef long long LL;
int root[MAX],cnt_trees,n,len,h[MAX],hcnt;
LL ans1,ans2,ans3;
struct Query{
    int f,s,t,k;
    void init ( int a , int b  ,int c , int d ){
    	f=a,s=b,t=c,k=d;
    }
}q[MAX<<1];
char s[30];
struct Tree{
    int l,r;
    int sum;
}tree[20*MAX];
//BIT
int c[MAX<<1];
int lowbit ( int x ){
    return x&-x;
}
void add ( int x ){
    while ( x < hcnt )
    {
        c[x]++;
        x += lowbit ( x );
    }
}
int sum ( int x ){
    int ret = 0;
    while ( x ){
        ret += c[x];
        x -= lowbit ( x );
    }
    return ret;
}
void build(int& u,int l,int r){
    u = cnt_trees++;
    tree[u].sum = 0;
    if (l==r) return;
    int mid=l+r>>1;
    build(tree[u].l,l,mid);
    build (tree[u].r,mid+1,r);
}
void update(int p,int& u,int l,int r,int x){
    u = cnt_trees++;
    tree[u] = tree[p];
    tree[u].sum++;
    if ( l == r ) return;
    int mid = l+r>>1;
    if ( x > mid )
        update ( tree[p].r , tree[u].r , mid+1 , r , x );
    else 
        update ( tree[p].l , tree[u].l , l , mid , x );
}

int query ( int p , int u , int l , int r , int k ){
    int sum = tree[tree[u].l].sum - tree[tree[p].l].sum;
    if ( l == r ) return l;
    int mid = l+r>>1;
    if ( sum >= k ) return query ( tree[p].l , tree[u].l , l , mid , k );
    else return query ( tree[p].r , tree[u].r , mid+1 , r , k-sum );
}
int main ( ){
    int cc = 1;
    while ( cin>>n ){
        cnt_trees = 0;
        len = hcnt = 1;
        memset ( c , 0 , sizeof ( c ) );
        for ( int i = 1 ; i <= n ; i++ ){
            int x,y,z;
            cin>>s;
            if ( s[0] == 'I' ){
                q[i].f = 0;
                cin>>q[i].k ;
                h[hcnt++] = q[i].k;
            }
            else{
                int id = s[6]-48;
                if ( id == 1 )
                	cin>>x>>y>>z;
                else 
                    cin>>z;
                q[i].init ( id , x , y , z );
            }
        }
        sort ( h+1 , h+hcnt );
        build ( root[0] , 1 , hcnt-1 );
        ans1 = ans2 = ans3 = 0;
        for ( int i = 1 ; i <= n ; i++ ){
            if ( q[i].f == 0 ){
                int x = lower_bound ( h , h+hcnt , q[i].k )-h;
                update ( root[len-1] , root[len] , 1 , hcnt-1 , x );
                add(x);
                len++;
            }
            else if (q[i].f==1)
                ans1 += h[query ( root[q[i].s-1] , root[q[i].t] , 1 , hcnt-1 , q[i].k )];
            else if ( q[i].f == 2 ){
                int x = lower_bound ( h , h+hcnt , q[i].k )-h;
                ans2 += sum(x);
            }
            else if ( q[i].f == 3 )
                ans3 += h[query ( root[0] , root[len-1] , 1 , hcnt-1 , q[i].k )];
        }
        printf ( "Case %d:\n" , cc++ );
        cout<<ans1<<endl;
        cout<<ans2<<endl;
        cout<<ans3<<endl;
    } 
}