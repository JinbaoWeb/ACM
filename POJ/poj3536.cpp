#include <iostream>
#include <cmath>
using namespace std;
#define M 1000000
int main(){
	int n,mul,s;
	while (cin>>n){
		int max=0xffffff,max_a=0,max_b=0,max_c=0,c;
		for (int a=1;a<=sqrt((double)n)+1;a++)
			for (int b=1;b<=sqrt((double)n)+1;b++)
			{
				mul=a*b;
				if (mul>n)
					break;
				if (n%mul!=0)
					continue;
				c=n/(a*b);
				s=2*(a*b+a*c+b*c);
				if (s<max)
				{
					max=s;
					max_a=a;
					max_b=b;
					max_c=c;
				}	
				
			}
		cout<<max_a<<" "<<max_b<<" "<<max_c<<endl;
	}
	return 0;
} 
