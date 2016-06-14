#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int n;
	char s;
	while (cin>>n){
		int a=0,b=0;
		for (int i=0;i<n;i++){
			cin>>s;
			if (s=='0')
				a++;
			else
				b++;
		}
		if (a>b)
			cout<<a-b<<endl;
		else
			cout<<b-a<<endl;
	}

	return 0;
}