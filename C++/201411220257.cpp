#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int main(){
	int n;
	char s[1005];
	bool used[1005];
	map<char,int> m;
	while (cin>>n){
		while (n--){
			cin>>s;
			int len=strlen(s);
			memset(used,false,sizeof(used));
			for (int i=0;i<len;i++){
				for (int j=i+1;j<len;j++)
					if (s[i]==s[j])
						used[j]=true;
			}
			int count=0;
			for (int i=0;i<len;i++)
				if (used[i]==false)
					count++;
			if (count%2==0)
				cout<<"Hi,girl!"<<endl;
			else
				cout<<"Cheater!"<<endl;
		}
	}
	return 0;
}