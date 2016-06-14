#include <bits/stdc++.h>
using namespace std;
map<string,string> Classes;
map<string,string> Method;
map<string,int> Class;
string s1,s2;
void ClassMethod(){
	cin>>s2;
	string str1,str2;
	int x=s2.find(':');
	if (x!=s2.npos){
		str1=s2.substr(0,x);
		str2=s2.substr(x+1,s2.length()-x-1);
		cout<<str1<<" "<<str2<<endl;
		if ()
	}
}
int main(){
	int t;
	cin>>t;
	while (t--){
		while (cin>>s1){
			if (s1=="begin"){
				Class.clear();
				Classes.clear();
				Method.clear();
				continue;
			}
			if (s1=="end") break;
			if (s1=="class") ClassMethod();
			/*if (s1=="def") DefMethond();
			if (s1=="undef") UndefMethod();
			if (s1=="call") CallMethod();*/
		}
	}
	return 0;
}