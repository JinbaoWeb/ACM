#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
#define pi 3.1415926
int main()
{
    ifstream cin("23.txt");
    double x1,y1,r1,x2,y2,r2,s,area,a,b;
    while (cin>>x1>>y1>>r1>>x2>>y2>>r2)
    {
        s=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if (s>=r1+r2)
            area=0;
        else
        {
            if (s<=r1-r2||s<=r2-r1)
            {
                if (s<=r1-r2)
                    area=pi*r2*r2;
                if (s<=r2-r1)
                    area=pi*r1*r1;
            }
            else
            {
                a=acos((s*s+r1*r1-r2*r2)/(2*s*r1));
                b=acos((s*s+r2*r2-r1*r1)/(2*s*r2));
                area=a*r1*r1-0.5*r1*r1*sin(2*a)+b*r2*r2-0.5*r2*r2*sin(2*b);
            }
        }
        cout<<fixed<<setprecision(3)<<area<<endl;
    }
    return 0;
}
