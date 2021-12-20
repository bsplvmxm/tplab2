#include "Student.h"

Student::Student() : secondName("Не задано"), iniciales("Не задано"), numberGroup(0)
{
	cout << "Вызван конструктор" << endl;
}

Student::Student(string secondName, string iniciales, int numberGroup, Marray<int> marks) :
	secondName(secondName), iniciales(iniciales), numberGroup(numberGroup), marks(marks)
{
	cout << "Вызван конструктор" << endl;
}

Student::Student(const Student& student) : secondName(student.secondName), iniciales(student.iniciales), 
numberGroup(student.numberGroup), marks(student.marks)
{
	cout << "Вызван конструктор копирования" << endl;
}

Student::~Student()
{
	cout << "Вызван деструктор" << endl;
}

void Student::inputFromConsole()
{
	cout << "Введите фамилию: ";
	getline(cin, secondName);
	cout << "Введите инициалы: ";
	iniciales = inputIniciales();
	cout << "Введите номер группы: ";
	numberGroup = safeInput(1, INT32_MAX);
	cout << "Введите количество оценок: ";
	int countMarks = safeInput(1, INT32_MAX);
	for (int i = 0; i < countMarks; i++) {
		cout << "Введите " << i + 1 << " оценку: ";
		marks +=safeInput(2, 5);
	}
}

void Student::printToConsole()
{
	cout << "ФИО: " << secondName << " " << iniciales << endl;
	cout << "Номер группы: " << numberGroup << endl;
	cout << "Оценки: ";
	for (int i = 0; i < marks.getSize(); i++)
		cout << marks[i] << " ";
	cout << endl;
}

void Student::change()
{
	marks.clear();
	cout << "Введите новую фамилию: ";
	getline(cin, secondName);
	cout << "Введите новые инициалы: ";
	getline(cin, iniciales);
	cout << "Введите новый номер группы: ";
	numberGroup = safeInput(1, INT32_MAX);
	cout << "Введите новое количество оценок: ";
	int countMarks = safeInput(1, INT32_MAX);
	for (int i = 0; i < countMarks; i++) {
		cout << "Введите " << i + 1 << " оценку: ";
		marks += safeInput(2, 5);
	}
}

double Student::getAverageMark() {
	int sum = 0;
	for (int i = 0; i < marks.getSize(); i++)
		sum += marks[i];
	return double(sum) / double(marks.getSize());
}

Student& Student::operator=(const Student& student) {
	if (this == &student)
		return *this;
	secondName = student.secondName;
	iniciales = student.iniciales;
	numberGroup = student.numberGroup;
	marks = student.marks;
	return *this;
}

bool Student::operator>(Student& student) {
	return getAverageMark() > student.getAverageMark();
}