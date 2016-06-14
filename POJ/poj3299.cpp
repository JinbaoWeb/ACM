#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
	
	char a;
	while (cin>>a){
		double t=200,d=200,h=200,e;
		if (a=='E')
			break;
		else if (a=='T')
			cin>>t;
		else if (a=='D')
			cin>>d;
		else
			cin>>h;
		cin>>a;
		if (a=='T')
			cin>>t;
		else if (a=='D')
			cin>>d;
		else
			cin>>h;
		if(h==200)  
            h=t+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10);  
        else if(t==200)  
            t=h-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10);  
        else if(d==200)  
            d=1/((1/273.16)-((log((((h-t)/0.5555)+10.0)/6.11))/5417.7530))-273.16;  
        cout<<setprecision(1)<<fixed<<"T "<<t<<" D "<<d<<" H "<<h<<endl;  
	}
	return 0;
}