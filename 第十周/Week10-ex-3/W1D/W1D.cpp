// W1D.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "W1D.h"


// 这是导出变量的一个示例
W1D_API int nW1D=0;

// 这是导出函数的一个示例。
W1D_API int fnW1D(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 W1D.h
CW1D::CW1D()
{
	return;
}

W1D_API int Factorial(int n){
	
	int num = 1;
	if (n <= 0)  return 0;
	if (n >= 17) return -1;
	for (int i = 1; i <= n; i++)
	{
		num *= i;
	}
	return num;
}