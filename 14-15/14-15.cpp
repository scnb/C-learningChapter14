// 14-15.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stacktp1.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

const int Num = 10;

int main()
{
	std::srand(std::time(0));
	std::cout << "Please enter stack size: ";
	int stacksize;
	std::cin >> stacksize;
	//根据stacksize大小来创建一个空栈
	Stack<const char *>st(stacksize);
	//模拟收取篮
	const char * in[Num] = { " 1: Hank Gilgamesh"," 2: Kiki Ishtar"," 3: Betty Rocker"," 4: Ian Flagranti"," 5: Wolfgang Kibble"," 6: Portia Koop"," 7: Joy Almondo"," 8: Xaverie Paprika"," 9: Juan Moore"," 10: Misha Mache" };
	//模拟取出篮
	const char * out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty())
		{
			st.push(in[nextin++]);
		}
		else if (st.isfull())
		{
			st.pop(out[processed++]);
		}
		else if (std::rand() % 2 && nextin < Num)
		{
			st.push(in[nextin++]);
		}
		else
		{
			st.pop(out[processed++]);
		}
	}
	for (int i = 0;i < Num;i++)
	{
		std::cout << out[i] << std::endl;
	}
	std::cout << "Bye.\n";
	getchar();
	getchar();
    return 0;
}

