/*#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
int main(){
	double a,b,c,d;
	while (cin>>a>>b>>c>>d){
		double k1=max(3*a/10,a-a/250*c);
		double k2=max(3*b/10,b-b/250*d);
		//cout<<k1<<" "<<k2<<endl;
		if (k1>k2)
			cout<<"Misha"<<endl;
		else if (k1<k2)
			cout<<"Vasya"<<endl;
		else 
			cout<<"Tie"<<endl;
	}
	return 0;
}
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
int main(){
    int a,b,c,d;
    while (cin>>a>>b>>c>>d){
        double k1=max(3*a*1.0/10,a-a*1.0/250*c*1.0);
        double k2=max(3*b*1.0/10,b-b*1.0/250*d*1.0);
        //cout<<k1<<" "<<k2<<endl;
        if (k1>k2)
            cout<<"Misha"<<endl;
        else if (k1<k2)
            cout<<"Vasya"<<endl;
        else
            cout<<"Tie"<<endl;
    }
    return 0;
}