#include<iostream>
#include<algorithm>

template <typename T>
bool printIfWholeNumber(const T&) {
	return false;
}

template <>
bool printIfWholeNumber<int>(const int& i) {
	std::cout << i << " ";
	return true;
}
/*
1. What will this template do if it is given a std::string, a double, or a EuclideanVector?
Answer: call printIfWholeNumber(const T&)
2. What will this template do if it is given an int?
Answer: call printIfWholeNumber(const int&)
3. What will this template do if it is given a long?
Answer; call printIfWholeNumber(const T&)
*/




template <typename T>
unsigned int printAndCountWholeNumbers(const T& d) {
	if (printIfWholeNumber(d)) {
		std::cout << " ";
		return 1;
	}
	return 0;
}
/*
1. What will this template do if it is given a std::string, a double, or a EuclideanVector?
Answer: call printIfWholeNumber(const T&)
2. What will this template do if it is given an int?
Answer: call printIfWholeNumber(const int&)
3. What will this template do if it is given a long?
Answer; call printIfWholeNumber(const T&)
*/

// // Use the following code to write a recursive variadic template function to print the whole numbers in a variable number of parameters:
// template <typename T, typename... U>
// unsigned int printAndCountWholeNumbers(T head, U... tail) {
// 	// call a function to work out if the "head" is a whole number
// 	// call a function to process the tail
// 	// return the number of whole numbers in the variadic parameters
// 	return printIfWholeNumber(head) ?
// 			1 + printAndCountWholeNumbers(tail...) : printAndCountWholeNumbers(tail...);
// }

// int main(){
//     // Test your code by writing a main function that contains:
// 	// The numbers 1 3 6 -5 should be printed out.
// 	// Why is the number 7 not printed?
// 	// Answer: since 7.0 match  printIfWholeNumber(const T&), where T is double
// 	// Why is the number 2 not printed?
// 	// Answer: since 2 match  printIfWholeNumber(const T&), where T is std:;string
// 	auto c = printAndCountWholeNumbers(1, 2.5, 3, 4.5, 5.5, 6, 7.0, -5, "2" );
//     std::cout << "count = " << c << std::endl;
// 	// Add the following code to your main function:
// 	std::vector<double> d = {1.2, 32.0, 3.2, 5.30, 5.4, 6, -5};
// 	auto dc = printAndCountWholeNumbers(d);
// 	std::cout << "count = " << dc << std::endl;
// 	// This code will compile and run, but it won't print out the correct
// 	// number of whole numbers in either vector. Why?
// 	// Answer: since all of them not match int, previous one match T = double
// 	// the other one match T = unsigned int.
// 	std::vector<unsigned int> vui = {65, 343, 21, 3};
// 	dc = printAndCountWholeNumbers(vui);
// 	std::cout << "count = " << dc << std::endl;
// }


// Write another overloaded template function to correctly work through a vector:
template <typename T>
unsigned int printAndCountWholeNumbers(const std::vector<T>& vd) {
	unsigned int count = 0;
	for (auto d : vd) {
		auto dCopy = d;
		// work out if d is a whole number
		dCopy -= static_cast<int>(d);
		if (dCopy == 0) {
			// call: printIfWholeNumber
			// and add to count.
			return printIfWholeNumber(static_cast<int>(d));
		}
	}
	return count;
}

int main(){
	std::vector<double> d = {1.2, 32.0, 3.2, 5.30, 5.4, 6, -5};
	auto dc = printAndCountWholeNumbers(d);
	std::cout << "count = " << dc << std::endl;

	std::vector<unsigned int> vui = {65, 343, 21, 3};
	dc = printAndCountWholeNumbers(vui);
	std::cout << "count = " << dc << std::endl;

	// In this function the number 32 gets printed, why?
	// Answer: not print, only if you cast it into an integer,
	// then it will print.
}
