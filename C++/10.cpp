#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
const int INF=1000000000;
const int maxn=510;
using namespace std;
int map[maxn][maxn],dis[maxn],visited[maxn];
int main()
{
    //ifstream cin("10.txt");
    int n,a,b,k,i,j,N,E,mindistance,min,t;
    cin>>n; //scanf("%d",&n);
    while (n--)
    {
        memset(visited,0,sizeof(visited));  //清0
        mindistance=0;
        cin>>N>>E;  //scanf("%d%d",&N,&E);
        for (i=0;i<N;i++)
        {
            for (j=0;j<N;j++)
            {
                map[i][j]=INF;
            }
        }
	    for (i=0;i<E;i++)
	    {
	        cin>>a>>b>>k;   //scanf("%d%d%d",&a,&b,&k);
	        map[a][b]=map[b][a]=k;
        }
        for (j=0;j<N;j++)
        {
            dis[j]=map[0][j];
        }
        visited[0]=1;
        for (i=0;i<N;i++)
        {
            min=INF;
            for (j=0;j<N;j++)
            {
                if(!visited[j] && min>dis[j])
                {
                    min=dis[j];
                    t=j;
                }
            }
            if(min!=INF)//值得注意的地方
                mindistance+=min;
            visited[t]=1;
            for (j=0;j<N;j++)
            {
                if (!visited[j] && dis[j]>map[t][j])
                {
                    dis[j]=map[t][j];
                }
            }
        }
        cout<<mindistance<<endl;    //printf("%d\n",mindistance);
    }
    return 0;
}
