// 14-13.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stacktp.h"
#include <iostream>
#include <cctype>
#include <string>
using std::cin;
using std::cout;


int main()
{
	Stack<std::string> st;
	char ch;
	std::string po;
	cout << "Please enter A to add a pucchase order,\nP to process a PO,or Q to quit.\n";
	while (cin >> ch&&std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
		{
			continue;
		}
		if (!std::isalpha(ch))//如果输入的不是字母
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
			{
				cout << "Stack is already full.\n";
			}
			else
			{
				st.push(po);
			}
			break;
		case 'P':
		case 'p':
			if (st.isempty())
			{
				cout << "Stack is alreay empty.\n";
			}
			else
			 {
				st.pop(po);
				cout << "PO #" << po << " popped.\n";
				break;
			 }
		}
		cout << "Please enter A to add a purchase order,\nP to process a PO,or Q to quit.\n";
	}
	cout << "Bye.\n";
	getchar();
	getchar();
    return 0;
}

