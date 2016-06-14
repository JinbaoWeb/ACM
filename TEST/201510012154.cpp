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


int main()
{
	int id = 0;
	srand(time(NULL));
	fileBegin(id++);
	cout<<100<<endl;
	for(int i=1;i<=100;i++)
	{
		int n=rand()%10000+1;
		int A=rand()%1000000000+1;
		int q=rand()%1000+1;
		cout<<n<<" "<<A<<" "<<q<<endl;
		for(int j=1;j<n;j++)
			cout<<rand()%2000000001-1000000000<<" ";
		cout<<rand()%2000000001-1000000000<<endl;
		while(q--)
		{
			int L=rand()%n;
			int tmp=n-L;
			int R=L+rand()%tmp;
			cout<<L<<" "<<R<<endl;
		}
	}
	fclose(stdout);
}