#include <iostream>
using namespace std;
int inf = 0xfffff;
int dis[205][205];
int low[205];
bool vis[205];
int n;
int prim()
{
    int ans = 0, i, j, flag, min;
    for(i = 1; i <= n; ++i)
    {
        low[i] = dis[1][i];
        vis[i] = false;
    }
    vis[1] = true;
    for(i = 1; i <= n; ++i)
    {
        min = inf;
        flag = 1;
        for(j = 1; j <= n; ++j)
        {
            if(min > low[j] && !vis[j])
            {
                 min = low[j];
                flag = j;
            }
        }
        if(min >= inf)
        {
            flag = -1;
            break;
        }
        ans += min;
        vis[flag] = true;
        for(j = 1; j <= n; ++j)
        {
            if(dis[flag][j] < low[j] && !vis[j])
            {
                low[j] = dis[flag][j];
            }
        }
    }
    if(flag == -1)  return -1;
    return ans;
}
int main(){
	while (cin>>n){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				cin>>dis[i][j];
			}
		}
		cout<<prim()<<endl;
	}
	return 0;
}
