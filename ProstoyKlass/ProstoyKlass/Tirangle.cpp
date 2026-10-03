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
	cout << "Input point A coordinates : ";
	cin >> ax_ >> ay_;  
	cout << "Input a length : "; 
	cin >> a_; 
	cout << "Input b length : "; 
	cin >> b_;
}

void RightTriangle::outputTriangle()
{
	cout << "point A coordinates: (" << ax_ << "," << ay_ << "), a length = " << a_ << ", b length = " << b_ << endl;

}
double RightTriangle::getAx() const
{
	return ax_;
}
void RightTriangle::setAx(const double ax)
{
	ax_ = ax;
}
double RightTriangle::getAy() const
{
	return ay_;
}
void RightTriangle::setAy(const double ay)
{
	ay_ = ay;
}
double RightTriangle::getA() const
{
	return a_;
}
void RightTriangle::setA(const double a)
{
	a_ = a;
}
double RightTriangle::getB() const
{
	return b_;
}
void RightTriangle::setB(const double b)
{
	b_ = b;
}
double RightTriangle::computeHypotenuse()
{
	double c;
	c = sqrt(a_ * a_ + b_ * b_);
	return c;
}

double RightTriangle::computePerimeter()
{
	double c, p;
	c = sqrt(a_ * a_ + b_ * b_);
	p = a_ + b_ + c;
	return p;
}

bool RightTriangle::checkIsoscelesNature()
{
	if (a_ == b_) return true;
	return false;
}

void RightTriangle::scaleTriangle(double e)
{
	a_ *= e;
	b_ *= e;
}
double RightTriangle::findLargerAngle()
{
	double first, second;
	const double pi = 3.14159265359;
	first = atan(a_/ b_);
	second = (pi/2) - first;
	if (first > second) return (first * 180/pi);
	return (second * 180/pi);

}

bool RightTriangle::operator==(const RightTriangle& other) const
{
	if (a_ / other.a_ == b_ / other.b_)
		return true;
	return false;
}
