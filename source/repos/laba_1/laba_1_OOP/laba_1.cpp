#include <iostream>
#include <windows.h>
#include<math.h>
#include "Vector.h"
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Перевірка першого класу

	cout << "Vector class\n";
	Vector v1(3);
	double vector2[] = { 1,2,3,4,5 };
	Vector v2(5, vector2);

	cout << "First vector: ";
	v1.print();
	cout << "Second vector: ";
	v1.print();

	v1.setValue(2, 9);
	v2.setValue(0, 567);

	cout << "First vector: ";
	v1.print();
	cout << "Second vector: ";
	v1.print();

	cout << v1.getValue(2) << endl;
	cout << v2.getValue(4) << endl;

	cout << v2.lenght() << endl;

	Vector v3 = v2.norm();
	cout << "Norm Vector: ";
	v3.print();

	return 0;
}