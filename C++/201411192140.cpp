#include <iostream>
using namespace std;
int main(){
	double dis = 50,min=50;
	for (double a=0.1;a<=1.9;a+=0.1){
		double time = 0;
		dis = 50;
		while (dis>=0){
			dis-=a;
			if (dis<=0)
				break;
			time+=a;
		}
		if (time<min)
			min=time;
	}
	cout<<min<<endl;
	return 0;
}