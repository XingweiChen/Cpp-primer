#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<iterator>

// template<typename Container>
// std::ostream& print(Container const& container, std::ostream& os){
//     for(typename Container::size_type i = 0; i != container.size(); ++ i)
//         os << container[i] << " ";
//     return os;
// }

template<typename Container>
std::ostream& print(Container const& container, std::ostream& os){
    std::copy(std::begin(container), std::end(container), std::ostream_iterator<typename Container::value_type>(os, " "));
    return os;
}


int main(){
    // std::vector<int> vec_int = {1,2,3,4,5};
    // print(vec_int, std::cout) << "\n";
    std::array<int, 5> arr_int = {1,2,3,4,5};
    print(arr_int, std::cout) << "\n";
}
