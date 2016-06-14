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
    
    printf("180 170 1\n");
    fclose(stdout);

    // 小数据
    
    fileBegin(id++);
    printf("5 17 2\n");
 
    fclose(stdout);

    fileBegin(id++);
    printf("170 11 3\n");
    fclose(stdout);
    // 随机
    for(int i = 3; i < 9; i++){
        fileBegin(id++);
        int n=rand() %100000;
       	int m=rand() %100000;
       	int k=rand() %5;
       	printf("%d %d %d\n",n,m,k);
       	fclose(stdout);
    }

    // 极限数据
     fileBegin(id++);
        int n=1;
       	int m=100000;
       	int k=3;
       	printf("%d %d %d\n",n,m,k);
     fclose(stdout);
    return 0;
}

