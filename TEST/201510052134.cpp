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
    printf("aaaaaaab\n");
    fclose(stdout);

    fileBegin(id++);
    printf("hhhhhhhb\n");
    fclose(stdout);
    
    fileBegin(id++);
    printf("abaaaaa\n");
    fclose(stdout);

    fileBegin(id++);
    printf("aaaaaahhab\n");
    fclose(stdout);

    fileBegin(id++);
    printf("aaaaaaawb\n");
    fclose(stdout);

    fileBegin(id++);
    printf("baaaa\n");
    fclose(stdout);

    fileBegin(id++);
    printf("nananaaaaanhhhhhhnwhb\n");
    fclose(stdout);

    fileBegin(id++);
    printf("nnnnnnnnnnnnnwwwwwwwwwwwwwwwwwwwwwwwwaaaaaaanb\n");
    fclose(stdout);

    fileBegin(id++);
    printf("wwwwwwwwwwwwnnnnnnnnnnnnnaaaahhhhhhhb\n");
    fclose(stdout);
    fileBegin(id++);
    printf("ahahahahahahahb\n");
    fclose(stdout);
    return 0;
}

