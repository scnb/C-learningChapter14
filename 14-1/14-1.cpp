// 14-1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "student.h"
#include <iostream>
using std::cin;
using std::endl;
using std::cout;

void set(Student & sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main()
{
	Student ada[pupils] = { Student(quizzes),Student(quizzes),Student(quizzes) };
	int i;
	for (i = 0;i < pupils;++i)
	{
		set(ada[i], quizzes);
	}
	cout << "\nStudent List:\n";
	for (i = 0;i < pupils;i++)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].Average() << endl;
	}
	cout << "Done\n";
	getchar();
	getchar();
    return 0;
}

void set(Student & sa, int n)
{
	cout << "Please enter the student's name: ";
	getline(cin, sa);
	cout << "Please enter " << n << " quiz scores:\n";
	for (int i = 0;i < n;i++)
	{
		cin >> sa[i];
	}
	while (cin.get() != '\n')
	{
		continue;
	}
}