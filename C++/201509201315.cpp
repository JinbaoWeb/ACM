#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 1010
#define MOD 1000000007
using namespace std;
int a[2*MAXN], g[40][2*MAXN];
int Gauss(int n) {
    int i, j, r, c, cnt;
    for (c = cnt = 0; c < n; c++) {
        for (r = cnt; r < 31; r++) {
            if (g[r][c])
                break;
        }
        if (r < 31) {
            if (r != cnt) {
                for (i = 0; i < n; i++)
                    swap(g[r][i], g[cnt][i]);
            }
            for (i = cnt + 1; i < 31; i++) {
                if (g[i][c]) {
                    for (j = 0; j < n; j++)
                        g[i][j] ^= g[cnt][j];
                }
            }
            cnt++;
        }
    }
    return n - cnt;
}
int main(){
    int n,m,L,R,vary;
    while (cin>>n>>m>>L>>R){
        int k=0;
        long long tmp=0,ans;
        for (int j=L;j<=R;j++){
            k=0;
            for (int i=0;i<=m;i++){
                a[k++]=i+j;
            }
            for (int ii = 0; ii < 31; ii++) {
                for (int jj = 0; jj < k; jj++)
                    g[ii][jj] = (a[jj] >> ii) & 1;
            }
            vary=Gauss(k);
            int s=2*n+1;
            for (ans = 1; vary--;) {
                ans <<= 1;
                ans %= MOD;
            }
            long long ans2;
            for (ans2=1;s--;){
                ans2<<=1;
                ans2%=MOD;
            }
            tmp+=(ans*ans2)%MOD;
            tmp%=MOD;
        }
        cout<<tmp<<endl;
        /*
        for (int i=0;i<=m;i++){
            for (int j=L;j<=R;j++){
                a[k++]=i+j;
            }
        }

        for (int i = 0; i < 31; i++) {
            for (int j = 0; j < k; j++)
                g[i][j] = (a[j] >> i) & 1;
        }
        vary=Gauss(k);
        cout<<k<<" "<<vary<<endl;
        {
            for (ans = 1; vary--;) {
                ans <<= 1;
                ans %= MOD;
            }
            printf("%d\n", ans);
        }
        */
    }
    return 0;
}