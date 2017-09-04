#include <iostream>
#include <vector>

// the same as std::begin
template<typename T, unsigned int size>
T* begin(T (&arr)[size]){
    return arr;
}


// the same as std::end
template<typename T, unsigned int size>
T* end(T (&arr)[size]){
    return arr + size;
}

int main()
{
    int s[] = {1, 2, 3, 4};
    std::cout << *begin<int, 4>(s) << "\n";
    std::cout << *(end(s) - 1) << "\n";

    std::vector<int> vc =  {1, 2, 3, 4};
    std::cout << *begin<int, 4>(s) << "\n";
    std::cout << *(end(s) - 1) << "\n";
}
