#include <iostream>
#include <iomanip>
using namespace std;
struct line{
	double x1,y1,x2,y2;
}l[3];
bool istrue(line a,double x,double y){
	if ((a.x1<=x&&x<=a.x2||a.x1>=x&&x>=a.x2) && (a.y1<=y&&y<=a.y2||a.y1>=y&&y>=a.y2))
		return true;
	return false;
}
int main(){
	int n;
	cin>>n;
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	while (n--){
		for (int i=0;i<2;i++)
			cin>>l[i].x1>>l[i].y1>>l[i].x2>>l[i].y2;
		if (l[0].x1!=l[0].x2 && l[1].x1!=l[1].x2){		//均有斜率的两条线段 
			double k1=(l[0].y2-l[0].y1)/(l[0].x2-l[0].x1),k2=(l[1].y2-l[1].y1)/(l[1].x2-l[1].x1);
			double b1=-k1*l[0].x1+l[0].y1,b2=-k2*l[1].x1+l[1].y1;
			//cout<<"k1="<<k1<<" k2="<<k2<<endl;
			if (k1==k2){	//共线或者平行 
				if (k1*l[1].x1+b1==l[1].y1)
					cout<<"LINE"<<endl;
				else
					cout<<"NONE"<<endl;
			}
			else{
				double x=(b2-b1)/(k1-k2),y=k1*x+b1;
				//cout<<"x="<<x<<" y="<<y<<endl;
				if (istrue(l[0],x,y)==true && istrue(l[1],x,y)==true)	//有交点且在线段内 
					cout<<"POINT "<<fixed<<setprecision(2)<<x<<" "<<y<<endl;
				else	//无交点或者有交点但不在线段内 
					cout<<"NONE"<<endl;
			}
		}
		else{
			if (l[0].x1!=l[0].x2 && l[1].x1==l[1].x2){	//其中一条线段无斜率 
				double k1=(l[0].y2-l[0].y1)/(l[0].x2-l[0].x1);
				double b1=-k1*l[0].x1+l[0].y1;
				double x=l[1].x1,y=k1*x+b1;
				if (istrue(l[0],x,y)==true && istrue(l[1],x,y)==true)
					cout<<"POINT "<<fixed<<setprecision(2)<<x<<" "<<y<<endl;
				else
					cout<<"NONE"<<endl;
			}
			else{
				if (l[0].x1==l[0].x2 && l[1].x1!=l[1].x2){	//其中一条线段无斜率 
					double k2=(l[1].y2-l[1].y1)/(l[1].x2-l[1].x1);
					double b2=-k2*l[1].x1+l[1].y1;
					double x=l[0].x1,y=k2*x+b2;
					if (istrue(l[0],x,y)==true && istrue(l[1],x,y)==true)
						cout<<"POINT "<<fixed<<setprecision(2)<<x<<" "<<y<<endl;
					else
						cout<<"NONE"<<endl;
				}
				else{	//均无斜率 
					if (l[0].x1==l[1].x2)
						cout<<"LINE"<<endl;
					else
						cout<<"NONE"<<endl;
				}
			}
		}
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}
