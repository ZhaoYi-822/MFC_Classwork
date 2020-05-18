// W2D.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "W2D.h"
#include"math.h"

// 这是导出变量的一个示例
W2D_API int nW2D=0;

// 这是导出函数的一个示例。
W2D_API int fnW2D(void)
{
	return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 W2D.h
CW2D::CW2D()
{
	return;
}
float Rad_to_deg = 45.0 / atan(1.0);

W2D_API float FAC::convert(float deg)
{

	return   deg / Rad_to_deg;
}