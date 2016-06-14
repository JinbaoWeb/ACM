#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
int n;
int main(int argc, char const *argv[])
{
	freopen("in", "w", stdout);
	srand((unsigned)time(NULL));
	int n = rand()%25+4;
	printf("%d\n",n );
	if (n<4){
		cout<<-1<<endl;
		
	}
	else if (n==4){
		cout<<"1 * 2\n";
		cout<<"5 + 3\n";
		cout<<"6 + 4\n";
	}
	else if (n==5){
		cout<<"1 * 2"<<endl;
		cout<<"6 * 3"<<endl;
		cout<<"7 - 4"<<endl;
		cout<<"8 / 5"<<endl;
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
	else if (n==10)
	{
		printf("1 / 2\n" );
		printf("3 / 4\n");
		printf("5 / 6\n");
		printf("11 + 12\n");
		printf("13 + 14\n");
		printf("7 + 8\n");
		printf("16 / 9\n");
		printf("10 - 17\n");
		printf("18 * 15\n");
	}
	else if (n==9)
	{
		printf("1 + 2\n");
		printf("10 + 3\n");
		printf("4 / 5\n");
		printf("6 / 7\n");
		printf("8 / 9\n");
		printf("11 - 12\n");
		printf("15 - 13\n");
		printf("16 - 14\n");
	}
	else if (n==11)
	{
		printf("1 + 2\n");
		printf("12 / 3\n");
		printf("13 + 4\n");
		printf("14 + 5\n");
		printf("15 + 6\n");
		printf("16 - 7\n");
		printf("17 + 8\n");
		printf("18 - 9\n");
		printf("19 + 10\n");
		printf("20 - 11\n");
	}
	else if (n==12)
	{
		printf("1 + 2\n");
		for (int i=3;i<=12;i++) if (i%2==0)
			printf("%d + %d\n",10+i,i );
		else printf("%d - %d\n",10+i,i );

	}
	else if (n>=13 && n<23)
	{
		int re=24%n-1;
		printf("1 + 2\n");
		for (int i=1;i<re;i++) printf("%d + %d\n",n+i,i+2 );
		printf("%d / %d\n",n+re,2+re );
		printf("%d + %d\n",n+re+1,3+re );
		for (int i=4+re;i<=n;i++) if (i%2==0)
			printf("%d + %d\n",n+re+1+i-5-re+1+1,i );
		else
			printf("%d - %d\n",n+re+1+i-5-re+1+1,i  );
	}
	else if (n>=23){
		if (n%2==0){
			for (int i=1;i<=11;i++)
				printf("%d / %d\n",i*2-1,i*2 );
			printf("%d + %d\n",n+1,n+2 );
			printf("%d + %d\n",n+12,n+3 ); //n+13  = 3
			printf("%d + %d\n",n+4,n+5 );
			printf("%d + %d\n",n+14,n+6 );
			printf("%d + %d\n",n+15,n+7 );
			printf("%d + %d\n", n+16,n+8);
			printf("%d + %d\n", n+17,n+9);
			printf("%d + %d\n",n+18,n+10 );
			printf("%d + %d\n",n+19,n+11 );  //n+20   = 8
			printf("%d * %d\n",n+13,n+20 );  // n+21 =24
			for (int i=0;i<n-22;i++)
				if (i%2==0)
					printf("%d + %d\n",n+21+i,23+i );
				else
					printf("%d - %d\n",n+21+i,23+i );
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
	return 0;
}