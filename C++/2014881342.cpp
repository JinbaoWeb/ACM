#include<stdio.h>
 #include<string.h>
 void inchess(int x,int y,int *chess)
 {
 int i;
 while(y--)
 {
 switch (x)
 {
 case 1:chess[1]++,chess[2]++,chess[3]++,chess[4]++,chess[5]++,chess[9]++,chess[13]++;break;
 case 2:chess[1]++,chess[2]++,chess[3]++,chess[4]++,chess[6]++,chess[10]++,chess[14]++;;break;
 case 3:chess[1]++,chess[2]++,chess[3]++,chess[4]++,chess[7]++,chess[11]++,chess[15]++;;break;
 case 4:chess[1]++,chess[2]++,chess[3]++,chess[4]++,chess[8]++,chess[12]++,chess[16]++;;break;
 case 6:chess[5]++,chess[6]++,chess[7]++,chess[8]++,chess[2]++,chess[10]++,chess[14]++;;break;
 case 7:chess[5]++,chess[6]++,chess[7]++,chess[8]++,chess[3]++,chess[11]++,chess[15]++;;break;
 case 5:chess[5]++,chess[6]++,chess[7]++,chess[8]++,chess[1]++,chess[9]++,chess[13]++;;break;
 case 8:chess[5]++,chess[6]++,chess[7]++,chess[8]++,chess[4]++,chess[12]++,chess[16]++;;break;
 case 9:chess[9]++,chess[10]++,chess[11]++,chess[12]++,chess[1]++,chess[5]++,chess[13]++;;break;
 case 10:chess[9]++,chess[10]++,chess[11]++,chess[12]++,chess[2]++,chess[6]++,chess[14]++;;break;
 case 11:chess[9]++,chess[10]++,chess[11]++,chess[12]++,chess[3]++,chess[7]++,chess[15]++;;break;
 case 12:chess[9]++,chess[10]++,chess[11]++,chess[12]++,chess[4]++,chess[8]++,chess[16]++;;break;
 case 13:chess[13]++,chess[14]++,chess[15]++,chess[16]++,chess[1]++,chess[5]++,chess[9]++;;break;
 case 14:chess[13]++,chess[14]++,chess[15]++,chess[16]++,chess[2]++,chess[6]++,chess[10]++;;break;
 case 15:chess[13]++,chess[14]++,chess[15]++,chess[16]++,chess[3]++,chess[7]++,chess[11]++;;break;
 case 16:chess[13]++,chess[14]++,chess[15]++,chess[16]++,chess[4]++,chess[8]++,chess[12]++;;break;
 }
 for(i=0;i<=16;i++)
 while(chess[i]=2)
 chess[i]=chess[i]-2;
 }
 }
 void rechess(int x,int y,int *chess)
 {
 int i;
 while(y--)
 {
 for(i=0;i<=16;i++)
 if(chess[i]==0)
 chess[i]=2;
 switch (x)
 {
 case 1:chess[1]--,chess[2]--,chess[3]--,chess[4]--,chess[5]--,chess[9]--,chess[13]--;break;
 case 2:chess[1]--,chess[2]--,chess[3]--,chess[4]--,chess[6]--,chess[10]--,chess[14]--;;break;
 case 3:chess[1]--,chess[2]--,chess[3]--,chess[4]--,chess[7]--,chess[11]--,chess[15]--;;break;
 case 4:chess[1]--,chess[2]--,chess[3]--,chess[4]--,chess[8]--,chess[12]--,chess[16]--;;break;
 case 6:chess[5]--,chess[6]--,chess[7]--,chess[8]--,chess[2]--,chess[10]--,chess[14]--;;break;
 case 7:chess[5]--,chess[6]--,chess[7]--,chess[8]--,chess[3]--,chess[11]--,chess[15]--;;break;
 case 5:chess[5]--,chess[6]--,chess[7]--,chess[8]--,chess[1]--,chess[9]--,chess[13]--;;break;
 case 8:chess[5]--,chess[6]--,chess[7]--,chess[8]--,chess[4]--,chess[12]--,chess[16]--;;break;
 case 9:chess[9]--,chess[10]--,chess[11]--,chess[12]--,chess[1]--,chess[5]--,chess[13]--;;break;
 case 10:chess[9]--,chess[10]--,chess[11]--,chess[12]--,chess[2]--,chess[6]--,chess[14]--;;break;
 case 11:chess[9]--,chess[10]--,chess[11]--,chess[12]--,chess[3]--,chess[7]--,chess[15]--;;break;
 case 12:chess[9]--,chess[10]--,chess[11]--,chess[12]--,chess[4]--,chess[8]--,chess[16]--;;break;
 case 13:chess[13]--,chess[14]--,chess[15]--,chess[16]--,chess[1]--,chess[5]--,chess[9]--;;break;
 case 14:chess[13]--,chess[14]--,chess[15]--,chess[16]--,chess[2]--,chess[6]--,chess[10]--;;break;
 case 15:chess[13]--,chess[14]--,chess[15]--,chess[16]--,chess[3]--,chess[7]--,chess[11]--;;break;
 case 16:chess[13]--,chess[14]--,chess[15]--,chess[16]--,chess[4]--,chess[8]--,chess[12]--;;break;
 }
 }
 }
 int main()
 {
 char ch;
 int chess[17]={0},num[17]={0},max=20,total,ss[17]={0};;
 int a=1,b=2,c=3,d=4,e=5,f=6,g=7,h=8,i=9,j=10,k=11,l=12,m=13,n=14,o=15,p=16,z=1,x;
 while(scanf("%c",&ch))
 {
 if(ch=='+')
 {
 chess[z]=1;
 z++;
 }
 else if(ch=='-')
 {
 chess[z]=0;
 z++;
 }
 if(z==17)
 break;
 }
 for(num[1]=0;num[1]<2;num[1]++)
 {
 inchess(a,num[1],chess);
 for(num[2]=0;num[2]<2;num[2]++)
 {
 inchess(b,num[2],chess);
 for(num[3]=0;num[3]<2;num[3]++)
 {
 inchess(c,num[3],chess);
 for(num[4]=0;num[4]<2;num[4]++)
 {
 inchess(d,num[4],chess);
 for(num[5]=0;num[5]<2;num[5]++)
 {
 inchess(e,num[5],chess);
 for(num[6]=0;num[6]<2;num[6]++)
 {
 inchess(f,num[6],chess);
 for(num[7]=0;num[7]<2;num[7]++)
 {
 inchess(g,num[7],chess);
 for(num[8]=0;num[8]<2;num[8]++)
 {
 inchess(h,num[8],chess);
 for(num[9]=0;num[9]<2;num[9]++)
 {
 inchess(i,num[9],chess);
 for(num[10]=0;num[10]<2;num[10]++)
 {
 inchess(j,num[10],chess);
 for(num[11]=0;num[11]<2;num[11]++)
 {
 inchess(k,num[11],chess);
 for(num[12]=0;num[12]<2;num[12]++)
 {
 inchess(l,num[12],chess);
 for(num[13]=0;num[13]<2;num[13]++)
 {
 inchess(m,num[13],chess);
 for(num[14]=0;num[14]<2;num[14]++)
 {
 inchess(n,num[14],chess);
 for(num[15]=0;num[15]<2;num[15]++)
 {
 inchess(o,num[15],chess);
 for(num[16]=0;num[16]<2;num[16]++)
 {
 inchess(p,num[16],chess);
 if(chess[1]==0&&chess[2]==0&&chess[3]==0&&chess[4]==0&&chess[5]==0&&chess[6]==0&&chess[7]==0&&chess[8]==0&&chess[9]==0&&chess[10]==0&&chess[11]==0&&chess[12]==0&&chess[13]==0&&chess[14]==0&&chess[15]==0&&chess[16]==0)
 {
 total=num[1]+num[2]+num[3]+num[4]+num[5]+num[6]+num[7]+num[8]+num[9]+num[10]+num[11]+num[12]+num[13]+num[14]+num[15]+num[16];
 if(total<max)
 {
 for(x=1;x<=16;x++)
 ss[x]=num[x];
 max=total;
 }
 }
 rechess(p,num[16],chess);
 }
 rechess(o,num[15],chess);
 }
 rechess(n,num[14],chess);
 }
 rechess(m,num[13],chess);
 }
 rechess(l,num[12],chess);
 }
 rechess(k,num[11],chess);
 }
 rechess(j,num[10],chess);
 }
 rechess(i,num[9],chess);
 }
 rechess(h,num[8],chess);
 }
 rechess(g,num[7],chess);
 }
 rechess(f,num[6],chess);
 }
 rechess(e,num[5],chess);
 }
 rechess(d,num[4],chess);
 }
 rechess(c,num[3],chess);
 }
 rechess(b,num[2],chess);
 }
 rechess(a,num[1],chess);
 }
if(max==20)
 	printf("Impossible\n");
else
	 printf("%d\n",max);
 for(x=1;x<=16;x++)
 {
 if(ss[x]!=0)
 {
 if(x%4==0)
 printf("%d %d\n",x/4,4);
 else
 printf("%d %d\n",1+x/4,x%4);
 }
 }
 return 0;
 }
