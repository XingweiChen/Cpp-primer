#include<iostream>

template<int size, typename T>
constexpr unsigned int getsize(T (&arr)[size]){
    return size;
}

int main(){
    int arr[] = {1,2,3,4,5};
    auto res = getsize(arr);
    std::cout << res << "\n";
}
