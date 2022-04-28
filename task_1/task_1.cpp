/*
1. Разработать структуру Point, описывающую точку в двумерной
системе координат (x, y). Создать две точки (две переменные типа
Point). Будет ли прямая, проходящая через эти точки, параллельна
оси ординат или оси абсцисс?
*/

#include <iostream>
#include <Windows.h>
using std::cout;
using std::cin;
using std::endl;

// глобальное объявление структуры "Point"
struct Point
{
	// поля структуры, описывающие точку на плоскости
	int x, y;
};

// Функция определяет будет ли прямая, проходящая через эти точки, параллельна
// оси ординат или оси абсцисс 
int IsParallelToOrdAxisOrAbscXxis(Point p1, Point p2)
{
	if (p1.y == p2.y) // Параллельна оси "X".
		return 1;
	else if (p1.x == p2.x) // Параллельна оси "Y".
		return 2;
	else
		return 3; // Не параллельна ничему.
}

int main()
{
	SetConsoleOutputCP(1251);

	Point p1;
	Point p2;

	cout << "Введите 1 точку(x, y):\n";
	cin >> p1.x;
	cin >> p1.y;
	cout << "Введите 2 точку(x, y):\n";
	cin >> p2.x;
	cin >> p2.y;

	int result = IsParallelToOrdAxisOrAbscXxis(p1, p2);

	if (result == 1)
		cout << "Параллельна оси \"X\"." << endl;
	else if (result == 2)
		cout << "Параллельна оси \"Y\"." << endl;
	else if (result == 3)
		cout << "Не параллельна ничему." << endl;

	return 0;
}