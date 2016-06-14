#include<fstream>
#include<string.h>
#include<iostream>
using namespace std;
class zifujiamijiemi
{
	char*a;//a?????
	char*x;//x???????
public:
	 zifujiamijiemi(char*b)	 //???? ???
	 {
		 	int n=strlen(b);
			a=new char[n+1];
			x=new char[n+1];
			a[n]=0;
            x[n]=0;
			for(int d=0;d<n;d++)//??
			{
			  a[d]=b[d];
              x[d]=b[d];
			}
	 }
	 ~zifujiamijiemi() //????
	 {
	    delete []a;
		delete []x;
	 }
	 char* Geta()
	 {
		return a;
	 }
	 char* Getx()
	 {
		return x;
	 }
	 int lengtha()
	 {
    	return strlen(a);
	 }
	 int lengthx()
	 {
    	return strlen(x);
	 }
     void Showa()
	 {
		cout<<a<<endl;
	 }
     void Showx()
	 {
		cout<<x<<endl;
	 }
	 void jiami1(char*way)//????1
	 {
		 int len=strlen(a);
		 int length=strlen(way);
		 for(int i=0;i<len;i++)
	     x[i]=a[i]+way[i%length]-'0';
	 }
	 void jiemi1(char*way)//????1
	 {
		 int len=strlen(a);
		 int length=strlen(way);
		 for(int i=0;i<len;i++)
	    a[i]=x[i]+way[i%length]+'0';
	 }
	void jiami2(char*way)//????2 
	{
		int length=strlen(way);
		char*key=new char[length+1];
		key[length]=0;
		for(int i=0;i<length;i++)
		{
		key[i]=a[int(way[i]-'1')];
		}
		strcpy(x,key);	
		delete[]key;
	}
	void jiemi2(char*way)//????2
	 {
		int n=strlen(way);
		char*key=new char[n+1];
		key[n]=0;
		for(int i=0;i<n;i++)
		{
		key[i]=x[int(way[i]-'1')];
		}
		strcpy(x,key);	
		delete[]key;
	 }
	void jiami3(char*way)//????3
	{
	  int len=strlen(a);
	  int length=strlen(way);
	  for (int i = 0; i<len; i++)
		x[i]=a[i]^way[i%length];
	}
	void jiemi3(char*way)//????3
	{		
	  int len= strlen(a);
	  int length = strlen(way);
	  for (int i=0;i<len;i++)
	  a[i] = x[i] ^ way[i%length];
	}
};
void zhucaidan()
{	
	cout << "                          ??1??????1                " << endl;
	cout << "                          ??2??????2                " << endl;
	cout << "                          ??3??????3                " << endl;
	cout << "                          ??4??????1                " << endl;
	cout << "                          ??5??????2                "<< endl;
	cout << "                          ??6??????3                " << endl;
}
int main ()
{
	char way[256];
	int shuzi,i=0;
	cout << "                        ???????????               " << endl;
    cout << "                       ??? ???  ??913106840146       " << endl;
    cout << "                           ????????                  " << endl;
    char  filename1[256], filename2[256];
	char buff[300];
	char data[300];                                        //data?????????
    cout <<"??????:";
	cin >>filename1;
	cout <<"???????:";
    cin >>filename2;
	/*fstream infile,outfile;
	infile.open(filename1,ios::in|ios::nocreate);
	outfile.open(filename2,ios::out);*/
	ifstream infile(filename1,ios::in | ios::nocreate);
    ofstream outfile(filename2,ios::out);
	if (!infile)
	{
	    cout << "????????:"<<filename1<<'\n';
		return;
	}
	if (!outfile)
	{
		cout<<"????????:"<<filename2<<'\n';
		return;
	}
	while(infile.getline(buff,300))//??????????????
	{
		strcpy(data,buff);
	}
	cout<<"??????"<<endl;
    cin>>way;
	for(int z=0;z<strlen(way);z++)
		if(way[z]<'0'||way[z]>'9')
		{
			cout<<"??????"<<endl;
			return;
		}
	zhucaidan();
	zifujiamijiemi duixiang(data);//??????????????
	cin>> shuzi;
	switch (shuzi)
	{
	 case 1:
	    duixiang.jiami1(way);//??
        char* ch=duixiang.Getx();
        int n=duixiang.lengthx();
        for (int i=0;i<n;i++)
		{
	      outfile<<ch[i];
		} 
		break;
/*	 case 2:
		duixiang.jiami2(way);//??
		break;
/*	case 3:
	 duixiang.jiami2(way);//??
	 char* cha=duixiang.Getx();
	 int n2=duixiang.lengthx();
	 for (int i2=0;i2<n2;i2++)//?????????????
	   {
		  outfile<<cha[i];
		}
		break;
         
*/
	}

infile.close();//????
outfile.close();
}
