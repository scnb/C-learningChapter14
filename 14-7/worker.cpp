#include "stdafx.h"
#include "worker.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Worker的方法
Worker::~Worker()
{
}

void Worker::Set()
{
	cout << "Enter worker's name: ";
	getline(cin, fullname);
	cout << "Enter worker's id: ";
	cin >> id;
	while (cin.get() != '\n')
	{
		continue;
	}
}

void Worker::Show()const
{
	cout << "Name: " << fullname << "\n";
	cout << "Employee ID: " << id << "\n";
}

//Waiter的方法
void Waiter::Set()
{
	Worker::Set();
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
	{
		continue;
	}
}

void Waiter::Show()const
{
	cout << "Category: waiter\n";
	Worker::Show();
	cout << "Panache rating: " << panache << "\n";
}

//Singer的方法
char * Singer::pv[] = { "other","alto","contralto","soprano","bass","baritone","tenor" };

void Singer::Set()
{
	Worker::Set();
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0;i < Vtypes;i++)
	{
		cout << i << ": " << pv[i] << "  ";
		if (i % 4 == 3)
		{
			cout << endl;
		}
	}
	if (i % 4 != 0)
	{
		cout << endl;
	}
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
	{
		cout << "Please enter a value >=0 and < " << Vtypes << endl;
	}
	while (cin.get() != '\n')
	{
		continue;
	}
}

void Singer::Show()const
{
	cout << "Category: Singer\n";
	Worker::Show();
	cout << "Vocal range: " << pv[voice] << endl;
}