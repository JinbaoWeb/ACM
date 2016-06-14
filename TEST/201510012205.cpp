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

    cout<<100<<endl;
    for(int j=0;j<20;j++)
        cout<<1<<" "<<j<<endl;
    cout<<2<<" "<<2<<endl;
    for(int i=1;i<60;i++)
    {
        int t=rand()%19+3;
        cout<<t<<" "<<rand()%(t-2)<<endl;
    }
    for(int i=1;i<=10;i++)
        cout<<20<<" "<<8+i<<endl;
    for(int i=1;i<=10;i++)
        cout<<21<<" "<<8+i<<endl;

    fclose(stdout);
    return 0;
}
