#include <iostream>
using namespace std;

int target[16][3];

int main()
{
    int i,a,b,c,ci;
    for(i = 0;i < 16;i++)
        scanf("%d%d%d",&target[i][0],&target[i][1],&target[i][2]);
    while(scanf("%d%d%d",&a,&b,&c) != EOF && a != -1)
    {
        double cmin = (a - target[0][0]) * (a - target[0][0]) + (b - target[0][1]) * (b - target[0][1]) + (c - target[0][2]) * (c - target[0][2]);
        ci = 0;
        for(i = 1;i < 16;i++)
        {
            double k = (a - target[i][0]) * (a - target[i][0]) + (b - target[i][1]) * (b - target[i][1]) + (c - target[i][2]) * (c - target[i][2]);
            if(cmin > k)
            {
                cmin = k;
                ci = i;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",a,b,c,target[ci][0],target[ci][1],target[ci][2]);
    }
    return 0;
}
