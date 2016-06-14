#include <iostream>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
map<char,int> Ident_status;
int Ident_status_count;
map<char,int> Ident;
int Ident_count;
map<char,int> Operator_status;
int Operator_status_count;
map<char,int> Operator;
int Operator_count;
map<char,int> Jiefu_status;
int Jiefu_status_count;
map<char,int> Jiefu;
int Jiefu_count;
map<char,int> Const_status;
int Const_status_count;
map<char,int> Const;
int Const_count;
char NFA_Ident[20][70][5];
int Ident_end;
char NFA_Operator[20][70][5];
int Operator_end;
char NFA_Jiefu[20][70][5];
int Jiefu_end;
char NFA_Const[20][70][5];
int Const_end;
char sub[256];//token串 
string token[10000];
char token2id[10000]; 
int  token_type[10000]; //error，key_words,Ident,Const,Operator,Jiefu分别为0，1,2,3,4,5 
int token_count=0;
char symbol[53][20]=
{		//关键字 
		//a      b       c      d      e      f       g      h      i      j      k      
		"begin","end","const","var","char","string","int","float","bool","true","false",
		/*0,     1,      2,    3,    4,      5,      6,      7,     8,     9,     10,*/
		//l          m        n        o           p      q     r     s     t      u    v    
		"break","procedure","call","continue","default","do","if","else","then","for","while",
		/*11,     12,        13,        14,      15,     16,   17,    18,  19,     20,   21,*/
		//w      x      y      z       
		"do","return","void","main",
		/*22,   23,    24,     25,*/ 
		//运算符 
		//1   2                    3            4     5    6
		"++","--","+","-","*","/","==","<",">","<>","<=",">=","=","!"
		/*26, 27, 28,29,  30;,31,  32,33,  34,  35,  36,  37,  38,39*/
		//界符 
		//7   
		"//",",",";","(",")","[","]",".","\'","\"", 
		/*40, 41, 42, 43, 44,   45,  46,47,  48,49*/
		//标记符 ，常数 
		//8       9
		"标记符","常数","error"
		/*  50,    51,     52*/ 
};
bool isLetter(char ch)//判断是否为字母 
{
	if((ch>='a'&&ch<='z')||(ch>'A'&&ch<'Z')) return true;
	return false; 
}
bool isDigit(char ch)//判断是否为数字 
{
	if(ch>='0'&&ch<='9') return true;
	return false; 
}
bool isOperator(char ch)//判断是否为运算符 ,其中界符"//"也在这里判断 
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='<'||ch=='>'||ch=='='||ch=='!') return true;
	return false;
}
bool isJiefu(char ch)
{
	if(ch==','||ch==';'||ch=='('||ch==')'||ch=='['||ch==']'||ch=='.'
	    ||ch=='{'||ch=='}'||ch=='\''||ch=='\"') return true;
	return false;
 } 
 bool isBlank(char ch)
 {
 	if(ch==' '||ch=='\t'||ch=='\n') return true;
 	return false;
 }
void init()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<40;j++)
		{
			for(int k=0;k<5;k++)
			{
				NFA_Ident[i][j][k]='\0';
				NFA_Operator[i][j][k]='\0';
				NFA_Jiefu[i][j][k]='\0';
				NFA_Const[i][j][k]='\0';
			}
		}
	}
}
//READ turn to NFA(save in adj)
void read2NFA(char NFA[20][70][5],map<char,int> &mp_status,int &mp_status_cnt,map<char,int> &mp,int &mpcnt)
{
	int j=0,len=0;
	char s[100],ch;
	//map clear
	mp_status.clear();
	mp.clear();
	mp_status_cnt=1;
	mpcnt=1;
	while(~scanf("%s",s))
	{
		len=strlen(s);
		ch=s[0];
		if(mp_status[ch]==0)  
		{
			mp_status[ch]=mp_status_cnt++;
		}
		ch=s[3];
		if(mp[ch]==0)
		{
			mp[ch]=mpcnt++;
		}
		if(len==5)
		{
			ch=s[4];
			if(mp_status[ch]==0)
			{
				mp_status[ch]=mp_status_cnt++;
			}
		}
		else
		{
			s[4]='@';
			ch=s[4];
			if(mp_status[ch]==0)
			{
				mp_status[ch]=mp_status_cnt++;
			}
		}
		for(int i=0;i<5;i++)
		{
			if(NFA[mp_status[s[0]]][mp[s[3]]][i]=='\0')
			{
				NFA[mp_status[s[0]]][mp[s[3]]][i]=s[4];
				break;
			}
		}
		
	}
	mp_status_cnt--;
	mpcnt--;
}
//可以匹配出最大的符合NFA的字符串，但不能确定匹配出的字符串是否符合NFA，
//因为不知道匹配出的字符串是否为终态 
bool checkNFA(char NFA[20][70][5],map<char,int> mp_status,map<char,int> mp,char st[],int &curr)
{
	int len=strlen(st);
	int pos=curr;
	int qu[10000];	
	int fr=0;
	int er=0;
	int tempe;
	bool flag=false;//判断当前状态是否可以为终态 
	bool flag1=false;
	char curr_status='S';
	char ch;
	qu[er++]=mp_status[curr_status];
	while(curr<len&&fr<er)
	{
		ch=st[curr];
		tempe=er;
		
		for(int i=fr;i<tempe;i++)
		{
			for(int j=0;j<5;j++)
			{
				curr_status=NFA[qu[i]][mp[ch]][j];
				if(curr_status!='\0')
				{
					flag1=true;
					qu[er++]=mp_status[curr_status];
				}
			}
		}
		if(flag1)
		{
			curr++;
			fr=tempe;
			flag1=false;
		}
		else break;
		
	 } 
	 for(int i=0;i<20;i++)//本应该是最后一次循环中qu[fr]....qu[er]中的状态，而不是所有的状态 
	 {
	 	for(int j=0;j<5;j++)
	 	{
	 		if(NFA[i][mp[st[curr-1]]][j]=='@')
			 {
				 	flag=true;
				 	break;
			 }	 		
		 }
		 if(flag)
		 {
		 	break;
		 }

	 }
	 int j=0;
//	 for(int i=pos;i<curr;i++)
//	 cout<<st[i];
//	 cout<<endl;
	 for(int i=pos;i<curr;i++,j++)
	 	 sub[j]=st[i];
	 	 sub[j]='\0';
	 if(flag)
	 return true;
	 else return false;
	 
}
void analysis()
{
	char st[256];
	freopen("input_code_t.txt","r",stdin);//read code
	//freopen("const_test.txt","r",stdin);
	while(~(scanf("%s",st)))
	{
	//	cout<<"s:"<<s<<endl;
		int len=strlen(st);
		int pos=0;
		while(pos<len)
		{
		char ch;
		ch=st[pos];
		bool status=false;
		if(isBlank(ch))
		{
			pos++;
		 } 
		 else if(isLetter(ch))
		 {
		 	status=checkNFA(NFA_Ident,Ident_status,Ident,st,pos);
		 	token[token_count]=sub;
		 	
		 	if(status)
		 	{
		 		int t=1;
		 		for(int i=0;i<=25;i++)
		 		{
		 			t=strcmp(sub,symbol[i]);
		 			if(t==0)
		 			{
		 				printf("(%10s    , %10s)\n",sub,"Key_words");
		 				token_type[token_count]= 1;
		 				token2id[token_count]=i+'a';
		 				break;
					 }
				 }
				 if(t!=0)
				 {
				 	printf("(%10s    , %10s)\n",sub,"Ident");
				 	token_type[token_count]= 2;
				 	token2id[token_count]='8';
				 }
			 }
			 else
			 {
			 	printf("(%10s    , %10s)\n",sub,"error");
			 	token_type[token_count]= 0;
			 	token2id[token_count]='0';
			 }
			 token_count++;
		 	
		 }
		 else if(isDigit(ch))
		 {
		 	status=checkNFA(NFA_Const,Const_status,Const,st,pos);
		 	token[token_count]=sub;
		 	if(status)
		 	{
		 		printf("(%10s    , %10s)\n",sub,"Const");
		 		token_type[token_count]= 3;
		 		token2id[token_count]='9';
			 }
		 	else
			 {
			 	printf("(%10s    , %10s)\n",sub,"error");
			 	token_type[token_count]= 0;
			 	token2id[token_count]='0';
			 }
			 token_count++;
		 }
		 else if(isJiefu(ch)||(st[pos]=='/'&&st[pos+1]=='/'))
		 {
		 	status=checkNFA(NFA_Jiefu,Jiefu_status,Jiefu,st,pos);
		 	token[token_count]=sub;
		 	if(status)
		 	{
		 		printf("(%10s    , %10s)\n",sub,"Jiefu");
		 		if(sub=="//") 
				 token2id[token_count]='7';
				 else token2id[token_count]=sub[0];
		 		token_type[token_count]= 5;
			 }
			 else
		  	 {
			 	printf("(%10s    , %10s)\n",sub,"error");
			 	token_type[token_count]= 0;
			 	token2id[token_count]='0';
			 }	
			 token_count++;
		 }
		 else if(isOperator(ch))
		 {
		 	status=checkNFA(NFA_Operator,Operator_status,Operator,st,pos);
		 	token[token_count]=sub;
		 	if(status)
		 	{
			 	printf("(%10s    , %10s)\n",sub,"Operator");	
			 	token_type[token_count]= 4;
			 	if(sub=="++") token2id[token_count]='1';
			 	else if(sub=="--") token2id[token_count]='2';
			 	else if(sub=="==") token2id[token_count]='3';
			 	else if(sub=="<>") token2id[token_count]='4';
			 	else if(sub=="<=") token2id[token_count]='5';
			 	else if(sub==">=") token2id[token_count]='6';
			 	else token2id[token_count]=sub[0];
			 }
		 	 else
		  	 {
			 	printf("(%10s    , %10s)\n",sub,"error");
			 	token_type[token_count]= 0;
			 	token2id[token_count]='0';
			 }
			 token_count++;
		 }
		}
	}
}
void getAllNFA()
{
	freopen("input_ident.txt","r",stdin);
	read2NFA(NFA_Ident,Ident_status,Ident_status_count,Ident,Ident_count);
	freopen("input_operator.txt","r",stdin);
	read2NFA(NFA_Operator,Operator_status,Operator_status_count,Operator,Operator_count);
	freopen("input_jiefu.txt","r",stdin);
	read2NFA(NFA_Jiefu,Jiefu_status,Jiefu_status_count,Jiefu,Jiefu_count);
	freopen("input_const.txt","r",stdin);
	read2NFA(NFA_Const,Const_status,Const_status_count,Const,Const_count);
	
}
void test(char NFA[20][70][5])
{
	for(int i=0;i<20;i++)
	{
		for( int j=0;j<70;j++)
		{
			if(NFA[i][j][0]!='\0')
			{
				cout<<i<<"( "<<j<<"　)= "; 
			}
			for(int k=0;k<5;k++)
			{
			
				if(NFA[i][j][k]!='\0')
				{
					cout<<NFA[i][j][k]<<",";
				}
				else
				break;
			}
			if(NFA[i][j][0]!='\0')
			{
				cout<<endl; 
			}
		}
	}
}

int main(){
	init();
	getAllNFA();
//freopen("output_t.txt","w",stdout);//write to outout.txt
	analysis();
	for(int i=0;i<token_count;i++)
	{
		cout<<token[i]<<": "<<token_type[i]<<endl;
	}
	//freopen("output2LL1.txt","w",stdout);
	for(int i=0;i<token_count;i++)
	{
		cout<<token2id[i];
	}
	return 0;
} 
