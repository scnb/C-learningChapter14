#pragma once
#ifndef STUDENTI_H_
#define STUDENTI_H_
#include <iostream>
#include <valarray>
#include <string>

class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	std::ostream & arr_out(std::ostream & os)const;
public:
	Student() : std::string("NUll Student"), ArrayDb() {}
	explicit Student(const std::string & s) : std::string(s), ArrayDb() {}//��˽�м̳��У���Ա�����б�ʹ�����������ǳ�Ա�� 
	explicit Student(int n) : std::string("NUlly"), ArrayDb(n) {}
	Student(const std::string & s, int n) : std::string(s), ArrayDb(n) {}
	Student(const std::string & s, const ArrayDb & a) : std::string(s), ArrayDb(a) {}
	Student(const char * str, const double * pd, int n) : std::string(str), ArrayDb(pd, n) {}
	~Student() {}
	double Average()const;
	double & operator[](int i);//ֻ��
	double operator[](int i)const;//��д�ɶ�
	const std::string & Name()const;
	//��Ԫ
	friend std::istream & operator >> (std::istream & is,Student & stu);//��һ��
	friend std::ostream & operator << (std::ostream & os, const Student & stu);
	friend std::istream & getline(std::istream & is, Student & stu);//��һ��
};
#endif // !STUDENTI_H_
