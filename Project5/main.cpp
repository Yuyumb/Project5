#include <iostream>
#include "IntegerArray.h"

int main()
{
	try
	{
		IntArray arr(5);
		for (int i = 0; i < arr.getSize(); ++i)
		{
			arr[i] = i * 2;
		}

		std::cout << "Array elements: ";
		for (int i = 0; i < arr.getSize(); ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Trying to access an element out of range..." << std::endl;
		std::cout << arr[arr.getSize()] << std::endl;
	}
	catch (const bad_lenght& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const bad_range& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}