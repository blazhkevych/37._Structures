/*
1. Разработать структуру Point, описывающую точку в двумерной
системе координат (x, y). Создать две точки (две переменные типа
Point). Будет ли прямая, проходящая через эти точки, параллельна
оси ординат или оси абсцисс?
*/

#include <iostream>
#include <Windows.h>
using std::cout;
using std::endl;

// глобальное объявление структуры "Point"
struct Point
{
	// поля структуры, описывающие точку на плоскости
	int x, y;
};

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

	Point p1{ 3, 2 };
	Point p2{ 3, 4 };

	int result = IsParallelToOrdAxisOrAbscXxis(p1, p2);

	if (result == 1)
		cout << "Параллельна оси \"X\"." << endl;
	else if (result == 2)
		cout << "Параллельна оси \"Y\"." << endl;
	else if (result == 3)
		cout << "Не параллельна ничему." << endl;

	return 0;
}