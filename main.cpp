/* Gurnaman Singh
* 2/1/2021
* HW 2 - Templates
* This program creates a template class and implements the Rule of Five to safely manage and dynamically allocate 
* resources. With templates, it is easy for the user to create an array of any data type and modify or access elements.
*/

#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iostream>
#include "offset_array.h"

int main()
{
	// Test class object of int type
	nwacc::offset_array<int, 100, 105> array_one;
	array_one[100] = 1;
	array_one[101] = 2;
	array_one[102] = 3;
	array_one[103] = 4;
	array_one[104] = 5;
	array_one[105] = 6;
	// Try-catch statements to test if out-of-range exception is properly thrown and caught
	// If accessing element from array index that is lower or higher than the bounds written 
	try {
		array_one[106] = 7;
	}
	catch (std::out_of_range& e) {
		std::cout << "Exception -- " << e.what() << std::endl;
	}

	std::cout << "Array of numbers 1: " << array_one << std::endl;
	std::cout << "Fourth item is " << array_one[103] << std::endl;

	try {
		std::cout << array_one[99] << std::endl;
	}
	catch (std::out_of_range& e) {
		std::cout << "Exception -- " << e.what() << std::endl << std::endl;
	}

	// Test class object of string type
	nwacc::offset_array<std::string, 20, 31> array_two;
	array_two[20] = "first item";
	array_two[21] = "second item";
	array_two[31] = "last item";

	std::cout << "Array of strings: " << array_two << std::endl;
	std::cout << "This should return empty string: " << array_two[30] << std::endl;
	
	try {
		std::cout << array_one[32] << std::endl;
	}
	catch (std::out_of_range& e) {
		std::cout << "Exception -- " << e.what() << std::endl;
	}

	std::cout << "This should return the last element: " << array_two[31] << std::endl;

	try {
		std::cout << array_one[32] << std::endl;
	}
	catch (std::out_of_range& e) {
		std::cout << "Exception -- " << e.what() << std::endl;
	}

	// Test if copy constructor is called
	// and make sure changing one object does not change the other
	nwacc::offset_array<int, 100, 105> array_three(array_one);
	std::cout << "Array of numbers 2 (Copy of numbers 1): " << array_three << std::endl;

	// Test if changing array_one changes array_three
	array_one[100] = 2;
	std::cout << "Numbers 1 (changed): " << array_one << std::endl;
	std::cout << "Numbers 2: " << array_three << std::endl;

	// Test if changing array_three changes array_one
	array_three[104] = 6;
	std::cout << "Numbers 2 (changed): " << array_three << std::endl;
	std::cout << "Numbers 1: " << array_one << std::endl;

	// Test if copy assignment operator is called
	// and make sure changing one object does not change the other
	nwacc::offset_array<int, 100, 105> array_four;
	array_four = array_one;
	std::cout << "Array of numbers 3 (Assigned copy of numbers 1): " << array_four << std::endl;

	// Test if changing array_one changes array_four
	array_one[100] = 1;
	std::cout << "Numbers 1 (changed): " << array_one << std::endl;
	std::cout << "Numbers 3: " << array_four << std::endl;

	// Test if changing array_four changes array_one
	array_four[105] = 7;
	std::cout << "Numbers 3 (changed): " << array_four << std::endl;
	std::cout << "Numbers 1: " << array_one << std::endl;

	// Test if move constructor and move assignment operator are called
	std::vector<nwacc::offset_array<int, 50, 60> > array_objects(2);
	std::sort(array_objects.begin(), array_objects.end());
}