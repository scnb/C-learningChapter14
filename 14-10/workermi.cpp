#include "stdafx.h"
#include "workemi.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Worker::~Worker()
{
}

void Worker::Data()const
{
	cout << "Name: " << fullname << endl;
	cout << "Employee ID: " << id << endl;
}

void Worker::Get()
{
	getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
	{
		continue;
	}
}

void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show()const
{
	cout << "Category: waiter\n";
	Worker::Data();
	Data();
}

void Waiter::Data()const
{
	cout << "Pananche rating: " << panache << endl;
}

void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
	{
		continue;
	}
}

char * Singer::pv[vtypes] = { "other","alto","contralto","soprano","bass","baritone","tenor" };
void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

void Singer::Show()const
{
	cout << "Category: singer\n";
	Worker::Data();
	Data();
}

void Singer::Data()const
{
	cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0;i < vtypes;i++)
	{
		cout << i << ": " << pv[i] << "   ";
		if (i % 4 == 3)
		{
			cout << endl;
		}
	}
	if (i % 4 != 0)
	{
		cout << endl;
	}
	cin >> voice;
	while (voice < 0 || voice>6)
	{
		cout << "Enter the right number: ";
		cin >> voice;
	}
	while (cin.get() != '\n')
	{
		continue;
	}
}

void SingingWaiter::Data()const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWaiter::Show()const
{
	cout << "Category: singing waiter\n";
	Worker::Data();
	Data();
}

void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}