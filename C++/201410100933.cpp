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
	printf("           #####   ��ӭ��ʹ�þ�������ϵͳ��   ######\n"); 
	printf("           #####   ϵͳ����:                    ######\n"); 
	printf("           #####      ���������������,���;    ######\n"); 
	printf("           #####      ���˾��󣻾���ת��;����   ######\n"); 
	printf("           #####      ����                      ######\n"); 
	printf("           ###########################################\n"); 
	printf("��ѡ������Ҫ�����㣬���س�������\n"); 
	printf("******************************************************************\n"); 
	printf("1���������\n"); 
	printf("2���������\n"); 
	printf("3�����˾���\n"); 
	printf("4������ת��\n"); 
	printf("5�������  \n"); 
	printf("6���˳�    \n"); 
	printf("******************************************************************\n"); 
	int x; 
	scanf("%d",&x); 
	switch (x) 
	{ 
	case 1: 
		{ 
			printf("���������A������������(�ö��Ÿ���):"); 
			scanf("%d,%d",&i,&j); 
			printf("���������B������������(�ö��Ÿ���):") ; 
			scanf("%d,%d",&m,&n); 
			if(i!=m||j!=n) 
				printf("***�Բ����������������������ӣ�������.***\n"); 
			else printf("���������A:\n"); 
			for(p=0;p<i;p++) 
				for(q=0;q<j;q++) 
					scanf("%f",&A[p][q]); 
				printf("�������A��\n"); 
				for(p=0;p<i;p++) 
					for(q=0;q<j;q++) 
					{  
						printf("%10.2f",A[p][q]); 
						if((q+1)%j==0) 
							printf("\n");    
					} 
					printf("���������B��\n"); 
					for(p=0;p<i;p++) 
						for(q=0;q<j;q++) 
							scanf("%f",&B[p][q]);
						printf("�������B��\n"); 
						for(p=0;p<i;p++) 
							for(q=0;q<j;q++) 
							{  
								printf("%10.2f",B[p][q]); 
								if((q+1)%j==0) 
									printf("\n");    
							} 
							printf("����A+����BΪ:\n");     //��������������� 
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
			printf("���������A������������(�ö��Ÿ���):"); 
			scanf("%d,%d",&i,&j); 
			printf("���������B������������(�ö��Ÿ���):") ; 
			scanf("%d,%d",&m,&n); 
			if(i!=m||j!=n) 
				printf("***�Բ�������������������������������.***\n"); 
			else printf("���������A:\n"); 
			for(p=0;p<i;p++) 
				for(q=0;q<j;q++) 
					scanf("%f",&A[p][q]); 
				printf("�������A:\n"); 
				for(p=0;p<i;p++) 
					for(q=0;q<j;q++) 
					{  
						printf("%10.2f",A[p][q]); 
						if((q+1)%j==0) 
							printf("\n");    
					} 
					printf("���������B��\n"); 
					for(p=0;p<i;p++) 
						for(q=0;q<j;q++) 
							scanf("%f",&B[p][q]); 
						printf("����ھ���B:\n"); 
						for(p=0;p<i;p++) 
							for(q=0;q<j;q++) 
							{  
								printf("%10.2f",B[p][q]); 
								if((q+1)%j==0) 
									printf("\n");    
							} 
							printf("����A-����BΪ��\n");        //��������������� 
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
			printf("���������A������������(�ö��Ÿ���):"); 
			scanf("%d,%d",&i,&j); 
			printf("���������A\n"); 
			for(p=0;p<i;p++) 
				for(q=0;q<j;q++) 
					scanf("%f",&A[p][q]); 
				printf("�������A\n"); 
				for(p=0;p<i;p++) 
					for(q=0;q<j;q++) 
					{  
						printf("%10.2f",A[p][q]); 
						if((q+1)%j==0) 
							printf("\n");    
					}   
					printf("������һ��ʵ��:\n"); 
					scanf("%f",&k); 
					for(p=0;p<i;p++)                       //���˾��� 
						
						for(q=0;q<j;q++) 
							B[p][q]=k*A[p][q]; 
						printf("���k�˾���A�Ľ��\n"); 
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
			printf("���������A������������(�ö��Ÿ���):"); 
			scanf("%d,%d",&i,&j); 
			printf("���������A:\n"); 
			for(p=0;p<i;p++) 
				for(q=0;q<j;q++) 
					scanf("%f",&A[p][q]); 
				printf("�������A\n"); 
				for(p=0;p<i;p++) 
					for(q=0;q<j;q++) 
					{  
						printf("%10.2f",A[p][q]); 
						if((q+1)%j==0) 
							printf("\n");    
					} 
					for(p=0;p<i;p++)                    //ת�� 
						for(q=0;q<j;q++) 
							B[q][p]=A[p][q]; 
						printf("�������A��ת�þ���:\n"); 
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
		printf("���뷽���ά����\n");     //�����뷽�󣬼��к�����ȵľ��� 
		scanf("%d",&T); 
		printf("���������:\n"); 
		for(i=0;i<T;i++)  
			for (j=0;j<T;j++)  
				scanf("%f",&b[i][j]);  
			printf("ԭ����Ϊ��\n");  
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
					printf("�Բ���������ľ���û����������������롣\n"); 
				else    
				{ 
					for(i=0;i<T;i++)  
						for(j=0;j<T;j++) 
							b[i][j]=a[i][j+T]; 
						printf("�����Ϊ��\n");  
						for (i=0;i<T;i++)  
						{  
							for (j=0;j<T;j++)    
								printf("%10.3f",b[i][j]);  
							printf("\n");  
						}  
				};break;  
	case 6:;break; 
    default: 
		printf("\n********��ѡ�����������.********\n"); 
		break; 
} 
printf("#########�ٴθ�л��ʹ�ñ�ϵͳ,������죡############\n");
 }

