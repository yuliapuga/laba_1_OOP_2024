#pragma once
#include <iostream>
using namespace std;
#include <Windows.h>


class Vector {
	int m_len;
	double* m_vector=nullptr;
public:

	//Конструктор з параметром для задання ромірності вектора
	Vector(int n)
	{
		m_len = n;
		m_vector = new double[m_len];
		for (int i = 0; i < m_len; i++) {
			m_vector[i] = 0;
		}
	}
	//конструктор з параметром для задання розмірності вектора 
	//та заповнення його значеннями на основі заданого масиву
	Vector(int n, double vector[]) {
		m_len = n;
		m_vector = new double[n];
		for (int i = 0; i < m_len; i++)
		{
			m_vector[i] = vector[i];
		}

	}
	//Функція для виведення вектора
	void print() const {
		std::cout << "( ";
		for (int i = 0; i < m_len; i++) {
			std::cout << m_vector[i] << " ";
		}
		std::cout << ")" << endl;

	}
	//Функція для встановлення значення
	void setValue(int index, double value) const {
		m_vector[index] = value;
	}

	//Функція для отримання значення
	double getValue(int index) const { return m_vector[index]; }

       //Функція для визначення довжини вектора
	double lenght() const
	{
		double len = 0;
		for (int i = 0; i < m_len; i++) {
			len += pow(m_vector[i], 2);
		}
		len = pow(len, 0.5);
		return len;
	}

	Vector norm() const {
		double* array = new double[m_len];
		int len = lenght();
		if (len == 0) {
			cout << "Неможливо нормувати нульовий вектор!!! " << endl;
			return *this;
		}
		for (int i = 0; i < m_len; i++) {
			array[i] = m_vector[i] / len;
		}
		return Vector(m_len, array);
	}
	~Vector() {
		delete[] m_vector;
	}
};

