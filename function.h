#pragma once
#include <iostream>
#include "Matrix.h"
//默认构造函数
template<class T>
Matrix<T>::Matrix()
{
	row = 0;
	col = 0;
	mat = NULL;
}
//构造函数
template<class T>
Matrix<T>::Matrix(int r, int c)
{
	row = r;
	col = c;
	mat = new T * [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new T[col];
	}
}
//拷贝构造函数
template<class T>
Matrix<T>::Matrix(const Matrix<T>& m)
{
	row = m.row;
	col = m.col;
	mat = new T * [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new T[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mat[i][j] = m.mat[i][j];
		}
	}
}
//析构函数
template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}
//获取行数
template<class T>
int Matrix<T>::getRow()
{
	return row;
}
//获取列数
template<class T>
int Matrix<T>::getCol()
{
	return col;
}
//单位矩阵
template<class T>
Matrix<T> Matrix<T>::ones()
{
	if (row != col)
	{
		cout << "Error!" << endl;
		cout << "不是方阵，无法求单位矩阵" << endl;
		return *this;
	}
	Matrix<T> temp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == j)
			{
				temp.mat[i][j] = 1;
			}
			else
			{
				temp.mat[i][j] = 0;
			}
		}
	}
	return temp;
}
//重载
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//重载[]
template<class T>
T* Matrix<T>::operator[](int i)
{
	return mat[i];
}
//赋值运算符重载
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m)
{
	for (int i = 0; i < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
	row = m.row;
	col = m.col;
	mat = new T * [row];
	for (int i = 0; i < row; i++)
	{
		mat[i] = new T[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mat[i][j] = m.mat[i][j];
		}
	}
	return *this;
}
//加法运算符重载
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m)
{
	if (row != m.row || col != m.col)
	{
		cout << "Error!" << endl;
		cout << "维数不同，无法相加" << endl;
		return *this;
	}
	Matrix<T> temp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] = mat[i][j] + m.mat[i][j];
		}
	}
	return temp;
}
//减法运算符重载
template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m)
{
	if (row != m.row || col != m.col)
	{
		cout << "Error!" << endl;
		cout << "维数不同，无法相减" << endl;
		return *this;
	}
	Matrix<T> temp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] = mat[i][j] - m.mat[i][j];
		}
	}
	return temp;
}
//乘法运算符重载
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m)
{
	if (col != m.row)
	{
		cout << "Error!" << endl;
		cout << "维数不同，无法相乘" << endl;
		return *this;
	}
	Matrix<T> temp(row, m.col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			temp.mat[i][j] = 0;
			for (int k = 0; k < col; k++)
			{
				temp.mat[i][j] += mat[i][k] * m.mat[k][j];//横竖乘
			}
		}
	}
	return temp;
}
//除法运算符重载
template<class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& m)
{
	if (col != m.row)
	{
		cout << "Error!" << endl;
		cout << "维数不同，无法相除" << endl;
		return *this;
	}
	Matrix<T> temp(row, m.col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			temp.mat[i][j] = 0;
			for (int k = 0; k < col; k++)
			{
				temp.mat[i][j] += mat[i][k] / m.mat[k][j];
			}
		}
	}
	return temp;
}
//负号运算符重载
template<class T>
Matrix<T> Matrix<T>::operator-()
{
	Matrix<T> temp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] = -mat[i][j];
		}
	}
	return temp;
}
//重载输出
template<class U>
ostream& operator<<(ostream& os, const Matrix<U>& m)
{
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			os << m.mat[i][j] << " ";
		}
		os << endl;
	}

	return os;
}
//重载输入
template<class U>
istream& operator>>(istream& is, Matrix<U>& m)
{
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			is >> m.mat[i][j];
		}
	}
	return is;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//矩阵与标量(单个数字)加，减，乘，除
template<class T>
Matrix<T> Matrix<T>::add(T t)
{
	Matrix<T> temp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] = mat[i][j] + t;
		}
	}
	return temp;
}
template<class T>
Matrix<T> Matrix<T>::sub(T t)
{
	Matrix<T> temp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] = mat[i][j] - t;
		}
	}
	return temp;
}
template<class T>
Matrix<T> Matrix<T>::mul(T t)
{
	Matrix<T> temp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] = mat[i][j] * t;
		}
	}
	return temp;
}
//矩阵除法
template<class T>
Matrix<T> Matrix<T>::div(T t)
{
	Matrix<T> temp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] = mat[i][j] / t;
		}
	}
	return temp;
}
//矩阵转置
template<class T>
Matrix<T> Matrix<T>::transpose()
{
	Matrix<T> temp(col, row);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[j][i] = mat[i][j];
		}
	}
	return temp;
}
//高斯消元法求逆
template <class U>
Matrix<U> Matrix<U>::inverse()
{
	Matrix<U> temp(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] = mat[i][j];
		}
	}//将原矩阵拷贝过来
	Matrix<U> temp2(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == j)
			{
				temp2.mat[i][j] = 1;
			}
			else
			{
				temp2.mat[i][j] = 0;
			}
		}
	}//创建一个单位阵
	for (int i = 0; i < row; i++)
	{
		if (temp.mat[i][i] == 0)
		{
			for (int j = i + 1; j < row; j++)
			{
				if (temp.mat[j][i] != 0)
				{
					temp.swapRow(i, j);
					temp2.swapRow(i, j);//交换两行
					break;
				}
			}
		}
		for (int j = i + 1; j < row; j++)
		{
			if (temp.mat[j][i] != 0)
			{
				U temp3 = temp.mat[j][i] / temp.mat[i][i];
				for (int k = 0; k < col; k++)
				{
					temp.mat[j][k] -= temp.mat[i][k] * temp3;
					temp2.mat[j][k] -= temp2.mat[i][k] * temp3;
				}
			}
		}
	}
	for (int i = row - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (temp.mat[j][i] != 0)
			{
				U temp3 = temp.mat[j][i] / temp.mat[i][i];
				for (int k = 0; k < col; k++)
				{
					temp.mat[j][k] -= temp.mat[i][k] * temp3;
					temp2.mat[j][k] -= temp2.mat[i][k] * temp3;
				}
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		U temp3 = temp.mat[i][i];
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] /= temp3;
			temp2.mat[i][j] /= temp3;
		}
	}
	return temp2;
}
//矩阵的行列式
template <class T>
T Matrix<T>::det()
{
	if (row != col)
	{
		cout << "Error!" << endl;
		cout << "行数列数不同，无法求逆" << endl;
		return 0;
		}
		Matrix<T> temp(row, col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				temp.mat[i][j] = mat[i][j];
			}
		}
		T sum = 1;
		for (int i = 0; i < row; i++)
		{
			if (temp.mat[i][i] == 0)
			{
				for (int j = i + 1; j < row; j++)
				{
					if (temp.mat[j][i] != 0)
					{
						temp.swapRow(i, j);
						sum *= -1;
						break;
					}
				}
			}//化成对角矩阵
			for (int j = i + 1; j < row; j++)
			{
				if (temp.mat[j][i] != 0)
				{
					T temp3 = temp.mat[j][i] / temp.mat[i][i];
					for (int k = 0; k < col; k++)
					{
						temp.mat[j][k] -= temp.mat[i][k] * temp3;
					}
				}
			}
		}
		for (int i = 0; i < row; i++)
		{
			sum *= temp.mat[i][i];//将对角线元素相乘
		}
		return sum;
}
//矩阵整体的最大值，以及最大值位置
template<class T>
MatMax<T> Matrix<T>::max()
{
	MatMax<T> temp;
	temp.max = mat[0][0];
	temp.row = 0;
	temp.col = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (mat[i][j] > temp.max)
			{
				temp.max = mat[i][j];
				temp.row = i;
				temp.col = j;
			}
		}
	}
	return temp;
}
//矩阵整体的最小值，以及最小值位置
template<class T>
MatMin<T> Matrix<T>::min()
{
	MatMin<T> temp;
	temp.min = mat[0][0];
	temp.row = 0;
	temp.col = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (mat[i][j] < temp.min)
			{
				temp.min = mat[i][j];
				temp.row = i;
				temp.col = j;
			}
		}
	}
	return temp;
}
//矩阵整体的平均值
template<class T>
MatAvg<T> Matrix<T>::avg()
{
	MatAvg<T> temp;
	temp.avg = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.avg += mat[i][j];
		}
	}
	temp.avg /= (row*col);

	//找到最接近平均值的数
	temp.avgNum = mat[0][0];
	temp.row = 0;
	temp.col = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (abs(mat[i][j] - temp.avg) < abs(temp.avgNum - temp.avg))
			{
				temp.avgNum = mat[i][j];
				temp.row = i;
				temp.col = j;
			}
		}
	}
	return temp;
}
//获得子矩阵
template<class T>
Matrix<T> Matrix<T>::subMatrix(int r1, int c1, int r2, int c2)
{
	Matrix<T> temp(r2 - r1 + 1, c2 - c1 + 1);
	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++)
		{
			temp.mat[i - r1][j - c1] = mat[i][j];
		}
	}
	return temp;
}
//获得矩阵的某一行
template <class T>
Matrix<T> Matrix<T>::getMRow(int r)
{
	Matrix<T> temp(1, col);
	for (int i = 0; i < col; i++)
	{
		temp.mat[0][i] = mat[r][i];
	}
	return temp;
}
//获得矩阵的某一列
template <class T>
Matrix<T> Matrix<T>::getMCol(int c)
{
	Matrix<T> temp(row, 1);
	for (int i = 0; i < row; i++)
	{
		temp.mat[i][0] = mat[i][c];
	}
	return temp;
}
//交换两行
template <class T>
void Matrix<T>::swapRow(int r1, int r2)
{
	T* temp = new T[col];
	for (int i = 0; i < col; i++)
	{
		temp[i] = mat[r1][i];
	}
	for (int i = 0; i < col; i++)
	{
		mat[r1][i] = mat[r2][i];
	}
	for (int i = 0; i < col; i++)
	{
		mat[r2][i] = temp[i];
	}
	delete[] temp;
}
//矩阵整体的查找，并查找位置，如果找不到就返回最接近他的值
template <class T>
MatFind<T> Matrix<T>::find(T a)
{
	MatFind<T> temp;
	temp.find = a;
	temp.row = 0;
	temp.col = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (mat[i][j] == a)
			{
				temp.row = i;
				temp.col = j;
				return temp;
			}
		}
	}
	temp.find = mat[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (abs(mat[i][j] - a) < abs(temp.find - a))
			{
				temp.find = mat[i][j];
				temp.row = i;
				temp.col = j;
			}
		}
	}
	cout << "无法查找到当前值，已为您返回与该值最接近的值" << endl;
	return temp;
}
//设置矩阵的某个元素
template <class T>
void Matrix<T>::set(int r, int c, T a)
{
	mat[r][c] = a;
}
//矩阵增加一行
template <class T>
Matrix<T> Matrix<T>::addRow(int r,Matrix<T> a)
{
	Matrix<T> temp(row + 1, col);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] = mat[i][j];
		}
	}
	for (int i = 0; i < col; i++)
	{
		temp.mat[r][i] = a.mat[0][i];
	}
	for (int i = r + 1; i < row + 1; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] = mat[i - 1][j];
		}
	}
	return temp;
}
//增加一列
template<class T>
Matrix<T> Matrix<T>::addCol(int r, Matrix<T> a)
{
	Matrix<T> temp(row, col + 1);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < r; j++)
		{
			temp.mat[i][j] = mat[i][j];
		}
	}
	for (int i = 0; i < row; i++)
	{
		temp.mat[i][r] = a.mat[i][0];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = r + 1; j < col + 1; j++)
		{
			temp.mat[i][j] = mat[i][j - 1];
		}
	}
	return temp;
}
//删除一行
template <class T>
Matrix<T> Matrix<T>::deleteRow(int r)
{
	Matrix<T> temp(row - 1, col);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i][j] = mat[i][j];
		}
	}
	for (int i = r + 1; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.mat[i - 1][j] = mat[i][j];
		}
	}
	return temp;
}
template <class T>
//删除一列
Matrix<T> Matrix<T>::deleteCol(int r)
{
	Matrix<T> temp(row, col - 1);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < r; j++)
		{
			temp.mat[i][j] = mat[i][j];
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = r + 1; j < col; j++)
		{
			temp.mat[i][j - 1] = mat[i][j];
		}
	}
	return temp;
}
//设置矩阵的某一行
template <class T>
void Matrix<T>::setMRow(int r, Matrix<T> a)
{
	for (int i = 0; i < col; i++)
	{
		mat[r][i] = a.mat[0][i];
	}
}
//设置矩阵的某一列
template <class T>
void Matrix<T>::setMCol(int r, Matrix<T> a)
{
	for (int i = 0; i < row; i++)
	{
		mat[i][r] = a.mat[i][0];
	}
}
//矩阵的秩
template <class T>
int Matrix<T>::Rank()
{
	Matrix<T> temp = *this;
	int r = 0;
	int c = 0;
	while (r < row && c < col)
	{
		if (temp.mat[r][c] != 0)//判断当前元素是否为0
		{
			for (int i = r + 1; i < row; i++)
			{
				T a = temp.mat[i][c] / temp.mat[r][c];//计算当前元素与主元的比值
				for (int j = c; j < col; j++)
				{
					temp.mat[i][j] = temp.mat[i][j] - a * temp.mat[r][j];//消元
				}
			}
			r++;
			c++;//保证主元
		}
		else
		{
			int flag = 0;//标记是否找到非零元素
			for (int i = r + 1; i < row; i++)
			{
				if (temp.mat[i][c] != 0)
				{
					for (int j = c; j < col; j++)
					{
						T a = temp.mat[r][j];
						temp.mat[r][j] = temp.mat[i][j];
						temp.mat[i][j] = a;
					}
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				c++;
			}
		}
	}
	return r;
}
//矩阵的范数
template <class T>
T Matrix<T>::norm()
{
	T sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum += mat[i][j] * mat[i][j];
		}
	}
	return sqrt(sum);
}
//矩阵的QR分解
/*
1.写出矩阵A的列向量;
2.把列向量组按照施密特正交化方法得到正交向量组，由此构成的矩阵为正交矩阵Q;
3.把矩阵A列向量表示成向量组的线性组合，则系数矩阵为R;
4.得出矩阵的QR分解.
*/
template <class T>
Matrix<T> Matrix<T>::QR(Matrix<T>& Q, Matrix<T>& R)
{	
	const double eps = 1e-10;//精度
	Matrix<T> temp = *this;
	Matrix<T> q(row, col);
	Matrix<T> r(col, col);
	//写出矩阵的列向量
	Matrix<T>* a = new Matrix<T>[col];
	//存储正交化后的列向量
	Matrix<T>* b = new Matrix<T>[col];
	for (int i = 0; i < col; i++)
	{
		a[i] = temp.getMCol(i);
	}
	//施密特正交化
	for (int i = 0; i < col; i++)
	{
		b[i] = a[i];
		for (int j = 0; j < i; j++)
		{
			T f = (a[i].transpose() * b[j]).mat[0][0] / (b[j].transpose() * b[j]).mat[0][0];
			b[i] = b[i] - b[j].mul(f);
		}
	}
	//计算b中每个列向量的模
	T* norm = new T[col];
	for (int i = 0; i < col; i++)
	{
		norm[i] = b[i].norm();
	}
	//计算正交矩阵Q
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			q.mat[j][i] = b[i].mat[j][0] / norm[i];
		}
	}
	//求R
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i <= j)
			{
				r.mat[i][j] = (q.getMCol(i).transpose() * a[j]).mat[0][0];
			}
			else
			{
				r.mat[i][j] = 0;
			}
		}
	}
	Q = q;
	R = r;
	return q * r;
	}
















