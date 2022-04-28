/*
2. Разработать структуру Rectangle, описывающую прямоугольник.
Создать прямоугольник (переменную типа Rectangle) и точку
(переменную типа Point). Написать функцию для определения
попадания точки в прямоугольник.
*/

#include <iostream>
using std::cout;
using std::cin;

// глобальное объявление структуры "Point"
struct Point
{
	// поля структуры, описывающие точку на плоскости
	int x, y;
};

// глобальное объявление структуры "Rectangle"
struct Rectangle
{
	// поля структуры, задающие прямоугольник по координатам левого верхнего и правого нижнего углов
	Point LeftTop;
	Point RightBottom;
};

// Функция определения
// попадания точки в прямоугольник.
bool IsPointInRectangle(Rectangle rect, Point point)
{
	if (point.x >= rect.LeftTop.x && point.x <= rect.RightBottom.x &&
		point.y >= rect.LeftTop.y && point.y <= rect.RightBottom.y)
		return true; // принадлежит прямоугольнику
	else
		return false; // не принадлежит прямоугольнику
}

int main()
{
	Rectangle rect;
	Point point;

	cout << "Enter points to draw a rectangle."
		<< "\nLeftTop ( {x, y} ):\n";
	cin >> rect.LeftTop.x;
	cin >> rect.LeftTop.y;
	cout << "\RightBottom ( {x, y} ):\n";
	cin >> rect.RightBottom.x;
	cin >> rect.RightBottom.y;

	cout << "Enter point( {x, y} ):\n";
	cin >> point.x;
	cin >> point.y;

	if (IsPointInRectangle(rect, point) == true)
		cout << "Inside\n";
	else
		cout << "Outside\n";

	return 0;
}