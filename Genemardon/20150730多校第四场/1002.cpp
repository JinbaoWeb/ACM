#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
const double eps = 1e-3;
using namespace std;
int n;
int a[1000010], maxd, maxq, nowd, nowq;
int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        if (n <= 2)
        {
            printf("%d\n", n );
            continue;
        }
        int d = a[2] - a[1];
        maxd = 2; maxq = 2; nowd = 2; nowq = 2;
        double q = double(a[2]) / a[1];
        for (int i = 3; i <= n; i++)
        {
            if (a[i] - a[i - 1] == d) nowd++;
            else
            {
                maxd = max(maxd, nowd);
                nowd = 2;
                d = a[i] - a[i - 1];
            }
            if (fabs(a[i - 1]*q - a[i]) < eps) nowq++;
            else
            {
                maxq = max(maxq, nowq);
                nowq = 2;
                q = double(a[i]) / a[i - 1];
            }
        }
        maxd = max(nowd, maxd);
        maxq = max(nowq, maxq);
        printf("%d\n", max(maxd, maxq) );
    }
    return 0;
}