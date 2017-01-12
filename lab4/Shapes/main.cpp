#include "stdafx.h"
#include "ShapeList.h"

using namespace std;

int main()
{
	stringstream inputStream;

	inputStream << "rectangle 10 20 30 40 ff0000 00ff00" << endl
		<< "circle 10 10 35 ddd000 120ddd" << endl
		<< "rectangle 30 40 10 10 ffeeee eeffee" << endl
		<< "triangle 10 10 30 40 15 50 004555 88eeff" << endl
		<< "circle 70 80 33 aaa533 b22222" << endl
		<< "rectangle 50 50 50 20 ffeeee eeffee" << endl
		<< "triangle 10 10 30 10 30 40 00ee33 333ddd" << endl
		<< "rectangle 25 70 45 13 ffeeee eeffee" << endl;

	string shape;
	CShapeList shapeList;

	try
	{
		//while (getline(inputStream, shape))
		while (getline(cin, shape))
		{
			shapeList.ReadShape(shape);
		}
		shapeList.PrintMinPerimeterShape();
		shapeList.PrintMaxAreaShape();
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	return 0;
}