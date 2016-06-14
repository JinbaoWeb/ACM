#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;
double abss(double n){
    if (n<0)
        return -n;
    return n;
}
int main(){
    double a, b, c, d, L ,R;
    while (cin>>a>>b>>c>>d>>L>>R){
        double max=0;
        while (L<=R){
            double x=L;
            double temp=abss(a*pow(x,3)+b*pow(x,2)+c*x+d);
            if (temp>max)
                max=temp;
            L+=0.005;
        }
        
		cout<<fixed<<setprecision(2)<<<<endl;
    }
    return 0;
}