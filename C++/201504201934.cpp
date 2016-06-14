#include <stdio.h>
#include <limits.h>

//图中顶点个数
#define V 5

//未在mstSet中的点的集合中，找出最小key的点
int minKey(int key[], bool mstSet[])
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
   return min_index;
}

// 打印MST
int printMST(int parent[], int n, int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

// Prim算法
void primMST(int graph[V][V])
{
     int parent[V]; // 保持MST信息
     int key[V];   // 所有顶点的代价值
     bool mstSet[V];  //当前包含在MST中点的集合

     // 初始为无穷大
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

     key[0] = 0;     //
     parent[0] = -1; // 第一个作为树的根。

     //  MST 有V的顶点
     for (int count = 0; count < V-1; count++)
     {
        int u = minKey(key, mstSet);
        // 添加u到 MST Set
        mstSet[u] = true;
        //更新和u相连的顶点的代价
        for (int v = 0; v < V; v++)
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     // 打印生成的MST
     printMST(parent, V, graph);
}

int main()
{
   /* 创建以下的图
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    // Print the solution
    primMST(graph);

    return 0;
}
