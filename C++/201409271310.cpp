#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct bignum
{
	int num[1005];
	int len;
};
bool isbigger(bignum a,bignum b)
{
	if(a.len>b.len)
		return true;
	if(a.len<b.len)
		return false;
	for(int i=a.len-1;i>=0;i--){
		if(a.num[i]>b.num[i])
			return true;
		if(a.num[i]<b.num[i])
			return false;
	}
	return true;
}
bignum jian(bignum a,bignum b)
{
	bignum r;
	int carry=0;
	r.len=a.len;
	int i;
	for(i=0;i<r.len;i++){
		r.num[i]=a.num[i]-carry;
		if(i<b.len)
			r.num[i]-=b.num[i];
		if(r.num[i]<0){
			carry=1;
			r.num[i]+=2;
		}
		else
			carry=0;
	}
	while(r.len>0&&r.num[r.len-1]==0)
		r.len--;
	return r;
}
bignum Mod(bignum a,bignum b)
{
	bignum tmp=a;
	while(isbigger(tmp,b)){
		tmp=jian(tmp,b);
	}
	return tmp;
}
bignum Gcd(bignum a,bignum b)
{
	bignum tmp;
	while(b.len>0){
		tmp=Mod(a,b);
		a=b;
		b=tmp;
		//cout<<"b.len="<<b.len<<endl;
	}
	return a;
}
int main()
{
	int cases;
	bignum a,b;
	char aa[1005],bb[1005];
	int j=1;
	scanf("%d",&cases);
	while(cases--){
		scanf("%s%s",aa,bb);
		int lena=strlen(aa);
		int lenb=strlen(bb);
		a.len=lena;
		b.len=lenb;
		for(int i=0;i<lena;i++){
			a.num[lena-i-1]=aa[i]-'0';
		}
		for(int i=0;i<lenb;i++){
			b.num[lenb-i-1]=bb[i]-'0';
		}
		bignum tmp;
		if(isbigger(a,b)){
			tmp=a;
			a=b;
			b=tmp;
		}
		//tmp=jian(a,b);
		//for(int i=tmp.len-1;i>=0;i--){
		//	cout<<tmp.num[i];
		//}
		//cout<<endl;
		tmp=Gcd(a,b);
		printf("Case #%d: ",j++);
		for(int i=tmp.len-1;i>=0;i--){
			printf("%d",tmp.num[i]);
		}
		printf("\n");
	}
	return 0;
}
