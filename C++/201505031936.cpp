/*******************************************************************************
 * Author :          jinbao
 * Email :           dongjinbao913106840144@gmail.com
 * Last modified :   2015-05-03 19:36
 * Filename :        201505031936.cpp
 * Description :     
 * *****************************************************************************/
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int Max = 105;
const double inf = 0xffffff;
 
int n;
double edge[Max][Max], dict[Max];
bool vis[Max];
 
double dijkstra(){
    int now = 1, count = n - 1;
    vis[1] = true;
    dict[1] = 1;
    while(count --){
        int k;
        double max_dis = 0;
        for(int i = 2; i <= n; i ++)
            if(!vis[i]){
                if(dict[i] < dict[now] * edge[now][i])
                    dict[i] = dict[now] * edge[now][i];
                if(max_dis < dict[i])
                    max_dis = dict[k = i];
            }
        if(k == n) break;
        now = k;
        vis[k] = true;
    }
    return dict[n];
}
 
int main(){
    int t;
    while(~scanf("%d", &n)){
		if (n==0)
			break;
        memset(vis, 0, sizeof(vis));
        memset(edge, 0, sizeof(edge));
        memset(dict, 0, sizeof(dict));
        scanf("%d", &t);
        while(t --){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edge[u][v] = 1.0 * w / 100;
            edge[v][u] = 1.0 * w / 100;
        }
        double ans = dijkstra();
        printf("%.6lf percent\n", ans * 100);
    }
    return 0;
}
