// 14-24.cpp : 定义控制台应用程序的入口点。
//模板类的非约束模板友元函数

#include "stdafx.h"
#include <iostream>
using std::endl;
using std::cout;

template<typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T & i) : item(i) {}
	template <typename C, typename D> 
	friend void show2(C &, D &);
};

template <typename C, typename D>void show2(C & c, D & d)
{
	cout << c.item << ", " << d.item << endl;
}


int main()
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);
	cout << "hfi1,hfi2: ";
	show2(hfi1, hfi2);
	cout << "hfdb,hfi2: ";
	show2(hfdb, hfi2);
	getchar();
	return 0;
}

