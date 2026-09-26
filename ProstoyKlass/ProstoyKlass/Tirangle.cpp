#include <iostream>
#include <cmath>
#include "Triangle.h"
using namespace std;

RightTriangle::RightTriangle(const double ax, const double ay, const double a, const double b)
{
	ax_ = ax;
	ay_ = ay;
	a_ = a;
	b_ = b;
}

void RightTriangle::inputTriangle()
{
	cin >> "Input point A coordinates : " >> ax >> ay >> endl >> "Input a length : " >> a >> ", b length : " >> b >> endl;
}

void RightTriangle::outputTriangle()
{
	cout << "point A coordinates: ( " << ax << "," << ay << "), a length:" << a << ", b length: " << b << endl;
}
double RightTriangle::getAx() const
{
	return ax;
}
void RightTriangle::setAx(const double ax)
{
	ax_ = ax;
}
double RightTriangle::getAy() const
{
	return ay;
}
void RightTriangle::setAy(const double ay)
{
	ay_ = ay;
}
double RightTriangle::getA() const
{
	return a;
}
void RightTriangle::setA(const double a)
{
	a_ = a;
}
double RightTriangle::getB() const
{
	return b;
}
void RightTriangle::setB(const double b)
{
	b_ = b;
}
double RightTriangle::computeHypotenuse(double a, double b)
{
	double c;
	c = sqrt(a * a + b * b);
	return c;
}

double RightTriangle::computePerimeter(double a, double b)
{
	double c, p;
	c = sqrt(a * a + b * b);
	p = a + b + c;
	return p;
}

bool RightTriangle::checkIsoscelesNature(double a, double b)
{
	if (a == b) return true;
	return false;
}

void RightTriangle::scaleTriangle(double& a, double& b)
{
	double e;
	cout << "Input a number: ";
	cin >> e >> endl;
	a *= e;
	b *= e;
}
double RightTriangle::findLargerAngle(double a, double b)
{
	double first, second;
	first = atan(a / b);
	second = 90 - first;
	cout << "The larger angle: " << endl;
	if (first > second) return first;
	return second;

}

bool operator==(RightTriangle other)
{
	if (a / other.a == b / other.b)
		return true;
	return false;
}
