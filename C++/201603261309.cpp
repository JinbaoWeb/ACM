#include <bits/stdc++.h>
using namespace std;

//char s[12][20]={"Rat","Ox","Tiger","Rabbit","Dragon","Snake","Horse","Ram","Monkey","Rooster","Dog","Pig"};
char s[12][20]={"Rabbit","Tiger","Ox","Rat","Pig","Dog","Rooster","Monkey","Ram","Horse","Snake","Dragon"};
int main(){
	int t,n;
	cin>>t;
	while (t--){
		cin>>n;
		cout<<s[(n%12-1+12)%12]<<endl;
	}
	return 0;
}