#ifndef NUMBER_H
#define NUMBER_H


#include <iostream>
#include <cmath>

using std::ostream;

class Number
{
public:
	virtual Number operator+(const Number & other)
	{
		return Number();
	}
	virtual Number operator*(const Number & other)
	{
		return Number();
	}
};

class RealNumber : public Number
{
private:
	double _value;

public:
	RealNumber(double v)
	{
		_value = v;
	}
	double getValue() const
	{
		return _value;
	}
	friend ostream & operator<<(ostream & os, const RealNumber & value)
	{
		os << value._value;
		return os;
	}
	virtual RealNumber operator+(const RealNumber & other)
	{
		RealNumber sum(_value + other.getValue());
		return sum;
	}
	virtual RealNumber operator*(const RealNumber & other)
	{
		RealNumber mul(_value*other.getValue());
		return mul;
	}
};

class IntegerNumber : public RealNumber
{
public:
	IntegerNumber(int v)
		:RealNumber(v)
	{}
	IntegerNumber operator+(const IntegerNumber & other)
	{
		IntegerNumber sum(getValue() + other.getValue());
		return sum;
	}
	IntegerNumber operator*(const IntegerNumber & other)
	{
		IntegerNumber mul(getValue() * other.getValue());
		return mul;
	}
};

class ComplexNumber : public Number
{
private:
	double _realPart;
	double _imaginaryPart;

public:
	ComplexNumber(double v1, double v2)
	{
		_realPart = v1;
		_imaginaryPart = v2;
	}
	double getRealPart() const
	{
		return	_realPart;
	}
	double getImaginaryPart() const
	{
		return _imaginaryPart;
	}
	friend ostream & operator<<(ostream & os, const ComplexNumber & value)
	{
		os << value._realPart << "+" << value._imaginaryPart << "i";
		return os;
	}
	ComplexNumber operator+(const ComplexNumber & other)
	{
		ComplexNumber sum(_realPart + other.getRealPart(), _imaginaryPart + other.getImaginaryPart());
		return sum;
	}
	ComplexNumber operator*(const ComplexNumber & other)
	{
		double a = _realPart * other.getRealPart() - _imaginaryPart * other.getImaginaryPart();
		double b = _imaginaryPart * other.getRealPart() + _realPart * other.getImaginaryPart();
		ComplexNumber mul(a, b);
		return mul;
	}
};

#endif

