#pragma once
#include <iostream>
using namespace std;
#include <Windows.h>


class Vector {
	int m_len;
	double* m_vector=nullptr;
public:

	//����������� � ���������� ��� ������� �������� �������
	Vector(int n)
	{
		m_len = n;
		m_vector = new double[m_len];
		for (int i = 0; i < m_len; i++) {
			m_vector[i] = 0;
		}
	}
	//����������� � ���������� ��� ������� ��������� ������� 
	//�� ���������� ���� ���������� �� ����� �������� ������
	Vector(int n, double vector[]) {
		m_len = n;
		m_vector = new double[n];
		for (int i = 0; i < m_len; i++)
		{
			m_vector[i] = vector[i];
		}

	}
	//������� ��� ��������� �������
	void print() const {
		std::cout << "( ";
		for (int i = 0; i < m_len; i++) {
			std::cout << m_vector[i] << " ";
		}
		std::cout << ")" << endl;

	}
	//������� ��� ������������ ��������
	void setValue(int index, double value) const {
		m_vector[index] = value;
	}

	//������� ��� ��������� ��������
	double getValue(int index) const { return m_vector[index]; }

	//������� ��� ���������� ������� �������
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
			cout << "��������� ��������� �������� ������!!! " << endl;
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

