#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
using namespace std;

char ch[11];

void fileBegin(int fileID){
    sprintf(ch, "%d.in", fileID);
    freopen(ch, "w", stdout);
}


int main()
{
    int id = 0;
    srand(time(NULL));
    fileBegin(id++);

    int a,m,t=100;
    cout<<t<<endl;
    while(t--)
    {
        cout<<rand()%9+1;
        for(int i=1;i<100;i++)
            cout<<rand()%10;
        cout<<endl;
        cout<<rand()%9+1;
        for(int i=1;i<100;i++)
            cout<<rand()%10;
        cout<<endl;
        cout<<9900000000LL+rand()%100000008<<endl;
    }
    fclose(stdout);
    
    return 0;
}
