#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

char ch[11];

void fileBegin(int fileID){
    sprintf(ch, "%d.in", fileID);
    freopen(ch, "w", stdout);
}

int main(){
    int id = 0;
    int a, b;
    srand(1);

    // 小数据

    
    fileBegin(id++);
    printf("5 4\n");
    printf("180 1 180 1 180\n");
    printf("1 2\n");
    printf("2 3\n");
    printf("3 5\n");
    printf("1 5\n");
    fclose(stdout);

    // 小数据
    
    fileBegin(id++);
    printf("5 3\n");
    printf("180 179 78 65 22\n");
    printf("1 3\n");
    printf("1 4\n");
    printf("2 5\n");
    fclose(stdout);

    fileBegin(id++);
    printf("5 1\n");
    printf("150 23 123 123 123\n");
    printf("1 5\n");
    fclose(stdout);
    // 随机
    for(int i = 3; i < 10; i++){
        fileBegin(id++);
        int n=rand() %1000000;
        int k=rand()%n;
        printf("%d %d\n",n,k);
       	for(int j = 0 ; j < n ; j++)
       	{
       		int t = rand() % 100000000;
          if(j != 0)
       		   printf(" %d",t);
          else
             printf("%d",t);
       	}
        printf("\n");
        
        for(int i = 0; i < k; i++)
        {
          int q = 1,w = 0 ;
          while(q > w)
          {
            q = rand() % n;
            w = rand() % n;
          }
          printf("%d %d\n",q,w);
        }
       	fclose(stdout);
    }


    return 0;
}

