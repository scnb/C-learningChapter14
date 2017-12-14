#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name;
	ArrayDb scores;
	//输出成绩的私有方法
	std::ostream & arr_out(std::ostream & os)const;
public:
	Student() : name("null student"),scores(){}
	explicit Student(const std::string & s) : name(s), scores() {}//初始化顺序是类成员声明的顺序
	explicit Student(int n) : name("Nully"), scores(n) {}//n表示数组中元素的个数。使用explicit关闭隐式转换
	Student(const std::string & s, int n) : name(s), scores(n) {}//在包含中，成员初始化列表中，使用成员名而不是类名（与私有继承相区别）
	Student(const std::string & s, const ArrayDb & a) : name(s), scores(a) {}
	Student(const char * str, const double * pd, int n) : name(str), scores(pd, n) {}
	~Student() {};
	double Average()const;
	const std::string & Name()const;
	double & operator[](int i);//取出数组中某一个元素的方法
	double operator[](int i)const;
	//友元
	friend std::istream & operator >> (std::istream & is,Student & stu);
	friend std::ostream & operator <<(std::ostream & os,const Student & stu);
	friend std::istream & getline(std::istream & is,Student & stu);
};
#endif // !STUDENT_H_
