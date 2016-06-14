#include <iostream>
#include <map>
#include <string.h>
#include <string>
using namespace std;
string a,b;
int maxi;
map<string,int> h;
int main(){
	long long n;
	cin>>n;
	int c=0;
	for (int i=0;i<n;i++){
		cin>>a>>b;
		if (a=="+"){
			if (h[b]!=1){
				c++;
				h[b]=1;
			}
			if (maxi<c)
				maxi=c;
		}
		if (a=="-"){
			if (h[b]!=1){
				maxi+=1;
			}
			else{
				h[b]=0;
				c--;
			}
		}
	}
	cout<<maxi<<endl;
	return 0;
}