#include <iostream>
#include <cmath>

#include "Triangle.h"
using namespace std;

int main()
{
	RightTriangle RightTriangle1;
	RightTriangle RightTriangle2;

	cout << RightTriangle1.getA() << endl;
	RightTriangle1.setA(5);
	cout << RightTriangle1.getA() << endl;

	RightTriangle1.inputTriangle();
	RightTriangle2.inputTriangle();
	RightTriangle1.outputTriangle();
	RightTriangle2.outputTriangle();

	if (RightTriangle1 == RightTriangle2)
		cout << "The triangles are similar" << endl;
	else cout << "The triangles are not similar" << endl;

	cout << "First triangle hypotenuse = " << RightTriangle1.computeHypotenuse() << endl;
	cout << "First triangle perimeter = " << RightTriangle1.computePerimeter() << endl;

	if (RightTriangle1.checkIsoscelesNature())
	{
		cout << "The first triangle is isosceles" << endl;
	}
	else cout << "The first triangle is not isosceles" << endl;



	double e;
	cout << "Input a number for scaling:" << endl;
	cin >> e;
	RightTriangle1 * e;
	RightTriangle1.outputTriangle();
	cout << "First triangle larger angle = " << RightTriangle1.findLargerAngle() << endl;

}