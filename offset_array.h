/* Gurnaman Singh
* 2/1/2021
* HW 2 - Templates
* This program creates a template class and implements the Rule of Five to safely manage and dynamically allocate 
* resources. With templates, it is easy for the user to create an array of any data type and modify or access elements.
*/

#ifndef OFFSET_ARRAY_H
#define OFFSET_ARRAY_H

#include <stdexcept>
#include <iostream>

namespace nwacc {

	template<typename T, int S, int E>
	class offset_array {
	private:
		T* array;
		int array_size;

	public:
		// Default constructor
		offset_array() 
			: array_size{1 + (E - S)}
		{
			std::cout << "Default constructor is called." << std::endl;

			this->array = new T[this->array_size];
			for (int i = 0; i < this->array_size; i++) {
				this->array[i] = T();
			}
		}

		// Move constructor
		offset_array(offset_array&& other)
			: array_size{ other.array_size }
		{
			std::cout << "Move constructor is called." << std::endl;

			this->array = other.array;
			other.array_size = 0;
			other.array = nullptr;			
		}

		// Copy constructor
		offset_array(const offset_array& other)
			: array_size{ other.array_size }
		{
			std::cout << std::endl << "Copy constructor is called." << std::endl;

			this->array = new T[this->array_size];
			for (int i = 0; i < this->array_size; i++) {
				this->array[i] = other.array[i];
			}
		}

		// Destructor
		~offset_array() {
			std::cout << "Destructor is called." << std::endl;
			delete[] this->array;
		}

		// Move assignment operator
		offset_array& operator=(offset_array&& rhs) {
			std::cout << "Move assignment operator is called." << std::endl;

			if (this != &rhs) {
				this->array_size = rhs.array_size;
				delete[] this->array;
				this->array = rhs.array;
				rhs.array_size = 0;		
				rhs.array = nullptr;
			}

			return *this;
		}

		// Copy assignment operator
		offset_array& operator= (const offset_array& rhs) {
			std::cout << "Copy assignment operator is called." << std::endl;

			this->array_size = rhs.array_size;
			T* arr_two = new T[this->array_size];
			for (int i = 0; i < this->array_size; i++) {
				arr_two[i] = rhs.array[i];
			}

			delete[] this->array;
			this->array = arr_two;

			return *this;
		}

		// Stream insertion operator, which takes class object as parameter
		// For loop to iterate through each element in array and print on console
		friend std::ostream& operator<<(std::ostream& out, const offset_array& data) {
			for (int i = 0; i < data.array_size; i++) {
				out << data.array[i] << ", ";
			}

			return out << std::endl;
		}

		// Subscript operator
		T& operator[](int index_p) {
			// Consider a user-created class object of template<T, int S, int E> 
			// If user tries to access an element at an index, which is not in limits S-E, from an array, throw exception
			if (index_p < S || index_p > E) {
				throw std::out_of_range("***Accessing out of bounds index***");
			}

			// else take that index and subtract the lower limit (S) from it to get the actual index
			// and return the element at the actual index
			// a non-zero lower limit (S) is at 0th index in array
			auto index = index_p - S;

			return this->array[index];
		}

		// comparison operator invoked by sort function in main
		bool operator<(const offset_array& rhs) const
		{
			// takes two objects and strictly sorts them 
			return std::less<>()(this, &rhs);
		}
	};

}

#endif
