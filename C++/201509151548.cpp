#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>

using namespace std;

#define mnx 100050
#define ll long long
#define mod 1000000007
#define inf 223372036854775807
#define eps 1e-10
#define Pi acos(-1.0);
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
 
ll a[mnx], b[mnx];
int root[mnx], tot;
struct node{
    int ls, rs, sum;
}p[mnx*20];
int build( int l, int r ){
     int rt = tot++;
     p[rt].sum = 0;
     if( l == r ) return rt;
     int m = ( l + r ) >> 1;
     p[rt].ls = build( l, m );
     p[rt].rs = build( m + 1, r );
     //cout<<rt<<" "<<p[rt].ls<<" "<<p[rt].rs<<endl;
    return rt;
}
void Debug(){
    for (int i=0;i<=tot;i++){
        cout<<i<<" "<<p[i].ls<<" "<<p[i].rs<<endl;
    }
}
int update( int x, int v, int i, int l, int r ){
     int rt = tot++;
     p[rt] = p[i];
     p[rt].sum += v;
     if( l == r ) return rt;
     int m = ( l + r ) >> 1;
     if( x <= m ) p[rt].ls = update( x, v, p[i].ls, l, m );
    else p[rt].rs = update( x, v, p[i].rs, m + 1, r );
     return rt;
}
int query( int i, int j, int k, int l, int r ){
     if( l == r ) return p[i].sum - p[j].sum;
     int ret = 0, m = ( l + r ) >> 1;
     if( k > m ){
         ret += ( p[p[i].ls].sum - p[p[j].ls].sum );
         ret += query( p[i].rs, p[j].rs, k, m + 1, r );
     }
     else{
         ret += query( p[i].ls, p[j].ls, k, l, m );
     }
     return ret;
}
int main(){
     int cas, cnt = 1;
     scanf( "%d", &cas );
     while( cas-- ){
         tot = 0;
         int n, m;
         scanf( "%d %d", &n, &m );
         for( int i = 1; i <= n; i++ ){
             scanf( "%I64d", &a[i] );
             b[i] = a[i];
         }
         sort( b + 1, b + 1 + n );
         int tmp = unique( b + 1, b + 1 + n ) - b - 1;
        b[tmp] = inf;
         cout<<tmp<<endl;
         root[0] = build( 1, tmp );
         Debug();
         for( int i = 1; i <= n; i++ ){
             int k = lower_bound( b + 1, b + 1 + tmp, a[i] ) - b;
             root[i] = update( k, 1, root[i-1], 1, tmp ); 
             cout<<"-------------------"<<endl;
             Debug();
         }
         //Debug();
         printf( "Case %d:\n", cnt++ );
         while( m-- ){
             int l, r; ll v;
             scanf( "%d %d %I64d", &l, &r, &v );
             l++, r++;
             int k = upper_bound( b + 1, b + 1 + tmp, v ) - b - 1;
             int ans = 0;
             if( k > 0 ) ans = query( root[r], root[l-1], k, 1, tmp );
             printf( "%d\n", ans );
         }
     }
     return 0;
}