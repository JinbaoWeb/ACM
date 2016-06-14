#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
	char a[200100];
	char b[200100];
	cin>>a>>b;
	ll num[200100];
	memset(num,0,sizeof(num));
	int len=strlen(b);
	for (int i=0;i<len;i++){
		if (i==0)
			num[i]=b[i]-'0';
		else{
			if (b[i]=='1')
				num[i]=num[i-1]+1;
			else
				num[i]=num[i-1];
		}
	}
	ll ans=0;
	int len_a=strlen(a);
	int dis=len-strlen(a)+1;
	if (a[0]=='0')
		ans+=num[dis-1];
	else
		ans+=(dis-num[dis-1]);
	//cout<<ans<<endl;
	for (int i=1;i<len_a;i++){
		if (a[i]=='0')
			ans+=num[dis+i-1]-num[i-1];
		else
			ans+=(dis-num[dis+i-1]+num[i-1]);
	}
	cout<<ans<<endl;
	return 0;
}



