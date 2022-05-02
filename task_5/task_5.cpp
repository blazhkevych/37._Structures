/*
5. Разработать структуру Fraction, описывающую обыкновенную дробь.
Написать функции, реализующие операции сложения, вычитания,
умножения и деления дробей. Все функции должны принимать в
качестве входных параметров две дроби (две переменные типа
Fraction) и возвращать дробь в качестве результата.
*/
// сложения -> работает
// вычитания ->
// умножения ->
// деления -> 
//2:10:00

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// локальное объявление структуры
struct Fraction
{
	int whole; // целое
	int numerator; // числитель
	int denominator; // знаменатель
};

// Функция вычисляет наибольший общий делитель целых чисел (сокращенно НОД)
int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

// Функция сокращения дробей
Fraction FractReduction(Fraction f)
{
	Fraction result{};

	int nod = GCD(f.numerator, f.denominator);
	if (nod == 1)
		return f;
	else
	{
		result.whole = f.whole; // 0
		result.numerator = f.numerator / nod; // 1
		result.denominator = f.denominator / nod; // 1

		if (result.numerator == result.denominator)
		{
			result.whole = result.whole + (result.numerator / result.denominator);
			result.numerator = 0;
			result.denominator = 0;
		}

		return result;
	}
}

// Функция превращения неправильной дроби в смешанное число.
Fraction ConvIncorFractToMixNum(Fraction f)
{
	Fraction result{};

	result.whole = int(f.numerator / f.denominator);
	result.numerator = f.numerator - (result.whole * f.denominator);
	result.denominator = f.denominator;

	return result;
}

// Функция превращения смешанного числа в неправильную дробь.
Fraction ConvMixedNumToIncorrFract(Fraction f)
{
	if (f.whole == 0)
		return f;
	else
	{
		Fraction result{};
		result.numerator = f.whole * f.denominator + f.numerator;
		result.denominator = f.denominator;

		return result;
	}
}

// Функция вычисляет наименьшее общее кратное (сокращенно НОК)
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

// Функция реализующая операцию сложения
Fraction AdditionOfFractions(Fraction f1, Fraction f2)
{
	Fraction f1Copy = f1;
	Fraction f2Copy = f2;
	if (f1Copy.whole > 0)
		f1Copy = ConvMixedNumToIncorrFract(f1Copy);
	if (f2Copy.whole > 0)
		f2Copy = ConvMixedNumToIncorrFract(f2Copy);

	Fraction result{};

	// Сложение дробей с одинаковыми знаменателями
	if (f1Copy.denominator == f2Copy.denominator)
	{
		result.whole = f1Copy.whole + f2Copy.whole;
		result.numerator = f1Copy.numerator + f2Copy.numerator;
		result.denominator = f1Copy.denominator;
	}

	// Сложение дробей с разными знаменателями
	else if (f1Copy.denominator != f2Copy.denominator)
	{
		int nok = LCM(f1Copy.denominator, f2Copy.denominator);

		result.numerator = (nok / f1Copy.denominator * f1Copy.numerator) + (nok / f2Copy.denominator * f2Copy.numerator);
		result.denominator = nok;
	}

	if (result.numerator > result.denominator)
		result = ConvIncorFractToMixNum(result);

	result = FractReduction(result);
	return result;
}

// Функция для ввода дроби
void Input(Fraction& f)
{
	cout << "whole: ";
	cin >> f.whole;
	cout << "numerator: ";
	cin >> f.numerator;
	cout << "denominator: ";
	cin >> f.denominator;
}

// Функция для вывода дроби
void Print(Fraction f)
{
	cout << "\nResult:\n";
	if (f.whole)
		cout << f.whole << ' ';
	if (f.numerator && f.denominator)
		cout << f.numerator << '/' << f.denominator << endl;
}

// Функция выполняет вычитание дробей
Fraction FractionSubtraction(Fraction f1, Fraction f2)
{
	Fraction f1Copy = f1;
	Fraction f2Copy = f2;
	if (f1Copy.whole > 0)
		f1Copy = ConvMixedNumToIncorrFract(f1Copy);
	if (f2Copy.whole > 0)
		f2Copy = ConvMixedNumToIncorrFract(f2Copy);

	Fraction result{};

	// Вычитание дробей с одинаковыми знаменателями.
	if (f1Copy.denominator == f2Copy.denominator && f1Copy.whole == 0 && f2Copy.whole == 0)
	{
		result.numerator = f1Copy.numerator - f2Copy.numerator;
		result.denominator = f1Copy.denominator;
	}

	// Вычитание обычных дробей
	else if (f1Copy.denominator != f2Copy.denominator && f1Copy.whole == 0 && f2Copy.whole == 0)
	{
		int nok = LCM(f1Copy.denominator, f2Copy.denominator);

		result.numerator = (nok / f1Copy.denominator * f1Copy.numerator) - (nok / f2Copy.denominator * f2Copy.numerator);
		result.denominator = nok;
	}

	if (result.numerator > result.denominator)
		result = ConvIncorFractToMixNum(result);

	result = FractReduction(result);
	return result;
}



int main()
{
	Fraction f1{}, f2{}, result{};
	char action;

	cout << "Enter first fraction.\n";
	Input(f1);

	cout << "Enter an action: ";
	cin >> action;

	cout << "Enter second fraction.\n";
	Input(f2);

	switch (action)
	{
	case '+':
		result = AdditionOfFractions(f1, f2);
		break;

	case '-':
		result = FractionSubtraction(f1, f2);
		break;

	case '*':
		//result = AdditionOfFractions(f1, f2);
		break;

	case '/':
		//result = AdditionOfFractions(f1, f2);
		break;

	default:
		cout << "Try again !" << endl;
		break;
	}



	Print(result);

	return 0;
}