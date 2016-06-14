#include <iostream>  
#include <algorithm>  
using namespace std;  
typedef long long ll;
int main() { 
	ll a,b,c; 
    while (cin >> a >> b >> c) {  
    	ll sum = a+b+c;
    	if (sum<=6){
    		cout<<sum*(sum-1)/2<<endl;
    	}  
    	else{
    		cout<<15+(sum-6)*6<<endl;
    	}
    }  
    return 0;  
}  