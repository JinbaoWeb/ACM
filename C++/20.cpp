#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
#define M 200
#define INF 0xffffff
char str[M][M];
int value[M];
int main()
{
    //ifstream cin("20.txt");
    memset(count,0,M);
    int m,n;
    cin>>m>>n;
    for (int i=0;i<m;i++)
    {
        cin>>str[i];
        for (int j=0;j<n;j++)
            for (int s=j+1;s<n;s++)
                if (str[i][j]>str[i][s])
                    count[i]++;
    }
    int value,index;
    for (int i=0;i<m;i++)
    {
        value=count[i];
        index=i;
        for (int j=0;j<m;j++)
            if (value>count[j])
            {
                value=count[j];
                index=j;
            }
        cout<<str[index]<<endl;
        count[index]=INF;
    }
    return 0;
}

