/*
3. Разработать структуру Person, описывающую человека. Написать
функцию, в которую передается по ссылке переменная типа Person.
Функция должна заполнить данными эту переменную. Кроме того,
предусмотреть функцию, в которую передается по значению
переменная типа Person. Функция должна выводить в консоль
данные, хранящиеся в этой переменной.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// глобальное объявление структуры "Person"
struct Person
{
	// поля структуры, описывающие человека
	char name[10]; // имя
	char surname[15]; // фамилия
	int age; // возраст
	char gender[10]; // пол
};

// Функция принимает по ссылке струтуру типа Person и заполняет данными эту струтуру.
void Input(Person& p)
{
	cout << "Enter name: ";
	cin >> (p.name);

	cout << "Enter surname: ";
	cin >> p.surname;

	cout << "Enter age: ";
	cin >> p.age;

	cout << "Enter gender: ";
	cin >> p.gender;
}

void Print(Person p)
{
	cout << "Name: ";
	cout << p.name;

	cout << "\nSurname: ";
	cout << p.surname;

	cout << "\nAge: ";
	cout << p.age;

	cout << "\nGender: ";
	cout << p.gender;
}

int main()
{
	Person pers;
	Input(pers);
	cout << endl;
	Print(pers);

	return 0;
}