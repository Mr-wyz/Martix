#pragma once
#include <iostream>
#include<ostream>
using namespace std;

//矩阵最大值结构体
template<class T>
struct MatMax
{
	T max;
	int row;
	int col;
};
//矩阵最小值结构体
template<class T>
struct MatMin
{
	T min;
	int row;
	int col;
};
//矩阵平均值结构体
template<class T>
struct MatAvg
{
	T avg;//矩阵的平均值
	T avgNum;//最接近平均值的元素
	int row;
	int col;
};
//矩阵查找结构体
template<class T>
struct MatFind
{
	T find;//查找的元素
	int row;
	int col;
};

template<class T>
class Matrix
{
private:
	int row;//行
	int col;//列
	T** mat;//指向指针的指针
public:
	Matrix();//默认构造函数
	Matrix(int r, int c);//构造函数
	Matrix(const Matrix<T>& m);//拷贝构造函数
	~Matrix();//析构函数
	Matrix<T> ones();//生成单位矩阵

	void set(int r, int c, T t);//设置矩阵的某个元素
	T get(int r, int c);//获取矩阵的某个元素
	//转置矩阵
	Matrix<T> transpose();
	//高斯消元法求逆
	Matrix<T> inverse();
	//矩阵的行列式
	T det();
	void resize(int r, int c);//改变矩阵的大小
	int getRow();//获取矩阵的行数
	int getCol();//获取矩阵的列数
	//获得矩阵中的元素
	T getMat();
	//矩阵得到某一行
	Matrix<T> getMRow(int r);
	//矩阵得到某一列
	Matrix<T> getMCol(int c);
	//矩阵得到子矩阵
	Matrix<T> subMatrix(int r1, int c1, int r2, int c2);
	//矩阵与标量的加减乘除
	Matrix<T> add(T t);
	Matrix<T> sub(T t);
	Matrix<T> mul(T t);
	Matrix<T> div(T t);

	//矩阵整体的最大值，以及最大值位置
	MatMax<T> max();
	//矩阵整体的最小值，以及最小值位置
	MatMin<T> min();
	//矩阵整体的平均值，以及平均值位置
	MatAvg<T> avg();
	//矩阵整体的查找，以及查找位置
	MatFind<T> find(T t);
	//矩阵某一行的最大值，以及最大值位置

	Matrix<T> addRow(int r, Matrix<T> a);//矩阵增加一行
	Matrix<T> addCol(int r, Matrix<T> a);//矩阵增加一列
	Matrix<T> deleteRow(int r);//删除某一行元素
	Matrix<T> deleteCol(int c);//删除某一列元素
	void setMRow(int r, Matrix<T> a);
	void setMCol(int c, Matrix<T> a);


	//交换两行
	void swapRow(int r1, int r2);

	///////////////////////////////////////////////////////////
	T* operator[](int i);
	Matrix<T>& operator=(const Matrix<T>& m);
	Matrix<T> operator+(const Matrix<T>& m);
	Matrix<T> operator-(const Matrix<T>& m);
	Matrix<T> operator*(const Matrix<T>& m);
	Matrix<T> operator/(const Matrix<T>& m);
	Matrix<T> operator-();//负号运算符重载
	template<class U>
	friend ostream& operator<<(ostream& os, const Matrix<U>& m);//输出运算符重载
	template<class U>
	friend istream& operator>>(istream& is, Matrix<U>& m);//输入运算符重载
////////////////////////////////////////////////////////////////
//矩阵的分解
	Matrix<T> LU(Matrix<T>& L, Matrix<T>& U);
	Matrix<T> QR(Matrix<T>& Q, Matrix<T>& R);
//////////////////////////////////////////////////////////////////////////

	T norm();//矩阵的范数
	int Rank();//求矩阵的秩
};

