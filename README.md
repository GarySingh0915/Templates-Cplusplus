# Templates-Cplusplus
Summary
For this assignment, we will practice creating and using a template class. No user input will be required, you will need to
include test cases for all your methods to make sure it works as expected.
Specifications

• Create a new empty project.

• Define an offset_array class that allows the user to set a lower bound for index values that is different from zero.

• The class should be defined in the nwacc namespace.

• Consider a declaration of

• nwacc::offset_array<std::string, 55, 75> data;

• This should create can array of 21 string values indexed using the integers 55 to 75.

• The following is an example of using the offset_array.

• nwacc::offset_array<int, 47, 59> data;

• data[48] = 8;

• std::cout << "value is " << data[48] << std::endl;

• std::cout << data[0] << std::endl; // this should cause the app to die because of the out_of_range error.

• Notice you will need to overload the subscript operator. You will also need to dynamically allocate the memory
based on the range of values the user wants. Because of the dynamic memory allocation, you will need to
implement the rule of five.

• If the user tries to access an element outside of the given range, throw a std::out_of_range exception from
stdexcept header.

• Consider the following template typename for you class.

• template<typename T, int S, int E>

• Also implement the stream insertion operator so you can display the array like what is shown below.

• std::cout << data << std::endl;

• This should display the output as [element1, element2, etc…]
