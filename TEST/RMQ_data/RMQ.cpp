#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define Max 2505
#define FI first
#define SE second
#define ll long long
#define PI acos(-1.0)
#define inf 0x3fffffff
#define LL(x) ( x << 1 )
#define bug puts("here")
#define PII pair<int,int>
#define RR(x) ( x << 1 | 1 )
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,s,t) for( int i = ( s ) ; i <= ( t ) ; ++ i )
using namespace std;

#define N 1111111
int n , m ,k;
int ii,jj;
int a[N] ;
struct TT{
    int l , r , max , min ,num ;
}T[N * 3] ;
void build(int l , int r ,int x){
    T[x].l = l , T[x].r = r ;
    if(l == r){
        T[x].num = a[l] ;
        T[x].max = T[x].min = a[l] ;return ;
    }
    int mid = l + r >> 1 ;
    build(l , mid , LL(x)) ;
    build(mid + 1 , r , RR(x)) ;
    T[x].max = max(T[LL(x)].max , T[RR(x)].max) ;
    T[x].min = min(T[LL(x)].min , T[RR(x)].min) ;
}
int MAX , MIN ;
void query(int l , int r ,int x){
    if(T[x].l > r || T[x].r < l)return ;
    if(T[x].l == l && T[x].r == r){
        MAX = max(MAX , T[x].max) ;
        MIN = min(MIN , T[x].min) ;return ;
    }
    int mid = T[x].l + T[x].r >> 1 ;
    if(l > mid){
        query(l , r , RR(x)) ;
    }
    else if(r <= mid){
        query(l , r , LL(x)) ;
    }
    else {
        query(l , mid , LL(x)) ;
        query(mid + 1 , r , RR(x)) ;
    }
}
int b[N] , c[N] ;
int main() {
    scanf("%d %d",&n,&k) ;
    for (int i = 1 ; i <= n ; i ++ )
        scanf("%d",&a[i]) ;
    build(1 , n , 1) ;

    for(int s = 0 ; s < k; s++)
    {
        scanf("%d %d",&ii,&jj);
        
            MAX = -inf , MIN = inf ;
            query(ii , jj,1) ;
            b[ii] = MIN ;
            c[ii] = MAX ;
        
       printf("%d",b[ii]) ;puts("") ;
       printf("%d",c[ii]) ;puts("") ;
    }
    return 0;
}

