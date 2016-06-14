#include <iostream>
#include <fstream>
using namespace std;
template<class T>
class TMatrix{
	T *dp;	 //指向二维数组的指针
	int row; //行
	int col; //列
	static T defV; //缺省元素值
protected:
	void copy(const TMatrix<T> &a){ //将形参对象的数据拷贝给当前对象
		row = a.row;
		col = a.col;
		if (a.dp == 0){		//空矩阵
			return;
		}
		dp = new T[row*col];
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++)
				dp[i * col + j] = a.dp[i * col + j];
		}
	}
	void del(){		//回收动态内存
		if (row > 0 && col > 0)
			delete[row * col]dp;
	}
public:
	TMatrix(int r = 0, int c = 0){	 //缺省构造函数，用缺省值作为元素值
		if (r <= 0 || c <= 0){
			row = 0; //空矩阵
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
	TMatrix(const T *a, int r, int c){ //重载构造函数，用一维数组来初始化
		if (a == 0 || r <= 0 || c <= 0){
			row = 0; //空矩阵
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
	TMatrix(const TMatrix & a){	 //拷贝构造函数
		copy(a);
	}
	TMatrix & operator=(const TMatrix &a){ //赋值操作函数
		del();
		copy(a);
		return *this;
	}
	~TMatrix(){		//析构函数
		del();
	}
	int getRow()const{ return row; } //读取行
	int getCol()const{ return col; } //读取列
	T & elemAt(int r, int c)const{ //按下标访问元素
		if (r < 0 || r >= row)
			throw r;
		if (c < 0 || c >= col)
			throw c;
		return dp[r * col + c];
	}
	T & operator()(int r, int c)const{ //按下标访问元素,重载函数调用运算符，按下标访问元素，返回元素引用
		return elemAt(r, c);
	}
	/****************************矩阵的转置**********************************/
	TMatrix<T> reverse()const{ //转置，返回被转置的矩阵
		if (col == 0 || row == 0)
			return TMatrix();
		TMatrix a(col, row);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++){
				a.dp[j * row + i] = dp[i * col + j];
			}
				
		return a;
	}
	/****************************矩阵的逆************************************/
	TMatrix<T> inverse()const{	//矩阵的逆，返回矩阵的逆
		TMatrix a(row,col);
		for (int i=0;i<row;i++){	//构造单位矩阵 
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
	/****************************矩阵的乘法**********************************/
	TMatrix<T> operator*(const TMatrix & a)const{	//乘法，当前矩阵乘a，返回结果
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
	/****************************矩阵的数乘**********************************/
	TMatrix<T> operator*(T n)const{
		if (col == 0 || row == 0)
			return TMatrix();
		TMatrix a(row, col);
		for (int i = 0; i < row;i++)
			for (int j = 0; j < col; j++)
				a.dp[j*row + i] = dp[j*row + i] * n;
		return a;
	}


	static void setDef(T &def){	//修改缺省元素值
		defV = def;
	} 
	static const T& getDef(){	//读取缺省值
		return defV; 
	} 
};
template<class T>
T TMatrix<T>::defV; //静态变量，缺省值

template<class T>
void show(const TMatrix<T> &a){		//显示结果的函数 
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
	cout << "           #####           矩阵函数             ######\n";
	cout << "           #####   系统功能:                    ######\n";
	cout << "           #####        1  计算矩阵的转置       ######\n";
	cout << "           #####        2  计算矩阵的逆         ######\n";
	cout << "           #####        3  计算矩阵的乘法       ######\n";
	cout << "           #####        4  计算矩阵的数乘       ######\n";
	cout << "           ###########################################\n";
	int p;
	cout << "请选择数据输入类型，按回车键结束\n";
	cout << "1:文件输入；\n";
	cout << "2:键盘输入；\n";
	cout << "*********************************************************\n";
	cin >> p;
	if (p == 1){
		cout << "输入文件名：\n";
		cin >> file;
		ifstream cin(file);
	}
	cout << "请选择数据类型，按回车键结束\n";
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
			   cout << "请选择您需要的运算，按回车键结束\n";
			   cout << "******************************************************************\n";
			   cout << "1，矩阵的转置\n";
			   cout << "2，矩阵的逆\n";
			   cout << "3，矩阵的乘法\n";
			   cout << "4，矩阵的数乘\n";
			   cout << "5，退出    \n";
			   cout << "******************************************************************\n";
			   cin >> n;
			   switch (n){
					case 1:{
						cout << "请输入矩阵的行数和列数\n";
						cin >> r >> c;
						cout << "请输入矩阵\n";
						for (int i = 0; i < r*c;i++)
								cin >> a[i];
						TMatrix<float>m1((float*)a, r, c);
						TMatrix<float>m2= m1.reverse();
						cout << "矩阵的转置:\n";
						show(m2);
						break;
					}
					case 2:{
						cout << "请输入矩阵的行数和列数\n";
						cin >> r >> c;
						cout << "请输入矩阵\n";
						for (int i = 0; i < r*c; i++)
							cin >> a[i];
						TMatrix<float>m1((float*)a, r, c);
						TMatrix<float>m2 = m1.inverse();
						cout << "矩阵的逆：\n";
						show(m2);
						break;
					}
					case 3:{
						cout << "请输入矩阵的行数和列数\n";
						cin >> r >> c;
						cout << "请输入矩阵\n";
						for (int i = 0; i < r*c; i++)
							cin >> a[i];
						TMatrix<float>m1((float*)a, r, c);
						cout << "请输入另一个矩阵\n";
						for (int i = 0; i < r*c; i++)
							cin >> b[i];
						TMatrix<float>m2((float*)b, c, r);
						TMatrix<float>m3 = m1*m2;
						cout << "矩阵的乘：\n";
						show(m3);
						break;
					}
					case 4:{
						cout << "请输入矩阵的行数和列数\n";
						cin >> r >> c;
						cout << "请输入矩阵\n";
						for (int i = 0; i < r*c; i++)
							cin >> a[i];
						TMatrix<float>m1((float*)a, r, c);
						cout << "请输入要乘的数\n";
						cin >> k;
						TMatrix<float>m2 = m1*k;
						cout << "矩阵的数乘：\n";
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
				   cout << "请选择您需要的运算，按回车键结束\n";
				   cout << "******************************************************************\n";
				   cout << "1，矩阵的转置\n";
				   cout << "2，矩阵的逆\n";
				   cout << "3，矩阵的乘法\n";
				   cout << "4，矩阵的数乘\n";
				   cout << "5，退出    \n";
				   cout << "******************************************************************\n";
				   cin >> n;
				   switch (n){
				   case 1:{
							  cout << "请输入矩阵的行数和列数\n";
							  cin >> r >> c;
							  cout << "请输入矩阵\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<int>m1((int*)a, r, c);
							  TMatrix<int>m2 = m1.reverse();
							  cout << "矩阵的转置:\n";
							  show(m2);
							  break;
				   }
				   case 2:{
							  cout << "请输入矩阵的行数和列数\n";
							  cin >> r >> c;
							  cout << "请输入矩阵\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<int>m1((int*)a, r, c);
							  TMatrix<int>m2 = m1.inverse();
							  cout << "矩阵的逆：\n";
							  show(m2);
							  break;
				   }
				   case 3:{
							  cout << "请输入矩阵的行数和列数\n";
							  cin >> r >> c;
							  cout << "请输入矩阵\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<int>m1((int*)a, r, c);
							  cout << "请输入另一个矩阵\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> b[i];
							  TMatrix<int>m2((int*)b, c, r);
							  TMatrix<int>m3 = m1*m2;
							  cout << "矩阵的乘：\n";
							  show(m3);
							  break;
				   }
				   case 4:{
							  cout << "请输入矩阵的行数和列数\n";
							  cin >> r >> c;
							  cout << "请输入矩阵\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<int>m1((int*)a, r, c);
							  cout << "请输入要乘的数\n";
							  cin >> k;
							  TMatrix<int>m2 = m1*k;
							  cout << "矩阵的数乘：\n";
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
				   cout << "请选择您需要的运算，按回车键结束\n";
				   cout << "******************************************************************\n";
				   cout << "1，矩阵的转置\n";
				   cout << "2，矩阵的逆\n";
				   cout << "3，矩阵的乘法\n";
				   cout << "4，矩阵的数乘\n";
				   cout << "5，退出    \n";
				   cout << "******************************************************************\n";
				   cin >> n;
				   switch (n){
				   case 1:{
							  cout << "请输入矩阵的行数和列数\n";
							  cin >> r >> c;
							  cout << "请输入矩阵\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<double>m1((double*)a, r, c);
							  TMatrix<double>m2 = m1.reverse();
							  cout << "矩阵的转置:\n";
							  show(m2);
							  break;
				   }
				   case 2:{
							  cout << "请输入矩阵的行数和列数\n";
							  cin >> r >> c;
							  cout << "请输入矩阵\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<double>m1((double*)a, r, c);
							  TMatrix<double>m2 = m1.inverse();
							  cout << "矩阵的逆：\n";
							  show(m2);
							  break;
				   }
				   case 3:{
							  cout << "请输入矩阵的行数和列数\n";
							  cin >> r >> c;
							  cout << "请输入矩阵\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<double>m1((double*)a, r, c);
							  cout << "请输入另一个矩阵\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> b[i];
							  TMatrix<double>m2((double*)b, c, r);
							  TMatrix<double>m3 = m1*m2;
							  cout << "矩阵的乘：\n";
							  show(m3);
							  break;
				   }
				   case 4:{
							  cout << "请输入矩阵的行数和列数\n";
							  cin >> r >> c;
							  cout << "请输入矩阵\n";
							  for (int i = 0; i < r*c; i++)
								  cin >> a[i];
							  TMatrix<double>m1((double*)a, r, c);
							  cout << "请输入要乘的数\n";
							  cin >> k;
							  TMatrix<double>m2 = m1*k;
							  cout << "矩阵的数乘：\n";
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
