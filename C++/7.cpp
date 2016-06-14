#include <iostresam>
#include <string.h>
#include <fstream>
using namespace std;
#define M 200
#define INF 0xffffff
char str[M][M];
int count[M];
int main()
{
    ifstream cin("18.txt");
    memset(count,0,M);
    count[0]=INF;
    int m,n;
    cin>>m>>n;
    for (int i=1;i<=m;i++)
    {
        cin>>str[i];
        for (int j=0;j<n;j++)
            for (int s=j+1;s<n;s++)
                if (str[i][j]>str[i][s])
                    count[i]++;
    }
    int p=0;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=m;j++)
            if (count[j]<count[p])
                p=j;
        cout<<str[p]<<endl;
        count[p]=INF;
    }
    return 0;
}
