#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	char s[20];
	while (cin>>n&&n){
		ll answer=0;
		double d=0;
		while (n--){
			cin>>s;
			int ans=0;
			int len=strlen(s),i;
			for(i=0;i<len;i++){
				if (s[i]=='$' || s[i]==',')
					continue;
				if (s[i]=='.')
					break;
				ans=ans*10+s[i]-'0';
			}
			double a=0;
			while (len-->i+1){
				if (s[len]==',')
					continue;
				a=a/10+s[len]-'0';
			//	cout<<a<<endl;
			}
			a/=10;
		//	cout<<ans<<" "<<a<<endl;
			answer+=ans;
			d+=a;
		}
	//	cout<<answer<<" "<<d<<endl;
		answer=answer*100+(ll)(d*100);
	//	cout<<answer<<endl;
		//cout<<"$"<<answer/100<<"."<<answer%100<<endl;
		cout<<"$";
		char str[1000];
		str[0]=answer%10+'0';
		answer/=10;
		str[1]=answer%10+'0';
		answer/=10;
		str[2]='.';
		int k=3,count=0;
		while (answer){
			if (count%3==0 && count)
				str[k++]=',';
			str[k++]=answer%10+'0';
			answer/=10;
			count++;
		}
		if (str[k-1]==',')
			k--;
		while (k--)
			cout<<str[k];
		cout<<endl;
	}
	return 0;
}
