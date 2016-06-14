#include<stdio.h> 
#define M 20 
#define N 20 
float  A[M][N]; 
float  B[M][N]; 
float  C[M][N]; 
int i,j,m,n,p,q; 
float  y=1.0; 
int main() 
{ 
	printf("           ###########################################\n"); 
	printf("           #####   欢迎您使用矩阵函数包系统。   ######\n"); 
	printf("           #####   系统功能:                    ######\n"); 
	printf("           #####      计算两个矩阵相加,相减;    ######\n"); 
	printf("           #####      数乘矩阵；矩阵转置;求逆   ######\n"); 
	printf("           #####      矩阵                      ######\n"); 
	printf("           ###########################################\n"); 
	printf("请选择您需要的运算，按回车键结束\n"); 
	printf("******************************************************************\n"); 
	printf("1，矩阵相加\n"); 
	printf("2，矩阵相减\n"); 
	printf("3，数乘矩阵\n"); 
	printf("4，矩阵转置\n"); 
	printf("5，逆矩阵  \n"); 
	printf("6，退出    \n"); 
	printf("******************************************************************\n"); 
	int x; 
	scanf("%d",&x); 
	switch (x) 
	{ 
	case 1: 
		{ 
			printf("请输入矩阵A的行数和列数(用逗号隔开):"); 
			scanf("%d,%d",&i,&j); 
			printf("请输入矩阵B的行数和列数(用逗号隔开):") ; 
			scanf("%d,%d",&m,&n); 
			if(i!=m||j!=n) 
				printf("***对不起，您输入的两个矩阵不能相加，请重试.***\n"); 
			else printf("请输入矩阵A:\n"); 
			for(p=0;p<i;p++) 
				for(q=0;q<j;q++) 
					scanf("%f",&A[p][q]); 
				printf("输出矩阵A：\n"); 
				for(p=0;p<i;p++) 
					for(q=0;q<j;q++) 
					{  
						printf("%10.2f",A[p][q]); 
						if((q+1)%j==0) 
							printf("\n");    
					} 
					printf("请输入矩阵B：\n"); 
					for(p=0;p<i;p++) 
						for(q=0;q<j;q++) 
							scanf("%f",&B[p][q]);
						printf("输出矩阵B：\n"); 
						for(p=0;p<i;p++) 
							for(q=0;q<j;q++) 
							{  
								printf("%10.2f",B[p][q]); 
								if((q+1)%j==0) 
									printf("\n");    
							} 
							printf("矩阵A+矩阵B为:\n");     //计算两个矩阵相加 
							for(p=0;p<i;p++) 
								for(q=0;q<j;q++) 
									C[p][q]=A[p][q]+B[p][q]; 
								for(p=0;p<i;p++) 
									for(q=0;q<j;q++) 
									{ 
										printf("%10.2f",C[p][q]); 
										if((q+1)%j==0) 
											printf("\n"); 
									} 
		};break;  
	case 2: 
		{ 
			printf("请输入矩阵A的行数和列数(用逗号隔开):"); 
			scanf("%d,%d",&i,&j); 
			printf("请输入矩阵B的行数和列数(用逗号隔开):") ; 
			scanf("%d,%d",&m,&n); 
			if(i!=m||j!=n) 
				printf("***对不起，您输入的两个矩阵不能相减，请重试.***\n"); 
			else printf("请输入矩阵A:\n"); 
			for(p=0;p<i;p++) 
				for(q=0;q<j;q++) 
					scanf("%f",&A[p][q]); 
				printf("输出矩阵A:\n"); 
				for(p=0;p<i;p++) 
					for(q=0;q<j;q++) 
					{  
						printf("%10.2f",A[p][q]); 
						if((q+1)%j==0) 
							printf("\n");    
					} 
					printf("请输入矩阵B：\n"); 
					for(p=0;p<i;p++) 
						for(q=0;q<j;q++) 
							scanf("%f",&B[p][q]); 
						printf("输出第矩阵B:\n"); 
						for(p=0;p<i;p++) 
							for(q=0;q<j;q++) 
							{  
								printf("%10.2f",B[p][q]); 
								if((q+1)%j==0) 
									printf("\n");    
							} 
							printf("矩阵A-矩阵B为：\n");        //计算两个矩阵相减 
							for(p=0;p<i;p++) 
								for(q=0;q<j;q++) 
									C[p][q]=A[p][q]-B[p][q]; 
								for(p=0;p<i;p++) 
									for(q=0;q<j;q++) 
									{ 
										printf("%10.2f",C[p][q]); 
										if((q+1)%j==0) 
											printf("\n"); 
									} 
		};break;  
	case 3: 
		
		{ 
			float k; 
			printf("请输入矩阵A的行数和列数(用逗号隔开):"); 
			scanf("%d,%d",&i,&j); 
			printf("请输入矩阵A\n"); 
			for(p=0;p<i;p++) 
				for(q=0;q<j;q++) 
					scanf("%f",&A[p][q]); 
				printf("输出矩阵A\n"); 
				for(p=0;p<i;p++) 
					for(q=0;q<j;q++) 
					{  
						printf("%10.2f",A[p][q]); 
						if((q+1)%j==0) 
							printf("\n");    
					}   
					printf("请输入一个实数:\n"); 
					scanf("%f",&k); 
					for(p=0;p<i;p++)                       //数乘矩阵 
						
						for(q=0;q<j;q++) 
							B[p][q]=k*A[p][q]; 
						printf("输出k乘矩阵A的结果\n"); 
						for(p=0;p<i;p++) 
							for(q=0;q<j;q++) 
							{  
								printf("%10.2f",B[p][q]); 
								if((q+1)%j==0) 
									printf("\n");    
							} 
		};break;  
	case 4: 
		
		{ 
			printf("请输入矩阵A的行数和列数(用逗号隔开):"); 
			scanf("%d,%d",&i,&j); 
			printf("请输入矩阵A:\n"); 
			for(p=0;p<i;p++) 
				for(q=0;q<j;q++) 
					scanf("%f",&A[p][q]); 
				printf("输出矩阵A\n"); 
				for(p=0;p<i;p++) 
					for(q=0;q<j;q++) 
					{  
						printf("%10.2f",A[p][q]); 
						if((q+1)%j==0) 
							printf("\n");    
					} 
					for(p=0;p<i;p++)                    //转置 
						for(q=0;q<j;q++) 
							B[q][p]=A[p][q]; 
						printf("输出矩阵A的转置矩阵:\n"); 
						for(p=0;p<j;p++) 
							for(q=0;q<i;q++) 
							{  
								printf("%10.2f",B[p][q]); 
								if((q+1)%i==0) 
									printf("\n"); 
							} 
		} 
		;break;  
	case 5:   
		float a[M][2*M];  
		float b[N][2*N];  
		float t,x;  
		int k,T;  
		printf("输入方阵的维数：\n");     //请输入方阵，即行和列相等的矩阵。 
		scanf("%d",&T); 
		printf("请输入矩阵:\n"); 
		for(i=0;i<T;i++)  
			for (j=0;j<T;j++)  
				scanf("%f",&b[i][j]);  
			printf("原矩阵为：\n");  
			for (i=0;i<T;i++)  
			{  
				for (j=0;j<T;j++)    
					printf("%10.3f",b[i][j]);  
				printf("\n");  
			} 
			for(i=0;i<T;i++)  
				for(j=0;j<(2*T);j++)  
				{ if (j<T)   
				a[i][j]=b[i][j];  
				else if (j==T+i)   
					a[i][j]=1.0;  
				else  
					a[i][j]=0.0;  
				} 
				for(i=0;i<T;i++) 
				{ 
					for(k=0;k<T;k++) 
					{ 
						if(k!=i) 
						{ 
							t=a[k][i]/a[i][i]; 
							for(j=0;j<(2*T);j++) 
							{ 
								x=a[i][j]*t; 
								a[k][j]=a[k][j]-x; 
							} 
						} 
					} 
				} 
				for(i=0;i<T;i++) 
				{ 
					t=a[i][i]; 
					for(j=0;j<(2*T);j++) 
						a[i][j]=a[i][j]/t; 
				} 
				
                for(i=0;i<T;i++)  
					y=y*a[i][i]; 
				if(y==0) 
					printf("对不起，您输入的矩阵没有逆矩阵，请重新输入。\n"); 
				else    
				{ 
					for(i=0;i<T;i++)  
						for(j=0;j<T;j++) 
							b[i][j]=a[i][j+T]; 
						printf("逆矩阵为：\n");  
						for (i=0;i<T;i++)  
						{  
							for (j=0;j<T;j++)    
								printf("%10.3f",b[i][j]);  
							printf("\n");  
						}  
				};break;  
	case 6:;break; 
    default: 
		printf("\n********您选择错误，请重试.********\n"); 
		break; 
} 
printf("#########再次感谢您使用本系统,合作愉快！############\n");
 }

