/*
5. Разработать структуру Fraction, описывающую обыкновенную дробь.
Написать функции, реализующие операции сложения, вычитания,
умножения и деления дробей. Все функции должны принимать в
качестве входных параметров две дроби (две переменные типа
Fraction) и возвращать дробь в качестве результата.
*/
// НЕ РАБОТАЕТ
//2:10:00

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// локальное объявление структуры
struct Fraction
{
	int numerator; // числитель
	int denominator; // знаменатель
};

// Функция вычисляет наибольший общий делитель целых чисел (сокращенно НОД)
int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

// Функция вычисляет наименьшее общее кратное (сокращенно НОК)
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

Fraction AdditionOfFractions(Fraction f1, Fraction f2)
{
	// https://allcalc.ru/node/770

	Fraction result{};

	if (f1.denominator == f2.denominator) // Сложение дробей с одинаковыми знаменателями
	{
		result.numerator = f1.numerator + f2.numerator;
		result.denominator = f1.denominator;
		// Важно: Если есть возможность сократить дробь, то в конечный ответ мы записываем сокращенную дробь.
		// https://allcalc.ru/node/765
	}
	else if (f1.denominator != f2.denominator) // Сложение дробей с разными знаменателями
	{
		// 1) Приводим дроби к общему знаменателю.
		// Для этого ищем НОК - наименьшее общее кратное, для знаменателей
		int nok = LCM(f1.denominator, f2.denominator);

		// Дальше домножаем дроби на дополнительные множители и получаем выражение
		// 2) Складываем дроби.
		result.numerator = (nok / f1.denominator * f1.numerator) + (nok / f2.denominator * f2.numerator);
		result.denominator = nok;
	}

	return result;
}

int main()
{
	Fraction f1, f2, result;
	char action;
	cout << "Enter a fraction.\n";
	cout << "Enter a numerator for 1 fraction: ";
	cin >> f1.numerator;
	cout << "Enter a denominator for 1 fraction: ";
	cin >> f1.denominator;

	cout << "Enter an action: ";
	cin >> action;

	cout << "Enter a numerator for 2 fraction: ";
	cin >> f2.numerator;
	cout << "Enter a denominator for 2 fraction: ";
	cin >> f2.denominator;

	result = AdditionOfFractions(f1, f2);

	cout << "Result:\n"
		<< result.numerator << endl
		<< "--\n"
		<< result.denominator << endl;

	return 0;
}