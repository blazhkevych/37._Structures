/*
4. Разработать структуру Rectangle, описывающую прямоугольник.
Написать функции для работы с прямоугольником (переменной типа
Rectangle). Например, нормализация прямоугольника, перемещение
прямоугольника, изменение размера прямоугольника, печать
прямоугольника и т. д.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

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

// Функция нормализации прямоугольника
Rectangle Normalization(Rectangle rect)
{
	if (rect.LeftTop.x > rect.RightBottom.x)
	{
		int temp = rect.LeftTop.x;
		rect.LeftTop.x = rect.RightBottom.x;
		rect.RightBottom.x = temp;
	}
	if (rect.LeftTop.y > rect.RightBottom.y)
	{
		int temp = rect.LeftTop.y;
		rect.LeftTop.y = rect.RightBottom.y;
		rect.RightBottom.y = temp;
	}

	return rect;
}

// Функция перемещения прямоугольника
void MoveRectangle(Rectangle& rect, int X_offset, int Y_offset)
{
	// смещение по оси Х
	rect.LeftTop.x += X_offset;
	rect.RightBottom.x += X_offset;

	// смещение по оси Y
	rect.LeftTop.y += Y_offset;
	rect.RightBottom.y += Y_offset;
}

// Функция изменения размера прямоугольника
void ResizingRectangle(Rectangle& rect, int width, int height)
{
	int halfWidth = width / 2;
	int halfHeight = height / 2;

	rect.LeftTop.x -= halfWidth;
	rect.RightBottom.x += halfHeight;

	rect.LeftTop.y -= halfHeight;
	rect.RightBottom.y += halfHeight;
}

// Функция печати прямоугольника
void PrintRectangle(Rectangle rect)
{
	cout << "LeftTop{ " << rect.LeftTop.x << ", " << rect.LeftTop.y << " }";
	cout << "\nRightBottom{ " << rect.RightBottom.x << ", " << rect.RightBottom.y << " }\n";
}

int main()
{
	Rectangle rect;
	cout << "Enter points to draw a rect."
		<< "\nLeftTop ( {x, y} ):\n";
	cin >> rect.LeftTop.x;
	cin >> rect.LeftTop.y;
	cout << "\RightBottom ( {x, y} ):\n";
	cin >> rect.RightBottom.x;
	cin >> rect.RightBottom.y;
	cout << "\"rect\" before Normalization:\n";
	PrintRectangle(rect);
	rect = Normalization(rect);
	cout << "\"rect\" after Normalization:\n";
	PrintRectangle(rect);
	cout << endl;

	Rectangle rect2;
	cout << "Enter points to draw a rect2."
		<< "\nLeftTop ( {x, y} ):\n";
	cin >> rect2.LeftTop.x;
	cin >> rect2.LeftTop.y;
	cout << "\RightBottom ( {x, y} ):\n";
	cin >> rect2.RightBottom.x;
	cin >> rect2.RightBottom.y;
	cout << "\"rect2\" before MoveRectangle:\n";
	PrintRectangle(rect2);
	MoveRectangle(rect2, -1, -1);
	cout << "\"rect2\" after MoveRectangle(-1, -1):\n";
	PrintRectangle(rect2);
	cout << endl;

	Rectangle rect3;
	cout << "Enter points to draw a rect3."
		<< "\nLeftTop ( {x, y} ):\n";
	cin >> rect3.LeftTop.x;
	cin >> rect3.LeftTop.y;
	cout << "\RightBottom ( {x, y} ):\n";
	cin >> rect3.RightBottom.x;
	cin >> rect3.RightBottom.y;
	cout << "\"rect3\" before ResizingRectangle:\n";
	PrintRectangle(rect3);
	ResizingRectangle(rect3, -4, -4);
	cout << "\"rect3\" after ResizingRectangle(-4, -4):\n";
	PrintRectangle(rect3);
	cout << endl;

	return 0;
}