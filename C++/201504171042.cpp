#include <iostream>
#include <string.h>
using namespace std;
typedef long long ll;
struct date{
	ll year;
	int month,day;
};
int main(){
	int t;
	char s[12][50]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
	char c;
	char str[50];
	date x,y;
	cin>>t;
	for(int cas=1;cas<=t;cas++){
		cin>>str;
		for (int i=0;i<12;i++){
			if (strcmp(str,s[i])==0){
				x.month=i+1;
				break;
			}
		}
		cin>>x.day>>c>>x.year;
		cin>>str;
		for (int i=0;i<12;i++){
			if (strcmp(str,s[i])==0){
				y.month=i+1;
				break;
			}
		}
		cin>>y.day>>c>>y.year;
		//test
	//	cout<<x.year<<" "<<x.month<<" "<<x.day<<endl;
	//	cout<<y.year<<" "<<y.month<<" "<<y.day<<endl;
		ll count=0;
		if (x.month>2 || x.month==2&&x.day>29)
			x.year++;
		if (y.month>2 || y.month==2&&y.day>=29)
			y.year++;
		//找到第一个闰年
		ll k;
		for (k=x.year;k<y.year;k++){
			if (k%400==0 || k%4==0&&k%100!=0)
				break;
		}
		//找到最后一个闰年
		ll m;
		for (m=y.year-1;m>=x.year;m--){
			if (m%400==0 || m%4==0&&m%100!=0)
				break;
		}
	//	cout<<m<<" "<<k<<endl;
		if (m>=k){
			count+=(m-k)/4+1;
			ll p=m/100,q=k/100;
			for (ll j=q;j<=p;j++){
				if (j%4==0)
					continue;
				count--;
			}
		}
		cout<<"Case #"<<cas<<": ";
		cout<<count<<endl;
	}

	return 0;
}