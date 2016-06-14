#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	map<long long,string> m;
	map<long long,string>::iterator it;
	string a;
	int n;
	long long num;
	char ch;

	cin>>n;
	while(n--)
	{
		cin>>ch>>num>>a;
		if(ch=='N')
		{
			if(m.find(num)!=m.end())
				cout<<"ERROR: Exist"<<endl;
			else
			{
				cout<<"New: OK"<<endl;
				m.insert(make_pair(num,a));
			}
		}
		else if(ch=='L')
		{
			it=m.find(num);
			if(it==m.end())
				cout<<"ERROR: Not Exist"<<endl;
			else
			{
				if(a!=it->second)
					cout<<"ERROR: Wrong PW"<<endl;
				else
					cout<<"Login: OK"<<endl;
			}
		}
	}
	return 0;
}















/*#include <iostream>
#include <string.h>
using namespace std;
struct co{
	string a,b;
}c[100010];
int main(){
	int n,k=0;
	char s;
	string x,y;
	cin>>n;
	while (n--){
		cin>>s>>x>>y;
		int flag=0,i;
		for ( i=0;i<=k;i++){
			if (c[i].a==x){
				flag=1;
				break;
			}
		}
		if (s=='N'){
			if (flag==0){
				cout<<"New: OK"<<endl;
				c[k].a=x;
				c[k++].b=y;
			}
			else
				cout<<"ERROR: Exist"<<endl;
		}
		else{
		if (s=='L'){
			if (flag==0){
				cout<<"ERROR: Not Exist"<<endl;
			}
			else{
				if (c[i].b==y)
					cout<<"Login: OK"<<endl;
				else{
					cout<<"ERROR: Wrong PW"<<endl;
				}
			}
		}
	}
	}
	return 0;
}*/
