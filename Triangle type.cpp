#include <iostream>

using namespace std;

enum triangleType { scalene, isosceles, equilateral, noTriangle };

triangleType triangleShape(double a, double b, double c);

int main()
{
	double s1, s2, s3;
	cout << "Enter the lenths of 3 sides of a trinagle: " << endl;
	cin >> s1 >> s2 >> s3;
	triangleType type = triangleShape(s1, s2, s3);
	switch (type)
	{
	case scalene:
		cout << "The triangle is scalene." << endl;
		break;
	case isosceles:
		cout << "The triangle is isosceles." << endl;
		break;
	case equilateral:
		cout << "The triangle is equilateral." << endl;
		break;
	case noTriangle:
		cout << "This is not  triangle." << endl;
	}


	return 0;
}

triangleType triangleShape(double a, double b, double c)
{
	// In a trinagle the sum of lengths of any two sides is greater than the length of the third side.
	if (a + b > c && a + c > b && b + c > a)
	{
		if (a == b && b == c)
			return equilateral;
		else if (a == b || a == c || b == c)
			return isosceles;
		else
			return scalene;

	}
	else
		return noTriangle;
}
