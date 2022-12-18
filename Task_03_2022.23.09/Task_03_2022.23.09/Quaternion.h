#pragma once
#include <iostream>
#include <cmath>

class Quaternion
{

public:
	double a, b, c, d;
	Quaternion(double a = 0, double b = 0, double c = 0, double d = 0);
	Quaternion(const Quaternion& num);
	~Quaternion();

	double getA();
	double getB();
	double getC();
	double getD();

	void setA(double a);
	void setB(double b);
	void setC(double c);
	void setD(double d);

	void print();

	double norm();
	double arg();

	Quaternion conjugate();

	friend bool operator==(const Quaternion& number1, const Quaternion& number2);

	Quaternion& operator=(const Quaternion& number);
	Quaternion operator+(const Quaternion& number);
	Quaternion operator-(const Quaternion& number);
	Quaternion operator*(const Quaternion& number);

	friend Quaternion operator*(const double k, const Quaternion& number);
	friend Quaternion operator+(const double k, const Quaternion& number);
	friend Quaternion operator-(const double k, const Quaternion& number);
	friend Quaternion operator/(const double k, const Quaternion& number);

	Quaternion operator/(const Quaternion& num);
	Quaternion operator/(double c);

	Quaternion& operator+=(const Quaternion& q);
	Quaternion& operator+=(const double summ);
	Quaternion& operator*=(const Quaternion& q);
	Quaternion& operator*=(const double k);
	Quaternion& operator-=(const Quaternion& q);
	Quaternion& operator-=(const double summ);
	Quaternion& operator/=(const Quaternion& q);
	Quaternion& operator/=(const double div);

	friend std::ostream& operator<<(std::ostream& stream, const Quaternion& q);
	//friend std::istream& operator>>(std::istream& stream, const Quaternion& q);

};