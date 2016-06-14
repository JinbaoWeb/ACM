
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define X first
#define Y second
#define nl printf("\n")
#define SZ(x) (int)(x.size())
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpp make_pair

///==Scanning====///
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

///==Arr,Vec Functions==///
#define all(v) v.begin(),v.end()
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define MAX(a) (*max_element(all(a)))
#define MIN(a) (*min_element(all(a)))
#define fv(i,v)  for(int i=0;i<(int)v.size();i++)
#define fr(i,a,n) for(int i=a;i<=n;i++)
#define rf(i,n,a) for(int i=n;i>=a;i--)

///===Some Useful====///
#define OnBit(a) __builtin_popcountll(a)
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define dbg(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
#define IO freopen("A.in","r",stdin),freopen("Out.out","w",stdout)
using namespace std;

///===TypeDefs=====///
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vii;
#define MX     302
#define inf    1000000009
#define MD     1000000007LL

char s[4][MX + 5];
vector< pii >v[4];
int r, c, tot, tmm, dis[4][MX + 5];

bool CanGo(int id, int p) {
    int sz = SZ( v[id] );
  //  cout<< " ?? "<<p<<endl;
    for(int i = 0; i < sz; i++) {
        pii pp = v[id][i];
        int x = pp.X;
        int y = x + pp.Y - 1;
        int dc = tmm * 2;
      //  cout<<x<< " , "<<y<<  " -- "<<tmm<<endl;
        x -= dc;
        y -= dc;
//        x+=c*c;
//        y+=c*c;
//        x%=c;
//        y%=c;
      //  cout<<x<< " , "<<y<<endl;
        if( x<=p && y>=p ) return false;
    }
    return true;
}

int Bfs(int sx, int sy) {
    fr(i, 0, 3)fr(j, 0, c - 1)dis[i][j] = inf;
    queue< pii >Q;
    Q.push( mpp(sx, sy) );
    dis[sx][sy] = 0;
    while( !Q.empty() ) {
        pii p = Q.front();
        Q.pop();
        int x = p.X, y = p.Y;
        if( y == c - 1 ) return 1;
        /// go 1;
        int tmmm = dis[x][y];
        tmm = tmmm;
        //cout<<x<< " &&& "<<y<< " :: "<<tmm<<endl;
        if( CanGo(x, y + 1) == 1 ) {
            if( CanGo(x, y + 2) == 1 && dis[x][y + 1] > dis[x][y] + 1 ) {
                dis[x][y + 1] = dis[x][y] + 1;
                Q.push( mpp(x, y + 1) );
            }
            if( x - 1 >= 0 && CanGo(x - 1, y + 1) ) {
                if( dis[x - 1][y + 1] > dis[x][y] + 1 ) {
                    dis[x - 1][y + 1] = dis[x][y] + 1;
                    Q.push( mpp(x - 1, y + 1) );
                }
            }
            if( x + 1 <= 2 && CanGo(x + 1, y + 1) ) {
                if( dis[x + 1][y + 1] > dis[x][y] + 1 ) {
                    dis[x + 1][y + 1] = dis[x][y] + 1;
                    Q.push( mpp(x + 1, y + 1) );
                }
            }
        }
    }
    return 0;
}

int main() {
    int i, j, k, tc;
    //_cin;
    cin >> tc;
    while(tc--) {
        r = 3;
        fr(i,0,4)v[i].clear();
        cin >> c >> tot;
        fr(i, 0, r-1 ) {
            fr(j, 0, c - 1)cin >> s[i][j];
        }
        int stx, sty;
        fr(i, 0, r-1 ) {
            fr(j, 0, c - 1) {
                char ch = s[i][j];
                if(ch == '.')continue;
                if(ch == 's') {
                    stx = i, sty = j;
                    continue;
                }
                int jj = j, cnt = 0;
                while( j < c && s[i][j] == ch ) {
                    cnt++;
                    j++;
                }
                v[ i ].pb(  mpp(jj, cnt) );
                if(cnt)j--;
            }
        }
//        fr(i,0,2){
//            cout<<i<< " :: "<<SZ(v[i])<<endl;
//            fr(j,0,SZ(v[i])-1){
//                cout<<v[i][j].X<< " , "<<v[i][j].Y<<endl;
//            }
//        }
        bool ans = Bfs(stx, sty);
        if( ans ) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}