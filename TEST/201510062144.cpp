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

    srand(1);

    // 小数据

    
    fileBegin(id++);
    printf("aGA\n");
    fclose(stdout);

    // 小数据
    
    fileBegin(id++);
    printf("aaGAA\n");
    fclose(stdout);

    fileBegin(id++);
    printf("aAaAaaaaGAAAA\n");
    fclose(stdout);
    // 随机
    for(int i = 3; i < 9; i++){
        fileBegin(id++);
        int n=(rand() %500000) / 2 + 1;
        int p = 17;
       	for(int j = 0 ; j < n ; j++)
       	{
          if(j+1 == n/2 +1)
          {
            printf("G");
            continue;
          }
       		if(j+1 > (n/2) && j <= n)
          {
       		 printf("A");
           continue;
          }
          printf("a");
       	}
        printf("\n");
       	fclose(stdout);
    }

    // 极限数据
     fileBegin(id++);
        int n=499999;
        
        for(int j = 0 ; j < n ; j++)
        {
          if(j == n/2+1)
          {
            printf("G");
            continue;
          }
          if(j <= n/2)
          {
           printf("a");
           continue;
          }
          printf("A");
        }
        printf("\n");
        fclose(stdout);
    
    return 0;
}

