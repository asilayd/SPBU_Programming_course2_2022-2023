#include<iostream>
#include"Quaternion.h"

using namespace std;

Quaternion::Quaternion(double a , double b, double c , double d): a(a), b(b), c(c), d(d){}

Quaternion::Quaternion(const Quaternion& number) : a(number.a), b(number.b), c(number.c), d(number.d) {}

Quaternion::~Quaternion()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
}

double Quaternion::getA()
{
	return this->a ;
}
double Quaternion::getB()
{
	return this->b;
}
double Quaternion::getC()
{
	return this->c;
}
double Quaternion::getD()
{
	return this->d;
}

void Quaternion::setA(double a)
{
	this->a = a;
}
void Quaternion::setB(double b)
{
	this->b = b;
}
void Quaternion::setC(double c)
{
	this->c = c;
}
void Quaternion::setD(double d)
{
	this->d = d;
}

void Quaternion::print()
{
	cout << this->a << " ";
	(this->b >= 0) ? cout << "+ " << this->b << "*i" : cout << " " << this->b << "*i ";
	(this->c >= 0) ? cout << "+ " << this->c << "*i" : cout << " " << this->c << "*i ";
	(this->d >= 0) ? cout << "+ " << this->d << "*i" : cout << " " << this->d << "*i";
}

double Quaternion::norm()
{
	return sqrt(this->a * this->a + this->b * this->b + this->c * this->c + this->d * this->d);
}

double Quaternion::arg()
{
	return acos(this->a / this->norm());
}

Quaternion Quaternion::conjugate()
{
	return Quaternion(this->a, -this->b, -this->c, -this->d);
}

Quaternion& Quaternion::operator=(const Quaternion& number)
{
	this->a = number.a;
	this->b = number.b;
	this->c = number.c;
	this->d = number.d;
	return *this;

}

Quaternion Quaternion::operator+(const Quaternion& number)
{
	return Quaternion(this->a+number.a, this->b + number.b, this->c + number.c, this->d + number.d);
}

Quaternion Quaternion::operator-(const Quaternion& number)
{
	return Quaternion(this->a - number.a, this->b - number.b, this->c - number.c, this->d - number.d);
}

Quaternion Quaternion::operator*(const Quaternion& number)
{

	return Quaternion(a*number.a - b*number.b - c*number.c - d*number.d,
		a*number.b+number.a*b+c*number.d-number.c*d,
		a*number.c+number.a*c + d*number.b - number.d*b,
		a*number.d + number.a*d + b*number.c - number.b*c);
}

Quaternion Quaternion::operator/(const Quaternion& num)
{
	Quaternion number = num;
	return (*this * number.conjugate()/(number.norm() * number.norm()));
}

Quaternion Quaternion::operator/(double c)
{
	return Quaternion(this->a/c, this->b/c, this->c/c, this->d/c);
}

bool operator==(const Quaternion& number1, const Quaternion& number2)
{
	if (number1.a == number2.a && number1.b == number2.b && number1.c == number2.c && number1.d == number2.d)
	{
		return true;
	}
	return false;
}

Quaternion operator*(const double k, const Quaternion& number)
{
	return Quaternion(number.a*k, number.b*k, number.c*k, number.d*k);
}

Quaternion operator+(const double k, const Quaternion& number)
{
	return Quaternion(number.a+k, number.b, number.c, number.d);
}

Quaternion operator-(const double k, const Quaternion& number)
{
	return Quaternion(number.a - k, number.b, number.c, number.d);
}

Quaternion operator/(const double k, Quaternion& number)
{
	return k * (number.conjugate()/(number.norm()* number.norm()));
}

Quaternion& Quaternion::operator+=(const Quaternion& q)
{
	this->a += q.a;
	this->b += q.b;
	this->c += q.c;
	this->d += q.d;
	return *this;
}

Quaternion& Quaternion::operator+=(const double summ)
{
	Quaternion t;
	t.a = summ;
	*this += t;
	return *this;
}

Quaternion& Quaternion::operator*=(const Quaternion& q)
{
	double re, i, j, k;
	re = this->a;
	i = this->b;
	j = this->c;
	k = this->d;
	this->a = re * q.a - i * q.b - j * q.c - k * q.d;
	this->b = re * q.b + q.a * i + j * q.d - k * q.c;
	this->c = re * q.c - i * q.d + j * q.a + k * q.b;
	this->d = re * q.d + i * q.c - j * q.b + k * q.a;
	return *this;
}

Quaternion& Quaternion::operator*=(const double k)
{
	Quaternion t;
	t.a = k;
	*this *= t;
	return *this;
}

Quaternion& Quaternion::operator-=(const Quaternion& q)
{
	this->a -= q.a;
	this->b -= q.b;
	this->c -= q.c;
	this->d -= q.d;
	return *this;
}

Quaternion& Quaternion::operator-=(const double summ)
{
	Quaternion t;
	t.a = summ;
	*this -= t;
	return *this;
}

Quaternion& Quaternion::operator/=(const Quaternion& q)
{
	Quaternion t = q;
	(*this *= t.conjugate()) /= (t.norm() * t.norm());
	return *this;

}

Quaternion& Quaternion::operator/=(const double div)
{
	this->a /= div;
	this->b /= div;
	this->c /= div;
	this->d /= div;
	return *this;
}



std::ostream& operator<<(std::ostream& stream,  const Quaternion& q)
{
	if (q.a != 0) stream << q.a;
	if (q.b != 0) stream << (q.b > 0 ? "+" : "") << q.b << "*i";
	if (q.c != 0) stream << (q.c > 0 ? "+" : "") << q.c << "*j";
	if (q.d != 0) stream << (q.d > 0 ? "+" : "") << q.d << "*k";
	return stream;
}
/*
std::istream& operator>>(std::istream& stream, const Quaternion& q)
{
	stream >> q.a >> ' ' >> q.b >> ' ' >> q.c >> ' ' >> q.d;
	return stream;
}*/