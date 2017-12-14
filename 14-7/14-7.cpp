// 14-7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "worker.h"
#include <iostream>

const int LIM = 4;

int main()
{
	Waiter Bob("Bob Apple", 314L, 5);
	Singer bev("Beverly Hills", 522L, 3);
	Waiter w_temp;
	Singer s_temp;
	Worker * pw[LIM] = { &Bob,&bev,&w_temp,&s_temp };
	int i;
	for (i = 2;i < LIM;i++)
	{
		pw[i]->Set();
	}
	for (i = 0;i < LIM;i++)
	{
		pw[i]->Show();
		std::cout << std::endl;
	}
	getchar();
    return 0;
}

