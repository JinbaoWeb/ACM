#include <iostream>
#include <string.h>
using namespace std;
int main(){
	char a[15],b[15];
	int x,y;
	while (cin>>a>>x>>b>>y){
		int num_x=0,num_y=0;
		int len_a=strlen(a),len_b=strlen(b);
		for (int i=0;i<len_a;i++)
			if (a[i]-'0'==x)
				num_x++;
		for (int i=0;i<len_b;i++)
			if (b[i]-'0'==y)
				num_y++;
		long long p=0,q=0;
		for (int i=0;i<num_x;i++)
			p=p*10+x;
		for (int i=0;i<num_y;i++)
			q=q*10+y;
		cout<<p+q<<endl; 
	}
	return 0;
}
