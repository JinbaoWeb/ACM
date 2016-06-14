#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <time.h>
using namespace std;
#define Max(x,y)  ((x)>(y)?(x):(y))
#define Min(x,y)  ((x)<(y)?(x):(y))
#define Abs(x) 	  ((x)>0?(x):(-(x)))
#define Swap(x,y) (x+=y,y=x-y,x-=y)
#define sqr(x)	  ((x)*(x))
typedef long long LL;

const double Pi = acos(-1.0);
const double Eqs = 0.00000001;
const int Inf = 123456789;

inline void read(int &x){
    char c=0;
    for(;c<'0'||c>'9';c=getchar());
    for(x=0;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
}

const int max_N = 10000 + 10 ;
int a[max_N] ;
vector<int> e[max_N] ;
int N , M ;
int B , W ;

int cnt[max_N] ;
int cnt_t ;

int v[max_N] ;
int cnt_v ;
int dp[max_N] ;
int V ;

void dfs( int v , int c){
	a[v] = c ;
	for( vector<int>::iterator it = e[v].begin() ; it != e[v].end() ; it ++ ){
		if( a[ *it ] == 0 ){
			int t = c / 2 ;
			t *= 2 ;
			if( c % 2 == 0){
				t ++ ;
			}
			dfs( *it , t) ;
		}
	}
}

void zeroOnePack(int c,int v){
	for(int j=V;j>=c;j--){
		dp[j] = Max(dp[j],dp[j-c] + v);
	}
}
void solve(){
	for(int k = 2 ; k <= cnt_t ; k += 2 ){
		for(int v = V ; v >= 0 ; v--){
			for( int i = 0 ; i <= 1 ; i ++){
				zeroOnePack( cnt[k + i] , cnt[k + i]) ;
			}
		}
	}
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int T ; cin >> T ;
	while(T --){
		cin >> N >> M ;
		for(int i = 0 ; i < N ; i ++){
			a[i] = 0 ;
		}
		for(int i = 0 ; i < N ; i ++){
			cnt[i] = 0 ;
		}
		for(int i = 0 ; i < N ; i ++){
			e[i].clear();
		}

		for(int i = 0 ; i < M ; i ++){
			int x , y ; read(x) ; read(y) ;
			x -- ; y -- ;
			e[x].push_back(y) ;
			e[y].push_back(x) ;
		}
		
		B = W = 0 ;
		cnt_t = 0 ;
		for(int i = 0 ; i < N ; i ++){
			if(a[i] == 0){
				cnt_t += 2 ;
				dfs(i , cnt_t) ;
			}
		}

//		cout << "cnt_t = " << cnt_t << endl;
	
/////////////////////////////////////////
	//	cout << "a" << endl;
	//	for(int i = 0 ; i < N ; i ++){
	//		cout << a[i] << ' ';
	//	}
	//	cout << endl;

		for(int i = 0 ; i < N ; i ++){
			cnt[a[i]] ++ ;
		}

	//	for(int i = 2 ; i <= cnt_t + 1; i ++){
	//		cout << i << " : " << cnt[i] << endl;
	//	}

		V = N / 2 ;
		solve();


		cout << dp[V] * (N - dp[V]) - M << endl;
	}
    return 0;
}
