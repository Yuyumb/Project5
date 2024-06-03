#include "IntegerArray.h"

IntArray::IntArray(int lenght) : m_lenght(lenght)
{
	if (lenght == 0)
	{
		throw bad_lenght();
	}
	m_data = new int[lenght];
}

IntArray::IntArray(const IntArray& other) : m_lenght(other.m_lenght)
{
	m_data = new int[m_lenght];
	for (int i = 0; i < m_lenght; ++i)
	{
		m_data[i] = other.m_data[i];
	}
}

IntArray::~IntArray()
{
	delete[] m_data;
}

int IntArray::getSize() const
{
	return m_lenght;
}

int& IntArray::operator[](int index)
{
	if (index >= m_lenght)
	{
		throw bad_range();
	}
	return m_data[index];
}

const int& IntArray::operator[](int index) const
{
	if (index >= m_lenght)
	{
		throw bad_range();
	}
	return m_data[index];
}

IntArray& IntArray::operator = (const IntArray& other)
{
	if (this != &other)
	{
		delete[] m_data;
		m_lenght = other.m_lenght;
		m_data = new int[m_lenght];
		for (int i = 0; i < m_lenght; ++i)
		{
			m_data[i] = other.m_data[i];
		}
	}
	return *this;
}

void IntArray::resize(int newLenght)
{
	if (newLenght == 0)
	{
		throw bad_lenght();
	}
	int* newData = new int[newLenght];
	int minSize = (newLenght < m_lenght) ? newLenght : m_lenght;
	for (int i = 0; i < minSize; ++i)
	{
		newData[i] = m_data[i];
	}
	delete[] m_data;
	m_data = newData;
	m_lenght = newLenght;
}

void IntArray::insert(int index, int value)
{
	if (index > m_lenght)
	{
		throw bad_range();
	}
	resize(m_lenght + 1);
	for (int i = m_lenght - 1; i > index; --i)
	{
		m_data[i] = m_data[i - 1];
	}
	m_data[index] = value;
}

void IntArray::erase(int index)
{
	if (index >= m_lenght)
	{
		throw bad_range();
	}
	for (int i = index; i < m_lenght - 1; ++i)
	{
		m_data[i] = m_data[i + 1];
	}
	resize(m_lenght - 1);
}