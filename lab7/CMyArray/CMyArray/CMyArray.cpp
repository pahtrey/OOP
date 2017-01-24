#include "stdafx.h"
#include "CMyArray.h"
#include <vector>
#include <iostream>
#include <string>

int main()
{
	CMyArray<float> floatArray;

	floatArray.Append(1);
	floatArray.Append(2);
	std::cout << floatArray.GetSize() << std::endl;
	std::cout << floatArray.GetCapacity() << std::endl;
	floatArray.Resize(10);
	std::cout << floatArray.GetSize() << std::endl;
    return 0;
}