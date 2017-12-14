// 14-17.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "arraytp.h"
#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	ArrayTP<int, 10> sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10>twodee;//该数组包含10个元素，每个元素又包含5个int元素
	int i, j;
	for (i = 0;i < 10;i++)
	{
		sums[i] = 0;
		for (j = 0;j < 5;j++)
		{
			twodee[i][j] = (i + 1)*(j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 10;
	}
	for (i = 0;i < 10;i++)
	{
		for (j = 0;j < 5;j++)
		{
			cout.width(2);
			cout << twodee[i][j] << ' ';
		}
		cout << ": sum = ";
		cout.width(3);
		cout << sums[i] << ", average = " << aves[i] << endl;
	}
	cout << "Done.\n";
	getchar();
    return 0;
}