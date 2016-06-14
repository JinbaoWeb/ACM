#include <iostream>
using namespace std;
int main()
{
    double r,m,y;
    while(cin >> r >> m >> y)
    {
        r/=100;
        while(y--)
        {
            m = m*(1+r);
        }
        cout << (int)m << endl;
    }
    return 0;
}

