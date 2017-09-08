#include<array>
#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>

template<typename T> void fptr(T t1, T t2){
    std::cout<< "pointer" << "\n";
}

template<typename T> T fref(const T&, const T&){
    std::cout<< "reference" << "\n";
}

int main(){
    // int t1[5] = {1,1,1,1,1};
    // int t2[3] = {2,2,2};
    // fptr(t1, t2); // can compile. This is not standard array.
                    // it will pass two int*
    // fref(t1, t2); // deduce type is int[5] and int[3], can not compile.

    // std::array<int, 5> t1 = {1,1,1,1,1};
    // std::array<int, 3> t2 = {2,2,2};
    // fptr(t1, t2); // this not pass int*, it pass std::array<int, 5ul> and
                    // std::array<int, 3ul>, can not compile
    // fref(t1, t2); // same, can not compile

    // std::vector<int> t1 = {1,1,1,1,1};
    // std::vector<int> t2 = {2,2,2};
    // fptr(t1, t2); // can compile
    // fref(t1, t2); // can compile

    fptr("hello", "eye"); // ok
    // fref("hello", "eye"); // not ok, since char[6] and char[4] are not same
}
