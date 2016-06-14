#include <iostream>
using namespace std;
int main()
{
    union baby
    {
        char name[10];
        int number;
    }b={"Yangyang"};
    cout<<b.name<<" "<<b.number<<" "<<endl;
    b.number=65;
    cout<<b.name<<" "<<b.number<<endl;
    char s='A';
    cout<<(int)s<<endl;
    return 0;
}
