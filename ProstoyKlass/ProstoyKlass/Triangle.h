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
	void setAx(const double Ax);
	double getAy() const;
	void setAy(const double Ay);
	double getA() const;
	void setA(const double a);
	double getB() const;
	void setB(const double b);
	double computeHypotenuse(double a, double b);
	double computePerimeter(double a, double b);
	bool checkIsoscelesNature(double a, double b);
	void scaleTriangle(double& a, double& b);
	double findLargerAngle(double a, double b);
	bool checkSimillarity(RightTriangle other);

};
