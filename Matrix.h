#pragma once
#include <iostream>
#include<ostream>
using namespace std;

//�������ֵ�ṹ��
template<class T>
struct MatMax
{
	T max;
	int row;
	int col;
};
//������Сֵ�ṹ��
template<class T>
struct MatMin
{
	T min;
	int row;
	int col;
};
//����ƽ��ֵ�ṹ��
template<class T>
struct MatAvg
{
	T avg;//�����ƽ��ֵ
	T avgNum;//��ӽ�ƽ��ֵ��Ԫ��
	int row;
	int col;
};
//������ҽṹ��
template<class T>
struct MatFind
{
	T find;//���ҵ�Ԫ��
	int row;
	int col;
};

template<class T>
class Matrix
{
private:
	int row;//��
	int col;//��
	T** mat;//ָ��ָ���ָ��
public:
	Matrix();//Ĭ�Ϲ��캯��
	Matrix(int r, int c);//���캯��
	Matrix(const Matrix<T>& m);//�������캯��
	~Matrix();//��������
	Matrix<T> ones();//���ɵ�λ����

	void set(int r, int c, T t);//���þ����ĳ��Ԫ��
	T get(int r, int c);//��ȡ�����ĳ��Ԫ��
	//ת�þ���
	Matrix<T> transpose();
	//��˹��Ԫ������
	Matrix<T> inverse();
	//���������ʽ
	T det();
	void resize(int r, int c);//�ı����Ĵ�С
	int getRow();//��ȡ���������
	int getCol();//��ȡ���������
	//��þ����е�Ԫ��
	T getMat();
	//����õ�ĳһ��
	Matrix<T> getMRow(int r);
	//����õ�ĳһ��
	Matrix<T> getMCol(int c);
	//����õ��Ӿ���
	Matrix<T> subMatrix(int r1, int c1, int r2, int c2);
	//����������ļӼ��˳�
	Matrix<T> add(T t);
	Matrix<T> sub(T t);
	Matrix<T> mul(T t);
	Matrix<T> div(T t);

	//������������ֵ���Լ����ֵλ��
	MatMax<T> max();
	//�����������Сֵ���Լ���Сֵλ��
	MatMin<T> min();
	//���������ƽ��ֵ���Լ�ƽ��ֵλ��
	MatAvg<T> avg();
	//��������Ĳ��ң��Լ�����λ��
	MatFind<T> find(T t);
	//����ĳһ�е����ֵ���Լ����ֵλ��

	Matrix<T> addRow(int r, Matrix<T> a);//��������һ��
	Matrix<T> addCol(int r, Matrix<T> a);//��������һ��
	Matrix<T> deleteRow(int r);//ɾ��ĳһ��Ԫ��
	Matrix<T> deleteCol(int c);//ɾ��ĳһ��Ԫ��
	void setMRow(int r, Matrix<T> a);
	void setMCol(int c, Matrix<T> a);


	//��������
	void swapRow(int r1, int r2);

	///////////////////////////////////////////////////////////
	T* operator[](int i);
	Matrix<T>& operator=(const Matrix<T>& m);
	Matrix<T> operator+(const Matrix<T>& m);
	Matrix<T> operator-(const Matrix<T>& m);
	Matrix<T> operator*(const Matrix<T>& m);
	Matrix<T> operator/(const Matrix<T>& m);
	Matrix<T> operator-();//�������������
	template<class U>
	friend ostream& operator<<(ostream& os, const Matrix<U>& m);//������������
	template<class U>
	friend istream& operator>>(istream& is, Matrix<U>& m);//�������������
////////////////////////////////////////////////////////////////
//����ķֽ�
	Matrix<T> LU(Matrix<T>& L, Matrix<T>& U);
	Matrix<T> QR(Matrix<T>& Q, Matrix<T>& R);
//////////////////////////////////////////////////////////////////////////

	T norm();//����ķ���
	int Rank();//��������
};

