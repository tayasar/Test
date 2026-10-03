#pragma once

class RightTriangle
{
private:
	double ax_, ay_, a_, b_;
public:
	RightTriangle() = default;
	RightTriangle(const double Ax, const double Ay, const double a, const double b);
	void inputTriangle();
	void outputTriangle();
	double getAx() const;
	void setAx(const double ax);
	double getAy() const;
	void setAy(const double ay);
	double getA() const;
	void setA(const double a);
	double getB() const;
	void setB(const double b);
	double computeHypotenuse();
	double computePerimeter();
	bool checkIsoscelesNature();
	void scaleTriangle(double e);
	double findLargerAngle();
	bool operator==(const RightTriangle& other) const;

};
