#include <bits/stdc++.h>
using namespace std;  
#define N 100003  
#define inf 1e100  
double a[N][5];  
int n;  
int main() {  
    while (scanf("%d", &n) == 1) {  
        for (int i=0; i<n; i++)  
            for (int j=0; j<5; j++) scanf("%lf", &a[i][j]);  
        double ans = 0, mi, mx, t;  
        for (int s=0; s<(1<<5); s++) {  
            mi = inf, mx = -inf;  
            for (int i=0; i<n; i++) {  
                t = 0;  
                for (int j=0; j<5; j++)  
                    if ((1<<j) & s) t += a[i][j];  
                    else t -= a[i][j];  
                mi = min(mi, t);  
                mx = max(mx, t);  
            }  
            ans = max(ans, mx-mi);  
        }  
        printf("%.2lf\n", ans);  
    }  
    return 0;  
}  