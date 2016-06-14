#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

char ch[11];

void fileBegin(int fileID){
    sprintf(ch, "%d.in", fileID);
    freopen(ch, "w", stdout);
}

int main(){
    int id = 0;
    int a, b;
    srand(1);

    // å°æ•°æ?

    
    fileBegin(id++);
    printf("5\n");
    printf("180\n");
    printf("152\n");
    printf("155\n");
    printf("125\n");
    printf("185\n");
    fclose(stdout);

    // å°æ•°æ?
    
    fileBegin(id++);
    printf("5\n");
    printf("180\n");
    printf("172\n");
    printf("165\n");
    printf("155\n");
    printf("145\n");
    fclose(stdout);

    fileBegin(id++);
    printf("5\n");
    printf("150\n");
    printf("160\n");
    printf("170\n");
    printf("177\n");
    printf("185\n");
    fclose(stdout);
    // éšæœº
    for(int i = 3; i < 9; i++){
        fileBegin(id++);
        int n=rand() %100000;
        cout<<n<<endl;
       	for(int j = 0 ; j < n ; j++)
       	{
       		int t = rand() % 300;
       		printf("%d\n",t);
       	}
       	fclose(stdout);
    }

    // æžé™æ•°æ®
    fileBegin(id++);
   		int n=100000;
   		cout<<n<<endl;
       	for(int j = 0 ; j < n ; j++)
       	{
       		int t = rand() % 300;
       		printf("%d\n",t);
       	}
    
    return 0;
}


