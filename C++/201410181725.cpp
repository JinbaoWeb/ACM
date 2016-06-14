#include <iostream>
#include <fstream>
using namespace std;
template<class T>
class TMatrix{
	T *dp;	 //ָ���ά�����ָ��
	int row; //��
	int col; //��
	static T defV; //ȱʡԪ��ֵ
protected:
	void copy(const TMatrix<T> &a){ //���βζ�������ݿ�������ǰ����
		row = a.row;
		col = a.col;
		if (a.dp == 0){		//�վ���
			return;
		}
		dp = new T[row*col];
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++)
				dp[i * col + j] = a.dp[i * col + j];
		}
	}
	void del(){		//���ն�̬�ڴ�
		if (row > 0 && col > 0)
			delete[row * col]dp;
	}
public:
	TMatrix(int r = 0, int c = 0){	 //ȱʡ���캯������ȱʡֵ��ΪԪ��ֵ
		if (r <= 0 || c <= 0){
			row = 0; //�վ���
			col = 0;
			dp = 0;
			return;
		}
		row = r;
		col = c;
		dp = new T[row * col];
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++)
				dp[i * col + j] = defV;
		}
	}
	TMatrix(const T *a, int r, int c){ //���ع��캯������һά��������ʼ��
		if (a == 0 || r <= 0 || c <= 0){
			row = 0; //�վ���
			col = 0;
			dp = 0;
			return;
		}
		row = r;
		col = c;
		dp = new T[row * col];
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++)
				dp[i * col + j] = a[i * col + j];
		}
	}
	TMatrix(const TMatrix & a){	 //�������캯��
		copy(a);
	}
	TMatrix & operator=(const TMatrix &a){ //��ֵ��������
		del();
		copy(a);
		return *this;
	}
	~TMatrix(){		//��������
		del();
	}
	int getRow()const{ return row; } //��ȡ��
	int getCol()const{ return col; } //��ȡ��
	T & elemAt(int r, int c)const{ //���±����Ԫ��
		if (r < 0 || r >= row)
			throw r;
		if (c < 0 || c >= col)
			throw c;
		return dp[r * col + c];
	}
	T & operator()(int r, int c)const{ //���±����Ԫ��,���غ�����������������±����Ԫ�أ�����Ԫ������
		return elemAt(r, c);
	}
	/****************************�����ת��**********************************/
	TMatrix<T> reverse()const{ //ת�ã����ر�ת�õľ���
		if (col == 0 || row == 0)
			return TMatrix();
		TMatrix a(col, row);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++){
				a.dp[j * row + i] = dp[i * col + j];
			}
				
		return a;
	}
	/****************************�������************************************/
	TMatrix<T> inverse()const{	//������棬���ؾ������
		TMatrix a(row,col);
		for (int i=0;i<row;i++){	//���쵥λ���� 
			for (int j=0;j<col;j++){
				if (i==j)
					a.dp[j*row+i]=1;
				else
					a.dp[j*row+i]=0;
			}
		}
			
		for (int i=0;i<row;i++){
			for (int j=0;j<row;j++){
				if (i==j)
					continue;
				double k=dp[j*row]/dp[i*row];
				for (int p=0;p<col;p++){
					dp[j*row+p]-=k*dp[i*row+p];
					a.dp[j*row+p]-=k*a.dp[i*row+p]
				}
					
			}
		}
		return a;			
	}
	/****************************����ĳ˷�**********************************/
	TMatrix<T> operator*(const TMatrix & a)const{	//�˷�����ǰ�����a�����ؽ��
		if (col == 0 || row == 0 || a.col == 0 || a.row == 0)
			return TMatrix();
		if (col != a.row)
			throw "Can not multiple";
		TMatrix b(row, a.col);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < a.col; j++)
				for (int k = 0; k < col; k++)
					b.dp[i * b.col + j] += dp[i * col + k] * a.dp[k * a.col + j];
		return b;
	}
	/****************************���������**********************************/
	TMatrix<T> operator*(T n)const{
		if (col == 0 || row == 0)
			return TMatrix();
		TMatrix a(row, col);
		for (int i = 0; i < row;i++)
			for (int j = 0; j < col; j++)
				a.dp[j*row + i] = dp[j*row + i] * n;
		return a;
	}


	static void setDef(T &def){	//�޸�ȱʡԪ��ֵ
		defV = def;
	} 
	static const T& getDef(){	//��ȡȱʡֵ
		return defV; 
	} 
};
template<class T>
T TMatrix<T>::defV; //��̬������ȱʡֵ

template<class T>
void show(const TMatrix<T> &a){		//��ʾ����ĺ��� 
	if (a.getRow() == 0 || a.getCol() == 0)
		cout << "empty matrix\n";
	for (int i = 0; i < a.getRow(); i++){
		for (int j = 0; j < a.getCol(); j++)
			cout << a(i, j) << " ";
		cout << endl;
	}
		
}
int main(){
	char file[256];
	cout << "           ###########################################\n";
	cout << "           #####           ������             ######\n";
	cout << "           #####   ϵͳ����:                    ######\n";
	cout << "           #####        1  ��������ת��       ######\n";
	cout << "           #####        2  ����������         ######\n";
	cout << "           #####        3  �������ĳ˷�       ######\n";
	cout << "           #####        4  ������������       ######\n";
	cout << "           ###########################################\n";
	int p;
	cout << "��ѡ�������������ͣ����س�������\n";
	cout << "1:�ļ����룻\n";
	cout << "2:�������룻\n";
	cout << "*********************************************************\n";
	cin >> p;
	if (p == 1){
		cout << "�����ļ�����\n";
		cin >> file;
		ifstream cin(file);
	}
	cout << "��ѡ���������ͣ����س�������\n";
	cout << "*********************************************************\n";
	cout << "1:	float\n";
	cout << "2:	int\n";
	cout << "3:	double\n";
	cout << "*********************************************************\n";
	int t,n,r,c;
	cin >> t;
	switch (t){
		case 1:{
			   float a[10000],b[1000],k;
			   cout << "��ѡ������Ҫ�����㣬���س�������\n";
			   cout << "******************************************************************\n";
			   cout << "1�������ת��\n";
			   cout << "2���������\n";
			   cout << "3������ĳ˷�\n";
			   cout << "4�����������\n";
			   cout << "5���˳�    \n";
			   cout << "******************************************************************\n";
			   cin >> n;
			   switch (n){
					case 1:{
						cout << "��������������������\n";
						cin >> r >> c;
						cout << "���������\n";
						for (int i = 0; i < r*c;i++)
								cin >> a[i];
						TMatrix<float>m1((float*)a, r, c);
						TMatrix<float>m2= m1.reverse();
						cout << "�����ת��:\n";
						show(m2);
						break;
					}
					case 2:{
						cout << "��������������������\n";
						cin >> r >> c;
						cout << "���������\n";
						for (int i = 0; i < r*c; i++)
							cin >> a[i];
						TMatrix<float>m1((float*)a, r, c);
						TMatrix<float>m2 = m1.inverse();
						cout << "������棺\n";
						show(m2);
						break;
					}
					case 3:{
						cout << "��������������������\n";
						cin >> r >> c;
						cout << "���������\n";
						for (int i = 0; i < r*c; i++)
							cin >> a[i];
						TMatrix<float>m1((float*)a, r, c);
						cout << "��������һ������\n";
						for (int i = 0; i < r*c; i++)
							cin >> b[i];
						TMatrix<float>m2((float*)b, c, r);
						TMatrix<float>m3 = m1*m2;
						cout << "����ĳˣ�\n";
						show(m3);
						break;
					}
					case 4:{
						cout << "��������������������\n";
						cin >> r >> c;
						cout << "���������\n";
						for (int i = 0; i < r*c; i++)
							cin >> a[i];
						TMatrix<float>m1((float*)a, r, c);
						cout << "������Ҫ�˵���\n";
						cin >> k;
						TMatrix<float>m2 = m1*k;
						cout << "��������ˣ�\n";
						show(m2);
						break;
					}
					case 5:{
						return 0;
					}
			   }
			   break;
		}
		case 2:{
				   int a[10000], b[1000], k;
				   cout << "��ѡ������Ҫ�����㣬���س�������\n";
				   cout << "******************************************************************\n";
				   cout << "1�������ת��\n";
				   cout << "2���������\n";
				   cout << "3������ĳ˷�\n";
				   cout << "4�����������\n";
				   cout << "5���˳�    \n";
				   cout << "******************************************************************\n";
				   cin >> n;
				   switch (n){
				   case 1:{
							  cout << "��������������������\n";
							  cin >> r >> c;
							  cout << "���������\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<int>m1((int*)a, r, c);
							  TMatrix<int>m2 = m1.reverse();
							  cout << "�����ת��:\n";
							  show(m2);
							  break;
				   }
				   case 2:{
							  cout << "��������������������\n";
							  cin >> r >> c;
							  cout << "���������\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<int>m1((int*)a, r, c);
							  TMatrix<int>m2 = m1.inverse();
							  cout << "������棺\n";
							  show(m2);
							  break;
				   }
				   case 3:{
							  cout << "��������������������\n";
							  cin >> r >> c;
							  cout << "���������\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<int>m1((int*)a, r, c);
							  cout << "��������һ������\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> b[i];
							  TMatrix<int>m2((int*)b, c, r);
							  TMatrix<int>m3 = m1*m2;
							  cout << "����ĳˣ�\n";
							  show(m3);
							  break;
				   }
				   case 4:{
							  cout << "��������������������\n";
							  cin >> r >> c;
							  cout << "���������\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<int>m1((int*)a, r, c);
							  cout << "������Ҫ�˵���\n";
							  cin >> k;
							  TMatrix<int>m2 = m1*k;
							  cout << "��������ˣ�\n";
							  show(m2);
							  break;
				   }
				   case 5:{
							  return 0;
				   }
			}
			break;
		}
		case 3:{
				   double a[10000], b[1000], k;
				   cout << "��ѡ������Ҫ�����㣬���س�������\n";
				   cout << "******************************************************************\n";
				   cout << "1�������ת��\n";
				   cout << "2���������\n";
				   cout << "3������ĳ˷�\n";
				   cout << "4�����������\n";
				   cout << "5���˳�    \n";
				   cout << "******************************************************************\n";
				   cin >> n;
				   switch (n){
				   case 1:{
							  cout << "��������������������\n";
							  cin >> r >> c;
							  cout << "���������\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<double>m1((double*)a, r, c);
							  TMatrix<double>m2 = m1.reverse();
							  cout << "�����ת��:\n";
							  show(m2);
							  break;
				   }
				   case 2:{
							  cout << "��������������������\n";
							  cin >> r >> c;
							  cout << "���������\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<double>m1((double*)a, r, c);
							  TMatrix<double>m2 = m1.inverse();
							  cout << "������棺\n";
							  show(m2);
							  break;
				   }
				   case 3:{
							  cout << "��������������������\n";
							  cin >> r >> c;
							  cout << "���������\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<double>m1((double*)a, r, c);
							  cout << "��������һ������\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> b[i];
							  TMatrix<double>m2((double*)b, c, r);
							  TMatrix<double>m3 = m1*m2;
							  cout << "����ĳˣ�\n";
							  show(m3);
							  break;
				   }
				   case 4:{
							  cout << "��������������������\n";
							  cin >> r >> c;
							  cout << "���������\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<double>m1((double*)a, r, c);
							  cout << "������Ҫ�˵���\n";
							  cin >> k;
							  TMatrix<double>m2 = m1*k;
							  cout << "��������ˣ�\n";
							  show(m2);
							  break;
				   }
				   case 5:{
							  return 0;
						  }
				   }
		}
	}
	return 0;
}
