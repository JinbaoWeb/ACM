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

    fileBegin(id++);
    printf("1\n");
    fclose(stdout);

    fileBegin(id++);
    printf("2\n");
    fclose(stdout);
    
    fileBegin(id++);
    printf("10\n");
    fclose(stdout);

    fileBegin(id++);
    printf("100\n");
    fclose(stdout);

    fileBegin(id++);
    printf("500\n");
    fclose(stdout);

    fileBegin(id++);
    printf("1000\n");
    fclose(stdout);

    fileBegin(id++);
    printf("5000\n");
    fclose(stdout);

    fileBegin(id++);
    printf("10000\n");
    fclose(stdout);

    fileBegin(id++);
    printf("20000\n");
    fclose(stdout);
    fileBegin(id++);
    printf("50000\n");
    fclose(stdout);
    return 0;
}

