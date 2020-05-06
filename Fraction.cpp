#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <assert.h>

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
	Fraction sub(Fraction other);
	Fraction mult(Fraction other);
	Fraction div(Fraction other);
	
	Fraction operator+(Fraction rhs)
	{
		return add(rhs);
	}
	
	Fraction operator-(Fraction rhs)
	{
		return sub(rhs);
	}

	Fraction operator*(Fraction rhs)
	{
		return mult(rhs);
	}

	Fraction operator/(Fraction rhs)
	{
		return div(rhs);
	}

	bool equality(Fraction other);

	bool operator == (Fraction rhs);
	bool operator != (Fraction rhs);

	bool operator > (Fraction rhs);
	bool operator < (Fraction rhs);
	bool operator >= (Fraction rhs);
	bool operator <= (Fraction rhs);
	
	void normalize();						// converts to standard form
	int gcf(int a, int b);					// greatest common factor
	int lcm(int a, int b);					// least common multiple
};

int main()
{
	Fraction fract1, fract2, fract3, fract4, fract5, fract6;
	Fraction result1, result2, result3;
	vector<string>lineCells;
	std::ifstream csvFile("C:\\Users\\knarf\\source\\repos\\Practice CPP\\Practice CPP\\example.csv");

	std::string line;
	
	while (std::getline(csvFile, line))
	{
		//assert(!fin.fail());
		std::stringstream lineStream(line);
		std::string	cell;
		
		//while (!fin.eof())
		//{
			while (std::getline(lineStream, cell, ','))
			{
				lineCells.push_back(cell);
			}
		//}
		//fin.close();
		//assert(!fin.fail());
	}

	string firstNum = lineCells[0];
	string firstDen = lineCells[1];
	string op = lineCells[2];
	string secondNum = lineCells[3];
	string secondDen = lineCells[4];
	string firstNum2 = lineCells[5];
	string firstDen2 = lineCells[6];
	string op2 = lineCells[7];
	string secondNum2 = lineCells[8];
	string secondDen2 = lineCells[9];
	string firstNum3 = lineCells[10];
	string firstDen3 = lineCells[11];
	string op3 = lineCells[12];
	string secondNum3 = lineCells[13];
	string secondDen3 = lineCells[14];

	
	fract1.set(stoi(firstNum), stoi(firstDen));
	fract2.set(stoi(secondNum), stoi(secondDen));
	fract3.set(stoi(firstNum2), stoi(firstDen2));
	fract4.set(stoi(secondNum2), stoi(secondDen2)); 
	fract5.set(stoi(firstNum3), stoi(firstDen3));
	fract6.set(stoi(secondNum3), stoi(secondDen3));

	if (op == "+")
	{
		result1 = fract1 + fract2;
		cout << result1.get_num() << "/" << result1.get_den() << endl;
	}

	if (op == "-")
	{
		result1 = fract1 - fract2;
		cout << result1.get_num() << "/" << result1.get_den() << endl;
	}

	if (op == "*")
	{
		result1 = fract1 * fract2;
		cout << result1.get_num() << "/" << result1.get_den() << endl;
	}

	if (op == "/")
	{
		result1 = fract1 / fract2;
		cout << result1.get_num() << "/" << result1.get_den() << endl;
	}

	if (op2 == "==")
	{
		//result2 = (fract3 == fract4);
		if ('true')
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " = " << fract4.get_num() << "/" << fract4.get_den() << endl;
		}
		else
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " is not equal to " << fract4.get_num() << "/";
			cout << fract4.get_den() << endl;
		}
	}

	if (op2 == "!=")
	{
		//result2 = (fract3 == fract4);
		if ('true')
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " is not equal to " << fract4.get_num() << "/";
			cout << fract4.get_den() << endl; 
		}
		else
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " = " << fract4.get_num() << "/" << fract4.get_den() << endl;
		}
	}
	
	if (op2 == ">")
	{
		//result2 = (fract3 == fract4);
		if ('true')
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " > " << fract4.get_num() << "/";
			cout << fract4.get_den() << endl;
		}
		else
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " < " << fract4.get_num() << "/" << fract4.get_den() << endl;
		}
	}

	if (op2 == "<")
	{
		//result2 = (fract3 == fract4);
		if ('true')
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " < " << fract4.get_num() << "/";
			cout << fract4.get_den() << endl;
		}
		else
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " > " << fract4.get_num() << "/" << fract4.get_den() << endl;
		}
	}

	if (op2 == ">=")
	{
		//result2 = (fract3 == fract4);
		if ('true')
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " >= " << fract4.get_num() << "/";
			cout << fract4.get_den() << endl;
		}
		else
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " is not greater than or equal to " << fract4.get_num() << "/" << fract4.get_den() << endl;
		}
	}

	if (op2 == "<=")
	{
		//result2 = (fract3 == fract4);
		if ('true')
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " <= " << fract4.get_num() << "/";
			cout << fract4.get_den() << endl;
		}
		else
		{
			cout << fract3.get_num() << "/" << fract3.get_den();
			cout << " is not less than or equal to " << fract4.get_num() << "/" << fract4.get_den() << endl;
		}
	}

	if (op3 == "+")
	{
		result3 = fract5 + fract6;
		cout << result3.get_num() << "/" << result3.get_den() << endl;
	}

	if (op3 == "-")
	{
		result3 = fract5 - fract6;
		cout << result3.get_num() << "/" << result3.get_den() << endl;
	}

	if (op3 == "*")
	{
		result3 = fract5 * fract6;
		cout << result3.get_num() << "/" << result3.get_den() << endl;
	}

	if (op3 == "/")
	{
		result3 = fract5 / fract6;
		cout << result3.get_num() << "/" << result3.get_den() << endl;
	}

	// can't figure out how to use the destructor 

/*	int userNum1, userDen1, userNum2, userDen2;
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
		//fract3 = fract1.add(fract2);									//sum of fractions
		//fract4 = fract1.mult(fract2);									//product of fractions
		
		fract3 = fract1 + fract2;
		fract4 = fract1 * fract2;
		
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
	}	*/
	return 0;
}


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

Fraction Fraction::sub(Fraction other)				// Returns object Fraction, in Fraction class scope, other is of Fraction type
{
	Fraction fract;
	int lcd = lcm(den, other.den);
	int quotient1 = lcd / den;
	int quotient2 = lcd / other.den;
	fract.set(num * quotient1 - other.num * quotient2, lcd);
	return fract;
}

Fraction Fraction::mult(Fraction other)
{
	Fraction fract;
	fract.set(num * other.num, den * other.den);
	return fract;
}

Fraction Fraction::div(Fraction other)
{
	Fraction fract;
	fract.set(num / other.num, den / other.den);
	return fract;
}

bool Fraction::equality(Fraction other)
{
	Fraction fract1 = *this;
	Fraction fract2 = other;
	fract1.normalize();
	fract2.normalize();
	return false;
}

bool Fraction::operator == (Fraction rhs)
{
	Fraction fract1 = *this;
	Fraction fract2 = rhs;
	fract1.normalize();
	fract2.normalize();
	if (fract1.get_num() == fract2.get_num())
	{
		if (fract1.get_den() == fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Fraction::operator != (Fraction rhs)
{
	Fraction fract1 = *this;
	Fraction fract2 = rhs;
	fract1.normalize();
	fract2.normalize();
	if (fract1.get_num() != fract2.get_num())
	{
		if (fract1.get_den() != fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Fraction::operator > (Fraction rhs)
{
	Fraction fract1 = *this;
	Fraction fract2 = rhs;
	fract1.normalize();
	fract2.normalize();
	if (fract1.get_num() == fract2.get_num())
	{
		if (fract1.get_den() < fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	if (fract1.get_num() > fract2.get_num())
	{
		if (fract1.get_den() == fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	if (fract1.get_num() < fract2.get_num())
	{
		if (fract1.get_den() < fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Fraction::operator < (Fraction rhs)
{
	Fraction fract1 = *this;
	Fraction fract2 = rhs;
	fract1.normalize();
	fract2.normalize();	
	if (fract1.get_num() == fract2.get_num())
	{
		if (fract1.get_den() > fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	if (fract1.get_num() < fract2.get_num())
	{
		if (fract1.get_den() == fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	if (fract1.get_num() > fract2.get_num())
	{
		if (fract1.get_den() > fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Fraction::operator >= (Fraction rhs)
{
	Fraction fract1 = *this;
	Fraction fract2 = rhs;
	fract1.normalize();
	fract2.normalize();
	if (fract1.get_num() == fract2.get_num())
	{
		if (fract1.get_den() <= fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	if (fract1.get_num() >= fract2.get_num())
	{
		if (fract1.get_den() == fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	if (fract1.get_num() <= fract2.get_num())
	{
		if (fract1.get_den() <= fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Fraction::operator <= (Fraction rhs)
{
	Fraction fract1 = *this;
	Fraction fract2 = rhs;
	fract1.normalize();
	fract2.normalize();
	if (fract1.get_num() == fract2.get_num())
	{
		if (fract1.get_den() >= fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	if (fract1.get_num() <= fract2.get_num())
	{
		if (fract1.get_den() == fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	if (fract1.get_num() >= fract2.get_num())
	{
		if (fract1.get_den() >= fract2.get_den())
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}