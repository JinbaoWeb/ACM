#include<iostream>
#define MAX 30001
using namespace std;
int main()
{
        int n;
        int data[MAX];
        int num1 = 0, min;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
                cin>>data[i];
           if(1 == data[i])     num1++;
        }
        min = num1;
        for(int i = 0; i < n; ++i)             //对于每个分隔位i，我们计算（numOF1-n1)+n2；  然后把最小的给min     
        {
                if(1 == data[i]) num1--;                       //numOF1减去i位前的1 的个数同时加
                                                                          //上2的个数。也就    是 （numOF1-n1)+n2
                else num1++;
                if(num1 < min) min = num1;                 //把最小的给min
        }
        cout<<min<<endl;
        return 0;
}
 
