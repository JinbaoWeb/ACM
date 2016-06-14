#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#define INF 0xffffff
char str[200][200];
int value[200];
int main()
{
    ifstream cin("22.txt");
    int n,m,l,p;
    memset (value,0,sizeof(value));
    cin>>m>>n;
    value[0]=INF;
    for (int i=1;i<=n;i++)
    {
        cin>>str[i];
        for (int j=0;j<m;j++)
            for (int k=j+1;k<m;k++)
                if (str[i][j]>str[i][k])
                    value[i]++;
    }
    p=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            if (value[j]<value[p])
                p=j;
        cout<<str[p]<<endl;
        value[p]=INF;
    }
    return 0;
}
