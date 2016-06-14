#include <iostream>
using namespace std;
int pime[4000000];
int pal[4000000];
bool isprime(int x){
	if (x<2)
		return false;
	if (x==2 || x==3 || x==7 || x==5)
		return true;
	for (int i=2;i*i<=x;i++){
		if (x%i==0)
			return false;
	}
	return true;
}
bool ispalindromic(int x){
	int a[50];
	int k=0;
	while (x){
		a[k++]=x%10;
		x/=10;
	}
	for (int i=0;i<k;i++){
		if (a[i]!=a[k-1-i])
			return false;
	}
	return true;
}
int gcd(int x, int y){
	if (!x || !y) return x > y ? x : y;
	for (int t; t = x % y; x = y, y = t);
	return y;
}
int main(){
	int dp[45][45];
	pime[0]=pal[0]=0;
	for (int i=1;pime[i-1]<=43*pal[i-1];i++){
		if (isprime(i)==true)
			pime[i]=pime[i-1]+1;
		else
			pime[i]=pime[i-1];
		if (ispalindromic(i)==true)
			pal[i]=pal[i-1]+1;
		else
			pal[i]=pal[i-1];
		//cout<<i<<" "<<pime[i]<<" "<<pal[i]<<endl;
		int s=gcd(pime[i],pal[i]);
		if (pime[i]/s>45 || pal[i]/s>45)
			continue;
		else
			dp[pime[i]/s][pal[i]/s]=i;
	}
	for (int i=1;i<45;i++){
		for (int j=1;j<45;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}