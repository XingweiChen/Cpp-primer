#include<iostream>
#include<vector>

template<typename T> bool compare(const T& o1, const T& o2){
    std::cout << "enter" << "\n";
    if (o1 == o2)
        return 0;
    else if (o1 < o2)
        return -1;
    return 1;
}

int main(){
    //int num1 = 1, num2 = 2;
    // double num1 = 1.0, num2 = 0.5;
    std::vector<int> num1{1,2,3}, num2{2,4,6}; // can not compare here hence return 1
    auto res = compare(num1, num2);
    std::cout << res << "\n";

}
