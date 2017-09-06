#include<iostream>
#include<memory>
#include<algorithm>

// Add the following template function:
// This function will create a copy of the data passed into it on the heap and
// return a unique_ptr object around the data.
template <typename T>
std::unique_ptr<T> make_unique(T t) {
	return std::unique_ptr<T>(new T(t));
}



// Create an overloaded templated function to allow the duplication of a unique_ptr,
// that is a complete copy of the pointee data
template <typename T>
std::unique_ptr<T> make_unique(std::unique_ptr<T>& up) {
	// TODO: create a copy of the ptr data.
	// note the unique_ptr is passed by reference
    return std::unique_ptr<T>(new T(*up));
}

// Consider the following function templates:
template <typename T>
T getBase(T t) {
	return t;
}

template <typename T>
auto getBase(T *t) -> decltype(*t) {
	return *t;
}

// my template function
template <typename T>
auto getBase(std::unique_ptr<T>& t) -> decltype(*t) {
	return *t;
}

int main(){
    // Add the following code to a main function to test this:
    auto dptr = make_unique(3.14);
    std::cout << *dptr << std::endl;
    // Now try to add to the main function:
    auto dptr2 = make_unique(dptr);
    std::cout << *dptr2 << std::endl;
    // This won't compile as you can't copy construct a unique_ptr. Why?
    // Answer: you can't let two unique_ptr point to same object.

    // What do these functions do?
    // Add the following code to your main method to test them:
    int i = 9;
    int* iptr = &i;
    std::cout << getBase(i) << std::endl;
    std::cout << getBase(iptr) << std::endl;
    // Now add to main:
    std::cout << getBase(dptr) << std::endl;
    // Why does this not compile?
    // Can you write a third overloaded function template that will get
    // the base type from the unique_ptr?

}
/*


*/
