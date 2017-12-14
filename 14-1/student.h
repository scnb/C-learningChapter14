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
	//����ɼ���˽�з���
	std::ostream & arr_out(std::ostream & os)const;
public:
	Student() : name("null student"),scores(){}
	explicit Student(const std::string & s) : name(s), scores() {}//��ʼ��˳�������Ա������˳��
	explicit Student(int n) : name("Nully"), scores(n) {}//n��ʾ������Ԫ�صĸ�����ʹ��explicit�ر���ʽת��
	Student(const std::string & s, int n) : name(s), scores(n) {}//�ڰ����У���Ա��ʼ���б��У�ʹ�ó�Ա����������������˽�м̳�������
	Student(const std::string & s, const ArrayDb & a) : name(s), scores(a) {}
	Student(const char * str, const double * pd, int n) : name(str), scores(pd, n) {}
	~Student() {};
	double Average()const;
	const std::string & Name()const;
	double & operator[](int i);//ȡ��������ĳһ��Ԫ�صķ���
	double operator[](int i)const;
	//��Ԫ
	friend std::istream & operator >> (std::istream & is,Student & stu);
	friend std::ostream & operator <<(std::ostream & os,const Student & stu);
	friend std::istream & getline(std::istream & is,Student & stu);
};
#endif // !STUDENT_H_
