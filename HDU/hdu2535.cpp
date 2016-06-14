#include <iostream>
using namespace std;

int main()
{
    int n;

    while(cin >> n && n)
    {
        int i,j,sum = 0,t,k,a[105] = {0};
        for(i= 1; i<=n; i++)
        {
            cin >> a[i];
        }
        for(i = 1; i<n; i++)//用选择法将数组由小到大排序
        {
            k = i;
            for(j = i; j<=n; j++)
            {
                if(a[k]>a[j])
                    k = j;
            }
            t = a[k];
            a[k] = a[i];
            a[i] = t;
        }
        for(i = 1; i<=n/2+1; i++)//算出最小的前几个的票民数即所求
            sum = a[i]/2+1 + sum;
        cout << sum << endl;
    }
    return 0;
}


