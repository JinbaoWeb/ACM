#include <iostream>  
#include <algorithm>  
using namespace std; 
typedef long long ll; 
ll a, b, c;  
  
ll f(ll num) {  
    return num > 2 ? 2 : num;  
}  
  
int main() {  
    while (cin >> a >> b >> c) {  
    	
    	ll sum = f(a) + f(b) + f(c);  
    	ll hav = max(0ll, a + b + c - sum);  
    	cout << (hav * sum + (sum - 1) * sum / 2) << endl;  
    }  
    return 0;  
}  