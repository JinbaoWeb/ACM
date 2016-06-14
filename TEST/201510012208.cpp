#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
using namespace std;

char ch[11];

void fileBegin(int fileID){
    sprintf(ch, "%d.in", fileID);
    freopen(ch, "w", stdout);
}



string A,B;
int main()
{
	int id = 0;
    srand(time(NULL));
    fileBegin(id++);

	cout<<100<<endl;
	for(int i=1;i<=10000;i++)
		cout<<'a';
	cout<<endl;
	for(int i=1;i<=1000000;i++)
		cout<<'a';
	cout<<endl;
	for(int i=1;i<=79;i++)
	{
		A="";
		B="";
		for(int j=1;j<=1000;j++)
			A+=rand()%26+'a';
		for(int j=1;j<=100;j++)
		{
			int k=rand()%2;
			if(k==0)
				B+=A;
			else
				B+=rand()%26+'a';
		}
		cout<<A<<endl;
		cout<<B<<endl;
	}
	for(int i=1;i<=20;i++)
	{
		A="";
		B="";
		for(int j=1;j<=10000;j++)
			A+=rand()%26+'a';
		for(int j=1;j<=50;j++)
		{
			int k=rand()%2;
			if(k==0)
				B+=A;
			else
				B+=rand()%26+'a';
		}
		cout<<A<<endl;
		cout<<B<<endl;
	}
	fclose(stdout);
	return 0;
}