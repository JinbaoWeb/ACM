#include <iostream>
#include <string.h>
#include <algorithm>
#include <iomanip>
using namespace std;
struct se{
	double price;
	int x,y;
}s[1000];
int cmp(se p,se q){
	if (p.price<q.price)
		return 0;
	else{
		if (p.price==q.price){
			if (p.x<q.x){
				return 0;
			}
			else{
				if (p.x==q.x){
					if (p.y<q.y)
						return 0;
					else
						return 1;
				}
				else{
					return 1;
				}
			}
		}
	}
}
int main(){
	int n,num;
	while (cin>>n>>num){
		double money=0;
		for (int i=0;i<n;i++)
			cin>>s[i].x;
		for (int i=0;i<n;i++){
			cin>>s[i].y;
			s[i].price=s[i].y*1.0/s[i].x;
		}
		sort(s,s+n,cmp);
		int k=0;
		while (num){
			if (num>=s[k].x){
				money+=s[k].y;
				num-=s[k].x;
				k++;
			}
			else{
				money+=s[k].price*num;
				num=0;
			}
		}
		cout<<fixed<<setprecision(2)<<money<<endl;
	}	
	return 0;
}
