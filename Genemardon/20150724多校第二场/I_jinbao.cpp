#include <iostream>
using namespace std;
int main(){
	int n;
	while (cin>>n){
		if (n>24){
			if (n%2==0){
				cout<<-1<<endl;
			}
			else{
				cout<<"1 + 2"<<endl;
				int k=n+1,k1=3;
				for (int i=1;i<=22;i++){
					cout<<k++<<" + "<<k1++<<endl;
				}
				cout<<k++<<" / "<<k1++<<endl;
				for (int i=1;i<=(n-25)/2;i++){
					cout<<k++<<" + "<<k1++<<endl;
					cout<<k++<<" - "<<k1++<<endl;
				}
			}
		}
		if (n<4){
			cout<<-1<<endl;
			continue;
		}
		else if (n==4){
			cout<<"1 * 2\n";
			cout<<"5 + 3\n";
			cout<<"6 + 4\n";
		}
		else if (n==5){
			cout<<"1 * 2"<<endl;
			cout<<"5 * 3"<<endl;
			cout<<"6 - 4"<<endl;
			cout<<"7 / 5"<<endl;
		}
		else if (n==6){
			cout<<"1 + 2"<<endl;
			cout<<"7 + 3"<<endl;
			cout<<"8 + 4"<<endl;
			cout<<"9 + 5"<<endl;
			cout<<"10 - 6"<<endl;
		}
		else if (n==7){
			cout<<"1 + 2"<<endl;
			cout<<"8 + 3"<<endl;
			cout<<"9 / 4"<<endl;
			cout<<"10 + 5"<<endl;
			cout<<"11 + 6"<<endl;
			cout<<"12 + 7"<<endl;
		}
		else if (n==8){
			cout<<"1 + 2"<<endl;
			cout<<"9 + 3"<<endl;
			cout<<"4 - 5"<<endl;
			cout<<"11 * 6"<<endl;
			cout<<"12 * 7"<<endl;
			cout<<"13 * 8"<<endl;
			cout<<"10 + 14"<<endl;
		}
		else if (n==9){
			cout<<"1 + 2"<<endl;
			cout<<"10 + "
		}
		else if (n==10){

		}
	}

	return 0;
}