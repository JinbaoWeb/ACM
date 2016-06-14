#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    int t;
    double h,v;
    cin>>t;
    while (t--){
        cin>>h>>v;
        double max=0;
        for (double i=0.1;i<v;i+=0.1){
            double l = sqrt(v*v-i*i)*(i/9.8 + sqrt(2*h/9.8 + i*i/(9.8*9.8)));
            if (max<l)
                max=l;
        }
        cout<<fixed<<setprecision(2)<<max<<endl;
    }

    return 0;
}