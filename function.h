#pragma once
#include <iostream>
#include "Matrix.h"
//Ĭ�Ϲ��캯��
template<class T>
Matrix<T>::Matrix()
{
	row = 0;
	col = 0;
	mat = NULL;
}
//���캯��
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
//�������캯��
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
//��������
template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}
//��ȡ����
template<class T>
int Matrix<T>::getRow()
{
	return row;
}
//��ȡ����
template<class T>
int Matrix<T>::getCol()
{
	return col;
}
//��λ����
template<class T>
Matrix<T> Matrix<T>::ones()
{
	if (row != col)
	{
		cout << "Error!" << endl;
		cout << "���Ƿ����޷���λ����" << endl;
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
//����
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//����[]
template<class T>
T* Matrix<T>::operator[](int i)
{
	return mat[i];
}
//��ֵ���������
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
//�ӷ����������
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m)
{
	if (row != m.row || col != m.col)
	{
		cout << "Error!" << endl;
		cout << "ά����ͬ���޷����" << endl;
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
//�������������
template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m)
{
	if (row != m.row || col != m.col)
	{
		cout << "Error!" << endl;
		cout << "ά����ͬ���޷����" << endl;
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
//�˷����������
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m)
{
	if (col != m.row)
	{
		cout << "Error!" << endl;
		cout << "ά����ͬ���޷����" << endl;
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
				temp.mat[i][j] += mat[i][k] * m.mat[k][j];//������
			}
		}
	}
	return temp;
}
//�������������
template<class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& m)
{
	if (col != m.row)
	{
		cout << "Error!" << endl;
		cout << "ά����ͬ���޷����" << endl;
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
//�������������
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
//�������
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
//��������
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
//���������(��������)�ӣ������ˣ���
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
//�������
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
//����ת��
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
//��˹��Ԫ������
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
	}//��ԭ���󿽱�����
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
	}//����һ����λ��
	for (int i = 0; i < row; i++)
	{
		if (temp.mat[i][i] == 0)
		{
			for (int j = i + 1; j < row; j++)
			{
				if (temp.mat[j][i] != 0)
				{
					temp.swapRow(i, j);
					temp2.swapRow(i, j);//��������
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
//���������ʽ
template <class T>
T Matrix<T>::det()
{
	if (row != col)
	{
		cout << "Error!" << endl;
		cout << "����������ͬ���޷�����" << endl;
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
			}//���ɶԽǾ���
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
			sum *= temp.mat[i][i];//���Խ���Ԫ�����
		}
		return sum;
}
//������������ֵ���Լ����ֵλ��
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
//�����������Сֵ���Լ���Сֵλ��
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
//���������ƽ��ֵ
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

	//�ҵ���ӽ�ƽ��ֵ����
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
//����Ӿ���
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
//��þ����ĳһ��
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
//��þ����ĳһ��
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
//��������
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
//��������Ĳ��ң�������λ�ã�����Ҳ����ͷ�����ӽ�����ֵ
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
	cout << "�޷����ҵ���ǰֵ����Ϊ���������ֵ��ӽ���ֵ" << endl;
	return temp;
}
//���þ����ĳ��Ԫ��
template <class T>
void Matrix<T>::set(int r, int c, T a)
{
	mat[r][c] = a;
}
//��������һ��
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
//����һ��
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
//ɾ��һ��
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
//ɾ��һ��
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
//���þ����ĳһ��
template <class T>
void Matrix<T>::setMRow(int r, Matrix<T> a)
{
	for (int i = 0; i < col; i++)
	{
		mat[r][i] = a.mat[0][i];
	}
}
//���þ����ĳһ��
template <class T>
void Matrix<T>::setMCol(int r, Matrix<T> a)
{
	for (int i = 0; i < row; i++)
	{
		mat[i][r] = a.mat[i][0];
	}
}
//�������
template <class T>
int Matrix<T>::Rank()
{
	Matrix<T> temp = *this;
	int r = 0;
	int c = 0;
	while (r < row && c < col)
	{
		if (temp.mat[r][c] != 0)//�жϵ�ǰԪ���Ƿ�Ϊ0
		{
			for (int i = r + 1; i < row; i++)
			{
				T a = temp.mat[i][c] / temp.mat[r][c];//���㵱ǰԪ������Ԫ�ı�ֵ
				for (int j = c; j < col; j++)
				{
					temp.mat[i][j] = temp.mat[i][j] - a * temp.mat[r][j];//��Ԫ
				}
			}
			r++;
			c++;//��֤��Ԫ
		}
		else
		{
			int flag = 0;//����Ƿ��ҵ�����Ԫ��
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
//����ķ���
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
//�����QR�ֽ�
/*
1.д������A��������;
2.���������鰴��ʩ���������������õ����������飬�ɴ˹��ɵľ���Ϊ��������Q;
3.�Ѿ���A��������ʾ���������������ϣ���ϵ������ΪR;
4.�ó������QR�ֽ�.
*/
template <class T>
Matrix<T> Matrix<T>::QR(Matrix<T>& Q, Matrix<T>& R)
{	
	const double eps = 1e-10;//����
	Matrix<T> temp = *this;
	Matrix<T> q(row, col);
	Matrix<T> r(col, col);
	//д�������������
	Matrix<T>* a = new Matrix<T>[col];
	//�洢���������������
	Matrix<T>* b = new Matrix<T>[col];
	for (int i = 0; i < col; i++)
	{
		a[i] = temp.getMCol(i);
	}
	//ʩ����������
	for (int i = 0; i < col; i++)
	{
		b[i] = a[i];
		for (int j = 0; j < i; j++)
		{
			T f = (a[i].transpose() * b[j]).mat[0][0] / (b[j].transpose() * b[j]).mat[0][0];
			b[i] = b[i] - b[j].mul(f);
		}
	}
	//����b��ÿ����������ģ
	T* norm = new T[col];
	for (int i = 0; i < col; i++)
	{
		norm[i] = b[i].norm();
	}
	//������������Q
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			q.mat[j][i] = b[i].mat[j][0] / norm[i];
		}
	}
	//��R
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
















