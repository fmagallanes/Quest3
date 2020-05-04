#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//int read_file();

class Fraction
{
private:
	int num;								// numerator and denominator
	int den;

public:
	void set(int n, int d)
	{
		num = n;
		den = d;
		normalize();
	}

	int get_num()
	{
		return num;
	}

	int get_den()
	{
		return den;
	}

	Fraction add(Fraction other);
	Fraction mult(Fraction other);
	
	bool equality(Fraction other);


private:
	void normalize();						// converts to standard form
	int gcf(int a, int b);					// greatest common factor
	int lcm(int a, int b);					// least common multiple
};

int main()
{
	int userNum1, userDen1, userNum2, userDen2;
	Fraction fract1, fract2, fract3, fract4;
	char choice;
	while (true)
	{
		cout << "Enter numerator of first fraction: ";
		cin >> userNum1;
		cout << "Enter denominator of first fraction: ";
		cin >> userDen1;
		cout << "Enter numerator of second fraction: ";
		cin >> userNum2;
		cout << "Enter denominator of second fraction: ";
		cin >> userDen2;
		fract1.set(userNum1, userDen1);								//sets 1st fraction
		fract2.set(userNum2, userDen2);								//sets 2nd fraction
		fract3 = fract1.add(fract2);									//sum of fractions
		fract4 = fract1.mult(fract2);									//product of fractions
		cout << fract1.get_num() << "/" << fract1.get_den() << " + ";
		cout << fract2.get_num() << "/" << fract2.get_den() << " = ";
		cout << fract3.get_num() << "/" << fract3.get_den() << endl;	//print out sum

		cout << fract1.get_num() << "/" << fract1.get_den() << " * ";
		cout << fract2.get_num() << "/" << fract2.get_den() << " = ";
		cout << fract4.get_num() << "/" << fract4.get_den() << endl;	//print out product

		cout << "Again? (Y/N) ";
		cin >> choice;
		if (!(choice == 'Y' || choice == 'y'))
		{
			break;
		}	
	}
	return 0;
}

/* int read_file()
{
	int myVar;
	ifstream fin;
	fin.open("example.csv");
	fin >> myVar;
	fin.close();

	return myVar;
}  */

void Fraction::normalize()
{
	if (den == 0 || num == 0)					// cases with 0
	{
		num = 0;
		den = 1;
	}

	if (den < 0)								// puts negative sign in numerator only
	{
		num *= -1;
		den *= -1;
	}

	int n = gcf(num, den);						// factor out gcf from num and den
	num /= n;
	den /= n;
}

int Fraction::gcf(int a, int b)
{
	if (b == 0)
	{
		return abs(a);
	}
	else
	{
		return gcf(b, a % b);
	}
}

int Fraction::lcm(int a, int b)
{
	int n = gcf(a, b);
	return a / n * b;
}

Fraction Fraction::add(Fraction other)				// Returns object Fraction, in Fraction class scope, other is of Fraction type
{
	Fraction fract;
	int lcd = lcm(den, other.den);
	int quotient1 = lcd / den;
	int quotient2 = lcd / other.den;
	fract.set(num * quotient1 + other.num * quotient2, lcd);
	return fract;
}

Fraction Fraction::mult(Fraction other)
{
	Fraction fract;
	fract.set(num * other.num, den * other.den);
	return fract;
}

bool equality(Fraction other)
{
	Fraction fract1, fract2;
	
}