#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define MAX 13   //最大点13
class War
{
    int plyr1,plyr2,comp1,comp2; //payer玩家牌点1,2,comp计算机牌点1,2
    static int Score;//玩者的分数，分数为0或50时游戏结束
    static int bet;//赌注大小，在5以内
    static int Loop;//总的出牌次数
  public:
    int Player1();
    int Player2();   //返回玩者第一二张牌；
    int Computer1();
    int Computer2();   //返回计算机第一二张牌；
    void Initialize();  //给玩者和计算机的牌点
    int  CheckScore();  //返回玩家分数
    void GameOver();
    int addbet();  //返回赌注
    War();  //缺省构造函数，初始化对象
    static int Increase();  //加分
    static int Decrease();  //减分
    static int Loops();  //出牌次数增加
};
int War::Score=26;
int War::bet=1;
int War::Loop=0;
int War::addbet()
{
  int n;
  YYY:cout<<"开始加注，加注不大于5"<<endl;
  cin>>n;
  if(n<=0||n>5){
    cout<<"加注超出范围，请重输入"<<endl;
  goto YYY;
 }
 else
  bet=n;
 return bet;
}
int War::Increase()  //加分,每轮赢下注的分数
{
  Score+=bet;
return  Score;
}
int War::Decrease()  //减分，每轮输下注的分数
{   Score-=bet;
return  Score;
}
int War::Loops()  //下注一次为一轮
{ Loop++;
return Loop;
}
War::War()  //构造函数，双方初始牌点都为0
{ plyr1,plyr2,comp1,comp2=0;
}
int War::Player1()
{return plyr1;}
int War::Player2()
{return plyr2;}     //返回玩者第一二张牌；
int War::Computer1()
{return comp1;}
int War::Computer2() 
{return comp2;}    //返回计算机第一二张牌；
void War::Initialize() //给玩者和计算机的牌点
{ plyr1=rand()%MAX+2;
 plyr2=rand()%MAX+2;
 comp1=rand()%MAX+2;
 comp2=rand()%MAX+2;//牌点为2-14，14点为A
}
int War::CheckScore()
{return Score;}    //返回玩家分数
void War::GameOver()  //游戏结束时显示信息
{ cout<<endl<<"游戏结束! 谢谢参与."<<endl;
 cout<<" 你用了"<<War::Loops() <<"轮."<<endl;
} 
void main()
{ War Play;
 int x;
 srand(time(NULL));
 cout<<endl<<" 准备开始!"<<endl<<endl;
 Play.Initialize();  //随机产生双方牌点
 Play.Loops();   //轮次增加
 cout<<"你的第一张牌是";
    if(Play.Player1()==11)
  cout<<"J"<<endl;
 else if(Play.Player1()==12)
  cout<<"Q"<<endl;
 else if(Play.Player1()==13)
  cout<<"K"<<endl;
 else if(Play.Player1()==14)
  cout<<"A"<<endl;
 else
  cout<<Play.Player1()<<endl;
 cout<<"你的第二张牌是";
 if(Play.Player2()==11)
  cout<<"J"<<endl;
 else if(Play.Player2()==12)
  cout<<"Q"<<endl;
 else if(Play.Player2()==13)
  cout<<"K"<<endl;
 else if(Play.Player2()==14)
  cout<<"A"<<endl;
 else
  cout<<Play.Player2()<<endl;
 cout<<"计算机第一张牌是";
 if(Play.Computer1()==11)
  cout<<"J"<<endl;
 else if(Play.Computer1()==12)
  cout<<"Q"<<endl;
 else if(Play.Computer1()==13)
  cout<<"K"<<endl;
 else if(Play.Computer1()==14)
  cout<<"A"<<endl;
 else
  cout<<Play.Computer1()<<endl;
 cout<<"计算机第二张牌是";
 if(Play.Computer2()==11)
  cout<<"J"<<endl;
 else if(Play.Computer2()==12)
  cout<<"Q"<<endl;
 else if(Play.Computer2()==13)
  cout<<"K"<<endl;
 else if(Play.Computer2()==14)
  cout<<"A"<<endl;
 else
  cout<<Play.Computer2()<<endl;
 if(Play.Player1()==Play.Player2()&&Play.Computer1()!=Play.Computer2())  //玩家对子
  Play.Increase(); 
 else if(Play.Player1()!=Play.Player2()&&Play.Computer1()==Play.Computer2())  //计算机对子
  Play.Decrease(); 
 else if(Play.Player1()+Play.Player2()>Play.Computer1()+Play.Computer2())  //玩家非对子，大于计算机
  Play.Increase(); 
 else if(Play.Player1()+Play.Player2()<Play.Computer1()+Play.Computer2())  //计算机非对子，大于玩家
  Play.Decrease(); 
 else
  cout<<" 势均力敌!"<<endl;
 Play.CheckScore();   //返回玩家分数
 cout<<endl<<"你的分数是:"<<Play.CheckScore()<<endl;
 switch (Play.CheckScore())
 { case 0:
   cout<<"你输了!"<<endl;
 Play.GameOver();break;
  case 50:
   cout<<"你赢了!"<<endl;
 Play.GameOver();break;  //分数为0或50则游戏结束
  default:
   cout<<endl<<"继续1[退出0]"<<endl;  //选择游戏是否继续进行
   cin>>x;
   if(x==1)     //若继续，递归调用主函数
    main();
   break;  //否则退出系统
 }
}
