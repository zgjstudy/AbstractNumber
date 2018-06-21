#include "number.h"
using namespace std;
int main()
{
	RealNumber r1(10.5);
	RealNumber r2(2);
	RealNumber r3 = r1 + r2;
	RealNumber r4 = r1 * r2;
	IntegerNumber i1(10);
	IntegerNumber i2(5);
	IntegerNumber i3 = i1 + i2;
	IntegerNumber i4 = i1 * i2;
	ComplexNumber c1(10, 4);
	ComplexNumber c2(5, 2);
	ComplexNumber c3 = c1 + c2;
	ComplexNumber c4 = c1 * c2;

	cout << r1 << endl
		<< r2 << endl
		<< r3 << endl
		<< r4 << endl
		<< i1 << endl
		<< i2 << endl
		<< i3 << endl
		<< i4 << endl
		<< c1 << endl
		<< c2 << endl
		<< c3 << endl
		<< c4 << endl;

	return 0;
}
