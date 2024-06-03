#pragma once
#include <exception>

class IntArray
{
private:
	int* m_data{};
	int m_lenght{};
public:
	IntArray(int lenght);
	IntArray(const IntArray& other);
	~IntArray();

	int getSize() const;

	int& operator[](int index);
	const int& operator[](int index) const;

	IntArray& operator = (const IntArray& ohter);

	void resize(int newLenght);
	void insert(int index, int value);
	void erase(int index);
};

class bad_range : public std::exception
{
public:
	const char* what()const noexcept override
	{
		return "Index out of range for IntArray";
	}
};

class bad_lenght : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Invalid lenght provided for IntArray";
	}
};