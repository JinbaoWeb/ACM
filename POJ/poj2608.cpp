#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char letters[21];
    int i;
    int pre;
    int now;
    while(cin>>letters)
    {
        pre=0;
        now=0;
        for(i=0;i<strlen(letters);i++)
        {
            if(letters[i]=='B'||letters[i]=='F'||letters[i]=='P'||letters[i]=='V')
                now=1;
            else if(letters[i]=='C'||letters[i]=='G'||letters[i]=='J'||letters[i]=='K'||letters[i]=='Q'||letters[i]=='S'||letters[i]=='X'||letters[i]=='Z')
                now=2;
            else if(letters[i]=='D'||letters[i]=='T')
                now=3;
            else if(letters[i]=='L')
                now=4;
            else if(letters[i]=='M'||letters[i]=='N')
                now=5;
            else if(letters[i]=='R')
                now=6;
            else
                now=0;
            if(now==pre)
                continue;
            else if(now!=0)
            {
                cout<<now;
                pre=now;
            }
            else
                pre=now;
        }
        cout<<endl;
    }
    return 0;
}
