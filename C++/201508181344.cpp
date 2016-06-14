#include <cstdio>

const int mod=1000000007;

int b[100][101];
int n,m;

bool test0(int b[]) {
    if (b[1]==-1) return true;
    static bool a[101];
    for (int i=1;i<=n;i++) a[i]=false;
    for (int i=1;i<=n;i++) {
        if (a[b[i]]) return false;
        a[b[i]]=true;
    }
    return true;
}
bool test1() {
    for (int i=0;i<m;i++)
        if (!test0(b[i])) return false;
    return true;
}
bool test2() {
    static int a[101],c[101];
    for (int i=1;i<=n;i++) a[i]=i;
    for (int i=m-1;i>=0;i--) {
        for (int j=1;j<=n;j++) c[b[i][j]]=a[j];
        for (int j=1;j<=n;j++) a[j]=c[j];
    }
    for (int i=1;i<=n;i++)
        if (a[i]!=i) return false;
    return true;
}
int main() {
    int i,j;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int p=0;
        for (i=0;i<m;i++) {
            scanf("%d",&b[i][1]);
            if (b[i][1]==-1) {
                p++;
            } else {
                for (j=2;j<=n;j++) scanf("%d",&b[i][j]);
            }
        }
        if (!test1()) printf("0\n");
        else {
            if (p==0)
                if (test2()) printf("1\n");
                else printf("0\n");
            else {
                int x=1,ans=1;
                for (i=1;i<=n;i++) x=(long long)x*i%mod;
                for (i=1;i<p;i++) ans=(long long)ans*x%mod;
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}