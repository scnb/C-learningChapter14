// 14-23.cpp : 定义控制台应用程序的入口点。
//模板类的约束模板友元函数

#include "stdafx.h"
#include <iostream>
using std::endl;
using std::cout;

//模板原型
template<typename T> void counts();
template<typename T> void reports(T &);

//模板类
template<typename TT>
class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT & i) : item(i) { ct++; }
	~HasFriendT() { ct--; }
	friend void counts<TT>();
	friend void reports<>(HasFriendT<TT> &);
};

template<typename T>
int HasFriendT<T>::ct = 0;

//模板友元函数定义
template<typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
	cout << "template counts(): " << HasFriendT<T>::ct << endl;
}

template<typename T>
void reports(T & hf)
{
	cout << hf.item << endl;
}

int main()
{
	counts<int>();
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.5);
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);
	cout << "counts<int>() output:\n";
	counts<int>();
	cout << "counts<double>() output:\n";
	counts<double>();
	getchar();
    return 0;
}

