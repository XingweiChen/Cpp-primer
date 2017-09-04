#include<vector>
#include<string>
#include<list>
#include<iostream>

template<typename iteratorType, typename T>
iteratorType find(iteratorType begin, iteratorType end, T value){
    for(;begin != end && value != *begin; ++begin);
    return begin;
}

int main(){
    // std::vector<int> test = {1,2,3};
    // auto res = find(test.begin(), test.end(), 2);
    std::list<std::string> test = {"1","2","3"};
    auto res = find(test.begin(), test.end(), "3");
    if(res != test.end())
        std::cout<< *res << "\n";
    else
        std::cout << "no match" << "\n";
}
