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
		
		if (x.month>2 || x.month==2&&x.day>29)
			x.year++;
		if (y.month>2 || y.month==2&&y.day>=29)
			y.year++;
		int count=0;
		for (int i=x.year;i<y.year;i++){
			if (i%400==0 || (i%4==0&&i%100!=0))
				count++;
		}
		cout<<"Case #"<<cas<<": ";
		cout<<count<<endl;
	}
	return 0;
}
