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
    printf("5\n");
    printf("180 170 170\n");
    printf("180 170 170\n");
    printf("170 170 170\n");
    printf("170 160 150\n");
    printf("170 160 160\n");
    fclose(stdout);

    // 小数据
    
    fileBegin(id++);
    printf("5\n");
    printf("180 170 170\n");
    printf("180 170 171\n");
    printf("170 150 170\n");
    printf("170 160 150\n");
    printf("170 160 160\n");
    fclose(stdout);

    fileBegin(id++);
    printf("170 170 171\n");
    printf("170 170 171\n");
    printf("170 170 171\n");
    printf("170 170 171\n");
    printf("170 170 171\n");
    fclose(stdout);
    // 随机
    for(int i = 3; i < 9; i++){
        fileBegin(id++);
        int n=rand() %1000000;
       	for(int j = 0 ; j < n ; j++)
       	{
       		int h = rand() % 1000000;
          int w = rand() % 1000000;
          int g= rand() % 1000000;
       		printf("%d %d %d\n",h,w,g);
       	}
       	fclose(stdout);
    }

    // 极限数据
    fileBegin(id++);
   		int n=1000000;
      for(int j = 0 ; j < n ; j++)
        {
          int h = rand() % 1000000;
          int w = rand() % 1000000;
          int g= rand() % 1000000;
          printf("%d %d %d\n",h,w,g);
        }
    
    return 0;
}

